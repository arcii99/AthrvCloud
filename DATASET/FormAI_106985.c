//FormAI DATASET v1.0 Category: Pattern printing ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, i, j, k;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    for(i=1;i<=n;i++){
        for(j=1;j<=n-i;j++){
            printf(" ");
        }
        for(k=1;k<=i;k++){
            printf("%d ", k);
        }
        printf("\n");
    }

    for(i=n-1;i>=1;i--){
        for(j=1;j<=n-i;j++){
            printf(" ");
        }
        for(k=1;k<=i;k++){
            printf("%d ", k);
        }
        printf("\n");
    }
    return 0;
}