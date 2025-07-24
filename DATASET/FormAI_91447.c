//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <math.h>

void addition(double a, double b) {
    printf("%.2lf + %.2lf = %.2lf\n", a, b, (a+b));
}

void subtraction(double a, double b) {
    printf("%.2lf - %.2lf = %.2lf\n", a, b, (a-b));
}

void multiplication(double a, double b) {
    printf("%.2lf * %.2lf = %.2lf\n", a, b, (a*b));
}

void division(double a, double b) {
    if(b==0) {
        printf("Division by zero error!\n");
    }
    else {
        printf("%.2lf / %.2lf = %.2lf\n", a, b, (a/b));
    }
}

void power(double a, double b) {
    printf("%.2lf ^ %.2lf = %.2lf\n", a, b, pow(a, b));
}

void square(double a) {
    printf("%.2lf ^ 2 = %.2lf\n", a, (a*a));
}

int main() {
    int choice;
    double num1, num2;

    printf("\nWelcome to the Scientific Calculator designed in Ada Lovelace style\n");

    printf("\nEnter two numbers:\n");
    scanf("%lf %lf", &num1, &num2);

    printf("\nPlease select an operation to perform: \n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Square\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            addition(num1, num2);
            break;
        case 2:
            subtraction(num1, num2);
            break;
        case 3:
            multiplication(num1, num2);
            break;
        case 4:
            division(num1, num2);
            break;
        case 5:
            power(num1, num2);
            break;
        case 6:
            square(num1);
            break;
        default:
            printf("\nInvalid Input!\n");
    }

    return 0;
}