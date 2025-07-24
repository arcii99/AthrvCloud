//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: mind-bending
#include <stdio.h>

int main() {
    float num1, num2, result;
    int choice;

    printf("Welcome to the Mind-Bending Scientific Calculator!\n");
    printf("Enter the first number: ");
    scanf("%f", &num1);
    printf("Enter the second number: ");
    scanf("%f", &num2);

    printf("Select the operation you want to perform:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exponentiation\n");
    printf("6. Square Root\n");
    printf("7. Absolute Value\n");
    printf("8. Factorial\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            result = num1 + num2;
            printf("The sum of %f and %f is %f.\n", num1, num2, result);
            break;
        case 2:
            result = num1 - num2;
            printf("The difference between %f and %f is %f.\n", num1, num2, result);
            break;
        case 3:
            result = num1 * num2;
            printf("The product of %f and %f is %f.\n", num1, num2, result);
            break;
        case 4:
            if(num2 == 0) {
                printf("Error: Cannot divide by zero!\n");
            } else {
                result = num1 / num2;
                printf("%f divided by %f is %f.\n", num1, num2, result);
            }
            break;
        case 5:
            result = pow(num1, num2);
            printf("%f raised to the power of %f is %f.\n", num1, num2, result);
            break;
        case 6:
            if(num1 < 0) {
                printf("Error: Cannot find square root of negative number!\n");
            } else {
                result = sqrt(num1);
                printf("The square root of %f is %f.\n", num1, result);
            }
            break;
        case 7:
            if(num1 < 0) {
                result = num1 * -1;
                printf("The absolute value of %f is %f.\n", num1, result);
            } else {
                printf("The absolute value of %f is %f.\n", num1, num1);
            }
            break;
        case 8:
            if(num1 < 0) {
                printf("Error: Cannot find factorial of negative number!\n");
            } else {
                int i;
                float factorial = 1;
                for(i = 1; i <= num1; i++) {
                    factorial *= i;
                }
                printf("The factorial of %f is %f.\n", num1, factorial);
            }
            break;
        default:
            printf("Error: Did not recognize input.\n");
            main();
    }
    return 0;
}