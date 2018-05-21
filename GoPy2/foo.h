#ifndef FOO_H
#define FOO_H
#include <Python.h>

typedef struct _ctx_py {
	PyObject *main_module;
	PyObject *main_dict;
} mypy_ctx;

mypy_ctx* mypy_initialize(char* pyfile);

void mypy_finalize(mypy_ctx* ctx);

void helloworld(mypy_ctx* ctx);

long square(mypy_ctx* ctx, int x);

long myadd(mypy_ctx* ctx, int x, int y);

char* make_greet(mypy_ctx* ctx, char* x);

typedef struct _mydiv_ret {
	int answer;
	int remainder;
} mydiv_ret;

mydiv_ret* mydiv(mypy_ctx* ctx, int x, int y);

/*
typedef struct _my_int_array {
	int len;
	int *values;
} my_int_array;
my_int_array *new_my_int_array(int len);
void free_my_int_array(my_int_array *x);
int my_int_array_get(my_int_array *x, int i);
void my_int_array_set(my_int_array *x, int i, int value);

my_int_array* getlisti(mypy_ctx* ctx);
my_int_array* convlisti(mypy_ctx* ctx, my_int_array* a);
*/

PyObject* convlisti(mypy_ctx* ctx, PyObject* a);

void getlists(mypy_ctx* ctx);

PyObject* convlists(mypy_ctx* ctx, PyObject* a);

/*
typedef struct _my_int_ret {
	int ok;
	int value;
} my_int_ret;
my_int_ret* conv_PyInt(PyObject *obj);
*/

#endif /* FOO_H */
