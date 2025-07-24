//FormAI DATASET v1.0 Category: Math exercise ; Style: Romeo and Juliet
#include <stdio.h>

int main()
{
    float num1, num2;
    
    printf("Enter the first number: ");
    scanf("%f", &num1);
    
    printf("Enter the second number: ");
    scanf("%f", &num2);
    
    printf("Addition: %.2f\n", num1 + num2);
    
    printf("Subtraction: %.2f\n", num1 - num2);
    
    printf("Multiplication: %.2f\n", num1 * num2);
    
    if(num2 != 0)
    {
        printf("Division: %.2f\n", num1 / num2);
    }
    else
    {
        printf("Cannot divide by zero.\n");
    }
    
    return 0;
}