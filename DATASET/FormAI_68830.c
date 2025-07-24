//FormAI DATASET v1.0 Category: Pattern printing ; Style: thoughtful
#include <stdio.h>

int main() {
    int num, i, j;

    printf("Enter a number between 1 and 26: ");
    scanf("%d", &num);

    if (num < 1 || num > 26) {
        printf("Invalid input! The number must be between 1 and 26.\n");
        return 0;
    }

    for (i = num; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("%c ", 'A' + j - 1);
        }
        printf("\n");
    }

    for (i = 2; i <= num; i++) {
        for (j = 1; j <= i; j++) {
            printf("%c ", 'A' + j - 1);
        }
        printf("\n");
    }

    return 0;
}