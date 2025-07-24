//FormAI DATASET v1.0 Category: Pattern printing ; Style: surprised
#include <stdio.h>

int main() {
    printf("Wow, I can't believe I did it!\n");
    int rows = 5;
    int i, j, k;
    for (i = 1; i <= rows; i++) {
        for (j = 1; j < i; j++) {
            printf(" ");
        }
        for (k = 1; k <= (rows - i + 1); k++) {
            printf("* ");
        }
        printf("\n");
    }

    printf("\n");

    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= (rows - i); j++) {
            printf(" ");
        }
        for (k = 1; k < (2 * i); k++) {
            printf("*");
        }
        printf("\n");
    }

    printf("\n");

    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= (rows - i); j++) {
            printf(" ");
        }
        for (k = i; k >= 1; k--) {
            printf("%d", k);
        }
        for (k = 2; k <= i; k++) {
            printf("%d", k);
        }
        printf("\n");
    }

    printf("\n");

    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= (rows - i); j++) {
            printf(" ");
        }
        for (k = i; k >= 1; k--) {
            printf("%c", 64 + k);
        }
        for (k = 2; k <= i; k++) {
            printf("%c", 64 + k);
        }
        printf("\n");
    }

    printf("\n");

    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= (rows - i); j++) {
            printf(" ");
        }
        for (k = i; k >= 1; k--) {
            printf("%c", 64 + rows - k + 1);
        }
        for (k = 2; k <= i; k++) {
            printf("%c", 64 + rows - k + 1);
        }
        printf("\n");
    }

    return 0;
}