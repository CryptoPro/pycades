#include "PyCadesExtension.h"
#if IS_CADES_VERSION_GREATER_EQUAL(2, 0, 15000)
#include "PyCadesEncodedData.h"
#include "PyCadesOID.h"

using namespace CryptoPro::PKI::CAdES;

static void Extension_dealloc(Extension *self)
{
    self->m_pCppCadesImpl.reset();
    Py_TYPE(self)->tp_free((PyObject *)self);
}

static PyObject *Extension_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    Extension *self;
    self = (Extension *)type->tp_alloc(type, 0);
    if (self != NULL)
    {
        self->m_pCppCadesImpl = NS_SHARED_PTR::shared_ptr<CPPCadesCPExtensionObject>(new CPPCadesCPExtensionObject());
    }
    return (PyObject *)self;
}

static PyObject *Extension_getEncodedData(Extension *self)
{
    PyObject *pPyEncodedData = PyObject_CallObject((PyObject *)&EncodedDataType, NULL);
    EncodedData *pEncodedData = (EncodedData *)pPyEncodedData;
    HR_METHOD_ERRORCHECK_RETURN(self->m_pCppCadesImpl->get_EncodedData(pEncodedData->m_pCppCadesImpl));
    return Py_BuildValue("N", pEncodedData);
}

static PyObject *Extension_getIsCritical(Extension *self)
{
    BOOL bIsCritical;
    HR_METHOD_ERRORCHECK_RETURN(self->m_pCppCadesImpl->get_IsCritical(&bIsCritical));
    if (bIsCritical)
    {
        Py_RETURN_TRUE;
    }
    Py_RETURN_FALSE;
}

static PyObject *Extension_getOID(Extension *self)
{
    PyObject *pPyOID = PyObject_CallObject((PyObject *)&OIDType, NULL);
    OID *pOID = (OID *)pPyOID;
    pOID->m_pCppCadesImpl = NS_SHARED_PTR::shared_ptr<CPPCadesCPOIDObject>(new CPPCadesCPOIDObject());
    HR_METHOD_ERRORCHECK_RETURN(self->m_pCppCadesImpl->get_OID(pOID->m_pCppCadesImpl));
    return Py_BuildValue("N", pOID);
}

static PyGetSetDef Extension_getset[] = {
    {"EncodedData", (getter)Extension_getEncodedData, NULL, "EncodedData", NULL},
    {"IsCritical", (getter)Extension_getIsCritical, NULL, "IsCritical", NULL},
    {"OID", (getter)Extension_getOID, NULL, "OID", NULL},
    {NULL} /* Sentinel */
};

static PyMethodDef Extension_methods[] = {
    {NULL} /* Sentinel */
};

PyTypeObject ExtensionType = {
    PyVarObject_HEAD_INIT(NULL, 0) "pycades.Extension", /* tp_name */
    sizeof(Extension),                                  /* tp_basicsize */
    0,                                                  /* tp_itemsize */
    (destructor)Extension_dealloc,                      /* tp_dealloc */
    0,                                                  /* tp_print */
    0,                                                  /* tp_getattr */
    0,                                                  /* tp_setattr */
    0,                                                  /* tp_compare */
    0,                                                  /* tp_repr */
    0,                                                  /* tp_as_number */
    0,                                                  /* tp_as_sequence */
    0,                                                  /* tp_as_mapping */
    0,                                                  /* tp_hash */
    0,                                                  /* tp_call */
    0,                                                  /* tp_str */
    0,                                                  /* tp_getattro */
    0,                                                  /* tp_setattro */
    0,                                                  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,           /* tp_flags */
    "Extension object",                                 /* tp_doc */
    0,                                                  /* tp_traverse */
    0,                                                  /* tp_clear */
    0,                                                  /* tp_richcompare */
    0,                                                  /* tp_weaklistoffset */
    0,                                                  /* tp_iter */
    0,                                                  /* tp_iternext */
    Extension_methods,                                  /* tp_methods */
    0,                                                  /* tp_members */
    Extension_getset,                                   /* tp_getset */
    0,                                                  /* tp_base */
    0,                                                  /* tp_dict */
    0,                                                  /* tp_descr_get */
    0,                                                  /* tp_descr_set */
    0,                                                  /* tp_dictoffset */
    0,                                                  /* tp_init */
    0,                                                  /* tp_alloc */
    Extension_new,                                      /* tp_new */
};

#endif