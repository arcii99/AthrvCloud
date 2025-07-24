//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Claude Shannon
#include <stdio.h>

// Function to check if a given character is a digit
int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

// Function to calculate the sum of two numbers
int add(int num1, int num2) {
    return num1 + num2;
}

// Main function
int main() {
    char input[50]; // String to store user input
    int num1 = 0, num2 = 0; // Initialize variables to store numbers
    char op; // Variable to store operator

    printf("Enter an arithmetic expression: ");
    scanf("%s", input); // Read input from user

    // Loop through each character in input
    for (int i = 0; input[i] != '\0'; i++) {
        if (is_digit(input[i])) { // If current character is a digit
            if (num1 == 0) { // If num1 is not yet set
                num1 = input[i] - '0'; // Set num1 to current digit
            } else { // If num1 is already set
                num2 = input[i] - '0'; // Set num2 to current digit
            }
        } else { // If current character is an operator (+ or -)
            op = input[i]; // Set op to current operator
        }
    }

    // Calculate result based on operator
    int result;
    if (op == '+') {
        result = add(num1, num2);
    } else {
        result = num1 - num2;
    }

    // Print result to console
    printf("Result: %d\n", result);

    return 0;
}