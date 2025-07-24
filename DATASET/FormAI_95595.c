//FormAI DATASET v1.0 Category: Arithmetic ; Style: configurable
#include <stdio.h>

// Function to perform operations based on the given operator
int calculate(int num1, int num2, char operator) {
    if(operator == '+') {
        return num1 + num2;
    }
    else if(operator == '-') {
        return num1 - num2;
    }
    else if(operator == '*') {
        return num1 * num2;
    }
    else if(operator == '/') {
        return num1 / num2;
    }
    else {
        printf("Invalid Operator!\n");
        return 0;
    }
}

int main() {
    int num1, num2, result;
    char operator;

    printf("Enter a number: ");
    scanf("%d", &num1);

    printf("Enter another number: ");
    scanf("%d", &num2);

    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);

    // Perform the calculation and store the result
    result = calculate(num1, num2, operator);

    // Output the result
    printf("%d %c %d = %d\n", num1, operator, num2, result);

    return 0;
}