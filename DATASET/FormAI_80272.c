//FormAI DATASET v1.0 Category: Pattern printing ; Style: puzzling
#include <stdio.h>

int main() {
    int n = 5;
    int i, j, k = 1;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= i; j++) {
            printf("%d ", k % 2);
            k++;
            if (k > 3) k = 1;
        }
        printf("\n");
    }
    return 0;
}