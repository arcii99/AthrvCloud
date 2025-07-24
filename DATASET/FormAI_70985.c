//FormAI DATASET v1.0 Category: Table Game ; Style: calm
#include<stdio.h> 
#include<stdlib.h> 
#include<time.h> 
  
int main() 
{ 
    int guess, number_of_guesses=1, number_to_guess;
    srand(time(0)); 
    number_to_guess=rand()%1000+1; //generating a random number between 1 and 1000
    printf("Welcome to the C Table Game!\n"); 
    printf("Guess a number between 1 and 1000!\n"); 
 
    do{ 
        printf("Enter your guess: "); 
        scanf("%d",&guess); //taking input from user
        if(guess>number_to_guess){ //if the guessed number is greater than number_to_guess
            printf("Lower number please!\n");
            number_of_guesses++; //counting the number of guesses
        } 
        else if(guess<number_to_guess){ //if the guessed number is smaller than number_to_guess
            printf("Higher number please!\n");
            number_of_guesses++; //counting the number of guesses
        } 
        else{ 
            printf("Congratulations! You guessed it in %d attempts\n",number_of_guesses); //if the guessed number is equal to number_to_guess
            break; //exit from loop
        } 
    }while(guess!=number_to_guess); //loop will continue until the guessed number is equal to number_to_guess
    
    return 0; 
}