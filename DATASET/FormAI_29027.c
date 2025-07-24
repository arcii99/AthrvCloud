//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

#define HEIGHT 20
#define WIDTH 40

char board[HEIGHT][WIDTH];
int ballX, ballY;
int paddleX, paddleY;
int score = 0;

// Function to get user input without waiting for "Enter"
char getch() {
    struct termios old, new;
    char ch;
    tcgetattr(0, &old);
    new = old;
    new.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(0, TCSANOW, &new);
    ch = getchar();
    tcsetattr(0, TCSANOW, &old);
    return ch;
}

// Recursive function to update ball position and check for collisions
void update_ball() {
    // Clear previous ball position
    board[ballY][ballX] = ' ';

    // Update ball position
    ballX++;
    ballY--;

    // Check for wall collisions
    if (ballX == 0 || ballX == WIDTH-1) {
        ballX--;
    }
    if (ballY == 0) {
        ballY++;
    }

    // Check for paddle collision
    if (ballY == paddleY && ballX >= paddleX && ballX <= paddleX+4) {
        score++;
        ballY++;
    }

    // Check for game over
    if (ballY == HEIGHT-1) {
        printf("\nGame Over! Your score is %d.\n", score);
        exit(0);
    }

    // Draw new ball position
    board[ballY][ballX] = 'O';

    // Draw updated game board
    system("clear");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }

    // Wait for a moment
    usleep(50000);

    // Call update_ball recursively
    update_ball();
}

int main() {
    // Initialize game board
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT-1) {
                board[i][j] = '-';
            }
            else if (j == 0 || j == WIDTH-1) {
                board[i][j] = '|';
            }
            else {
                board[i][j] = ' ';
            }
        }
    }

    // Initialize ball position
    srand(time(0));
    ballX = rand() % (WIDTH-2) + 1;
    ballY = HEIGHT-2;

    // Initialize paddle position
    paddleX = WIDTH/2-2;
    paddleY = HEIGHT-1;
    board[paddleY][paddleX] = '/';
    board[paddleY][paddleX+1] = '|';
    board[paddleY][paddleX+2] = '|';
    board[paddleY][paddleX+3] = '|';
    board[paddleY][paddleX+4] = '\\';

    // Draw initial game board
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }

    // Start game loop
    while (1) {
        // Get user input
        char input = getch();

        // Move paddle left
        if (input == 'a' && paddleX > 1) {
            board[paddleY][paddleX-2] = '/';
            board[paddleY][paddleX-1] = '|';
            board[paddleY][paddleX] = ' ';
            board[paddleY][paddleX+1] = ' ';
            board[paddleY][paddleX+2] = ' ';
            board[paddleY][paddleX+3] = ' ';
            board[paddleY][paddleX+4] = '\\';
            paddleX -= 2;
        }
        // Move paddle right
        else if (input == 'd' && paddleX < WIDTH-6) {
            board[paddleY][paddleX-1] = ' ';
            board[paddleY][paddleX] = ' ';
            board[paddleY][paddleX+1] = '/';
            board[paddleY][paddleX+2] = '|';
            board[paddleY][paddleX+3] = '|';
            board[paddleY][paddleX+4] = '|';
            board[paddleY][paddleX+5] = '\\';
            paddleX += 2;
        }

        // Call update_ball recursively
        update_ball();
    }

    return 0;
}