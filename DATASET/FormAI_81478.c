//FormAI DATASET v1.0 Category: Pattern printing ; Style: interoperable
#include <stdio.h>

int main(){
    int rows, i, j, k;

    // Take input from user for number of rows
    printf("Enter number of rows: ");
    scanf("%d", &rows);

    // Upper half of the pattern
    for(i=1; i<=rows; i++){
        for(j=rows-i; j>=1; j--){
            printf(" ");
        }
        printf("*");
        for(k=1; k<(2*i-1); k++){
            printf(" ");
        }
        if(i != 1){
            printf("*");
        }
        printf("\n");
    }

    // Lower half of the pattern
    for(i=rows-1; i>=1; i--){
        for(j=1; j<=rows-i; j++){
            printf(" ");
        }
        printf("*");
        for(k=(2*i-3); k>=1; k--){
            printf(" ");
        }
        if(i != 1){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}