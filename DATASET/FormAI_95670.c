//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    int num,guess,count=0;
    srand(time(0)); //seed for random function
    num=rand()%100+1; //generating random number between 1 to 100
    printf("\n\t***WELCOME TO THE GUESSING GAME***\n\n\n");

    do{
        printf("Enter your guess(1-100): ");
        scanf("%d",&guess);
        count++; //incrementing the count for every guess
        if(guess>num){
            printf("Too high!\n\n");
        }else if(guess<num){
            printf("Too low!\n\n");
        }else{
            printf("\n\n***CONGRATULATIONS! You have guessed the correct number %d in %d attempts.***\n",num,count);
        }
        
    }while(guess!=num);

    return 0; //end of program
}