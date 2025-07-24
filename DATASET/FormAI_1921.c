//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: innovative
/* 
Innovative scientific calculator program that can evaluate basic arithmetic expressions 
and trigonometric functions using user-defined functions and a menu-driven program design.
*/

#include <stdio.h>
#include <math.h>

void add() {
    float num1, num2, result;
    printf("\nEnter the first number: ");
    scanf("%f", &num1);
    printf("Enter the second number: ");
    scanf("%f", &num2);
    result = num1 + num2;
    printf("\n%.2f + %.2f = %.2f\n", num1, num2, result);
}

void subtract() {
    float num1, num2, result;
    printf("\nEnter the first number: ");
    scanf("%f", &num1);
    printf("Enter the second number: ");
    scanf("%f", &num2);
    result = num1 - num2;
    printf("\n%.2f - %.2f = %.2f\n", num1, num2, result);
}

void multiply() {
    float num1, num2, result;
    printf("\nEnter the first number: ");
    scanf("%f", &num1);
    printf("Enter the second number: ");
    scanf("%f", &num2);
    result = num1 * num2;
    printf("\n%.2f * %.2f = %.2f\n", num1, num2, result);
}

void divide() {
    float num1, num2, result;
    printf("\nEnter the first number: ");
    scanf("%f", &num1);
    printf("Enter the second number: ");
    scanf("%f", &num2);
    if (num2 != 0) {
        result = num1 / num2;
        printf("\n%.2f / %.2f = %.2f\n", num1, num2, result);
    }
    else {
        printf("\nDivide by zero error!\n");
    }
}

void power() {
    float num, power, result;
    printf("\nEnter the number: ");
    scanf("%f", &num);
    printf("Enter the power: ");
    scanf("%f", &power);
    result = pow(num, power);
    printf("\n%.2f to the power of %.2f = %.2f\n", num, power, result);
}

void sine() {
    float angle, result;
    printf("\nEnter the angle in degrees: ");
    scanf("%f", &angle);
    result = sin(angle * M_PI / 180.0);
    printf("\nsin(%.2f) = %.2f\n", angle, result);
}

void cosine() {
    float angle, result;
    printf("\nEnter the angle in degrees: ");
    scanf("%f", &angle);
    result = cos(angle * M_PI / 180.0);
    printf("\ncos(%.2f) = %.2f\n", angle, result);
}

void tangent() {
    float angle, result;
    printf("\nEnter the angle in degrees: ");
    scanf("%f", &angle);
    result = tan(angle * M_PI / 180.0);
    printf("\ntan(%.2f) = %.2f\n", angle, result);
}

int main() {
    int choice;
    do {
        printf("\nScientific Calculator\n");
        printf("------------------------\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Power\n");
        printf("6. Sine\n");
        printf("7. Cosine\n");
        printf("8. Tangent\n");
        printf("9. Exit\n");
        printf("------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add();
            break;
        case 2:
            subtract();
            break;
        case 3:
            multiply();
            break;
        case 4:
            divide();
            break;
        case 5:
            power();
            break;
        case 6:
            sine();
            break;
        case 7:
            cosine();
            break;
        case 8:
            tangent();
            break;
        case 9:
            printf("\nGoodbye!\n");
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
        }
    } while (choice != 9);

    return 0;
}