//FormAI DATASET v1.0 Category: Pattern printing ; Style: imaginative
#include <stdio.h>

int main() {
    int size, i, j, k;

    printf("Enter an odd integer to determine the size of the pattern: ");
    scanf("%d", &size);
    printf("\n");

    if (size % 2 == 0) {
        printf("Please enter an odd integer!\n");
        return 0;
    }

    for (i = size / 2; i >= 0; i--) {
        for (j = 0; j < i; j++) {
            printf(" ");
        }
        printf("*");
        for (k = 0; k < size - 2 * i - 2; k++) {
            printf(" ");
        }
        printf("*\n");
    }

    for (i = 1; i <= size / 2; i++) {
        for (j = 0; j < i; j++) {
            printf(" ");
        }
        printf("*");
        for (k = 0; k < size - 2 * i - 2; k++) {
            printf(" ");
        }
        printf("*\n");
    }

    printf("\nCongratulations, you have successfully printed a unique C pattern!");
    return 0;
}