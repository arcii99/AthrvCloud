//FormAI DATASET v1.0 Category: Pattern printing ; Style: complex
#include <stdio.h>

int main() {
    int i, j, k;
    for (i = 1; i <= 6; i++) {
        for (j = 6; j >= i; j--) {
            printf(" ");
        }
        for (k = 1; k <= i; k++) {
            if (k % 2 == 0) {
                printf("C");
            } else {
                printf("A");
            }
        }
        printf("\n");
    }
    for (i = 1; i < 6; i++) {
        for (j = 0; j <= i; j++) {
            printf(" ");
        }
        for (k = 10; k > i * 2; k--) {
            if (k % 2 == 0) {
                printf("C");
            } else {
                printf("B");
            }
        }
        printf("\n");
    }
    return 0;
}