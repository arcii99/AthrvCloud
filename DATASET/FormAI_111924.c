//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: creative
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
    return num1 / num2;
}

double power(double base, double exponent) {
    return pow(base, exponent);
}

double square_root(double num) {
    return sqrt(num);
}

int main() {
    int choice;
    double num1, num2, result;
    printf("\nEnter two operands: ");
    scanf("%lf %lf", &num1, &num2);

    printf("\n-------------Scientific Calculator---------------\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Power\n6. Square root\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            result = add(num1, num2);
            printf("\n%.2lf + %.2lf = %.2lf", num1, num2, result);
            break;

        case 2:
            result = subtract(num1, num2);
            printf("\n%.2lf - %.2lf = %.2lf", num1, num2, result);
            break;

        case 3:
            result = multiply(num1, num2);
            printf("\n%.2lf * %.2lf = %.2lf", num1, num2, result);
            break;

        case 4:
            if (num2 == 0) {
                printf("\nCannot divide by zero");
                break;
            }
            result = divide(num1, num2);
            printf("\n%.2lf / %.2lf = %.2lf", num1, num2, result);
            break;

        case 5:
            result = power(num1, num2);
            printf("\n%.2lf ^ %.2lf = %.2lf", num1, num2, result);
            break;

        case 6:
            if (num1 < 0) {
                printf("\nInvalid input");
                break;
            }
            result = square_root(num1);
            printf("\nSquare root of %.2lf = %.2lf", num1, result);
            break;

        default:
            printf("\nInvalid choice");
    }

    return 0;
}