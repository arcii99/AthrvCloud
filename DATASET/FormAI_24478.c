//FormAI DATASET v1.0 Category: Funny ; Style: portable
#include <stdio.h>

// define constants
#define PI 3.14159265359
#define E 2.71828182846

int main() {

    // variable declarations
    int num1 = 42;
    float num2 = 3.14;
    double num3 = 1.61803398875;

    // print variables
    printf("The answer to life is %d\n", num1);
    printf("Pi is approximately %.2f\n", num2);
    printf("The Golden Ratio is %.11f\n", num3);

    // print constants
    printf("Pi is defined as %.11f\n", PI);
    printf("e is defined as %.11f\n", E);

    // perform math operations
    float result = num1 * num2 / num3;
    printf("The result of the math operations is %.11f\n", result);

    // declare a pointer
    double *pointer;
    pointer = &num3;

    // print pointer value
    printf("The pointer value is %p\n", pointer);

    // print pointer dereference value
    printf("The pointer dereference value is %.11f\n", *pointer);

    // use ternary operator
    int x = 5;
    int y = 10;
    int max = (x > y) ? x : y;
    printf("The max value is %d\n", max);

    // use for loop
    for (int i = 0; i < 5; i++) {
        printf("The current value of i is %d\n", i);
    }

    return 0;
}