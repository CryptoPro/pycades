#ifndef PY_CSPINFORMATION_H
#define PY_CSPINFORMATION_H

#include "stdafx.h"
#include "CPPEnrollCspInformation.h"

typedef struct {
    PyObject_HEAD
    NS_SHARED_PTR::shared_ptr<CryptoPro::PKI::Enroll::CPPEnrollCspInformation> m_pCppEnrollImpl;
} CspInformation;

extern PyTypeObject CspInformationType;
#endif
