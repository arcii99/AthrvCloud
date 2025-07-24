//FormAI DATASET v1.0 Category: Table Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int scores[2] = {0, 0};
    int player = 0;
    int dice_roll;
    int game_round = 1;
    printf("\n===== WELCOME TO THE C TABLE GAME =====\n\n");
    while (scores[0] < 100 && scores[1] < 100) {
        printf("Round %d\n", game_round);
        printf("Player %d's turn.\n", player+1);
        printf("Current Scores: Player 1 - %d, Player 2 - %d\n", scores[0], scores[1]);
        printf("Press enter to roll the dice.\n");
        getchar();
        dice_roll = rand() % 6 + 1;
        printf("You rolled a %d!\n", dice_roll);
        if (dice_roll == 1) {
            printf("Bad luck, you lose all your points.\n");
            scores[player] = 0;
            player = (player + 1) % 2;
        } else {
            scores[player] += dice_roll;
            printf("Your score is now %d.\n", scores[player]);
            if (scores[player] >= 100) break; // break out of the loop if a player has won
            printf("Do you want to roll again? Enter y for yes, n for no.\n");
            char choice;
            do {
                choice = getchar();
            } while (choice != '\n' && choice != 'y' && choice != 'n'); // wait for user input
            if (choice == 'n') player = (player + 1) % 2; // switch players
        }
        game_round++;
    }
    printf("\nGAME OVER! Final Scores: Player 1 - %d, Player 2 - %d\n", scores[0], scores[1]);
    printf("Congratulations, Player %d wins!\n", (scores[0] >= 100) ? 1 : 2);
    return 0;
}