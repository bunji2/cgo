package main

/*
#include "mydiv.h"
*/
import "C"
import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	if len(os.Args)<3 {
		fmt.Printf("Usage: %s arg1 arg2\n", os.Args[0])
		return
	}
	arg1, _ := strconv.Atoi(os.Args[1])
	arg2, _ := strconv.Atoi(os.Args[2])
	result := C.mydiv(C.int(arg1), C.int(arg2))
	defer C.mydiv_free(result)
	fmt.Printf("%d / %d = %d ... %d\n", arg1, arg2, 
		int(C.mydiv_answer(result)), int(C.mydiv_remainder(result)))
	C.mydiv_free(result)
}
