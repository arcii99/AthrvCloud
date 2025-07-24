//FormAI DATASET v1.0 Category: Pattern printing ; Style: complete
#include<stdio.h>
int main(){
    int n, i, j, space = 1;
    printf("Enter number of rows: ");
    scanf("%d", &n);

    for(i=1; i<=n; i++){
        for(j=1; j<=space; j++){
            printf(" ");
        }
        for(j=i; j<=n; j++){
            printf("%d", i);
            printf(" ");
        }
        printf("\n");
        space=space+2;
    }

    space = space - 4;

    for(i=n; i>=1; i--){
        for(j=1; j<=space; j++){
            printf(" ");
        }
        for(j=i; j<=n; j++){
            printf("%d", i);
            printf(" ");
        }
        printf("\n");
        space=space-2;
    }

    return 0;
}