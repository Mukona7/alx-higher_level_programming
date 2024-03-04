/*
 * File: 100-print_python_list_info.c
 */

#include <Python.h>

/**
 * print_python_list_info - Prints basic info about Python lists.
 * @pyObject: A PyObject list.
 */
void print_python_list_info(PyObject *pyObject)
{
	int size, alloc, x;
	PyObject *obj;

	size = Py_SIZE(pyObject);
	alloc = ((PyListObject *)pyObject)->allocated;

	printf("[*] Size of the Python List = %d\n", size);
	printf("[*] Allocated = %d\n", alloc);

	for (x = 0; x < size; x++)
	{
		printf("Element %d: ", x);

		obj = PyList_GetItem(pyObject, x);
		printf("%s\n", Py_TYPE(obj)->tp_name);
	}
}
