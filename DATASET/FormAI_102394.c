//FormAI DATASET v1.0 Category: Pattern printing ; Style: automated
#include <stdio.h>

int main() {
    int i, j, k, l;
    for (i = 1; i <= 5; i++) {
        for (j = 5; j > i; j--) {
            printf(" ");
        }
        for (k = 1; k <= i; k++) {
            printf("%d", k);
        }
        for (l = i - 1; l >= 1; l--) {
            printf("%d", l);
        }
        printf("\n");
    }
    for (i = 1; i <= 4; i++) {
        for (j = 1; j <= i; j++) {
            printf(" ");
        }
        for (k = 1; k <= 5 - i; k++) {
            printf("%d", k);
        }
        for (l = 4 - i; l >= 1; l--) {
            printf("%d", l);
        }
        printf("\n");
    }
    return 0;
}