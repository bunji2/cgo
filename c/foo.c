#include <stdio.h>
#include "foo.h"

int foo(int arg) {
    printf("C: arg = %d \n", arg);
    return arg*2;
}