# Makefile for MINGW64/MSYS2 + opencv-2.4.13.5

TARGETS=g.exe

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
	$(RM) *.o *.exe *.a

.c.o:
	$(CC) $(CFLAGS) -c $<

foo.h: foo.go
	$(GO) $(GOFLAGS) $^

foo.a: foo.go
	$(GO) $(GOFLAGS) $^

main.c: foo.h

g.exe: main.o foo.a
	$(CC) -o $@ $^ $(LIBS)
