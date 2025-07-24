//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 30
#define COLS 50
#define BRICKWIDTH 5
#define BRICKHEIGHT 3
#define BALLCHAR 'O'
#define PADDLECHAR '_'
#define BRICKCHAR '+'

bool isBrick[BRICKHEIGHT][BRICKWIDTH] = { false };

void setupBricks() {
    for (int i = 0; i < BRICKHEIGHT; i++) {
        for (int j = 0; j < BRICKWIDTH; j++) {
            isBrick[i][j] = true;
        }
    }
}

void drawBricks() {
    for (int i = 0; i < BRICKHEIGHT; i++) {
        for (int j = 0; j < BRICKWIDTH; j++) {
            if (isBrick[i][j]) {
                printf("%c", BRICKCHAR);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    // Set up game board
    char board[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }

    // Set up ball position and velocity
    int ballX = COLS / 2;
    int ballY = ROWS / 2;
    int ballVX = -1;
    int ballVY = -1;

    // Set up paddle position and size
    int paddleX = COLS / 2;
    int paddleY = ROWS - 1;
    int paddleWidth = 5;

    // Set up game loop
    setupBricks();
    bool isPlaying = true;
    while (isPlaying) {
        system("clear"); // Clear console

        // Move ball
        ballX += ballVX;
        ballY += ballVY;

        // Check for wall collisions and change direction if necessary
        if (ballX <= 0 || ballX >= COLS - 1) {
            ballVX *= -1;
        }
        if (ballY <= 0) {
            ballVY *= -1;
        }
        if (ballY >= ROWS - 1) {
            isPlaying = false; // Game over
        }

        // Check for paddle collision and change direction if necessary
        if (ballY == paddleY && ballX >= paddleX && ballX < paddleX + paddleWidth) {
            ballVY *= -1;
        }

        // Draw game board
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (i == ballY && j == ballX) {
                    printf("%c", BALLCHAR); // Draw ball
                } else if (i == paddleY && j >= paddleX && j < paddleX + paddleWidth) {
                    printf("%c", PADDLECHAR); // Draw paddle
                } else if (i < BRICKHEIGHT && j < BRICKWIDTH && isBrick[i][j]) {
                    printf("%c", BRICKCHAR); // Draw bricks
                } else {
                    printf("%c", board[i][j]); // Draw empty space
                }
            }
            printf("\n");
        }

        // Wait to refresh screen
        struct timespec delay = {0, 50000000}; // 50ms
        nanosleep(&delay, NULL);
    }

    // Game over
    printf("Game over!\n");

    return 0;
}