//FormAI DATASET v1.0 Category: Random ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    printf("Welcome to the C random number generator program!\n\n");

    // Create a seed for the random number generator
    srand(time(NULL));

    // Generate random numbers
    int randomNum1 = rand() % 100;
    int randomNum2 = rand() % 100;

    // Print the random numbers to the console
    printf("Random Number 1: %d\n", randomNum1);
    printf("Random Number 2: %d\n\n", randomNum2);

    // Create a variable to hold the sum of the random numbers
    int sum = randomNum1 + randomNum2;

    // Print the sum of the random numbers to the console
    printf("The sum of the random numbers is: %d\n\n", sum);

    // Create a variable to hold a random number between 1 and 10
    int randomNum3 = rand() % 10 + 1;

    // Print the random number to the console
    printf("Random Number 3: %d\n\n", randomNum3);

    // Ask the user to guess a number between 1 and 10
    printf("Guess a number between 1 and 10: ");

    // Create a variable to hold the user's guess
    int guess;
    scanf("%d", &guess);

    // Check if the user's guess is the same as the random number
    if(guess == randomNum3){
        printf("Congratulations! You guessed the correct number!\n");
    }
    else{
        printf("Sorry, the correct number was %d. Better luck next time!\n", randomNum3);
    }

    return 0;
}