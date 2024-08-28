#ifndef PY_ATTRIBUTES_H
#define PY_ATTRIBUTES_H

#include "stdafx.h"
#include "CPPCadesCPAttributes.h"

typedef struct {
    PyObject_HEAD
    NS_SHARED_PTR::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPAttributesObject> m_pCppCadesImpl;
} Attributes;

extern PyTypeObject AttributesType;
#endif
