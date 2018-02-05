package main

/*
#include "foo.h"
*/
import "C"
import (
	"fmt"
)

func main() {
	arg := 123
	result := int(C.foo(C.int(arg)))
	fmt.Printf("Go: result = %d\n", result)
}
