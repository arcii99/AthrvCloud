//FormAI DATASET v1.0 Category: Pattern printing ; Style: mathematical
#include <stdio.h>
#include <math.h>

int main() {
    int n = 5;
    int i, j, k;
    int offset = 2 * n - 2;
    int num_rows = 2 * n - 1;

    for(i = 1; i <= num_rows; i++) {
        for(j = 1; j <= offset; j++) {
            printf("  ");
        }

        for(j = 1; j <= i; j++) {
            printf("%d ", j);
        }

        for(j = i - 1; j >= 1; j--) {
            printf("%d ", j);
        }

        printf("\n");
        offset -= 2;

        if(i == n) {
            break;
        }
    }

    offset = 2;

    for(i = num_rows - n; i >= 1; i--) {
        for(j = 1; j <= offset; j++) {
            printf("  ");
        }

        for(j = 1; j <= i; j++) {
            printf("%d ", j);
        }

        for(j = i - 1; j >= 1; j--) {
            printf("%d ", j);
        }

        printf("\n");
        offset += 2;
    }

    return 0;
}