//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

// Define constants for game board size
#define ROWS 20
#define COLS 40

// Define constants for game object size and speed
#define BALL_SIZE 1
#define PADDLE_WIDTH 5
#define PADDLE_HEIGHT 1
#define PADDLE_SPEED 2
#define BRICK_WIDTH 3
#define BRICK_HEIGHT 1

// Define game objects
typedef struct {
    int x, y, dx, dy, size;
} Ball;

typedef struct {
    int x, y, width, height, speed, score, lives;
} Paddle;

typedef struct {
    int x, y, width, height, lives, hits, visible;
} Brick;

// Define function prototypes
void initBoard(char board[ROWS][COLS]);
void printBoard(char board[ROWS][COLS], Ball ball, Paddle paddle, Brick bricks[]);
void moveBall(Ball *ball);
void movePaddle(Paddle *paddle, int direction);
void createBricks(Brick bricks[]);
int checkCollision(Ball ball, Paddle paddle, Brick bricks[]);
void resetBall(Ball *ball);
void resetPaddle(Paddle *paddle);
void gameOver(int score);
int getch(void);

int main() {
    char board[ROWS][COLS];
    Ball ball = {COLS/2, ROWS/2, 1, -1, BALL_SIZE};
    Paddle paddle = {COLS/2 - PADDLE_WIDTH/2, ROWS - PADDLE_HEIGHT - 1, PADDLE_WIDTH, PADDLE_HEIGHT, PADDLE_SPEED, 0, 3};
    Brick bricks[ROWS/2*COLS/4];
    
    // Initialize game board and create bricks
    initBoard(board);
    createBricks(bricks);

    // Game loop
    while (paddle.lives > 0) {
        system("clear");

        // Move ball and paddle
        moveBall(&ball);
        int direction = getch();
        if (direction == 'a') {
            movePaddle(&paddle, -1);
        } else if (direction == 'd') {
            movePaddle(&paddle, 1);
        }

        // Check for collisions between ball, paddle, and bricks
        int hit = checkCollision(ball, paddle, bricks);
        
        // Print game board and objects
        printBoard(board, ball, paddle, bricks);
        
        // Check if game is over and reset ball and paddle if necessary
        if (ball.y >= ROWS) {
            resetBall(&ball);
            resetPaddle(&paddle);
            paddle.lives--;
        } else if (hit == 1) {
            resetBall(&ball);
            paddle.score++;
        } else if (hit == 2) {
            resetBall(&ball);
        }

        // Sleep to control game speed
        usleep(10000);
    }

    // Game over, print final score
    gameOver(paddle.score);

    return 0;
}

// Initialize game board with spaces
void initBoard(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }
}

// Print game board, ball, paddle, and bricks
void printBoard(char board[ROWS][COLS], Ball ball, Paddle paddle, Brick bricks[]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (i == ball.y && j == ball.x) {
                printf("o");
            } else if (i >= paddle.y && i < paddle.y + paddle.height && j >= paddle.x && j < paddle.x + paddle.width) {
                printf("#");
            } else {
                int k;
                for (k = 0; k < ROWS/2*COLS/4; k++) {
                    if (i >= bricks[k].y && i < bricks[k].y + bricks[k].height && j >= bricks[k].x && j < bricks[k].x + bricks[k].width && bricks[k].visible == 1) {
                        printf("X");
                        break;
                    }
                }
                if (k == ROWS/2*COLS/4) {
                    printf("%c", board[i][j]);
                }
            }
        }
        printf("\n");
    }
    printf("Score: %d    Lives: %d\n", paddle.score, paddle.lives);
}

// Move ball and check for collisions with walls and paddle
void moveBall(Ball *ball) {
    ball->x += ball->dx;
    ball->y += ball->dy;
    
    if (ball->x < 0 || ball->x >= COLS) {
        ball->dx = -ball->dx;
    }
    
    if (ball->y < 0) {
        ball->dy = -ball->dy;
    }
    
    if (ball->y == ROWS - 2 && ball->x >= ball->x && ball->x < ball->x + BALL_SIZE) {
        ball->dy = -ball->dy;
    }
}

// Move paddle left or right based on direction input
void movePaddle(Paddle *paddle, int direction) {
    int newx = paddle->x + direction * paddle->speed;
    if (newx >= 0 && newx < COLS - paddle->width) {
        paddle->x = newx;
    }
}

// Create bricks at the top of the game board
void createBricks(Brick bricks[]) {
    int i, j, k = 0;
    for (i = 0; i < ROWS/2; i++) {
        for (j = 0; j < COLS/4; j++) {
            bricks[k++] = (Brick){j*BRICK_WIDTH, i*BRICK_HEIGHT, BRICK_WIDTH, BRICK_HEIGHT, 1, 0, 1};
        }
    }
}

// Check for collisions between ball, paddle, and bricks
int checkCollision(Ball ball, Paddle paddle, Brick bricks[]) {
    int i;
    for (i = 0; i < ROWS/2*COLS/4; i++) {
        if (bricks[i].visible == 1) {
            if (ball.y == bricks[i].y + bricks[i].height - 1 && ball.x >= bricks[i].x && ball.x < bricks[i].x + bricks[i].width) {
                bricks[i].hits++;
                if (bricks[i].hits == bricks[i].lives) {
                    bricks[i].visible = 0;
                    return 1;
                }
            }
        }
    }
    if (ball.y == paddle.y - 1 && ball.x >= paddle.x && ball.x < paddle.x + paddle.width) {
        return 2;
    }
    return 0;
}

// Reset ball in the middle of the game board
void resetBall(Ball *ball) {
    ball->x = COLS/2;
    ball->y = ROWS/2;
    ball->dx = 1;
    ball->dy = -1;
}

// Reset paddle in the middle of the game board
void resetPaddle(Paddle *paddle) {
    paddle->x = COLS/2 - PADDLE_WIDTH/2;
    paddle->y = ROWS - PADDLE_HEIGHT - 1;
}

// Print game over message with final score
void gameOver(int score) {
    printf("GAME OVER\nFinal Score: %d\n", score);
}

// Get keyboard input without waiting for enter key
int getch(void) {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}