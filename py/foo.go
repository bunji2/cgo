package main

/*
#cgo pkg-config: python
#include "foo.h"
#include <stdlib.h>
*/
import "C"
import (
	"unsafe"
	"fmt"
	"os"
	"strconv"
)

func main() {
	if len(os.Args) < 3 {
		fmt.Printf("Usage: %s arg1 arg2\n", os.Args[0])
		return
	}
	filename_c := C.CString("script.py")
	defer C.free(unsafe.Pointer(filename_c))
	func_name_c := C.CString("multiply")
	defer C.free(unsafe.Pointer(func_name_c))
	arg1,_ := strconv.Atoi(os.Args[1])
	arg2,_ := strconv.Atoi(os.Args[2])
	
	result := C.exec_python_func(filename_c, func_name_c, C.int(arg1), C.int(arg2))
	fmt.Printf("result = %d\n", result)
}
