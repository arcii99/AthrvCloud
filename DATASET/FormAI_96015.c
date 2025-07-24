//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: mind-bending
#include<stdio.h>
#include<math.h>

void main() {
    printf("Welcome to the Mind-bending C Scientific Calculator\n");
    printf("Enter the corresponding option number to perform desired operation\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exponentiation\n");
    printf("6. Square root\n");
    printf("7. Logarithm\n");
    printf("8. Trigonometric functions\n");

    int option;
    printf("Option: ");
    scanf("%d", &option);

    double n1, n2, result;
    switch(option) {
        case 1: // addition
            printf("Enter the first number: ");
            scanf("%lf", &n1);
            printf("Enter the second number: ");
            scanf("%lf", &n2);
            result = n1 + n2;
            printf("%.2lf + %.2lf = %.2lf\n", n1, n2, result);
            break;

        case 2: // subtraction
            printf("Enter the first number: ");
            scanf("%lf", &n1);
            printf("Enter the second number: ");
            scanf("%lf", &n2);
            result = n1 - n2;
            printf("%.2lf - %.2lf = %.2lf\n", n1, n2, result);
            break;

        case 3: // multiplication
            printf("Enter the first number: ");
            scanf("%lf", &n1);
            printf("Enter the second number: ");
            scanf("%lf", &n2);
            result = n1 * n2;
            printf("%.2lf * %.2lf = %.2lf\n", n1, n2, result);
            break;

        case 4: // division
            printf("Enter the dividend: ");
            scanf("%lf", &n1);
            printf("Enter the divisor: ");
            scanf("%lf", &n2);
            if(n2 == 0) {
                printf("Division by zero is undefined\n");
            }
            else {
                result = n1 / n2;
                printf("%.2lf / %.2lf = %.2lf\n", n1, n2, result);
            }
            break;

        case 5: // exponentiation
            printf("Enter the base: ");
            scanf("%lf", &n1);
            printf("Enter the exponent: ");
            scanf("%lf", &n2);
            result = pow(n1, n2);
            printf("%.2lf to the power of %.2lf = %.2lf\n", n1, n2, result);
            break;

        case 6: // square root
            printf("Enter the number: ");
            scanf("%lf", &n1);
            if(n1 < 0) {
                printf("The square root of a negative number is undefined\n");
            }
            else {
                result = sqrt(n1);
                printf("The square root of %.2lf is %.2lf\n", n1, result);
            }
            break;

        case 7: // logarithm
            printf("Enter the number: ");
            scanf("%lf", &n1);
            if(n1 <= 0) {
                printf("The logarithm of a non-positive number is undefined\n");
            }
            else {
                result = log(n1);
                printf("The natural logarithm of %.2lf is %.2lf\n", n1, result);
            }
            break;

        case 8: // trigonometric functions
            printf("Enter the angle (in degrees): ");
            scanf("%lf", &n1);
            double rad = n1 * M_PI / 180;
            printf("Select the trigonometric function to find the value of\n");
            printf("1. Sine\n");
            printf("2. Cosine\n");
            printf("3. Tangent\n");
            int trig_option;
            printf("Option: ");
            scanf("%d", &trig_option);
            switch(trig_option) {
                case 1: // sine
                    result = sin(rad);
                    printf("Sin(%.2lf) = %.2lf\n", n1, result);
                    break;

                case 2: // cosine
                    result = cos(rad);
                    printf("Cos(%.2lf) = %.2lf\n", n1, result);
                    break;

                case 3: // tangent
                    if(fabs(cos(rad)) < 1e-6) {
                        printf("Tangent of %.2lf is undefined\n", n1);
                    }
                    else {
                        result = tan(rad);
                        printf("Tan(%.2lf) = %.2lf\n", n1, result);
                    }
                    break;

                default:
                    printf("Invalid option\n");
            }
            break;

        default:
            printf("Invalid option\n");
    }
}