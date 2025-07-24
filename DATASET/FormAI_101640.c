//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: excited
#include <stdio.h>

// board size
#define ROWS 25
#define COLS 25

// board elements
#define WALL '#'
#define DOT '.'
#define PACMAN 'C'
#define GHOST 'A'

// player movement directions
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

char board[ROWS][COLS]; // the game board
int score = 0; // player score
int lives = 3; // player lives
int gameover = 0; // flag for game over
int dx, dy; // player movement direction

// function to initialize the board
void initBoard() {
    // initialize with dots
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            board[i][j] = DOT;
        }
    }
    
    // add walls
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(i == 0 || i == ROWS-1 || j == 0 || j == COLS-1) {
                board[i][j] = WALL;
            }
        }
    }
    
    // add player and ghost
    board[ROWS/2][COLS/2] = PACMAN;
    board[ROWS/4][COLS/4] = GHOST;
    
    // set initial movement direction
    dx = 0;
    dy = 0;
}

// function to print the board
void printBoard() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    
    printf("Score: %d, Lives: %d\n", score, lives);
}

// function to update the game state
void updateGame(char key) {
    // move player
    if(key == UP) {
        dx = -1;
        dy = 0;
    }
    else if(key == DOWN) {
        dx = 1;
        dy = 0;
    }
    else if(key == LEFT) {
        dx = 0;
        dy = -1;
    }
    else if(key == RIGHT) {
        dx = 0;
        dy = 1;
    }
    
    // check for collision with ghost
    if(board[ROWS/2+dx][COLS/2+dy] == GHOST) {
        lives--;
        if(lives == 0) {
            gameover = 1;
        }
        else {
            // reset player and ghost positions
            board[ROWS/2][COLS/2] = PACMAN;
            board[ROWS/4][COLS/4] = GHOST;
        }
    }
    else {
        // move player
        board[ROWS/2+dx][COLS/2+dy] = PACMAN;
        board[ROWS/2][COLS/2] = DOT;
        
        // update score
        score++;
        
        // check for game over
        if(score == ROWS*COLS-1) {
            gameover = 1;
        }
    }
}

int main() {
    initBoard();
    
    while(!gameover) {
        printBoard();
        
        char key;
        printf("Enter direction (w/s/a/d): ");
        scanf("%c", &key);
        
        updateGame(key);
    }
    
    printf("Game over! Score: %d\n", score);
    
    return 0;
}