//FormAI DATASET v1.0 Category: Pattern printing ; Style: lively
#include<stdio.h>
// Code for printing C pattern
int main(){
    int rows;
    printf("Welcome to the C pattern printing program!\n\n");
    printf("Enter the number of rows you want in your C pattern:");
    scanf("%d",&rows);
    printf("\n");
    int i,j,space;
    for(i=1;i<=rows;i++){
        if(i==1 || i==rows){ // printing first and last line of C pattern
            for(j=1;j<=rows;j++){
                printf("*");
            }
            printf("\n");
        }else{
            for(j=1;j<=rows;j++){
                if(j==1){ //adding spaces before C pattern
                    printf("*");
                }else if(j==rows){ // printing C pattern in last column of each row
                    printf("*");
                }else if(i==j){ // printing C pattern in diagonal line
                    printf("*");
                }else{
                    printf(" "); // leaving spaces inside C pattern
                }
            }
            printf("\n");
        }
    }
    return 0;
}