//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a six-sided die
int rollDie() {
    return (rand() % 6) + 1;
}

// Function to check if player can move forward
int canMoveForward(int currentPos, int roll) {
    return currentPos + roll <= 30 ? 1 : 0;
}

// Function to update player's position
void updatePosition(int *currentPos, int roll) {
    *currentPos += roll;
}

// Function to check if player has reached the end
int hasReachedEnd(int currentPos) {
    return currentPos == 30 ? 1 : 0;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize player's position
    int playerPos = 0;

    // Initialize alien encounter flag
    int alienEncounter = 0;

    printf("Welcome to your space adventure!\n");

    while (1) {
        // Roll the die
        int roll = rollDie();

        printf("You rolled a %d.\n", roll);

        if (alienEncounter) {
            // Player is encountering aliens, cannot move forward
            printf("You are encountering aliens, cannot move forward.\n");
            alienEncounter = 0;
        } else if (canMoveForward(playerPos, roll)) {
            // Player can move forward
            printf("You move forward %d steps.\n", roll);
            updatePosition(&playerPos, roll);
        } else {
            // Player cannot move forward, hit a space obstacle
            printf("You hit a space obstacle, cannot move forward.\n");
        }

        if (playerPos == 10) {
            // Player encountered aliens
            printf("You encountered aliens! You must fight them off or be stuck for 3 turns.\n");
            alienEncounter = 1;
        } else if (playerPos == 20) {
            // Player found a power-up
            printf("You found a power-up that grants you an extra turn!\n");
            roll = rollDie();
            printf("You rolled a %d.\n", roll);
            printf("You move forward an extra %d steps.\n", roll);
            updatePosition(&playerPos, roll);
        }

        // Check if player has reached the end
        if (hasReachedEnd(playerPos)) {
            printf("Congratulations, you have completed your space adventure!\n");
            break;
        }
    }

    return 0;
}