//FormAI DATASET v1.0 Category: Pattern printing ; Style: irregular
#include <stdio.h>

int main() {
    int i, j, k;

    for (i = 1; i <= 10; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d", j * i);
        }
        printf("\n");
    }

    printf("\n");

    for (i = 10; i >= 1; i--) {
        for (j = i; j <= 10; j++) {
            printf("%d", j - i + 1);
        }
        printf("\n");
    }

    printf("\n");

    for (i = 1; i <= 10; i++) {
        for (j = i; j <= 10; j++) {
            printf("*");
        }
        printf("\n");
    }

    printf("\n");

    for (i = 1; i <= 10; i++) {
        for (j = i; j <= 10; j++) {
            printf(" ");
        }
        for (k = 1; k <= i; k++) {
            printf("*");
        }
        printf("\n");
    }

    printf("\n");

    for (i = 1; i <= 5; i++) {
        for (j = i; j < 5; j++) {
            printf(" ");
        }
        for (k = 1; k <= 2 * i - 1; k++) {
            printf("%d", k);
        }
        printf("\n");
    }

    for (i = 4; i >= 1; i--) {
        for (j = i; j < 5; j++) {
            printf(" ");
        }
        for (k = 1; k <= 2 * i - 1; k++) {
            printf("%d", k);
        }
        printf("\n");
    }

    printf("\n");

    for (i = 1; i <= 10; i++) {
        for (j = 1; j < i; j++) {
            printf(" ");
        }
        for (k = 1; k <= 11 - i; k++) {
            printf("*");
        }
        printf("\n");
    }

    printf("\n");

    for (i = 1; i <= 10; i++) {
        for (j = i; j <= 10; j++) {
            printf("*");
        }
        printf("\n");
    }
    for (i = 9; i >= 1; i--) {
        for (j = i; j <= 10; j++) {
            printf("*");
        }
        printf("\n");
    }

    printf("\n");

    for (i = 1; i <= 10; i++) {
        for (j = 1; j <= 10; j++) {
            if (i == j) {
                printf("%d", i);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("\n");

    for (i = 1; i <= 10; i++) {
        for (j = i; j >= 1; j--) {
            printf("%d", j);
        }
        printf("\n");
    }

    printf("\n");

    for (i = 1; i <= 10; i++) {
        for (j = i; j >= 1; j--) {
            printf("%d", j % 2);
        }
        printf("\n");
    }

    printf("\n");

    for (i = 1; i <= 10; i++) {
        for (j = i; j <= 10; j++) {
            printf("%c", j + 'A' - 1);
        }
        printf("\n");
    }

    printf("\n");

    for (i = 10; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("%c", j + 'A' - 1);
        }
        printf("\n");
    }

    printf("\n");

    for (i = 1; i <= 10; i++) {
        for (j = 1; j <= i; j++) {
            printf("%c", j + 'A' - 1);
        }
        printf("\n");
    }
    for (i = 9; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("%c", j + 'A' - 1);
        }
        printf("\n");
    }

    printf("\n");

    for (i = 1; i <= 10; i++) {
        for (j = 1; j <= i; j++) {
            printf("%c", 'A' + (i - j));
        }
        printf("\n");
    }

    printf("\n");

    for (i = 10; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("%c", 'A' + (i - j));
        }
        printf("\n");
    }

    printf("\n");

    for (i = 1; i <= 10; i++) {
        for (j = i; j >= 1; j--) {
            printf("%c", 'A' + (i - j));
        }
        printf("\n");
    }
    for (i = 9; i >= 1; i--) {
        for (j = i; j >= 1; j--) {
            printf("%c", 'A' + (i - j));
        }
        printf("\n");
    }

    printf("\n");

    for (i = 1; i <= 10; i++) {
        for (j = 1; j <= i; j++) {
            printf("%c", 'A' + (j - 1));
        }
        printf("\n");
    }

    printf("\n");

    for (i = 10; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("%c", 'A' + (j - 1));
        }
        printf("\n");
    }

    printf("\n");

    for (i = 1; i <= 10; i++) {
        for (j = 1; j <= i; j++) {
            printf("%c", 'A' + (i % 26));
        }
        printf("\n");
    }

    printf("\n");

    for (i = 10; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("%c", 'A' + (i % 26));
        }
        printf("\n");
    }

    printf("\n");

    for (i = 1; i <= 10; i++) {
        for (j = i; j <= 10; j++) {
            printf("%c", 'A' + (j % 26));
        }
        printf("\n");
    }

    printf("\n");

    for (i = 10; i >= 1; i--) {
        for (j = i; j <= 10; j++) {
            printf("%c", 'A' + (j % 26));
        }
        printf("\n");
    }

    return 0;
}