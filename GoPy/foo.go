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
}