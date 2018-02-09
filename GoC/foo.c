/*
 * gcc -DUSE_MAIN foo.c -o foo.exe
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "foo.h"

/*
 * void -> void
 */
void helloworld() {
    printf("Hello, world.\n");
}

/*
 * int -> int
 */
int square(int x) {
    return x*x;
}

/*
 * (int, int) -> int
 */
int add(int x, int y) {
    return x+y;
}

/*
 * string -> string
 */
char* make_greet(char *x) {
    char *r = (char*)malloc(10+strlen(x));
    sprintf(r, "Hello, %s!", x);
    return r;
}

void free_greet(char *x) {
    free(x);
}

/*
 * (int,int) -> (int, int)
 */
MyDiv* mydiv(int x, int y) {
    MyDiv *r = (MyDiv*)malloc(sizeof(MyDiv));
    r->answer = x/y;
    r->remainder = x%y;
    return r;
}

int mydiv_answer(MyDiv* x) {
    return x->answer;
}

int mydiv_remainder(MyDiv* x) {
    return x->remainder;
}

void mydiv_free(MyDiv *x) {
    free(x);
}

#ifdef USE_MAIN
int main(int argc, char**argv) {
    int x, y;
    char *name, *msg;
    MyDiv* r;

    helloworld();

    x = 111;
    printf("square(%d) = %d\n", x, square(x));

    x = 123;
    y = 654;
    printf("add(%d, %d) = %d\n", x, y, add(x, y));

    name = "DARK STAR";
    msg = make_greet(name);
    printf("%s\n", msg);
    free_greet(msg);

    x = 1000;
    y = 17;
    r = mydiv(x, y);
    printf("%d / %d = %d ... %d\n", x, y, mydiv_answer(r),
      mydiv_remainder(r));
    mydiv_free(r);
    return 0;
}
#endif /* USE_MAIN */
