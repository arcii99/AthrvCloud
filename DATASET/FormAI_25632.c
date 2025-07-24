//FormAI DATASET v1.0 Category: Pattern printing ; Style: inquisitive
#include<stdio.h>

int main(){
    int n, i, j;
    
    printf("Enter the number of rows for pattern: ");
    scanf("%d", &n);

    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            if(i==1 || i==n || j==1 || j==n || i==j || j==n-i+1){
                printf("* ");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }

    return 0;
}