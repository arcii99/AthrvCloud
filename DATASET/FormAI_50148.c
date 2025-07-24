//FormAI DATASET v1.0 Category: Pattern printing ; Style: lively
#include <stdio.h>

int main() {
    printf("Welcome to the C Pattern printing program!\n\n");

    // Upper half
    int i, j, k, l, m;
    for (i = 1; i <= 5; i++) {
        for (j = 5 - i; j > 0; j--) {
            printf(" ");
        }
        for (k = 1; k <= i; k++) {
            printf("%d", k);
        }
        for (l = i - 1; l > 0; l--) {
            printf("%d", l);
        }
        printf("\n");
    }

    // Lower half
    for (m = 4; m > 0; m--) {
        for (j = 5 - m; j > 0; j--) {
            printf(" ");
        }
        for (k = 1; k <= m; k++) {
            printf("%d", k);
        }
        for (l = m - 1; l > 0; l--) {
            printf("%d", l);
        }
        printf("\n");
    }

    printf("Thanks for using our program!");
    return 0;
}