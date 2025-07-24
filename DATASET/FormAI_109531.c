//FormAI DATASET v1.0 Category: Pattern printing ; Style: futuristic
#include<stdio.h>

int main(){
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i; j++){
            printf("  ");
        }
        for(int j=i; j>=1; j--){
            printf("%d ", j % 2);
        }
        for(int j=2; j<=i; j++){
            printf("%d ", j % 2);
        }
        printf("\n");
    }

    for(int i=n-1; i>=1; i--){
        for(int j=1; j<=n-i; j++){
            printf("  ");
        }
        for(int j=i; j>=1; j--){
            printf("%d ", j % 2);
        }
        for(int j=2; j<=i; j++){
            printf("%d ", j % 2);
        }
        printf("\n");
    }

    return 0;
}