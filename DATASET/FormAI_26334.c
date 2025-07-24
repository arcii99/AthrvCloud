//FormAI DATASET v1.0 Category: Random ; Style: brave
#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  
  
int main()  
{  
    srand(time(0));  //Seed based on current time  
    int randomNum = rand() % 100;  //Generate random number between 0-99  
  
    printf("Welcome to the Random Number Game!\n");  
    printf("I have picked a random number between 0-99. Can you guess what it is?");  
    
    int guess, numGuesses = 0;  
    do  
    {  
        printf("\nEnter your guess: ");  
        scanf("%d", &guess);  
        numGuesses++;  
          
        //Check if guess is correct  
        if (guess == randomNum)  
        {  
            printf("Congratulations! You guessed it in %d tries.\n", numGuesses);  
            break;  
        }  
        else if (guess < randomNum)  
        {  
            printf("Your guess is too low. Try again.\n");  
        }  
        else  
        {  
            printf("Your guess is too high. Try again.\n");  
        }  
          
        //Check if max number of guesses reached  
        if (numGuesses == 10)  
        {  
            printf("Sorry, you have used all your guesses. The number was %d.\n", randomNum);  
            break;  
        }  
    } while (guess != randomNum);  
    
    printf("Thanks for playing!");  
      
    return 0;  
}