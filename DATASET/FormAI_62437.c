//FormAI DATASET v1.0 Category: Table Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define NUM_PLAYERS 2
#define MAX_HEALTH 100

// Function to generate random integer between min and max (inclusive)
int generateRandomInt(int min, int max) {
    srand(time(NULL));
    int range = max - min + 1;
    return min + rand() % range;
}

// Function to check if all players have lost
int allPlayersLost(int* healthPoints) {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        if (healthPoints[i] > 0) {
            return 0; // Not all players lost yet
        }
    }
    return 1; // All players lost
}

int main() {
    int playerTurn = 0; // Player turn counter
    int healthPoints[NUM_PLAYERS] = { MAX_HEALTH, MAX_HEALTH }; // Initialize both players' health points
    int currentRow, currentColumn; // Current player position
    char board[SIZE][SIZE]; // Game board
    
    // Initialize game board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '-';
        }
    }
    
    // Set initial player positions to random cells
    currentRow = generateRandomInt(0, SIZE - 1);
    currentColumn = generateRandomInt(0, SIZE - 1);
    board[currentRow][currentColumn] = 'P'; // Player 1 symbol on game board
    currentRow = generateRandomInt(0, SIZE - 1);
    currentColumn = generateRandomInt(0, SIZE - 1);
    board[currentRow][currentColumn] = 'E'; // Player 2 symbol on game board

    // Game Loop
    while (!allPlayersLost(healthPoints)) {
        // Print game board and player health points
        printf("Game Board:\n");
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
        printf("Player 1 Health: %d\n", healthPoints[0]);
        printf("Player 2 Health: %d\n", healthPoints[1]);
        
        // Get player move input
        printf("Player %d, enter a direction to move (UP/DOWN/LEFT/RIGHT): ", playerTurn + 1);
        char direction[5];
        scanf("%s", direction);
        
        // Move player and update game board
        switch (direction[0]) {
            case 'U':
                if (currentRow > 0) {
                    board[currentRow][currentColumn] = '-'; // Clear current player cell
                    currentRow--;
                }
                break;
            case 'D':
                if (currentRow < SIZE - 1) {
                    board[currentRow][currentColumn] = '-'; // Clear current player cell
                    currentRow++;
                }
                break;
            case 'L':
                if (currentColumn > 0) {
                    board[currentRow][currentColumn] = '-'; // Clear current player cell
                    currentColumn--;
                }
                break;
            case 'R':
                if (currentColumn < SIZE - 1) {
                    board[currentRow][currentColumn] = '-'; // Clear current player cell
                    currentColumn++;
                }
                break;
            default:
                printf("Invalid direction. Try again.\n");
                break;
        }
        board[currentRow][currentColumn] = (playerTurn == 0) ? 'P' : 'E'; // Update new player cell on game board
        
        // Check for events on current cell
        int event = generateRandomInt(1, 10);
        if (event <= 3) { // 30% chance of meeting a friendly survivor
            printf("You met a friendly survivor who gave you a health boost!\n");
            healthPoints[playerTurn] += generateRandomInt(20, 50);
            if (healthPoints[playerTurn] > MAX_HEALTH) {
                healthPoints[playerTurn] = MAX_HEALTH;
            }
        } else if (event >= 8) { // 20% chance of encountering an enemy
            printf("You encountered an enemy and a battle begins!\n");
            int enemyHealth = generateRandomInt(50, 100);
            while (healthPoints[playerTurn] > 0 && enemyHealth > 0) {
                printf("Player %d's Health: %d\n", playerTurn + 1, healthPoints[playerTurn]);
                printf("Enemy Health: %d\n", enemyHealth);
                int damage = generateRandomInt(10, 20);
                printf("You attack the enemy for %d damage!\n", damage);
                enemyHealth -= damage;
                if (enemyHealth > 0) { // Enemy gets to attack if still alive
                    damage = generateRandomInt(10, 20);
                    printf("The enemy attacks you for %d damage!\n", damage);
                    healthPoints[playerTurn] -= damage;
                }
            }
            if (healthPoints[playerTurn] <= 0) {
                printf("Player %d has lost and is out of the game!\n", playerTurn + 1);
            } else {
                printf("You have defeated the enemy and earned a health boost!\n");
                healthPoints[playerTurn] += generateRandomInt(20, 50);
                if (healthPoints[playerTurn] > MAX_HEALTH) {
                    healthPoints[playerTurn] = MAX_HEALTH;
                }
            }
        }
        
        // Switch to next player's turn
        playerTurn = (playerTurn == 0) ? 1 : 0;
    }
    
    // Game Over
    printf("All players lost. Game Over!\n");
    return 0;
}