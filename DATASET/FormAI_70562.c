//FormAI DATASET v1.0 Category: Pattern printing ; Style: bold
#include<stdio.h>

int main() {

    int row, col, rows, cols, space;

    rows = 10;

    cols = 10;

    // top row

    for (col = 0; col < cols; col++) {

        printf("\033[1m*\033[0m ");

    }

    printf("\n");

    // This loop prints the middle section of the pattern

    for (row = 1; row < rows - 1; row++) {

        // print the first star in each row

        printf("\033[1m*\033[0m ");

        // print the spaces in between the stars

        for (space = 1; space < row; space++) {

            printf("  ");

        }

        // print the stars after the spaces

        printf("\033[1m*\033[0m");

        // print the spaces after the stars

        for (space = row + 1; space < rows - 1; space++) {

            printf("  ");

        }

        // print the last star in each row

        printf(" \033[1m*\033[0m ");

        printf("\n");

    }

    // bottom row

    for (col = 0; col < cols; col++) {

        printf("\033[1m*\033[0m ");

    }

    printf("\n");

    return 0;
}