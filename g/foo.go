package main

import "C"
import (
	"fmt"
	"time"
	"unsafe"
)

//export Square
func Square(x int32) int32 {
//	fmt.Println("Go:", x)
	return x*x
}

//export Double
func Double(x int32) int32 {
	//	fmt.Println("Go:", x)
	return x+x
}

//export Greet
func Greet(name string) {
	//fmt.Println("Go:", name)
	fmt.Printf("Hello, %s!\n", name)
}

//export Foo
func Foo(x, y int32) (u, v int32) {
	u = x + y
	v = x - y
	return
}

//export Now
func Now() uintptr {
	buf := []byte(now())
	return uintptr(unsafe.Pointer(&buf[0]))
}

func now() string {
	return time.Now().Format(time.RFC3339)
}

// Dummy main
func main(){}
