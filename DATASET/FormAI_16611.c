//FormAI DATASET v1.0 Category: Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function to generate a random number between 1 and 100
int generateRandomNum(){
    srand(time(NULL)); //seed the random number generator with the current time
    return rand() % 100 + 1; //generate a random number between 1 and 100
}

int main(){
    int secretNum = generateRandomNum(); //get the random number
    int guess; //variable to store user's guess
    int attempts = 0; //variable to keep track of number of attempts

    printf("Welcome to the Guessing Game!\n");
    printf("I am thinking of a number between 1 and 100. You have 10 attempts to guess it.\n");

    //loop until user guesses the correct number or runs out of attempts
    while(attempts < 10){
        printf("Enter your guess: ");
        scanf("%d", &guess); //get user's guess

        //if guess is correct, break out of the loop
        if(guess == secretNum){
            printf("Congratulations! You guessed the number in %d attempts!\n", attempts+1); //adding 1 since attempts starts at 0
            break;
        }
        //if guess is too low, inform the user and give another attempt
        else if(guess < secretNum){
            printf("Too low! Try again.\n");
            attempts++;
        }
        //if guess is too high, inform the user and give another attempt
        else{
            printf("Too high! Try again.\n");
            attempts++;
        }
    }

    //if user has used up all attempts without guessing the correct number, inform them and reveal the answer
    if(attempts == 10){
        printf("Sorry! You have used up all your attempts. The number was %d.\n", secretNum);
    }

    return 0;
}