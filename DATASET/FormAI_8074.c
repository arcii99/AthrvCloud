//FormAI DATASET v1.0 Category: Pattern printing ; Style: beginner-friendly
#include <stdio.h>

int main() {
    int rows = 5;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <= i; j++) {
            printf(" ");
        }

        for (int j = i; j < rows; j++) {
            printf("*");
        }

        printf("\n");
    }

    for (int i = rows; i > 0; i--) {
        for (int j = 0; j < i - 1; j++) {
            printf(" ");
        }

        for (int j = i; j <= rows; j++) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}