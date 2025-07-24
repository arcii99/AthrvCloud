//FormAI DATASET v1.0 Category: Pattern printing ; Style: puzzling
#include<stdio.h>

int main() {
    int n, m, a, b;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    m = n / 2;
    a = m;
    b = m;
    
    // Printing the top half of the pattern
    for(int i=1; i<=m+1; i++) {
        for(int j=1; j<=n; j++) {
            if(j==a || j==b) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        a--;
        b++;
        printf("\n");
    }

    // Printing the bottom half of the pattern
    a = 1;
    b = n-2;
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(j==a || j==b) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        a++;
        b--;
        printf("\n");
    }
    return 0;
}