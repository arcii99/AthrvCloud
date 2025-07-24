//FormAI DATASET v1.0 Category: Error handling ; Style: introspective
#include <stdio.h>

/* Custom error handling function */
void handle_error(char* message) {
    printf("Error: %s\n", message);
    fflush(stdout);
    /* Further actions can be performed here, such as logging */
}

int divide(int num1, int num2) {
    if (num2 == 0) {
        handle_error("Cannot divide by zero.");
        return -1;
    }

    return num1 / num2;
}

int main() {
    int result = divide(10, 0);

    if (result == -1) {
        handle_error("Division failed.");
    }
    else {
        printf("Result: %d\n", result);
    }

    return 0;
}