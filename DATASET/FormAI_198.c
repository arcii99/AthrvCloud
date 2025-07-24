//FormAI DATASET v1.0 Category: Pattern printing ; Style: scientific
#include <stdio.h>

int main() {
    int n = 5; // size of the pattern
    int i, j, k, l; // loop variables
    
    // first half of the pattern
    for (i = 1; i <= n; i++) {
        // print leading spaces
        for (j = n; j > i; j--) {
            printf(" ");
        }
        // print the stars
        for (k = 1; k <= i; k++) {
            printf("* ");
        }
        printf("\n");
    }
    
    // second half of the pattern
    for (i = n-1; i >= 1; i--) {
        // print leading spaces
        for (j = n; j > i; j--) {
            printf(" ");
        }
        // print the stars
        for (k = 1; k <= i; k++) {
            printf("* ");
        }
        printf("\n");
    }
    
    return 0;
}