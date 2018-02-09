package main

import "C"
import (
	"fmt"
	"unsafe"
)

// Dummy Main
func main() {}

/*
 * void -> void
 */
//export helloworld
func helloworld() {
    fmt.Printf("Hello, world.\n");
}

/*
 * int -> int
 */
//export square
func square(x C.int) C.int {
    return x*x
}

/*
 * (int, int) -> int
 */
//export myadd
func myadd(x, y C.int) C.int {
    return x+y
}

/*
 * string -> string
 */
//export make_greet
func make_greet(x *C.char) uintptr {
	buf := []byte(fmt.Sprintf("Hello, %s!", C.GoString(x)))
	return uintptr(unsafe.Pointer(&buf[0]))
}

/*
 * (int,int) -> (int, int)
 */
//export mydiv
func mydiv(x, y C.int) (answer, remainder C.int){
    answer = x/y;
    remainder = x%y;
    return;
}
