//FormAI DATASET v1.0 Category: Pattern printing ; Style: energetic
#include<stdio.h>

int main(){
    int n = 15;
    int i,j;
    

    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(j==1 || i==1 || i==n || i==n/2+1 || j==n/2+1){
                printf("*");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
    
    printf("\n");
    
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(j==i || i+j==n+1 || i==1 || i==n){
                printf("*");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
    
    printf("\n");

    int space = 0;
    for(i=1;i<=n;i++){
        for(j=1;j<=space;j++){
            printf(" ");
        }
        for(j=1;j<=n-i+1;j++){
            printf("%d",j);
        }
        printf("\n");
        space++;
    }
    
    printf("\n");
    
    space = n-1;
    for(i=1;i<=n;i++){
        for(j=1;j<=space;j++){
            printf(" ");
        }
        for(j=1;j<=i;j++){
            printf("%d",j);
        }
        for(j=i-1;j>=1;j--){
            printf("%d",j);
        }
        printf("\n");
        space--;
    }
    
    printf("\n");
    
    space = n-1;
    for(i=1;i<=n;i++){
        for(j=1;j<=space;j++){
            printf(" ");
        }
        for(j=1;j<=i;j++){
            printf("%d ",j);
        }
        for(j=i-1;j>=1;j--){
            printf("%d ",j);
        }
        printf("\n");
        space--;
    }
    
    printf("\n");
    
    for(i=1;i<=n;i++){
        for(j=1;j<=n-i;j++){
            printf(" ");
        }
        for(j=1;j<=i;j++){
            printf("%d ",j);
        }
        for(j=i-1;j>=1;j--){
            printf("%d ",j);
        }
        printf("\n");
    }
    
    printf("\n");
    
    for(i=1;i<=n;i++){
        for(j=1;j<=n-i;j++){
            printf(" ");
        }
        for(j=1;j<=i;j++){
            printf("%d ",j);
        }
        for(j=i-1;j>=1;j--){
            printf("%d ",j);
        }
        printf("\n");
    }
    
    for(i=n-1;i>=1;i--){
        for(j=1;j<=n-i;j++){
            printf(" ");
        }
        for(j=1;j<=i;j++){
            printf("%d ",j);
        }
        for(j=i-1;j>=1;j--){
            printf("%d ",j);
        }
        printf("\n");
    }
    
    return 0;
}