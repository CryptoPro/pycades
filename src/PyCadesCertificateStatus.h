#ifndef PY_CERTIFICATE_STATUS_H
#define PY_CERTIFICATE_STATUS_H

#include "stdafx.h"
#include "CPPCadesCPCertificateStatus.h"

typedef struct {
    PyObject_HEAD
    NS_SHARED_PTR::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPCertificateStatusObject> m_pCppCadesImpl;
} CertificateStatus;

extern PyTypeObject CertificateStatusType;
#endif
