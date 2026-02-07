#include "PyEnrollContainerKeys.h"
#include "PyEnrollContainerKey.h"
#include "PyEnrollContainer.h"

using namespace CryptoPro::PKI::Enroll;

static void ContainerKeys_dealloc(ContainerKeys *self)
{
    self->m_pCppEnrollImpl.reset();
    Py_TYPE(self)->tp_free((PyObject *)self);
}

static PyObject *ContainerKeys_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    ContainerKeys *self;
    self = (ContainerKeys *)type->tp_alloc(type, 0);
    if (self != NULL)
    {
        self->m_pCppEnrollImpl = NS_SHARED_PTR::shared_ptr<CPPEnrollContainerKeys>(new CPPEnrollContainerKeys());
    }
    return (PyObject *)self;
}

static PyObject *ContainerKeys_getCount(ContainerKeys *self)
{
    unsigned int Count = 0;
    HR_METHOD_ERRORCHECK_RETURN(self->m_pCppEnrollImpl->get_Count(&Count));
    return Py_BuildValue("l", Count);
}

static PyObject *ContainerKeys_getItemByIndex(ContainerKeys *self, PyObject *args)
{
    long lIndex = 0;
    if (!PyArg_ParseTuple(args, "l", &lIndex))
    {
        return NULL;
    }
    NS_SHARED_PTR::shared_ptr<CPPEnrollContainerKey> pCPPEnrollContainerKey;
    HR_METHOD_ERRORCHECK_RETURN(self->m_pCppEnrollImpl->get_ItemByIndex(lIndex, pCPPEnrollContainerKey));
    PyObject *pPyContainerKey = PyObject_CallObject((PyObject *)&ContainerKeyType, NULL);
    ContainerKey *pContainerKey = (ContainerKey *)pPyContainerKey;
    pContainerKey->m_pCppEnrollImpl = pCPPEnrollContainerKey;
    return Py_BuildValue("N", pContainerKey);
}

static PyGetSetDef ContainerKeys_getset[] = {
    {"Count", (getter)ContainerKeys_getCount, NULL, "Count", NULL},
    {NULL} /* Sentinel */
};

static PyMethodDef ContainerKeys_methods[] = {
    {"ItemByIndex", (PyCFunction)ContainerKeys_getItemByIndex, METH_VARARGS, "ItemByIndex"},
    {NULL} /* Sentinel */
};

PyTypeObject ContainerKeysType = {
    PyVarObject_HEAD_INIT(NULL, 0) "pycades.ContainerKeys", /* tp_name */
    sizeof(ContainerKeys),                                  /* tp_basicsize */
    0,                                                      /* tp_itemsize */
    (destructor)ContainerKeys_dealloc,                      /* tp_dealloc */
    0,                                                      /* tp_print */
    0,                                                      /* tp_getattr */
    0,                                                      /* tp_setattr */
    0,                                                      /* tp_compare */
    0,                                                      /* tp_repr */
    0,                                                      /* tp_as_number */
    0,                                                      /* tp_as_sequence */
    0,                                                      /* tp_as_mapping */
    0,                                                      /* tp_hash */
    0,                                                      /* tp_call */
    0,                                                      /* tp_str */
    0,                                                      /* tp_getattro */
    0,                                                      /* tp_setattro */
    0,                                                      /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,               /* tp_flags */
    "ContainerKeys object",                                 /* tp_doc */
    0,                                                      /* tp_traverse */
    0,                                                      /* tp_clear */
    0,                                                      /* tp_richcompare */
    0,                                                      /* tp_weaklistoffset */
    0,                                                      /* tp_iter */
    0,                                                      /* tp_iternext */
    ContainerKeys_methods,                                  /* tp_methods */
    0,                                                      /* tp_members */
    ContainerKeys_getset,                                   /* tp_getset */
    0,                                                      /* tp_base */
    0,                                                      /* tp_dict */
    0,                                                      /* tp_descr_get */
    0,                                                      /* tp_descr_set */
    0,                                                      /* tp_dictoffset */
    0,                                                      /* tp_init */
    0,                                                      /* tp_alloc */
    ContainerKeys_new,                                      /* tp_new */
};

