#include <stdio.h>
#include "helloworld.h"

void greet(char *name) {
    printf("Hello, %s!", name);
}

#ifdef USE_MAIN
int main(int argc, char**argv) {
    if (argc <2) {
        printf("Usage: %s your_name\n", argv[0]);
        return 1;
    }
    greet(argv[1]);
    return 0;
}
#endif /* USE_MAIN */
