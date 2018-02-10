
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

	ctx = (mypy_ctx*)malloc(sizeof(mypy_ctx));

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
		free(ctx);
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

	ret = (mydiv_ret*)malloc(sizeof(mydiv_ret));
	PyArg_ParseTuple(result, "ii", &(ret->answer), &(ret->remainder));

final:

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
	free(ret);
	
	mypy_final(ctx);

	return 0;
}

#endif
