//FormAI DATASET v1.0 Category: Game of Life ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void printBoard(char board[][SIZE]);
void updateBoard(char board[][SIZE]);

int main()
{
    srand(time(NULL));
    char board[SIZE][SIZE];

    // Initialize the board with random values
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            if(rand()%2 == 0)
            {
                board[i][j] = 'X';
            }
            else
            {
                board[i][j] = '-';
            }
        }
    }

    // Play the game
    int generations = 10;
    for(int i=0; i<generations; i++)
    {
        printf("Generation %d\n", i+1);
        printBoard(board);
        updateBoard(board);
    }
    return 0;
}

void printBoard(char board[][SIZE])
{
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void updateBoard(char board[][SIZE])
{
    char tempBoard[SIZE][SIZE];

    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            // Count the number of live neighbors
            int neighbors = 0;
            for(int k=-1; k<=1; k++)
            {
                for(int l=-1; l<=1; l++)
                {
                    int row = i+k;
                    int col = j+l;

                    // Ensure we don't go out of bounds
                    if(row < 0)
                    {
                        row = SIZE-1;
                    }
                    else if(row >= SIZE)
                    {
                        row = 0;
                    }
                    if(col < 0)
                    {
                        col = SIZE-1;
                    }
                    else if(col >= SIZE)
                    {
                        col = 0;
                    }

                    if(board[row][col] == 'X')
                    {
                        neighbors++;
                    }
                }
            }

            // Update the cell based on the number of neighbors
            if(board[i][j] == 'X')
            {
                if(neighbors < 2 || neighbors > 3)
                {
                    tempBoard[i][j] = '-';
                }
                else
                {
                    tempBoard[i][j] = 'X';
                }
            }
            else
            {
                if(neighbors == 3)
                {
                    tempBoard[i][j] = 'X';
                }
                else
                {
                    tempBoard[i][j] = '-';
                }
            }
        }
    }

    // Copy the updated board back to the original board
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            board[i][j] = tempBoard[i][j];
        }
    }
}