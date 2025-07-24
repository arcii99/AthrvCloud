//FormAI DATASET v1.0 Category: Arithmetic ; Style: relaxed
#include <stdio.h>

int main() {
    printf("Welcome to my arithmetic program!\n\n");
    
    int num1, num2, sum, difference, product;
    float quotient;
    
    printf("Enter the first number: ");
    scanf("%d", &num1);
    
    printf("Enter the second number: ");
    scanf("%d", &num2);
    
    sum = num1 + num2;
    difference = num1 - num2;
    product = num1 * num2;
    quotient = (float) num1 / num2;
    // We cast one of the integers to a float so the division returns a float
    
    printf("\nHere are the results:\n");
    printf("The sum of %d and %d is %d\n", num1, num2, sum);
    printf("The difference between %d and %d is %d\n", num1, num2, difference);
    printf("The product of %d and %d is %d\n", num1, num2, product);
    printf("The quotient of %d and %d is %.2f\n", num1, num2, quotient);
    // %.2f specifies that we want to print the float with two decimal places
    
    printf("\nThank you for using my program! Goodbye.\n");
    
    return 0;
}