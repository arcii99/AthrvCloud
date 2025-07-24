//FormAI DATASET v1.0 Category: Pattern printing ; Style: artistic
#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    for(i = n; i >= 1; i--) {
        for(j = n; j > i; j--)
            printf("%d", j);
        for(j = 1; j <= 2 * i - 1; j++)
            printf("%d", i);
        for(j = i + 1; j <= n; j++)
            printf("%d", j);
        printf("\n");
    }
    for(i = 1; i <= n; i++) {
        for(j = n; j > i; j--)
            printf("%d", j);
        for(j = 1; j <= 2 * i - 1; j++)
            printf("%d", i);
        for(j = i + 1; j <= n; j++)
            printf("%d", j);
        printf("\n");
    }
    return 0;
}