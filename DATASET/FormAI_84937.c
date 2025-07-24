//FormAI DATASET v1.0 Category: Pattern printing ; Style: complete
#include<stdio.h>
int main(){
    int n,i,j,k,s;
    printf("Enter the number of rows: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){  // Loop for the rows
        for(j=i;j<n;j++){
            printf(" ");   // Space printing
        }
        for(k=1;k<=(2*i-1);k++){
            if(k==1 || k==(2*i-1) || i==n){
                printf("*"); // Printing asterisks for C pattern
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}