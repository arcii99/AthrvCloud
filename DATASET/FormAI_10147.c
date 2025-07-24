//FormAI DATASET v1.0 Category: Game ; Style: irregular
#include<stdio.h>

int game(int num, int guess){
    int count=0;
    while(num!=guess){
        printf("Guess the number:\n");
        scanf("%d",&guess);
        count++;
        if(guess>num){
            printf("Lower!\n");
        }
        else if(guess<num){
            printf("Higher!\n");
        }
    }
    printf("You guessed it in %d tries!\n",count);
    return count;
}

int main(){
    printf("Welcome to the Guessing Game!\n");
    int num;
    printf("Please enter a number between 1 and 100:\n");
    scanf("%d",&num);
    printf("You have 10 chances to guess the number!\n");
    int guess=-1;
    int total=0;
    for(int i=0;i<10;i++){
        printf("Guess the number:\n");
        scanf("%d",&guess);
        if(guess==num){
            printf("You guessed it in 1 try!\n");
            return 0;
        }
        else if(guess>num){
            printf("Lower!\n");
            total+=game(num,guess);
        }
        else if(guess<num){
            printf("Higher!\n");
            total+=game(num,guess);
        }
    }
    printf("Better luck next time!\n");
    printf("You guessed it in an average of %f tries!\n",(float)total/10);
    return 0;
}