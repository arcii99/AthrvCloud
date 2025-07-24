//FormAI DATASET v1.0 Category: Data validation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUFFER_SIZE 256

void validateInput(char *input) {
    // Validate input asynchronously
    printf("Validating input...\n");
    // Simulate asynchronous operation by sleeping
    sleep(2);
    if (isdigit(input[0])) {
        printf("Input is valid.\n");
    } else {
        printf("Input is invalid. Please enter a number.\n");
    }
}

int main() {
    char buffer[BUFFER_SIZE];
    bool isValidInput = false;
    while (!isValidInput) {
        printf("Please enter a number: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        // Remove newline character
        buffer[strcspn(buffer, "\n")] = '\0';
        // Call function to validate input asynchronously
        validateInput(buffer);
        // Simulate waiting for asynchronous operation to complete
        sleep(1);
        printf("Do you want to enter another number? (Y/N): ");
        fgets(buffer, BUFFER_SIZE, stdin);
        // Remove newline character
        buffer[strcspn(buffer, "\n")] = '\0';
        if (tolower(buffer[0]) == 'n') {
            isValidInput = true;
        }
    }
    return 0;
}