# [PyGo] Calling Go Functions from Python program via C

## How to build

```
C:\work\go\cgo\PyGo>make
gcc -IC:/msys64/mingw64/include/python2.7 -c wrapper.c
go build -buildmode=c-archive foo.go
gcc -shared wrapper.o foo.a -lWs2_32 -lwinmm -LC:/msys64/mingw64/lib -lpython2.7 -o foo.pyd
```

## Execution

```
C:\work\go\cgo\PyGo>python main.py
Hello, world.
square(111) = 12321
add(123, 654) = 777
Hello, DARK STAR!
1000 / 17 = 58 ... 14
```
