//FormAI DATASET v1.0 Category: Pattern printing ; Style: imaginative
#include<stdio.h>

int main(){
    int n,i,j,k,count;
    printf("Enter the number of rows (minimum 5): ");
    scanf("%d",&n);
    if(n<5){
        printf("Invalid input. Please try again.\n");
        return 0;
    }
    //Printing the top portion
    for(i=1;i<=n/2;i++){
        for(j=1;j<=i;j++){
            printf("* ");
        }
        for(k=1;k<=n-2*i;k++){
            printf("  ");
        }
        for(j=1;j<=i;j++){
            printf("* ");
        }
        printf("\n");
    }
    //Printing the middle line(s)
    if(n%2!=0){
        count=(n-1)/2;
        for(i=1;i<=2*count+1;i++){
            printf("* ");
        }
        printf("\n");
    }
    //Printing the bottom portion
    for(i=n/2;i>=1;i--){
        for(j=1;j<=i;j++){
            printf("* ");
        }
        for(k=1;k<=n-2*i;k++){
            printf("  ");
        }
        for(j=1;j<=i;j++){
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}