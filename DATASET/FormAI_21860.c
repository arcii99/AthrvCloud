//FormAI DATASET v1.0 Category: Pattern printing ; Style: retro
#include <stdio.h>
int main() {
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    for (i = 10; i > 0; i--) {
        for (j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }
    for (i = 1; i <= 10; i++) {
        for (j = 1; j <= 10; j++) {
            if (i == j || j == 10 - i + 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    for (i = 1; i <= 10; i++) {
        for (j = 1; j <= 10; j++) {
            if (i == 1 || i == 10 || j == 1 || j == 10) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    for (i = 1; i <= 10; i++) {
        for (j = 1; j <= 21; j++) {
            if (j >= 11 - i && j <= 11 + i) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}