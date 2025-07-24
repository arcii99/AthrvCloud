//FormAI DATASET v1.0 Category: Pattern printing ; Style: invasive
#include <stdio.h>

int main() {
    int i, j, n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    for(i=0; i<=n/2; i++) {
        for(j=0; j<=n; j++) {
            if((j==n/2-i+1) || (j==n/2+i))
                printf("*");
            else if(i==n/2 && j%2==0)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    for(i=n/2+1; i<=n; i++) {
        for(j=0; j<=n; j++) {
            if((j==i-n/2) || (j==n-i+n/2))
                printf("*");
            else if(i==n && j%2==0)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}