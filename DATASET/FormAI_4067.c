//FormAI DATASET v1.0 Category: Table Game ; Style: post-apocalyptic
// Post-Apocalyptic Table Game
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice()
{
    // Roll two dice and return the sum
    int dice_1 = rand() % 6 + 1;
    int dice_2 = rand() % 6 + 1;
    return dice_1 + dice_2;
}

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Initialize player and computer scores
    int player_score = 0;
    int computer_score = 0;

    // Keep playing until someone reaches 21
    while(player_score < 21 && computer_score < 21)
    {
        // Player's turn
        printf("Player's turn:\n");
        int roll = roll_dice();
        printf("You rolled a %d\n", roll);
        player_score += roll;
        printf("Your score is %d\n", player_score);

        // Computer's turn
        printf("Computer's turn:\n");
        roll = roll_dice();
        printf("The computer rolled a %d\n", roll);
        computer_score += roll;
        printf("The computer's score is %d\n", computer_score);

        // Check for a winner
        if(player_score >= 21)
        {
            printf("The player wins!\n");
        }
        else if(computer_score >= 21)
        {
            printf("The computer wins!\n");
        }
    }
    return 0;
}