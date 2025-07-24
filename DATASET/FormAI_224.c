//FormAI DATASET v1.0 Category: Pattern printing ; Style: calm
#include <stdio.h>

int main() {
    int n = 4; // number of rows
    int m = 7; // number of columns

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 || i == n) {
                printf("*");
            }
            else if (j == 1 || j == m) {
                printf("*");
            }
            else if (i == j || j == m - i + 1) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}