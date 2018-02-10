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

#endif /* FOO_H */
