//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define WIDTH 40 // Board width
#define HEIGHT 20 // Board height
#define BRICK_ROWS 3 // Number of brick rows
#define BRICK_COLS 7 // Number of brick columns

/* Define brick struct */
typedef struct {
    int x, y; // Position of the brick
    int value; // Value of the brick
    int active; // Whether the brick is active or not
} Brick;

/* Function to initialize the board */
void initBoard(char board[HEIGHT][WIDTH]) {
    int i, j;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            board[i][j] = ' ';
        }
    }
}

/* Function to initialize the bricks */
void initBricks(Brick bricks[BRICK_ROWS][BRICK_COLS]) {
    int i, j;

    for (i = 0; i < BRICK_ROWS; i++) {
        for (j = 0; j < BRICK_COLS; j++) {
            bricks[i][j].x = j * 5 + 2;
            bricks[i][j].y = i + 2;
            bricks[i][j].value = BRICK_COLS - j;
            bricks[i][j].active = 1;
        }
    }
}

/* Function to draw the board */
void drawBoard(char board[HEIGHT][WIDTH]) {
    int i, j;

    system("clear"); // Clear screen
    printf("+=================================+\n");
    for (i = 0; i < HEIGHT; i++) {
        printf("|");
        for (j = 0; j < WIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("|\n");
    }
    printf("+=================================+\n");
}

/* Function to draw the bricks */
void drawBricks(Brick bricks[BRICK_ROWS][BRICK_COLS], char board[HEIGHT][WIDTH]) {
    int i, j;

    for (i = 0; i < BRICK_ROWS; i++) {
        for (j = 0; j < BRICK_COLS; j++) {
            if (bricks[i][j].active) {
                board[bricks[i][j].y][bricks[i][j].x] = bricks[i][j].value + '0';
            }
        }
    }
}

/* Function to draw the paddle */
void drawPaddle(int paddleX, char board[HEIGHT][WIDTH]) {
    int i;

    for (i = paddleX; i < paddleX + 6; i++) {
        board[HEIGHT - 3][i] = '=';
    }
}

/* Function to draw the ball */
void drawBall(int ballX, int ballY, char board[HEIGHT][WIDTH]) {
    board[ballY][ballX] = 'O';
}

/* Function to move the paddle */
int movePaddle() {
    int ch;
    struct termios old, new;

    tcgetattr(0, &old); // Get the old terminal settings
    new = old;
    new.c_lflag &= ~ICANON; // Turn off canonical mode
    new.c_lflag &= ~ECHO; // Turn off echoing
    tcsetattr(0, TCSANOW, &new); // Set the new terminal settings

    ch = getchar();

    tcsetattr(0, TCSANOW, &old); // Restore the old terminal settings

    if (ch == 'a') {
        return -1;
    } else if (ch == 'd') {
        return 1;
    } else {
        return 0;
    }
}

/* Function to check for collisions with the walls */
void checkWallCollision(int *ballX, int *ballY, int *ballDX, int *ballDY) {
    if (*ballX == 0 || *ballX == WIDTH - 1) {
        *ballDX = -(*ballDX);
    }

    if (*ballY == 0) {
        *ballDY = -(*ballDY);
    } else if (*ballY == HEIGHT - 1) {
        // Game over
        printf("Game over!\n");
        exit(0);
    }
}

/* Function to check for collisions with the paddle */
void checkPaddleCollision(int ballX, int ballY, int paddleX, int *ballDX, int *ballDY) {
    int i;

    if (ballY == HEIGHT - 4) {
        for (i = paddleX; i < paddleX + 6; i++) {
            if (ballX == i) {
                *ballDY = -(*ballDY);
                *ballDX += (ballX - (paddleX + 2)) / 2;
                break;
            }
        }
    }
}

/* Function to check for collisions with the bricks */
void checkBrickCollision(int ballX, int ballY, Brick bricks[BRICK_ROWS][BRICK_COLS], int *ballDX, int *ballDY, int *score) {
    int i, j;

    for (i = 0; i < BRICK_ROWS; i++) {
        for (j = 0; j < BRICK_COLS; j++) {
            if (bricks[i][j].active && ballX >= bricks[i][j].x && ballX < bricks[i][j].x + 5 && ballY == bricks[i][j].y) {
                bricks[i][j].active = 0;
                *score += bricks[i][j].value;
                if (*ballDY > 0) {
                    *ballDY = -(*ballDY);
                }
                break;
            }
        }
    }
}

/* Main function */
int main() {
    char board[HEIGHT][WIDTH];
    Brick bricks[BRICK_ROWS][BRICK_COLS];
    int paddleX = WIDTH / 2 - 3;
    int ballX = WIDTH / 2;
    int ballY = HEIGHT - 4;
    int ballDX = 1;
    int ballDY = -1;
    int score = 0;
    int i, j;
    
    srand(time(NULL)); // Seed random number generator

    initBoard(board);
    initBricks(bricks);

    while (1) {
        drawBoard(board);
        drawBricks(bricks, board);
        drawPaddle(paddleX, board);
        drawBall(ballX, ballY, board);

        // Move the paddle
        paddleX += movePaddle();
        if (paddleX < 1) {
            paddleX = 1;
        } else if (paddleX > WIDTH - 7) {
            paddleX = WIDTH - 7;
        }

        // Move the ball
        ballX += ballDX;
        ballY += ballDY;

        // Check for collisions
        checkWallCollision(&ballX, &ballY, &ballDX, &ballDY);
        checkPaddleCollision(ballX, ballY, paddleX, &ballDX, &ballDY);
        checkBrickCollision(ballX, ballY, bricks, &ballDX, &ballDY, &score);

        // Update score
        printf("Score: %d\n", score);

        // Pause
        usleep(50000);
    }

    return 0;
}