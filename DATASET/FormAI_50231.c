//FormAI DATASET v1.0 Category: Arithmetic ; Style: minimalist
#include <stdio.h>
#define MAX(a,b) (a > b ? a : b)

int main() {
    int a = 10;
    int b = 15;
    printf("The value of a is: %d\n", a);
    printf("The value of b is: %d\n", b);

    int sum = a + b;
    printf("The sum of a and b is: %d\n", sum);

    int diff = a - b;
    printf("The difference between a and b is: %d\n", diff);

    int prod = a * b;
    printf("The product of a and b is: %d\n", prod);

    double quo = (double)a / b;
    printf("The quotient of a and b is: %.3lf\n", quo);

    int max = MAX(a, b);
    printf("The larger number between a and b is: %d\n", max);

    int min = MAX(a, b) == a ? b : a;
    printf("The smaller number between a and b is: %d\n", min);

    int modulo = b % a;
    printf("The modulo of b by a is: %d\n", modulo);

    int neg_a = -a;
    printf("The negation of a is: %d\n", neg_a);

    int neg_b = -b;
    printf("The negation of b is: %d\n", neg_b);

    int inc_a = ++a;
    printf("The value of a after increment is: %d\n", inc_a);

    int dec_b = --b;
    printf("The value of b after decrement is: %d\n", dec_b);

    return 0;
}