//FormAI DATASET v1.0 Category: Pattern printing ; Style: cheerful
#include <stdio.h>

int main() {
    int rows = 7;

    printf("Hello there! Let's get printed a unique pattern of C in a cheerful way.\n\n");

    printf("Here is the C pattern printed for %d rows:\n", rows);

    // Top part of C pattern
    for (int i = 1; i <= rows; i++) {
        printf("*");
        for (int j = 1; j < rows; j++) {
            if (i == 1 || i == rows) {
                printf("*");
            } else if ((j == i - 1) || (j==rows-1)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Bottom part of C pattern
    for (int i = 1; i <= rows; i++) {
        printf("*");
    }
    printf("\n");

    printf("Hooray! We have printed the C pattern in a unique way.\n");

    return 0;
}