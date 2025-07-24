//FormAI DATASET v1.0 Category: Arithmetic ; Style: single-threaded
#include <stdio.h>

int main()
{
    int a = 10, b = 3;
    float c = 4.5;
    printf("a = %d, b = %d, c = %f\n", a, b, c);
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n", a / b);
    printf("c + b = %f\n", c + b);
    printf("c - b = %f\n", c - b);
    printf("c * b = %f\n", c * b);
    printf("c / b = %f\n", c / b);
    int result = a % b;
    printf("a %% b = %d\n", result);
    result += 5;
    printf("result += 5 = %d\n", result);
    result -= 2;
    printf("result -= 2 = %d\n", result);
    result *= 3;
    printf("result *= 3 = %d\n", result);
    float result_float = c / a;
    printf("c / a = %f\n", result_float);
    result_float += 2.5;
    printf("result_float += 2.5 = %f\n", result_float);
    result_float -= 1.3;
    printf("result_float -= 1.3 = %f\n", result_float);
    result_float *= 2.2;
    printf("result_float *= 2.2 = %f\n", result_float);
    if (a > b) {
        printf("a is greater than b\n");
    } else {
        printf("b is greater than a\n");
    }
    if (c >= b) {
        printf("c is greater than or equal to b\n");
    } else {
        printf("c is less than b\n");
    }
    if (a == b) {
        printf("a is equal to b\n");
    } else {
        printf("a is not equal to b\n");
    }
    return 0;
}