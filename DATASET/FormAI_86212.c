//FormAI DATASET v1.0 Category: Pattern printing ; Style: Romeo and Juliet
// Romeo and Juliet themed C pattern printing program

#include <stdio.h>

int main() {
    int n = 7; // Number of rows in pattern
    int i, j;

    printf("Oh Romeo, Romeo, wherefore art thou Romeo?\n"); // Shakespearean opening line

    for (i = 1; i <= n; i++) { // Outer loop for rows
        for (j = 1; j <= n; j++) { // Inner loop for columns
            if (i == 1 || i == n || j == 1 || j == n || i == j || j == n-i+1) {
                // If on the first, last, or diagonal row/column, or on the opposite diagonal
                printf("* ");
            } else {
                printf("  "); // Print spaces for non-star positions
            }
        }
        printf("\n"); // Move to next row
    }

    printf("What's in a name? That which we call a rose, By any other name would smell as sweet.\n");
    // Famous Juliet monologue

    return 0;
}