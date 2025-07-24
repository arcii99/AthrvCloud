//FormAI DATASET v1.0 Category: Pattern printing ; Style: relaxed
#include <stdio.h>

int main() {
    int n = 6; // Variable to store the number of rows in the pattern
    int i, j; // Loop variables

    // Loop through the rows of the pattern
    for(i = 1; i <= n; i++) {
        // Print the spaces before the stars in each row
        for(j = 1; j <= n-i; j++) {
            printf(" ");
        }

        // Print the stars for the first half of the row
        for(j = 1; j <= i; j++) {
            printf("* ");
        }

        // Print the spaces between the first and second halves of the row
        for(j = 1; j <= (n-i)*2; j++) {
            printf(" ");
        }

        // Print the stars for the second half of the row
        for(j = 1; j <= i; j++) {
            printf("* ");
        }

        // Move to the next line for the next row
        printf("\n");
    }

    return 0;
}