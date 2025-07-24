//FormAI DATASET v1.0 Category: Pattern printing ; Style: unmistakable
#include <stdio.h>

int main() {
    int n = 10; //number of rows

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i==1 || i==n || j==1 || j==n) {
                printf("* ");
            }
            else if(i<=n/2 && j>i && j<=n-i+1) {
                printf("* ");
            }
            else if(i>n/2 && j<=i && j>=n-i+1) {
                printf("* ");
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }

    return 0;
}