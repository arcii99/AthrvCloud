//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Function Declarations
void addition();
void subtraction();
void multiplication();
void division();
void power();
void square();
void square_root();

int main() {
    int choice;

    while(1) {
        //Display Menu
        printf("\n================================\n");
        printf("        Scientific Calculator\n");
        printf("================================\n");
        printf(" 1. Addition\n");
        printf(" 2. Subtraction\n");
        printf(" 3. Multiplication\n");
        printf(" 4. Division\n");
        printf(" 5. Power\n");
        printf(" 6. Square\n");
        printf(" 7. Square Root\n");
        printf(" 8. Exit\n");
        printf("================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addition();
                break;
            case 2:
                subtraction();
                break;
            case 3:
                multiplication();
                break;
            case 4:
                division();
                break;
            case 5:
                power();
                break;
            case 6:
                square();
                break;
            case 7:
                square_root();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addition() {
    double num1, num2, result;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    result = num1 + num2;
    printf("The sum of %lf and %lf is %lf\n", num1, num2, result);
}

void subtraction() {
    double num1, num2, result;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    result = num1 - num2;
    printf("The subtraction of %lf and %lf is %lf\n", num1, num2, result);
}

void multiplication() {
    double num1, num2, result;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    result = num1 * num2;
    printf("The multiplication of %lf and %lf is %lf\n", num1, num2, result);
}

void division() {
    double num1, num2, result;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    if (num2 == 0) {
        printf("Division by zero error!\n");
    } else {
        result = num1 / num2;
        printf("The division of %lf and %lf is %lf\n", num1, num2, result);
    }
}

void power() {
    double num1, num2, result;
    printf("Enter base and exponent: ");
    scanf("%lf %lf", &num1, &num2);
    result = pow(num1, num2);
    printf("The Power of %lf raised to %lf is %lf\n", num1, num2, result);
}

void square() {
    double num, result;
    printf("Enter the number: ");
    scanf("%lf", &num);
    result = num * num;
    printf("The square of %lf is %lf\n", num, result);
}

void square_root() {
    double num, result;
    printf("Enter the number: ");
    scanf("%lf", &num);
    if (num < 0) {
        printf("Square root of a negative number is not possible!\n");
    } else {
        result = sqrt(num);
        printf("The square root of %lf is %lf\n", num, result);
    }
}