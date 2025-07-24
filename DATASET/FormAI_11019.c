//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: future-proof
#include <stdio.h>
#include <math.h>

/* A simple scientific calculator program */

int main() {

    int option;
    double num, result;

    /* Print out the options to the user */
    printf("Welcome to the Scientific Calculator!\n");
    printf("Please select an option:\n");
    printf("1. Square root\n");
    printf("2. Exponential\n");
    printf("3. Logarithm\n");
    printf("4. Trigonometry\n");

    /* Read the user's option */
    scanf("%d", &option);

    switch(option) {
        case 1:
            /* Calculate the square root of a number */
            printf("Enter a number: ");
            scanf("%lf", &num);
            result = sqrt(num);
            printf("The square root of %lf is %lf\n", num, result);
            break;

        case 2:
            /* Calculate the exponential of a number */
            printf("Enter a number: ");
            scanf("%lf", &num);
            result = exp(num);
            printf("The exponential of %lf is %lf\n", num, result);
            break;

        case 3:
            /* Calculate the logarithm of a number */
            printf("Enter a number: ");
            scanf("%lf", &num);
            result = log(num);
            printf("The natural logarithm of %lf is %lf\n", num, result);
            break;

        case 4:
            /* Calculate trigonometric functions */
            printf("Please select an option:\n");
            printf("1. Sine\n");
            printf("2. Cosine\n");
            printf("3. Tangent\n");
            scanf("%d", &option);

            printf("Enter an angle in degrees: ");
            scanf("%lf", &num);
            num = num * M_PI / 180;

            switch(option) {
                case 1:
                    result = sin(num);
                    printf("The sine of %lf degrees is %lf\n", num, result);
                    break;
                case 2:
                    result = cos(num);
                    printf("The cosine of %lf degrees is %lf\n", num, result);
                    break;
                case 3:
                    result = tan(num);
                    printf("The tangent of %lf degrees is %lf\n", num, result);
                    break;
                default:
                    printf("Invalid option\n");
                    break;
            }

            break;

        default:
            printf("Invalid option\n");
            break;
    }

    return 0;
}