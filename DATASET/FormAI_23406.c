//FormAI DATASET v1.0 Category: Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int min = 1, max = 100, guess, num, count = 0;
    char choice;
    srand(time(0));
    
    printf("Welcome to the Number Guessing Game!\n");
    printf("I'm thinking of a number between %d and %d. Can you guess it?\n", min, max);
    num = (rand() % 100) + 1;
    
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        count++;
        
        if(guess > num) {
            printf("Lower!\n");
        } else if(guess < num) {
            printf("Higher!\n");
        }
    } while(guess != num);
    
    printf("Congratulations! You guessed the number in %d tries!\n", count);
    
    printf("Would you like to play again? (Y/N): ");
    scanf(" %c", &choice);
    
    if(choice == 'Y' || choice == 'y') {
        main();
    } else {
        printf("Thanks for playing!\n");
    }
    
    return 0;
}