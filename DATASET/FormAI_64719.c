//FormAI DATASET v1.0 Category: Pattern printing ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, k, n;
    printf("Enter a number greater than 2: ");
    scanf("%d", &n);
    if(n<=2) {   //check if input is greater than 2
        printf("Invalid input\n");
        return 0;
    }
    for(i=1; i<=n; i++) {
        if(i==1 || i==n) {  //for top and bottom row print "*" n-times
            for(j=1; j<=n; j++) {
                printf("* ");
            }
        }
        else if(i%2==0) { //for even numbered rows, print reverse triangle
            for(j=n-i+1; j>=1; j--) {
                printf("* ");
            }
        }
        else {  //for odd numbered rows, print regular triangle
            for(j=1; j<=i; j++) {
                printf("* ");
            }
        }
        printf("\n");
    }
    return 0;
}