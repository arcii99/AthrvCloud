//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 60
#define HEIGHT 20
#define PADDLE_SIZE 3
#define BALL_SPEED 1

int ballX = WIDTH / 2;
int ballY = HEIGHT / 2;
int ballVelocityX = BALL_SPEED;
int ballVelocityY = BALL_SPEED;

int playerPaddleY = HEIGHT / 2 - PADDLE_SIZE / 2;
int aiPaddleY = HEIGHT / 2 - PADDLE_SIZE / 2;

int playerScore = 0;
int aiScore = 0;

int getRand(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void clearScreen() {
    system("cls");
}

void drawBorders() {
    int i, j;
    for (i = 0; i < HEIGHT + 2; i++) {
        for (j = 0; j < WIDTH + 2; j++) {
            if ((i == 0 || i == HEIGHT + 1) && (j == 0 || j == WIDTH + 1)) {
                printf("+");
            } else if (i == 0 || i == HEIGHT + 1) {
                printf("-");
            } else if (j == 0 || j == WIDTH + 1) {
                printf("|");
            } else if (j == ballX && i == ballY) {
                printf("*");
            } else if (j == 1 && i >= playerPaddleY && i < playerPaddleY + PADDLE_SIZE) {
                printf("|");
            } else if (j == WIDTH && i >= aiPaddleY && i < aiPaddleY + PADDLE_SIZE) {
                printf("|");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("Player Score: %d\n", playerScore);
    printf("AI Score: %d\n", aiScore);
}

int main() {
    srand(time(NULL));
    while (playerScore < 5 && aiScore < 5) {
        drawBorders();
        ballX += ballVelocityX;
        ballY += ballVelocityY;

        if (ballY == 1 || ballY == HEIGHT) {
            ballVelocityY = -ballVelocityY;
        }

        if (ballX == 2 && ballY >= playerPaddleY && ballY < playerPaddleY + PADDLE_SIZE) {
            ballVelocityX = -ballVelocityX;
        } else if (ballX == 1) {
            aiScore++;
            ballX = WIDTH / 2;
            ballY = HEIGHT / 2;
            ballVelocityX = BALL_SPEED;
            ballVelocityY = BALL_SPEED;
        }

        if (ballX == WIDTH && ballY >= aiPaddleY && ballY < aiPaddleY + PADDLE_SIZE) {
            ballVelocityX = -ballVelocityX;
        } else if (ballX == WIDTH + 1) {
            playerScore++;
            ballX = WIDTH / 2;
            ballY = HEIGHT / 2;
            ballVelocityX = -BALL_SPEED;
            ballVelocityY = BALL_SPEED;
        }

        if (ballX == WIDTH / 2) {
            if (aiPaddleY + PADDLE_SIZE / 2 < ballY) {
                aiPaddleY++;
            } else {
                aiPaddleY--;
            }
        }

        if (playerScore < 5 && aiScore < 5) {
            clearScreen();
        }
    }
    printf("Game Over!\n");
    printf("Final Score:\n");
    printf("Player Score: %d\n", playerScore);
    printf("AI Score: %d\n", aiScore);
    return 0;
}