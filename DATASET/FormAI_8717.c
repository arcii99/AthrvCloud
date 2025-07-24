//FormAI DATASET v1.0 Category: Pattern printing ; Style: grateful
#include<stdio.h>
#include<stdlib.h>

int main(){
    int num, i, j;
    printf("Enter a number: ");
    scanf("%d", &num);

    for(i=1; i<=num; i++){
        for(j=1; j<=num; j++){
            if(i==1 || i==num || j==1 || j==num){
                printf("*");
            }
            else if(i==j || j==num-i+1){
                printf("+");
            }
            else{
                printf("-");
            }
        }
        printf("\n");
    }

    return 0;
}