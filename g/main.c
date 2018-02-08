#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "foo.h"

void set_GoString(GoString *str_g, char *str) {
    if (!str_g || !str) {
        return;
    }
    str_g->p = str;
    str_g->n = (GoInt)strlen(str);
}

int main(int argc, char **argv) {
    int arg = 111, x=123, y=654;
    char *name = "GoLang";
    GoString name_g, ret_g;
    struct Foo_return result;
    char *r;

    // (1) pass int and receive int

    printf("Square(%d) = %d\n", arg, (int)Square((GoInt32)arg));

    // (2) pass string

    set_GoString(&name_g, name);
    Greet(name_g);

    // (3) pass int+int and receive int+int

    result = Foo((GoInt32)x, (GoInt32)y);
    printf("Foo(%d, %d) = (%d, %d)\n", x, y, (int)result.r0, (int)result.r1);

    // (4) receive string

    r = (char*)Now();
    printf("%s\n", r);

    return 0;
}