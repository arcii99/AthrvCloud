//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_INPUT_LEN 50

int main() {
    char input[MAX_INPUT_LEN];
    double angle;
    double num1, num2;
    double result;
    char operator;

    printf("Welcome to my scientific calculator!\n");

    while (1) {
        // Take user input
        printf("Enter equation (or q to quit): ");
        if (fgets(input, MAX_INPUT_LEN, stdin) == NULL) {
            printf("Error reading input.\n");
            continue;
        }
        input[strcspn(input, "\n")] = 0; // Remove trailing newline

        // Check if user wants to quit
        if (input[0] == 'q' && strlen(input) == 1) {
            printf("Goodbye!\n");
            break;
        }

        // Parse input
        if (sscanf(input, "%lf %c %lf", &num1, &operator, &num2) != 3) {
            printf("Invalid input.\n");
            continue;
        }

        // Calculate result based on operator
        switch (operator) {
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
                if (num2 == 0) {
                    printf("Error: division by zero.\n");
                    continue;
                }
                result = num1 / num2;
                break;
            case '^':
                result = pow(num1, num2);
                break;
            case 's':
                angle = num2 * M_PI / 180; // Convert degrees to radians
                result = num1 * sin(angle);
                break;
            case 'c':
                angle = num2 * M_PI / 180; // Convert degrees to radians
                result = num1 * cos(angle);
                break;
            case 't':
                angle = num2 * M_PI / 180; // Convert degrees to radians
                result = num1 * tan(angle);
                break;
            default:
                printf("Invalid operator.\n");
                continue;
        }

        // Print result
        printf("= %lf\n", result);
    }

    return 0;
}