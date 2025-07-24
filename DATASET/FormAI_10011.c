//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define ROWS 20
#define COLS 30

char grid[ROWS][COLS];
int ballRow, ballCol;
int paddlePos;
int score;

void initGrid();
void printGrid();
void moveBall();
void movePaddle(int);
bool isGameOver();
void endGame();

int main()
{
    srand(time(NULL));
    initGrid();
    printGrid();

    char input;
    while (!isGameOver())
    {
        printf("\nEnter a,d or q to quit: ");
        scanf(" %c", &input);

        if (input == 'a')
        {
            movePaddle(-1);
        }
        else if (input == 'd')
        {
            movePaddle(1);
        }
        else if (input == 'q')
        {
            endGame();
            exit(0);
        }

        moveBall();
        printGrid();
    }

    endGame();
    return 0;
}

void initGrid()
{
    memset(grid, ' ', sizeof(grid));

    // create paddle
    paddlePos = COLS / 2;
    grid[ROWS-1][paddlePos-1] = '_';
    grid[ROWS-1][paddlePos] = '_';
    grid[ROWS-1][paddlePos+1] = '_';

    //create ball
    ballRow = ROWS - 2;
    ballCol = rand() % COLS;
    grid[ballRow][ballCol] = 'o';
}

void printGrid()
{
    system("clear");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
    printf("Score: %d", score);
}

void moveBall()
{
    // move the ball down
    ballRow++;

    // check if the ball hit the wall
    if (ballCol == 0 || ballCol == COLS-1)
    {
        // change direction if the ball hit the wall
        moveBall();
        moveBall();
        return;
    }

    // check if the ball hit the paddle
    if (ballRow == ROWS-1 && (ballCol == paddlePos-1 || 
        ballCol == paddlePos || ballCol == paddlePos+1))
    {
        score++;
        moveBall();
        moveBall();
        return;
    }

    // check if the ball hit a block
    if (ballRow < ROWS-2 && grid[ballRow][ballCol] == '#')
    {
        score++;
        grid[ballRow][ballCol] = ' ';
        moveBall();
        moveBall();
        return;
    }

    // check if the ball hit the bottom of the screen
    if (ballRow == ROWS-1)
    {
        endGame();
        exit(0);
    }

    // remove the ball from the old position
    grid[ballRow-1][ballCol] = ' ';
    
    // move the ball left or right
    int direction = rand() % 2;
    if (direction == 0)
    {
        ballCol--;
    }
    else
    {
        ballCol++;
    }

    //put the ball in a new position
    grid[ballRow][ballCol] = 'o';
}

void movePaddle(int direction)
{
    if (paddlePos == 0 && direction == -1)
    {
        return;
    }

    if (paddlePos == COLS-3 && direction == 1)
    {
        return;
    }

    grid[ROWS-1][paddlePos-1] = ' ';
    grid[ROWS-1][paddlePos] = ' ';
    grid[ROWS-1][paddlePos+1] = ' ';
    paddlePos += direction;
    grid[ROWS-1][paddlePos-1] = '_';
    grid[ROWS-1][paddlePos] = '_';
    grid[ROWS-1][paddlePos+1] = '_';
}

bool isGameOver()
{
    int blocksLeft = 0;
    for (int i = 0; i < ROWS-2; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (grid[i][j] == '#')
            {
                blocksLeft++;
            }
        }
    }
    return blocksLeft == 0;
}

void endGame()
{
    printf("\n\n\nGAME OVER\n\n");
}