//FormAI DATASET v1.0 Category: Error handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Function declaration
void handle_error(int error_code);

int main() {
    int result;
    printf("Enter a number: ");
    scanf("%d", &result);

    if(result < 0) {
        handle_error(-1);
    }
    else if(result == 0) {
        handle_error(0);
    }
    else if(result > 100) {
        handle_error(1);
    }
    else {
        printf("Result: %d\n", result);
    }

    return 0;
}

// Function definition for error handling
void handle_error(int error_code) {
    switch(error_code) {
        case -1:
            printf("Error: Number cannot be negative. Please try again.\n");
            break;
        case 0:
            printf("Error: Number cannot be zero. Please try again.\n");
            break;
        case 1:
            printf("Error: Number cannot be greater than 100. Please try again.\n");
            break;
        default:
            printf("Error: Unknown error occurred. Please try again.\n");
            break;
    }
    exit(EXIT_FAILURE); // Always exit the program on error
}