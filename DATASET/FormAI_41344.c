//FormAI DATASET v1.0 Category: Pattern printing ; Style: romantic
#include<stdio.h>
int main(){
    int n,k=0;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++)
            printf("  ");
        while(k!=(2*i-1)){
            if(k==0 || k==2*i-2 || i==n)
                printf("* ");
            else
                printf("  ");
            k++;
        }
        k=0;
        printf("\n");
    }
    return 0;
}