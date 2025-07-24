//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BOARD_WIDTH 80
#define BOARD_HEIGHT 24
#define PADDLE_WIDTH 3
#define MAX_SCORE 7

typedef struct {
    int x, y, velocity_x, velocity_y;
} Ball;

typedef struct {
    int x, y, score;
} Paddle;

// Initialize the ball and paddles
void initGame(Ball *ball, Paddle *playerPaddle, Paddle *computerPaddle) {
    // Set the ball to the center of the board
    ball->x = BOARD_WIDTH / 2;
    ball->y = BOARD_HEIGHT / 2;

    // Randomize the ball's velocity
    srand(time(NULL));
    if (rand() % 2 == 0) {
        ball->velocity_x = 1;
    } else {
        ball->velocity_x = -1;
    }
    if (rand() % 2 == 0) {
        ball->velocity_y = 1;
    } else {
        ball->velocity_y = -1;
    }

    // Initialize the player's paddle to the left side of the board
    playerPaddle->x = 1;
    playerPaddle->y = BOARD_HEIGHT / 2 - PADDLE_WIDTH / 2;
    playerPaddle->score = 0;

    // Initialize the computer's paddle to the right side of the board
    computerPaddle->x = BOARD_WIDTH - 2;
    computerPaddle->y = BOARD_HEIGHT / 2 - PADDLE_WIDTH / 2;
    computerPaddle->score = 0;
}

// Update the ball's position based on its velocity
void updateBall(Ball *ball) {
    ball->x += ball->velocity_x;
    ball->y += ball->velocity_y;
}

// Implement the computer's movement using a simple AI algorithm
void updateComputerPaddle(Ball *ball, Paddle *computerPaddle) {
    if (ball->velocity_x < 0) {
        if (ball->y < computerPaddle->y + PADDLE_WIDTH / 2) {
            computerPaddle->y--;
        } else if (ball->y > computerPaddle->y + PADDLE_WIDTH / 2) {
            computerPaddle->y++;
        }
    } else {
        if (computerPaddle->y + PADDLE_WIDTH / 2 < BOARD_HEIGHT / 2) {
            computerPaddle->y++;
        } else {
            computerPaddle->y--;
        }
    }
}

// Check if the ball has collided with the top or bottom of the board
void checkWallCollision(Ball *ball) {
    if (ball->y <= 0 || ball->y >= BOARD_HEIGHT - 1) {
        ball->velocity_y *= -1;
    }
}

// Check if the ball has collided with either paddle, and update its velocity accordingly
void checkPaddleCollision(Ball *ball, Paddle *playerPaddle, Paddle *computerPaddle) {
    if (ball->x == playerPaddle->x + 1 && ball->y >= playerPaddle->y && ball->y < playerPaddle->y + PADDLE_WIDTH) {
        ball->velocity_x *= -1;
    } else if (ball->x == computerPaddle->x - 1 && ball->y >= computerPaddle->y && ball->y < computerPaddle->y + PADDLE_WIDTH) {
        ball->velocity_x *= -1;
    } else if (ball->x == playerPaddle->x) {
        computerPaddle->score++;
        initGame(ball, playerPaddle, computerPaddle);
    } else if (ball->x == computerPaddle->x) {
        playerPaddle->score++;
        initGame(ball, playerPaddle, computerPaddle);
    }
}

// Display the board and paddles on the screen
void displayBoard(Ball *ball, Paddle *playerPaddle, Paddle *computerPaddle) {
    int i, j;
    for (i = 0; i < BOARD_HEIGHT; i++) {
        for (j = 0; j < BOARD_WIDTH; j++) {
            if (i == 0 || i == BOARD_HEIGHT - 1) {
                printf("-");
            } else if (j == playerPaddle->x && i >= playerPaddle->y && i < playerPaddle->y + PADDLE_WIDTH) {
                printf("|");
            } else if (j == computerPaddle->x && i >= computerPaddle->y && i < computerPaddle->y + PADDLE_WIDTH) {
                printf("|");
            } else if (j == ball->x && i == ball->y) {
                printf("O");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("Player Score: %d\n", playerPaddle->score);
    printf("Computer Score: %d\n", computerPaddle->score);
}

int main() {
    // Initialize the ball and paddles
    Ball ball;
    Paddle playerPaddle, computerPaddle;
    initGame(&ball, &playerPaddle, &computerPaddle);

    // Loop until one of the players reaches the maximum score
    while (playerPaddle.score < MAX_SCORE && computerPaddle.score < MAX_SCORE) {
        // Update the ball's position and check for collisions
        updateBall(&ball);
        checkWallCollision(&ball);
        checkPaddleCollision(&ball, &playerPaddle, &computerPaddle);

        // Update the computer's paddle using the AI algorithm
        updateComputerPaddle(&ball, &computerPaddle);

        // Display the board and paddles
        displayBoard(&ball, &playerPaddle, &computerPaddle);
    }

    // Print the winner
    if (playerPaddle.score >= MAX_SCORE) {
        printf("Congratulations! You won!\n");
    } else {
        printf("Sorry, you lost. Better luck next time!\n");
    }

    return 0;
}