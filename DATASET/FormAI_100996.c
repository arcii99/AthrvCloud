//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: surprised
#include <stdio.h>
#include <math.h>

int main() {
    printf("Welcome to the scientific calculator!\n");
    printf("What operation would you like to perform?\n");
    printf("(1) Addition\n");
    printf("(2) Subtraction\n");
    printf("(3) Multiplication\n");
    printf("(4) Division\n");
    printf("(5) Square root\n");
    printf("(6) Exponentiation\n");
    printf("(7) Trigonometry\n");
    printf("(8) Logarithm\n");
    printf("(9) Factorial\n");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("You chose addition!\n");
        printf("Enter the first number:\n");
        double num1;
        scanf("%lf", &num1);
        printf("Enter the second number:\n");
        double num2;
        scanf("%lf", &num2);
        double result = num1 + num2;
        printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
    } else if (choice == 2) {
        printf("You chose subtraction!\n");
        printf("Enter the first number:\n");
        double num1;
        scanf("%lf", &num1);
        printf("Enter the second number:\n");
        double num2;
        scanf("%lf", &num2);
        double result = num1 - num2;
        printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
    } else if (choice == 3) {
        printf("You chose multiplication!\n");
        printf("Enter the first number:\n");
        double num1;
        scanf("%lf", &num1);
        printf("Enter the second number:\n");
        double num2;
        scanf("%lf", &num2);
        double result = num1 * num2;
        printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
    } else if (choice == 4) {
        printf("You chose division!\n");
        printf("Enter the dividend:\n");
        double dividend;
        scanf("%lf", &dividend);
        printf("Enter the divisor:\n");
        double divisor;
        scanf("%lf", &divisor);
        while (divisor == 0) {
            printf("Error! Division by zero is not allowed!\n");
            printf("Enter a non-zero divisor:\n");
            scanf("%lf", &divisor);
        }
        double result = dividend / divisor;
        printf("%.2lf / %.2lf = %.2lf\n", dividend, divisor, result);
    } else if (choice == 5) {
        printf("You chose square root!\n");
        printf("Enter a non-negative number to find the square root of:\n");
        double num;
        scanf("%lf", &num);
        while (num < 0) {
            printf("Error! Square root of a negative number is not allowed!\n");
            printf("Enter a non-negative number to find the square root of:\n");
            scanf("%lf", &num);
        }
        double result = sqrt(num);
        printf("Square root of %.2lf = %.2lf\n", num, result);
    } else if (choice == 6) {
        printf("You chose exponentiation!\n");
        printf("Enter the base:\n");
        double base;
        scanf("%lf", &base);
        printf("Enter the exponent:\n");
        double exponent;
        scanf("%lf", &exponent);
        double result = pow(base, exponent);
        printf("%.2lf raised to the power of %.2lf = %.2lf\n", base, exponent, result);
    } else if (choice == 7) {
        printf("You chose trigonometry!\n");
        printf("Which function would you like to use?\n");
        printf("(1) Sine\n");
        printf("(2) Cosine\n");
        printf("(3) Tangent\n");
        int function_choice;
        scanf("%d", &function_choice);
        printf("Enter an angle in radians:\n");
        double angle;
        scanf("%lf", &angle);
        while (function_choice == 3 && (fmod(angle, M_PI/2) == 0)) {
            printf("Error! Tangent of an angle that is a multiple of pi/2 is undefined!\n");
            printf("Enter a different angle in radians:\n");
            scanf("%lf", &angle);
        }
        double result;
        if (function_choice == 1) {
            result = sin(angle);
            printf("Sine of %.2lf radians = %.2lf\n", angle, result);
        } else if (function_choice == 2) {
            result = cos(angle);
            printf("Cosine of %.2lf radians = %.2lf\n", angle, result);
        } else if (function_choice == 3) {
            result = tan(angle);
            printf("Tangent of %.2lf radians = %.2lf\n", angle, result);
        }
    } else if (choice == 8) {
        printf("You chose logarithm!\n");
        printf("Enter the base:\n");
        double base;
        scanf("%lf", &base);
        while (base <= 0) {
            printf("Error! Base must be positive!\n");
            printf("Enter a positive base:\n");
            scanf("%lf", &base);
        }
        printf("Enter the number:\n");
        double num;
        scanf("%lf", &num);
        while (num <= 0) {
            printf("Error! Number must be positive!\n");
            printf("Enter a positive number:\n");
            scanf("%lf", &num);
        }
        double result = log(num) / log(base);
        printf("Log base %.2lf of %.2lf = %.2lf\n", base, num, result);
    } else if (choice == 9) {
        printf("You chose factorial!\n");
        printf("Enter a non-negative integer:\n");
        int num;
        scanf("%d", &num);
        while (num < 0) {
            printf("Error! Factorial of a negative number is not defined!\n");
            printf("Enter a non-negative integer:\n");
            scanf("%d", &num);
        }
        int result = 1;
        for (int i = 1; i <= num; i++) {
            result *= i;
        }
        printf("%d! = %d\n", num, result);
    } else {
        printf("Error! Invalid choice!\n");
    }

    return 0;
}