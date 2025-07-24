//FormAI DATASET v1.0 Category: Calculator ; Style: content
#include <stdio.h>
#include <math.h>

int main(){

    int num1, num2, operator;
    
    printf("Welcome to the Calculator program! \nEnter the first number: ");
    scanf("%d", &num1);
    
    printf("Enter the second number: ");
    scanf("%d", &num2);
    
    printf("\nChoose an Operator: \n[1] + \n[2] - \n[3] * \n[4] / \n[5] ^\n[6] %% (modulus) \n[7] sqrt \n\nEnter your choice: ");
    scanf("%d", &operator);
    
    switch(operator){
    
        case 1: // Addition
            printf("\nResult: %d + %d = %d", num1, num2, num1+num2);
            break;
            
        case 2: // Subtraction
            printf("\nResult: %d - %d = %d", num1, num2, num1-num2);
            break;
            
        case 3: // Multiplication
            printf("\nResult: %d * %d = %d", num1, num2, num1*num2);
            break;
            
        case 4: // Division
            if(num2 == 0){
                printf("\nError! Division by zero not allowed.");
            }
            else{
                printf("\nResult: %d / %d = %.2f", num1, num2, (float)num1/num2);
            }
            break;
            
        case 5: // Exponent
            printf("\nResult: %d ^ %d = %.2f", num1, num2, pow(num1, num2));
            break;
            
        case 6: // Modulus
            if(num2 == 0){
                printf("\nError! Division by zero not allowed.");
            }
            else{
                printf("\nResult: %d %% %d = %d", num1, num2, num1%num2);
            }
            break;
            
        case 7: // Square Root
            if(num1 < 0){
                printf("\nError! Square root of negative numbers not allowed.");
            }
            else{
                printf("\nResult: sqrt(%d) = %f", num1, sqrt(num1));
            }
            break;
            
        default:
            printf("\nInvalid input!");
            break;
    }
    
    printf("\n\nThank you for using the Calculator Program!\n");
    
    return 0;
}