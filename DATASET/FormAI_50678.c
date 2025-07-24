//FormAI DATASET v1.0 Category: Pattern printing ; Style: portable
#include<stdio.h>

int main() {

    int pattern_length, i, j, k;

    printf("Enter Pattern Length: ");
    scanf("%d", &pattern_length);

    for (i = 0; i < pattern_length; i++) {

        for (j = 0; j <= i; j++) {
            printf("* ");
        }

        printf("\n");
    }

    for (i = pattern_length; i > 0; i--) {

        for (j = 1; j < i; j++) {
            printf("* ");
        }

        printf("\n");

        for (k = 0; k < pattern_length - i + 1; k++) {
            printf("  ");
        }
    }

    return 0;
}