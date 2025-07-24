//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25

// Global variables
char board[HEIGHT][WIDTH];
int shipX, shipY;
int score;

// Function to initialize the game board with spaces
void initBoard() {
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to place the ship at the bottom of the board
void placeShip() {
    shipX = WIDTH/2;
    shipY = HEIGHT - 1;
    board[shipY][shipX] = '^';
}

// Function to print the game board
void printBoard() {
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    printf("Score: %d\n", score);
}

// Function to update the position of the ship based on user input
void updateShip(char direction) {
    board[shipY][shipX] = ' ';
    if(direction == 'a' && shipX > 0) {
        shipX--;
    }
    else if(direction == 'd' && shipX < WIDTH - 1) {
        shipX++;
    }
    board[shipY][shipX] = '^';
}

// Function to add a new enemy at the top of the board
void addEnemy() {
    int x = rand() % WIDTH;
    board[0][x] = 'X';
}

// Function to move all enemies down by one row
void moveEnemiesDown() {
    for(int i = HEIGHT - 1; i >= 0; i--) {
        for(int j = 0; j < WIDTH; j++) {
            if(board[i][j] == 'X' && i < HEIGHT - 1) {
                if(board[i+1][j] == '^') {
                    // Enemy has hit the ship, game is over
                    printf("GAME OVER\n");
                    printf("Final Score: %d\n", score);
                    exit(0);
                }
                else {
                    board[i+1][j] = 'X';
                    board[i][j] = ' ';
                }
            }
        }
    }
}

// Function to check if the game has ended (i.e. no enemies left)
int checkGameEnd() {
    for(int i = 0; i < WIDTH; i++) {
        if(board[0][i] == 'X') {
            return 0;
        }
    }
    return 1;
}

int main() {
    // Seed random number generator
    srand(time(NULL));
    
    // Initialize game board
    initBoard();
    
    // Place ship and add some initial enemies
    placeShip();
    for(int i = 0; i < 3; i++) {
        addEnemy();
    }
    
    // Game loop
    char input;
    while(1) {
        // Get user input
        scanf(" %c", &input);
        
        // Update ship position and print board
        updateShip(input);
        printBoard();
        
        // Move enemies down and add new enemies
        moveEnemiesDown();
        addEnemy();
        
        // Check if game has ended
        if(checkGameEnd()) {
            printf("You won!\n");
            printf("Final Score: %d\n", score);
            exit(0);
        }
        
        // Increase score
        score += 10;
    }
    
    return 0;
}