//FormAI DATASET v1.0 Category: Pattern printing ; Style: intelligent
#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    
    // first part of the pattern
    for(int i = 0; i <= n/2; i++) {
        for(int j = n/2; j > i; j--) {
            printf(" ");
        }
        for(int k = 0; k < (2*i)+1; k++) {
            printf("*");
        }
        printf("\n");
    }

    // second part of the pattern
    for(int i = n/2; i > 0; i--) {
        for(int j = n/2; j >= i; j--) {
            printf(" ");
        }
        for(int k = 0; k < (2*i)-1; k++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}