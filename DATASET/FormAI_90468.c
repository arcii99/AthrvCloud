//FormAI DATASET v1.0 Category: Table Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed random number generator with current time
    int player_score = 0;
    int computer_score = 0;
    int round = 1;
    printf("Let's play a game of Table.\n");
    while (round <= 5) { // play 5 rounds
        printf("Round %d\n", round);
        int player_choice, computer_choice;
        printf("Choose a number between 1 and 10: ");
        scanf("%d", &player_choice);
        while (player_choice < 1 || player_choice > 10) { // player must choose a valid number
            printf("Invalid choice. Choose a number between 1 and 10: ");
            scanf("%d", &player_choice);
        }
        computer_choice = rand() % 10 + 1;
        printf("The computer chose %d.\n", computer_choice);
        if (player_choice > computer_choice) { // player wins round
            printf("You win this round!\n");
            player_score++;
        } else if (computer_choice > player_choice) { // computer wins round
            printf("The computer wins this round.\n");
            computer_score++;
        } else { // tie
            printf("It's a tie.\n");
        }
        round++;
    }
    printf("Game over!\n");
    printf("Your final score is %d.\n", player_score);
    printf("The computer's final score is %d.\n", computer_score);
    if (player_score > computer_score) { // player wins game
        printf("Congratulations, you win!\n");
    } else if (computer_score > player_score) { // computer wins game
        printf("Sorry, the computer wins this time.\n");
    } else { // tie game
        printf("It's a tie game!\n");
    }
    return 0;
}