#ifndef PY_RECIPIENTS_H
#define PY_RECIPIENTS_H

#include "stdafx.h"
#include "CPPCadesCollections.h"

typedef struct {
    PyObject_HEAD
    NS_SHARED_PTR::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPRecipientsObject> m_pCppCadesImpl;
} Recipients;

extern PyTypeObject RecipientsType;
#endif
