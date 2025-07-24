//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ROWS 20
#define COLS 30
 
int board[ROWS][COLS];
int playerRow, playerCol;
int ghostRow, ghostCol;
int score = 0;
 
void initialize() { // function to initialize game board and player position
    int i, j;
 
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if ((i == 0) || (i == ROWS-1) || (j == 0) || (j == COLS-1)) {
                board[i][j] = -1; // make border of board with walls
            } else {
                board[i][j] = 0; // empty space in board
            }
        }
    }
 
    playerRow = ROWS/2; // Player starting position
    playerCol = COLS/2;
    board[playerRow][playerCol] = 1; // Set player on board
 
    ghostRow = 1 + rand() % (ROWS-2); // Randomly set ghost position
    ghostCol = 1 + rand() % (COLS-2);
    board[ghostRow][ghostCol] = 2; // Set ghost on board
}
 
void draw() { // function to draw game board
    int i, j;
 
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            switch (board[i][j]) { // print board element depending on it's value
                case -1:
                    printf("#");
                    break;
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf("C");
                    break;
                case 2:
                    printf("G");
                    break;
            }
        }
        printf("\n");
    }
    printf("Score: %d\n", score); // Print current score
}
 
void movePlayer(char move) { // function to move player on board depending on user keypress
    switch (move) {
        case 'w':
            if (board[playerRow-1][playerCol] != -1) { //check wall hit
                board[playerRow][playerCol] = 0;
                playerRow--;
                board[playerRow][playerCol] = 1;
            }
            break;
        case 'a':
            if (board[playerRow][playerCol-1] != -1) {
                board[playerRow][playerCol] = 0;
                playerCol--;
                board[playerRow][playerCol] = 1;
            }
            break;
        case 's':
            if (board[playerRow+1][playerCol] != -1) {
                board[playerRow][playerCol] = 0;
                playerRow++;
                board[playerRow][playerCol] = 1;
            }
            break;
        case 'd':
            if (board[playerRow][playerCol+1] != -1) {
                board[playerRow][playerCol] = 0;
                playerCol++;
                board[playerRow][playerCol] = 1;
            }
            break;
    }
}
 
void moveGhost() { // function to randomly move ghost on board
    int direction = rand() % 4;
    switch (direction) {
        case 0:
            if (board[ghostRow-1][ghostCol] != -1) {
                board[ghostRow][ghostCol] = 0;
                ghostRow--;
                board[ghostRow][ghostCol] = 2;
            }
            break;
        case 1:
            if (board[ghostRow][ghostCol-1] != -1) {
                board[ghostRow][ghostCol] = 0;
                ghostCol--;
                board[ghostRow][ghostCol] = 2;
            }
            break;
        case 2:
            if (board[ghostRow+1][ghostCol] != -1) {
                board[ghostRow][ghostCol] = 0;
                ghostRow++;
                board[ghostRow][ghostCol] = 2;
            }
            break;
        case 3:
            if (board[ghostRow][ghostCol+1] != -1) {
                board[ghostRow][ghostCol] = 0;
                ghostCol++;
                board[ghostRow][ghostCol] = 2;
            }
            break;
    }
}
 
void checkCollision() { // function to check whether player and ghost collided
    if (playerRow == ghostRow && playerCol == ghostCol) { // if collided, print game over and exit
        printf("Game Over - You were caught!\n");
        exit(0);
    }
}
 
void checkWin() { // function to check whether player won the game
    if (score >= 10) { // if score is greater than or equal to 10, print win and exit
        printf("You Win - Congratulations!\n");
        exit(0);
    }
}
 
int main() { // main function to run game
    char move;
 
    srand(time(NULL)); // Initialize random seed
 
    initialize();
    draw();
 
    while (1) { // infinite loop to run game
        printf("Enter Move (W A S D): ");
        scanf(" %c", &move); // receive player movement input
 
        movePlayer(move); // move player on board
 
        moveGhost(); // move ghost on board
 
        checkCollision(); // check for player-ghost collision
 
        if (board[playerRow][playerCol] == 3) { // If player reaches food, update score and empty square
            score++;
            board[playerRow][playerCol] = 0;
        }
 
        checkWin(); // Check for player winning
 
        draw(); // Draw game board
    }
 
    return 0;
}