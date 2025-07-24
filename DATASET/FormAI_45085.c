//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: complex
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

#define ROW 23
#define COL 80

// Structure for every brick in the game
struct Brick {
    int health;
    int x;
    int y;
};

// Function to set terminal properties such as hiding cursor and keypress input
void setTermProps() {
    struct termios tattr;
    tcgetattr(STDIN_FILENO, &tattr);
    tattr.c_lflag &= ~(ICANON|ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &tattr);
    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
    printf("\x1b[?25l"); // Hide cursor
}

// Function to get key input from the user
int getKey() {
    int keyPressed = getchar();
    if (keyPressed < 0) {
        return -1;
    }
    if (keyPressed == 27) { // Handling arrow inputs
        getchar(); // [ character
        keyPressed = getchar();
        return keyPressed;
    }
    return keyPressed;
}

// Main function
int main() {
    // Clearing the terminal
    printf("\033[2J");
    // Setting terminal properties and hiding cursor
    setTermProps();
    // Initializing variables
    struct Brick bricks[8][14];
    int ballX = 41;
    int ballY = 20;
    int ballVelocityX = -1;
    int ballVelocityY = -1;
    int paddleX = 37;
    bool gameOver = false;
    int brickCount = 8 * 14;
    int score = 0;
    // Initializing bricks
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 14; j++) {
            struct Brick brick;
            brick.health = rand() % 3 + 1;
            brick.x = j * 4 + 2;
            brick.y = i * 2 + 2;
            bricks[i][j] = brick;
        }
    }
    // Game loop
    while (!gameOver) {
        // Updating ball position
        ballX += ballVelocityX;
        ballY += ballVelocityY;
        // Handling ball collision with walls and ceiling
        if (ballX == 1 || ballX == COL - 2) {
            ballVelocityX = -ballVelocityX;
        } else if (ballY == 1) {
            ballVelocityY = -ballVelocityY;
        }
        // Handling ball collision with paddle
        if (ballY == ROW - 3 && ballX >= paddleX - 4 && ballX <= paddleX + 4) {
            ballVelocityY = -ballVelocityY;
            ballVelocityX = (ballX - paddleX) / 4;
        }
        // Checking if ball missed paddle and hit ground
        if (ballY == ROW - 2) {
            gameOver = true;
            printf("\033[22;37HGame Over! Your Score: %d\n", score);
            continue;
        }
        // Handling ball collision with bricks
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 14; j++) {
                struct Brick brick = bricks[i][j];
                if (brick.health > 0 && ballX >= brick.x && ballX < brick.x + 4 && ballY >= brick.y && ballY < brick.y + 2) {
                    brick.health--;
                    bricks[i][j] = brick;
                    if (brick.health == 0) {
                        brickCount--;
                        score += 10;
                    } else {
                        score += 1;
                    }
                    if (ballX == brick.x || ballX == brick.x + 3) {
                        ballVelocityX = -ballVelocityX;
                    } else {
                        ballVelocityY = -ballVelocityY;
                    }
                    if (brickCount == 0) {
                        gameOver = true;
                        printf("\033[22;37HYou Won! Your Score: %d\n", score);
                        continue;
                    }
                }
            }
        }
        // Handling paddle movement
        int keyPressed = getKey();
        if (keyPressed == 67 && paddleX <= COL - 10) {
            paddleX++;
        } else if (keyPressed == 68 && paddleX >= 2) {
            paddleX--;
        }
        // Rendering the game
        printf("\033[1;1H");
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (ballX == j && ballY == i) {
                    printf("O");
                } else if (i == ROW - 2 && j >= paddleX - 4 && j <= paddleX + 4) {
                    printf("-");
                } else {
                    bool brickFound = false;
                    for (int k = 0; k < 8; k++) {
                        for (int l = 0; l < 14; l++) {
                            struct Brick brick = bricks[k][l];
                            if (brick.x <= j && j < brick.x + 4 && brick.y <= i && i < brick.y + 2 && brick.health > 0) {
                                printf("\033[%d;31m#\033[0m", k + 1);
                                brickFound = true;
                                break;
                            }
                        }
                        if (brickFound) {
                            break;
                        }
                    }
                    if (!brickFound) {
                        printf(" ");
                    }
                }
            }
            printf("\n");
        }
        printf("\033[20;1HScore: %d", score);
        fflush(stdout);
        usleep(30000); // Delay to control game speed
    }
    // Reseting terminal properties and showing cursor
    printf("\033[22;1H");
    printf("\x1b[?25h");
    struct termios tattr;
    tcgetattr(STDIN_FILENO, &tattr);
    tattr.c_lflag |= (ICANON|ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &tattr);
    return 0;
}