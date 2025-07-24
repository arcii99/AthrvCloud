//FormAI DATASET v1.0 Category: System administration ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Welcome message
    printf("Welcome to the System Administration Example Program!\n");
    
    // Get user's name
    char name[50];
    printf("What is your name?\n");
    scanf("%s", name);
    
    // Greet the user
    printf("Hello, %s! Let's get started.\n", name);
    
    // Set up random number generator
    srand(time(0));
    
    // Generate random number between 1 and 100
    int random_num = rand() % 100 + 1;
    
    // Prompt user to guess the number
    printf("I'm thinking of a number between 1 and 100. Can you guess it?\n");
    
    // Loop until user guesses correctly
    int guess;
    int num_guesses = 0;
    do {
        scanf("%d", &guess);
        num_guesses++;
        
        if (guess > random_num) {
            printf("Too high - try again!\n");
        } else if (guess < random_num) {
            printf("Too low - try again!\n");
        }
    } while (guess != random_num);
    
    // Congratulate the user and show number of guesses
    printf("Congratulations, %s! You guessed the number in %d tries.\n", name, num_guesses);
    
    // Say goodbye
    printf("Thanks for playing! Have a great day.\n");
    
    return 0;
}