//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5 // Number of rows in the game board
#define COLS 10 // Number of columns in the game board

#define PLAYER_CHAR 'P' // Player character
#define INVADER_CHAR 'I' // Invader character
#define BLANK_CHAR ' ' // Blank character
#define SHOT_CHAR 'X' // Shot character

#define PLAYER_START_ROW 4 // Starting row of player
#define PLAYER_START_COL 5 // Starting column of player

#define INVADER_START_ROW 0 // Starting row of invaders
#define INVADER_START_COL 0 // Starting column of invaders

#define MAX_INVADERS 10 // Maximum number of invaders on the board

// Game board
char board[ROWS][COLS];

// Player position
int playerRow, playerCol;

// Invader positions
int invaderRows[MAX_INVADERS];
int invaderCols[MAX_INVADERS];
int numInvaders;

// Shot position
int shotRow, shotCol;

// Function prototypes
void initBoard();
void displayBoard();
void movePlayer(int dir);
void moveInvaders();
void shoot();
void updateBoard();

// Main function
int main() {
    // Initialize random number generator
    srand(time(NULL));
    
    // Initialize game board
    initBoard();
    
    // Display game board
    displayBoard();
    
    // Main game loop
    while (1) {
        // Check for player input
        printf("Enter direction (left=l, right=r, shoot=s): ");
        char input;
        scanf(" %c", &input);
        if (input == 'l') {
            movePlayer(-1); // Move player left
        } else if (input == 'r') {
            movePlayer(1); // Move player right
        } else if (input == 's') {
            shoot(); // Shoot a shot
        }
        
        // Move invaders
        moveInvaders();
        
        // Update game board
        updateBoard();
        displayBoard();
        
        // Check for game over condition
        if (numInvaders == 0) {
            printf("You have defeated the invaders!\n");
            break;
        }
    }
    
    return 0;
}

// Initialize game board
void initBoard() {
    // Initialize player position
    playerRow = PLAYER_START_ROW;
    playerCol = PLAYER_START_COL;
    
    // Initialize invader positions
    numInvaders = MAX_INVADERS;
    for (int i = 0; i < MAX_INVADERS; i++) {
        invaderRows[i] = INVADER_START_ROW;
        invaderCols[i] = INVADER_START_COL + i;
    }
    
    // Initialize shot position
    shotRow = -1;
    shotCol = -1;
    
    // Initialize game board with blank characters
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = BLANK_CHAR;
        }
    }
    
    // Set player character on board
    board[playerRow][playerCol] = PLAYER_CHAR;
    
    // Set invader characters on board
    for (int i = 0; i < numInvaders; i++) {
        board[invaderRows[i]][invaderCols[i]] = INVADER_CHAR;
    }
}

// Display game board
void displayBoard() {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Move player in specified direction
void movePlayer(int dir) {
    // Check if moving out of bounds
    if (playerCol + dir < 0 || playerCol + dir >= COLS) {
        return;
    }
    
    // Move player
    board[playerRow][playerCol] = BLANK_CHAR;
    playerCol += dir;
    board[playerRow][playerCol] = PLAYER_CHAR;
}

// Move invaders
void moveInvaders() {
    // Move invaders in random direction
    for (int i = 0; i < numInvaders; i++) {
        int dir = rand() % 3 - 1; // -1, 0, or 1
        if (invaderCols[i] + dir < 0 || invaderCols[i] + dir >= COLS) {
            continue; // Do not move out of bounds
        }
        board[invaderRows[i]][invaderCols[i]] = BLANK_CHAR;
        invaderCols[i] += dir;
        board[invaderRows[i]][invaderCols[i]] = INVADER_CHAR;
    }
}

// Shoot a shot
void shoot() {
    // Check if shot is already on board
    if (shotRow != -1 && shotCol != -1) {
        return;
    }
    
    // Initialize shot position
    shotRow = playerRow - 1;
    shotCol = playerCol;
    board[shotRow][shotCol] = SHOT_CHAR;
}

// Update game board
void updateBoard() {
    // Move shot up one row
    if (shotRow != -1 && shotCol != -1) {
        board[shotRow][shotCol] = BLANK_CHAR;
        shotRow--;
        if (shotRow == -1) {
            shotCol = -1;
        } else {
            board[shotRow][shotCol] = SHOT_CHAR;
        }
    }
    
    // Remove invaders hit by shot
    for (int i = 0; i < numInvaders; i++) {
        if (shotRow == invaderRows[i] && shotCol == invaderCols[i]) {
            board[invaderRows[i]][invaderCols[i]] = BLANK_CHAR;
            invaderRows[i] = -1; // Mark for removal
            invaderCols[i] = -1; // Mark for removal
            numInvaders--;
            shotRow = -1;
            shotCol = -1;
        }
    }
    
    // Remove dead invaders
    int count = 0; // Number of dead invaders
    for (int i = 0; i < numInvaders; i++) {
        if (invaderRows[i] != -1 && invaderCols[i] != -1) {
            invaderRows[count] = invaderRows[i];
            invaderCols[count] = invaderCols[i];
            count++;
        }
    }
    numInvaders = count;
    
    // Reset shot position if no more invaders
    if (numInvaders == 0) {
        shotRow = -1;
        shotCol = -1;
    }
}