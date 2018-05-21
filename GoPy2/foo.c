
/*
 * Very tiresome code (-_-;)

 * Build

 * with MSVC + Python2.7
	cl /DUSE_MAIN foo.c /I C:\Python27\include C:\Python27\libs\python27.lib

 * with Mingw64/Python2.7 in Msys2
	gcc -o foo foo.c -DUSE_MAIN -IC:/msys64/mingw64/include/python2.7 -LC:/msys64/mingw64/lib -lpython2.7
	set PYTHONHOME=C:/msys64/mingw64
*/

#include <stdio.h>
#include "foo.h"

/* 
 *
 */
mypy_ctx* mypy_initialize(char* pyfile) {
	mypy_ctx *ctx = NULL;
	FILE *fp = NULL;
	PyObject *main_module = NULL;

	Py_Initialize();

	//ctx = (mypy_ctx*)malloc(sizeof(mypy_ctx));
	ctx = (mypy_ctx*)PyMem_Malloc(sizeof(mypy_ctx));

	ctx->main_module = PyImport_AddModule("__main__");
	ctx->main_dict = PyModule_GetDict(ctx->main_module);
	if (! ctx->main_dict) {
		printf("Error: PyModule_GetDict\n");
		goto final;
	}
	fp = PyFile_AsFile(PyFile_FromString(pyfile, "r"));
	if (!fp) {
		printf("Error: PyFile_FromString\nfilename = %s\n", pyfile);
		goto final;
	}
	PyRun_File(fp, pyfile, Py_file_input, ctx->main_dict, ctx->main_dict);
	fclose(fp);

	return ctx;

final:
	mypy_finalize(ctx);
	return NULL;
}

void mypy_finalize(mypy_ctx* ctx) {
	Py_Finalize();
	if (ctx) {
		//free(ctx);
		PyMem_Free(ctx);
		ctx = NULL;
	}
}

void helloworld(mypy_ctx* ctx) {
	char *func_name = "helloworld";
	PyObject *func = NULL;

	if (!ctx) {
		printf("Error: empty context\n");
		return;
	}

	func = PyObject_GetAttrString(ctx->main_module, func_name);
	if (!func) {
		printf("Error: PyObject_GetAttrString\nfunc_name = %s\n", func_name);
		return;
	}
	if (!PyCallable_Check(func)) {
		printf("Error: Not Callable\nfunc_name = %s\n", func_name);
		return;
	}

/*
	PyObject_CallObject(func, PyTuple_New(0));
*/
	PyObject_CallObject(func, NULL);
}

long square(mypy_ctx* ctx, int x) {
	char *func_name = "square";
	PyObject *func = NULL;
	PyObject *args = NULL;
	PyObject *result = NULL;
	long ret = -1;

	if (!ctx) {
		printf("Error: empty context\n");
		goto final;
	}

	func = PyObject_GetAttrString(ctx->main_module, func_name);
	
	if (!func) {
		printf("Error: PyDict_GetItemString\nfunc_name = %s\n", func_name);
		goto final;
	}

	if (!PyCallable_Check(func)) {
		printf("Error: Not Callable\nfunc_name = %s\n", func_name);
		goto final;
	}

	args = PyTuple_New(1);
	PyTuple_SetItem(args, 0, PyInt_FromLong((long)x));

	result = PyObject_CallObject(func, args);
	ret = PyInt_AsLong(result);

final:
	return ret;
}

long myadd(mypy_ctx* ctx, int x, int y) {
	char *func_name = "myadd";
	PyObject *func = NULL;
	PyObject *args = NULL;
	PyObject *result = NULL;
	long ret = -1;

	if (!ctx) {
		printf("Error: empty context\n");
		goto final;
	}

	func = PyObject_GetAttrString(ctx->main_module, func_name);
	
	if (!func) {
		printf("Error: PyDict_GetItemString\nfunc_name = %s\n", func_name);
		goto final;
	}

	if (!PyCallable_Check(func)) {
		printf("Error: Not Callable\nfunc_name = %s\n", func_name);
		goto final;
	}

	args = PyTuple_New(2);
	PyTuple_SetItem(args, 0, PyInt_FromLong((long)x));
	PyTuple_SetItem(args, 1, PyInt_FromLong((long)y));

	result = PyObject_CallObject(func, args);
	ret = PyInt_AsLong(result);

final:
	return ret;
}

