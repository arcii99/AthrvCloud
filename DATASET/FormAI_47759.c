//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: futuristic
#include <stdio.h>
#include <math.h>

int main() {

    int operation;
    float num1, num2, result;
    printf("Welcome to the futuristic scientific calculator!\n");

    do {
        printf("Please select an operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Square Root\n");
        printf("6. Power\n");
        printf("7. Sin\n");
        printf("8. Cos\n");
        printf("9. Tan\n");
        printf("10. Log\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &operation);

        switch(operation) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%f %f", &num1, &num2);
                result = num1 + num2;
                printf("Result: %f\n", result);
                break;
            case 2:
                printf("Enter two numbers: ");
                scanf("%f %f", &num1, &num2);
                result = num1 - num2;
                printf("Result: %f\n", result);
                break;
            case 3:
                printf("Enter two numbers: ");
                scanf("%f %f", &num1, &num2);
                result = num1 * num2;
                printf("Result: %f\n", result);
                break;
            case 4:
                printf("Enter two numbers: ");
                scanf("%f %f", &num1, &num2);
                result = num1 / num2;
                printf("Result: %f\n", result);
                break;
            case 5:
                printf("Enter a number: ");
                scanf("%f", &num1);
                result = sqrt(num1);
                printf("Result: %f\n", result);
                break;
            case 6:
                printf("Enter two numbers: ");
                scanf("%f %f", &num1, &num2);
                result = pow(num1, num2);
                printf("Result: %f\n", result);
                break;
            case 7:
                printf("Enter a number: ");
                scanf("%f", &num1);
                result = sin(num1);
                printf("Result: %f\n", result);
                break;
            case 8:
                printf("Enter a number: ");
                scanf("%f", &num1);
                result = cos(num1);
                printf("Result: %f\n", result);
                break;
            case 9:
                printf("Enter a number: ");
                scanf("%f", &num1);
                result = tan(num1);
                printf("Result: %f\n", result);
                break;
            case 10:
                printf("Enter a number: ");
                scanf("%f", &num1);
                result = log10(num1);
                printf("Result: %f\n", result);
                break;
            case 0:
                printf("Thank you for using the futuristic scientific calculator!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }

    } while(operation != 0);

    return 0;
}