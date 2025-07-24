//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: multiplayer
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 21
#define COLS 21

int score = 0;
int numLives = 3;

// game board
char board[ROWS][COLS];

// game elements
char pacman = '<';
char ghost = 'G';
char pellet = '.';
char emptySpace = ' ';

// pacman coordinates
int pacman_x = 1;
int pacman_y = 1;

// ghost coordinates
int ghost_x = 10;
int ghost_y = 10;

// pellet coordinates
int pellet_x = 5;
int pellet_y = 5;

// initialize game board
void initializeBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = emptySpace;
        }
    }
}

// print game board
void displayBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// move pacman
void movePacman(char direction) {
    switch (direction) {
        case 'w':
            pacman_x--;
            break;
        case 'a':
            pacman_y--;
            break;
        case 's':
            pacman_x++;
            break;
        case 'd':
            pacman_y++;
            break;
        default:
            break;
    }
    
    // check for collision with ghost
    if (pacman_x == ghost_x && pacman_y == ghost_y) {
        numLives--;
        printf("Life lost! Lives: %d\n", numLives);
        pacman_x = 1;
        pacman_y = 1;
        ghost_x = 10;
        ghost_y = 10;
    }
    
    // check for collision with pellet
    if (pacman_x == pellet_x && pacman_y == pellet_y) {
        score++;
        printf("Score: %d\n", score);
        pellet_x = rand() % ROWS;
        pellet_y = rand() % COLS;
    }
    
    // update game board
    board[pacman_x][pacman_y] = pacman;
}

// move ghost
void moveGhost() {
    int dx = rand() % 3 - 1; // random movement in x direction
    int dy = rand() % 3 - 1; // random movement in y direction
    
    ghost_x += dx;
    ghost_y += dy;
    
    // check if ghost goes out of bounds
    if (ghost_x < 0) {
        ghost_x = 0;
    }
    if (ghost_x >= ROWS) {
        ghost_x = ROWS - 1;
    }
    if (ghost_y < 0) {
        ghost_y = 0;
    }
    if (ghost_y >= COLS) {
        ghost_y = COLS - 1;
    }
    
    // check for collision with pacman
    if (pacman_x == ghost_x && pacman_y == ghost_y) {
        numLives--;
        printf("Life lost! Lives: %d\n", numLives);
        pacman_x = 1;
        pacman_y = 1;
        ghost_x = 10;
        ghost_y = 10;
    }
    
    // update game board
    board[ghost_x][ghost_y] = ghost;
}

int main() {
    srand(time(NULL)); // seed random number generator
    
    initializeBoard();
    
    pellet_x = rand() % ROWS;
    pellet_y = rand() % COLS;
    
    // initialize game board with game elements
    board[pacman_x][pacman_y] = pacman;
    board[ghost_x][ghost_y] = ghost;
    board[pellet_x][pellet_y] = pellet;
    
    // main game loop
    while (numLives > 0) {
        displayBoard();
        
        char input;
        scanf(" %c", &input);
        
        movePacman(input);
        moveGhost();
    }
    
    printf("Game over! Final score: %d\n", score);
    
    return 0;
}