//FormAI DATASET v1.0 Category: Pattern printing ; Style: rigorous
#include <stdio.h>

int main() {
    int n = 7; // change value of n here to adjust the size of the pattern
    int i, j, k;
    for (i=0; i<n; i++) {
        // upper half of the pattern
        for (j=0; j<i; j++) {
            printf(" ");
        }
        for (k=0; k<2*(n-i)-1; k++) {
            printf("*");
        }
        printf("\n");
    }
    for (i=n-2; i>=0; i--) {
        // lower half of the pattern
        for (j=0; j<i; j++) {
            printf(" ");
        }
        for (k=0; k<2*(n-i)-1; k++) {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}