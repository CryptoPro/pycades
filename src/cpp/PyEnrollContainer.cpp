#include "PyEnrollContainer.h"
#include "PyEnrollContainerKeys.h"

using namespace CryptoPro::PKI::Enroll;

static void Container_dealloc(Container *self)
{
    self->m_pCppEnrollImpl.reset();
    Py_TYPE(self)->tp_free((PyObject *)self);
}

static PyObject *Container_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    Container *self;
    self = (Container *)type->tp_alloc(type, 0);
    if (self != NULL)
    {
        self->m_pCppEnrollImpl = NS_SHARED_PTR::shared_ptr<CPPEnrollContainer>(new CPPEnrollContainer());
    }
    return (PyObject *)self;
}

static PyObject *Container_getUniqueName(Container *self)
{
    CAtlString sValue;
    HR_METHOD_ERRORCHECK_RETURN(self->m_pCppEnrollImpl->get_UniqueName(sValue));
    return Py_BuildValue("s", sValue.GetString());
}

static PyObject *Container_getMedia(Container *self)
{
    CAtlString sValue;
    HR_METHOD_ERRORCHECK_RETURN(self->m_pCppEnrollImpl->get_Media(sValue));
    return Py_BuildValue("s", sValue.GetString());
}

static PyObject *Container_getReader(Container *self)
{
    CAtlString sValue;
    HR_METHOD_ERRORCHECK_RETURN(self->m_pCppEnrollImpl->get_Reader(sValue));
    return Py_BuildValue("s", sValue.GetString());
}

static PyObject *Container_getFQCN(Container *self)
{
    CAtlString sValue;
    HR_METHOD_ERRORCHECK_RETURN(self->m_pCppEnrollImpl->get_FQCN(sValue));
    return Py_BuildValue("s", sValue.GetString());
}

static PyObject *Container_getName(Container *self)
{
    CAtlString sValue;
    HR_METHOD_ERRORCHECK_RETURN(self->m_pCppEnrollImpl->get_Name(sValue));
    return Py_BuildValue("s", sValue.GetString());
}

static PyObject *Container_Delete(Container *self, PyObject *args)
{
    HR_METHOD_ERRORCHECK_RETURN(self->m_pCppEnrollImpl->Delete());
    Py_RETURN_NONE;
}

static PyObject *Container_getKeys(Container *self)
{
    NS_SHARED_PTR::shared_ptr<CPPEnrollContainerKeys> pContKeys;
    HR_METHOD_ERRORCHECK_RETURN(self->m_pCppEnrollImpl->get_Keys(pContKeys));
    PyObject *pPyContainerKeys = PyObject_CallObject((PyObject *)&ContainerKeysType, NULL);
    ContainerKeys *pContainerKeys = (ContainerKeys *)pPyContainerKeys;
    pContainerKeys->m_pCppEnrollImpl = pContKeys;
    return Py_BuildValue("N", pContainerKeys);
}

static int Container_setSilent(Container *self, PyObject *value)
{
    int bValue = 0;
    if (!PyArg_Parse(value, "i", &bValue))
    {
        return -1;
    }
    HR_SETTER_ERRORCHECK_RETURN(self->m_pCppEnrollImpl->set_Silent(bValue));
    return 0;
}

static PyGetSetDef Container_getset[] = {
    {"UniqueName", (getter)Container_getUniqueName, NULL, "UniqueName", NULL},
    {"Media", (getter)Container_getMedia, NULL, "Media", NULL},
    {"Reader", (getter)Container_getReader, NULL, "Reader", NULL},
    {"FQCN", (getter)Container_getFQCN, NULL, "FQCN", NULL},
    {"Name", (getter)Container_getName, NULL, "Name", NULL},
    {"Keys", (getter)Container_getKeys, NULL, "Keys", NULL},
    {"Silent", NULL, (setter)Container_setSilent, "Silent", NULL},
    {NULL} /* Sentinel */
};

static PyMethodDef Container_methods[] = {
    {"Delete", (PyCFunction)Container_Delete, METH_NOARGS, "Delete"},
    {NULL} /* Sentinel */
};

PyTypeObject ContainerType = {
    PyVarObject_HEAD_INIT(NULL, 0) "pycades.Container", /* tp_name */
    sizeof(Container),                                  /* tp_basicsize */
    0,                                                  /* tp_itemsize */
    (destructor)Container_dealloc,                      /* tp_dealloc */
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
    "Container object",                                 /* tp_doc */
    0,                                                  /* tp_traverse */
    0,                                                  /* tp_clear */
    0,                                                  /* tp_richcompare */
    0,                                                  /* tp_weaklistoffset */
    0,                                                  /* tp_iter */
    0,                                                  /* tp_iternext */
    Container_methods,                                  /* tp_methods */
    0,                                                  /* tp_members */
    Container_getset,                                   /* tp_getset */
    0,                                                  /* tp_base */
    0,                                                  /* tp_dict */
    0,                                                  /* tp_descr_get */
    0,                                                  /* tp_descr_set */
    0,                                                  /* tp_dictoffset */
    0,                                                  /* tp_init */
    0,                                                  /* tp_alloc */
    Container_new,                                      /* tp_new */
};
