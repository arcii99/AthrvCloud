//FormAI DATASET v1.0 Category: Robot movement control ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

#define MAXROW 10
#define MAXCOL 10

void initBoard(char board[][MAXCOL], int numRows, int numCols);
void printBoard(char board[][MAXCOL], int numRows, int numCols);
bool canMove(char board[][MAXCOL], int numRows, int numCols, int row, int col);
void moveRobot(char board[][MAXCOL], int numRows, int numCols, int *row, int *col);
bool atEnd(char board[][MAXCOL], int numRows, int numCols, int row, int col);

int main()
{
    char board[MAXROW][MAXCOL];
    int numRows = 5;
    int numCols = 5;
    int curr_row = 0;
    int curr_col = 0;

    srand(time(NULL));

    initBoard(board, numRows, numCols);
    board[curr_row][curr_col] = 'R';

    while(!atEnd(board, numRows, numCols, curr_row, curr_col))
    {
       printBoard(board, numRows, numCols);
       moveRobot(board, numRows, numCols, &curr_row, &curr_col);
       system("pause");
       system("cls");
    }

    printf("\nCongratulations! You have reached the end!");
    return 0;
}

void initBoard(char board[][MAXCOL], int numRows, int numCols)
{
    for(int i = 0; i < numRows; i++)
       for(int j = 0; j < numCols; j++)
           board[i][j] = '-';
}

void printBoard(char board[][MAXCOL], int numRows, int numCols)
{
    for(int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < numCols; j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }
}

bool canMove(char board[][MAXCOL], int numRows, int numCols, int row, int col)
{
    return (row >=0 && row < numRows && col >=0 && col < numCols && board[row][col] == '-');
}

void moveRobot(char board[][MAXCOL], int numRows, int numCols, int *row, int *col)
{
    int r, c;
    int dir;
    int moves[] = {1, -1};
    while(true)
    {
        dir = rand() % 2;
        r = moves[dir] + *row;
        c = moves[(dir + 1) % 2] + *col;
        if(canMove(board, numRows, numCols, r, c))
          break;
    }
    board[*row][*col] = '-';
    *row = r;
    *col = c;
    board[*row][*col] = 'R';
}

bool atEnd(char board[][MAXCOL], int numRows, int numCols, int row, int col)
{
    return (row == numRows - 1) && (col == numCols - 1);
}