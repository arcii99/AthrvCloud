//FormAI DATASET v1.0 Category: Pattern printing ; Style: shocked
#include<stdio.h>
#include<stdlib.h>

int main(){
    int rows, i, j, space;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    if(rows%2 == 0){
        printf("Error: The number entered should be odd.");
        exit(0);
    }

    space = rows/2;

    for(i=1; i<=rows; i+=2){
        for(int k=0; k<space; k++)
            printf(" ");
        space--;

        for(j=1; j<=i; j++)
            printf("*");

        printf("\n");
    }

    for(i=rows-2; i>=1; i-=2){
        space++;
        for(int k=0; k<space; k++)
            printf(" ");

        for(j=1; j<=i; j++)
            printf("*");

        printf("\n");
    }

    return 0;
}