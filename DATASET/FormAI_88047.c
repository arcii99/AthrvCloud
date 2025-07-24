//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: energetic
#include <stdio.h>
#include <math.h>

int main() {
    printf("Welcome to the Energized Scientific Calculator!\n");
    printf("This program can do all sorts of scientific calculations for you.\n");
    printf("Enter your desired operation below:\n");

    int choice;
    float num1, num2, result;

    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Square Root\n");
    printf("7. Logarithm\n");
    printf("8. Trigonometric Functions\n");
    printf("9. Exit\n");

    printf("Please choose your option: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter two numbers to add: ");
            scanf("%f %f", &num1, &num2);
            result = num1 + num2;
            printf("%.2f + %.2f = %.2f\n", num1, num2, result);
            break;
        case 2:
            printf("Enter two numbers to subtract: ");
            scanf("%f %f", &num1, &num2);
            result = num1 - num2;
            printf("%.2f - %.2f = %.2f\n", num1, num2, result);
            break;
        case 3:
            printf("Enter two numbers to multiply: ");
            scanf("%f %f", &num1, &num2);
            result = num1 * num2;
            printf("%.2f * %.2f = %.2f\n", num1, num2, result);
            break;
        case 4:
            printf("Enter two numbers to divide: ");
            scanf("%f %f", &num1, &num2);
            result = num1 / num2;
            printf("%.2f / %.2f = %.2f\n", num1, num2, result);
            break;
        case 5:
            printf("Enter two numbers to find the power: ");
            scanf("%f %f", &num1, &num2);
            result = pow(num1, num2);
            printf("%.2f ^ %.2f = %.2f\n", num1, num2, result);
            break;
        case 6:
            printf("Enter a number to find the square root: ");
            scanf("%f", &num1);
            result = sqrt(num1);
            printf("sqrt(%.2f) = %.2f\n", num1, result);
            break;
        case 7:
            printf("Enter a number to find the natural logarithm: ");
            scanf("%f", &num1);
            result = log(num1);
            printf("ln(%.2f) = %.2f\n", num1, result);
            break;
        case 8:
            printf("Choose the trigonometric function:\n");
            printf("1. Sine\n");
            printf("2. Cosine\n");
            printf("3. Tangent\n");
            scanf("%d", &choice);
            printf("Enter the angle in degrees: ");
            scanf("%f", &num1);

            switch (choice) {
                case 1:
                    result = sin(num1 * (M_PI / 180));
                    printf("sin(%.2f) = %.2f\n", num1, result);
                    break;
                case 2:
                    result = cos(num1 * (M_PI / 180));
                    printf("cos(%.2f) = %.2f\n", num1, result);
                    break;
                case 3:
                    result = tan(num1 * (M_PI / 180));
                    printf("tan(%.2f) = %.2f\n", num1, result);
                    break;
                default:
                    printf("Invalid choice.\n");
                    break;
            }
            break;
        case 9:
            printf("Exiting the calculator...\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}