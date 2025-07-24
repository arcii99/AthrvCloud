//FormAI DATASET v1.0 Category: Pattern printing ; Style: secure
#include <stdio.h>

int main() {
    int n = 7;

    // upper half of the pattern
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    // lower half of the pattern
    for(int i=n-1; i>=0; i--) {
        for(int j=0; j<=i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}