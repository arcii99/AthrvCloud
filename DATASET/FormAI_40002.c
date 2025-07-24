//FormAI DATASET v1.0 Category: Pattern printing ; Style: future-proof
#include <stdio.h>
#include <stdbool.h>

int main() {
    int size, i, j, k;
    bool isAlternate = true; // flag to alternate the characters

    printf("Enter the size of the pattern: ");
    scanf("%d", &size);

    for (i = 1; i <= size; i++) {
        if (isAlternate) {
            for (j = 1, k = i; j <= i; j++, k--) {
                printf("%c ", 'a' + k - 1);
            }
        } else {
            for (j = 1, k = 1; j <= i; j++, k++) {
                printf("%c ", 'a' + k - 1);
            }
        }
        isAlternate = !isAlternate; // flip the flag
        printf("\n"); // move to the next line
    }

    return 0;
}