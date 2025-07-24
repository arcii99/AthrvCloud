//FormAI DATASET v1.0 Category: Table Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player_score = 0;
    int computer_score = 0;
    int round = 1;
   
    printf("Welcome to the Happy Table Game!\n");
    printf("In this game, you and the computer will each roll a die.\n");
    printf("Whoever gets the higher number gets a point.\n");
    printf("Whoever has the most points after five rounds, wins!\n\n");
    
    srand(time(0)); // seed the random number generator with the current time
    
    while (round <= 5) {
        
        printf("Round %d\n", round);
        
        // player's turn
        printf("Your turn! Press Enter to roll the die.\n");
        getchar(); // wait for user to press enter
        int player_roll = rand() % 6 + 1; // generate a number between 1 and 6
        printf("You rolled a %d!\n", player_roll);
        
        // computer's turn
        printf("Computer's turn! Press Enter to roll the die.\n");
        getchar(); // wait for user to press enter
        int computer_roll = rand() % 6 + 1;
        printf("The computer rolled a %d!\n", computer_roll);
        
        // determine the winner of the round
        if (player_roll > computer_roll) {
            printf("You win this round!\n\n");
            player_score++;
        }
        else if (player_roll < computer_roll) {
            printf("The computer wins this round!\n\n");
            computer_score++;
        }
        else {
            printf("It's a tie!\n\n");
        }
        
        round++;
        
    }
    
    // determine the winner of the game
    printf("Final score:\n");
    printf("You: %d\n", player_score);
    printf("Computer: %d\n", computer_score);
    
    if (player_score > computer_score) {
        printf("Congratulations, you win!\n");
    }
    else if (player_score < computer_score) {
        printf("Sorry, the computer wins this time.\n");
    }
    else {
        printf("It's a tie!\n");
    }
    
    return 0;
}