//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <termios.h>
#include <fcntl.h>

// Function to set up terminal for non-blocking input
void setupTerminal(struct termios *tty) {
    tcgetattr(STDIN_FILENO, tty); // Get current terminal settings
    tty->c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
    tty->c_cc[VMIN] = 0; // Set minimum number of characters for read
    tty->c_cc[VTIME] = 0; // Set timeout for read
    tcsetattr(STDIN_FILENO, TCSANOW, tty); // Apply new settings
}

// Function to reset terminal to original settings
void resetTerminal(struct termios *tty) {
    tcsetattr(STDIN_FILENO, TCSANOW, tty);
}

// Function to get a random integer in range [min, max]
int getRandomInt(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main(void) {
    srand(time(NULL)); // Seed random number generator

    // Set up terminal for non-blocking input
    struct termios oldtty, newtty;
    setupTerminal(&newtty);

    // Initialize variables
    int numRows = 6, numCols = 10;
    char board[numRows][numCols];
    int ballRow = getRandomInt(1, numRows - 2), ballCol = getRandomInt(1, numCols - 2);
    int ballDirRow = getRandomInt(-1, 1), ballDirCol = getRandomInt(-1, 1);
    int paddleRow = numRows - 1, paddleCol = numCols / 2;
    int score = 0;
    int gameOver = 0;

    // Initialize board
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (i == 0 || i == numRows - 1 || j == 0 || j == numCols - 1) {
                board[i][j] = '#'; // Draw border
            } else {
                board[i][j] = ' '; // Empty space
            }
        }
    }

    // Main game loop
    while (!gameOver) {
        // Clear screen and print board
        system("clear");
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                printf("%c", board[i][j]);
            }
            printf("\n");
        }

        // Check for ball hitting walls
        if (ballRow == 1 || ballRow == numRows - 2) {
            ballDirRow *= -1;
        }
        if (ballCol == 1 || ballCol == numCols - 2) {
            ballDirCol *= -1;
        }

        // Check for ball hitting paddle
        if (ballRow == paddleRow && ballCol >= paddleCol - 1 && ballCol <= paddleCol + 1) {
            ballDirRow *= -1;
            score++;
        }

        // Move ball and paddle
        ballRow += ballDirRow;
        ballCol += ballDirCol;
        if (ballCol < paddleCol - 1) {
            paddleCol--;
        } else if (ballCol > paddleCol + 1) {
            paddleCol++;
        }

        // Update board
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                if (i == ballRow && j == ballCol) {
                    board[i][j] = 'O';
                } else if (i == paddleRow && j >= paddleCol - 1 && j <= paddleCol + 1) {
                    board[i][j] = '=';
                } else if (i == numRows - 2 && j == numCols - 9) {
                    printf("Score: %d", score);
                    fflush(stdout);
                } else if (board[i][j] == 'O' || board[i][j] == '=') {
                    board[i][j] = ' ';
                }
            }
        }

        // Check for game over
        if (ballRow == numRows - 1) {
            gameOver = 1;
        }

        // Sleep to control game speed
        usleep(100000);
        
        // Check for user input to move paddle
        char input;
        if (read(STDIN_FILENO, &input, 1) == 1) {
            if (input == 'a' && paddleCol > 1) {
                paddleCol--;
            } else if (input == 'd' && paddleCol < numCols - 2) {
                paddleCol++;
            } else if (input == 'q') {
                gameOver = 1;
            }
        }
    }

    // Reset terminal to original settings
    resetTerminal(&newtty);

    // Print game over message
    system("clear");
    printf("Game over! Final score: %d\n", score);

    return 0;
}