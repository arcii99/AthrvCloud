//FormAI DATASET v1.0 Category: Pattern printing ; Style: single-threaded
#include <stdio.h>

int main() {
    int n = 15; // Number of rows and columns to print
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 || i == n || j == 1 || j == n) {
                printf("*");
            } else if (i == j || i == n - j + 1) {
                printf("O");
            } else if (i < j && i < n - j + 1) {
                printf("\\");
            } else if (i > j && i > n - j + 1) {
                printf("/");
            } else {
                printf(".");
            }
        }
        printf("\n"); // Move to next line after each row is printed
    }
    return 0;
}