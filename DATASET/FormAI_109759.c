//FormAI DATASET v1.0 Category: Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void initializeBoard(int board[10][10]);
void displayBoard(int board[10][10], int revealAll);
int checkNeighbors(int board[10][10], int row, int col);
void updateBoard(int board[10][10], int row, int col);

int main()
{
    // Initialize board and variables
    int board[10][10], row, col, numMines = 10, numSafe = 90, revealAll = 0;

    // Set seed for random number generator
    srand(time(NULL));

    // Initialize board and place mines
    initializeBoard(board);
    for (int i = 0; i < numMines; i++)
    {
        row = rand() % 10;
        col = rand() % 10;
        if (board[row][col] == 9)
        {
            i--;
        }
        else
        {
            board[row][col] = 9;
        }
    }

    // Display board for the first time
    displayBoard(board, revealAll);

    // Game loop
    while (numSafe > 0)
    {
        // Prompt user for row and column
        printf("Enter row (1-10) and column (1-10): ");
        scanf("%d%d", &row, &col);
        row--;
        col--;

        // Check if user stepped on a mine
        if (board[row][col] == 9)
        {
            revealAll = 1;
            printf("Sorry, you stepped on a mine. Game over!\n");
            displayBoard(board, revealAll);
            return 0;
        }
        // Update board and check how many safe spaces remain
        else
        {
            updateBoard(board, row, col);
            numSafe = 0;
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    if (board[i][j] == 0)
                    {
                        numSafe++;
                    }
                }
            }
        }

        // Check if user has won the game
        if (numSafe == 0)
        {
            revealAll = 1;
            printf("Congratulations, you won the game!\n");
            displayBoard(board, revealAll);
            return 0;
        }

        // Display updated board
        displayBoard(board, revealAll);
    }

    return 0;
}

// Function to initialize board with all zeros
void initializeBoard(int board[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            board[i][j] = 0;
        }
    }
}

// Function to display board with hidden or revealed spaces
void displayBoard(int board[10][10], int revealAll)
{
    printf("   1 2 3 4 5 6 7 8 9 10\n");
    printf("  ---------------------\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d |", i + 1);
        for (int j = 0; j < 10; j++)
        {
            if (board[i][j] == 0 || revealAll == 1)
            {
                printf(" ");
            }
            else if (board[i][j] == 9)
            {
                printf("*");
            }
            else
            {
                printf("%d", board[i][j]);
            }
            printf("|");
        }
        printf("\n");
    }
    printf("  ---------------------\n");
}

// Function to check how many mines are in the neighboring spaces
int checkNeighbors(int board[10][10], int row, int col)
{
    int numMines = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (row + i < 0 || row + i > 9 || col + j < 0 || col + j > 9)
            {
                continue;
            }
            else if (board[row + i][col + j] == 9)
            {
                numMines++;
            }
        }
    }
    return numMines;
}

// Function to update board with new safe spaces
void updateBoard(int board[10][10], int row, int col)
{
    int numMines = checkNeighbors(board, row, col);
    board[row][col] = numMines;
    if (numMines == 0)
    {
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (row + i < 0 || row + i > 9 || col + j < 0 || col + j > 9 || board[row + i][col + j] != 0)
                {
                    continue;
                }
                else
                {
                    updateBoard(board, row + i, col + j);
                }
            }
        }
    }
}