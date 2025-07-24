//FormAI DATASET v1.0 Category: Pattern printing ; Style: mathematical
#include <stdio.h>

int main() {
    int rows = 9;
    int cols = 15;
    int num = 9;
    int count = 0;

    // upper half of pattern
    for (int i = 1; i <= rows/2; i++) {
        for (int j = 1; j <= cols; j++) {
            if (j == i || j == cols-i+1) {
                printf("%d", num);
            } else {
                printf(" ");
            }
        }
        num--;
        printf("\n");
    }

    // middle row of pattern
    for (int j = 1; j <= cols; j++) {
        printf("%d", num);
        num--;
    }
    num = 1;
    printf("\n");

    // lower half of pattern
    for (int i = rows/2+2; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            if (j == i || j == cols-i+1) {
                printf("%d", num);
            } else {
                printf(" ");
            }
        }
        num++;
        printf("\n");
    }

    return 0;
}