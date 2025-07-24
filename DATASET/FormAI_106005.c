//FormAI DATASET v1.0 Category: Arithmetic ; Style: energetic
#include<stdio.h>

int main() {
    int num1, num2, addition, subtraction, multiplication, division;

    printf("Welcome to the Energetic Calculator!\n");

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    // Addition Calculation
    addition = num1 + num2;
    printf("\nAddition: %d\n", addition);

    // Subtraction Calculation
    subtraction = num1 - num2;
    printf("Subtraction: %d\n", subtraction);

    // Multiplication Calculation
    multiplication = num1 * num2;
    printf("Multiplication: %d\n", multiplication);

    // Division Calculation
    if (num2 == 0) {
        printf("Oops! Divide by 0 error.\n");
    } else {
        division = num1 / num2;
        printf("Division: %d\n", division);
    }

    printf("\nThank you for using the Energetic Calculator!");

    return 0;
}