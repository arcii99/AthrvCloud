//FormAI DATASET v1.0 Category: Arithmetic ; Style: portable
#include <stdio.h>

int main() {
    int num1, num2, sum, prod;
    float quotient;

    printf("Enter two integers (separated by a space): ");
    scanf("%d %d", &num1, &num2);

    sum = num1 + num2;
    prod = num1 * num2;

    if (num2 != 0) {
        quotient = (float)num1 / num2;
        printf("%d + %d = %d\n", num1, num2, sum);
        printf("%d * %d = %d\n", num1, num2, prod);
        printf("%d / %d = %.2f\n", num1, num2, quotient);
    } else {
        printf("Cannot divide by 0\n");
        printf("%d + %d = %d\n", num1, num2, sum);
        printf("%d * %d = %d\n", num1, num2, prod);
    }

    return 0;
}