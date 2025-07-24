//FormAI DATASET v1.0 Category: Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between min and max
int rand_num(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

int main(){
    srand(time(NULL)); // Seed the random number generator
    int num_guesses = 0;
    int guess = 0;
    int num = rand_num(1, 100); // Generate random number between 1 and 100

    printf("Welcome to the Guessing Game!\n");
    printf("I'm thinking of a number between 1 and 100. Can you guess it?\n");

    // Loop until user guesses correctly
    while(guess != num){
        printf("Enter your guess: ");
        scanf("%d", &guess);
        num_guesses++;

        if(guess < num){
            printf("Too low, try again.\n");
        } else if(guess > num){
            printf("Too high, try again.\n");
        } else {
            printf("Congratulations, you guessed the number in %d tries!\n", num_guesses);
        }
    }

    return 0;
}