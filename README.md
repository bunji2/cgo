# Minimal samples of CGO

* [GoC] Calling C functions from Go program
* [CGo] Calling Go functions from C program
* [GoPy] Calling Python functions from Go program via C
* [PyGo] Calling Go Functions from Python program via C

## Environment

* Windows 7 Professional SP1 64bit
* Go 1.9.3 windows/amd64
* MSYS64
  * gcc (Rev2, Built by MSYS2 project) 7.3.0
  * gnu make 4.2.1
  * Python 2.7.14

## Instaling MSYS64 / MINGW64

Download x86_64 installer from http://www.msys2.org/ and install.

Enter following commands at your msys console.

```
$ pacman -Sy
$ pacman -Su

(you will restart msys console.)

$ pacman -S base-devel
$ pacman -S mingw-w64-x86_64-toolchain
```

## Installing GoLang

Download x86_64 installer from https://golang.org/ and install.

## Environment Variables

```
rem GoLang
PATH C:\Go\bin;%PATH%

rem MSYS64 / MINGW64
PATH C:\msys64\mingw64\bin;C:\msys64\usr\bin;%PATH%
```

