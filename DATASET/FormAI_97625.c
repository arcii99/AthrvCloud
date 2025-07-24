//FormAI DATASET v1.0 Category: Pattern printing ; Style: scalable
#include <stdio.h>

int main() {
    // Get user input for the size of the pattern
    int size;
    printf("Enter the size of the pattern: ");
    scanf("%d", &size);

    // Generate the pattern
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            // The pattern will be a capital C
            if (j == 1 || (i == 1 && j <= size/2) || (i == size && j <= size/2) || (i == j && i > size/2)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}