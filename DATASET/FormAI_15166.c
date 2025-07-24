//FormAI DATASET v1.0 Category: Pattern printing ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, k, l;

    printf("Welcome to the surreal C pattern printer!\n");

    for (i = 1; i <= 5; i++) {
        for (j = 1; j <= i; j++) {
            for (k = 1; k <= i + j; k++) {
                if (k <= i) {
                    printf("%d", i);
                } else {
                    printf("%d", j);
                }
            }
            printf("\n");
        }
        for (l = 1; l <= i; l++) {
            for (k = 1; k <= i + l; k++) {
                if (k <= i) {
                    printf("%d", l);
                } else {
                    printf("%d", i);
                }
            }
            printf("\n");
        }
    }

    printf("Congratulations, you have printed a surreal C pattern!\n");

    return 0;
}