char* make_greet(mypy_ctx* ctx, char* x) {
	char *func_name = "make_greet";
	PyObject *func = NULL;
	PyObject *args = NULL;
	PyObject *result = NULL;
	char *ret = NULL;

	if (!ctx) {
		printf("Error: empty context\n");
		goto final;
	}

	func = PyObject_GetAttrString(ctx->main_module, func_name);
	
	if (!func) {
		printf("Error: PyDict_GetItemString\nfunc_name = %s\n", func_name);
		goto final;
	}

	if (!PyCallable_Check(func)) {
		printf("Error: Not Callable\nfunc_name = %s\n", func_name);
		goto final;
	}
	args = PyTuple_New(1);
	PyTuple_SetItem(args, 0, PyString_FromString(x));

	result = PyObject_CallObject(func, args);
	ret = PyString_AsString(result);

final:
	return ret;
}

mydiv_ret* mydiv(mypy_ctx* ctx, int x, int y) {
	char *func_name = "mydiv";
	PyObject *func = NULL;
	PyObject *args = NULL;
	PyObject *result = NULL;
	mydiv_ret *ret = NULL;

	if (!ctx) {
		printf("Error: empty context\n");
		goto final;
	}

	func = PyObject_GetAttrString(ctx->main_module, func_name);
	
	if (!func) {
		printf("Error: PyDict_GetItemString\nfunc_name = %s\n", func_name);
		goto final;
	}

	if (!PyCallable_Check(func)) {
		printf("Error: Not Callable\nfunc_name = %s\n", func_name);
		goto final;
	}

	args = PyTuple_New(2);
	PyTuple_SetItem(args, 0, PyInt_FromLong((long)x));
	PyTuple_SetItem(args, 1, PyInt_FromLong((long)y));

	result = PyObject_CallObject(func, args);

	//ret = (mydiv_ret*)malloc(sizeof(mydiv_ret));
	ret = (mydiv_ret*)PyMem_Malloc(sizeof(mydiv_ret));
	PyArg_ParseTuple(result, "ii", &(ret->answer), &(ret->remainder));

final:

	return ret;
}

/*
my_int_array *new_my_int_array(int len) {
	my_int_array *ret;
	if (len < 1) {
		return NULL;
	}
	//ret = (my_int_array*)malloc(sizeof(my_int_array));
	ret = (my_int_array*)PyMem_Malloc(sizeof(my_int_array));
	ret->len = len;
	//ret->values = (int*)malloc(sizeof(int)*len);
	ret->values = (int*)PyMem_Malloc(sizeof(int)*len);
	return ret;
}

void free_my_int_array(my_int_array *x) {
	if (!x) {
		return;
	}
	//free(x->values);
	PyMem_Free(x->values);
	//free(x);
	PyMem_Free(x);
}

int my_int_array_get(my_int_array *x, int i) {
	if (!x) {
		return -1;
	}
	return x->values[i];
}

void my_int_array_set(my_int_array *x, int i, int value) {
	if (!x) {
		return;
	}
	x->values[i] = value;
}

my_int_array* getlisti(mypy_ctx* ctx) {
	char *func_name = "getlisti";
	PyObject *func = NULL;
	PyObject *args = NULL;
	PyObject *result = NULL;
	my_int_array *ret = NULL;
	Py_ssize_t len = 0, i=0, value=0;
	PyObject *obj = NULL;

	if (!ctx) {
		printf("Error: empty context\n");
		goto final;
	}

	func = PyObject_GetAttrString(ctx->main_module, func_name);
	
	if (!func) {
		printf("Error: PyDict_GetItemString\nfunc_name = %s\n", func_name);
		goto final;
	}

	if (!PyCallable_Check(func)) {
		printf("Error: Not Callable\nfunc_name = %s\n", func_name);
		goto final;
	}

	//args = PyTuple_New(2);
	//PyTuple_SetItem(args, 0, PyInt_FromLong((long)x));
	//PyTuple_SetItem(args, 1, PyInt_FromLong((long)y));

	result = PyObject_CallObject(func, args);

	if (!PyList_Check(result)) {
		goto final;
	}

	len = PyList_Size(result);
	//printf("len = %d\n", len);

	ret = new_my_int_array(len);
	//PyArg_ParseTuple(result, "ii", &(ret->answer), &(ret->remainder));


	for (i=0; i<len; i++) {
		obj = PyList_GetItem(result, i);
		if (PyInt_Check(obj)) {
			value = PyInt_AsSsize_t(obj);
			//printf("%d: %d\n", i, value);
			my_int_array_set(ret, i, value);
		} else {
			printf("Error: %d: not integer.\n", i);
		}
	}

final:
	//return;
	return ret;
}
*/

