# Makefile for MINGW64/MSYS2 + opencv-2.4.13.5

TARGETS=foo.exe

GOFLAGS=build -buildmode=c-archive

CFLAGS=

LIBS=-lWs2_32 -lwinmm

GO=go
CC=gcc
RM=rm -f
GREP=grep

.SUFFIXES: .o .c

all: $(TARGETS)

clean:
	$(RM) *.o *.exe *.a foo.h

.c.o:
	$(CC) $(CFLAGS) -c $<

foo.h: foo.go
	$(GO) $(GOFLAGS) $^

foo.a: foo.go
	$(GO) $(GOFLAGS) $^

foo.c: foo.h

foo.exe: foo.o foo.a
	$(CC) -o $@ $^ $(LIBS)
