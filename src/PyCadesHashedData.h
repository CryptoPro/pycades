#ifndef PY_HASHED_DATA_H
#define PY_HASHED_DATA_H

#include "stdafx.h"
#include "CPPCadesCPHashedData.h"

typedef struct {
    PyObject_HEAD
    NS_SHARED_PTR::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPHashedDataObject> m_pCppCadesImpl;
} HashedData;

extern PyTypeObject HashedDataType;
#endif
