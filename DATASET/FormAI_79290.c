//FormAI DATASET v1.0 Category: Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10     // Number of rows in grid
#define COLS 10     // Number of columns in grid
#define BOMBS 10    // Number of bombs in grid

// Function to print game board
void printBoard(int board[ROWS][COLS], char mask[ROWS][COLS], int gameOver)
{
    system("clear");  // Clear console screen

    printf("   1 2 3 4 5 6 7 8 9 10\n");  // Column indicators

    for(int i=0; i<ROWS; i++)
    {
        printf("%d ", i+1);  // Row indicators

        for(int j=0; j<COLS; j++)
        {
            if(gameOver && board[i][j] == 9)  // Show all bombs if game is over
                printf("* ");
            else if(mask[i][j] == 'F')   // Show flagged cells
                printf("F ");
            else if(mask[i][j] == 'O')  // Show open cells
                printf("%d ", board[i][j]);
            else                         // Show hidden cells
                printf(". ");
        }

        printf("\n");
    }
}

// Function to place bombs randomly in the grid
void placeBombs(int board[ROWS][COLS])
{
    int bombsPlaced = 0;

    // Repeat until all bombs are placed
    while(bombsPlaced < BOMBS)
    {
        int row = rand() % ROWS;
        int col = rand() % COLS;

        if(board[row][col] != 9)  // Place bomb only if it doesn't already exist
        {
            board[row][col] = 9;
            bombsPlaced++;
        }
    }
}

// Function to count number of bombs in adjacent cells
int countAdjacentBombs(int board[ROWS][COLS], int row, int col)
{
    int count = 0;

    // Check all adjacent cells
    for(int i=row-1; i<=row+1; i++)
    {
        for(int j=col-1; j<=col+1; j++)
        {
            if(i>=0 && i<ROWS && j>=0 && j<COLS)   // Ignore cells outside the grid
            {
                if(board[i][j] == 9)  // Increment count if cell contains bomb
                    count++;
            }
        }
    }

    return count;
}

// Function to open all non-bomb cells and adjacent cells recursively
void openCells(int board[ROWS][COLS], char mask[ROWS][COLS], int row, int col)
{
    if(mask[row][col] == 'O' || board[row][col] == 9)  // Return if cell is already open or contains bomb
        return;

    mask[row][col] = 'O';  // Mark cell as open
    int count = countAdjacentBombs(board, row, col);   // Count number of bombs in adjacent cells

    if(count == 0)   // Open all adjacent cells if no bombs are present
    {
        for(int i=row-1; i<=row+1; i++)
        {
            for(int j=col-1; j<=col+1; j++)
            {
                if(i>=0 && i<ROWS && j>=0 && j<COLS)   // Ignore cells outside the grid
                {
                    openCells(board, mask, i, j);   // Recursively open adjacent cells
                }
            }
        }
    }
}

// Function to check if all non-bomb cells are open
int checkWin(char mask[ROWS][COLS], int bombs)
{
    int count = 0;

    // Count number of open cells
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            if(mask[i][j] == 'O')
                count++;
        }
    }

    if(count == ROWS*COLS - bombs)   // If all non-bomb cells are open, return 1
        return 1;
    else
        return 0;
}

int main()
{
    int board[ROWS][COLS] = {0};   // Initialize game board
    char mask[ROWS][COLS] = {'H'}; // Initialize mask to hide all cells
    int bombsRemaining = BOMBS;    // Initialize number of bombs remaining
    int gameOver = 0;              // Flag to indicate end of game

    srand(time(NULL));             // Seed random number generator

    placeBombs(board);             // Place bombs randomly in the grid

    while(!gameOver)
    {
        printBoard(board, mask, gameOver);  // Print game board

        int row, col;
        char action;

        printf("Enter row, column, and action (O/F): ");
        scanf("%d %d %c", &row, &col, &action);

        row--;  // Convert row and column to 0-based indexing
        col--;

        if(action == 'O')   // Open cell if action is 'O'
        {
            if(board[row][col] == 9)   // End game if cell contains bomb
            {
                gameOver = 1;
                printf("Game over! You hit a bomb!\n");
            }
            else
            {
                openCells(board, mask, row, col);  // Open cell and adjacent cells
            }
        }
        else if(action == 'F')   // Flag or unflag cell if action is 'F'
        {
            if(mask[row][col] == 'H')   // Flag cell if it is hidden
            {
                mask[row][col] = 'F';
                bombsRemaining--;
            }
            else if(mask[row][col] == 'F')  // Unflag cell if it is flagged
            {
                mask[row][col] = 'H';
                bombsRemaining++;
            }
        }

        if(checkWin(mask, BOMBS))   // Check if all non-bomb cells are open
        {
            gameOver = 1;
            printf("Congratulations! You won the game!\n");
        }
    }

    printBoard(board, mask, gameOver);   // Print final game board

    return 0;
}