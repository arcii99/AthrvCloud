//FormAI DATASET v1.0 Category: Memory Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

// Function to print the current board
void printBoard(int board[][COLS], int rows, int cols)
{
    int i, j;
    printf("\n");

    for(i=0; i < rows; i++)
    {
        for(j=0; j < cols; j++)
        {
            if(board[i][j] == -1)
                printf("  . ");
            else
                printf("%3d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if the game is over
int isGameOver(int board[][COLS], int rows, int cols)
{
    int i, j;

    for(i=0; i < rows; i++)
    {
        for(j=0; j < cols; j++)
        {
            if(board[i][j] == -1)
                return 0;
        }
    }
    return 1;
}

// Function to swap two elements in the board
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Function to shuffle the board
void shuffleBoard(int board[][COLS], int rows, int cols)
{
    int i, j, row_shuffle, col_shuffle;
    srand(time(0));

    for(i=0; i < rows; i++)
    {
        for(j=0; j < cols; j++)
        {
            row_shuffle = rand() % rows;
            col_shuffle = rand() % cols;

            swap(&board[i][j], &board[row_shuffle][col_shuffle]);
        }
    }
}

// Function to play the game
void playGame(int board[][COLS], int rows, int cols)
{
    int row1, col1, row2, col2, temp;
    while(!isGameOver(board, rows, cols))
    {
        // Print the board
        printBoard(board, rows, cols);

        // Prompt user for choice
        printf("Enter the row and column numbers of the first card: ");
        scanf("%d %d", &row1, &col1);

        // Check if invalid row or column has been entered
        if(row1>=rows || row1<0 || col1 >=cols || col1<0)
        {
            printf("Invalid row or column entered.\n");
            continue;
        }

        // Check if already matched
        if(board[row1][col1] == -1)
        {
            printf("This card has already been matched.\n");
            continue;
        }

        // Print the current board
        printBoard(board, rows, cols);

        // Prompt user for choice
        printf("Enter the row and column numbers of the second card: ");
        scanf("%d %d", &row2, &col2);

        // Check if invalid row or column has been entered
        if(row2>=rows || row2<0 || col2 >=cols || col2<0)
        {
            printf("Invalid row or column entered.\n");
            continue;
        }

        // Check if already matched
        if(board[row2][col2] == -1)
        {
            printf("This card has already been matched.\n");
            continue;
        }

        // Check if the two cards match
        if(board[row1][col1] != board[row2][col2])
        {
            printf("The two cards do not match. Try again.\n");

            // cover the cards again
            board[row1][col1] = temp;
            board[row2][col2] = temp;
        }
        else
        {
            // Mark the cards as matched
            board[row1][col1] = -1;
            board[row2][col2] = -1;
            printf("Great! You have matched the cards.\n");
        }
    }

    // Game over
    printBoard(board, rows, cols);
    printf("GAME OVER! Congratulations!!");
}

int main()
{
    int board[ROWS][COLS] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    shuffleBoard(board, ROWS, COLS);
    playGame(board, ROWS, COLS);
    printf("\n Thanks for playing the game!\n");
    return 0;
}