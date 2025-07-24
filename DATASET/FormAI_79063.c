//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: curious
#include <stdio.h>
#include <math.h>

int main() {
    
    printf("*** Welcome to the Curious Calculator! ***\n\n");
    printf("Please enter the first number: ");
    double num1;
    scanf("%lf", &num1);
    
    printf("Please enter the second number: ");
    double num2;
    scanf("%lf", &num2);
    
    printf("\nGreat! Which operation would you like to perform?\n\t1. Addition (+)\n\t2. Subtraction (-)\n\t3. Multiplication (*)\n\t4. Division (/)\n\t5. Power (^)\n\t6. Square Root (√)\n\nPlease enter the operation number: ");
    
    int operation;
    scanf("%d", &operation);
    
    double result;
    
    switch(operation) {
        case 1:
            result = num1 + num2;
            printf("\n\n%lf + %lf = %lf\n", num1, num2, result);
            break;
        case 2:
            result = num1 - num2;
            printf("\n\n%lf - %lf = %lf\n", num1, num2, result);
            break;
        case 3:
            result = num1 * num2;
            printf("\n\n%lf * %lf = %lf\n", num1, num2, result);
            break;
        case 4:
            if(num2 == 0) {
                printf("\n\nError: Cannot divide by zero\n");
            } else {
                result = num1 / num2;
                printf("\n\n%lf / %lf = %lf\n", num1, num2, result);
            }
            break;
        case 5:
            result = pow(num1, num2);
            printf("\n\n%lf ^ %lf = %lf\n", num1, num2, result);
            break;
        case 6: 
            if(num1 < 0) {
                printf("\n\nError: Square root of a negative number is undefined\n");
            } else {
                result = sqrt(num1);
                printf("\n\nSquare root of %lf is %lf\n", num1, result);
            }
            break;
        default:
            printf("\n\nError: Invalid operation number\n");
            break;
    }
    
    printf("\n\nThank you for using the Curious Calculator!");
    
    return 0;
}