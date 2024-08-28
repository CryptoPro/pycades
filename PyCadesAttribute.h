#ifndef PY_ATTRIBUTE_H
#define PY_ATTRIBUTE_H

#include "stdafx.h"
#include "CPPCadesCPAttribute.h"

typedef struct {
    PyObject_HEAD
    NS_SHARED_PTR::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPAttributeObject> m_pCppCadesImpl;
} Attribute;

extern PyTypeObject AttributeType;
#endif
