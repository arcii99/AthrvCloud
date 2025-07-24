//FormAI DATASET v1.0 Category: Pattern printing ; Style: post-apocalyptic
#include <stdio.h>

int main() {
    printf("After the apocalypse, only the strongest will survive.\n\n");

    // Top section of the pattern
    for(int i = 5; i >= 1; i--) {
        for(int j = i; j >= 1; j--) {
            printf("%d ", j);
        }

        for(int j = 1; j <= 10 - 2 * i; j++) {
            printf("* ");
        }

        for(int j = 1; j <= i; j++) {
            printf("%d ", j);
        }

        printf("\n");
    }

    // Middle section of the pattern
    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= i; j++) {
            printf("%d ", j);
        }

        for(int j = 1; j <= 10 - 2 * i; j++) {
            printf("* ");
        }

        for(int j = i; j >= 1; j--) {
            printf("%d ", j);
        }

        printf("\n");
    }

    // Bottom section of the pattern
    for(int i = 4; i >= 1; i--) {
        for(int j = i; j >= 1; j--) {
            printf("%d ", j);
        }

        for(int j = 1; j <= 10 - 2 * i; j++) {
            printf("* ");
        }

        for(int j = 1; j <= i; j++) {
            printf("%d ", j);
        }

        printf("\n");
    }

    return 0;
}