//FormAI DATASET v1.0 Category: Math exercise ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void add(int a, int b) {
    int result = a + b;
    printf("%d + %d = %d\n", a , b, result);
}

void subtract(int a, int b) {
    int result = a - b;
    printf("%d - %d = %d\n", a , b, result);
}

void multiply(int a, int b) {
    int result = a * b;
    printf("%d * %d = %d\n", a , b, result);
}

void divide(int a, int b) {
    if (b == 0){
        printf("Error: Cannot divide by zero\n");
    }
    else {
        float result = (float)a / (float)b;
        printf("%d / %d = %.2f\n", a , b, result);
    }
}

void mod(int a, int b) {
    if (b == 0) {
        printf("Error: Cannot divide by zero\n");
    }
    else {
        int result = a % b;
        printf("%d %% %d = %d\n", a , b, result);
    }
}

int main() {
    srand(time(NULL));

    int a = rand() % 100;
    int b = rand() % 100;

    printf("Randomly generated values: a = %d, b = %d\n\n", a, b);

    add(a, b);
    subtract(a, b);
    multiply(a, b);
    divide(a, b);
    mod(a, b);

    printf("\nCalculations complete.\n");

    return 0;
}