//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <math.h>

int main()
{
    int choice;
    float num1, num2, result;
    
    printf("\tKEN'S SCIENTIFIC CALCULATOR\n");
    printf("\n");
    printf("\t MENU \n");
    printf("\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Square root\n");
    printf("6. Exponential\n");
    printf("7. Logarithmic\n");
    printf("8. Trigonometric (sine, cosine, tangent)\n");
    printf("\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice){
        case 1:
            printf("\nEnter first number: ");
            scanf("%f", &num1);
            printf("Enter second number: ");
            scanf("%f", &num2);
            result = num1 + num2;
            printf("\nResult: %.2f", result);
            break;
        case 2:
            printf("\nEnter first number: ");
            scanf("%f", &num1);
            printf("Enter second number: ");
            scanf("%f", &num2);
            result = num1 - num2;
            printf("\nResult: %.2f", result);
            break;
        case 3:
            printf("\nEnter first number: ");
            scanf("%f", &num1);
            printf("Enter second number: ");
            scanf("%f", &num2);
            result = num1 * num2;
            printf("\nResult: %.2f", result);
            break;
        case 4:
            printf("\nEnter first number: ");
            scanf("%f", &num1);
            printf("Enter second number: ");
            scanf("%f", &num2);
            result = num1 / num2;
            printf("\nResult: %.2f", result);
            break;
        case 5:
            printf("\nEnter a number: ");
            scanf("%f", &num1);
            result = sqrt(num1);
            printf("\nResult: %.2f", result);
            break;
        case 6:
            printf("\nEnter a number: ");
            scanf("%f", &num1);
            result = exp(num1);
            printf("\nResult: %.2f", result);
            break;
        case 7:
            printf("\nEnter a number: ");
            scanf("%f", &num1);
            result = log(num1);
            printf("\nResult: %.2f", result);
            break;
        case 8:
            printf("\nEnter a number: ");
            scanf("%f", &num1);
            result = sin(num1);
            printf("\nSine: %.2f", result);
            result = cos(num1);
            printf("\nCosine: %.2f", result);
            result = tan(num1);
            printf("\nTangent: %.2f", result);
            break;
        default:
            printf("\nInvalid choice!");
    }
    
    return 0;
}