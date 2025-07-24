//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

// Function to check if all the elements in a given column are marked
int isColumnMarked(int arr[ROWS][COLS], int col)
{
    int count = 0;
    for(int i=0; i<ROWS; i++)
    {
        if(arr[i][col] == 0)
            count++;
    }
    if(count == ROWS)
        return 1; // all elements in the given column are marked
    else
        return 0; // otherwise
}

// Function to check if all the elements in a given row are marked
int isRowMarked(int arr[ROWS][COLS], int row)
{
    int count = 0;
    for(int j=0; j<COLS; j++)
    {
        if(arr[row][j] == 0)
            count++;
    }
    if(count == COLS)
        return 1; // all elements in the given row are marked
    else
        return 0; // otherwise
}

// Function to check if any of the diagonal lines are marked
int isDiagonalMarked(int arr[ROWS][COLS])
{
    int count1 = 0, count2 = 0;
    for(int i=0; i<ROWS; i++)
    {
        if(arr[i][i] == 0)
            count1++;
        if(arr[i][COLS-i-1] == 0)
            count2++;
    }
    if(count1 == ROWS || count2 == ROWS)
        return 1; // either of the diagonal lines are marked
    else
        return 0; // otherwise
}

// Function to print the current state of the board
void printBoard(int arr[ROWS][COLS])
{
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int board[ROWS][COLS]; // the board

    // Initialize the board with unique numbers between 1 and 25
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            board[i][j] = i*COLS + j + 1;
        }
    }

    // Shuffle the board
    srand(time(0));
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            int r = rand() % ROWS;
            int c = rand() % COLS;

            int temp = board[i][j];
            board[i][j] = board[r][c];
            board[r][c] = temp;
        }
    }

    // Mark the center square
    board[ROWS/2][COLS/2] = 0;

    // Print the initial state of the board
    printf("\nWelcome to Bingo!\n\n");
    printBoard(board);

    // Play the game
    int count = 0;
    while(1)
    {
        // Get a random number between 1 and 25
        int number = rand() % 25 + 1;
        printf("\n(%d) Press Enter to draw a number...\n", count++);
        getchar();

        // Mark the number on the board
        for(int i=0; i<ROWS; i++)
        {
            for(int j=0; j<COLS; j++)
            {
                if(board[i][j] == number)
                    board[i][j] = 0;
            }
        }

        // Print the current state of the board
        printf("\n");
        printBoard(board);

        // Check if any player has won
        int gameover = 0;
        for(int i=0; i<ROWS; i++)
        {
            if(isRowMarked(board, i) || isColumnMarked(board, i))
            {
                gameover = 1;
                printf("\nBingo! A row or column has been marked!\n");
                break;
            }
        }
        if(!gameover && isDiagonalMarked(board))
        {
            gameover = 1;
            printf("\nBingo! A diagonal line has been marked!\n");
        }
        if(gameover)
            break;
    }

    printf("\nGame Over!\n");

    return 0;
}