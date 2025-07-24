//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Constants for the game
#define ROWS 25
#define COLS 50
#define MAX_LIVES 3

// Constants for the paddle and ball
#define PADDLE_WIDTH 5
#define PADDLE_HEIGHT 1
#define BALL_START_ROW (ROWS-2)
#define BALL_START_COL (COLS/2)
#define BALL_START_DX 1
#define BALL_START_DY -1

// Constants for the bricks
#define BRICK_ROWS 5
#define BRICK_COLS 10
#define BRICK_START_ROW 2
#define BRICK_START_COL 2
#define BRICK_WIDTH 4
#define BRICK_HEIGHT 2

// Matrix to store the state of the game
char matrix[ROWS][COLS];

// Variables for the paddle and ball
int paddleX;
int ballX, ballY;
int ballDX, ballDY;

// Variables for the bricks
bool bricks[BRICK_ROWS][BRICK_COLS];
int numBricks;

// Variables for the game
int score;
int lives;

// Function to draw the matrix
void drawMatrix() {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            putchar(matrix[row][col]);
        }
        putchar('\n');
    }
}

// Function to clear the matrix
void clearMatrix() {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            matrix[row][col] = ' ';
        }
    }
}

// Function to draw the paddle
void drawPaddle() {
    for (int x = paddleX; x < paddleX+PADDLE_WIDTH; x++) {
        matrix[ROWS-1][x] = '=';
    }
}

// Function to move the paddle left
void movePaddleLeft() {
    if (paddleX > 0) {
        paddleX--;
    }
}

// Function to move the paddle right
void movePaddleRight() {
    if (paddleX+PADDLE_WIDTH < COLS) {
        paddleX++;
    }
}

// Function to update the position of the ball
void updateBallPosition() {
    int nextX = ballX + ballDX;
    int nextY = ballY + ballDY;

    // Check for collision with the paddle
    if (nextY == ROWS-1) {
        for (int x = paddleX; x < paddleX+PADDLE_WIDTH; x++) {
            if (nextX == x) {
                ballDY = -ballDY;
                break;
            }
        }
    }

    // Check for collision with the walls
    if (nextX == 0 || nextX == COLS-1) {
        ballDX = -ballDX;
    }
    if (nextY == 0) {
        ballDY = -ballDY;
    }

    // Check for collision with a brick
    int brickRow = (nextY-BRICK_START_ROW) / BRICK_HEIGHT;
    if (brickRow >= 0 && brickRow < BRICK_ROWS) {
        int brickCol = (nextX-BRICK_START_COL) / BRICK_WIDTH;
        if (brickCol >= 0 && brickCol < BRICK_COLS) {
            if (bricks[brickRow][brickCol]) {
                bricks[brickRow][brickCol] = false;
                numBricks--;
                score += 10;
                if (nextY == BRICK_START_ROW+brickRow*BRICK_HEIGHT || nextY == BRICK_START_ROW+brickRow*BRICK_HEIGHT+BRICK_HEIGHT-1) {
                    ballDY = -ballDY;
                } else {
                    ballDX = -ballDX;
                }
                if (numBricks == 0) {
                    printf("Congratulations! You won!\n");
                    exit(0);
                }
            }
        }
    }

    // Update the position of the ball
    ballX += ballDX;
    ballY += ballDY;

    // Check for game over
    if (ballY == ROWS-1) {
        lives--;
        printf("You lost a life! You have %d lives left.\n", lives);
        if (lives == 0) {
            printf("Game over! You scored %d points.\n", score);
            exit(0);
        } else {
            ballX = BALL_START_COL;
            ballY = BALL_START_ROW;
            ballDX = BALL_START_DX;
            ballDY = BALL_START_DY;
        }
    }
}

// Recursive function to play the game
void playGame() {
    clearMatrix();
    drawPaddle();

    // Draw the bricks
    for (int row = 0; row < BRICK_ROWS; row++) {
        for (int col = 0; col < BRICK_COLS; col++) {
            if (bricks[row][col]) {
                for (int r = 0; r < BRICK_HEIGHT; r++) {
                    for (int c = 0; c < BRICK_WIDTH; c++) {
                        matrix[BRICK_START_ROW+row*BRICK_HEIGHT+r][BRICK_START_COL+col*BRICK_WIDTH+c] = '#';
                    }
                }
            }
        }
    }

    // Draw the ball
    matrix[ballY][ballX] = 'O';

    // Update the position of the ball
    updateBallPosition();

    // Draw the score and number of lives
    printf("Score: %d, Lives: %d\n", score, lives);

    // Draw the matrix and wait for 100 ms
    drawMatrix();
    usleep(100000);

    // Move the paddle based on user input
    int c = getchar();
    if (c == 'a') {
        movePaddleLeft();
    } else if (c == 'd') {
        movePaddleRight();
    }

    // Call the function recursively
    playGame();
}

// Main function
int main() {
    srand(time(NULL));

    // Initialize the matrix
    clearMatrix();

    // Initialize the paddle and ball
    paddleX = COLS/2 - PADDLE_WIDTH/2;
    ballX = BALL_START_COL;
    ballY = BALL_START_ROW;
    ballDX = BALL_START_DX;
    ballDY = BALL_START_DY;

    // Initialize the bricks
    for (int row = 0; row < BRICK_ROWS; row++) {
        for (int col = 0; col < BRICK_COLS; col++) {
            bricks[row][col] = true;
        }
    }
    numBricks = BRICK_ROWS*BRICK_COLS;

    // Initialize the game
    score = 0;
    lives = MAX_LIVES;

    // Start the game
    playGame();

    return 0;
}