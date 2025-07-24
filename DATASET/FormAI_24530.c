//FormAI DATASET v1.0 Category: Pattern printing ; Style: funny
#include<stdio.h>
int main(){
    printf("Hello there! I am going to show you a funny way to print a unique C Pattern.\n");
    printf("You are going to enjoy this. Trust me, I'm a computer program.\n");
    printf("Enter the number of rows you want in the pattern: ");

    int rows;
    scanf("%d", &rows);

    int spaces = rows - 1;
    int stars = 1;

    printf("Here we go...\n");

    // Let's start the fun

    for(int i=1; i<=rows; i++){
        for(int j=1; j<=spaces; j++){
            printf(" ");
        }

        for(int k=1; k<=stars; k++){
            if(i==1 || i==rows){
                printf("*");
            }else{
                if(k==1 || k==stars){
                    printf("*");
                }else{
                    printf(" ");
                }
            }
        }
        printf("\n");
        spaces--;
        stars+=2;
    }

    printf("See, it was fun. Hope you enjoyed the pattern.\n");
    printf("By the way, let me know if you want to print more patterns.\n");

    return 0;
}