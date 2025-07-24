//FormAI DATASET v1.0 Category: Arithmetic ; Style: genious
#include <stdio.h>

int main() {
    int num1, num2, result; //declaring integer variables
    char operator; //declaring character variable for operator
    printf("Welcome to the Arithmetic Genius Program! Please enter two numbers separated by a space: ");
    scanf("%d %d", &num1, &num2); //taking user inputs for the two numbers
    printf("Please enter the desired operator (+, -, *, /): ");
    scanf(" %c", &operator); //taking user input for operator with a space before the %c
    switch(operator) { //using switch statement for different operations based on the operator
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if(num2 == 0) { //handling division by zero
                printf("Error: Cannot divide by zero!\n");
                return 0;
            }
            result = num1 / num2;
            break;
        default:
            printf("Error: Invalid operator entered. Please try again with a valid operator.\n");
            return 0;
    }
    printf("The result is: %d\n", result); //printing the result
    return 0; //ending the program
}