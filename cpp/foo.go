package main

/*
#include "foo.h"
*/
import "C"

func main() {
	C.foo()
}
