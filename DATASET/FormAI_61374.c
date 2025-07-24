//FormAI DATASET v1.0 Category: Error handling ; Style: cheerful
#include <stdio.h>

int main() {
    int num1, num2, result;
    printf("Let's add two numbers!\n");
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    if(num2 == 0) {
        printf("Oops! Division by zero is not possible. Please enter a non-zero value for the second number.\n");
        return 1;
    }

    result = num1/num2;

    printf("The sum of %d and %d is %d.", num1, num2, result);

    return 0;
}