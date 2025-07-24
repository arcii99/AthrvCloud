//FormAI DATASET v1.0 Category: Pattern printing ; Style: peaceful
#include <stdio.h>

int main() {
    int rows = 10, columns = 10, i, j;
    char pattern = '*';

    // Start pattern printing
    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= columns; j++) {
            if ((i == 1 || i == rows) || (j == 1 || j == columns)) {
                printf("%c ", pattern);
            } else if (i == j || i == (columns - j + 1)) {
                printf("%c ", pattern);
            } else if ((i >= (rows / 2) - 1 && i <= (rows / 2) + 1) && (j >= (columns / 2) - 1 && j <= (columns / 2) + 1)) {
                printf("%c ", pattern);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    return 0;
}