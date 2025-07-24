//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: creative
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define WIDTH 20 // width of the screen
#define HEIGHT 20 // height of the screen
#define PADDLE_SIZE 4 // height of the paddles
#define BALL 'O' // symbol of the ball
#define BLANK ' ' // symbol of the blank space

// function prototypes
void initGame(bool* gameOver, int* ballX, int* ballY, int* ballVelocityX, int* ballVelocityY, 
              int* playerAPaddleX, int* playerAPaddleY, int* playerBPaddleX, int* playerBPaddleY);
void movePaddles(char input, int* playerAPaddleY, int* playerBPaddleY);
void moveBall(int* ballX, int* ballY, int* ballVelocityX, int* ballVelocityY, int* playerAPaddleX,
              int* playerAPaddleY, int* playerBPaddleX, int* playerBPaddleY, bool* gameOver);
void drawScreen(int ballX, int ballY, int playerAPaddleX, int playerAPaddleY, int playerBPaddleX, int playerBPaddleY);
char getUserInputWithoutEnter();
char getAIMove(int aiPaddleY, int ballY);

// the main function
int main()
{
    // initialize variables
    bool gameOver = false;
    int ballX, ballY, ballVelocityX, ballVelocityY;
    int playerAPaddleX, playerAPaddleY, playerBPaddleX, playerBPaddleY;
    initGame(&gameOver, &ballX, &ballY, &ballVelocityX, &ballVelocityY, &playerAPaddleX, 
              &playerAPaddleY, &playerBPaddleX, &playerBPaddleY);

    // game loop
    while (!gameOver)
    {
        // get user input for player A paddle
        char input = getUserInputWithoutEnter();
        movePaddles(input, &playerAPaddleY, &playerBPaddleY);

        // get AI move for player B paddle
        int ballYCopy = ballY;
        char aiMove = getAIMove(playerBPaddleY, ballYCopy);
        movePaddles(aiMove, &playerBPaddleY, &playerAPaddleY);

        // move the ball and check if the game is over
        moveBall(&ballX, &ballY, &ballVelocityX, &ballVelocityY, &playerAPaddleX, &playerAPaddleY, 
                  &playerBPaddleX, &playerBPaddleY, &gameOver);

        // draw the screen
        drawScreen(ballX, ballY, playerAPaddleX, playerAPaddleY, playerBPaddleX, playerBPaddleY);

        usleep(50000); // slow down the game
    }

    // print game over message
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nGame Over\n");

    return 0;
}

// function to initialize the game
void initGame(bool* gameOver, int* ballX, int* ballY, int* ballVelocityX, int* ballVelocityY, 
              int* playerAPaddleX, int* playerAPaddleY, int* playerBPaddleX, int* playerBPaddleY)
{
    // initialize the random number generator
    srand(time(NULL));

    // initialize the ball position and velocity
    *ballX = WIDTH / 2;
    *ballY = HEIGHT / 2;
    *ballVelocityX = rand() % 2 == 0 ? -1 : 1; // either -1 or 1
    *ballVelocityY = rand() % 2 == 0 ? -1 : 1; // either -1 or 1

    // initialize the paddle positions
    *playerAPaddleX = 0;
    *playerBPaddleX = WIDTH - 1;
    *playerAPaddleY = HEIGHT / 2 - PADDLE_SIZE / 2;
    *playerBPaddleY = HEIGHT / 2 - PADDLE_SIZE / 2;

    // set the game over flag to false
    *gameOver = false;

    // draw the screen
    drawScreen(*ballX, *ballY, *playerAPaddleX, *playerAPaddleY, *playerBPaddleX, *playerBPaddleY);
}

// function to move the paddles
void movePaddles(char input, int* playerAPaddleY, int* playerBPaddleY)
{
    // move the paddle for player A
    if (input == 'w' && *playerAPaddleY > 0)
    {
        (*playerAPaddleY)--;
    }
    else if (input == 's' && *playerAPaddleY < HEIGHT - PADDLE_SIZE)
    {
        (*playerAPaddleY)++;
    }

    // move the paddle for player B
    if (input == 'i' && *playerBPaddleY > 0)
    {
        (*playerBPaddleY)--;
    }
    else if (input == 'k' && *playerBPaddleY < HEIGHT - PADDLE_SIZE)
    {
        (*playerBPaddleY)++;
    }
}

// function to move the ball
void moveBall(int* ballX, int* ballY, int* ballVelocityX, int* ballVelocityY, int* playerAPaddleX,
              int* playerAPaddleY, int* playerBPaddleX, int* playerBPaddleY, bool* gameOver)
{
    // check if the ball hits the walls
    if (*ballX == 0 || *ballX == WIDTH - 1)
    {
        *ballVelocityX *= -1;
    }
    if (*ballY == 0 || *ballY == HEIGHT - 1)
    {
        *ballVelocityY *= -1;
    }

    // check if the ball hits a paddle
    if (*ballX == *playerAPaddleX + 1 && *ballY >= *playerAPaddleY && *ballY <= *playerAPaddleY + PADDLE_SIZE - 1)
    {
        *ballVelocityX *= -1;
    }
    if (*ballX == *playerBPaddleX - 1 && *ballY >= *playerBPaddleY && *ballY <= *playerBPaddleY + PADDLE_SIZE - 1)
    {
        *ballVelocityX *= -1;
    }

    // check if the ball goes out of bounds
    if (*ballX == 0 || *ballX == WIDTH - 1)
    {
        *gameOver = true; // if the ball goes out of bounds, the game is over
    }

    // move the ball
    *ballX += *ballVelocityX;
    *ballY += *ballVelocityY;
}

// function to draw the screen
void drawScreen(int ballX, int ballY, int playerAPaddleX, int playerAPaddleY, int playerBPaddleX, int playerBPaddleY)
{
    // clear the screen
    system("clear");

    // draw the ball
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (i == ballY && j == ballX)
            {
                printf("%c", BALL);
            }
            else
            {
                printf("%c", BLANK);
            }
        }
        printf("\n");
    }

    // draw the paddles
    for (int i = 0; i < HEIGHT; i++)
    {
        // draw player A paddle
        if (i >= playerAPaddleY && i < playerAPaddleY + PADDLE_SIZE)
        {
            printf("|");
        }
        else
        {
            printf("%c", BLANK);
        }

        // draw player B paddle
        if (i >= playerBPaddleY && i < playerBPaddleY + PADDLE_SIZE)
        {
            printf("|");
        }
        else
        {
            printf("%c", BLANK);
        }

        printf("\n");
    }
}

// function to get user input without waiting for the Enter key
char getUserInputWithoutEnter()
{
    char c;
    struct termios oldTerm, newTerm;
    tcgetattr(STDIN_FILENO, &oldTerm);
    newTerm = oldTerm;
    newTerm.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newTerm);
    c = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldTerm);
    return c;
}

// function to get the AI move
char getAIMove(int aiPaddleY, int ballY)
{
    if (aiPaddleY + PADDLE_SIZE / 2 < ballY)
    {
        return 'k'; // move paddle down
    }
    else if (aiPaddleY + PADDLE_SIZE / 2 > ballY)
    {
        return 'i'; // move paddle up
    }
    else
    {
        return ' '; // stay still
    }
}