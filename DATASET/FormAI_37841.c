//FormAI DATASET v1.0 Category: Pattern printing ; Style: imaginative
#include <stdio.h>

int main()
{
    int rows, i, j, k;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    for(i=1;i<=rows;i++){
        for(j=rows;j>=i;j--){
            printf(" ");
        }
        for(k=1;k<=i;k++){
            printf("* ");
        }
        printf("\n");
    }
    for(i=rows;i>=1;i--){
        for(j=rows;j>=i;j--){
            printf(" ");
        }
        for(k=1;k<=i;k++){
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}