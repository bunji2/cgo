# Minimal sample of CGO with Python C API

## Environment

```
C:\work\go\cgo\py>go version
go version go1.9.3 windows/amd64

C:\work\go\cgo\py>gcc --version
gcc (Rev1, Built by MSYS2 project) 7.3.0
Copyright (C) 2017 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

C:\work\go\cgo\py>pkg-config python --cflags --libs
-IC:/msys64/mingw64/include/python2.7 -LC:/msys64/mingw64/lib -lpython2.7
```


## How to build

```
go build
```

## Example

```
C:\work\go\cgo\py>PATH C:\msys64\mingw64\bin;%PATH%
C:\work\go\cgo\py>set PYTHONHOME=C:/msys64/mingw64

C:\work\go\cgo\py>py.exe
Usage: py.exe arg1 arg2

C:\work\go\cgo\py>py.exe 1111 1111
result = 1234321
```
