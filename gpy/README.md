# Minimal sample to Call Go function from Python

## Environment

```
C:\work\go\cgo\g>go version
go version go1.8.3 windows/amd64

C:\work\go\cgo\g>gcc --version
gcc (Rev2, Built by MSYS2 project) 7.2.0
Copyright (C) 2017 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

## How to build

```
C:\work\go\cgo\g>make
go build -buildmode=c-archive foo.go
gcc  -c main.c
gcc -o g.exe main.o foo.a -lWs2_32 -lwinmm
```

## Example

```
C:\work\go\cgo\g>g
Square(111) = 12321
Hello, GoLang!
Foo(123, 654) = (777, -531)
2018-02-08T16:44:42+09:00
```
