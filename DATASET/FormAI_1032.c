//FormAI DATASET v1.0 Category: Random ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    time_t t;
    srand((unsigned) time(&t)); // Seed the random number generator with current time
    
    int min_num = 1;
    int max_num = 100;
    int target_num = rand() % (max_num + 1 - min_num) + min_num; // Generate a random number between 1 to 100
    
    int guess, num_guesses = 0;
    char play_again = 'y';

    while (play_again == 'y') {
        printf("Guess a number between 1 and 100: ");
        scanf("%d", &guess);
        num_guesses++;
        
        if (guess == target_num) {
            printf("Congratulations! You guessed the number in %d attempts.\n", num_guesses);
            printf("Do you want to play again? (y/n): ");
            scanf(" %c", &play_again);
            if (play_again == 'y') {
                // Reset the target number and number of guesses
                target_num = rand() % (max_num + 1 - min_num) + min_num;
                num_guesses = 0;
            }
        }
        else if (guess < target_num) {
            printf("Your guess is lower than the target number.\n");
        }
        else {
            printf("Your guess is higher than the target number.\n");
        }
    }
    
    printf("Thanks for playing!\n");
    
    return 0;
}