//FormAI DATASET v1.0 Category: Pattern printing ; Style: curious
#include <stdio.h>

int main() {
    printf("I'm feeling curious today, so let me show you a unique pattern.\n");

    int rows, i, j, space, k = 0;

    printf("Enter the number of rows you want to print: ");
    scanf("%d", &rows);

    for (i = 1; i <= rows; ++i, k = 0) {
        for (space = 1; space <= rows - i; ++space) {
            printf("  ");
        }

        while (k != 2 * i - 1) {
            printf("* ");
            ++k;
        }

        printf("\n");
    }

    printf("Did you like it?\n");
    printf("If you want something different, let me show you another pattern.\n");

    int n = 10;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == 1 || i == n || j == 1 || j == n)
                printf("* ");
            else if (i == j || i + j == n + 1)
                printf("0 ");
            else
                printf("  ");
        }
        printf("\n");
    }

    printf("Isn't this pattern interesting too?\n");

    return 0;
}