#ifndef PY_VERSION_H
#define PY_VERSION_H

#include "stdafx.h"
#include "CPPVersion.h"

typedef struct {
    PyObject_HEAD
    NS_SHARED_PTR::shared_ptr<CryptoPro::PKI::CAdES::CPPVersionObject> m_pCppCadesImpl;
} Version;

extern PyTypeObject VersionType;
#endif
