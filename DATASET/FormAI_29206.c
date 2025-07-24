//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: safe
#include<stdio.h>
#include<math.h>

//Function prototypes
double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);
double power(double, double);
double root(double, double);

int main() {
    double num1, num2, result;
    int option;

    printf("Welcome to My Calculator Program!\n");

    do {
        printf("\nPlease select an option:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Power\n");
        printf("6. Root\n");
        printf("7. Exit\n");

        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = add(num1, num2);
                printf("Result: %lf\n", result);
                break;

            case 2:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = subtract(num1, num2);
                printf("Result: %lf\n", result);
                break;

            case 3:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = multiply(num1, num2);
                printf("Result: %lf\n", result);
                break;

            case 4:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = divide(num1, num2);
                if(isnan(result)) {
                    printf("Invalid input: Division by zero\n");
                }
                else {
                    printf("Result: %lf\n", result);
                }
                break;

            case 5:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = power(num1, num2);
                printf("Result: %lf\n", result);
                break;

            case 6:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = root(num1, num2);
                if(isnan(result)) {
                    printf("Invalid input: Negative number\n");
                }
                else {
                    printf("Result: %lf\n", result);
                }
                break;

            case 7:
                printf("Exiting calculator program!\n");
                break;

            default:
                printf("Invalid option selected. Please try again.\n");
        }

    } while(option != 7);

    return 0;
}

//Function definitions
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if(b == 0) {
        return NAN;
    }
    else {
        return a / b;
    }
}

double power(double base, double exponent) {
    return pow(base, exponent);
}

double root(double num, double degree) {
    if(num < 0) {
        return NAN;
    }
    else {
        return pow(num, 1.0/degree);
    }
}