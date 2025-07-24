//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    int selection=0, x=0, y=0;
    double result=0.0, angle=0.0, value=0.0;
    
    printf("\nWelcome to Puzzling Scientific Calculator!\n");
    printf("=========================================\n\n");
    
    while(selection!=10) {
    
        printf("Select an operation (1-10):\n");
        printf("----------------------------\n");
        printf("[1] Addition\n[2] Subtraction\n[3] Multiplication\n[4] Division\n");
        printf("[5] Exponential\n[6] Square Root\n[7] Absolute Value\n[8] Sine\n");
        printf("[9] Cosine\n[10] Exit\n\n");
        
        printf("Enter selection: ");
        scanf("%d", &selection);
        
        switch(selection) {
        
            case 1:
                printf("\nAddition selected.\n");
                printf("Enter the values to be added separated by a space: ");
                scanf("%d %d", &x, &y);
                result = x + y;
                printf("\n%d + %d = %0.2lf\n\n", x, y, result);
                break;
                
            case 2:
                printf("\nSubtraction selected.\n");
                printf("Enter the values to be subtracted separated by a space: ");
                scanf("%d %d", &x, &y);
                result = x - y;
                printf("\n%d - %d = %0.2lf\n\n", x, y, result);
                break;
                
            case 3:
                printf("\nMultiplication selected.\n");
                printf("Enter the values to be multiplied separated by a space: ");
                scanf("%d %d", &x, &y);
                result = x * y;
                printf("\n%d x %d = %0.2lf\n\n", x, y, result);
                break;
                
            case 4:
                printf("\nDivision selected.\n");
                printf("Enter the values to be divided separated by a space: ");
                scanf("%d %d", &x, &y);
                if(y==0) {
                    printf("\nSorry, division by zero is undefined.\n\n");
                    break;
                }
                result = (double) x / y;
                printf("\n%d / %d = %0.2lf\n\n", x, y, result);
                break;
                
            case 5:
                printf("\nExponential selected.\n");
                printf("Enter the base value: ");
                scanf("%lf", &value);
                printf("Enter the exponent value: ");
                scanf("%lf", &angle);
                result = pow(value, angle);
                printf("\n%0.2lf raised to the power of %0.2lf = %0.2lf\n\n", value, angle, result);
                break;
                
            case 6:
                printf("\nSquare Root selected.\n");
                printf("Enter the value to be square rooted: ");
                scanf("%lf", &value);
                if(value<0) {
                    printf("\nSorry, square root of a negative value is undefined.\n\n");
                    break;
                }
                result = sqrt(value);
                printf("\nThe square root of %0.2lf = %0.2lf\n\n", value, result);
                break;
                
            case 7:
                printf("\nAbsolute Value selected.\n");
                printf("Enter the value to find its absolute value: ");
                scanf("%lf", &value);
                result = fabs(value);
                printf("\nThe absolute value of %0.2lf = %0.2lf\n\n", value, result);
                break;
                
            case 8:
                printf("\nSine selected.\n");
                printf("Enter the angle in degrees: ");
                scanf("%lf", &angle);
                angle = angle * (22.0/7.0) / 180.0;
                result = sin(angle);
                printf("\nThe sine of %0.2lf degrees = %0.2lf\n\n", angle, result);
                break;
                
            case 9:
                printf("\nCosine selected.\n");
                printf("Enter the angle in degrees: ");
                scanf("%lf", &angle);
                angle = angle * (22.0/7.0) / 180.0;
                result = cos(angle);
                printf("\nThe cosine of %0.2lf degrees = %0.2lf\n\n", angle, result);
                break;
                
            case 10:
                printf("\nExiting Puzzling Scientific Calculator. Goodbye!\n");
                break;
                
            default:
                printf("\nInvalid selection. Try again.\n\n");
                break;
        }
    }
    
    return 0;
}