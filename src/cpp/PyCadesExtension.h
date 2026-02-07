#ifndef PY_EXTENSION_H
#define PY_EXTENSION_H

#include "stdafx.h"
#if IS_CADES_VERSION_GREATER_EQUAL(2, 0, 15000)
#include "CPPCadesCPExtension.h"

typedef struct {
    PyObject_HEAD
    NS_SHARED_PTR::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPExtensionObject> m_pCppCadesImpl;
} Extension;

extern PyTypeObject ExtensionType;
#endif

#endif
