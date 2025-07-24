//FormAI DATASET v1.0 Category: Pattern printing ; Style: decentralized
#include <stdio.h>

int main(){
    int i, j, row, col, space;
    printf("Enter the number of rows:");
    scanf("%d",&row);
    col = row;
    for(i=1;i<=row;i++){
        for(space=1;space<=i;space++){
            printf(" ");
        }
        for(j=1;j<=col;j++){
            printf("*");
        }
        col--;
        printf("\n");
    }
    col = 1;
    for(i=row-1;i>=1;i--){
        for(space=1;space<=i;space++){
            printf(" ");
        }
        for(j=1;j<=col;j++){
            printf("*");
        }
        col++;
        printf("\n");
    }
    return 0;
}