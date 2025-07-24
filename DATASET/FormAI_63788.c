//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 60
#define HEIGHT 20

bool quit = false;
char screen[HEIGHT][WIDTH];
int paddle1 = 8;
int paddle2 = 8;
int ballX = 30;
int ballY = 10;
int ballDirX = -1;
int ballDirY = 0;
int player1Score = 0;
int player2Score = 0;

void initScreen() {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            screen[i][j] = ' ';
        }
    }
}

void printScreen() {
    system("cls");
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", screen[i][j]);
        }
        printf("\n");
    }
}

void updateBall() {
    ballX += ballDirX;
    ballY += ballDirY;
    if (ballX >= WIDTH - 1) {
        ballDirX = -1;
    } else if (ballX <= 0) {
        ballDirX = 1;
    } else if (ballY >= HEIGHT - 1) {
        ballDirY = -1;
    } else if (ballY <= 0) {
        ballDirY = 1;
    }
}

void updatePaddle1(int direction) {
    if (direction == -1 && paddle1 > 0) {
        paddle1--;
    } else if (direction == 1 && paddle1 < HEIGHT - 1) {
        paddle1++;
    }
}

void updatePaddle2(int direction) {
    if (direction == -1 && paddle2 > 0) {
        paddle2--;
    } else if (direction == 1 && paddle2 < HEIGHT - 1) {
        paddle2++;
    }
}

int main() {
    initScreen();
    while (!quit) {
        // AI opponent's paddle movement based on ball position
        if (ballY < paddle2) {
            updatePaddle2(-1);
        } else if (ballY > paddle2) {
            updatePaddle2(1);
        }

        updateBall();

        // update screen with ball and paddles
        int i, j;
        for (i = 0; i < HEIGHT; i++) {
            for (j = 0; j < WIDTH; j++) {
                if (i == ballY && j == ballX) {
                    screen[i][j] = 'O';
                } else if (i == paddle1 && j == 0) {
                    screen[i][j] = '|';
                } else if (i == paddle1 - 1 && j == 0) {
                    screen[i][j] = '|';
                } else if (i == paddle1 + 1 && j == 0) {
                    screen[i][j] = '|';
                } else if (i == paddle2 && j == WIDTH - 1) {
                    screen[i][j] = '|';
                } else if (i == paddle2 - 1 && j == WIDTH - 1) {
                    screen[i][j] = '|';
                } else if (i == paddle2 + 1 && j == WIDTH - 1) {
                    screen[i][j] = '|';
                } else {
                    screen[i][j] = ' ';
                }
            }
        }

        // check for collision with paddles and update ball direction
        if (((ballY >= paddle1 - 1 && ballY <= paddle1 + 1) && ballX == 1) ||
            ((ballY >= paddle2 - 1 && ballY <= paddle2 + 1) && ballX == WIDTH - 2)) {
            ballDirX = -ballDirX;
        }

        // check for out of bounds
        if (ballX < 0) {
            player2Score++;
            ballX = WIDTH / 2;
            ballY = HEIGHT / 2;
        } else if (ballX >= WIDTH) {
            player1Score++;
            ballX = WIDTH / 2;
            ballY = HEIGHT / 2;
        }

        printScreen();

        // check for game over
        if (player1Score == 3 || player2Score == 3) {
            printf("Game Over!\n");
            if (player1Score == 3) {
                printf("Player 1 wins!");
            } else {
                printf("Player 2 wins!");
            }
            quit = true;
        }

        // delay before next frame
        struct timespec ts;
        ts.tv_sec = 0;
        ts.tv_nsec = 1000000000 / 60;
        nanosleep(&ts, NULL);
    }

    return 0;
}