//FormAI DATASET v1.0 Category: Pattern printing ; Style: lively
#include<stdio.h>

int main(){
    int n=5;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            printf("*");
        }
        printf("\n");
    }

    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=i;j++){
            printf("*");
        }
        printf("\n");
    }

    printf("\n");

    int space,rows=10,k=0;
    for(int i=1;i<=rows;i++){
        for(space=1;space<=rows-i;space++){
            printf(" ");
        }
        while(k!=2*i-1){
            printf("*");
            k++;
        }
        k=0;
        printf("\n");
    }

    printf("\n");

    for(int i=1;i<=n;i++){
        for(int j=n-i;j>=1;j--){
            printf(" ");
        }
        for(int j=1;j<=2*i-1;j++){
            if(j==1 || j==2*i-1 || i==n){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}