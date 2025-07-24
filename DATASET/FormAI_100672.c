//FormAI DATASET v1.0 Category: Arithmetic ; Style: calm
#include <stdio.h>

int main() {
    int num1, num2, sum, diff, prod;
    float quotient;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    
    sum = num1 + num2;
    diff = num1 - num2;
    prod = num1 * num2;
    if (num2 != 0) {
        quotient = (float)num1 / num2;
        printf("The quotient of %d and %d is %.2f\n", num1, num2, quotient);
    } else {
        printf("Cannot divide by zero\n");
    }
    printf("The sum of %d and %d is %d\n", num1, num2, sum);
    printf("The difference of %d and %d is %d\n", num1, num2, diff);
    printf("The product of %d and %d is %d\n", num1, num2, prod);

    return 0;
}