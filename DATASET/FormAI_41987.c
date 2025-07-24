//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Constants for the game
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 20
#define PADDLE_WIDTH 5
#define BALL_SPEED 100000 // smaller is faster

typedef struct {
    int x, y;
    int dx, dy;
} Ball;

// Function to move the ball
void moveBall(Ball *ball, int paddleX, int paddleY) {
    // Check for paddle collision
    if (ball->y == paddleY && ball->x >= paddleX && ball->x < paddleX + PADDLE_WIDTH) {
        ball->dy = -1;
    }
    // Check for wall collisions
    if (ball->x == 0 || ball->x == SCREEN_WIDTH - 1) {
        ball->dx *= -1;
    }
    if (ball->y == 0) {
        ball->dy = 1;
    }
    // Move the ball
    ball->x += ball->dx;
    ball->y += ball->dy;
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Initialize the ball
    Ball ball = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, rand() % 2 ? 1 : -1, -1};

    // Initialize the paddle
    int paddleX = SCREEN_WIDTH / 2 - PADDLE_WIDTH / 2;
    int paddleY = SCREEN_HEIGHT - 2;

    // Loop until the ball goes off the bottom of the screen
    bool gameOver = false;
    while (!gameOver) {
        // Clear the screen
        system("clear");

        // Draw the ball
        for (int i = 0; i < ball.y; i++) {
            printf("\n");
        }
        for (int i = 0; i < ball.x; i++) {
            printf(" ");
        }
        printf("O");
        printf("\n");

        // Draw the paddle
        for (int i = 0; i < paddleY; i++) {
            printf("\n");
        }
        for (int i = 0; i < paddleX; i++) {
            printf(" ");
        }
        for (int i = 0; i < PADDLE_WIDTH; i++) {
            printf("#");
        }
        printf("\n");

        // Move the ball
        moveBall(&ball, paddleX, paddleY);

        // Check for game over
        if (ball.y == SCREEN_HEIGHT - 1) {
            gameOver = true;
        }

        // Sleep to control ball speed
        usleep(BALL_SPEED);
    }
    printf("Game over!\n");

    return 0;
}