//FormAI DATASET v1.0 Category: Educational ; Style: unmistakable
#include <stdio.h>

int main() 
{
    int num1, num2, choice, result;
    
    // Taking user input for two numbers
    printf("Enter two numbers: ");
    scanf("%d%d", &num1, &num2);
    
    // Displaying menu options
    printf("\nMenu\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    // Performing selected operation
    switch(choice) {
        case 1: result = num1 + num2;
                printf("\nAddition of %d and %d is %d\n", num1, num2, result);
                break;
                
        case 2: result = num1 - num2;
                printf("\nSubtraction of %d from %d is %d\n", num2, num1, result);
                break;
                
        case 3: result = num1 * num2;
                printf("\nMultiplication of %d and %d is %d\n", num1, num2, result);
                break;
                
        case 4: if(num2 == 0) {
                    printf("\nDivide by zero error!\n");
                    break;
                }
                result = num1 / num2;
                printf("\nDivision of %d by %d is %d\n", num1, num2, result);
                break;
                
        default: printf("\nInvalid choice!\n");
    }
    
    return 0;
}