package main

/*
#include <stdlib.h>
#include "helloworld.h"
*/
import "C"
import (
	"unsafe"
	"fmt"
	"os"
)

func main() {
	if len(os.Args)<2 {
		fmt.Printf("Usage: %s your_name\n", os.Args[0])
		return
	}
	name_c := C.CString(os.Args[1])
	defer C.free(unsafe.Pointer(name_c))
	C.greet(name_c)
}
