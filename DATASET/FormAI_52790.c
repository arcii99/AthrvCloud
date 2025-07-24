//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 6
int rollDice() {
    return (rand() % 6) + 1;
}

int main() {
    int playerPosition = 0; // Starting position of the player
    int diceValue; // Value obtained on rolling the dice
    srand(time(NULL)); // Seed random number generator with current time

    printf("Welcome to the Surrealist Game!\n");
    printf("You are standing at position 0. Press enter to continue...\n");
    getchar(); // Waits for user to press enter

    while (playerPosition < 20) { // Game continues until player reaches position 20
        diceValue = rollDice(); // Roll the dice
        printf("You rolled a %d!\n", diceValue);

        switch (diceValue) {
            case 1:
            case 2:
                printf("You take a walk through an underground tunnel, but get lost and end up back where you started.\n");
                break;
            case 3:
                printf("You find a giant blue beanstalk and climb to the top, where you find a magical portal that teleports you to position 10.\n");
                playerPosition = 10;
                break;
            case 4:
                printf("You stumble upon a labyrinth and manage to navigate through it successfully, reaching position %d.\n", playerPosition + 5);
                playerPosition += 5;
                break;
            case 5:
                printf("You are suddenly transported to a different realm with strange creatures. They invite you to a tea party and you lose track of time. You are now at position %d.\n", playerPosition + 2);
                playerPosition += 2;
                break;
            case 6:
                printf("You run into a talking snail who offers to take you on a ride. You end up at position %d.\n", playerPosition + 3);
                playerPosition += 3;
                break;
        }

        printf("You are now at position %d. Press enter to continue...\n", playerPosition);
        getchar(); // Waits for user to press enter
    }

    printf("Congratulations, you have reached position 20 and won the game!\n");

    return 0;
}