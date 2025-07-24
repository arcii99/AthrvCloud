//FormAI DATASET v1.0 Category: Game ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int guess,rand_num,count=0,flag=0;
    time_t t;
    srand((unsigned)time(&t)); //generating random number using time as seed
    rand_num=rand()%101; //generating a random number between 0 and 100
    
    printf("Welcome to the Guessing game!\n");
    printf("I have a number between 0 and 100, can you guess it?\n");
    
    do{
        printf("Enter your guess: ");
        scanf("%d",&guess);
        count++; //incrementing count for every guess made
        
        if(guess==rand_num){
            flag=1; //setting flag to indicate correct guess
            break;
        }
        else if(guess>rand_num)
            printf("Incorrect! Your guess is too high.\n");
        else
            printf("Incorrect! Your guess is too low.\n");
            
    }while(count<5); //allowing maximum of 5 guesses
    
    if(flag==1)
        printf("Congratulations! You have guessed the number in %d tries.\n",count);
    else
        printf("Sorry, you ran out of tries. The correct number was %d.\n",rand_num);
    
    return 0; 
}