//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846

int main(void)
{
    char input[100];
    double result;

    printf("Welcome to the Linux Scientific Calculator!\n");

    while (1) {
        printf("Enter an expression (or 'quit' to exit): ");
        fgets(input, 100, stdin);

        if (strncmp(input, "quit", 4) == 0)
            break;

        // tokenize the input
        char *tokens[25];
        int num_tokens = 0;

        char *token = strtok(input, " ");
        while (token != NULL) {
            tokens[num_tokens++] = token;
            token = strtok(NULL, " ");
        }

        // perform the calculation
        double a, b;
        if (num_tokens == 3) {

            a = atof(tokens[0]);
            b = atof(tokens[2]);

            if (tokens[1][0] == '+') {
                result = a + b;
            } else if (tokens[1][0] == '-') {
                result = a - b;
            } else if (tokens[1][0] == '*') {
                result = a * b;
            } else if (tokens[1][0] == '/') {
                result = a / b;
            } else if (tokens[1][0] == '^') {
                result = pow(a, b);
            } else {
                printf("Invalid operator!\n");
                continue;
            }

            printf("Result: %f\n", result);

        } else if (num_tokens == 2) {

            a = atof(tokens[1]);

            if (strncmp(tokens[0], "sin", 3) == 0) {
                result = sin(a);
            } else if (strncmp(tokens[0], "cos", 3) == 0) {
                result = cos(a);
            } else if (strncmp(tokens[0], "tan", 3) == 0) {
                result = tan(a);
            } else if (strncmp(tokens[0], "sqrt", 4) == 0) {
                result = sqrt(a);
            } else if (strncmp(tokens[0], "log", 3) == 0) {
                result = log10(a);
            } else if (strncmp(tokens[0], "ln", 2) == 0) {
                result = log(a);
            } else {
                printf("Invalid function!\n");
                continue;
            }

            printf("Result: %f\n", result);

        } else {
            printf("Invalid input!\n");
            continue;
        }
    }

    return 0;
}