/*
my_int_array* convlisti(mypy_ctx* ctx, my_int_array* a) {
	char *func_name = "convlisti";
	PyObject *func = NULL;
	PyObject *arg = NULL;
	PyObject *args = NULL;
	PyObject *result = NULL;
	my_int_array *ret = NULL;
	Py_ssize_t len = 0, i=0, value=0;
	PyObject *obj = NULL;

	if (!ctx) {
		printf("Error: empty context\n");
		goto final;
	}

	func = PyObject_GetAttrString(ctx->main_module, func_name);
	
	if (!func) {
		printf("Error: PyDict_GetItemString\nfunc_name = %s\n", func_name);
		goto final;
	}

	if (!PyCallable_Check(func)) {
		printf("Error: Not Callable\nfunc_name = %s\n", func_name);
		goto final;
	}

	arg = PyList_New(a->len);
	for (i=0; i<a->len; i++) {
		value = my_int_array_get(a, i);
		printf("i = %d, value = %d\n", i, value);
		PyList_SetItem(arg, i, PyInt_FromSsize_t(value));
	}
	args = PyTuple_New(1);
	PyTuple_SetItem(args, 0, arg);

	result = PyObject_CallObject(func, args);

	if (!result) {
		printf("Error: PyObject_CallObject() returned NULL\n");
		goto final;
	}

	if (!PyList_Check(result)) {
		printf("Error: PyList_Check()\n");
		goto final;
	}

	len = PyList_Size(result);
	//printf("len = %d\n", len);

	ret = new_my_int_array(len);
	//PyArg_ParseTuple(result, "ii", &(ret->answer), &(ret->remainder));


	for (i=0; i<len; i++) {
		obj = PyList_GetItem(result, i);
		if (PyInt_Check(obj)) {
			value = PyInt_AsSsize_t(obj);
			//printf("%d: %d\n", i, value);
			my_int_array_set(ret, i, value);
		} else {
			printf("Error: %d: not integer.\n", i);
		}
	}

final:
	//return;
	return ret;
}
*/

/*
my_int_ret* conv_PyInt(PyObject *obj) {
	my_int_ret *r = (my_int_ret*)malloc(sizeof(my_int_ret));
	r->ok = 0;
	if (PyInt_Check(obj)) {
		r->ok = 1;
		r->value = PyInt_AsSsize_t(obj);
	}
	return r;
}
*/

PyObject* convlisti(mypy_ctx* ctx, PyObject* a) {
	char *func_name = "convlisti";
	PyObject *func = NULL;
	PyObject *arg = NULL;
	PyObject *args = NULL;
	PyObject *result = NULL;
	PyObject *ret = NULL;
	PyObject *obj = NULL;
	Py_ssize_t len = 0, i=0;

	if (!ctx) {
		printf("Error: empty context\n");
		goto final;
	}

	func = PyObject_GetAttrString(ctx->main_module, func_name);
	
	if (!func) {
		printf("Error: PyDict_GetItemString\nfunc_name = %s\n", func_name);
		goto final;
	}

	if (!PyCallable_Check(func)) {
		printf("Error: Not Callable\nfunc_name = %s\n", func_name);
		goto final;
	}

	args = PyTuple_New(1);
//	PyTuple_SetItem(args, 0, arg);
	PyTuple_SetItem(args, 0, a);

	result = PyObject_CallObject(func, args);

	if (!result) {
		printf("Error: PyObject_CallObject() returned NULL\n");
		goto final;
	}

	if (!PyList_Check(result)) {
		printf("Error: PyList_Check()\n");
		goto final;
	}

	len = PyList_Size(result);

	for (i=0; i<len; i++) {
		if (!PyInt_Check(PyList_GetItem(result, i))) {
			printf("Error: result is not list of int\n");
			goto final;
		}
	}

	ret = result;

final:
	//return;
	return ret;
}

