//FormAI DATASET v1.0 Category: Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to get a random number between minimum and maximum
int getRandomNumber(int minimum, int maximum) {
    srand(time(NULL)); //Seed the random number generator
    return (rand() % (maximum - minimum + 1)) + minimum; //Return random number within range
}

int main() {
    int minimum, maximum, randomNumber, guess, attempts = 0;
    
    printf("Welcome to the Guessing Game!\n");
    printf("Please enter the minimum and maximum values: ");
    scanf("%d %d", &minimum, &maximum);
    
    //Generate random number within the range
    randomNumber = getRandomNumber(minimum, maximum);
    
    printf("\nGuess the number between %d and %d.\n", minimum, maximum);
    
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++; //Increment number of attempts
        
        if (guess > randomNumber) {
            printf("Too high!\n");
        } else if (guess < randomNumber) {
            printf("Too low!\n");
        } else {
            printf("\nCongratulations! You guessed the number in %d attempts.\n", attempts);
        }
    } while (guess != randomNumber);
    
    return 0;
}