//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int score = 0;
    int option;
    
    srand(time(NULL)); // srand sets the seed for rand to value returned by time function below
    int random_number = rand() % 10; // Generating random number between 0 and 9 (inclusive)
    
    printf("Welcome to the surprise game!\n");
    printf("Guess the number between 0 and 9 to win points!\n");
    
    while (1) { // Infinite loop until user enters '0'
        printf("Enter 0 to quit the game or any other number to continue: ");
        scanf("%d", &option);
        
        if (option == 0) {
            printf("Leaving so soon? See you next time!\n");
            return 0;
        }
        
        int guess;
        printf("Enter your guess (between 0 and 9): ");
        scanf("%d", &guess);
        
        if (guess == random_number) {
            printf("Congratulations! Your guess was correct!\n");
            score += 10;
            printf("Your current score is: %d\n", score);
            printf("The next number is ready to be guessed.\n");
            random_number = rand() % 10; // Generating a new random number
        } else {
            printf("Oops! Your guess was incorrect.\n");
            printf("The correct answer was: %d\n", random_number);
            printf("Your score remains at: %d\n", score);
        }
    }
}