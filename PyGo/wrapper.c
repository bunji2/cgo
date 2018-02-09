#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Python.h"
#include "foo.h"

PyObject* foo_helloworld(PyObject* self, PyObject* args) {
	helloworld();
	return Py_BuildValue("");
}

PyObject* foo_square(PyObject* self, PyObject* args) {
	int x, g;

	if (!PyArg_ParseTuple(args, "i", &x))
		return NULL;
	g = square(x);
	return Py_BuildValue("i", g);
}

PyObject* foo_myadd(PyObject* self, PyObject* args) {
	int x, y, g;

	if (!PyArg_ParseTuple(args, "ii", &x, &y))
		return NULL;
	g = myadd(x, y);
	return Py_BuildValue("i", g);
}

PyObject* foo_make_greet(PyObject* self, PyObject* args) {
	char *x, *g;

	if (!PyArg_ParseTuple(args, "s", &x))
		return NULL;
	g = (char*)make_greet(x);
	return Py_BuildValue("s", g);
}

PyObject* foo_mydiv(PyObject* self, PyObject* args) {
	int x, y;
    struct mydiv_return g;

	if (!PyArg_ParseTuple(args, "ii", &x, &y))
		return NULL;
	g = mydiv(x, y);
	return Py_BuildValue("ii", g.r0, g.r1);
}

static PyMethodDef foomethods[] = {
	{"helloworld", foo_helloworld, METH_VARARGS},
	{"square", foo_square, METH_VARARGS},
	{"myadd", foo_myadd, METH_VARARGS},
	{"make_greet", foo_make_greet, METH_VARARGS},
	{"mydiv", foo_mydiv, METH_VARARGS},
	{NULL},
};

void initfoo() {
	Py_InitModule("foo", foomethods);
}
