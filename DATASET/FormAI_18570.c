//FormAI DATASET v1.0 Category: Pattern printing ; Style: active
#include<stdio.h>
int main(){
    int n;
    printf("Enter the number of rows: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            printf("  ");
        }
        for(int k=1;k<=i;k++){
            printf("* ");
        }
        printf("\n");
    }
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=i;j++){
            printf("  ");
        }
        for(int k=1;k<=n-i;k++){
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}