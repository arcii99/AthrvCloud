//FormAI DATASET v1.0 Category: Pattern printing ; Style: Donald Knuth
#include <stdio.h>

int main() {
    int n, i, j, k;
    printf("Enter a number: ");
    scanf("%d", &n);

    // Upper Part
    for (i = 1; i <= n; i += 2) {
        for (j = 1; j <= ((n / 2) + 1) - (i / 2); j++) {
            printf("* "); // printing asterisk
        }

        for (j = 1; j <= i; j++) {
            if (j == 1 || j == i) {
                printf("* "); // printing asterisk
            } else {
                printf("  "); // printing space
            }
        }

        for (j = 1; j <= ((n / 2) + 1) - (i / 2); j++) {
            printf("* "); // printing asterisk
        }
        printf("\n");
    }

    // Lower Part
    for (i = n - 2; i >= 1; i -= 2) {
        for (j = 1; j <= ((n / 2) + 1) - (i / 2); j++) {
            printf("* "); // printing asterisk
        }

        for (j = 1; j <= i; j++) {
            if (j == 1 || j == i) {
                printf("* "); // printing asterisk
            } else {
                printf("  "); // printing space
            }
        }

        for (j = 1; j <= ((n / 2) + 1) - (i / 2); j++) {
            printf("* "); // printing asterisk
        }
        printf("\n");
    }

    return 0;
}