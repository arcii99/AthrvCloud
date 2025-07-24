//FormAI DATASET v1.0 Category: Pattern printing ; Style: portable
#include<stdio.h>

int main(){
    int row, col, num;
    printf("Enter the number of rows you want to print: ");
    scanf("%d",&num);
    
    printf("Printing C pattern...\n");
    for(row=1;row<=num;row++){
        for(col=1;col<=num;col++){
            if(row==1 || row==num || col==1)
                printf("*");
            else 
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}