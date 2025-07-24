//FormAI DATASET v1.0 Category: Pattern printing ; Style: brave
#include <stdio.h>

int main() {
    printf("I am a brave C pattern printing program!\n\n");

    int size = 10;

    // Top half of the pattern
    for (int i = 1; i <= size; i++) {
        for (int j = size; j > i; j--) {
            printf("  ");
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
            printf("* ");
        }
        printf("\n");
    }

    // Bottom half of the pattern
    for (int i = size - 1; i >= 1; i--) {
        for (int j = size - 1; j >= i; j--) {
            printf("  ");
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
            printf("* ");
        }
        printf("\n");
    }

    printf("\nI did it! I printed a brave C pattern!\n");

    return 0;
}