#include <stdio.h>
#include <stdlib.h>
#include "mydiv.h"

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
    MyDiv* r;
    if (argc <3) {
        printf("Usage: %s arg1 arg2\n", argv[0]);
        return 1;
    }
    x = atoi(argv[1]);
    y = atoi(argv[2]);
    r = mydiv(x, y);
    printf("%d / %d = %d ... %d\n", x, y, mydiv_answer(r), mydiv_remainder(r));
    mydiv_free(r);
    return 0;
}
#endif /* USE_MAIN */
