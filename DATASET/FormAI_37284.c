//FormAI DATASET v1.0 Category: Pattern printing ; Style: Romeo and Juliet
#include <stdio.h>

int main() {
    printf("+------------------------------+\n");
    printf("| Romeo & Juliet C-Program     |\n");
    printf("+------------------------------+\n");

    int row = 1;
    int col = 1;

    while (row <= 7) {
        printf("|");

        while (col <= 7) {
            if (row == 1 || row == 7 || col == 1 || col == 7) {
                printf("*");
            } else if (row == 4 && col == 4) {
                printf("R");
            } else if ((row == 2 && col == 2) || (row == 6 && col == 6)) {
                printf("J");
            } else if ((row == 2 && col == 6) || (row == 6 && col == 2)) {
                printf("R");
            } else if ((row == 3 && col == 3) || (row == 5 && col == 5)) {
                printf("O");
            } else if ((row == 3 && col == 5) || (row == 5 && col == 3)) {
                printf("E");
            } else {
                printf(" ");
            }
            col++;
        }

        col = 1;

        printf("|");
        printf("\n");

        row++;
    }

    printf("+------------------------------+\n");

    return 0;
}