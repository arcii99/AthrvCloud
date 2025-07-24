//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    int choice;
    double num1, num2, result;
    printf("Welcome to the Energetic Scientific Calculator!\n");
    while(1) {
        printf("\nChoose the operation you want to perform:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Square Root\n");
        printf("6. Power Function\n");
        printf("7. Log Function\n");
        printf("8. Exit\n");
        printf("\nEnter your choice (1-8): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter two numbers to add:\n");
                scanf("%lf %lf", &num1, &num2);
                result = num1 + num2;
                printf("\nResult: %lf\n", result);
                break;
            case 2:
                printf("\nEnter two numbers to subtract:\n");
                scanf("%lf %lf", &num1, &num2);
                result = num1 - num2;
                printf("\nResult: %lf\n", result);
                break;
            case 3:
                printf("\nEnter two numbers to multiply:\n");
                scanf("%lf %lf", &num1, &num2);
                result = num1 * num2;
                printf("\nResult: %lf\n", result);
                break;
            case 4:
                printf("\nEnter two numbers to divide:\n");
                scanf("%lf %lf", &num1, &num2);
                if(num2 == 0) {
                    printf("\nCannot divide by zero!\n");
                } else {
                    result = num1 / num2;
                    printf("\nResult: %lf\n", result);
                }
                break;
            case 5:
                printf("\nEnter a number to find the square root:\n");
                scanf("%lf", &num1);
                if(num1 < 0) {
                    printf("\nCannot find square root of a negative number!\n");
                } else {
                    result = sqrt(num1);
                    printf("\nResult: %lf\n", result);
                }
                break;
            case 6:
                printf("\nEnter two numbers to find the power:\n");
                scanf("%lf %lf", &num1, &num2);
                result = pow(num1, num2);
                printf("\nResult: %lf\n", result);
                break;
            case 7:
                printf("\nEnter a number to find the logarithm:\n");
                scanf("%lf", &num1);
                if(num1 <= 0) {
                    printf("\nCannot find log of a non-positive number!\n");
                } else {
                    result = log(num1);
                    printf("\nResult: %lf\n", result);
                }
                break;
            case 8:
                printf("\nThank you for using the Energetic Scientific Calculator!\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice! Please enter a number between 1-8.\n");
        }
    }

    return 0;
}