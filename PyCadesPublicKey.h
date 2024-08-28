#ifndef PY_PUBLIC_KEY_H
#define PY_PUBLIC_KEY_H

#include "stdafx.h"
#include "CPPCadesCPPublicKey.h"

typedef struct {
    PyObject_HEAD
    NS_SHARED_PTR::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPPublicKeyObject> m_pCppCadesImpl;
} PublicKey;

extern PyTypeObject PublicKeyType;
#endif
