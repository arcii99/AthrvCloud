//FormAI DATASET v1.0 Category: Math exercise ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int num1, num2, result;
    float num3, num4, res;
    char operator;
    
    printf("Enter first integer: ");
    scanf("%d", &num1);
    printf("Enter second integer: ");
    scanf("%d", &num2);
    
    printf("\nEnter operator (+,-,*,/): ");
    scanf(" %c", &operator);
   
    switch(operator)
    {
        case '+':
            result = num1 + num2;
            printf("\nAddition of %d and %d is: %d", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("\nSubtraction of %d and %d is: %d", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("\nMultiplication of %d and %d is: %d", num1, num2, result);
            break;
        case '/':
            if(num2 == 0){
                printf("\nDenominator cannot be zero. Please try again.");
                break;
            }
            res = (float) num1 / num2;
            printf("\nDivision of %d by %d is: %.2f", num1, num2, res);
            break;
        default:
            printf("\nInvalid operator entered. Please try again.");
            break;
    }
    
    printf("\n\nEnter a floating point number: ");
    scanf("%f", &num3);
    printf("Enter an integer value: ");
    scanf("%f", &num4);

    printf("\nAbsolute value of %f is %.2f", num3, fabs(num3));
    printf("\nSquare root of %f is %.2f", num3, sqrt(num3));
    printf("\n%f to the power of %d is %.2f", num3, (int)num4, pow(num3, (int)num4));

    return 0;
}