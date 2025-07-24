//FormAI DATASET v1.0 Category: Pattern printing ; Style: statistical
#include <stdio.h>

int main() {
    printf("This program prints a unique C pattern in statistical style!\n");

    int rows = 15; // Change this value to adjust the size of the pattern
    int i, j, k;

    for (i = 1; i <= rows; i++) {
        printf("C\t"); // Prints the first column of the C pattern
        for (j = 1; j <= i; j++) {
            printf("*"); // Prints the asterisk at the bottom of the C pattern
        }
        for (k = i; k <= rows; k++) {
            printf(" "); // Prints spaces to form the left side of the C pattern
        }
        printf("*\n"); // Prints the last asterisk to complete the C pattern
    }

    for (i = rows; i >= 1; i--) {
        printf("C\t"); // Prints the first column of the C pattern
        for (j = 1; j <= i; j++) {
            printf("*"); // Prints the asterisk at the top of the C pattern
        }
        for (k = i; k <= rows; k++) {
            printf(" "); // Prints spaces to form the right side of the C pattern
        }
        printf("*\n"); // Prints the last asterisk to complete the C pattern
    }

    return 0;
}