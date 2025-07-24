//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {

    int choice;
    double num1, num2, result;

    printf("Welcome to the Scientific Calculator program.\n\n");

    printf("Please select an operation:\n");
    printf("[1] Addition\n");
    printf("[2] Subtraction\n");
    printf("[3] Multiplication\n");
    printf("[4] Division\n");
    printf("[5] Modulus\n");
    printf("[6] Square root\n");
    printf("[7] Exponential\n");
    printf("[8] Natural logarithm\n");
    printf("[9] Power\n");
    printf("[10] Trigonometric functions\n\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {

        case 1:
            printf("\nEnter two numbers to add: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 + num2;
            printf("The sum of %.2lf and %.2lf is: %.2lf\n", num1, num2, result);
            break;

        case 2:
            printf("\nEnter two numbers to subtract: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 - num2;
            printf("The difference of %.2lf and %.2lf is: %.2lf\n", num1, num2, result);
            break;

        case 3:
            printf("\nEnter two numbers to multiply: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 * num2;
            printf("The product of %.2lf and %.2lf is: %.2lf\n", num1, num2, result);
            break;

        case 4:
            printf("\nEnter two numbers to divide: ");
            scanf("%lf %lf", &num1, &num2);
            if(num2 == 0) {
                printf("Error: Cannot divide by zero.\n");
            }
            else {
                result = num1 / num2;
                printf("The quotient of %.2lf divided by %.2lf is: %.2lf\n", num1, num2, result);
            }
            break;

        case 5:
            printf("\nEnter two numbers to find modulus: ");
            scanf("%lf %lf", &num1, &num2);
            if(num2 == 0) {
                printf("Error: Cannot divide by zero.\n");
            }
            else {
                result = fmod(num1, num2);
                printf("The modulus of %.2lf and %.2lf is: %.2lf\n", num1, num2, result);
            }
            break;

        case 6:
            printf("\nEnter a number to find the square root: ");
            scanf("%lf", &num1);
            if(num1 < 0) {
                printf("Error: Cannot find square root of negative number.\n");
            }
            else {
                result = sqrt(num1);
                printf("The square root of %.2lf is: %.2lf\n", num1, result);
            }
            break;

        case 7:
            printf("\nEnter a number to find the exponential: ");
            scanf("%lf", &num1);
            result = exp(num1);
            printf("The exponential of %.2lf is: %.2lf\n", num1, result);
            break;

        case 8:
            printf("\nEnter a number to find the natural logarithm: ");
            scanf("%lf", &num1);
            if(num1 <= 0) {
                printf("Error: Cannot find natural logarithm of non-positive number.\n");
            }
            else {
                result = log(num1);
                printf("The natural logarithm of %.2lf is: %.2lf\n", num1, result);
            }
            break;

        case 9:
            printf("\nEnter a base number: ");
            scanf("%lf", &num1);
            printf("Enter a power number: ");
            scanf("%lf", &num2);
            if(num1 == 0 && num2 < 0) {
                printf("Error: Cannot take negative power of zero.\n");
            }
            else {
                result = pow(num1, num2);
                printf("%.2lf to the power of %.2lf is: %.2lf\n", num1, num2, result);
            }
            break;

        case 10:
            printf("\nPlease select a trigonometric function:\n");
            printf("[1] Sine\n");
            printf("[2] Cosine\n");
            printf("[3] Tangent\n");
            printf("[4] Cosecant\n");
            printf("[5] Secant\n");
            printf("[6] Cotangent\n\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            printf("\nEnter an angle in degrees: ");
            scanf("%lf", &num1);
            num1 = num1 * M_PI / 180; // convert to radians

            switch(choice) {

                case 1:
                    result = sin(num1);
                    printf("The sine of %.2lf degrees is: %.2lf\n", num1 * 180 / M_PI, result);
                    break;

                case 2:
                    result = cos(num1);
                    printf("The cosine of %.2lf degrees is: %.2lf\n", num1 * 180 / M_PI, result);
                    break;

                case 3:
                    result = tan(num1);
                    printf("The tangent of %.2lf degrees is: %.2lf\n", num1 * 180 / M_PI, result);
                    break;

                case 4:
                    if(sin(num1) == 0) {
                        printf("Error: Infinite cosecant value.\n");
                    }
                    else {
                        result = 1 / sin(num1);
                        printf("The cosecant of %.2lf degrees is: %.2lf\n", num1 * 180 / M_PI, result);
                    }
                    break;

                case 5:
                    if(cos(num1) == 0) {
                        printf("Error: Infinite secant value.\n");
                    }
                    else {
                        result = 1 / cos(num1);
                        printf("The secant of %.2lf degrees is: %.2lf\n", num1 * 180 / M_PI, result);
                    }
                    break;

                case 6:
                    if(tan(num1) == 0) {
                        printf("Error: Infinite cotangent value.\n");
                    }
                    else {
                        result = 1 / tan(num1);
                        printf("The cotangent of %.2lf degrees is: %.2lf\n", num1 * 180 / M_PI, result);
                    }
                    break;

                default:
                    printf("Error: Invalid choice.\n");
                    break;
            }
            break;

        default:
            printf("Error: Invalid choice.\n");
            break;
    }

    printf("\nThank you for using the Scientific Calculator program.\n");

    return 0;
}