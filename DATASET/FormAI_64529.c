//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: creative
#include<stdio.h>

int main(){

    int rows;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    for(int i=1; i<=rows; i++){
        for(int j=1; j<=(rows-i); j++){
            printf(" ");
        }
        for(int k=1; k<=i; k++){
            printf("* ");
        }
        printf("\n");
    }

    for(int i=rows-1; i>=1; i--){
        for(int j=1; j<=(rows-i); j++){
            printf(" ");
        }
        for(int k=1; k<=i; k++){
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}