//FormAI DATASET v1.0 Category: Pattern printing ; Style: complex
#include <stdio.h>

int main() {
    int n, k, i, j, c=1;
    printf("Enter number of rows: ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        for(j=0; j<n-i-1; j++) {
            printf(" ");
        }
        for(k=0; k<=i; k++) {
            if (k==0 || i==n-1) {
                printf("%d", c);
            }
            else {
                printf("*");
            }
            c++;
        }
        for(j=0; j<n-i-1; j++) {
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}