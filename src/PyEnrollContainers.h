#ifndef PY_CONTAINERS_H
#define PY_CONTAINERS_H

#include "stdafx.h"
#include "CPPEnrollCollections.h"

typedef struct {
    PyObject_HEAD
    NS_SHARED_PTR::shared_ptr<CryptoPro::PKI::Enroll::CPPEnrollContainers> m_pCppEnrollImpl;
} Containers;

extern PyTypeObject ContainersType;
#endif
