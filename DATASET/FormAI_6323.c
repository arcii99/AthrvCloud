//FormAI DATASET v1.0 Category: Arithmetic ; Style: single-threaded
#include <stdio.h>

int main() {
    int num1, num2, sum;
    
    printf("Enter the first number: ");
    scanf("%d", &num1);
    
    printf("Enter the second number: ");
    scanf("%d", &num2);
    
    sum = num1 + num2; // Add the two numbers
    
    printf("Sum of %d and %d is %d\n", num1, num2, sum);
    
    int diff = num1 - num2; // Subtract the two numbers
    
    printf("Difference of %d and %d is %d\n", num1, num2, diff);
    
    int prod = num1 * num2; // Multiply the two numbers
    
    printf("Product of %d and %d is %d\n", num1, num2, prod);
    
    float quotient = (float) num1 / num2; // Divide the two numbers
    
    printf("Quotient of %d and %d is %.2f\n", num1, num2, quotient);
    
    int rem = num1 % num2; // Find the remainder when num1 is divided by num2
    
    printf("Remainder when %d is divided by %d is %d\n", num1, num2, rem);
    
    int power = 1; 
    
    for (int i = 1; i <= num2; i++) {
        power *= num1; // Calculate num1 raised to the power of num2
    }
    
    printf("%d raised to the power of %d is %d\n", num1, num2, power);
    
    return 0;
}