//FormAI DATASET v1.0 Category: Pattern printing ; Style: calm
#include <stdio.h>

int main() {
    int i, j, n = 10; // n is the size of the pattern
    
    // print the top of the C
    for (i = 1; i <= n/2; i++) {
        for (j = 1; j <= n; j++) {
            if (j == 1 || i == 1 || i == n/2) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    // print the stem of the C
    for (i = 1; i <= n/2 + 1; i++) {
        for (j = 1; j <= n; j++) {
            if (j == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}