//FormAI DATASET v1.0 Category: Pattern printing ; Style: enthusiastic
#include <stdio.h>

int main() {

    printf("\t\t*** Welcome to the C Pattern Printing program ***\n\n");
    printf("Today, we will print some amazing patterns using C Programming Language. So, let's start...\n\n");

    // Pattern 1
    printf("Pattern 1:\n\n");
    for(int i=1; i<=5; i++) {
        for(int j=1; j<=i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    printf("\n");

    // Pattern 2
    printf("Pattern 2:\n\n");
    for(int i=5; i>=1; i--) {
        for(int j=1; j<=i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    printf("\n");

    // Pattern 3
    printf("Pattern 3:\n\n");
    for(int i=1; i<=5; i++) {
        for(int j=1; j<=i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }

    printf("\n");

    // Pattern 4
    printf("Pattern 4:\n\n");
    for(int i=5; i>=1; i--) {
        for(int j=1; j<=i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }

    printf("\n");

    // Pattern 5
    printf("Pattern 5:\n\n");
    for(int i=1; i<=5; i++) {
        for(int j=5; j>=1; j--) {
            if(j>i) {
                printf("  ");
            }
            else {
                printf("* ");
            }
        }
        printf("\n");
    }

    printf("\n");

    // Pattern 6
    printf("Pattern 6:\n\n");
    for(int i=1; i<=5; i++) {
        for(int j=i; j<=5; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }

    printf("\n");

    printf("Wow! That was awesome. I hope you have enjoyed this C Pattern Printing program. Keep coding and stay happy! :)\n");

    return 0;
}