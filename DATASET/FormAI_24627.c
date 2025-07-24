//FormAI DATASET v1.0 Category: Pattern printing ; Style: calm
#include <stdio.h>

int main() {
    int size;
    printf("Enter the size of the pattern: ");
    scanf("%d", &size);

    // Upper triangle
    for (int i = 0; i < size; i++) {
        // Spaces
        for (int j = i; j < size - 1; j++) {
            printf(" ");
        }
        // Stars
        for (int j = 0; j < 2 * i + 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    // Lower triangle
    for (int i = size - 2; i >= 0; i--) {
        // Spaces
        for (int j = i; j < size - 1; j++) {
            printf(" ");
        }
        // Stars
        for (int j = 0; j < 2 * i + 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}