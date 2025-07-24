//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to simulate a dice roll
int rollDice() {
    int dice = (rand() % 6) + 1;
    return dice;
}

int main() {

    //Seed the random number generator
    srand(time(NULL));

    //Welcome message
    printf("Welcome to the Haunted House Simulator\n\n");

    //Initialize variables
    int playerScore = 0;
    int ghostScore = 0;

    //Loop until one of the players scores 10 points
    while (playerScore < 10 && ghostScore < 10) {

        //Player's turn
        printf("It's your turn...\n");
        printf("Press Enter to roll the dice\n");
        getchar();

        int playerRoll = rollDice();
        printf("You rolled a %d\n", playerRoll);

        playerScore += playerRoll;
        printf("Your score is now %d\n", playerScore);

        //Check if player won
        if (playerScore >= 10) {
            printf("Congratulations! You have escaped from the haunted house\n");
            break;
        }

        //Ghost's turn
        printf("\nIt's the ghost's turn...\n");

        int ghostRoll = rollDice();
        printf("The ghost rolled a %d\n", ghostRoll);

        ghostScore += ghostRoll;
        printf("The ghost's score is now %d\n", ghostScore);

        //Check if ghost won
        if (ghostScore >= 10) {
            printf("Oh no! The ghost has caught you. GAME OVER\n");
            break;
        }

        printf("\n");
    }

    return 0;
}