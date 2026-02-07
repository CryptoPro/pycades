#include "PyEnrollContainers.h"
#include "PyEnrollContainer.h"

using namespace CryptoPro::PKI::Enroll;

static void Containers_dealloc(Containers *self)
{
    self->m_pCppEnrollImpl.reset();
    Py_TYPE(self)->tp_free((PyObject *)self);
}

static PyObject *Containers_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    Containers *self;
    self = (Containers *)type->tp_alloc(type, 0);
    if (self != NULL)
    {
        self->m_pCppEnrollImpl = NS_SHARED_PTR::shared_ptr<CPPEnrollContainers>(new CPPEnrollContainers());
    }
    return (PyObject *)self;
}

static PyObject *Containers_getCount(Containers *self)
{
    unsigned int Count = 0;
    HR_METHOD_ERRORCHECK_RETURN(self->m_pCppEnrollImpl->get_Count(&Count));
    return Py_BuildValue("l", Count);
}

static PyObject *Containers_getItemByIndex(Containers *self, PyObject *args)
{
    long lIndex = 0;
    if (!PyArg_ParseTuple(args, "l", &lIndex))
    {
        return NULL;
    }
    NS_SHARED_PTR::shared_ptr<CPPEnrollContainer> pCPPEnrollContainer;
    HR_METHOD_ERRORCHECK_RETURN(self->m_pCppEnrollImpl->get_ItemByIndex(lIndex, pCPPEnrollContainer));
    PyObject *pPyContainer = PyObject_CallObject((PyObject *)&ContainerType, NULL);
    Container *pContainer = (Container *)pPyContainer;
    pContainer->m_pCppEnrollImpl = pCPPEnrollContainer;
    return Py_BuildValue("N", pContainer);
}

static PyGetSetDef Containers_getset[] = {
    {"Count", (getter)Containers_getCount, NULL, "Count", NULL},
    {NULL} /* Sentinel */
};

static PyMethodDef Containers_methods[] = {
    {"ItemByIndex", (PyCFunction)Containers_getItemByIndex, METH_VARARGS, "ItemByIndex"},
    {NULL} /* Sentinel */
};

PyTypeObject ContainersType = {
    PyVarObject_HEAD_INIT(NULL, 0) "pycades.Containers", /* tp_name */
    sizeof(Containers),                                  /* tp_basicsize */
    0,                                                   /* tp_itemsize */
    (destructor)Containers_dealloc,                      /* tp_dealloc */
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
    "Containers object",                                 /* tp_doc */
    0,                                                   /* tp_traverse */
    0,                                                   /* tp_clear */
    0,                                                   /* tp_richcompare */
    0,                                                   /* tp_weaklistoffset */
    0,                                                   /* tp_iter */
    0,                                                   /* tp_iternext */
    Containers_methods,                                  /* tp_methods */
    0,                                                   /* tp_members */
    Containers_getset,                                   /* tp_getset */
    0,                                                   /* tp_base */
    0,                                                   /* tp_dict */
    0,                                                   /* tp_descr_get */
    0,                                                   /* tp_descr_set */
    0,                                                   /* tp_dictoffset */
    0,                                                   /* tp_init */
    0,                                                   /* tp_alloc */
    Containers_new,                                      /* tp_new */
};
