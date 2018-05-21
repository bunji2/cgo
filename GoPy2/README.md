# [GoPy] Calling Python functions from Go program via C

## How to build

```
C:\work\go\cgo\GoPy>go build -o foo.exe
```

## Execution

```
C:\work\go\cgo\GoPy>PATH C:\msys64\mingw64\bin;%PATH%
C:\work\go\cgo\GoPy>set PYTHONHOME=C:/msys64/mingw64

C:\work\go\cgo\GoPy>foo.exe
Hello, world.
square(111) = 12321
123 + 654 = 777
Hello, DARK START!
1000 / 17 = 58 ... 14
```
