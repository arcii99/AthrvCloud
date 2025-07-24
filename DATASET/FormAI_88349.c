//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    double num1;
    double num2;
    char operator;
} equation;

double performCalculation(double num1, double num2, char operator) {
    switch(operator) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        default:
            printf("Invalid operator!\n");
            return 0;
    }
}

void* calculatorThread(void* arg) {
    equation* eq = (equation*) arg;
    double result = performCalculation(eq->num1, eq->num2, eq->operator);
    printf("%.2f %c %.2f = %.2f\n", eq->num1, eq->operator, eq->num2, result);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[3];
    equation eq1 = {5.6, 2.3, '+'};
    equation eq2 = {9.1, 3.7, '-'};
    equation eq3 = {10.2, 2.0, '*'};

    pthread_create(&threads[0], NULL, calculatorThread, (void*) &eq1);
    pthread_create(&threads[1], NULL, calculatorThread, (void*) &eq2);
    pthread_create(&threads[2], NULL, calculatorThread, (void*) &eq3);

    for(int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}