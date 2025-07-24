//FormAI DATASET v1.0 Category: Pattern printing ; Style: energetic
#include <stdio.h>

int main() {
    int rows = 6;
    int cols = (2 * rows) - 1;
    int i, j, k;
    char letter = 'C';

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (i == 0 || i == rows - 1 || (i == j && j < rows) || j == 0) {
                printf("%c", letter);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (i == 0 || i == rows - 1 || (j == cols - i - 1 && j < rows)) {
                printf("%c", letter);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}