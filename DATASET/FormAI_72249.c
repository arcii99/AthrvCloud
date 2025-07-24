//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int choice, i, j = 0;
    float num1, num2, result;

    printf("\n\n");
    printf("      /~~|   /~~|  ~~ /~~|  /~~|\\  \n");
    printf("     |     |     |    --|   |     \n");
    printf("      \\__/    \\__/  __/   \\__/   \n\n");
    printf(" Welcome to my Scientific Calculator!\n");

    do
    {
        printf("\n");
        printf(" 1. Addition\n");
        printf(" 2. Subtraction\n");
        printf(" 3. Multiplication\n");
        printf(" 4. Division\n");
        printf(" 5. Square Root\n");
        printf(" 6. Power\n");
        printf(" 7. Logarithm\n");
        printf(" 8. Trigonometric Functions\n");
        printf(" 9. Exit\n");

        printf("\n");
        printf(" Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\n Enter first number: ");
                scanf("%f", &num1);

                printf(" Enter second number: ");
                scanf("%f", &num2);

                result = num1 + num2;
                printf("\n The sum of %.2f and %.2f is: %.2f\n", num1, num2, result);
                break;

            case 2:
                printf("\n Enter first number: ");
                scanf("%f", &num1);

                printf(" Enter second number: ");
                scanf("%f", &num2);

                result = num1 - num2;
                printf("\n The difference of %.2f and %.2f is: %.2f\n", num1, num2, result);
                break;

            case 3:
                printf("\n Enter first number: ");
                scanf("%f", &num1);

                printf(" Enter second number: ");
                scanf("%f", &num2);

                result = num1 * num2;
                printf("\n The product of %.2f and %.2f is: %.2f\n", num1, num2, result);
                break;

            case 4:
                printf("\n Enter first number: ");
                scanf("%f", &num1);

                do
                {
                    printf(" Enter non-zero second number: ");
                    scanf("%f", &num2);

                    if (num2 == 0)
                    {
                        printf("\n Cannot divide by zero! Try again.\n");
                    }

                } while (num2 == 0);

                result = num1 / num2;
                printf("\n The quotient of %.2f and %.2f is: %.2f\n", num1, num2, result);
                break;

            case 5:
                printf("\n Enter a number: ");
                scanf("%f", &num1);

                if (num1 < 0)
                {
                    printf("\n Cannot find square root of negative numbers! Try again.\n");
                    break;
                }

                result = sqrt(num1);
                printf("\n The square root of %.2f is: %.2f\n", num1, result);
                break;

            case 6:
                printf("\n Enter base number: ");
                scanf("%f", &num1);

                printf(" Enter exponent: ");
                scanf("%f", &num2);

                result = pow(num1, num2);
                printf("\n %.2f to the power %.2f is: %.2f\n", num1, num2, result);
                break;

            case 7:
                printf("\n Enter a number: ");
                scanf("%f", &num1);

                if (num1 <= 0)
                {
                    printf("\n Cannot find logarithm of non-positive numbers! Try again.\n");
                    break;
                }

                result = log10(num1);
                printf("\n The logarithm (base 10) of %.2f is: %.2f\n", num1, result);
                break;

            case 8:
                printf("\n 1. Sine\n");
                printf(" 2. Cosine\n");
                printf(" 3. Tangent\n");
                printf(" 4. Inverse Sine\n");
                printf(" 5. Inverse Cosine\n");
                printf(" 6. Inverse Tangent\n");

                printf("\n");
                printf(" Enter your choice: ");
                scanf("%d", &i);

                switch (i)
                {
                    case 1:
                        printf("\n Enter angle in radians: ");
                        scanf("%f", &num1);

                        result = sin(num1);
                        printf("\n The sine of %.2f radians is: %.2f\n", num1, result);
                        break;

                    case 2:
                        printf("\n Enter angle in radians: ");
                        scanf("%f", &num1);

                        result = cos(num1);
                        printf("\n The cosine of %.2f radians is: %.2f\n", num1, result);
                        break;

                    case 3:
                        printf("\n Enter angle in radians: ");
                        scanf("%f", &num1);

                        result = tan(num1);
                        printf("\n The tangent of %.2f radians is: %.2f\n", num1, result);
                        break;

                    case 4:
                        printf("\n Enter value of sine: ");
                        scanf("%f", &num1);

                        if (num1 > 1 || num1 < -1)
                        {
                            printf("\n There is no angle with sine %.2f! Try again.\n", num1);
                            break;
                        }

                        result = asin(num1);
                        printf("\n The inverse sine (in radians) of %.2f is: %.2f\n", num1, result);
                        break;

                    case 5:
                        printf("\n Enter value of cosine: ");
                        scanf("%f", &num1);

                        if (num1 > 1 || num1 < -1)
                        {
                            printf("\n There is no angle with cosine %.2f! Try again.\n", num1);
                            break;
                        }

                        result = acos(num1);
                        printf("\n The inverse cosine (in radians) of %.2f is: %.2f\n", num1, result);
                        break;

                    case 6:
                        printf("\n Enter value of tangent: ");
                        scanf("%f", &num1);

                        result = atan(num1);
                        printf("\n The inverse tangent (in radians) of %.2f is: %.2f\n", num1, result);
                        break;

                    default:
                        printf("\n Invalid choice! Try again.\n");
                        break;
                }

                break;

            case 9:
                printf("\n Thanks for using my Scientific Calculator!\n\n");
                break;

            default:
                printf("\n Invalid choice! Try again.\n");
                break;
        }

    } while (choice != 9);

    return 0;
}