//FormAI DATASET v1.0 Category: Pattern printing ; Style: complete
#include<stdio.h>
int main() {
    int n,i,j,k;
    printf("Enter a number between 3 and 10: ");
    scanf("%d",&n);
    while(n<3 || n>10) {
        printf("Invalid input\n\n");
        printf("Enter a number between 3 and 10: ");
        scanf("%d",&n);
    }
    int arr[n][n];
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++){
            arr[i][j]=-1;
        }
    }
    for(i=0;i<n/2;i++) {
        for(j=i;j<n-i;j++){
            arr[i][j]=i+1;
            arr[n-i-1][j]=i+1;
            arr[j][i]=i+1;
            arr[j][n-i-1]=i+1;
        }
    }
    if(n%2==1){
        arr[n/2][n/2]=n/2+1;
    }
    printf("\nThe Pattern is:");
    printf("\n-----------------\n");
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            if(arr[i][j]==-1) {
                printf("  ");
            } else {
                printf("%d ",arr[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}