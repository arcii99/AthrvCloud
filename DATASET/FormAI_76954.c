//FormAI DATASET v1.0 Category: Pattern printing ; Style: peaceful
#include<stdio.h>
int main(){
    int rows,spaces,i,j,k;
    printf("Enter the number of rows: ");
    scanf("%d",&rows);
    spaces = rows -1;
    
    for(i=1;i<=rows;i++){
        for(j=1;j<=spaces;j++){
            printf("  ");  //Printing two spaces
        }
        spaces--;        //Decreasing number of spaces
        for(k=1;k<=2*i-1;k++){
            printf("* ");
        }
        printf("\n");
    }
    spaces=1;
    for(i=1;i<=rows-1;i++){
        for(j=1;j<=spaces;j++){
            printf("  ");   //Printing two spaces
        }
        spaces++;           //Increasing number of spaces
        for(k=1;k<=2*(rows-i)-1;k++){
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}