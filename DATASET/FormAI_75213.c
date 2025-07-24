//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define WIDTH 40
#define HEIGHT 20

int board[WIDTH][HEIGHT];
int ballX, ballY;
int ballDirX, ballDirY;
int paddleX;
int score;

void initGame()
{
    int i, j;
    // initialize the board
    for(i = 0; i < WIDTH; i++)
    {
        for(j = 0; j < HEIGHT; j++)
        {
            if(j == 0 || j == HEIGHT - 1)
                board[i][j] = 1;
            else if(i == 0 || i == WIDTH - 1)
                board[i][j] = 1;
            else
                board[i][j] = 0;
        }
    }
    // initialize the ball
    ballX = WIDTH / 2;
    ballY = HEIGHT / 2;
    ballDirX = (rand() % 2 == 0) ? -1 : 1;
    ballDirY = -1;
    // initialize the paddle
    paddleX = (WIDTH - 5) / 2;
    // initialize the score
    score = 0;
}

void draw()
{
    int i, j;
    // clear the screen
    system("clear");
    // draw the board
    for(i = 0; i < WIDTH; i++)
    {
        for(j = 0; j < HEIGHT; j++)
        {
            if(board[i][j] == 1)
                printf("#");
            else if(i == ballX && j == ballY)
                printf("o");
            else if(i == paddleX && j == HEIGHT - 2)
                printf("=====");
            else
                printf(" ");
        }
        printf("\n");
    }
    // print the score
    printf("Score: %d\n", score);
}

void moveBall()
{
    // move the ball
    ballX += ballDirX;
    ballY += ballDirY;
    // check if the ball hits the wall
    if(ballX == 0 || ballX == WIDTH - 1)
        ballDirX *= -1;
    if(ballY == 0)
        ballDirY *= -1;
    // check if the ball hits the paddle
    if(ballY == HEIGHT - 2 && ballX >= paddleX && ballX <= paddleX + 4)
    {
        ballDirY *= -1;
        score++;
    }
    // check if the ball falls off the screen
    if(ballY == HEIGHT - 1)
        exit(0);
}

void movePaddle()
{
    // read the user input
    char c = getchar();
    // move the paddle
    if(c == 'a' && paddleX > 1)
        paddleX--;
    else if(c == 'd' && paddleX < WIDTH - 6)
        paddleX++;
}

int main()
{
    srand(time(NULL));
    initGame();
    while(1)
    {
        draw();
        moveBall();
        movePaddle();
    }
    return 0;
}