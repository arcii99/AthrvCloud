//FormAI DATASET v1.0 Category: Pattern printing ; Style: detailed
#include <stdio.h>

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Top pattern
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            printf("%d ", j);
        }
        for(int j=i+1; j<=n; j++) {
            printf("%d ", i);
        }
        printf("\n");
    }

    // Bottom pattern
    for(int i=n; i>=1; i--) {
        for(int j=1; j<=i; j++) {
            printf("%d ", j);
        }
        for(int j=i+1; j<=n; j++) {
            printf("%d ", i);
        }
        printf("\n");
    }

    return 0;
}