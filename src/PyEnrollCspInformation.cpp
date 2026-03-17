#include "PyEnrollCspInformation.h"
#include "PyEnrollContainers.h"

using namespace CryptoPro::PKI::Enroll;

static void CspInformation_dealloc(CspInformation *self)
{
    self->m_pCppEnrollImpl.reset();
    Py_TYPE(self)->tp_free((PyObject *)self);
}

static PyObject *CspInformation_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    CspInformation *self;
    self = (CspInformation *)type->tp_alloc(type, 0);
    if (self != NULL)
    {
        self->m_pCppEnrollImpl = NS_SHARED_PTR::shared_ptr<CPPEnrollCspInformation>(new CPPEnrollCspInformation());
    }
    return (PyObject *)self;
}

static PyObject *CspInformation_InitializeFromName(CspInformation *self, PyObject *args)
{
    char *szName = "";
    if (!PyArg_ParseTuple(args, "s", &szName))
    {
        return NULL;
    }
    CAtlString sName = CAtlString(szName);
    HR_METHOD_ERRORCHECK_RETURN(self->m_pCppEnrollImpl->InitializeFromName(sName));
    Py_RETURN_NONE;
}

static PyObject *CspInformation_EnumContainers(CspInformation *self)
{
    NS_SHARED_PTR::shared_ptr<CPPEnrollContainers> pVal;
    HR_METHOD_ERRORCHECK_RETURN(self->m_pCppEnrollImpl->EnumContainers(pVal));
    PyObject *pPyContainers = PyObject_CallObject((PyObject *)&ContainersType, NULL);
    Containers *pContainers = (Containers *)pPyContainers;
    pContainers->m_pCppEnrollImpl = pVal;
    return Py_BuildValue("N", pContainers);
}

static PyGetSetDef CspInformation_getset[] = {
    {NULL} /* Sentinel */
};

static PyMethodDef CspInformation_methods[] = {
    {"InitializeFromName", (PyCFunction)CspInformation_InitializeFromName, METH_VARARGS, "InitializeFromName"},
    {"EnumContainers", (PyCFunction)CspInformation_EnumContainers, METH_NOARGS, "EnumContainers"},
    {NULL} /* Sentinel */
};

PyTypeObject CspInformationType = {
    PyVarObject_HEAD_INIT(NULL, 0) "pycades.CspInformation", /* tp_name */
    sizeof(CspInformation),                                  /* tp_basicsize */
    0,                                                       /* tp_itemsize */
    (destructor)CspInformation_dealloc,                      /* tp_dealloc */
    0,                                                       /* tp_print */
    0,                                                       /* tp_getattr */
    0,                                                       /* tp_setattr */
    0,                                                       /* tp_compare */
    0,                                                       /* tp_repr */
    0,                                                       /* tp_as_number */
    0,                                                       /* tp_as_sequence */
    0,                                                       /* tp_as_mapping */
    0,                                                       /* tp_hash */
    0,                                                       /* tp_call */
    0,                                                       /* tp_str */
    0,                                                       /* tp_getattro */
    0,                                                       /* tp_setattro */
    0,                                                       /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                /* tp_flags */
    "CspInformation object",                                 /* tp_doc */
    0,                                                       /* tp_traverse */
    0,                                                       /* tp_clear */
    0,                                                       /* tp_richcompare */
    0,                                                       /* tp_weaklistoffset */
    0,                                                       /* tp_iter */
    0,                                                       /* tp_iternext */
    CspInformation_methods,                                  /* tp_methods */
    0,                                                       /* tp_members */
    CspInformation_getset,                                   /* tp_getset */
    0,                                                       /* tp_base */
    0,                                                       /* tp_dict */
    0,                                                       /* tp_descr_get */
    0,                                                       /* tp_descr_set */
    0,                                                       /* tp_dictoffset */
    0,                                                       /* tp_init */
    0,                                                       /* tp_alloc */
    CspInformation_new,                                      /* tp_new */
};
