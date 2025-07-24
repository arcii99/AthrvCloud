//FormAI DATASET v1.0 Category: Error handling ; Style: irregular
#include<stdio.h>
#include<stdlib.h>

// Custom error handler function
void handleError(const char* message) {
    printf("\n\n");
    printf("ERROR OCCURRED\n");
    printf("===================================\n");
    printf("%s\n", message);
    printf("===================================\n");

    // Ask user if they want to exit or continue
    printf("Enter 'e' to Exit or 'c' to Continue: ");
    char choice = getchar();
    fflush(stdin);
    printf("\n");
    if (choice == 'e') {
        printf("Exiting...\n");
        exit(1);
    }
}

int main() {
    int x, y;

    printf("Enter two numbers to divide: ");
    if (scanf("%d %d", &x, &y) != 2) {
        handleError("Invalid input, expected two integers.");
    }

    if (y == 0) {
        handleError("Division by zero error.");
    }

    int result = x / y;

    if (result > 100) {
        handleError("Result is greater than 100, program terminating...");
    }

    printf("%d divided by %d is %d\n", x, y, result);
    printf("Program exiting successfully.\n");

    return 0;
}