//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: thoughtful
#include <stdio.h>
#include <math.h>

int main() {
    int choice;
    double x, y, result;
    printf("Welcome to the Scientific Calculator!\n");
    printf("Choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Square Root\n");
    printf("7. Sine\n");
    printf("8. Cosine\n");
    printf("9. Tangent\n");
    printf("Enter your choice (1-9): ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("Enter two numbers to add: ");
            scanf("%lf %lf", &x, &y);
            result = x + y;
            printf("Result: %lf\n", result);
            break;
        case 2:
            printf("Enter two numbers to subtract: ");
            scanf("%lf %lf", &x, &y);
            result = x - y;
            printf("Result: %lf\n", result);
            break;
        case 3:
            printf("Enter two numbers to multiply: ");
            scanf("%lf %lf", &x, &y);
            result = x * y;
            printf("Result: %lf\n", result);
            break;
        case 4:
            printf("Enter two numbers to divide: ");
            scanf("%lf %lf", &x, &y);
            if (y == 0) {
                printf("Cannot divide by zero.\n");
            } else {
                result = x / y;
                printf("Result: %lf\n", result);
            }
            break;
        case 5:
            printf("Enter base number: ");
            scanf("%lf", &x);
            printf("Enter power number: ");
            scanf("%lf", &y);
            result = pow(x, y);
            printf("Result: %lf\n", result);
            break;
        case 6:
            printf("Enter a number to find square root: ");
            scanf("%lf", &x);
            if (x < 0) {
                printf("Invalid input.\n");
            } else {
                result = sqrt(x);
                printf("Result: %lf\n", result);
            }
            break;
        case 7:
            printf("Enter angle in degrees: ");
            scanf("%lf", &x);
            result = sin(x * 3.14159 / 180);
            printf("Result: %lf\n", result);
            break;
        case 8:
            printf("Enter angle in degrees: ");
            scanf("%lf", &x);
            result = cos(x * 3.14159 / 180);
            printf("Result: %lf\n", result);
            break;
        case 9:
            printf("Enter angle in degrees: ");
            scanf("%lf", &x);
            result = tan(x * 3.14159 / 180);
            printf("Result: %lf\n", result);
            break;
        default:
            printf("Invalid input.\n");
    }
    return 0;
}