//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int choice, flag;
    float num1, num2, result;

    do
    {
        printf("\nWelcome to My Scientific Calculator\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Power\n6. Square Root\n7. Exponential\n8. Logarithmic\n9. Exit\n\n");
        printf("Please enter your choice (1-9): ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: //addition
                printf("\nEnter two numbers for addition: ");
                scanf("%f %f", &num1, &num2);
                result = num1 + num2;
                printf("Result: %f\n", result);
                break;

            case 2: //subtraction
                printf("\nEnter two numbers for subtraction: ");
                scanf("%f %f", &num1, &num2);
                result = num1 - num2;
                printf("Result: %f\n", result);
                break;

            case 3: //multiplication
                printf("\nEnter two numbers for multiplication: ");
                scanf("%f %f", &num1, &num2);
                result = num1 * num2;
                printf("Result: %f\n", result);
                break;

            case 4: //division
                printf("\nEnter two numbers for division: ");
                scanf("%f %f", &num1, &num2);
                if(num2 == 0)
                {
                    printf("Error! Division by zero.\n");
                    break;
                }
                result = num1 / num2;
                printf("Result: %f\n", result);
                break;

            case 5: //power
                printf("\nEnter a number and its power: ");
                scanf("%f %f", &num1, &num2);
                result = pow(num1, num2);
                printf("Result: %f\n", result);
                break;

            case 6: //square root
                printf("\nEnter a number: ");
                scanf("%f", &num1);
                if(num1 < 0)
                {
                    printf("Error! Cannot find square root of a negative number.\n");
                    break;
                }
                result = sqrt(num1);
                printf("Result: %f\n", result);
                break;

            case 7: //exponential
                printf("\nEnter a number: ");
                scanf("%f", &num1);
                result = exp(num1);
                printf("Result: %f\n", result);
                break;

            case 8: //logarithmic
                printf("\nEnter a number: ");
                scanf("%f", &num1);
                if(num1 <= 0)
                {
                    printf("Error! Cannot find logarithm of a non-positive number.\n");
                    break;
                }
                result = log(num1);
                printf("Result: %f\n", result);
                break;

            case 9: //exit
                printf("Thank you for using My Scientific Calculator!\n");
                flag = 1;
                break;

            default: //invalid choice
                printf("Invalid choice. Please enter a number between 1 and 9.\n");
                break;
        }

    } while(!flag);

    return 0;
}