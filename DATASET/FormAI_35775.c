//FormAI DATASET v1.0 Category: Pattern printing ; Style: interoperable
#include <stdio.h>

int main()
{
    int i, j, k;

    // Pattern 1
    for(i = 1; i <= 5; i++) {
        for(j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    // Pattern 2
    for(i = 5; i >= 1; i--) {
        for(j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    // Pattern 3
    for(i = 1; i <= 5; i++) {
        for(j = i; j < 5; j++) {
            printf(" ");
        }
        for(k = 1; k <= i * 2 - 1; k++) {
            printf("*");
        }
        printf("\n");
    }

    // Pattern 4
    for(i = 5; i >= 1; i--) {
        for(j = i; j < 5; j++) {
            printf(" ");
        }
        for(k = 1; k <= i * 2 - 1; k++) {
            printf("*");
        }
        printf("\n");
    }

    // Pattern 5
    for(i = 1; i <= 5; i++) {
        for(j = i; j < 5; j++) {
            printf(" ");
        }
        for(k = 1; k <= i; k++) {
            printf("*");
        }
        printf("\n");
    }

    // Pattern 6
    for(i = 5; i >= 1; i--) {
        for(j = i; j < 5; j++) {
            printf(" ");
        }
        for(k = 1; k <= i; k++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}