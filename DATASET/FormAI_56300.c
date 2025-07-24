//FormAI DATASET v1.0 Category: Pattern printing ; Style: lively
#include <stdio.h>

int main() {

    printf("Welcome to the C Pattern printing program!\n");
    printf("Let's get started with creating some fun patterns.\n");

    // First pattern - Triangle
    printf("\nTriangle:\n");
    int rows = 5;
    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= i; ++j) {
            printf("* ");
        }
        printf("\n");
    }

    // Second pattern - Diamond
    printf("\nDiamond:\n");
    rows = 5;
    int k = 0;
    for (int i = 1; i <= rows; ++i, k = 0) {
        for (int j = 1; j <= rows - i; ++j) {
            printf("  ");
        }
        while (k != 2 * i - 1) {
            printf("* ");
            ++k;
        }
        printf("\n");
    }
    for (int i = rows - 1; i >= 1; --i, k = 0) {
        for (int j = 1; j <= rows - i; ++j) {
            printf("  ");
        }
        while (k != 2 * i - 1) {
            printf("* ");
            ++k;
        }
        printf("\n");
    }

    // Third pattern - Hourglass
    printf("\nHourglass:\n");
    rows = 4;
    k = 0;
    for (int i = rows; i >= 1; --i, k = 0) {
        for (int j = 0; j < rows - i; ++j) {
            printf(" ");
        }
        while (k != 2 * i - 1) {
            printf("*");
            ++k;
        }
        printf("\n");
    }
    k = 2;
    for (int i = 2; i <= rows; ++i, k = 0) {
        for (int j = 0; j < rows - i; ++j) {
            printf(" ");
        }
        while (k != 2 * i - 1) {
            printf("*");
            ++k;
        }
        printf("\n");
    }

    printf("\nHope you enjoyed creating these beautiful patterns with C programming!\n");

    return 0;
}