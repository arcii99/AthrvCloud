//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number
int generateRandomNum(int lower, int upper) {
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main() {
    int guess, num_guesses = 1;
    int lower = 1, upper = 100, randomNum;
    
    srand(time(0)); // Seed for the random number generator
    randomNum = generateRandomNum(lower, upper); // Generates random number
    
    printf("\nWelcome to the Guessing Game!\n");
    printf("You have to guess a number between %d and %d\n", lower, upper);
    
    // Loop until the user guesses the correct number
    do {
        printf("Enter your guess (try %d): ", num_guesses);
        scanf("%d", &guess);
        
        if(guess < randomNum) {
            printf("The number is higher than %d, try again\n", guess);
            num_guesses++;
        } else if(guess > randomNum) {
            printf("The number is lower than %d, try again\n", guess);
            num_guesses++;
        } else {
            printf("Congratulations! You guessed the number in %d tries\n", num_guesses);
        }
    } while(guess != randomNum);
    
    return 0;
}