//FormAI DATASET v1.0 Category: Game of Life ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

void init_board(int board[ROWS][COLS])
{
    srand(time(NULL));
    for(int i=0; i<ROWS; i++) 
    {
        for(int j=0; j<COLS; j++) 
        {
            board[i][j] = rand()%2;
        }
    }
}

void print_board(int board[ROWS][COLS])
{
    for(int i=0; i<ROWS; i++) 
    {
        for(int j=0; j<COLS; j++) 
        {
            if(board[i][j] == 1) 
            {
                printf("X");
            }
            else 
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int num_neighbors(int board[ROWS][COLS], int i, int j)
{
    int count = 0;
    for(int k=-1; k<=1; k++) 
    {
        for(int l=-1; l<=1; l++) 
        {
            int x = i + k;
            int y = j + l;
            if(x >= 0 && y >= 0 && x < ROWS && y < COLS && !(k == 0 && l == 0)) 
            {
                count += board[x][y];
            }
        }
    }
    return count;
}

void update_board(int board[ROWS][COLS])
{
    int new_board[ROWS][COLS];
    for(int i=0; i<ROWS; i++) 
    {
        for(int j=0; j<COLS; j++) 
        {
            int neighbors = num_neighbors(board, i, j);
            if(board[i][j] == 1 && (neighbors == 2 || neighbors == 3)) 
            {
                new_board[i][j] = 1;
            }
            else if(board[i][j] == 0 && neighbors == 3)
            {
                new_board[i][j] = 1;
            }
            else 
            {
                new_board[i][j] = 0;
            }
        }
    }
    for(int i=0; i<ROWS; i++) 
    {
        for(int j=0; j<COLS; j++) 
        {
            board[i][j] = new_board[i][j];
        }
    }
}

int main(void)
{
    int board[ROWS][COLS];
    init_board(board);
    for(int i=0; i<100; i++) 
    {
        print_board(board);
        update_board(board);
        printf("\n");
    }
    return 0;
}