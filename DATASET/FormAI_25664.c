//FormAI DATASET v1.0 Category: Table Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll dice
int rollDice() {
    return (rand() % 6) + 1;
}

int main() {
    // Initialize variables
    int playerPos = 0; // Player's position on board
    int cpuPos = 0; // CPU's position on board
    int roll; // Value of roll
    int turns = 0; // Number of turns played so far
    int winner = 0; // 0 if no winner yet, 1 if player wins, 2 if CPU wins

    // Seed random number generator
    srand(time(NULL));

    // Print welcome message
    printf("Welcome to the C Table Game!\n");

    // Main game loop
    while (winner == 0) {
        // Player's turn
        printf("\nPlayer's turn:\n");
        roll = rollDice();
        playerPos += roll;
        printf("You rolled a %d\n", roll);
        if (playerPos >= 20) {
            winner = 1;
        } else {
            printf("You are now at position %d\n", playerPos);
        }

        // CPU's turn
        printf("\nCPU's turn:\n");
        roll = rollDice();
        cpuPos += roll;
        printf("CPU rolled a %d\n", roll);
        if (cpuPos >= 20) {
            winner = 2;
        } else {
            printf("CPU is now at position %d\n", cpuPos);
        }

        // Increment number of turns played
        turns++;
    }

    // Print final results
    printf("\nGame over in %d turns\n", turns);
    if (winner == 1) {
        printf("You win!\n");
    } else {
        printf("CPU wins!\n");
    }

    // Exit program
    return 0;
}