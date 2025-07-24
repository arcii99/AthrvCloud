//FormAI DATASET v1.0 Category: Pattern printing ; Style: funny
#include<stdio.h>
int main(){
printf("\n\n");
printf("*******************************\n");
printf("Welcome to the C Pattern Printer\n");
printf("*******************************\n\n\n");
int rows, cols;
printf("Please enter the number of rows: ");
scanf("%d",&rows);
printf("\nGreat! And how many columns do you want? ");
scanf("%d",&cols);
printf("\nBrilliant! Here's your pattern:\n\n");

//upper half of the pattern
for(int i=1; i<=rows; i++){
    printf("*");
    for(int j=1; j<=cols; j++){
        if(j==i){
            printf("C");
        }else{
            printf("*");
        }
    }
    printf("*\n");
}

//lower half of the pattern
for(int i=rows-1; i>=1; i--){
    printf("*");
    for(int j=1; j<=cols; j++){
        if(j==i){
            printf("C");
        }else{
            printf("*");
        }
    }
    printf("*\n");
}

printf("\n\nHope you liked your pattern! Come back soon!\n\n");
return 0;
}