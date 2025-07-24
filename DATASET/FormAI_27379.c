//FormAI DATASET v1.0 Category: Pattern printing ; Style: retro
#include <stdio.h>

int main() {
    int rows = 6;

    int i, j, k;
    
    for (i = 0; i < rows; i++) {
        // Pattern 1 - Triangle
        for (j = rows-i; j > 0; j--) {
            printf(" ");
        }
        for (k = 0; k <= i; k++) {
            printf("* ");
        }
        printf("\n");
        
        // Pattern 2 - Cross
        for (j = 0; j < rows; j++) {
            if (j == i || j == rows-i-1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
        
        // Pattern 3 - Arrow
        if (i < rows/2) {
            for (j = 0; j <= i; j++) {
                printf("*");
            }
        } else {
            for (j = 0; j < rows-i; j++) {
                printf("*");
            }
        }
        printf("\n");
        
        // Pattern 4 - Diamond
        if (i <= rows/2) {
            for (j = rows-i; j > 0; j--) {
                printf(" ");
            }
            for (k = 0; k <= i; k++) {
                printf("* ");
            }
        } else {
            for (j = 0; j <= i-rows/2; j++) {
                printf(" ");
            }
            for (k = rows-i; k > 0; k--) {
                printf("* ");
            }
        }
        printf("\n");
    }
    return 0;
}