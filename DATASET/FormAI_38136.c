//FormAI DATASET v1.0 Category: Pattern printing ; Style: artistic
#include <stdio.h>

int main() {
    int i, j, k;
    
    // First half of the pattern
    for (i = 0; i <= 5; i++) {
        for (j = 4; j >= i; j--) {
            printf(" ");
        }
        for (k = 1; k <= (2 * i + 1); k++) {
            printf("*");
        }
        printf("\n");
    }
    
    // Second half of the pattern
    for (i = 4; i >= 0; i--) {
        for (j = 4; j >= i; j--) {
            printf(" ");
        }
        for (k = 1; k <= (2 * i + 1); k++) {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}