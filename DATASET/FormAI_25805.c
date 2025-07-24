//FormAI DATASET v1.0 Category: Pattern printing ; Style: future-proof
#include <stdio.h>

int main() {

    int row, col, space;

    // size of C pattern
    int size = 8;

    // upper part of C
    for(row=0; row<size; row++) {

        // first and last columns
        printf("*");

        // spaces in between
        for(space=0; space<size-2; space++) {
            if(row == 0 || row == size-1) {
                printf("*");
            } else {
                printf(" ");
            }
        }

        // last column
        printf("*\n");
    }

    // middle part of C
    for(row=0; row<size/2; row++) {

        // first columns
        printf("*");

        // spaces in between
        for(space=0; space<size-2; space++) {
            printf(" ");
        }

        // last column
        printf("*\n");
    }
    
    return 0;
}