//FormAI DATASET v1.0 Category: Pattern printing ; Style: thoughtful
#include<stdio.h>

int main(){
    int length, i, j, k;
    printf("Enter length of pattern: ");
    scanf("%d",&length);    //reading length of pattern from user
  
    for(i=0;i<=length;i++){    //loop for printing upper half of pattern
        for(j=i;j<=length;j++){
            printf(" ");
        }
        for(k=1;k<=i;k++){
            printf("%d ",k);
        }
        printf("\n");
    }
    
    for(i=length-1;i>=1;i--){    //loop for printing lower half of pattern
        for(j=length+1;j>i;j--){
            printf(" ");
        }
        for(k=1;k<=i;k++){
            printf("%d ",k);
        }
        printf("\n");
    }
  
    return(0);
}