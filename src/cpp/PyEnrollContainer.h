#ifndef PY_CONTAINER_H
#define PY_CONTAINER_H

#include "stdafx.h"
#include "CPPEnrollContainer.h"

typedef struct {
    PyObject_HEAD
    NS_SHARED_PTR::shared_ptr<CryptoPro::PKI::Enroll::CPPEnrollContainer> m_pCppEnrollImpl;
} Container;

extern PyTypeObject ContainerType;
#endif
