//FormAI DATASET v1.0 Category: Educational ; Style: optimized
#include<stdio.h>

int main() {

    int n, i, j, space;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printf("\n\n");
    
    for(i=1; i<=n; i++) {
        for(space=1; space<=n-i; space++) {
            printf("  ");
        }
        for(j=1; j<=i; j++) {
            printf("%d ", j);
        }
        for(j=i-1; j>=1; j--) {
            printf("%d ", j);
        }
        printf("\n");
    }
    
    printf("\n\n");
    return 0;
}