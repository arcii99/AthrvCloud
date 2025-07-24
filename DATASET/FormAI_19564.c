//FormAI DATASET v1.0 Category: Pattern printing ; Style: enthusiastic
#include <stdio.h>
int main() {
    int rows = 11; // the number of rows in the pattern
    int cols = 21; // the number of columns in the pattern
    int middle_row = rows / 2; // the middle row of the pattern
    int middle_col = cols / 2; // the middle column of the pattern
    int x, y; // loop counters

    // nested loops to print out the pattern
    for (x = 0; x <= rows; x++) {
        for (y = 0; y <= cols; y++) {
            if (x < middle_row && y < middle_col) {
                printf("+");
            } else if (x < middle_row && y > middle_col) {
                printf("-");
            } else if (x > middle_row && y < middle_col) {
                printf("/");
            } else if (x > middle_row && y > middle_col) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n"); // move to the next row
    }
    return 0;
}