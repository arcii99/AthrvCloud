//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <math.h>

// Function declarations
void printMenu();
double add(double x, double y);
double subtract(double x, double y);
double multiply(double x, double y);
double divide(double x, double y);
double power(double x, double y);
double squareRoot(double x);
double sine(double x);
double cosine(double x);
double tangent(double x);

int main() {
    int choice;
    double x, y, result;
    
    do {
        printMenu();
        printf("Enter your choice (1-9): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter the first number: ");
                scanf("%lf", &x);
                printf("Enter the second number: ");
                scanf("%lf", &y);
                result = add(x, y);
                printf("Result = %lf\n", result);
                break;
            case 2:
                printf("Enter the first number: ");
                scanf("%lf", &x);
                printf("Enter the second number: ");
                scanf("%lf", &y);
                result = subtract(x, y);
                printf("Result = %lf\n", result);
                break;
            case 3:
                printf("Enter the first number: ");
                scanf("%lf", &x);
                printf("Enter the second number: ");
                scanf("%lf", &y);
                result = multiply(x, y);
                printf("Result = %lf\n", result);
                break;
            case 4:
                printf("Enter the first number: ");
                scanf("%lf", &x);
                printf("Enter the second number: ");
                scanf("%lf", &y);
                result = divide(x, y);
                printf("Result = %lf\n", result);
                break;
            case 5:
                printf("Enter the number: ");
                scanf("%lf", &x);
                result = power(x, 2);
                printf("Result = %lf\n", result);
                break;
            case 6:
                printf("Enter the number: ");
                scanf("%lf", &x);
                if(x < 0) {
                    printf("Invalid argument!\n");
                } else {
                    result = squareRoot(x);
                    printf("Result = %lf\n", result);
                }
                break;
            case 7:
                printf("Enter the angle in degrees: ");
                scanf("%lf", &x);
                result = sine(x);
                printf("Result = %lf\n", result);
                break;
            case 8:
                printf("Enter the angle in degrees: ");
                scanf("%lf", &x);
                result = cosine(x);
                printf("Result = %lf\n", result);
                break;
            case 9:
                printf("Enter the angle in degrees: ");
                scanf("%lf", &x);
                result = tangent(x);
                if(isnan(result)) {
                    printf("Invalid argument!\n");
                } else {
                    printf("Result = %lf\n", result);
                }
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid choice.\n");
                break;
        }
        
    } while(choice != 0);
    
    return 0;
}

// Function definitions
void printMenu() {
    printf("------------------\n");
    printf("       MENU       \n");
    printf("------------------\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Square\n");
    printf("6. Square root\n");
    printf("7. Sine\n");
    printf("8. Cosine\n");
    printf("9. Tangent\n");
    printf("0. Exit\n");
}

double add(double x, double y) {
    return x + y;
}

double subtract(double x, double y) {
    return x - y;
}

double multiply(double x, double y) {
    return x * y;
}

double divide(double x, double y) {
    if(y == 0) {
        printf("Division by zero error!\n");
        return NAN;
    } else {
        return x / y;
    }
}

double power(double x, double y) {
    return pow(x, y);
}

double squareRoot(double x) {
    return sqrt(x);
}

double sine(double x) {
    double radians = x * (M_PI / 180);
    return sin(radians);
}

double cosine(double x) {
    double radians = x * (M_PI / 180);
    return cos(radians);
}

double tangent(double x) {
    double radians = x * (M_PI / 180);
    return tan(radians);
}