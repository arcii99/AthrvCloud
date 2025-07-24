//FormAI DATASET v1.0 Category: Math exercise ; Style: multi-threaded
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

struct Calculation {
    int num1;
    int num2;
    char op;
};

void* add(void* arg) {
    struct Calculation calc = *(struct Calculation*)arg;
    int result = calc.num1 + calc.num2;
    printf("%d %c %d = %d\n", calc.num1, calc.op, calc.num2, result);
    pthread_exit(NULL);
}

void* subtract(void* arg) {
    struct Calculation calc = *(struct Calculation*)arg;
    int result = calc.num1 - calc.num2;
    printf("%d %c %d = %d\n", calc.num1, calc.op, calc.num2, result);
    pthread_exit(NULL);
}

void* multiply(void* arg) {
    struct Calculation calc = *(struct Calculation*)arg;
    int result = calc.num1 * calc.num2;
    printf("%d %c %d = %d\n", calc.num1, calc.op, calc.num2, result);
    pthread_exit(NULL);
}

void* divide(void* arg) {
    struct Calculation calc = *(struct Calculation*)arg;
    if (calc.num2 == 0) {
        printf("Error: Division by zero\n");
    } else {
        int result = calc.num1 / calc.num2;
        printf("%d %c %d = %d\n", calc.num1, calc.op, calc.num2, result);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread[4];
    struct Calculation calc;
    calc.num1 = 10;
    calc.num2 = 5;
    calc.op = '+';
    pthread_create(&thread[0], NULL, add, (void*)&calc);
    pthread_create(&thread[1], NULL, subtract, (void*)&calc);
    pthread_create(&thread[2], NULL, multiply, (void*)&calc);
    pthread_create(&thread[3], NULL, divide, (void*)&calc);
    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);
    pthread_join(thread[2], NULL);
    pthread_join(thread[3], NULL);
    return 0;
}