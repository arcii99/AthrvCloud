//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: expert-level
#include<stdio.h>
#include<math.h>

/* Function to perform addition operation */
double add(double x, double y) {
    return x + y;
}

/* Function to perform subtraction operation */
double subtract(double x, double y) {
    return x - y;
}

/* Function to perform multiplication operation */
double multiply(double x, double y) {
    return x * y;
}

/* Function to perform division operation */
double divide(double x, double y) {
    if(y == 0) {
        printf("Math Error: Cannot divide by zero\n");
        return NAN;
    } else {
        return x / y;
    }
}

/* Function to perform square root operation */
double squareRoot(double x) {
    if(x < 0) {
        printf("Math Error: Cannot calculate square root of a negative number\n");
        return NAN;
    } else {
        return sqrt(x);
    }
}

/* Function to calculate factorial of a number */
double factorial(double x) {
    double fact = 1;
    int i;
    
    if(x < 0) {
        printf("Math Error: Cannot calculate factorial of a negative number\n");
        return NAN;
    } else {
        for(i = 1; i <= x; i++) {
            fact *= i;
        }
        return fact;
    }
}

/* Function to calculate power of a number */
double power(double x, double y) {
    return pow(x, y);
}

/* Function to display available operations */
void displayMenu() {
    printf("Available Operations:\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Square Root (√)\n");
    printf("6. Factorial (!)\n");
    printf("7. Power (^)\n\n");
}

int main() {
    int choice;
    double num1, num2, res;
    
    displayMenu();
    
    do {
        /* Take input of operation choice */
        printf("Enter choice of operation (or 0 to exit): ");
        scanf("%d", &choice);
        
        if(choice == 0) {
            break;
        }
        
        switch(choice) {
            case 1: /* Addition */
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                res = add(num1, num2);
                printf("%.2lf + %.2lf = %.2lf\n\n", num1, num2, res);
                break;
            case 2: /* Subtraction */
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                res = subtract(num1, num2);
                printf("%.2lf - %.2lf = %.2lf\n\n", num1, num2, res);
                break;
            case 3: /* Multiplication */
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                res = multiply(num1, num2);
                printf("%.2lf * %.2lf = %.2lf\n\n", num1, num2, res);
                break;
            case 4: /* Division */
                printf("Enter numerator: ");
                scanf("%lf", &num1);
                printf("Enter denominator: ");
                scanf("%lf", &num2);
                res = divide(num1, num2);
                printf("%.2lf / %.2lf = %.2lf\n\n", num1, num2, res);
                break;
            case 5: /* Square Root */
                printf("Enter a number: ");
                scanf("%lf", &num1);
                res = squareRoot(num1);
                printf("√%.2lf = %.2lf\n\n", num1, res);
                break;
            case 6: /* Factorial */
                printf("Enter a number: ");
                scanf("%lf", &num1);
                res = factorial(num1);
                printf("%.0lf! = %.0lf\n\n", num1, res);
                break;
            case 7: /* Power */
                printf("Enter base number: ");
                scanf("%lf", &num1);
                printf("Enter exponent: ");
                scanf("%lf", &num2);
                res = power(num1, num2);
                printf("%.2lf ^ %.2lf = %.2lf\n\n", num1, num2, res);
                break;
            default: /* Invalid choice */
                printf("Invalid choice\n\n");
        }
        
    } while(choice != 0);
    
    return 0;
}