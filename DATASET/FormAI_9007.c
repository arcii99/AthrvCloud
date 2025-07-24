//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24
#define INITIAL_SPEED 100000
#define PADDLE_SIZE 3

int score = 0;
int difficulty = 0;
int speed = INITIAL_SPEED;

char board[HEIGHT][WIDTH];
int ballX = WIDTH / 2, ballY = HEIGHT / 2;
int ballDir = -1; // -1: up-left, 1: up-right
int paddleY = HEIGHT / 2;


// AI opponent logic
void ai_move() {
    if (ballY < paddleY)
        paddleY--;
    else if (ballY > paddleY + PADDLE_SIZE - 1)
        paddleY++;
}


// Update the ball's position and direction
void update_ball() {
    int nextX = ballX + ballDir;
    int nextY = ballY + ballDir;

    // Hit the top or bottom wall
    if (nextY < 0 || nextY >= HEIGHT) {
        ballDir *= -1;
        nextY = ballY + ballDir;
    }

    // Hit the left paddle
    if (nextX == 3 && nextY >= paddleY && nextY < paddleY + PADDLE_SIZE) {
        score++;
        ballDir = 1;
        nextX = ballX + ballDir;
    }

    // Hit the left wall (scored a point)
    if (nextX < 0) {
        score--;
        ballX = WIDTH / 2;
        ballY = HEIGHT / 2;
        ballDir = -1;
        paddleY = HEIGHT / 2;
        speed = INITIAL_SPEED + (score * difficulty * 10000);
        return;
    }

    ballX = nextX;
    ballY = nextY;
}


// Draw the game board
void draw_board() {
    system("clear");
    memset(board, ' ', sizeof(board[0][0]) * WIDTH * HEIGHT);

    // Draw walls
    for (int y = 0; y < HEIGHT; y++) {
        board[y][0] = '|';
        board[y][WIDTH-1] = '|';
    }
    for (int x = 0; x < WIDTH; x++) {
        board[0][x] = '-';
        board[HEIGHT-1][x] = '-';
    }

    // Draw the ball
    board[ballY][ballX] = 'o';

    // Draw the paddle
    for (int y = 0; y < PADDLE_SIZE; y++)
        board[paddleY+y][3] = '#';

    // Draw the score
    char scoreStr[10];
    sprintf(scoreStr, "%d", score);
    strncpy(&board[0][WIDTH-strlen(scoreStr)-2], scoreStr, strlen(scoreStr));
    board[0][WIDTH-strlen(scoreStr)-3] = 'S';
    board[0][WIDTH-1] = '|';

    // Print the board
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++)
            putchar(board[y][x]);
        putchar('\n');
    }

    // Slow down the game
    usleep(speed);
}


int main() {
    srand(time(NULL));

    // Reset the score and game state
    score = 0;
    ballX = WIDTH / 2;
    ballY = HEIGHT / 2;
    ballDir = -1;
    paddleY = HEIGHT / 2;

    // Main game loop
    while (1) {
        draw_board();
        update_ball();
        ai_move();
    }

    return 0;
}