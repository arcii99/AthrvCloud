//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: irregular
#include <stdio.h>
#include <math.h>

void main() // Entry point for the program
{
    int choice = 0;
    float num1, num2, result;

    printf("\n\n   < Scientific Calculator >\n\n");

    while (1) // Infinite loop until the user chooses to exit
    {
        // Display the Menu
        printf("   1. Addition\n");
        printf("   2. Subtraction\n");
        printf("   3. Multiplication\n");
        printf("   4. Division\n");
        printf("   5. Square Root\n");
        printf("   6. Power Function\n");
        printf("   7. Trigonometric Functions\n");
        printf("   8. Logarithmic Function\n");
        printf("   9. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice); // Read the user's choice

        switch (choice)
        {
            case 1:
                printf("\nEnter the 1st number : ");
                scanf("%f", &num1);
                printf("Enter the 2nd number : ");
                scanf("%f", &num2);
                result = num1 + num2;
                printf("\nResult : %f", result);
                break;

            case 2:
                printf("\nEnter the 1st number : ");
                scanf("%f", &num1);
                printf("Enter the 2nd number : ");
                scanf("%f", &num2);
                result = num1 - num2;
                printf("\nResult : %f", result);
                break;

            case 3:
                printf("\nEnter the 1st number : ");
                scanf("%f", &num1);
                printf("Enter the 2nd number : ");
                scanf("%f", &num2);
                result = num1 * num2;
                printf("\nResult : %f", result);
                break;

            case 4:
                printf("\nEnter the 1st number : ");
                scanf("%f", &num1);
                printf("Enter the 2nd number : ");
                scanf("%f", &num2);
                if(num2 != 0)
                {
                    result = num1 / num2;
                    printf("\nResult : %f", result);
                }
                else
                {
                    printf("\nMath Error: Division by zero!");
                }
                break;

            case 5:
                printf("\nEnter a number : ");
                scanf("%f", &num1);
                if(num1 >= 0)
                {
                    result = sqrt(num1);
                    printf("\nResult : %f", result);
                }
                else
                {
                    printf("\nMath Error: Square Root of a negative number!");
                }
                break;

            case 6:
                printf("\nEnter the base number : ");
                scanf("%f", &num1);
                printf("Enter the exponent : ");
                scanf("%f", &num2);
                result = pow(num1, num2);
                printf("\nResult : %f", result);
                break;

            case 7:
                printf("\nEnter an angle in degrees : ");
                scanf("%f", &num1);
                printf("\n");
                printf("   sin(%0.2f) = %0.4f\n", num1, sin(num1 * M_PI / 180));
                printf("   cos(%0.2f) = %0.4f\n", num1, cos(num1 * M_PI / 180));
                printf("   tan(%0.2f) = %0.4f\n", num1, tan(num1 * M_PI / 180));
                break;

            case 8:
                printf("\nEnter a number : ");
                scanf("%f", &num1);
                if(num1 > 0)
                {
                    printf("\n");
                    printf("   ln(%0.2f) = %0.4f\n", num1, log(num1));
                    printf("   log10(%0.2f) = %0.4f\n", num1, log10(num1));
                }
                else
                {
                    printf("\nMath Error: Logarithmic Function of a non-positive number!");
                }
                break;

            case 9:
                printf("\nThank you for using the Scientific Calculator!");
                exit(0); // Terminate the program

            default:
                printf("\nInvalid Choice, Please Try Again!");
        }

        printf("\n\n-----------------------\n");
    }
}