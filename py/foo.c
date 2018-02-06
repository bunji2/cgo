
/* Build

 * MSVC on Windows
	cl /DUSE_MAIN foo.c /I C:\Python27\include C:\Python27\libs\python27.lib

 * Mingw64/Msys2 on Windows
	gcc -o foo foo.c -DUSE_MAIN -IC:/msys64/mingw64/include/python2.7 -LC:/msys64/mingw64/lib -lpython2.7
	set PYTHONHOME=C:/msys64/mingw64
*/

#include <stdio.h>
#include "foo.h"


// returns 0 for FAILURE
// returns other value for SUCCESS
long exec_python_func(char *filename, char *func_name, int x, int y) {
	FILE *fp = NULL;
	PyObject *main_module = NULL;
	PyObject *main_dict = NULL;
	PyObject *func = NULL;
	PyObject *ans = NULL;
	long result = 0;

	Py_Initialize();

	main_module = PyImport_AddModule("__main__");
	main_dict = PyModule_GetDict(main_module);
	if (!main_dict) {
		printf("Error: PyModule_GetDict\n");
		goto final;
	}

	fp = PyFile_AsFile(PyFile_FromString(filename, "r"));
	if (!fp) {
		printf("Error: PyFile_FromString\nfilename = %s\n", filename);
		goto final;
	}
	PyRun_File(fp, filename, Py_file_input, main_dict, main_dict);

/*
	fp = fopen(filename, "r");
	PyRun_SimpleFile(fp, filename);
*/


	func = PyDict_GetItemString(main_dict, func_name);
	
	if (!func) {
		printf("Error: PyDict_GetItemString\nfunc_name = %s\n", func_name);
		goto final;
	}

	if (PyCallable_Check(func)) {
		ans = PyEval_CallFunction(func, "ii", x, y);
		result = PyInt_AsLong(ans);
	}

final:

	if (main_dict) {
		Py_XDECREF(main_dict);
	}
	if (main_dict) {
		Py_XDECREF(main_dict);
	}
	if (func) {
		Py_XDECREF(func);
	}
	if (ans) {
		Py_XDECREF(ans);
	}
	Py_Finalize();

	return result;
}

#ifdef USE_MAIN

int main(int ac, char **av)
{
	char *filename = "script.py";
	char *func_name = "multiply";
	int x, y;
	long result;
	if (ac < 3) {
		printf("Usage: foo.exe x_value y_value");
		return 1;
	}
	x = atoi(av[1]);
	y = atoi(av[2]);
	result = exec_python_func(filename, func_name, x, y);
	printf("result = %d\n", result);
	return 0;
}

#endif
