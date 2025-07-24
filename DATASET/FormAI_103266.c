//FormAI DATASET v1.0 Category: Arithmetic ; Style: minimalist
#include <stdio.h>

int main() {
    int a = 10, b = 20;
    float pi = 3.14159;
    int sum = a + b;
    float c = a / pi;
    int diff = b - a;
    float product = a * pi;
    float quotient = b / pi;

    printf("The sum of %d and %d is %d\n", a, b, sum);
    printf("%d divided by %f is %f\n", a, pi, c);
    printf("The difference between %d and %d is %d\n", b, a, diff);
    printf("%f times %d is %f\n", pi, a, product);
    printf("%d divided by %f is %f\n", b, pi, quotient);

    return 0;
}