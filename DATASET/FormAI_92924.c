//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: authentic
#include <stdio.h>  // standard input/output library
#include <stdlib.h> // standard library
#include <time.h>   // time library

#define ROWS 5      // number of rows of blocks
#define COLS 10     // number of columns of blocks
#define BLOCK_WIDTH 8  // width of each block in characters
#define BLOCK_HEIGHT 3 // height of each block in characters
#define PADDLE_WIDTH 12 // width of the paddle in characters
#define PADDLE_HEIGHT 1 // height of the paddle in characters
#define BALL_WIDTH 1    // width of the ball in characters
#define BALL_HEIGHT 1   // height of the ball in characters

int blocks[ROWS][COLS]; // array to store the blocks
int paddleX, paddleY;   // coordinates of the paddle
int ballX, ballY;       // coordinates of the ball
int ballVX, ballVY;     // velocity of the ball
int lives;              // number of lives

void initBlocks() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            blocks[i][j] = 1; // all blocks are initially present
        }
    }
}

void initPaddle() {
    paddleX = COLS / 2 - PADDLE_WIDTH / 2;
    paddleY = ROWS - 1;
}

void initBall() {
    ballX = COLS / 2 - BALL_WIDTH / 2;
    ballY = ROWS - 2;
    ballVX = 1;
    ballVY = -1;
}

void drawBlocks() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (blocks[i][j] == 1) {
                int x = j * BLOCK_WIDTH;
                int y = i * BLOCK_HEIGHT;
                printf("\033[%d;%dH", y+1, x+1);
                printf("########");
                printf("\033[%d;1H", ROWS*BLOCK_HEIGHT+1);
            }
        }
    }
}

void drawPaddle() {
    int i, j;
    for (i = 0; i < PADDLE_HEIGHT; i++) {
        for (j = 0; j < PADDLE_WIDTH; j++) {
            int x = paddleX + j;
            int y = paddleY + i;
            printf("\033[%d;%dH", y+1, x+1);
            printf("=");
            printf("\033[%d;1H", ROWS*BLOCK_HEIGHT+2);
        }
    }
}

void drawBall() {
    int i, j;
    for (i = 0; i < BALL_HEIGHT; i++) {
        for (j = 0; j < BALL_WIDTH; j++) {
            int x = ballX + j;
            int y = ballY + i;
            printf("\033[%d;%dH", y+1, x+1);
            printf("O");
            printf("\033[%d;1H", ROWS*BLOCK_HEIGHT+3);
        }
    }
}

void clearScreen() {
    printf("\033[2J");
    printf("\033[1;1H");
}

void updateBall() {
    int nextX = ballX + ballVX;
    int nextY = ballY + ballVY;

    // check for collision with the walls
    if (nextX < 0 || nextX >= COLS) {
        ballVX = -ballVX;
    }
    if (nextY < 0) {
        ballVY = -ballVY;
    }

    // check for collision with the paddle
    if (nextY == paddleY - BALL_HEIGHT &&
        nextX >= paddleX &&
        nextX <= paddleX + PADDLE_WIDTH - BALL_WIDTH) {
        ballVY = -ballVY;
    }

    // check for collision with the blocks
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (blocks[i][j] == 1) {
                int blockX = j * BLOCK_WIDTH;
                int blockY = i * BLOCK_HEIGHT;
                if (nextY == blockY + BLOCK_HEIGHT &&
                    nextX >= blockX &&
                    nextX <= blockX + BLOCK_WIDTH - BALL_WIDTH) {
                    blocks[i][j] = 0;
                    ballVY = -ballVY;
                }
            }
        }
    }

    ballX += ballVX;
    ballY += ballVY;

    // check for loss of life
    if (ballY >= ROWS) {
        lives--;
        if (lives > 0) {
            initBall();
        }
    }
}

void updatePaddle() {
    char c = getchar();
    switch (c) {
        case 'a':
            if (paddleX > 0) {
                paddleX--;
            }
            break;
        case 'd':
            if (paddleX < COLS - PADDLE_WIDTH) {
                paddleX++;
            }
            break;
    }
}

int main() {
    srand(time(NULL)); // seed the random number generator
    lives = 3;
    initBlocks();
    initPaddle();
    initBall();
    clearScreen();

    while (1) {
        drawBlocks();
        drawPaddle();
        drawBall();

        printf("\033[%d;1H", ROWS*BLOCK_HEIGHT+4);
        printf("Lives: %d", lives);

        updateBall();
        updatePaddle();

        if (lives == 0) {
            printf("\033[%d;%dH", ROWS*BLOCK_HEIGHT/2, COLS*BLOCK_WIDTH/2-10);
            printf("Game Over");
            break;
        }
        if (blocks[0][0] == 0 && blocks[ROWS-1][COLS-1] == 0) {
            printf("\033[%d;%dH", ROWS*BLOCK_HEIGHT/2, COLS*BLOCK_WIDTH/2-10);
            printf("You Win!");
            break;
        }
    }

    return 0;
}