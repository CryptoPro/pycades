#ifndef PY_CONTAINER_KEYS_H
#define PY_CONTAINER_KEYS_H

#include "stdafx.h"
#include "CPPEnrollCollections.h"

typedef struct {
    PyObject_HEAD
    NS_SHARED_PTR::shared_ptr<CryptoPro::PKI::Enroll::CPPEnrollContainerKeys> m_pCppEnrollImpl;
} ContainerKeys;

extern PyTypeObject ContainerKeysType;
#endif
