//FormAI DATASET v1.0 Category: Pattern printing ; Style: irregular
#include<stdio.h>

int main(){
    int i, j, k;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(i==0 || i==9){
                printf("*");
            }
            else if(i==j || i+j==9){
                printf("+");
            }
            else if(i%2==0 && j%2==0){
                printf("-");
            }
            else if(i%2!=0 && j%2!=0){
                printf(".");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}