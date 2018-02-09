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

int main(int argc, char**argv) {
    int x, y;
    char *name, *msg;
    GoString name_g;
    struct mydiv_return r;

    helloworld();

    x = 111;
    printf("square(%d) = %d\n", x, (int)square((GoInt)x));

    x = 123;
    y = 654;
    printf("add(%d, %d) = %d\n", x, y, (int)myadd((GoInt)x, (GoInt)y));

    name = "DARK STAR";
    set_GoString(&name_g, name);
    msg = (char*)make_greet(name_g);
    printf("%s\n", msg);

    x = 1000;
    y = 17;
    r = mydiv((GoInt)x, (GoInt)y);
    printf("%d / %d = %d ... %d\n", x, y, (int)(r.r0), (int)(r.r1));

    return 0;
}
