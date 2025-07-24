//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define ROWS 5
#define COLUMNS 10

// Function to display the game board
void displayBoard(char board[ROWS][COLUMNS]) {
    int i, j;

    printf("\n");

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            printf("%c", board[i][j]);
        }
        
        printf("\n");
    } 
}

// Function to initialize the game board
void initGameBoard(char board[ROWS][COLUMNS]) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            board[i][j] = '-';
        }
    }
}

// Function to update the game board
void updateGameBoard(char board[ROWS][COLUMNS], int posX, int posY) {
    board[posX][posY] = '*';
}

// Function to randomly generate the enemy ships
void generateEnemies(char board[ROWS][COLUMNS], int numEnemies) {
    int i, j, x, y;

    srand(time(NULL));

    for (i = 0; i < numEnemies; i++) {
        do {
            x = rand() % ROWS;
            y = rand() % COLUMNS;
        } while (board[x][y] != '-');

        board[x][y] = 'e'; 
    }
}

// Function to get user input for the position of the player's ship
bool getPlayerInput(char board[ROWS][COLUMNS], int *posX, int *posY) {
    char input[256];
    bool validInput = false;

    printf("Enter position (row, column) to place your ship: ");
    fgets(input, sizeof(input), stdin);

    // Remove new line character from input
    input[strlen(input) - 1] = '\0';

    // Parse input string to integers
    *posX = atoi(&input[0]);
    *posY = atoi(&input[2]);

    // Check if input is valid
    if (*posX >= 0 && *posX < ROWS && *posY >= 0 && *posY < COLUMNS) {
        if (board[*posX][*posY] == '-') {
            validInput = true;
        } else {
            printf("Invalid input. Position already occupied.\n");
        }
    } else {
        printf("Invalid input. Position out of range.\n");
    }

    return validInput;
}

// Function to check if any enemy ships are left
bool enemiesLeft(char board[ROWS][COLUMNS], int numEnemies) {
    int i, j, count = 0;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            if (board[i][j] == 'e') {
                count++;
            }
        }
    }

    return (count > 0);
}

// Function to simulate the player's turn
void playerTurn(char board[ROWS][COLUMNS], int *score) {
    int x, y;

    printf("Player's turn...\n");

    printf("Enter position (row, column) to fire: ");
    scanf("%d %d", &x, &y);

    if (board[x][y] == 'e') {
        *score += 10;
        printf("Hit! Score: %d\n", *score);
        board[x][y] = '-';
    } else {
        printf("Miss!\n");
    }
}

// Function to simulate the enemy's turn
void enemyTurn(char board[ROWS][COLUMNS], int *score) {
    int x, y;

    printf("Enemy's turn...\n");

    // Randomly select a position to fire at
    do {
        x = rand() % ROWS;
        y = rand() % COLUMNS;
    } while (board[x][y] == 'e' || board[x][y] == '*');

    if (board[x][y] == '-') {
        printf("Enemy missed!\n");
        board[x][y] = 'X';
    } else {
        *score -= 5;
        printf("Player hit! Score: %d\n", *score);
        board[x][y] = '-';
    }
}

int main() {
    char board[ROWS][COLUMNS];
    int numEnemies = 10;
    int posX, posY;
    int score = 0;

    initGameBoard(board);

    // Generate enemy ships
    generateEnemies(board, numEnemies);

    // Get player input for ship position
    while (!getPlayerInput(board, &posX, &posY));

    // Update board with player's ship
    updateGameBoard(board, posX, posY);

    // Start game loop
    while (enemiesLeft(board, numEnemies) && score >= 0) {
        displayBoard(board);

        playerTurn(board, &score);

        enemyTurn(board, &score);
    }

    if (score < 0) {
        printf("Game over! You lost.\n");
    } else {
        printf("Game over! You won. Final score: %d\n", score);
    }

    return 0;
}