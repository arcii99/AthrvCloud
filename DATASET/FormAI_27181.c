//FormAI DATASET v1.0 Category: Pattern printing ; Style: introspective
#include <stdio.h>

int main() {
    printf("Hello! I am a C program that writes a unique pattern.\n");

    // variable declaration
    int rows = 7;
    int columns = 7;
    int mid_row = rows / 2;
    int mid_col = columns / 2;

    // loop to print rows
    for (int i=0; i<rows; i++) {
        // loop to print columns
        for (int j=0; j<columns; j++) {
            // conditions to check and print either 'C' or space
            if (i < mid_row && j == 0) {
                printf("C ");
            } 
            if (i == mid_row && j == 0) {
                printf("C ");
            }
            if (i > mid_row && j == mid_col) {
                printf("C ");
            }
            if (i == mid_row && j == columns-1) {
                printf("C ");
            }
            if (i < mid_row && j == columns-1) {
                printf("C ");
            }
            if (i == 0 && j > 0 && j < mid_col) {
                printf("C ");
            }
            if (i == rows-1 && j > mid_col && j < columns-1) {
                printf("C ");
            }
            else {
                printf("  ");
            }
        }
        // printing a new line after each row
        printf("\n");
    }
    return 0;
}