package main

/*
#include <stdlib.h>
#include "foo.h"
*/
import "C"
import (
	"fmt"
	"unsafe"
)

func main() {
	C.helloworld()

	x := 111
	fmt.Printf("square(%d) = %d\n", x, C.square(C.int(x)));

	x = 123
	y := 654
	fmt.Printf("add(%d, %d) = %d\n", x, y, C.add(C.int(x), C.int(y)))

	name := "DARK STAR";
	name_c := C.CString(name) // Go string -> C string
	defer C.free(unsafe.Pointer(name_c)) // you must free!
	msg_c := C.make_greet(name_c)
	fmt.Printf("%s\n", C.GoString(msg_c))
	C.free_greet(msg_c);

	x = 1000
	y = 17
	r := C.mydiv(C.int(x), C.int(y));
	fmt.Printf("%d / %d = %d ... %d\n", x, y, int(C.mydiv_answer(r)),
	int(C.mydiv_remainder(r)))
	C.mydiv_free(r);
}
