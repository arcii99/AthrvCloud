//FormAI DATASET v1.0 Category: Pattern printing ; Style: interoperable
#include <stdio.h>

int main() {
    int size, i, j;
    printf("Enter the size of the pattern: ");
    scanf("%d", &size);

    // First Section
    for (i = size; i >= 1; i--) {
        for (j = 1; j <= i; j++)
            printf("%d ", j);
        printf("\n");
    }

    // Second Section
    for (i = 2; i <= size; i++) {
        for (j = 1; j <= i; j++)
            printf("%d ", j);
        printf("\n");
    }

    // Third Section
    for (i = 1; i <= size; i++) {
        for (j = 1; j <= size; j++) {
            if (j == i || j == size - i + 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }

    // Fourth Section
    for (i = size; i >= 1; i--) {
        for (j = 1; j <= i; j++)
            printf("%d ", size - j + 1);
        printf("\n");
    }

    return 0;
}