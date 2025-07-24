//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: ultraprecise
#include <stdio.h>
#include <math.h>

/* Function declarations */
void display_menu();
int get_num1();
int get_num2();
double add(double num1, double num2);
double subtract(double num1, double num2);
double multiply(double num1, double num2);
double divide(double num1, double num2);
double power(double num1, double num2);
double sqrt_func(double num);

/* Main function */
int main() {
    int choice, num1, num2;
    double result;

    display_menu(); // Display the menu

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            num1 = get_num1();
            num2 = get_num2();
            result = add(num1, num2);
            printf("%d + %d = %lf\n", num1, num2, result);
            break;
        case 2:
            num1 = get_num1();
            num2 = get_num2();
            result = subtract(num1, num2);
            printf("%d - %d = %lf\n", num1, num2, result);
            break;
        case 3:
            num1 = get_num1();
            num2 = get_num2();
            result = multiply(num1, num2);
            printf("%d * %d = %lf\n", num1, num2, result);
            break;
        case 4:
            num1 = get_num1();
            num2 = get_num2();
            result = divide(num1, num2);
            printf("%d / %d = %lf\n", num1, num2, result);
            break;
        case 5:
            num1 = get_num1();
            num2 = get_num2();
            result = power(num1, num2);
            printf("%d ^ %d = %lf\n", num1, num2, result);
            break;
        case 6:
            num1 = get_num1();
            result = sqrt_func(num1);
            printf("sqrt(%d) = %lf\n", num1, result);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}

/* Function to display the menu */
void display_menu() {
    printf("===== Scientific Calculator =====\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Square Root\n");
    printf("===============================\n");
}

/* Function to get the first number */
int get_num1() {
    int num1;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    return num1;
}

/* Function to get the second number */
int get_num2() {
    int num2;
    printf("Enter the second number: ");
    scanf("%d", &num2);
    return num2;
}

/* Function to add two numbers */
double add(double num1, double num2) {
    return num1 + num2;
}

/* Function to subtract two numbers */
double subtract(double num1, double num2) {
    return num1 - num2;
}

/* Function to multiply two numbers */
double multiply(double num1, double num2) {
    return num1 * num2;
}

/* Function to divide two numbers */
double divide(double num1, double num2) {
    if(num2 == 0) {
        printf("Cannot divide by zero\n");
        exit(0);
    }
    return num1 / num2;
}

/* Function to calculate power of a number */
double power(double num1, double num2) {
    return pow(num1, num2);
}

/* Function to calculate square root of a number */
double sqrt_func(double num) {
    if(num < 0) {
        printf("Cannot find square root of a negative number\n");
        exit(0);
    }
    return sqrt(num);
}