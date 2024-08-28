#ifndef PY_CERTIFICATES_H
#define PY_CERTIFICATES_H

#include "stdafx.h"
#include "CPPCadesCPCertificates.h"

typedef struct {
    PyObject_HEAD
    NS_SHARED_PTR::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPCertificatesObject> m_pCppCadesImpl;
} Certificates;

extern PyTypeObject CertificatesType;
#endif
