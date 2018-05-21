/*
C:\work\go\cgo\GoPy>go build -o foo.exe
C:\work\go\cgo\GoPy>set PYTHONHOME=C:/msys64/mingw64
*/

package main

/*
#cgo pkg-config: python
#include <stdlib.h>
#include "foo.h"
*/
import "C"
import (
	"unsafe"
	"fmt"
)

func main() {
	pyfile_c := C.CString("foo.py")
	defer C.free(unsafe.Pointer(pyfile_c))
	ctx := C.mypy_initialize(pyfile_c)
	if ctx == nil {
		return
	}
	defer C.mypy_finalize(ctx)
	my_main(ctx)
}

/*
func conv_int_array(a []int) (r *C.my_int_array) {
	r = C.new_my_int_array(C.int(len(a)))
	for i, value := range a {
		fmt.Println("#i =", i)
		C.my_int_array_set(r, C.int(i), C.int(value))
	}
	return
}
*/

// Go の int 配列を Python の int 配列に変換する関数
func conv_int_array(a []int) (r *C.PyObject) {
	r = C.PyList_New(C.Py_ssize_t(len(a)))
	for i, value := range a {
		//fmt.Println("#i =", i)
		C.PyList_SetItem(r, C.Py_ssize_t(i),
		    C.PyInt_FromSsize_t(C.Py_ssize_t(value)))
	}
	return
}

// Go の str 配列を Python の str 配列に変換する関数
func conv_str_array(a []string) (r *C.PyObject) {
	r = C.PyList_New(C.Py_ssize_t(len(a)))
	for i, value := range a {
		value_c := C.CString(value)
		C.PyList_SetItem(r, C.Py_ssize_t(i), C.PyString_FromString(value_c))
		C.free(unsafe.Pointer(value_c))
	}
	return
}

func my_main(ctx *C.mypy_ctx) {
	C.helloworld(ctx)

	x := 111
	fmt.Printf("square(%d) = %d\n", x, (int)(C.square(ctx, C.int(x))))

	x = 123
	y := 654
	fmt.Printf("%d + %d = %d\n", x, y, (int)(C.myadd(ctx, C.int(x), C.int(y))))

	name := "DARK START"
	name_c := C.CString(name)
	defer C.free(unsafe.Pointer(name_c))
	fmt.Printf("%s\n", C.GoString(C.make_greet(ctx, name_c)))

	x = 1000
	y = 17
	ret := C.mydiv(ctx, C.int(x), C.int(y));
	defer C.free(unsafe.Pointer(ret))
	fmt.Printf("%d / %d = %d ... %d\n", x, y, ret.answer, ret.remainder)

/*
	r := C.getlisti(ctx)
	for i:=C.int(0); i<r.len; i++ {
		fmt.Printf("#%d: %d\n", i, C.my_int_array_get(r, i))
	}
*/
	C.getlists(ctx)

	// calling "convlisti"
	a := conv_int_array([]int{1,9,6,9})
	r2 := C.convlisti(ctx, a)
	if r2 == nil {
		fmt.Println("null!")
		return
	}
	// process result of "convlisti"
	for i:=C.Py_ssize_t(0); i<C.PyList_Size(r2); i++ {
		obj := C.PyList_GetItem(r2, i)
		fmt.Printf("#%d: %d\n", i, C.PyInt_AsSsize_t(obj))
	}

	// calling "convlists"
	b := conv_str_array([]string{"a1","b2","c3","d4"})
	r3 := C.convlists(ctx, b)
	if r3 == nil {
		fmt.Println("null!")
		return
	}
	// process result of "convlists"
	for i:=C.Py_ssize_t(0); i<C.PyList_Size(r3); i++ {
		obj := C.PyList_GetItem(r3, i)
		fmt.Printf("#%d: %s\n", i, C.GoString(C.PyString_AsString(obj)))
	}

}