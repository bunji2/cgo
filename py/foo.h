#ifndef FOO_H
#define FOO_H

#include <Python.h>

long
exec_python_func(
	char *filename,
	char *func_name,
	int x,
	int y
);

#endif /* FOO_H */
