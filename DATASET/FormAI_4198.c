//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set up the random number generator
    srand(time(NULL));

    // Define the variables
    int rooms[4][4];
    int playerRow = 0;
    int playerCol = 0;
    int ghostRow = 0;
    int ghostCol = 0;
    int treasureRow = 0;
    int treasureCol = 0;
    int moveCount = 0;

    // Initialize the rooms
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            rooms[i][j] = rand() % 3; // 0 = empty, 1 = ghost, 2 = treasure
        }
    }

    // Place the player, ghost, and treasure randomly
    playerRow = rand() % 4;
    playerCol = rand() % 4;
    do {
        ghostRow = rand() % 4;
        ghostCol = rand() % 4;
    } while (ghostRow == playerRow && ghostCol == playerCol);
    do {
        treasureRow = rand() % 4;
        treasureCol = rand() % 4;
    } while ((treasureRow == playerRow && treasureCol == playerCol) || (treasureRow == ghostRow && treasureCol == ghostCol));

    // Game loop
    while (1) {
        // Print the room
        printf("You are in a dark, medieval room.\n");
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (i == playerRow && j == playerCol) {
                    printf("P ");
                } else {
                    printf("%d ", rooms[i][j]);
                }
            }
            printf("\n");
        }

        // Ask for the player's move
        printf("Enter your move (N/S/E/W): ");
        char input[3];
        fgets(input, 3, stdin);

        // Handle the player's move
        if (input[0] == 'n' || input[0] == 'N') {
            if (playerRow > 0) {
                playerRow--;
            }
        } else if (input[0] == 's' || input[0] == 'S') {
            if (playerRow < 3) {
                playerRow++;
            }
        } else if (input[0] == 'e' || input[0] == 'E') {
            if (playerCol < 3) {
                playerCol++;
            }
        } else if (input[0] == 'w' || input[0] == 'W') {
            if (playerCol > 0) {
                playerCol--;
            }
        } else {
            printf("Invalid input.\n");
            continue;
        }

        // Increment the move count
        moveCount++;

        // Check for the ghost
        if (playerRow == ghostRow && playerCol == ghostCol) {
            printf("A ghost has caught you!\n");
            break;
        }

        // Check for the treasure
        if (playerRow == treasureRow && playerCol == treasureCol) {
            printf("You have found the treasure!\n");
            break;
        }
    }

    // Print the final message
    printf("Game over! You made %d moves.\n", moveCount);

    return 0;
}