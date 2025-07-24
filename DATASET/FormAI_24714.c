//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 20
#define BRICKS 30
#define PADDLE_SIZE 5

void printBoard(int board[ROWS][COLS], int score);
void drawBricks(int board[ROWS][COLS], int bricks[BRICKS][2]);
void setupBoard(int board[ROWS][COLS], int bricks[BRICKS][2], int *score);
void moveBall(int board[ROWS][COLS], int bricks[BRICKS][2], int *score, int *ballRow, int *ballCol, int *rowInc, int *colInc, int paddlePos);
int recursiveFunc(int n);

int main(void)
{
    srand(time(NULL));
    int board[ROWS][COLS], bricks[BRICKS][2], score = 0, ballRow = ROWS - 2, ballCol = COLS / 2, rowInc = -1, colInc = 1, paddlePos = (COLS - PADDLE_SIZE) / 2;
    setupBoard(board, bricks, &score);
    char input;
    int i, j;

    while (1)
    {
        printBoard(board, score);
        input = getchar();
        getchar();
        if (input == 'a')
        {
            if (paddlePos > 0)
                paddlePos--;
        }
        else if (input == 'd')
        {
            if (paddlePos < COLS - PADDLE_SIZE)
                paddlePos++;
        }
        else if (input == 'q')
        {
            return 0;
        }
        moveBall(board, bricks, &score, &ballRow, &ballCol, &rowInc, &colInc, paddlePos);
        for (i = 0; i < BRICKS; i++)
        {
            if (ballRow == bricks[i][0] && ballCol == bricks[i][1])
            {
                board[bricks[i][0]][bricks[i][1]] = 0;
                score++;
                bricks[i][0] = -1;
                bricks[i][1] = -1;
                rowInc *= -1;
                colInc *= -1;
                break;
            }
        }
        if (ballRow == ROWS - 1)
        {
            printf("GAME OVER!\n");
            return 0;
        }
        if (score == BRICKS)
        {
            printf("YOU WIN!\n");
            return 0;
        }
    }
    return 0;
}

void printBoard(int board[ROWS][COLS], int score)
{
    system("clear");
    printf("Score: %d\n", score);
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (board[i][j] == 1)
                printf("X");
            else if (i == ROWS - 1 && j >= (COLS - PADDLE_SIZE) / 2 && j < (COLS + PADDLE_SIZE) / 2)
                printf("_");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void drawBricks(int board[ROWS][COLS], int bricks[BRICKS][2])
{
    int i;
    for (i = 0; i < BRICKS; i++)
    {
        if (bricks[i][0] >= 0 && bricks[i][1] >= 0)
            board[bricks[i][0]][bricks[i][1]] = 1;
    }
}

void setupBoard(int board[ROWS][COLS], int bricks[BRICKS][2], int *score)
{
    int i, j, k;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (i == 0 || j == 0 || i == ROWS - 1 || j == COLS - 1)
                board[i][j] = 1;
            else
                board[i][j] = 0;
        }
    }
    for (k = 0; k < BRICKS; k++)
    {
        int row = rand() % (ROWS - 5) + 1;
        int col = rand() % (COLS - 4) + 2;
        for (i = -1; i <= 1; i++)
        {
            for (j = -2; j <= 2; j++)
            {
                if (board[row + i][col + j] == 0)
                {
                    board[row + i][col + j] = 1;
                    bricks[k][0] = row + i;
                    bricks[k][1] = col + j;
                    (*score)++;
                }
            }
        }
    }
}

void moveBall(int board[ROWS][COLS], int bricks[BRICKS][2], int *score, int *ballRow, int *ballCol, int *rowInc, int *colInc, int paddlePos)
{
    board[*ballRow][*ballCol] = 0;
    *ballRow += *rowInc;
    *ballCol += *colInc;

    if (*ballRow == ROWS - 2)
    {
        if (*ballCol >= paddlePos && *ballCol < paddlePos + PADDLE_SIZE)
        {
            *rowInc *= -1;
        }
    }
    else if (board[*ballRow][*ballCol] == 1)
    {
        *rowInc *= -1;
        *colInc *= -1;
    }

    if (*ballRow == 0)
        *rowInc *= -1;
    if (*ballCol == 0 || *ballCol == COLS - 1)
        *colInc *= -1;

    board[*ballRow][*ballCol] = 1;
    drawBricks(board, bricks);
}

int recursiveFunc(int n)
{
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return recursiveFunc(n - 1) + recursiveFunc(n - 2);
}