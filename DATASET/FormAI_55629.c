//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: realistic
#include <stdio.h>
#include <math.h>

double add(double num1, double num2) {
    return num1 + num2;
}

double subtract(double num1, double num2) {
    return num1 - num2;
}

double multiply(double num1, double num2) {
    return num1 * num2;
}

double divide(double num1, double num2) {
    if (num2 == 0) {
        printf("Error: cannot divide by zero!\n");
        return 0;
    } else {
        return num1/num2;
    }
}

double power(double num1, double num2) {
    return pow(num1, num2);
}

double square_root(double num) {
    if (num < 0) {
        printf("Error: cannot take square root of negative number!\n");
        return 0;
    } else {
        return sqrt(num);
    }
}

int main() {
    double num1, num2, result;
    int choice;
    
    printf("Welcome to the Scientific Calculator!\n");
    printf("Please select an operation:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Power\n");
    printf("6. Square Root\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("Enter the first number: ");
            scanf("%lf", &num1);
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            result = add(num1, num2);
            printf("The sum is: %lf\n", result);
            break;
        case 2:
            printf("Enter the first number: ");
            scanf("%lf", &num1);
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            result = subtract(num1, num2);
            printf("The difference is: %lf\n", result);
            break;
        case 3:
            printf("Enter the first number: ");
            scanf("%lf", &num1);
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            result = multiply(num1, num2);
            printf("The product is: %lf\n", result);
            break;
        case 4:
            printf("Enter the first number: ");
            scanf("%lf", &num1);
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            result = divide(num1, num2);
            printf("The quotient is: %lf\n", result);
            break;
        case 5:
            printf("Enter the first number: ");
            scanf("%lf", &num1);
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            result = power(num1, num2);
            printf("The result is: %lf\n", result);
            break;
        case 6:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            result = square_root(num1);
            printf("The square root is: %lf\n", result);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
    
    return 0;
}