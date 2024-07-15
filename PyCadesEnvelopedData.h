#ifndef PY_ENVELOPED_DATA_H
#define PY_ENVELOPED_DATA_H

#include "stdafx.h"
#include "CPPCadesCPEnvelopedData.h"

typedef struct {
    PyObject_HEAD
    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPEnvelopedDataObject> m_pCppCadesImpl;
} EnvelopedData;

extern PyTypeObject EnvelopedDataType;
#endif
