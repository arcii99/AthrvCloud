//FormAI DATASET v1.0 Category: Pattern printing ; Style: expert-level
#include <stdio.h>

int main() {
    // Welcome message
    printf("Hello! Welcome to the C Pattern Printing Program.\n\n");

    int rows = 0; // Number of rows
    int columns = 0; // Number of columns

    // Get user input for number of rows and columns
    printf("Please enter the number of rows (1-10): ");
    scanf("%d", &rows);
    printf("Please enter the number of columns (1-10): ");
    scanf("%d", &columns);

    // Validate user input
    if (rows < 1 || rows > 10) {
        printf("Invalid number of rows. Please enter a value between 1 and 10.\n");
        return 1;
    }

    if (columns < 1 || columns > 10) {
        printf("Invalid number of columns. Please enter a value between 1 and 10.\n");
        return 1;
    }

    printf("\n"); // Add some whitespace for readability

    // Print the pattern
    for (int i = 1; i <= rows; i++) {
        // Print spaces for each row
        for (int j = 1; j <= (rows - i); j++) {
            printf(" ");
        }

        // Print digits for each row
        for (int k = 1; k < (2*i); k++) {
            printf("%d", i);
        }

        printf("\n"); // Move to the next row
    }

    // Thank you message
    printf("\nThank you for using the C Pattern Printing Program.\n");

    return 0;
}