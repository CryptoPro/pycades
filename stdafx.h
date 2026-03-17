#pragma once

#define CRYPT_SIGN_MESSAGE_PARA_HAS_CMS_FIELDS
#define CMSG_SIGNER_ENCODE_INFO_HAS_CMS_FIELDS
#define CMSG_SIGNED_ENCODE_INFO_HAS_CMS_FIELDS
#define CERT_PARA_HAS_EXTRA_FIELDS

#define IS_CADES_VERSION_GREATER_EQUAL(major, minor, build) \
    (CPRO_CADES_VERSION_MAJOR > (major) || \
    (CPRO_CADES_VERSION_MAJOR == (major) && CPRO_CADES_VERSION_MINOR > (minor)) || \
    (CPRO_CADES_VERSION_MAJOR == (major) && CPRO_CADES_VERSION_MINOR == (minor) && CPRO_CADES_VERSION_BUILD >= (build)))

#define IGNORE_LEGACY_FORMAT_MESSAGE_MSG

#include <Python.h>
#include "boost/shared_ptr.hpp"
#include <iostream>
#include "CSP_WinDef.h"
#include "CSP_WinError.h"
#include <WinCryptEx.h>
#include <atlcrypt2.h>
#include "ocspcli_e.h"
#include "tspcli_e.h"
#include "cppcades.h"

#ifndef NS_SHARED_PTR
#define NS_SHARED_PTR boost
#endif

#include "CSP_WinCrypt.h"

#ifdef MAKELANGID
#undef MAKELANGID
#endif //MAKELANGID
#define MAKELANGID(a, b) 0x409 //English U.S.

#define RETURN_NULL_WITH_EXCEPTION(err)                                                      \
    do                                                                                       \
    {                                                                                        \
        CAtlStringW message = GetErrorMessage(HRESULT_FROM_WIN32(err),                       \
                                              MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US)); \
        wchar_t buff[14];                                                                    \
        swprintf(buff, 14, L" (0x%08X)", err);                                               \
        message.Append(buff);                                                                \
        PyErr_SetString(PyExc_Exception, CW2A(message, CP_UTF8));                            \
        return NULL;                                                                         \
    } while (0)

#define RETURN_MINUS_1_WITH_EXCEPTION(err)                                                   \
    do                                                                                       \
    {                                                                                        \
        CAtlStringW message = GetErrorMessage(HRESULT_FROM_WIN32(err),                       \
                                              MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US)); \
        wchar_t buff[14];                                                                    \
        swprintf(buff, 14, L" (0x%08X)", err);                                               \
        message.Append(buff);                                                                \
        PyErr_SetString(PyExc_Exception, CW2A(message, CP_UTF8));                            \
        return -1;                                                                           \
    } while (0)


#define HR_SETTER_ERRORCHECK_RETURN(expr)             \
    __pragma(warning(push))                           \
        __pragma(warning(disable : 4127)) do          \
    {                                                 \
        HRESULT stdafx_hr = (expr);                   \
        if (stdafx_hr != S_OK)                        \
        {                                             \
            RETURN_MINUS_1_WITH_EXCEPTION(stdafx_hr); \
        }                                             \
    } while (0)

#define HR_METHOD_ERRORCHECK_RETURN(expr)          \
    __pragma(warning(push))                        \
        __pragma(warning(disable : 4127)) do       \
    {                                              \
        HRESULT stdafx_hr = (expr);                \
        if (stdafx_hr != S_OK)                     \
        {                                          \
            RETURN_NULL_WITH_EXCEPTION(stdafx_hr); \
        }                                          \
    } while (0)

