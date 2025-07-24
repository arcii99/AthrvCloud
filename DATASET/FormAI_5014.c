//FormAI DATASET v1.0 Category: Memory Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define TRUE 1
#define FALSE 0

void printBoard(int board[][COLS], int hiddenBoard[][COLS], int rows, int cols);
void shuffleBoard(int board[][COLS], int rows, int cols);
int isGameOver(int board[][COLS], int rows, int cols, int hiddenBoard[][COLS]);

int main()
{
    int board[ROWS][COLS] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {1, 2, 3, 4}, {5, 6, 7, 8} };
    int hiddenBoard[ROWS][COLS] = { {FALSE} };
    int row1, col1, row2, col2;
    int moves = 0;

    shuffleBoard(board, ROWS, COLS);

    do
    {
        printBoard(board, hiddenBoard, ROWS, COLS);

        printf("Enter the row (0-3) and column (0-3) of the first card: ");
        scanf("%d %d", &row1, &col1);

        if (hiddenBoard[row1][col1])
        {
            printf("This card has already been selected. Please try again.\n");
            continue;
        }

        hiddenBoard[row1][col1] = TRUE;
        printBoard(board, hiddenBoard, ROWS, COLS);

        printf("Enter the row (0-3) and column (0-3) of the second card: ");
        scanf("%d %d", &row2, &col2);

        if (hiddenBoard[row2][col2])
        {
            printf("This card has already been selected. Please try again.\n");
            continue;
        }

        hiddenBoard[row2][col2] = TRUE;

        if (board[row1][col1] != board[row2][col2])
        {
            hiddenBoard[row1][col1] = FALSE;
            hiddenBoard[row2][col2] = FALSE;
            printf("Cards do not match. Please try again.\n");
        }

        moves++;
    }
    while (!isGameOver(board, ROWS, COLS, hiddenBoard));

    printf("Congratulations! You completed the game in %d moves.\n", moves);

    return 0;
}

void shuffleBoard(int board[][COLS], int rows, int cols)
{
    srand((unsigned) time(NULL));

    int i, j;
    for (i = rows * cols - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);

        int temp = board[0][i];
        board[0][i] = board[0][j];
        board[0][j] = temp;
    }
}

void printBoard(int board[][COLS], int hiddenBoard[][COLS], int rows, int cols)
{
    int i, j;

    printf("\n");
    for (i = 0; i < rows; i++)
    {
        printf("+---+---+---+---+\n");

        for (j = 0; j < cols; j++)
        {
            printf("|");

            if (hiddenBoard[i][j])
            {
                printf(" %d ", board[i][j]);
            }
            else
            {
                printf("   ");
            }
        }

        printf("|\n");
    }

    printf("+---+---+---+---+\n");
}

int isGameOver(int board[][COLS], int rows, int cols, int hiddenBoard[][COLS])
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (!hiddenBoard[i][j])
            {
                return FALSE;
            }
        }
    }

    return TRUE;
}