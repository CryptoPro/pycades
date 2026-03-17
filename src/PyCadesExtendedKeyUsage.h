#ifndef PY_EXTENDED_KEY_USAGE_H
#define PY_EXTENDED_KEY_USAGE_H

#include "stdafx.h"
#include "CPPCadesCPExtendedKeyUsage.h"

typedef struct {
    PyObject_HEAD
    NS_SHARED_PTR::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPExtendedKeyUsageObject> m_pCppCadesImpl;
} ExtendedKeyUsage;

extern PyTypeObject ExtendedKeyUsageType;
#endif