static const ATL::CAtlStringW GetErrorMessage(HRESULT hr, DWORD dwLangId)
{
    UNUSED(dwLangId);
    ATL::CAtlStringW ret;
    switch (hr)
    {
    case TSPCLI_ERROR_HTTP:
    case OCSPCLI_ERROR_HTTP:
        ret = L"HTTP error occurred while sending request.";
        break;
    case TSPCLI_ERROR_PolicyDeniedAuthType:
    case OCSPCLI_ERROR_PolicyDeniedAuthType:
        ret = L"Specified authentication type prohibited by group policy.";
        break;
    case TSPCLI_ERROR_PolicyDeniedProxyAuthType:
    case OCSPCLI_ERROR_PolicyDeniedProxyAuthType:
        ret = L"Specified proxy authentication type prohibited by group policy.";
        break;
    case TSPCLI_ERROR_PolicyDeniedURL:
        ret = L"Specified time-stamp authority prohibited by group policy.";
        break;
    case OCSPCLI_ERROR_PolicyDeniedURL:
        ret = L"Specified OCSP server authority prohibited by group policy.";
        break;
    case TSPCLI_ERROR_PolicyDeniedNonce:
        ret = L"Nonce usage prohibited by group policy.";
        break;
    case TSPCLI_ERROR_PolicyDeniedHashAlg:
        ret = L"Specified hash algorithm prohibited by group policy.";
        break;
    case TSPCLI_ERROR_PolicyDeniedPolicyID:
        ret = L"Specified PolicyID prohibited by group policy.";
        break;
    case TSPCLI_ERROR_IncorrectNonce:
        ret = L" The values of request's and stamp's \"Nonce\" fields are not equal.";
        break;
    case TSPCLI_ERROR_AddressIsEmpty:
        ret = L"The URL of TSP service is not specified.";
        break;
    case TSPCLI_ERROR_ExpiredStamp:
        ret = L"The time stamp is expired (ProducedAt value).";
        break;
    case TSPCLI_ERROR_DataHashIsEmpty:
        ret = L"Request does not contain data hash.";
        break;
    case TSPCLI_ERROR_UnsuccessfullResponse:
        ret = L"TSA response is unsuccessful.";
        break;
    case 0xC2100140: // TSPCLI_ERROR_LicenseExpired
        ret = L"No TSP Client license has been entered or TSP Client license is expired.";
        break;
    case OCSPCLI_ERROR_PolicyDeniedSignedRequest:
        ret = L"Signed OCSP requests prohibited by group policy.";
        break;
    case OCSPCLI_ERROR_PolicyDeniedUnsignedRequest:
        ret = L"Unsigned OCSP requests prohibited by group policy.";
        break;
    case OCSPCLI_ERROR_IncorrectNonce:
        ret = L"The values of OCSP-request's and response's \"Nonce\" extensions are not equal.";
        break;
    case OCSPCLI_ERROR_AddressIsEmpty:
        ret = L"The URL of OCSP service is not specified.";
        break;
    case OCSPCLI_ERROR_ExpiredResponse:
        ret = L"OCSP-response is expired by ProducedAt or by NextUpdate.";
        break;
    case OCSPCLI_ERROR_ExpiredThisUpdate:
        ret = L"ThisUpdate value of single response is expired.";
        break;
    case OCSPCLI_ERROR_IncorrectNextUpdate:
        ret = L" NextUpdate value of single response is less than ThisUpdate.";
        break;
    case OCSPCLI_ERROR_ReqRespNotMatch:
        ret = L"OCSP-response does not contain requested certificate status.";
        break;
    case OCSPCLI_ERROR_CertStatusIsRevoked:
        ret = L"Certificate is revoked.";
        break;
    case OCSPCLI_ERROR_CertStatusIsUnknown:
        ret = L"Certificate status is unknown.";
        break;
    case OCSPCLI_ERROR_UnsuccessfullResponse:
        ret = L"OCSP-response is unsuccessful.";
        break;
    case OCSPCLI_ERROR_PolicyDeniedExtension:
        ret = L"Encountered extension (AcceptableTypes or Nonce) prohibited by group policy.";
        break;
    case ERROR_BAD_CONFIGURATION:
        ret = L"The configuration data or license for this product is corrupt or not present.";
        break;
    case 0x8007064a: // License info isn't present
        ret = L"The configuration data or license for this product is corrupt or not present.";
        break;
    case CRYPT_E_REVOKED:
        ret = L"The certificate is revoked.";
        break;
    case ERROR_NO_DATA_DETECTED:
        ret = L"The data you supplied have zero length.";
        break;
    case CRYPT_E_NO_REVOCATION_CHECK:
        ret = L"The revocation function was unable to check revocation for the certificate.";
        break;
    case 0x8007006E:
        ret = L"The system cannot open the device or file specified.";
        break;
    case NTE_BAD_ALGID:
    case CRYPT_E_OID_FORMAT: //       oid       UNIX
        ret = L"Invalid algorithm specified.";
        break;
    case REGDB_E_CLASSNOTREG:
        ret = L"Class not registered.";
        break;
    case OLE_E_BLANK:
        ret = L"Uninitialized object.";
        break;
    case CAPICOM_E_STORE_NOT_OPENED:
        ret = L"The Store object does not represent an opened certificate store.";
        break;
    case E_INVALIDARG:
        ret = L"The parameter is incorrect.";
        break;
    case 0x80070002: // returned by OpenStore(Existing) if no store
        ret = L"The system cannot find the file specified.";
        break;
    case E_NOT_VALID_STATE:
        ret = L"The group or resource is not in the correct state to perform the requested operation.";
        break;
    case E_NOTIMPL:
        ret = L"Not implemented.";
        break;
    case ERROR_ALREADY_EXISTS:
        ret = L"Cannot create a file when that file already exists.";
        break;
    case 0x800700B7: // ERROR_ALREADY_EXISTS in HRESULT variant
        ret = L"Cannot create a file when that file already exists.";
        break;
    case NS_E_CURL_INVALIDSCHEME:
        ret = L"The URL contains an invalid scheme.";
        break;
    case SCARD_W_WRONG_CHV:
        ret = L"The private key cannot be accessed because the wrong PIN was presented.";
        break;
    case CRYPT_E_NOT_FOUND:
        ret = L"Cannot find object or property.";
        break;
    case NTE_BAD_SIGNATURE:
        ret = L"Invalid Signature.";
        break;
    case ERROR_DS_INSUFF_ACCESS_RIGHTS:
        ret = L"Insufficient access rights to perform the operation.";
        break;
    case 0x800705B9: // ERROR_XML_PARSE_ERROR in HRESULT variant
        ret = L"The system was unable to parse the requested XML data.";
        break;
    case 0x800705BA: // ERROR_XMLDSIG_ERROR in HRESULT variant
        ret = L"An error was encountered while processing an XML digital signature.";
        break;
    case 0x800B010E: // CERT_E_REVOCATION_FAILURE
        ret = L"The revocation process could not continue - the certificate(s) could not be checked.";
        break;
    case OCSPCLI_ERROR_ResponseWithUnallowedExtension:
        ret = L"OCSP-response contains unallowed critical extension.";
        break;
    case NTE_EXISTS:
        ret = L"Object already exists.";
        break;
    case CRYPT_E_HASH_VALUE:
        ret = L"The hash value is not correct";
        break;
    case OCSPCLI_ERROR_ResponseWithIncorrectTimeStamp:
        ret = L"OCSP Responder time is out of sync with Time Stamping Authority";
        break;
    case OCSPCLI_ERROR_UntrustedSitesDisabled:
        ret = L"Untrusted sites disabled";
        break;
    case 0xC2110140: // OCSPCLI_ERROR_LicenseExpired
        ret = L"No OCSP Client license has been entered or OCSP Client license is expired";
        break;
    case SCARD_E_CARD_UNSUPPORTED:
        ret = L"Wrong name format or an attempt is made to open container of another CSP.";
        break;
    case NTE_PERM:
        ret = L"Access denied";
        break;
    case CERT_E_UNTRUSTEDROOT:
        ret = L"A certificate chain processed correctly, but terminated in a root certificate which is not trusted by the trust provider";
        break;
    case CRYPT_E_NO_DECRYPT_CERT:
        ret = L"Cannot find the certificate and private key to use for decryption";
        break;
    default:
        ret = L"Internal error.";
        break;
    }
    return ret;
}