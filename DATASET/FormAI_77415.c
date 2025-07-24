//FormAI DATASET v1.0 Category: Pattern printing ; Style: medieval
#include <stdio.h>

int main() {
    int i, j, n = 10; // n is the number of rows
    
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n");
    }
    
    for (i = n - 1; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n");
    }
    
    printf("\n");
    
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (j = 1; j <= i; j++) {
            printf("%c", i + 64);
        }
        printf("\n");
    }
    
    for (i = n - 1; i >= 1; i--) {
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (j = 1; j <= i; j++) {
            printf("%c", i + 64);
        }
        printf("\n");
    }
    
    return 0;
}