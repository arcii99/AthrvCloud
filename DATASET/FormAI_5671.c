//FormAI DATASET v1.0 Category: Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice() {
    return rand() % 6 + 1;
}

int main() {
    srand(time(NULL));
    int score = 0, roll, num_rounds = 0;
    char play_again = 'y';

    printf("Welcome to Dice Game!\n");

    while (play_again == 'y') {
        printf("Round %d begins!\n", num_rounds + 1);
        roll = rollDice();
        printf("You rolled a %d!\n", roll);
        score += roll;

        while (roll != 1) {
            printf("Do you want to roll again? (y/n) ");
            char continue_game;
            scanf(" %c", &continue_game);

            if (continue_game == 'n') {
                break;
            }
            
            roll = rollDice();
            printf("You rolled a %d!\n", roll);
            score += roll;
        }

        printf("Round %d ended with a score of %d!\n", num_rounds + 1, score);
        printf("Do you want to play another round? (y/n) ");
        scanf(" %c", &play_again);
        
        if (play_again == 'y') {
            num_rounds++;
        }
    }
    
    printf("Thanks for playing Dice Game!\n");
    return 0;
}