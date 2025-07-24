//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows, columns;

    // Prompt user to enter rows and columns
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &columns);

    srand(time(NULL)); // Set random seed based on current time

    // Loop through each row
    for(int i = 1; i <= rows; i++) {
        // Loop through each column
        for(int j = 1; j <= columns; j++) {
            int r = rand() % 3; // Generate random number between 0 and 2

            // Print corresponding character based on random number
            if(r == 0)
                printf("█");
            else if(r == 1)
                printf("▒");
            else
                printf("░");
        }
        printf("\n"); // Newline after each row
    }

    return 0;
}