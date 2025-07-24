//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

// Function prototypes
void createBoard(int board[][COLS]);
void displayBoard(int board[][COLS]);
int drawNumber(int drawnNumbers[], int size, int max);
void markNumber(int board[][COLS], int num);
int checkWin(int board[][COLS]);

// Main function
int main()
{
    int board[ROWS][COLS];
    int drawnNumbers[75];
    int numDrawn = 0;
    int num;

    // Set random seed
    srand(time(NULL));

    // Generate the board
    createBoard(board);

    // Display the board
    printf("\nWelcome to Bingo!\n");
    displayBoard(board);

    // Play Bingo
    while (1)
    {
        // Draw a number
        num = drawNumber(drawnNumbers, numDrawn, 75);
        drawnNumbers[numDrawn++] = num;

        // Display the drawn number
        printf("\nNumber drawn: %d\n", num);

        // Mark the number on the board
        markNumber(board, num);
        displayBoard(board);

        // Check for win
        if (checkWin(board))
        {
            printf("\nBingo! You win!\n");
            break;
        }

        // Sleep for a second before drawing the next number
        printf("Next number in 1 second...\n");
        sleep(1);
    }

    return 0;
}

// Function definitions
void createBoard(int board[][COLS])
{
    int i, j;
    int nums[75];

    // Initialize the board with zeros
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            board[i][j] = 0;
        }
    }

    // Generate an array of the numbers to pick from
    for (i = 0; i < 75; i++)
    {
        nums[i] = i + 1;
    }

    // Shuffle the array
    for (i = 74; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    // Fill in the board with the numbers
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (i == ROWS / 2 && j == COLS / 2)
            {
                board[i][j] = -1;
            }
            else
            {
                board[i][j] = nums[i * COLS + j];
            }
        }
    }
}

void displayBoard(int board[][COLS])
{
    int i, j;

    printf("\n   B   I   N   G   O\n");

    for (i = 0; i < ROWS; i++)
    {
        printf(" +---+---+---+---+---+\n");
        for (j = 0; j < COLS; j++)
        {
            if (board[i][j] == -1)
            {
                printf(" | X ");
            }
            else if (board[i][j] < 10)
            {
                printf(" | %d ", board[i][j]);
            }
            else
            {
                printf(" | %d", board[i][j]);
            }
        }
        printf(" |\n");
    }

    printf(" +---+---+---+---+---+\n");
}

int drawNumber(int drawnNumbers[], int size, int max)
{
    int num;

    // Keep drawing numbers until we get a number that hasn't been drawn yet
    do
    {
        num = rand() % max + 1;
    } while (findNumber(drawnNumbers, size, num) != -1);

    return num;
}

int findNumber(int arr[], int size, int num)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }
    return -1;
}

void markNumber(int board[][COLS], int num)
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (board[i][j] == num)
            {
                board[i][j] = -1;
                return;
            }
        }
    }
}

int checkWin(int board[][COLS])
{
    int i, j;
    int row, col, diag, antidiag;

    // Check for a horizontal win
    for (i = 0; i < ROWS; i++)
    {
        row = 1;
        for (j = 0; j < COLS; j++)
        {
            if (board[i][j] != -1)
            {
                row = 0;
                break;
            }
        }
        if (row)
        {
            return 1;
        }
    }

    // Check for a vertical win
    for (j = 0; j < COLS; j++)
    {
        col = 1;
        for (i = 0; i < ROWS; i++)
        {
            if (board[i][j] != -1)
            {
                col = 0;
                break;
            }
        }
        if (col)
        {
            return 1;
        }
    }

    // Check for a diagonal win
    diag = 1;
    for (i = 0; i < ROWS; i++)
    {
        if (board[i][i] != -1)
        {
            diag = 0;
            break;
        }
    }
    if (diag)
    {
        return 1;
    }

    // Check for an antidiagonal win
    antidiag = 1;
    for (i = 0; i < ROWS; i++)
    {
        if (board[i][COLS - i - 1] != -1)
        {
            antidiag = 0;
            break;
        }
    }
    if (antidiag)
    {
        return 1;
    }

    // No win yet
    return 0;
}