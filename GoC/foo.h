#ifndef FOO__H
#define FOO__H

void helloworld();
int square(int x);
int add(int x, int y);
char* make_greet(char *x);
void free_greet(char *x);

typedef struct {
    int answer;
    int remainder;
} MyDiv;

MyDiv *mydiv(int, int);
int mydiv_answer(MyDiv *x);
int mydiv_remainder(MyDiv *x);
void mydiv_free(MyDiv *x);


#endif /* FOO__H */
