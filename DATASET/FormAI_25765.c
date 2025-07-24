//FormAI DATASET v1.0 Category: Pattern printing ; Style: grateful
// Hey there, let's print a beautiful pattern!
#include <stdio.h>

int main() {
    int num_rows = 5;
    int num_cols = num_rows;
    int middle_row = (num_rows + 1) / 2;

    printf("Thank you for choosing this program to print a unique pattern!\n\n");

    for (int row = 1; row <= num_rows; row++) {
        for (int col = 1; col <= num_cols; col++) {
            if (row == middle_row) {
                printf("*");
            } else if (col == 1 || col == num_cols) {
                printf("*");
            } else if ((row < middle_row && col == row) || (row > middle_row && col == num_cols - row + 1)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("\nWow, your pattern is now complete! Thank you for using this program!\n");

    return 0;
}