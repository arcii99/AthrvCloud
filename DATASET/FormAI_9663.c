//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: satisfied
#include<stdio.h>
#include<math.h>

int main()
{
    int option, num1, num2, result;
    float fnum1, fnum2, fresult;
    
    printf("\n********** SCIENTIFIC CALCULATOR **********\n\n");
    
    printf("Select an operation to perform:\n\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Square Root\n");
    printf("7. Sine\n");
    printf("8. Cosine\n");
    printf("9. Tangent\n");
    printf("10. Logarithm\n\n");
    
    printf("Enter your choice: ");
    scanf("%d", &option);
    
    switch(option)
    {
        case 1: // Addition
            
            printf("\nEnter first number: ");
            scanf("%d", &num1);
            
            printf("Enter second number: ");
            scanf("%d", &num2);
            
            result = num1 + num2;
            
            printf("\n%d + %d = %d\n\n", num1, num2, result);
            
            break;
            
        case 2: // Subtraction
            
            printf("\nEnter first number: ");
            scanf("%d", &num1);
            
            printf("Enter second number: ");
            scanf("%d", &num2);
            
            result = num1 - num2;
            
            printf("\n%d - %d = %d\n\n", num1, num2, result);
            
            break;
            
        case 3: // Multiplication
            
            printf("\nEnter first number: ");
            scanf("%d", &num1);
            
            printf("Enter second number: ");
            scanf("%d", &num2);
            
            result = num1 * num2;
            
            printf("\n%d * %d = %d\n\n", num1, num2, result);
            
            break;
            
        case 4: // Division
            
            printf("\nEnter first number: ");
            scanf("%d", &num1);
            
            printf("Enter second number: ");
            scanf("%d", &num2);
            
            if(num2 == 0)
            {
                printf("\nError: Division by zero.\n\n");
            }
            
            else
            {
                fresult = (float)num1 / num2;
                
                printf("\n%d / %d = %.2f\n\n", num1, num2, fresult);
            }
            
            break;
            
        case 5: // Power
            
            printf("\nEnter base number: ");
            scanf("%f", &fnum1);
            
            printf("Enter exponent: ");
            scanf("%f", &fnum2);
            
            fresult = pow(fnum1, fnum2);
            
            printf("\n%.2f ^ %.2f = %.2f\n\n", fnum1, fnum2, fresult);
            
            break;
            
        case 6: // Square Root
            
            printf("\nEnter a number: ");
            scanf("%f", &fnum1);
            
            if(fnum1 < 0)
            {
                printf("\nError: Square root of negative number.\n\n");
            }
            
            else
            {
                fresult = sqrt(fnum1);
                
                printf("\nSquare root of %.2f = %.2f\n\n", fnum1, fresult);
            }
            
            break;
            
        case 7: // Sine
            
            printf("\nEnter angle in degrees: ");
            scanf("%f", &fnum1);
            
            fresult = sin(fnum1*M_PI/180);
            
            printf("\nSine of %.2f degrees = %.2f\n\n", fnum1, fresult);
            
            break;
            
        case 8: // Cosine
            
            printf("\nEnter angle in degrees: ");
            scanf("%f", &fnum1);
            
            fresult = cos(fnum1*M_PI/180);
            
            printf("\nCosine of %.2f degrees = %.2f\n\n", fnum1, fresult);
            
            break;
            
        case 9: // Tangent
            
            printf("\nEnter angle in degrees: ");
            scanf("%f", &fnum1);
            
            fresult = tan(fnum1*M_PI/180);
            
            printf("\nTangent of %.2f degrees = %.2f\n\n", fnum1, fresult);
            
            break;
            
        case 10: // Logarithm
            
            printf("\nEnter a number: ");
            scanf("%f", &fnum1);
            
            if(fnum1 <= 0)
            {
                printf("\nError: Invalid input.\n\n");
            }
            
            else
            {
                fresult = log10(fnum1);
                
                printf("\nLogarithm of %.2f = %.2f\n\n", fnum1, fresult);
            }
            
            break;
            
        default: // Invalid option
            
            printf("\nError: Invalid option.\n\n");
            
            break;
    }
    
    return 0;
}