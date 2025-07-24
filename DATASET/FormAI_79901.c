//FormAI DATASET v1.0 Category: Pattern printing ; Style: happy
#include <stdio.h>

int main() {

    // Happy C Pattern Printing!

    printf("\nOh happy day! Let's print some C patterns!\n\n");

    // Pattern 1
    printf("Pattern 1:\n");
    for(int i=1; i<=5; i++) {
        for(int j=1; j<=i; j++) {
            printf("C ");
        }
        printf("\n");
    }

    // Pattern 2
    printf("\nPattern 2:\n");
    int rows = 5;
    for(int i=rows; i>=1; i--) {
        for(int j=1; j<=i; j++) {
            printf("C ");
        }
        printf("\n");
    }

    // Pattern 3
    printf("\nPattern 3:\n");
    rows = 5;
    int space = rows - 1;
    for(int i=1; i<=rows; i++) {
        for(int j=1; j<=space; j++) {
            printf("  ");
        }
        space--;
        for(int j=1; j<=2*i-1; j++) {
            printf("C ");
        }
        printf("\n");
    }

    // Pattern 4
    printf("\nPattern 4:\n");
    rows = 5;
    space = 0;
    for(int i=1; i<=rows; i++) {
        for(int j=1; j<=space; j++) {
            printf("  ");
        }
        space++;
        for(int j=1; j<=2*(rows-i)-1; j++) {
            printf("C ");
        }
        printf("\n");
    }

    // Pattern 5
    printf("\nPattern 5:\n");
    int k=0;
    for(int i=1; i<=5; i++) {
        for(int j=1; j<=i+k; j++) {
            printf("C ");
        }
        k++;
        printf("\n");
    }
    k=4;
    for(int i=1; i<=4; i++) {
        for(int j=1; j<=k+i; j++) {
            printf("C ");
        }
        k--;
        printf("\n");
    }

    // Happy C Pattern Printing!
    printf("\nYay! That was fun! Let's do it again!\n");
    
    return 0;
}