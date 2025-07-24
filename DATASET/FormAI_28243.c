//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board size
#define ROW 20
#define COL 40

// Define the paddle size
#define PADDLE_SIZE 3

// Define game elements
#define BALL '@'
#define PADDLE '#'
#define EMPTY ' '

// Define game speed
#define DELAY 50000

// Define the ball struct
typedef struct
{
    int x;
    int y;
    int dx;
    int dy;
} Ball;

// Define the paddle struct
typedef struct
{
    int x;
    int y;
    int score;
} Paddle;

// Define the AI opponent function
int ai_opponent(int x, int y, int bx, int by)
{
    if (y == by)
        return 0;
    else if ((y > by) && (x == bx))
        return -1;
    else if ((y < by) && (x == bx))
        return 1;
    else if (y > by)
        return -1;
    else
        return 1;
}

int main()
{
    srand(time(NULL)); // seed random number generator

    // Initialize game elements
    Ball ball = {.x = ROW/2, .y = COL/2, .dx = 1, .dy = 1};
    Paddle player = {.x = 1, .y = COL/2, .score = 0};
    Paddle ai = {.x = ROW - 2, .y = COL/2, .score = 0};

    // Initialize game board
    char board[ROW][COL];
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (i == 0 || i == ROW - 1)
                board[i][j] = '-';
            else if (j == 0 || j == COL - 1)
                board[i][j] = '|';
            else
                board[i][j] = EMPTY;
        }
    }

    // Loop until game over
    while (1)
    {
        // Clear screen
        system("clear");

        // Move ball
        ball.x += ball.dx;
        ball.y += ball.dy;

        // Reverse directions on collisions
        if (ball.x == 1 && ball.y >= player.y && ball.y <= player.y + PADDLE_SIZE)
            ball.dx = 1;
        if (ball.x == ROW - 2 && ball.y >= ai.y && ball.y <= ai.y + PADDLE_SIZE)
            ball.dx = -1;
        if (ball.y == 1 || ball.y == COL - 2)
            ball.dy *= -1;

        // Update score and reset ball
        if (ball.x == 0)
        {
            ai.score++;
            ball.x = ROW/2;
            ball.y = COL/2;
            ball.dx *= -1;
            ball.dy *= -1;
        }
        if (ball.x == ROW - 1)
        {
            player.score++;
            ball.x = ROW/2;
            ball.y = COL/2;
            ball.dx *= -1;
            ball.dy *= -1;
        }

        // Update AI paddle position
        ai.y += ai_opponent(ai.x, ai.y, ball.x, ball.y);

        // Draw game board
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                if (i == ball.x && j == ball.y)
                    printf("%c", BALL);
                else if (i >= player.x && i <= player.x + PADDLE_SIZE && j == player.y)
                    printf("%c", PADDLE);
                else if (i >= ai.x && i <= ai.x + PADDLE_SIZE && j == ai.y)
                    printf("%c", PADDLE);
                else
                    printf("%c", board[i][j]);
            }
            printf("\n");
        }

        // Print scores
        printf("Player: %d\tAI: %d\n", player.score, ai.score);

        // Check for game over
        if (player.score == 5 || ai.score == 5)
            break;

        // Delay game to control speed
        usleep(DELAY);
    }

    // Print winner
    if (player.score == 5)
        printf("Player wins!\n");
    else
        printf("AI wins!\n");

    return 0;
}