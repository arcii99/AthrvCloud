//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 21
#define COLS 31

void printboard(int[][31], int[][31]);
void moveup(int[], int[], int[][31], int[][31], int*, int*);
void movedown(int[], int[], int[][31], int[][31], int*, int*);
void moveleft(int[], int[], int[][31], int[][31], int*, int*);
void moveright(int[], int[], int[][31], int[][31], int*, int*);

int main()
{
    int x = 15, y = 10;
    int board[ROWS][COLS] = {0};
    int dots[ROWS][COLS] = {0};
    int score = 0, numdots = 0;
    char ch;
    srand(time(NULL)); //Set seed for random

    //Initialize board
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(i == 0 || j == 0 || i == ROWS - 1 || j == COLS - 1)
                board[i][j] = -1;
            else
            {
                //Create random dots
                if(rand() % 5 == 0)
                {
                    dots[i][j] = 1;
                    numdots++;
                }
            }
        }
    }

    //Print initial board
    printboard(board, dots);

    while(1)
    {
        if(numdots == 0)
        {
            printf("\n\nYOU WIN!\n");
            break;
        }
        ch = getchar();

        switch(ch)
        {
            case 'w':
                moveup(&x, &y, board, dots, &score, &numdots);
                break;
            case 's':
                movedown(&x, &y, board, dots, &score, &numdots);
                break;
            case 'a':
                moveleft(&x, &y, board, dots, &score, &numdots);
                break;
            case 'd':
                moveright(&x, &y, board, dots, &score, &numdots);
                break;
        }
        system("clear");
        printboard(board, dots);
        printf("Score: %d\n", score);
    }
    return 0;
}

void printboard(int board[][31], int dots[][31])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(board[i][j] == -1)
                printf("*");
            else if(dots[i][j] == 1)
                printf(".");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void moveup(int *x, int *y, int board[][31], int dots[][31], int *score, int *numdots)
{
    if(board[*x - 1][*y] != -1)
    {
        (*x)--;
        if(dots[*x][*y] == 1)
        {
            (*score)++;
            (*numdots)--;
            dots[*x][*y] = 0;
        }
    }
}

void movedown(int *x, int *y, int board[][31], int dots[][31], int *score, int *numdots)
{
    if(board[*x + 1][*y] != -1)
    {
        (*x)++;
        if(dots[*x][*y] == 1)
        {
            (*score)++;
            (*numdots)--;
            dots[*x][*y] = 0;
        }
    }
}

void moveleft(int *x, int *y, int board[][31], int dots[][31], int *score, int *numdots)
{
    if(board[*x][*y - 1] != -1)
    {
        (*y)--;
        if(dots[*x][*y] == 1)
        {
            (*score)++;
            (*numdots)--;
            dots[*x][*y] = 0;
        }
    }
}

void moveright(int *x, int *y, int board[][31], int dots[][31], int *score, int *numdots)
{
    if(board[*x][*y + 1] != -1)
    {
        (*y)++;
        if(dots[*x][*y] == 1)
        {
            (*score)++;
            (*numdots)--;
            dots[*x][*y] = 0;
        }
    }
}