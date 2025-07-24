//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// define game board
#define ROWS 20
#define COLS 60

// define paddle properties
#define PADDLE_HEIGHT 4
#define PADDLE_WIDTH 1

// define ball properties
#define BALL_XSTART (COLS / 2)
#define BALL_YSTART (ROWS / 2)
#define BALL_XVEL 1.5
#define BALL_YVEL 1.5

// define game over criteria
#define SCORE_TO_WIN 5

// define player and opponent score
int playerScore = 0;
int opponentScore = 0;

// initialize game board
char board[ROWS][COLS];

// initialize paddle position;
int playerPaddleY;
int opponentPaddleY;

// initialize ball position and velocity
double ballX = BALL_XSTART;
double ballY = BALL_YSTART;
double ballXVel = BALL_XVEL;
double ballYVel = BALL_YVEL;

/**
 * Initialize game board with blank spaces
 */
void initializeBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }
}

/**
 * Draw game board including players and ball
 */
void drawBoard() {
    // draw ball
    board[(int)ballY][(int)ballX] = 'O';

    // draw player paddle
    for (int i = 0; i < PADDLE_HEIGHT; i++) {
        board[playerPaddleY + i][1] = '|';
    }

    // draw opponent paddle
    for (int i = 0; i < PADDLE_HEIGHT; i++) {
        board[opponentPaddleY + i][COLS - 2] = '|';
    }

    // draw score
    printf("Player Score: %d\tOpponent Score: %d\n", playerScore, opponentScore);

    // draw top wall
    for (int i = 0; i < COLS + 2; i++) {
        printf("-");
    }
    printf("\n");

    // draw game board
    for (int i = 0; i < ROWS; i++) {
        printf("|");
        for (int j = 0; j < COLS; j++) {
            printf("%c", board[i][j]);
        }
        printf("|\n");
    }

    // draw bottom wall
    for (int i = 0; i < COLS + 2; i++) {
        printf("-");
    }
    printf("\n");
}

/**
 * Reset ball position and velocity to initial values
 */
void resetBall() {
    ballX = BALL_XSTART;
    ballY = BALL_YSTART;
    ballXVel = BALL_XVEL;
    ballYVel = BALL_YVEL;
}

/**
 * Handle collision of ball and game board walls
 */
void handleWallCollision() {
    // check collision with top or bottom walls
    if (ballY <= 0 || ballY >= ROWS - 1) {
        ballYVel *= -1;
    }

    // check collision with left wall (player scores)
    if (ballX <= 0) {
        resetBall();
        opponentScore++;
        if (opponentScore == SCORE_TO_WIN) {
            printf("Game Over. Opponent wins!");
            exit(0);
        }
    }

    // check collision with right wall (opponent scores)
    if (ballX >= COLS - 1) {
        resetBall();
        playerScore++;
        if (playerScore == SCORE_TO_WIN) {
            printf("Game Over. Player wins!");
            exit(0);
        }
    }
}

/**
 * Handle collision of ball and paddles
 */
void handlePaddleCollision() {
    // player paddle collision
    if (ballX == 2 && ballY >= playerPaddleY && ballY < playerPaddleY + PADDLE_HEIGHT) {
        ballXVel *= -1.1;
        ballYVel *= 1.1;
    }

    // opponent paddle collision
    if (ballX == COLS - 3 && ballY >= opponentPaddleY && ballY < opponentPaddleY + PADDLE_HEIGHT) {
        ballXVel *= -1.1;
        ballYVel *= 1.1;
    }
}

/**
 * Move opponent paddle based on ball position
 */
void moveOpponentPaddle() {
    if (ballY > opponentPaddleY + PADDLE_HEIGHT / 2) {
        opponentPaddleY++;
    } else if (ballY < opponentPaddleY + PADDLE_HEIGHT / 2) {
        opponentPaddleY--;
    }
}

int main() {
    // seed random number generator
    srand(time(NULL));

    // initialize player and opponent paddle positions
    playerPaddleY = ROWS / 2 - PADDLE_HEIGHT / 2;
    opponentPaddleY = ROWS / 2 - PADDLE_HEIGHT / 2;

    // initialize game board with blank spaces
    initializeBoard();

    while (1) {
        // clear screen
        system("clear");

        // handle collision of ball and game board walls
        handleWallCollision();

        // handle collision of ball and paddles
        handlePaddleCollision();

        // move opponent paddle based on ball position
        moveOpponentPaddle();

        // update ball position
        ballX += ballXVel;
        ballY += ballYVel;

        // draw game board
        drawBoard();

        // wait for 50 milliseconds
        usleep(50000);
    }

    return 0;
}