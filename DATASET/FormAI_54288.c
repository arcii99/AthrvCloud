//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Cryptic
#include <stdio.h>
#include <math.h>

int main()
{
    int num1, num2, choice;
    float result;

    printf("Enter your first number: ");
    scanf("%d", &num1);
    printf("Enter your second number: ");
    scanf("%d", &num2);

    printf("Enter operation to perform (1-7):\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Square\n");
    printf("6. Square Root\n");
    printf("7. Modulus\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            result = num1 + num2;
            printf("The sum of %d and %d is %.2f\n", num1, num2, result);
            break;
        case 2:
            result = num1 - num2;
            printf("The difference between %d and %d is %.2f\n", num1, num2, result);
            break;
        case 3:
            result = num1 * num2;
            printf("The product of %d and %d is %.2f\n", num1, num2, result);
            break;
        case 4:
            if(num2 == 0) {
                printf("Cannot divide by zero\n");
            } else {
                result = (float)num1 / num2;
                printf("%d divided by %d is %.2f\n", num1, num2, result);
            }
            break;
        case 5:
            result = pow(num1, 2);
            printf("The square of %d is %.2f\n", num1, result);
            result = pow(num2, 2);
            printf("The square of %d is %.2f\n", num2, result);
            break;
        case 6:
            if(num1 < 0 || num2 < 0) {
                printf("Cannot calculate square root of negative number\n");
            } else {
                result = sqrt(num1);
                printf("The square root of %d is %.2f\n", num1, result);
                result = sqrt(num2);
                printf("The square root of %d is %.2f\n", num2, result);
            }
            break;
        case 7:
            result = num1 % num2;
            printf("The modulus of %d and %d is %d\n", num1, num2, (int)result);
            break;
        default:
            printf("Invalid operation\n");
            break;
    }

    return 0;
}