#include "PyCadesExtensions.h"
#if IS_CADES_VERSION_GREATER_EQUAL(2, 0, 15000)
#include "PyCadesExtension.h"

using namespace CryptoPro::PKI::CAdES;

static void Extensions_dealloc(Extensions *self)
{
    self->m_pCppCadesImpl.reset();
    Py_TYPE(self)->tp_free((PyObject *)self);
}

static PyObject *Extensions_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    Extensions *self;
    self = (Extensions *)type->tp_alloc(type, 0);
    if (self != NULL)
    {
        self->m_pCppCadesImpl = NS_SHARED_PTR::shared_ptr<CPPCadesCPExtensionsObject>(new CPPCadesCPExtensionsObject());
    }
    return (PyObject *)self;
}

static PyObject *Extensions_getCount(Extensions *self)
{
    unsigned int count = 0;
    HR_METHOD_ERRORCHECK_RETURN(self->m_pCppCadesImpl->get_Count(&count));
    return Py_BuildValue("l", count);
}

static PyObject *Extensions_getItem(Extensions *self, PyObject *args)
{
    long index = 0;
    if (!PyArg_ParseTuple(args, "l", &index))
    {
        return NULL;
    }
    NS_SHARED_PTR::shared_ptr<CPPCadesCPExtensionObject> pCppCadesExtension = NS_SHARED_PTR::shared_ptr<CPPCadesCPExtensionObject>(new CPPCadesCPExtensionObject());
    HR_METHOD_ERRORCHECK_RETURN(self->m_pCppCadesImpl->get_Item(index, pCppCadesExtension));
    PyObject *pPyExtension = PyObject_CallObject((PyObject *)&ExtensionType, NULL);
    Extension *pExtension = (Extension *)pPyExtension;
    pExtension->m_pCppCadesImpl = pCppCadesExtension;
    return Py_BuildValue("N", pExtension);
}

static PyGetSetDef Extensions_getset[] = {
    {"Count", (getter)Extensions_getCount, NULL, "Count", NULL},
    {NULL} /* Sentinel */
};

static PyMethodDef Extensions_methods[] = {
    {"Item", (PyCFunction)Extensions_getItem, METH_VARARGS, "Item"},
    {NULL} /* Sentinel */
};

PyTypeObject ExtensionsType = {
    PyVarObject_HEAD_INIT(NULL, 0) "pycades.Extensions", /* tp_name */
    sizeof(Extensions),                                  /* tp_basicsize */
    0,                                                   /* tp_itemsize */
    (destructor)Extensions_dealloc,                      /* tp_dealloc */
    0,                                                   /* tp_print */
    0,                                                   /* tp_getattr */
    0,                                                   /* tp_setattr */
    0,                                                   /* tp_compare */
    0,                                                   /* tp_repr */
    0,                                                   /* tp_as_number */
    0,                                                   /* tp_as_sequence */
    0,                                                   /* tp_as_mapping */
    0,                                                   /* tp_hash */
    0,                                                   /* tp_call */
    0,                                                   /* tp_str */
    0,                                                   /* tp_getattro */
    0,                                                   /* tp_setattro */
    0,                                                   /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,            /* tp_flags */
    "Extensions object",                                 /* tp_doc */
    0,                                                   /* tp_traverse */
    0,                                                   /* tp_clear */
    0,                                                   /* tp_richcompare */
    0,                                                   /* tp_weaklistoffset */
    0,                                                   /* tp_iter */
    0,                                                   /* tp_iternext */
    Extensions_methods,                                  /* tp_methods */
    0,                                                   /* tp_members */
    Extensions_getset,                                   /* tp_getset */
    0,                                                   /* tp_base */
    0,                                                   /* tp_dict */
    0,                                                   /* tp_descr_get */
    0,                                                   /* tp_descr_set */
    0,                                                   /* tp_dictoffset */
    0,                                                   /* tp_init */
    0,                                                   /* tp_alloc */
    Extensions_new,                                      /* tp_new */
};

#endif