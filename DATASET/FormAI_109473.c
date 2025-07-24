//FormAI DATASET v1.0 Category: Game ; Style: Linus Torvalds
#include <stdio.h>

// Main function
int main() {
    short i, j, k;
    int rows;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    // Iterate through each row
    for (i = 1; i <= rows; ++i) {
        // Print spaces in each row
        for (j = 1; j <= rows - i; ++j) {
            printf("   ");
        }

        // Print numbers in each row
        k = 0;
        while (k != 2 * i - 1) {
            printf("%d  ", i);
            ++k;
        }

        printf("\n");
    }

    return 0;
}