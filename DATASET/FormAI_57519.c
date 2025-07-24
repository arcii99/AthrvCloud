//FormAI DATASET v1.0 Category: Pattern printing ; Style: optimized
#include <stdio.h>

int main() {
    int rows = 10, cols = 10;
    int count = 0, i, j, k;
    char c = 'A';

    for (i = rows; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("%c ", c++);
        }
        c--;
        for (k = 1; k <= count; k++) {
            printf("%c ", --c);
        }
        count++;
        printf("\n");
    }

    count = rows - 1;
    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= i; j++) {
            printf("%c ", c++);
        }
        c--;
        for (k = 1; k <= count; k++) {
            printf("%c ", --c);
        }
        count--;
        printf("\n");
    }

    return 0;
}