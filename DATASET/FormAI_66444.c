//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25 // Number of rows in the game board
#define COLS 50 // Number of columns in the game board
#define MAX_PILLS 25 // Maximum number of pills that can be on the board at once

// Global variables
int board[ROWS][COLS]; // Game board
int pills[MAX_PILLS][2]; // Array to keep track of pill coordinates
int pill_count = 0; // Number of pills currently on the board
int pacman_row, pacman_col; // Pac-Man position
int score = 0; // Player's score
int lives = 3; // Number of lives the player has left

void init_board() {
    // Initialize game board with 0's
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }
    
    // Add walls to the game board
    for (int i = 0; i < ROWS; i++) {
        board[i][0] = board[i][COLS-1] = 1;
    }
    for (int j = 0; j < COLS; j++) {
        board[0][j] = board[ROWS-1][j] = 1;
    }
    
    // Add Pac-Man to the game board
    pacman_row = ROWS/2;
    pacman_col = COLS/2;
    board[pacman_row][pacman_col] = 2;
    
    // Add pills to the game board
    srand(time(NULL)); // Seed random number generator
    int pill_max_row = ROWS - 2; // Pill rows must be between 1 and ROWS-2
    int pill_max_col = COLS - 2; // Pill columns must be between 1 and COLS-2
    while (pill_count < MAX_PILLS) {
        int row = rand() % pill_max_row + 1;
        int col = rand() % pill_max_col + 1;
        if (board[row][col] == 0) {
            pills[pill_count][0] = row;
            pills[pill_count][1] = col;
            pill_count++;
            board[row][col] = 3;
        }
    }
}

void draw_board() {
    // Clear screen
    system("clear");
    
    // Draw game board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 0) { // Empty space
                printf(" ");
            } else if (board[i][j] == 1) { // Wall
                printf("#");
            } else if (board[i][j] == 2) { // Pac-Man
                printf("O");
            } else if (board[i][j] == 3) { // Pill
                printf(".");
            }
        }
        printf("\n");
    }
    
    // Print player's score and lives left
    printf("Score: %d\tLives: %d\n", score, lives);
}

void move_pacman(char direction) {
    int new_row = pacman_row;
    int new_col = pacman_col;
    
    switch (direction) {
        case 'w':
            new_row--;
            break;
        case 'a':
            new_col--;
            break;
        case 's':
            new_row++;
            break;
        case 'd':
            new_col++;
            break;
    }
    
    if (board[new_row][new_col] == 0 || board[new_row][new_col] == 3) {
        // Move Pac-Man to new position
        board[pacman_row][pacman_col] = 0;
        pacman_row = new_row;
        pacman_col = new_col;
        board[pacman_row][pacman_col] = 2;
        
        if (board[new_row][new_col] == 3) {
            // Remove pill from board and increase player's score
            for (int i = 0; i < MAX_PILLS; i++) {
                if (pills[i][0] == new_row && pills[i][1] == new_col) {
                    board[new_row][new_col] = 0;
                    pills[i][0] = -1; // Mark pill as eaten
                    score += 10;
                    break;
                }
            }
        }
    } else if (board[new_row][new_col] == 1) {
        // Pac-Man hits a wall, do nothing
    }
}

void remove_eaten_pills() {
    for (int i = 0; i < MAX_PILLS; i++) {
        if (pills[i][0] != -1 && board[pills[i][0]][pills[i][1]] == 0) {
            // Pill has been eaten, remove it from the pills array
            pills[i][0] = -1;
            pill_count--;
        }
    }
}

void check_gameover() {
    if (lives <= 0) {
        printf("Game over! Final score: %d\n", score);
        exit(0);
    }
}

int main() {
    init_board();
    
    while (1) { // Game loop
        draw_board();
        
        // Get user input
        char input;
        printf("Enter direction (w/a/s/d): ");
        scanf("%c", &input);
        while (getchar() != '\n'); // Clear input buffer
        
        move_pacman(input);
        remove_eaten_pills();
        check_gameover();
    }
    
    return 0;
}