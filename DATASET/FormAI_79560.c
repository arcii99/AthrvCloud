//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Game dimensions
#define WIDTH 80
#define HEIGHT 20

// Paddle dimensions
#define PADDLE_WIDTH 5
#define PADDLE_HEIGHT 1
#define PADDLE_SPEED 1

// Ball dimensions
#define BALL_SIZE 1
#define BALL_SPEED 1

// Brick dimensions
#define BRICK_WIDTH 5
#define BRICK_HEIGHT 2

// Colors
#define COLOR_WHITE "\033[0m"
#define COLOR_GREEN "\033[0;32m"
#define COLOR_YELLOW "\033[0;33m"
#define COLOR_RED "\033[0;31m"

// Function prototypes
void setup();
void draw();
void input();
void update();
bool isColliding(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);

// Global variables
char screen[HEIGHT][WIDTH];
int paddleX, paddleY;
int ballX, ballY;
int ballDirX, ballDirY;
int score;
int bricks[HEIGHT][WIDTH / BRICK_WIDTH];
bool playing;

int main()
{
    setup();

    while (true)
    {
        draw();
        input();
        update();

        // If player wins
        if (score == HEIGHT * (WIDTH / BRICK_WIDTH))
        {
            printf(COLOR_GREEN "You win the game! Congratulations!\n" COLOR_WHITE);
            break;
        }

        // If player loses
        if (ballY == HEIGHT - 1)
        {
            printf(COLOR_RED "You lose the game! Try again next time!\n" COLOR_WHITE);
            break;
        }
    }

    return 0;
}

void setup()
{
    // Seed the random number generator
    srand((unsigned int)time(NULL));

    // Initialize screen
    for (int row = 0; row < HEIGHT; row++)
    {
        for (int col = 0; col < WIDTH; col++)
        {
            screen[row][col] = ' ';
        }
    }

    // Add bricks
    for (int row = 0; row < HEIGHT; row += BRICK_HEIGHT)
    {
        for (int col = 0; col < WIDTH; col += BRICK_WIDTH)
        {
            bricks[row][col / BRICK_WIDTH] = rand() % 2;
        }
    }

    // Initialize paddle
    paddleX = WIDTH / 2 - PADDLE_WIDTH / 2;
    paddleY = HEIGHT - 2;

    // Initialize ball
    ballX = WIDTH / 2;
    ballY = HEIGHT - PADDLE_HEIGHT - 2;
    ballDirX = (rand() % 2 == 0) ? -1 : 1;
    ballDirY = -1;

    // Initialize score
    score = 0;

    // Start the game
    playing = true;
}

void draw()
{
    system("clear");

    // Draw header
    printf(COLOR_YELLOW "Surrealist Breakout\n" COLOR_WHITE);
    printf("Score: %d\n", score);

    // Draw screen
    for (int row = 0; row < HEIGHT; row++)
    {
        for (int col = 0; col < WIDTH; col++)
        {
            printf("%c", screen[row][col]);
        }

        printf("\n");
    }
}

void input()
{
    // Move paddle left
    if ('a' == getchar() && paddleX > 0)
    {
        paddleX -= PADDLE_SPEED;
    }

    // Move paddle right
    if ('d' == getchar() && paddleX < WIDTH - PADDLE_WIDTH)
    {
        paddleX += PADDLE_SPEED;
    }
}

void update()
{
    // Clear ball
    screen[ballY][ballX] = ' ';

    // Move ball
    ballX += ballDirX * BALL_SPEED;
    ballY += ballDirY * BALL_SPEED;

    // If ball hits top or sides of screen, reverse direction
    if (ballY == 0 || ballX == 0 || ballX == WIDTH - 1)
    {
        ballDirX *= -1;
        ballDirY *= -1;
    }

    // If ball hits paddle, reverse direction and add score
    if (isColliding(ballX, ballY, BALL_SIZE, BALL_SIZE, paddleX, paddleY, PADDLE_WIDTH, PADDLE_HEIGHT))
    {
        ballDirY *= -1;
        score++;
    }

    // If ball hits brick, remove brick and reverse direction
    for (int row = 0; row < HEIGHT; row++)
    {
        for (int col = 0; col < WIDTH / BRICK_WIDTH; col++)
        {
            if (bricks[row][col] == 1 && isColliding(ballX, ballY, BALL_SIZE, BALL_SIZE, col * BRICK_WIDTH, row, BRICK_WIDTH, BRICK_HEIGHT))
            {
                bricks[row][col] = 0;
                ballDirY *= -1;
                score++;
            }
        }
    }

    // Draw paddle
    for (int col = 0; col < PADDLE_WIDTH; col++)
    {
        screen[paddleY][paddleX + col] = '=';
    }

    // Draw ball
    screen[ballY][ballX] = 'O';

    // Draw bricks
    for (int row = 0; row < HEIGHT; row++)
    {
        for (int col = 0; col < WIDTH / BRICK_WIDTH; col++)
        {
            if (bricks[row][col] == 1)
            {
                for (int i = 0; i < BRICK_HEIGHT; i++)
                {
                    for (int j = 0; j < BRICK_WIDTH; j++)
                    {
                        screen[row + i][col * BRICK_WIDTH + j] = '*';
                    }
                }
            }
        }
    }

    // If player pressed ESC, stop playing
    if (getchar() == 27)
    {
        printf(COLOR_RED "You quit the game! Better luck next time!\n" COLOR_WHITE);
        playing = false;
    }
}

bool isColliding(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{
    return x1 <= x2 + w2 && x1 + w1 >= x2 && y1 <= y2 + h2 && y1 + h1 >= y2;
}