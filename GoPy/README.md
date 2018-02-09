# [GoPy] Calling Python functions from Go program via C

## How to build

```
go build -o foo.exe
```

## Execution

```
C:\work\go\cgo\GoPy>PATH C:\msys64\mingw64\bin;%PATH%
C:\work\go\cgo\GoPy>set PYTHONHOME=C:/msys64/mingw64

C:\work\go\cgo\GoPy>foo.exe
Usage: foo.exe arg1 arg2

C:\work\go\cgo\GoPy>foo.exe 1111 1111
result = 1234321
```
