//FormAI DATASET v1.0 Category: Educational ; Style: Linus Torvalds
#include <stdio.h>

int main() {
    int num1, num2, sum, product;

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    sum = num1 + num2;
    product = num1 * num2;

    printf("The sum of %d and %d is %d.\n", num1, num2, sum);
    printf("The product of %d and %d is %d.\n", num1, num2, product);
    
    if (num1 == 0 || num2 == 0) {
        printf("Warning: Division by zero is undefined.\n");
    } else {
        printf("The division of %d by %d is %.2f.\n", num1, num2, (float)num1 / num2);
    }

    return 0;
}