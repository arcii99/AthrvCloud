//FormAI DATASET v1.0 Category: Pattern printing ; Style: retro
#include <stdio.h>

int main() {
    int i, j;
    char c = 'C';

    for (i = 1; i <= 5; i++) {
        for (j = 1; j <= i; j++) {
            printf("%c ", c);
        }
        printf("\n");
    }

    for (i = 4; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("%c ", c);
        }
        printf("\n");
    }

    for (i = 1; i <= 4; i++) {
        for (j = 1; j <= i; j++) {
            printf("  ");
        }
        for (j = 4; j >= i; j--) {
            printf("%c ", c);
        }
        printf("\n");
    }

    for (i = 1; i <= 4; i++) {
        for (j = 4; j >= i; j--) {
            printf("  ");
        }
        for (j = 1; j <= i; j++) {
            printf("%c ", c);
        }
        printf("\n");
    }

    return 0;
}