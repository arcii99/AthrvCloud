//FormAI DATASET v1.0 Category: Pattern printing ; Style: relaxed
#include <stdio.h>

// Function to print the C pattern
void printCPattern(int num) {
    int i, j;

    // Loop to print the first row
    for (i = 0; i < num; i++) {
        printf("*");
    }

    printf("\n");

    // Loop to print the middle rows
    for (i = 0; i < num - 2; i++) {
        printf("*");

        for (j = 0; j < num - 2; j++) {
            printf(" ");
        }

        printf("*\n");
    }

    // Loop to print the last row
    for (i = 0; i < num; i++) {
        printf("*");
    }

    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of rows for the C pattern: ");
    scanf("%d", &n);

    // Check if n is valid, else prompt user to enter again
    while (n < 3) {
        printf("Invalid input! Please enter a number greater than or equal to 3: ");
        scanf("%d", &n);
    }

    // Call the function to print the pattern
    printCPattern(n);

    return 0;
}