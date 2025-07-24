//FormAI DATASET v1.0 Category: Calculator ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main() {
    double first_number, second_number;
    char operator;
    printf("Welcome to the Calculator\n");
    printf("Please enter the first number: ");
    scanf("%lf", &first_number);
    printf("\nPlease enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);
    printf("\nPlease enter the second number: ");
    scanf("%lf", &second_number);
    printf("\n");

    switch(operator) {
        case '+': printf("The result of %.2lf + %.2lf is: %.2lf\n", first_number, second_number,first_number + second_number);
            break;
        case '-': printf("The result of %.2lf - %.2lf is: %.2lf\n", first_number, second_number,first_number - second_number);
            break;
        case '*': printf("The result of %.2lf * %.2lf is: %.2lf\n", first_number, second_number,first_number * second_number);
            break;
        case '/': 
            if(second_number == 0){
                    printf("ERROR! Division by zero\n");
                    exit(0);
            }
            printf("The result of %.2lf / %.2lf is: %.2lf\n", first_number, second_number,first_number / second_number);
            break;
        default : printf("Invalid Operator. Please try again\n");
            break;
    }

    return 0;
}