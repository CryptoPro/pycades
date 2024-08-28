#ifndef PY_BASIC_CONSTRAINTS_H
#define PY_BASIC_CONSTRAINTS_H

#include "stdafx.h"
#include "CPPCadesCPBasicConstraints.h"

typedef struct {
    PyObject_HEAD
    NS_SHARED_PTR::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPBasicConstraintsObject> m_pCppCadesImpl;
} BasicConstraints;

extern PyTypeObject BasicConstraintsType;
#endif
