//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20
#define MAX_GHOSTS 4
#define MAX_SCORE 100


int score;
int gameOver;
int pacmanX, pacmanY;
int ghostX[MAX_GHOSTS], ghostY[MAX_GHOSTS];
int numGhosts;

// Function to print the game board
void printBoard(char board[][WIDTH]) {
    printf("\n\n");
    for(int i=0; i < HEIGHT; i++) {
        for(int j=0; j < WIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

// Function to update the game board after each move
void updateBoard(char board[][WIDTH]) {
    board[pacmanY][pacmanX] = 'C';
    for(int i=0; i < numGhosts; i++) {
        board[ghostY[i]][ghostX[i]] = 'G';
    }
    printBoard(board);
}

// Function to check for collision with ghosts
void checkCollision() {
    for(int i=0; i < numGhosts; i++) {
        if(pacmanX == ghostX[i] && pacmanY == ghostY[i]) {
            gameOver = 1;
        }
    }
}

// Function to move ghosts randomly
void moveGhosts() {
    for(int i=0; i < numGhosts; i++) {
        switch(rand() % 4) {
            case 0:
                if(ghostX[i] > 0) ghostX[i]--;
                break;
            case 1:
                if(ghostX[i] < WIDTH-1) ghostX[i]++;
                break;
            case 2:
                if(ghostY[i] > 0) ghostY[i]--;
                break;
            case 3:
                if(ghostY[i] < HEIGHT-1) ghostY[i]++;
                break;
        }
    }
}

// Main function to run the game
int main(void) {

    // Initialize game variables
    char board[HEIGHT][WIDTH];
    srand(time(NULL));
    numGhosts = MAX_GHOSTS;
    score = 0;
    gameOver = 0;
    pacmanX = WIDTH/2;
    pacmanY = HEIGHT/2;
    for(int i=0; i < MAX_GHOSTS; i++) {
        ghostX[i] = rand() % WIDTH;
        ghostY[i] = rand() % HEIGHT;
    }

    // Initialize game board
    for(int i=0; i < HEIGHT; i++) {
        for(int j=0; j < WIDTH; j++) {
            if(i == pacmanY && j == pacmanX) {
                board[i][j] = 'C';
            } else {
                board[i][j] = '.';
            }
            for(int k=0; k < numGhosts; k++) {
                if(i == ghostY[k] && j == ghostX[k]) {
                    board[i][j] = 'G';
                }
            }
        }
    }

    // Main game loop
    while(!gameOver) {
        updateBoard(board);
        char input;
        printf("Score: %d\n", score);
        printf("Use WASD keys to move: ");
        scanf(" %c", &input);
        switch(input) {
            case 'w':
                if(pacmanY > 0) pacmanY--;
                break;
            case 'a':
                if(pacmanX > 0) pacmanX--;
                break;
            case 's':
                if(pacmanY < HEIGHT-1) pacmanY++;
                break;
            case 'd':
                if(pacmanX < WIDTH-1) pacmanX++;
                break;
        }
        moveGhosts();
        checkCollision();
        score++;
        if(score >= MAX_SCORE) {
            gameOver = 1;
            printf("Congratulations! You won!");
        }
    }

    // Print final score
    printf("\n\nFinal Score: %d\n", score);

    return 0;
}