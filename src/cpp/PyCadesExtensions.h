#ifndef PY_EXTENSIONS_H
#define PY_EXTENSIONS_H

#include "stdafx.h"
#if IS_CADES_VERSION_GREATER_EQUAL(2, 0, 15000)
#include "CPPCadesCollections.h"

typedef struct {
    PyObject_HEAD
    NS_SHARED_PTR::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPExtensionsObject> m_pCppCadesImpl;
} Extensions;

extern PyTypeObject ExtensionsType;
#endif

#endif
