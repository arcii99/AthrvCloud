//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ADD '+'
#define SUB '-'
#define MUL '*'
#define DIV '/'
#define MOD '%'
#define POW '^'
#define SQRT 's'
#define ABS 'a'
#define EXIT 'q'

double get_num(){
    double n;
    scanf("%lf", &n);
    return n;
}

char get_op(){
    char op;
    scanf(" %c", &op);
    return op;
}

void calc(){
    double a, b;
    char op;

    while(1){
        printf("\nEnter an operation (+, -, *, /, %%, ^, s, a, q): ");
        op = get_op();

        switch(op){
            case ADD:
                a = get_num();
                b = get_num();
                printf("%lf\n", a+b);
                break;
            case SUB:
                a = get_num();
                b = get_num();
                printf("%lf\n", a-b);
                break;
            case MUL:
                a = get_num();
                b = get_num();
                printf("%lf\n", a*b);
                break;
            case DIV:
                a = get_num();
                b = get_num();
                if(b == 0){
                    printf("Cannot divide by zero\n");
                } else {
                    printf("%lf\n", a/b);
                }
                break;
            case MOD:
                a = get_num();
                b = get_num();
                printf("%d\n", (int)a%(int)b);
                break;
            case POW:
                a = get_num();
                b = get_num();
                printf("%lf\n", pow(a, b));
                break;
            case SQRT:
                a = get_num();
                printf("%lf\n", sqrt(a));
                break;
            case ABS:
                a = get_num();
                printf("%lf\n", fabs(a));
                break;
            case EXIT:
                return;
            default:
                printf("Invalid operation\n");
        }
    }
}

int main(){
    calc();
    return 0;
}