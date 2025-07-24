//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <pthread.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20

// Ball structure
typedef struct Ball
{
    int x;
    int y;
    int vx;
    int vy;
} Ball;

// Paddle structure
typedef struct Paddle
{
    int x;
    int y;
} Paddle;

// Global variables
Ball ball;
Paddle player1, player2;

// Function to set terminal in raw mode
void setRawMode(int fd)
{
    struct termios raw;
    tcgetattr(fd, &raw);
    raw.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(fd, TCSANOW, &raw);
}

// Function to update ball position
void updateBall()
{
    // Update ball position
    ball.x += ball.vx;
    ball.y += ball.vy;

    // Check for collision with walls
    if (ball.x < 0 || ball.x >= WIDTH)
    {
        ball.vx = -ball.vx;
    }

    if (ball.y < 0 || ball.y >= HEIGHT)
    {
        ball.vy = -ball.vy;
    }

    // Check for collision with paddles
    if (ball.x == player1.x && ball.y >= player1.y && ball.y <= player1.y + 3)
    {
        ball.vx = -ball.vx;
    }

    if (ball.x == player2.x && ball.y >= player2.y && ball.y <= player2.y + 3)
    {
        ball.vx = -ball.vx;
    }
}

// Function to update AI opponent position
void updateOpponent()
{
    // Calculate AI opponent center position
    int opponentCenter = player2.y + 1;

    // If ball is moving towards opponent
    if (ball.vx > 0)
    {
        // If ball is below opponent
        if (ball.y > opponentCenter)
        {
            player2.y++;
        }
        // If ball is above opponent
        else if (ball.y < opponentCenter)
        {
            player2.y--;
        }
    }
}

// Function to draw game screen
void drawScreen()
{
    // Clear screen
    system("clear");

    // Draw top boundary
    for (int i = 0; i <= WIDTH; i++)
    {
        printf("-");
    }
    printf("\n");

    // Draw game area
    for (int i = 0; i < HEIGHT; i++)
    {
        printf("|");
        for (int j = 0; j < WIDTH; j++)
        {
            if (i == ball.y && j == ball.x)
            {
                printf("o");
            }
            else if (i >= player1.y && i <= player1.y + 3 && j == player1.x)
            {
                printf("|");
            }
            else if (i >= player2.y && i <= player2.y + 3 && j == player2.x)
            {
                printf("|");
            }
            else
            {
                printf(" ");
            }
        }
        printf("|\n");
    }

    // Draw bottom boundary
    for (int i = 0; i <= WIDTH; i++)
    {
        printf("-");
    }
    printf("\n");
}

// Function to handle keyboard inputs
void *inputThread(void *arg)
{
    int *fd = (int *)arg;
    char input;

    // Loop forever
    while (1)
    {
        read(*fd, &input, 1);

        // Move player paddle up
        if (input == 'w' && player1.y > 0)
        {
            player1.y--;
        }
        // Move player paddle down
        else if (input == 's' && player1.y < HEIGHT - 4)
        {
            player1.y++;
        }
    }
}

// Function to initialize game objects
void initGame()
{
    // Initialize ball position and velocity
    ball.x = 10;
    ball.y = 5;
    ball.vx = 1;
    ball.vy = 1;

    // Initialize player paddle positions
    player1.x = 2;
    player1.y = 8;
    player2.x = WIDTH - 3;
    player2.y = 8;
}

// Main function
int main()
{
    // Initialize game objects
    initGame();

    // Set terminal in raw mode
    int fd = 0;
    if (isatty(fd))
    {
        setRawMode(fd);
    }

    // Create input thread
    pthread_t inputThreadID;
    pthread_create(&inputThreadID, NULL, inputThread, &fd);

    // Loop forever
    while (1)
    {
        // Update ball position
        updateBall();

        // Update AI opponent position
        updateOpponent();

        // Draw game screen
        drawScreen();

        // Delay game loop
        usleep(50000);
    }

    return 0;
}