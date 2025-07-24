//FormAI DATASET v1.0 Category: Pattern printing ; Style: romantic
#include<stdio.h>

int main(){
    int rows, i, j, space, k=0;
    printf("My dearest love,\nI would like to print a pattern for you today.\n");
    printf("Please enter the number of rows you would like in the pattern: ");
    scanf("%d",&rows);
    printf("Here is your pattern, my love:\n\n");

    for(i=1; i<=rows; i++){
        for(space=1; space <=rows-i; space++){
            printf(" ");
        }

        while(k != 2*i-1){
            printf("*");
            k++;
        }

        k=0;
        printf("\n");
    }
    printf("I hope you like it, my love.\nI promise to always try my best to bring a smile on your face.\n");
    return 0;
}