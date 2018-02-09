#include <stdio.h>
#include <stdlib.h>
#include "foo.h"

int main(int argc, char**argv) {
    int x, y;
    char *name, *msg;
    struct mydiv_return r;

    helloworld();

    x = 111;
    printf("square(%d) = %d\n", x, square(x));

    x = 123;
    y = 654;
    printf("add(%d, %d) = %d\n", x, y, myadd(x, y));

    name = "DARK STAR";
    msg = (char*)make_greet(name);
    printf("%s\n", msg);

    x = 1000;
    y = 17;
    r = mydiv(x, y);
    printf("%d / %d = %d ... %d\n", x, y, r.r0, r.r1);

    return 0;
}
