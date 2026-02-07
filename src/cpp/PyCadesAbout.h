#ifndef PY_ABOUT_H
#define PY_ABOUT_H

#include "stdafx.h"
#include "CPPCadesAbout.h"

typedef struct {
    PyObject_HEAD
    NS_SHARED_PTR::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesAboutObject> m_pCppCadesImpl;
} About;

extern PyTypeObject AboutType;
#endif
