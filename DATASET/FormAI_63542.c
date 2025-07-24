//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: safe
#include<stdio.h>
#include<math.h>

int main() {

    double num1, num2, result;
    int choice;

    printf("Enter your choice\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Square Root\n");
    printf("6. Power\n");
    printf("7. Log\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            result = num1 + num2;
            printf("%.2lf + %.2lf = %.2lf", num1, num2, result);
            break;

        case 2:
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            result = num1 - num2;
            printf("%.2lf - %.2lf = %.2lf", num1, num2, result);
            break;

        case 3:
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            result = num1 * num2;
            printf("%.2lf * %.2lf = %.2lf", num1, num2, result);
            break;

        case 4:
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            if(num2 == 0) {
                printf("Error! Divisor must be non-zero.");
            } else {
                result = num1 / num2;
                printf("%.2lf / %.2lf = %.2lf", num1, num2, result);
            }
            break;

        case 5:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            result = sqrt(num1);
            printf("Square root of %.2lf = %.2lf", num1, result);
            break;

        case 6:
            printf("Enter base: ");
            scanf("%lf", &num1);
            printf("Enter exponent: ");
            scanf("%lf", &num2);
            result = pow(num1, num2);
            printf("%.2lf^%.2lf = %.2lf", num1, num2, result);
            break;

        case 7:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            result = log(num1);
            printf("Log of %.2lf = %.2lf", num1, result);
            break;

        default:
            printf("Error! Invalid choice.");
    }

    return 0;
}