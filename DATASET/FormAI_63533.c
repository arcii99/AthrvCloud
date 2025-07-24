//FormAI DATASET v1.0 Category: Pattern printing ; Style: introspective
#include <stdio.h>

int main() {
    // get user input for pattern size
    printf("Enter pattern size: ");
    int size;
    scanf("%d", &size);
    printf("\n");

    // check if pattern size is within valid range
    if (size < 1 || size > 26) {
        printf("Invalid pattern size\n");
        return 0;
    }

    // print the top half of the pattern
    for (int i = size; i >= 1; i--) {
        // print spaces for padding
        for (int j = 0; j < i-1; j++) {
            printf(" ");
        }

        // print letters in decreasing order
        for (int k = i-1; k < size; k++) {
            printf("%c ", 64 + k);
        }

        printf("\n");
    }

    // print the bottom half of the pattern
    for (int i = 1; i <= size; i++) {
        // print spaces for padding
        for (int j = 0; j < i-1; j++) {
            printf(" ");
        }

        // print letters in increasing order
        for (int k = i-1; k < size; k++) {
            printf("%c ", 64 + k);
        }

        printf("\n");
    }

    return 0;
}