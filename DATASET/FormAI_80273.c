//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: complex
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// function prototypes
void add(double x, double y);
void subtract(double x, double y);
void multiply(double x, double y);
void divide(double x, double y);
void power(double x, double y);

int main() {
    printf("Welcome to the Scientific Calculator!\n");

    int choice;
    double x, y;

    do {
        printf("\nWhat do you want to do?\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Calculate power\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &x, &y);
                add(x, y);
                break;
            case 2:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &x, &y);
                subtract(x, y);
                break;
            case 3:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &x, &y);
                multiply(x, y);
                break;
            case 4:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &x, &y);
                divide(x, y);
                break;
            case 5:
                printf("Enter a base number: ");
                scanf("%lf", &x);
                printf("Enter a power number: ");
                scanf("%lf", &y);
                power(x, y);
                break;
            case 6:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (1);

    return 0;
}

void add(double x, double y) {
    double result = x + y;
    printf("%.2lf + %.2lf = %.2lf\n", x, y, result);
}

void subtract(double x, double y) {
    double result = x - y;
    printf("%.2lf - %.2lf = %.2lf\n", x, y, result);
}

void multiply(double x, double y) {
    double result = x * y;
    printf("%.2lf * %.2lf = %.2lf\n", x, y, result);
}

void divide(double x, double y) {
    if (y == 0) {
        printf("Cannot divide by zero!\n");
        return;
    }

    double result = x / y;
    printf("%.2lf / %.2lf = %.2lf\n", x, y, result);
}

void power(double x, double y) {
    double result = pow(x, y);
    printf("%.2lf ^ %.2lf = %.2lf\n", x, y, result);
}