//FormAI DATASET v1.0 Category: Math exercise ; Style: portable
#include <stdio.h>
#include <math.h>

int main() {
    int choice;
    double num1, num2, result;
    printf("Choose an operation to perform:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Power\n");
    printf("6. Square root\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter two numbers to add separated by a space: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 + num2;
            printf("Result: %lf\n", result);
            break;
        case 2:
            printf("Enter two numbers to subtract separated by a space: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 - num2;
            printf("Result: %lf\n", result);
            break;
        case 3:
            printf("Enter two numbers to multiply separated by a space: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 * num2;
            printf("Result: %lf\n", result);
            break;
        case 4:
            printf("Enter two numbers to divide separated by a space: ");
            scanf("%lf %lf", &num1, &num2);
            if(num2 == 0) {
                printf("Division by zero error!\n");
            } else {
                result = num1 / num2;
                printf("Result: %lf\n", result);
            }
            break;
        case 5:
            printf("Enter a number and the power to raise it to separated by a space: ");
            scanf("%lf %lf", &num1, &num2);
            result = pow(num1, num2);
            printf("Result: %lf\n", result);
            break;
        case 6:
            printf("Enter a number to find its square root: ");
            scanf("%lf", &num1);
            if(num1 < 0) {
                printf("Error: Cannot find square root of negative numbers!\n");
            } else {
                result = sqrt(num1);
                printf("Result: %lf\n", result);
            }
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}