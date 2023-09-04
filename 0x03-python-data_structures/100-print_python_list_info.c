
#include <Python.h>
#include <stdio.h>

void print_python_list_info(PyObject *p) {
    Py_ssize_t len = PyList_Size(p);
    Py_ssize_t i;

    printf("[*] Size of the Python List = %ld\n", len);
    printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

    for (i = 0; i < len; i++) {
        PyObject *item = PyList_GetItem(p, i);
        const char *item_type = item->ob_type->tp_name;

        printf("Element %ld: %s\n", i, item_type);
    }
}

int main(int argc, char *argv[]) {
    // This is a test program. You can call the print_python_list_info
    // function with a Python list from your Python code.
    // We can use it to work on C to python

    Py_Initialize();

    // Create a Python list (you can replace this with your own list)
    PyObject *my_list = PyList_New(3);
    PyList_SetItem(my_list, 0, PyLong_FromLong(1));
    PyList_SetItem(my_list, 1, PyFloat_FromDouble(3.14));
    PyList_SetItem(my_list, 2, PyUnicode_DecodeUTF8("Hello", 5, "strict"));

    print_python_list_info(my_list);

    Py_Finalize();

    return 0;
}
