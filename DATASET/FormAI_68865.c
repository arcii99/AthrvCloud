//FormAI DATASET v1.0 Category: Arithmetic ; Style: peaceful
#include <stdio.h>

int main() {
    int num1, num2;
    printf("Please enter two numbers for addition:\n");
    scanf("%d%d", &num1, &num2);
    int sum = num1 + num2;

    printf("\nAdding %d and %d results in %d\n\n", num1, num2, sum);

    printf("Please enter two numbers for subtraction:\n");
    scanf("%d%d", &num1, &num2);
    int diff = num1 - num2;

    printf("\nSubtracting %d from %d results in %d\n\n", num2, num1, diff);

    printf("Please enter two numbers for multiplication:\n");
    scanf("%d%d", &num1, &num2);
    int product = num1 * num2;

    printf("\nMultiplying %d by %d results in %d\n\n", num1, num2, product);

    printf("Please enter two numbers for division:\n");
    scanf("%d%d", &num1, &num2);
    int quotient = num1 / num2;

    printf("\nDividing %d by %d results in %d\n\n", num1, num2, quotient);

    return 0;
}