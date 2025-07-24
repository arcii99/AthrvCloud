//FormAI DATASET v1.0 Category: Pattern printing ; Style: mathematical
#include <stdio.h>

int main(){
    int i, j, k, n = 10;

    // Top part of C
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == 0 || j == 0 || j == n - 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    // Bottom part of C
    for (i = 0; i <= n/2; i++) {
        for (j = 0; j < (n/2)-i+1; j++) {
            printf("  ");
        }
        for (k = 0; k < i*2-1; k++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}