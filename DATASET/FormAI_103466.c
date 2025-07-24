//FormAI DATASET v1.0 Category: Pattern printing ; Style: happy
#include <stdio.h>

int main() {
    int n = 7;
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j == 0 || i == n-1 || j == i) {
                printf("H");
            } else if ((j == n-1 && i <= n/2) || (i >= n/2 && j == 0)) {
                printf("A");
            } else if (i == 0 || j == n-1 || i == j) {
                printf("P");
            } else if ((i == n/2 && j <= n/2) || (j == n/2 && i >= n/2)) {
                printf("Y");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }

    return 0;
}