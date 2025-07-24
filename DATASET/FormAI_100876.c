//FormAI DATASET v1.0 Category: Pattern printing ; Style: sophisticated
#include<stdio.h>

int main(){
    int n,i,j;
    printf("Enter the number of rows in the pattern: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=n-i;j>=1;j--){
            printf(" ");
        }
        for(j=1;j<=i;j++){
            printf("%d",j);
        }
        for(j=i-1;j>=1;j--){
            printf("%d",j);
        }
        printf("\n");
    }
    for(i=n-1;i>=1;i--){
        for(j=n-i;j>=1;j--){
            printf(" ");
        }
        for(j=1;j<=i;j++){
            printf("%d",j);
        }
        for(j=i-1;j>=1;j--){
            printf("%d",j);
        }
        printf("\n");
    }
    return 0;
}