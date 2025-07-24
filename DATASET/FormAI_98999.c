//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define screen size and paddle dimensions
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 40
#define PADDLE_WIDTH 7
#define PADDLE_HEIGHT 2

// Function to randomly generate initial direction of ball
int randDir() {
    srand(time(NULL));
    int dir = rand() % 4; // random number between 0 and 3

    // Return -1 if direction is left or up, 1 if right or down
    if (dir == 0)
        return -1;
    else if (dir == 1)
        return 1;
    else if (dir == 2)
        return -1;
    else
        return 1;
}

// Function to update ball position based on its current direction
void updateBall(int *x, int *y, int *dirX, int *dirY) {
    // Move ball
    *x += *dirX;
    *y += *dirY;

    // Reverse X direction if ball hits left or right wall
    if (*x <= 0 || *x >= SCREEN_WIDTH - 1)
        *dirX = -*dirX;

    // Reverse Y direction if ball hits top or bottom wall
    if (*y <= 0 || *y >= SCREEN_HEIGHT - 1)
        *dirY = -*dirY;
}

// Function to update AI opponent based on current ball position
void updateOpponent(int *paddleY, int ballY) {
    if (ballY < *paddleY + PADDLE_HEIGHT / 2)
        (*paddleY)--;
    else if (ballY > *paddleY + PADDLE_HEIGHT / 2)
        (*paddleY)++;
}

int main() {
    // Initialize game objects
    int ballX = SCREEN_WIDTH / 2;
    int ballY = SCREEN_HEIGHT / 2;
    int dirX = randDir(); // randomly generate initial direction of ball
    int dirY = randDir();
    int playerScore = 0;
    int opponentScore = 0;
    int playerPaddleY = SCREEN_HEIGHT / 2 - PADDLE_HEIGHT / 2;
    int opponentPaddleY = SCREEN_HEIGHT / 2 - PADDLE_HEIGHT / 2;

    // Main game loop
    bool gameOver = false;
    while (!gameOver) {
        // Clear screen
        system("clear");

        // Update ball position
        updateBall(&ballX, &ballY, &dirX, &dirY);

        // Update opponent paddle position
        updateOpponent(&opponentPaddleY, ballY);

        // Draw game objects on screen
        for (int i = 0; i < SCREEN_HEIGHT; i++) {
            for (int j = 0; j < SCREEN_WIDTH; j++) {
                // Draw ball
                if (i == ballY && j == ballX)
                    printf("O");
                // Draw player paddle
                else if (i >= playerPaddleY && i < playerPaddleY + PADDLE_HEIGHT && j == 1)
                    printf("|");
                // Draw opponent paddle
                else if (i >= opponentPaddleY && i < opponentPaddleY + PADDLE_HEIGHT && j == SCREEN_WIDTH - PADDLE_WIDTH - 1)
                    printf("|");
                // Draw top and bottom walls
                else if (i == 0 || i == SCREEN_HEIGHT - 1)
                    printf("-");
                // Draw score
                else if (i == 1 && j == SCREEN_WIDTH / 2 - 3)
                    printf("%d : %d", playerScore, opponentScore);
                // Draw empty space
                else
                    printf(" ");
            }
            printf("\n");
        }

        // Check for ball collision with player or opponent paddle
        if (ballX == 1 && ballY >= playerPaddleY && ballY < playerPaddleY + PADDLE_HEIGHT) {
            dirX = 1;
        }
        else if (ballX == SCREEN_WIDTH - PADDLE_WIDTH - 1 && ballY >= opponentPaddleY && ballY < opponentPaddleY + PADDLE_HEIGHT) {
            dirX = -1;
        }
        // If ball goes out of bounds, update score and reset ball position and direction
        else if (ballX <= 0 || ballX >= SCREEN_WIDTH - 1) {
            if (ballX <= 0)
                opponentScore++;
            else
                playerScore++;

            ballX = SCREEN_WIDTH / 2;
            ballY = SCREEN_HEIGHT / 2;
            dirX = randDir();
            dirY = randDir();
        }

        // Check for end game condition (first to reach 10 points)
        if (playerScore == 10 || opponentScore == 10)
            gameOver = true;
    }

    // Print game over message
    if (playerScore == 10)
        printf("Congratulations, you win!\n");
    else
        printf("Sorry, you lose.\n");

    return 0;
}