//FormAI DATASET v1.0 Category: Arithmetic ; Style: lively
#include <stdio.h>

int main() {
    int num1, num2, sum, difference, product, quotient, remainder;
    
    printf("Welcome to the magical arithmetic world!\n");
    printf("Enter two numbers and watch the magic happen...\n");
    
    printf("Enter the first number: ");
    scanf("%d", &num1);
    
    printf("Enter the second number: ");
    scanf("%d", &num2);
    
    sum = num1 + num2;
    difference = num1 - num2;
    product = num1 * num2;
    quotient = num1 / num2;
    remainder = num1 % num2;
    
    printf("\nBehold, the magic results:\n");
    
    printf("%d + %d = %d\n", num1, num2, sum);
    printf("%d - %d = %d\n", num1, num2, difference);
    printf("%d * %d = %d\n", num1, num2, product);
    
    if (num2 == 0) {
        printf("Oops, cannot perform division. The second number is zero!\n");
    } else {
        quotient = num1 / num2;
        remainder = num1 % num2;
        printf("%d / %d = %d (with a remainder of %d)\n", num1, num2, quotient, remainder);
    }
    
    printf("Thank you for witnessing the magic! Goodbye!\n");
    
    return 0;
}