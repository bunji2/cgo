#ifndef MYDIV__H
#define MYDIV__H

typedef struct {
    int answer;
    int remainder;
} MyDiv;

MyDiv *mydiv(int, int);
int mydiv_answer(MyDiv *x);
int mydiv_remainder(MyDiv *x);
void mydiv_free(MyDiv *x);

#endif /* MYDIV__H */
