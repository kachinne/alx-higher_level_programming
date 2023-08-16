#include <stdio.h>
#include <Python.h>

/**
 * print_python_list_info - prints python list info here
 *
 * @p: PyObject
 * Return: no return
 */
void print_python_list_info(PyObject *p)
{
	int i, l;

	l = PyList_Size(p)
	for (i = 0 ; i < l ; i++)
		printf("[*] Size of the Python List = %d", l);
}
