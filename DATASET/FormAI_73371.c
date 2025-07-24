//FormAI DATASET v1.0 Category: Math exercise ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2;
    float result;
    
    printf("Welcome to the Math Exercise Generator!");
    printf("\n\n");
    
    printf("Enter the first number: ");
    scanf("%d", &num1);
    
    printf("Enter the second number: ");
    scanf("%d", &num2);
    
    printf("\n");
    
    // Addition
    printf("Addition: ");
    result = num1 + num2;
    printf("%d + %d = %.2f", num1, num2, result);
    printf("\n\n");
    
    // Subtraction
    printf("Subtraction: ");
    result = num1 - num2;
    printf("%d - %d = %.2f", num1, num2, result);
    printf("\n\n");
    
    // Multiplication
    printf("Multiplication: ");
    result = num1 * num2;
    printf("%d * %d = %.2f", num1, num2, result);
    printf("\n\n");
    
    // Division
    printf("Division: ");
    if(num2 == 0) {
        printf("ERROR! Cannot divide by zero.");
        exit(0);
    }
    result = (float)num1 / num2;
    printf("%d / %d = %.2f", num1, num2, result);
    printf("\n\n");
    
    // Modulus
    printf("Modulus: ");
    result = num1 % num2;
    printf("%d %% %d = %.2f", num1, num2, result);
    printf("\n\n");
    
    // Power
    printf("Power: ");
    result = pow(num1, num2);
    printf("%d ^ %d = %.2f", num1, num2, result);
    printf("\n\n");
    
    printf("Thanks for using the Math Exercise Generator!");
    
    return 0;
}