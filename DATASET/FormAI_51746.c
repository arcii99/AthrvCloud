//FormAI DATASET v1.0 Category: Pattern printing ; Style: puzzling
#include<stdio.h>
int main(){
    int i,j,k,row=10;
    for(i=1;i<=row;i++){
        for(j=1;j<=row;j++){
            if(i==j || j==row-i+1){
                // If it is an even row or column, print "+"
                if(i%2==0 || j%2==0 ){
                    printf("+");
                }
                // If it is odd row or column, print *
                else{
                    printf("*");
                }
            }
            else{
                // If the column value is greater than the row
                // then print "|" else "-"
                if(j>i){
                    printf("|");
                }
                else{
                    printf("-");
                }
            }
        }
        printf("\n");
    }
    return 0;
}