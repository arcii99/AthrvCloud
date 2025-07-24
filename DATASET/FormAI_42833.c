//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define EMPTY_TILE 16

/* function to initialize the game board */
void initBoard(int board[][COLS])
{
    int i, j, count = 1;
    
    /* fill the board with numbers */
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            board[i][j] = count++;
        }
    }
    
    /* set the last tile as empty */ 
    board[ROWS-1][COLS-1] = EMPTY_TILE;
}

/* function to swap two tiles on the board */
void swapTiles(int board[][COLS], int row1, int col1, int row2, int col2)
{
    int temp = board[row1][col1];
    board[row1][col1] = board[row2][col2];
    board[row2][col2] = temp;
}

/* function to print the game board */
void printBoard(int board[][COLS])
{
    int i, j;
    printf("\n");
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            if(board[i][j] != EMPTY_TILE)
            {
                printf("%-3d", board[i][j]);
            }
            else
            {
                printf("   ");
            }
        }
        printf("\n");
    }
}

/* function to check if the game is won */
int isGameWon(int board[][COLS])
{
    int i, j, count = 1;
    
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            if(board[i][j] != count++)
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int board[ROWS][COLS];
    int row, col;
    char dir;
    srand(time(NULL));
    printf("Welcome to the Sliding Puzzle Game!\n");
    printf("----------------------------------\n");
    printf("Try to arrange the tiles in order from 1 to 15.\n");
    printf("Use 'w','a','s' and 'd' keys to move the tiles.\n");
    printf("Press 'q' to quit the game.\n");
    initBoard(board);
    printBoard(board);
    while(!isGameWon(board))
    {
        printf("\nEnter direction: ");
        scanf(" %c", &dir);
        switch(dir)
        {
            case 'w':
                /* move up */
                for(row = 0; row < ROWS; row++)
                {
                    for(col = 0; col < COLS; col++)
                    {
                        if(board[row][col] == EMPTY_TILE && row < ROWS-1)
                        {
                            swapTiles(board, row, col, row+1, col);
                            printBoard(board);
                            break;
                        }
                    }
                }
                break;
            case 'a':
                /* move left */
                for(row = 0; row < ROWS; row++)
                {
                    for(col = 0; col < COLS; col++)
                    {
                        if(board[row][col] == EMPTY_TILE && col < COLS-1)
                        {
                            swapTiles(board, row, col, row, col+1);
                            printBoard(board);
                            break;
                        }
                    }
                }
                break;
            case 's':
                /* move down */
                for(row = 0; row < ROWS; row++)
                {
                    for(col = 0; col < COLS; col++)
                    {
                        if(board[row][col] == EMPTY_TILE && row > 0)
                        {
                            swapTiles(board, row, col, row-1, col);
                            printBoard(board);
                            break;
                        }
                    }
                }
                break;
            case 'd':
                /* move right */
                for(row = 0; row < ROWS; row++)
                {
                    for(col = 0; col < COLS; col++)
                    {
                        if(board[row][col] == EMPTY_TILE && col > 0)
                        {
                            swapTiles(board, row, col, row, col-1);
                            printBoard(board);
                            break;
                        }
                    }
                }
                break;
            case 'q':
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid direction, please try again.\n");
        }
    }
    printf("\nCongratulations, you won the game!\n");
    return 0;
}