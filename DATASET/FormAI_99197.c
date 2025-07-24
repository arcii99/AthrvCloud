//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: inquisitive
#include <stdio.h>
#include <math.h>

int main() {

    printf("Welcome to the Scientific Calculator!\n");
    printf("Please enter your choice:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Power\n");
    printf("6. Square Root\n");
    printf("7. Sine\n");
    printf("8. Cosine\n");
    printf("9. Tangent\n");

    int choice;
    scanf("%d", &choice);

    double a, b, result;

    switch(choice) {
        case 1:
            printf("Enter two numbers to add: ");
            scanf("%lf %lf", &a, &b);
            result = a + b;
            printf("The result is: %lf\n", result);
            break;

        case 2:
            printf("Enter two numbers to subtract: ");
            scanf("%lf %lf", &a, &b);
            result = a - b;
            printf("The result is: %lf\n", result);
            break;

        case 3:
            printf("Enter two numbers to multiply: ");
            scanf("%lf %lf", &a, &b);
            result = a * b;
            printf("The result is: %lf\n", result);
            break;

        case 4:
            printf("Enter two numbers to divide: ");
            scanf("%lf %lf", &a, &b);
            if (b == 0) {
                printf("Error: Cannot divide by zero!\n");
                return 1;
            } else {
                result = a / b;
                printf("The result is: %lf\n", result);
            }
            break;

        case 5:
            printf("Enter the base number: ");
            scanf("%lf", &a);
            printf("Enter the exponent: ");
            scanf("%lf", &b);
            result = pow(a, b);
            printf("The result is: %lf\n", result);
            break;

        case 6:
            printf("Enter a number to find its square root: ");
            scanf("%lf", &a);
            if (a < 0) {
                printf("Error: Cannot find square root of negative numbers!\n");
                return 1;
            } else {
                result = sqrt(a);
                printf("The result is: %lf\n", result);
            }
            break;

        case 7:
            printf("Enter the angle in degrees: ");
            scanf("%lf", &a);
            result = sin(a * M_PI / 180);
            printf("The result is: %lf\n", result);
            break;

        case 8:
            printf("Enter the angle in degrees: ");
            scanf("%lf", &a);
            result = cos(a * M_PI / 180);
            printf("The result is: %lf\n", result);
            break;

        case 9:
            printf("Enter the angle in degrees: ");
            scanf("%lf", &a);
            result = tan(a * M_PI / 180);
            printf("The result is: %lf\n", result);
            break;

        default:
            printf("Error: Invalid choice!\n");
            return 1;
    }

    return 0;
}