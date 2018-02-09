# Makefile for MINGW64/MSYS2 + opencv-2.4.13.5

TARGETS=foo.pyd

GOFLAGS=build -buildmode=c-archive

#C:\work\go\cgo\gpy>pkg-config python --cflags
#-IC:/msys64/mingw64/include/python2.7
CFLAGS=-IC:/msys64/mingw64/include/python2.7

#C:\work\go\cgo\gpy>pkg-config python --libs
#-LC:/msys64/mingw64/lib -lpython2.7

LIBS=-lWs2_32 -lwinmm -LC:/msys64/mingw64/lib -lpython2.7

GO=go
CC=gcc
RM=rm -f
GREP=grep

.SUFFIXES: .o .c

all: $(TARGETS)

clean:
	$(RM) *.o *.exe foo.a foo.h foo.pyd

.c.o:
	$(CC) $(CFLAGS) -c $<

foo.h: foo.go
	$(GO) $(GOFLAGS) $^

foo.a: foo.go
	$(GO) $(GOFLAGS) $^

wrapper.c: foo.h

foo.pyd: wrapper.o foo.a
	$(CC) -shared $^ $(LIBS) -o $@

