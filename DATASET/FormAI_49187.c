//FormAI DATASET v1.0 Category: Pattern printing ; Style: realistic
#include<stdio.h>
int main(){
    int n;
    printf("Enter the number of rows : ");
    scanf("%d", &n);

    int i, j;
    for(i=1; i<n; i++){
        for(j=1; j<=n; j++){
            if(j<=i){
                printf("%d ", j);
            }
            else{
                printf("  ");
            }
        }
        for(j=n-1; j>=1; j--){
            if(j<=i){
                printf("%d ", j);
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }

    for(i=n; i>=1; i--){
        for(j=1; j<=n; j++){
            if(j<=i){
                printf("%d ", j);
            }
            else{
                printf("  ");
            }
        }
        for(j=n-1; j>=1; j--){
            if(j<=i){
                printf("%d ", j);
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}