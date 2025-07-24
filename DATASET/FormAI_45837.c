//FormAI DATASET v1.0 Category: Pattern printing ; Style: visionary
#include <stdio.h>

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    // Top half of the pattern
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(j <= i) {
                printf("%d ", i);
            } else {
                printf("%d ", j);
            }
        }
        printf("\n");
    }

    // Bottom half of the pattern
    for(int i = n-1; i >= 1; i--) {
        for(int j = 1; j <= n; j++) {
            if(j <= i) {
                printf("%d ", i);
            } else {
                printf("%d ", j);
            }
        }
        printf("\n");
    }

    return 0;
}