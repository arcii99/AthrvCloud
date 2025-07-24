//FormAI DATASET v1.0 Category: Pattern printing ; Style: calm
#include <stdio.h>

int main() {
    int i, j, k;
    int spaces = 1;
    int rows = 20; // Change the number of rows as required
    for (i = 1; i <= rows; i++) {
        if (i == 1 || i == rows) { // First and last rows
            for (j = i; j < rows; j++) {
                printf(" ");
            }
            for (j = 1; j <= i; j++) {
                printf("*");
            }
        }
        else if (i <= rows / 2 + 1) { // Rows before the middle row
            for (j = i; j < rows; j++) {
                printf(" ");
            }
            printf("*");
            for (j = 1; j <= spaces; j++) {
                printf(" ");
            }
            printf("*");
            spaces += 2;
        }
        else { // Rows after the middle row
            if (i == rows / 2 + 2) { // Middle row
                for (j = 1; j <= i - 1; j++) {
                    printf(" ");
                }
                printf("*");
            }
            else {
                for (j = 1; j <= i - 1; j++) {
                    printf(" ");
                }
                printf("*");
                for (j = 1; j <= spaces; j++) {
                    printf(" ");
                }
                printf("*");
                spaces -= 2;
            }
        }
        printf("\n");
    }
    return 0;
}