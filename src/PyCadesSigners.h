#ifndef PY_SIGNERS_H
#define PY_SIGNERS_H

#include "stdafx.h"
#include "CPPCadesCollections.h"

typedef struct {
    PyObject_HEAD
    NS_SHARED_PTR::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPSignersObject> m_pCppCadesImpl;
} Signers;

extern PyTypeObject SignersType;
#endif
