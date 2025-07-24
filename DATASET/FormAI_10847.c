//FormAI DATASET v1.0 Category: Table Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    //initialize random seed
    srand(time(NULL));

    //initialize variables
    printf("Welcome to the C table game!\n\n");
    int player_score = 0;
    int computer_score = 0;
    int round = 1;
    char choice;

    while(round <= 5) {

        //player's turn
        printf("Round %d - Player's turn:\n", round);
        int player_roll1 = rand() % 6 + 1;
        int player_roll2 = rand() % 6 + 1;
        printf("You rolled a %d and a %d.\n", player_roll1, player_roll2);
        player_score += player_roll1 + player_roll2;
        printf("Your current score is %d.\n", player_score);

        //computer's turn
        printf("Round %d - Computer's turn:\n", round);
        int computer_roll1 = rand() % 6 + 1;
        int computer_roll2 = rand() % 6 + 1;
        printf("The computer rolled a %d and a %d.\n", computer_roll1, computer_roll2);
        computer_score += computer_roll1 + computer_roll2;
        printf("The computer's current score is %d.\n", computer_score);

        round++;
    }

    //determine winner
    printf("\nGame over!\n");
    if(player_score > computer_score) {
        printf("Congratulations, you won with a score of %d!", player_score);
    } else if(computer_score > player_score) {
        printf("Sorry, the computer won with a score of %d.", computer_score);
    } else {
        printf("It's a tie!");
    }

    return 0;
}