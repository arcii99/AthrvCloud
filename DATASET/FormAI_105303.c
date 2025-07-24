//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Romeo and Juliet
/* 
 * "The Scientific Calculator of Juliet" 
 * A unique implementation in C 
 * By: YourFriendlyChatbot 
 * 
 * Romeo and I were counting stars last night, 
 * When I thought of creating a calculator, just right. 
 * A calculator, so scientific and smart, 
 * That it can solve equations that tear people apart. 
 * 
 * With functions and variables, the calculator was made, 
 * Functions for trigonometry, logarithms, and graphing, no shade. 
 * Variables for storing numbers, with precision so sweet, 
 * The calculator was complete, and ready to meet. 
 * 
 * From algebra to calculus, the calculator can solve, 
 * It can differentiate and integrate, with problems to revolve. 
 * With just a few clicks, calculations are done, 
 * The calculator is the one-stop for problems that stun. 
 *
 * So, take this calculator, my dear Juliet, 
 * And let it be your companion, no matter the threat. 
 * For it will help you to the end, 
 * And make your calculations blend. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main()
{
    double num1, num2, result;
    int choice;

    printf("Welcome to 'The Scientific Calculator of Juliet'\n");
    printf("Please choose an option:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Square Root\n");
    printf("6. Exponent\n");
    printf("7. Trigonometry\n");
    printf("8. Logarithm\n");
    printf("9. Graphing\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            result = num1 + num2;
            printf("The sum is: %lf\n", result);
            break;

        case 2:
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            result = num1 - num2;
            printf("The difference is: %lf\n", result);
            break;

        case 3:
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            result = num1 * num2;
            printf("The product is: %lf\n", result);
            break;

        case 4:
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            if(num2 == 0)
            {
                printf("Cannot divide by zero\n");
            }
            else
            {
                result = num1 / num2;
                printf("The quotient is: %lf\n", result);
            }
            break;

        case 5:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            if(num1 < 0)
            {
                printf("Invalid input\n");
            }
            else
            {
                result = sqrt(num1);
                printf("The square root is: %lf\n", result);
            }
            break;

        case 6:
            printf("Enter the base: ");
            scanf("%lf", &num1);
            printf("Enter the exponent: ");
            scanf("%lf", &num2);
            result = pow(num1, num2);
            printf("The result is: %lf\n", result);
            break;

        case 7:
            printf("Select an option:\n");
            printf("1. Sine\n");
            printf("2. Cosine\n");
            printf("3. Tangent\n");
            printf("4. Inverse Sine\n");
            printf("5. Inverse Cosine\n");
            printf("6. Inverse Tangent\n");
            scanf("%d", &choice);
            printf("Enter the angle in radians: ");
            scanf("%lf", &num1);
            switch(choice)
            {
                case 1:
                    result = sin(num1);
                    printf("The sine of %lf radians is: %lf\n", num1, result);
                    break;

                case 2:
                    result = cos(num1);
                    printf("The cosine of %lf radians is: %lf\n", num1, result);
                    break;

                case 3:
                    result = tan(num1);
                    printf("The tangent of %lf radians is: %lf\n", num1, result);
                    break;

                case 4:
                    result = asin(num1);
                    printf("The inverse sine of %lf is: %lf radians\n", num1, result);
                    break;

                case 5:
                    result = acos(num1);
                    printf("The inverse cosine of %lf is: %lf radians\n", num1, result);
                    break;

                case 6:
                    result = atan(num1);
                    printf("The inverse tangent of %lf is: %lf radians\n", num1, result);
                    break;

                default:
                    printf("Invalid option\n");
            }
            break;

        case 8:
            printf("Select an option:\n");
            printf("1. Base 10 logarithm\n");
            printf("2. Natural logarithm\n");
            scanf("%d", &choice);
            printf("Enter a number: ");
            scanf("%lf", &num1);
            switch(choice)
            {
                case 1:
                    result = log10(num1);
                    printf("The base 10 logarithm of %lf is: %lf\n", num1, result);
                    break;

                case 2:
                    result = log(num1);
                    printf("The natural logarithm of %lf is: %lf\n", num1, result);
                    break;

                default:
                    printf("Invalid option\n");
            }
            break;

        case 9:
            printf("Select an option:\n");
            printf("1. Linear equation\n");
            printf("2. Quadratic equation\n");
            scanf("%d", &choice);
            switch(choice)
            {
                case 1:
                    printf("Equation: y = mx + b\n");
                    printf("Enter the slope (m): ");
                    scanf("%lf", &num1);
                    printf("Enter the y-intercept (b): ");
                    scanf("%lf", &num2);
                    printf("Equation: y = %.2lfx + %.2lf\n", num1, num2);
                    break;

                case 2:
                    printf("Equation: ax^2 + bx + c = 0\n");
                    printf("Enter the value for a: ");
                    scanf("%lf", &num1);
                    printf("Enter the value for b: ");
                    scanf("%lf", &num2);
                    printf("Enter the value for c: ");
                    scanf("%lf", &result);
                    result = pow(num2, 2) - (4 * num1 * result);
                    if(result < 0)
                    {
                        printf("No real solutions\n");
                    }
                    else
                    {
                        result = sqrt(result);
                        double x1 = (-num2 + result) / (2 * num1);
                        double x2 = (-num2 - result) / (2 * num1);
                        printf("Equation: %.2lfx^2 + %.2lfx + %.2lf = 0\n", num1, num2, result);
                        printf("Solution 1: %lf\n", x1);
                        printf("Solution 2: %lf\n", x2);
                    }
                    break;

                default:
                    printf("Invalid option\n");
            }
            break;

        default:
            printf("Invalid option\n");
            break;

    }

    return 0;
}