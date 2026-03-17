#ifndef PY_CONTAINER_KEY_H
#define PY_CONTAINER_KEY_H

#include "stdafx.h"
#include "CPPEnrollContainerKey.h"

typedef struct {
    PyObject_HEAD
    NS_SHARED_PTR::shared_ptr<CryptoPro::PKI::Enroll::CPPEnrollContainerKey> m_pCppEnrollImpl;
} ContainerKey;

extern PyTypeObject ContainerKeyType;
#endif

