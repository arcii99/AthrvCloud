//FormAI DATASET v1.0 Category: Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_INPUT_SIZE 1024

int main(int argc, char **argv) {

    char buffer[MAX_INPUT_SIZE];
    char operator;
    float num1, num2;
    int pos = 0, num1_pos = 0, num2_pos = 0;

    while (1) {

        printf("Enter an expression: ");

        // Asynchronous input
        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(STDIN_FILENO, &read_fds);
        select(STDIN_FILENO + 1, &read_fds, NULL, NULL, NULL);

        // Read user input
        int bytes_read = read(STDIN_FILENO, buffer, MAX_INPUT_SIZE);
        if (bytes_read < 0) {
            fprintf(stderr, "Error reading input: %s\n", strerror(errno));
            continue;
        }
        buffer[bytes_read] = '\0';

        // Check for exit condition
        if (strncmp(buffer, "exit\n", 5) == 0) {
            break;
        }

        // Parse input
        while (buffer[pos] != '\0') {
            if (isdigit(buffer[pos])) {
                if (num1_pos == 0) {
                    num1_pos = pos;
                } else if (num2_pos == 0) {
                    num2_pos = pos;
                } else {
                    fprintf(stderr, "Invalid input.\n");
                    num1_pos = 0;
                    num2_pos = 0;
                    break;
                }
            } else if (buffer[pos] == '.' || buffer[pos] == ',') {
                if (num1_pos != 0 && num2_pos == 0) {
                    num2_pos = pos;
                }
            } else if (buffer[pos] == '+' || buffer[pos] == '-' || buffer[pos] == '*' || buffer[pos] == '/') {
                if (num1_pos == 0 || num2_pos == 0) {
                    fprintf(stderr, "Invalid input.\n");
                    num1_pos = 0;
                    num2_pos = 0;
                    break;
                } else {
                    operator = buffer[pos];
                    break;
                }
            }
            pos++;
        }

        // Evaluate expression
        if (num1_pos != 0 && num2_pos != 0 && operator != '\0') {
            num1 = atof(&buffer[num1_pos]);
            num2 = atof(&buffer[num2_pos]);
            switch (operator) {
                case '+':
                    printf("%.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
                    break;
                case '-':
                    printf("%.2f - %.2f = %.2f\n", num1, num2, num1 - num2);
                    break;
                case '*':
                    printf("%.2f * %.2f = %.2f\n", num1, num2, num1 * num2);
                    break;
                case '/':
                    if (num2 == 0) {
                        fprintf(stderr, "Cannot divide by zero.\n");
                    } else {
                        printf("%.2f / %.2f = %.2f\n", num1, num2, num1 / num2);
                    }
                    break;
            }
            num1_pos = 0;
            num2_pos = 0;
            operator = '\0';
        } else {
            fprintf(stderr, "Invalid input. Please enter an expression in the format 'num1 op num2'.\n");
        }

    }

    return 0;
}