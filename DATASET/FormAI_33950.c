//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

// Constants
#define ROWS 30
#define COLUMNS 50
#define PADDLE_WIDTH 5
#define BALL_SPEED 100000
#define PADDLE_SPEED 1

// Global variables
char screen[ROWS][COLUMNS], ball, paddle[PADDLE_WIDTH] = "---", ballX, ballY, paddleX;
int brickCount = 0, score = 0;

// Function to initialize the screen
void initScreen() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            if(i == ROWS - 1) {
                screen[i][j] = '-';
            } else if(j == 0 || j == COLUMNS - 1) {
                screen[i][j] = '|';
            } else {
                screen[i][j] = ' ';
            }
        }
    }
}

// Function to print the screen
void printScreen() {
    system("clear"); // Clear the screen
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            printf("%c", screen[i][j]);
        }
        printf("\n");
    }
    printf("Score: %d\n", score); // Print the score
}

// Function to generate a random number
int randomNumber(int min, int max) {
    srand(time(NULL));
    int number = (rand() % (max - min + 1)) + min;
    return number;
}

// Function to move the ball
void moveBall() {
    // Move the ball to the new position
    screen[ballY][ballX] = ' ';
    ballY--;
    if(ballY < 1) { // If the ball hits the ceiling
        ballY++;
    }
    if(ballY > ROWS - 2) { // If the ball goes out of screen
        printScreen();
        printf("Game Over!\n");
        sleep(2);
        exit(0); // Quit the game
    }
    if(ballX < 1) { // If the ball hits the left wall
        ballX = 1;
    }
    if(ballX > COLUMNS - 2) { // If the ball hits the right wall
        ballX = COLUMNS - 2;
    }
    screen[ballY][ballX] = ball;
    // If the ball hits the paddle
    if(ballY == ROWS - 2 && ballX >= paddleX && ballX < paddleX + PADDLE_WIDTH) {
        ballY++;
    }
    // If the ball hits a brick
    if(screen[ballY - 1][ballX] == '+') {
        ballY++;
        score++;
        brickCount--;
        if(brickCount == 0) { // If all the bricks are destroyed
            printScreen();
            printf("You Win!\n");
            sleep(2);
            exit(0); // Quit the game
        }
    }
}

// Function to move the paddle
void movePaddle(char direction) {
    // Move the paddle to the new position
    screen[ROWS - 2][paddleX] = ' ';
    if(direction == 'L' && paddleX > 1) { // If move left
        paddleX -= PADDLE_SPEED;
    }
    if(direction == 'R' && paddleX < COLUMNS - PADDLE_WIDTH - 1) { // If move right
        paddleX += PADDLE_SPEED;
    }
    for(int i = 0; i < PADDLE_WIDTH; i++) {
        screen[ROWS - 2][paddleX + i] = paddle[i];
    }
}

// Function to read key input
char readKey() {
    char key;
    struct termios oldt, newt;
    // Get the terminal settings
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    // Set the new terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    // Read the key
    key = getchar();
    // Restore the old terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return key;
}

int main() {
    // Setup the game
    initScreen();
    ball = '@';
    ballX = randomNumber(1, COLUMNS - 2);
    ballY = randomNumber(5, ROWS / 2);
    paddleX = (COLUMNS - PADDLE_WIDTH) / 2;
    // Generate the bricks
    for(int i = 0; i < ROWS / 2; i++) {
        for(int j = 1; j < COLUMNS - 1; j++) {
            if(i % 2 == 0 && j % 3 == 1) {
                screen[i][j] = '+';
                brickCount++;
            }
        }
    }
    // Start the game loop
    while(true) {
        // Move the ball
        moveBall();
        // Read the key input
        char key = readKey();
        // Move the paddle
        if(key == 'a') {
            movePaddle('L');
        } else if(key == 'd') {
            movePaddle('R');
        }
        // Print the screen
        printScreen();
        // Wait for a moment
        usleep(BALL_SPEED);
    }
    return 0;
}