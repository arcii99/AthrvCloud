//FormAI DATASET v1.0 Category: Pattern printing ; Style: retro
#include <stdio.h>

int main() {
    int n = 10;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0 || i == n - 1 || j == n - 1 || i == j || i + j == n - 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    return 0;
}