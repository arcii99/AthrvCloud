//FormAI DATASET v1.0 Category: Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice() { // function to simulate rolling a pair of dice
    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;
    printf("Rolling the dice... You got %d and %d = %d\n", dice1, dice2, dice1 + dice2);
    return dice1 + dice2;
}

int main() {
    srand(time(NULL));
    int score = 0;
    int point = 0;
    int roll = 0;
    printf("Welcome to the Dicey Game, where you roll dice and win big!\n");
    while (1) {
        roll++;
        printf("Roll #%d:\n", roll);
        if (point == 0) { // if the player doesn't have a point, roll the dice
            score += roll_dice();
            if (score == 7 || score == 11) { // if the player rolled a 7 or 11, they win
                printf("WOW! You got a 7 or 11 on your first roll. You win!\n");
                break;
            } else if (score == 2 || score == 3 || score == 12) { // if the player rolled a 2, 3, or 12, they lose
                printf("Oh no! You got a 2, 3, or 12 on your first roll. You lose!\n");
                break;
            } else { // otherwise, set the point to the score and continue rolling
                point = score;
                printf("Your point is set to %d. Keep rolling to try to match it!\n", point);
            }
        } else { // if the player has a point, keep rolling to try to match it
            int new_roll = roll_dice();
            if (new_roll == point) { // if the player matched their point, they win
                printf("You matched your point of %d. You win!\n", point);
                break;
            } else if (new_roll == 7) { // if the player rolled a 7 before matching their point, they lose
                printf("Oh no! You rolled a 7 before matching your point of %d. You lose!\n", point);
                break;
            }
        }
    }
    printf("Thanks for playing the Dicey Game! Come back and play again soon!\n");
    return 0;
}