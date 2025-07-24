//FormAI DATASET v1.0 Category: Pattern printing ; Style: creative
#include<stdio.h>
int main(){
    int i, j, k, l, n;

    printf("Enter the value of n: ");
    scanf("%d",&n);

    // Upper half of the pattern
    for(i=0; i<n; i++){
        for(j=0; j<=i; j++){
            printf("* ");
        }
        printf("\n");
    }

    // Lower half of the pattern
    for(k=n-1; k>=0; k--){
        for(l=0; l<=k; l++){
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}