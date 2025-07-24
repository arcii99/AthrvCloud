//FormAI DATASET v1.0 Category: Game ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int randomNumber, guessNumber, numberOfGuesses=0;
    srand(time(0));
    randomNumber=rand()%100 +1; //generating random number between 1 to 100

     printf("\n\nGuess a Number Game\n\n");

     do{
        printf("Guess the Number between 1 to 100 : ");
        scanf("%d", &guessNumber);
        numberOfGuesses++;
        if(guessNumber>randomNumber)
            printf("Lower Number Please\n");
        else if(guessNumber<randomNumber)
            printf("Higher Number Please\n");
        else
            printf("\n\nCongratulations!! You Guessed it in %d Attempts.", numberOfGuesses);
     }while(guessNumber!=randomNumber);

     return 0;
}