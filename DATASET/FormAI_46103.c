//FormAI DATASET v1.0 Category: Calculator ; Style: enthusiastic
#include <stdio.h>

int main() {
    //Welcome message
    printf("Welcome to the incredible C Calculator!\n");

    //User input section
    float num1, num2;
    char operation;
    printf("Enter the first number: ");
    scanf("%f", &num1);
    printf("Enter the second number: ");
    scanf("%f", &num2);
    printf("Enter the operation (+,-,*,/): ");
    scanf(" %c", &operation);

    //Calculation section
    float result;
    if (operation == '+') {
        result = num1 + num2;
    } else if (operation == '-') {
        result = num1 - num2;
    } else if (operation == '*') {
        result = num1 * num2;
    } else if (operation == '/') {
        result = num1 / num2;
    } else {
        //Handling invalid operation
        printf("Invalid operation entered!");
        return 0;
    }

    //Printing the result
    printf("%f %c %f = %f\n", num1, operation, num2, result);

    //Additional features
    printf("Would you like to round the result? (y/n): ");
    char round_option;
    scanf(" %c", &round_option);
    if (round_option == 'y') {
        printf("How many decimal places would you like to round to?: ");
        int decimal_places;
        scanf("%d", &decimal_places);
        result = roundf(result * pow(10, decimal_places)) / pow(10, decimal_places);
        printf("The rounded result is: %f", result);
    } else {
        printf("Good bye!\n");
    }

    return 0;
}