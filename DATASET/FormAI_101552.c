//FormAI DATASET v1.0 Category: Pattern printing ; Style: genious
#include <stdio.h>

int main() {
    // Welcome user
    printf("Welcome to the C pattern printing program! Let's get started...\n\n");

    // Define variables
    int num_rows, i, j, k;

    // Ask user for input
    printf("Please enter the number of rows you would like to print: ");
    scanf("%d", &num_rows);

    // Validate input
    if (num_rows < 1) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 0;
    }

    // Print first half of pattern
    for (i = 1; i <= num_rows; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d", j);
        }
        for (k = i; k <= num_rows; k++) {
            printf("*");
        }
        printf("\n");
    }

    // Print second half of pattern
    for (i = 1; i <= num_rows; i++) {
        for (j = 1; j <= num_rows - i + 1; j++) {
            printf("%d", j);
        }
        for (k = 1; k <= i - 1; k++) {
            printf("*");
        }
        printf("\n");
    }

    // Goodbye message
    printf("\nThanks for using the C pattern printing program. Goodbye!");

    return 0;
}