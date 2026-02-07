#ifndef PY_SIGNED_XML_H
#define PY_SIGNED_XML_H

#include "stdafx.h"
#include "CPPCadesSignedXML.h"

typedef struct {
    PyObject_HEAD
    NS_SHARED_PTR::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesSignedXMLObject> m_pCppCadesImpl;
} SignedXML;

extern PyTypeObject SignedXMLType;
#endif