void getlists(mypy_ctx* ctx) {
	char *func_name = "getlists";
	PyObject *func = NULL;
	PyObject *args = NULL;
	PyObject *result = NULL;
	//mydiv_ret *ret = NULL;
	Py_ssize_t len = 0, i=0;
	char *value = NULL;
	PyObject *obj = NULL;

	if (!ctx) {
		printf("Error: empty context\n");
		goto final;
	}

	func = PyObject_GetAttrString(ctx->main_module, func_name);
	
	if (!func) {
		printf("Error: PyDict_GetItemString\nfunc_name = %s\n", func_name);
		goto final;
	}

	if (!PyCallable_Check(func)) {
		printf("Error: Not Callable\nfunc_name = %s\n", func_name);
		goto final;
	}

	//args = PyTuple_New(2);
	//PyTuple_SetItem(args, 0, PyInt_FromLong((long)x));
	//PyTuple_SetItem(args, 1, PyInt_FromLong((long)y));

	result = PyObject_CallObject(func, args);

	//ret = (mydiv_ret*)malloc(sizeof(mydiv_ret));
	//PyArg_ParseTuple(result, "ii", &(ret->answer), &(ret->remainder));

	if (!PyList_Check(result)) {
		goto final;
	}

	len = PyList_Size(result);
	printf("len = %d\n", len);
	for (i=0; i<len; i++) {
		obj = PyList_GetItem(result, i);
		if (PyString_Check(obj)) {
			value = PyString_AsString(obj);
			printf("%d: %s\n", i, value);
		} else {
			printf("%d: not string.\n", i);
		}
	}

final:
	return;
	//return ret;
}

PyObject* convlists(mypy_ctx* ctx, PyObject* a) {
	char *func_name = "convlists";
	PyObject *func = NULL;
	PyObject *arg = NULL;
	PyObject *args = NULL;
	PyObject *result = NULL;
	PyObject *ret = NULL;
	PyObject *obj = NULL;
	Py_ssize_t len = 0, i=0;

	if (!ctx) {
		printf("Error: empty context\n");
		goto final;
	}

	func = PyObject_GetAttrString(ctx->main_module, func_name);
	
	if (!func) {
		printf("Error: PyDict_GetItemString\nfunc_name = %s\n", func_name);
		goto final;
	}

	if (!PyCallable_Check(func)) {
		printf("Error: Not Callable\nfunc_name = %s\n", func_name);
		goto final;
	}

	args = PyTuple_New(1);
//	PyTuple_SetItem(args, 0, arg);
	PyTuple_SetItem(args, 0, a);

	result = PyObject_CallObject(func, args);

	if (!result) {
		printf("Error: PyObject_CallObject() returned NULL\n");
		goto final;
	}

	if (!PyList_Check(result)) {
		printf("Error: PyList_Check()\n");
		goto final;
	}

	len = PyList_Size(result);

	for (i=0; i<len; i++) {
		if (!PyString_Check(PyList_GetItem(result, i))) {
			printf("Error: result is not list of str\n");
			goto final;
		}
	}

	ret = result;

final:
	//return;
	return ret;
}

#ifdef USE_MAIN

int main(int ac, char **av)
{
	char *filename = "foo.py";
	mypy_ctx *ctx = NULL;
	int x, y;
	long result;
	char *name, *msg;
	mydiv_ret *ret;

	ctx = mypy_init(filename);
	if (!ctx) {
		printf("?!");
		return 1;
	}
	helloworld(ctx);

	x = 111;
	result = square(ctx, x);
	printf("square(%d) = %d\n", x, result);

	x = 123;
	y = 654;
	result = myadd(ctx, x, y);
	printf("%d + %d = %d\n", x, y, result);

	name = "DARK START";
	msg = make_greet(ctx, name);
	printf("%s\n", msg);

	x = 1000;
	y = 17;
	ret = mydiv(ctx, x, y);
	printf("%d / %d = %d ... %d\n", x, y, ret->answer, ret->remainder);
	//free(ret);
	PyMem_Free(ret);
	
	mypy_final(ctx);

	return 0;
}

#endif
