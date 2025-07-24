//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: active
#include <stdio.h>
#include <math.h>

float add(float num1, float num2) {
    return num1 + num2;
}

float subtract(float num1, float num2) {
    return num1 - num2;
}

float multiply(float num1, float num2) {
    return num1 * num2;
}

float divide(float num1, float num2) {
    if (num2 == 0) {
        printf("Error: Cannot divide by zero!");
        return 0;
    }
    else {
        return num1 / num2;
    }
}

int power(float num1, float num2) {
    return pow(num1, num2);
}

int factorial(int num) {
    if (num < 0) {
        printf("Error: Factorial not defined for negative numbers!");
        return 0;
    }
    else if (num == 0) {
        return 1;
    }
    else {
        return num * factorial(num-1);
    }
}

int logarithm(float num) {
    if (num <= 0) {
        printf("Error: Cannot take logarithm of non-positive number!");
        return 0;
    }
    else {
        return log(num);
    }
}

int main() {
    float num1, num2;
    int choice;

    printf("Scientific Calculator");
    printf("\n1. Add");
    printf("\n2. Subtract");
    printf("\n3. Multiply");
    printf("\n4. Divide");
    printf("\n5. Power");
    printf("\n6. Factorial");
    printf("\n7. Logarithm");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter two numbers to add: ");
            scanf("%f %f", &num1, &num2);
            printf("Result: %f", add(num1, num2));
            break;

        case 2:
            printf("Enter two numbers to subtract: ");
            scanf("%f %f", &num1, &num2);
            printf("Result: %f", subtract(num1, num2));
            break;

        case 3:
            printf("Enter two numbers to multiply: ");
            scanf("%f %f", &num1, &num2);
            printf("Result: %f", multiply(num1, num2));
            break;

        case 4:
            printf("Enter two numbers to divide: ");
            scanf("%f %f", &num1, &num2);
            printf("Result: %f", divide(num1, num2));
            break;

        case 5:
            printf("Enter a number and its power: ");
            scanf("%f %f", &num1, &num2);
            printf("Result: %f", power(num1, num2));
            break;

        case 6:
            printf("Enter a number to find its factorial: ");
            scanf("%f", &num1);
            printf("Result: %d", factorial((int)num1));
            break;

        case 7:
            printf("Enter a number to find its logarithm: ");
            scanf("%f", &num1);
            printf("Result: %d", logarithm(num1));
            break;

        default:
            printf("Error: Invalid choice!");
            break;
    }

    return 0;
}