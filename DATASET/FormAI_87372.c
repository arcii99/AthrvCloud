//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: energetic
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

double addition(double num1, double num2) {
    return num1 + num2;
}

double subtraction(double num1, double num2) {
    return num1 - num2;
}

double multiplication(double num1, double num2) {
    return num1 * num2;
}

double division(double num1, double num2) {
    return num1 / num2;
}

double power(double num1, double num2) {
    return pow(num1, num2);
}

double square_root(double num) {
    return sqrt(num);
}

double sine(double num) {
    return sin(num);
}

double cosine(double num) {
    return cos(num);
}

double tangent(double num) {
    return tan(num);
}

double logarithm(double num) {
    return log(num);
}

void display_menu() {
    printf("\nWelcome to the Calculator App\n\n");
    printf("Please choose from the following options:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Square Root\n");
    printf("7. Sine\n");
    printf("8. Cosine\n");
    printf("9. Tangent\n");
    printf("10. Logarithm\n");
    printf("11. Exit\n\n");
}

int main() {
    int choice;
    double num1, num2;

    display_menu();

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter two numbers to add: ");
                scanf("%lf %lf", &num1, &num2);
                printf("%.2lf + %.2lf = %.2lf\n", num1, num2, addition(num1, num2));
                break;

            case 2:
                printf("\nEnter two numbers to subtract: ");
                scanf("%lf %lf", &num1, &num2);
                printf("%.2lf - %.2lf = %.2lf\n", num1, num2, subtraction(num1, num2));
                break;

            case 3:
                printf("\nEnter two numbers to multiply: ");
                scanf("%lf %lf", &num1, &num2);
                printf("%.2lf * %.2lf = %.2lf\n", num1, num2, multiplication(num1, num2));
                break;

            case 4:
                printf("\nEnter two numbers to divide: ");
                scanf("%lf %lf", &num1, &num2);

                if (num2 == 0) {
                    printf("Error: division by zero\n");
                } else {
                    printf("%.2lf / %.2lf = %.2lf\n", num1, num2, division(num1, num2));
                }

                break;

            case 5:
                printf("\nEnter a base number: ");
                scanf("%lf", &num1);
                printf("Enter an exponent number: ");
                scanf("%lf", &num2);
                printf("%.2lf ^ %.2lf = %.2lf\n", num1, num2, power(num1, num2));
                break;

            case 6:
                printf("\nEnter a number: ");
                scanf("%lf", &num1);

                if (num1 < 0) {
                    printf("Error: square root of negative number\n");
                } else {
                    printf("sqrt(%.2lf) = %.2lf\n", num1, square_root(num1));
                }

                break;

            case 7:
                printf("\nEnter a number: ");
                scanf("%lf", &num1);
                printf("sin(%.2lf) = %.2lf\n", num1, sine(num1));
                break;

            case 8:
                printf("\nEnter a number: ");
                scanf("%lf", &num1);
                printf("cos(%.2lf) = %.2lf\n", num1, cosine(num1));
                break;

            case 9:
                printf("\nEnter a number: ");
                scanf("%lf", &num1);
                printf("tan(%.2lf) = %.2lf\n", num1, tangent(num1));
                break;

            case 10:
                printf("\nEnter a number: ");
                scanf("%lf", &num1);
                printf("log(%.2lf) = %.2lf\n", num1, logarithm(num1));
                break;

            case 11:
                printf("\nThank you for using the Calculator App! Goodbye.\n");
                break;

            default:
                printf("\nInvalid choice, please try again.\n");
        }
    } while (choice != 11);

    return 0;
}