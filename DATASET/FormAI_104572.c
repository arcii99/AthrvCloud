//FormAI DATASET v1.0 Category: Arithmetic ; Style: careful
#include <stdio.h>

int main() {
    int a, b;
    printf("Enter two integers to add\n");
    scanf("%d%d", &a, &b);

    int sum = a + b;
    printf("Sum of entered numbers = %d\n", sum);

    int tempa = a, tempb = b;
    while (tempa != tempb) {
        if (tempa > tempb)
            tempa = tempa - tempb;
        else
            tempb = tempb - tempa;
    }

    printf("GCD of %d and %d is %d\n", a, b, tempa);

    printf("Enter two integers to subtract\n");
    scanf("%d%d", &a, &b);

    int difference = a - b;
    printf("Difference of entered numbers = %d\n", difference);

    printf("Enter two integers to multiply\n");
    scanf("%d%d", &a, &b);

    int product = a * b;
    printf("Product of entered numbers = %d\n", product);

    printf("Enter two integers to divide\n");
    scanf("%d%d", &a, &b);

    float quotient = (float)a / b;
    printf("Quotient of entered numbers = %.2f\n", quotient);

    int remainder = a % b;
    printf("Remainder of entered numbers = %d\n", remainder);

    return 0;
}