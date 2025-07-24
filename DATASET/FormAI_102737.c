//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initializing variables
    int num_guesses = 0;
    int guess;
    int secret_num;
    char choice;
    
    // Seeding the random number generator
    srand(time(NULL));
    
    // Generating a secret number between 1 and 100
    secret_num = rand() % 100 + 1;
    
    printf("Welcome to the Paranoid Game!\n");
    printf("I have generated a secret number between 1 and 100 and you have to guess it.\n");
    
    do {
        // Prompting user for guess
        printf("Guess the secret number: ");
        scanf("%d", &guess);
        
        // Incrementing number of guesses
        num_guesses++;
        
        // Checking if guess is correct
        if (guess == secret_num) {
            printf("Congratulations! You guessed the secret number in %d tries!\n", num_guesses);
            break;
        } else if (guess < secret_num) {
            printf("Too low, try again.\n");
        } else {
            printf("Too high, try again.\n");
        }
        
        // Asking user if they want to continue playing
        printf("Do you want to keep playing? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y');
    
    // End of game message
    printf("Thanks for playing the Paranoid Game! Don't trust anyone.\n");
    
    return 0;
}