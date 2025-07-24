//FormAI DATASET v1.0 Category: Pattern printing ; Style: Ada Lovelace
#include <stdio.h>

int main() {
    int n, i, j, k = 1;
 
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    
    for(i = 0; i <= n/2; i++) {
        for(j = 1; j <= n-i; j++) {
            printf(" ");
        }
        for(j = 1; j <= k; j++) {
            printf("*");
        }
        k += 2;
        printf("\n");
    }
    
    k -= 4;
    
    for(i = n/2-1; i >= 0; i--) {
        for(j = 1; j <= n-i; j++) {
            printf(" ");
        }
        for(j = 1; j <= k; j++) {
            printf("*");
        }
        k -= 2;
        printf("\n");
    }
    
    return 0;
}