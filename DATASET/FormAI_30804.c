//FormAI DATASET v1.0 Category: Pattern printing ; Style: minimalist
#include <stdio.h>

int main() {
    int n = 6;
    int i, j;
    char c = 'A';

    for(i=1;i<=n;i++) {
        for(j=1;j<=i;j++) {
            printf("%c ", c++);
        }
        printf("\n");
    }
    for(i=1;i<=n;i++) {
        for(j=1;j<=n-i;j++) {
            printf("  ");
        }
        for(j=1;j<=i;j++) {
            printf("%c ", c++);
        }
        printf("\n");
    }
    for(i=1;i<=n;i++) {
        for(j=1;j<=n;j++) {
            if(j<=n-i)
                printf("  ");
            else 
                printf("%c ", c++);
        }
        printf("\n");
    }
    for(i=1;i<n;i++) {
        for(j=1;j<=i;j++) {
            printf("  ");
        }
        for(j=1;j<=n-i;j++) {
            printf("%c ", c++);
        }
        printf("\n");
    }

    return 0;
}