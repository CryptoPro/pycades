#include "PyEnrollContainerKey.h"
#include "PyCadesCertificate.h"
#include "PyCadesPublicKey.h"

using namespace CryptoPro::PKI::Enroll;

static void ContainerKey_dealloc(ContainerKey *self)
{
    self->m_pCppEnrollImpl.reset();
    Py_TYPE(self)->tp_free((PyObject *)self);
}

static PyObject *ContainerKey_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    ContainerKey *self;
    self = (ContainerKey *)type->tp_alloc(type, 0);
    if (self != NULL)
    {
        self->m_pCppEnrollImpl = NS_SHARED_PTR::shared_ptr<CPPEnrollContainerKey>(new CPPEnrollContainerKey());
    }
    return (PyObject *)self;
}

static PyObject *ContainerKey_getIsExportable(ContainerKey *self)
{
    BOOL bValue;
    HR_METHOD_ERRORCHECK_RETURN(self->m_pCppEnrollImpl->get_IsExportable(bValue));
    if (bValue)
    {
        Py_RETURN_TRUE;
    }
    Py_RETURN_FALSE;
}

static PyObject *ContainerKey_getHasCertificate(ContainerKey *self)
{
    BOOL bValue;
    HR_METHOD_ERRORCHECK_RETURN(self->m_pCppEnrollImpl->get_HasCertificate(bValue));
    if (bValue)
    {
        Py_RETURN_TRUE;
    }
    Py_RETURN_FALSE;
}

static PyObject *ContainerKey_getType(ContainerKey *self)
{
    DWORD dwValue;
    HR_METHOD_ERRORCHECK_RETURN(self->m_pCppEnrollImpl->get_Type(dwValue));
    return Py_BuildValue("l", dwValue);
}

static PyObject *ContainerKey_getCertificate(ContainerKey *self)
{
    NS_SHARED_PTR::shared_ptr<CPPCadesCPCertificateObject> pCPPCadesCPCert;
    HR_METHOD_ERRORCHECK_RETURN(self->m_pCppEnrollImpl->get_Certificate(pCPPCadesCPCert));
    PyObject *pPyCertificate = PyObject_CallObject((PyObject *)&CertificateType, NULL);
    Certificate *pCertificate = (Certificate *)pPyCertificate;
    pCertificate->m_pCppCadesImpl = pCPPCadesCPCert;
    return Py_BuildValue("N", pCertificate);
}

#if IS_CADES_VERSION_GREATER_EQUAL(2, 0, 15000)
static PyObject *ContainerKey_getPublicKey(ContainerKey *self)
{
    NS_SHARED_PTR::shared_ptr<CPPCadesCPPublicKeyObject> pCPPCadesPublicKey;
    HR_METHOD_ERRORCHECK_RETURN(self->m_pCppEnrollImpl->get_PublicKey(pCPPCadesPublicKey));
    PyObject *pPyPublicKey = PyObject_CallObject((PyObject *)&PublicKeyType, NULL);
    PublicKey *pPublicKey = (PublicKey *)pPyPublicKey;
    pPublicKey->m_pCppCadesImpl = pCPPCadesPublicKey;
    return Py_BuildValue("N", pPublicKey);
}

static PyObject *ContainerKey_getKP_FP(ContainerKey *self)
{
    CAtlString sValue;
    HR_METHOD_ERRORCHECK_RETURN(self->m_pCppEnrollImpl->get_KP_FP(sValue));
    return Py_BuildValue("s", sValue.GetString());
}
#endif

#if IS_CADES_VERSION_GREATER_EQUAL(2, 0, 15400)
static PyObject *ContainerKey_getKP_ALGID(ContainerKey *self)
{
    DWORD dwValue;
    HR_METHOD_ERRORCHECK_RETURN(self->m_pCppEnrollImpl->get_KP_ALGID(dwValue));
    return Py_BuildValue("l", dwValue);
}
#endif

static PyObject *ContainerKey_getExpirationTime(ContainerKey *self)
{
    CryptoPro::CDateTime date;
    CryptoPro::CStringProxy strProxyDate;
    HR_METHOD_ERRORCHECK_RETURN(self->m_pCppEnrollImpl->get_ExpirationTime(date));
    strProxyDate = date.tostring();
    return Py_BuildValue("s", strProxyDate.c_str());
}

static PyGetSetDef ContainerKey_getset[] = {
    {"IsExportable", (getter)ContainerKey_getIsExportable, NULL, "IsExportable", NULL},
    {"HasCertificate", (getter)ContainerKey_getHasCertificate, NULL, "HasCertificate", NULL},
    {"Type", (getter)ContainerKey_getType, NULL, "Type", NULL},
    {"Certificate", (getter)ContainerKey_getCertificate, NULL, "Certificate", NULL},
    {"ExpirationTime", (getter)ContainerKey_getExpirationTime, NULL, "ExpirationTime", NULL},
#if IS_CADES_VERSION_GREATER_EQUAL(2, 0, 15000)
    {"PublicKey", (getter)ContainerKey_getPublicKey, NULL, "PublicKey", NULL},
    {"KP_FP", (getter)ContainerKey_getKP_FP, NULL, "KP_FP", NULL},
#endif
#if IS_CADES_VERSION_GREATER_EQUAL(2, 0, 15400)
    {"KP_ALGID", (getter)ContainerKey_getKP_ALGID, NULL, "KP_ALGID", NULL},
#endif
    {NULL} /* Sentinel */
};

static PyMethodDef ContainerKey_methods[] = {
    {NULL} /* Sentinel */
};

PyTypeObject ContainerKeyType = {
    PyVarObject_HEAD_INIT(NULL, 0) "pycades.ContainerKey", /* tp_name */
    sizeof(ContainerKey),                                  /* tp_basicsize */
    0,                                                     /* tp_itemsize */
    (destructor)ContainerKey_dealloc,                      /* tp_dealloc */
    0,                                                     /* tp_print */
    0,                                                     /* tp_getattr */
    0,                                                     /* tp_setattr */
    0,                                                     /* tp_compare */
    0,                                                     /* tp_repr */
    0,                                                     /* tp_as_number */
    0,                                                     /* tp_as_sequence */
    0,                                                     /* tp_as_mapping */
    0,                                                     /* tp_hash */
    0,                                                     /* tp_call */
    0,                                                     /* tp_str */
    0,                                                     /* tp_getattro */
    0,                                                     /* tp_setattro */
    0,                                                     /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,              /* tp_flags */
    "ContainerKey object",                                 /* tp_doc */
    0,                                                     /* tp_traverse */
    0,                                                     /* tp_clear */
    0,                                                     /* tp_richcompare */
    0,                                                     /* tp_weaklistoffset */
    0,                                                     /* tp_iter */
    0,                                                     /* tp_iternext */
    ContainerKey_methods,                                  /* tp_methods */
    0,                                                     /* tp_members */
    ContainerKey_getset,                                   /* tp_getset */
    0,                                                     /* tp_base */
    0,                                                     /* tp_dict */
    0,                                                     /* tp_descr_get */
    0,                                                     /* tp_descr_set */
    0,                                                     /* tp_dictoffset */
    0,                                                     /* tp_init */
    0,                                                     /* tp_alloc */
    ContainerKey_new,                                      /* tp_new */
};

