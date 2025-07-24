//FormAI DATASET v1.0 Category: Syntax parsing ; Style: artistic
#include <stdio.h>

int main() {
    /* Create variables */
    int num1, num2, sum;

    /* Prompt user for first number */
    printf("Enter the first number: ");
    scanf("%d", &num1);

    /* Prompt user for second number */
    printf("Enter the second number: ");
    scanf("%d", &num2);

    /* Calculate sum */
    sum = num1 + num2;

    /* Check if sum is even */
    if (sum % 2 == 0) {
        printf("The sum of %d and %d is even.\n", num1, num2);
    } else {
        printf("The sum of %d and %d is odd.\n", num1, num2);
    }

    return 0;
}