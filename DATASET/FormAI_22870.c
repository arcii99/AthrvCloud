//FormAI DATASET v1.0 Category: Pattern printing ; Style: happy
#include <stdio.h>

int main() {

    printf("Happy C Pattern Printing!\n");

    // first pattern
    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n");
    }

    // newline separator
    printf("\n");

    // second pattern
    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= i; j++) {
            printf("%d", i);
        }
        printf("\n");
    }

    // newline separator
    printf("\n");

    // third pattern
    for(int i = 5; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n");
    }

    // newline separator
    printf("\n");

    // fourth pattern
    for(int i = 5; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {
            printf("%d", i);
        }
        printf("\n");
    }

    // newline separator
    printf("\n");

    // fifth pattern
    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= 5; j++) {
            if(j >= i) {
                printf("%d", j);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("\nThat's all for now folks!\n");

    return 0;
}