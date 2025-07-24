//FormAI DATASET v1.0 Category: Memory Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

void displayBoard(int board[][BOARD_SIZE])
{
    // Print the game board
    printf("\n------------------\n");
    for(int i=0;i<BOARD_SIZE;i++)
    {
        for(int j=0;j<BOARD_SIZE;j++)
        {
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
    printf("------------------\n");
}

void shuffle(int *arr, int n)
{
    // Randomly shuffle an array of integers
    srand(time(NULL));
    for(int i=n-1;i>=0;i--)
    {
        int j = rand() % (i+1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void resetBoard(int board[][BOARD_SIZE], int *numbers)
{
    // Reset the game board with random numbers
    shuffle(numbers, BOARD_SIZE*BOARD_SIZE);
    int k=0;
    for(int i=0;i<BOARD_SIZE;i++)
    {
        for(int j=0;j<BOARD_SIZE;j++)
        {
            board[i][j] = numbers[k++];
        }
    }
    displayBoard(board);
}

int isValidMove(int board[][BOARD_SIZE], int row, int col)
{
    // Check if the given move is valid
    if(row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == 0)
    {
        return 1;
    }
    return 0;
}

int isGameOver(int board[][BOARD_SIZE])
{
    // Check if the game is over
    for(int i=0;i<BOARD_SIZE;i++)
    {
        for(int j=0;j<BOARD_SIZE;j++)
        {
            if(board[i][j] == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

void move(int board[][BOARD_SIZE], int row, int col)
{
    // Move the number to the empty cell
    int r, c;
    for(int i=-1;i<=1;i++)
    {
        for(int j=-1;j<=1;j++)
        {
            r = row + i;
            c = col + j;
            if(isValidMove(board, r, c))
            {
                board[r][c] = board[row][col];
                board[row][col] = 0;
                displayBoard(board);
                return;
            }
        }
    }
    printf("Invalid move. Try again.\n");
}

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {0};
    int numbers[BOARD_SIZE*BOARD_SIZE];
    for(int i=0;i<BOARD_SIZE*BOARD_SIZE;i++)
    {
        numbers[i] = i+1;
    }
    resetBoard(board, numbers);
    int row, col;
    while(!isGameOver(board))
    {
        printf("Enter row and column of number to move: ");
        scanf("%d %d", &row, &col);
        if(isValidMove(board, row, col))
        {
            move(board, row, col);
        }
        else
        {
            printf("Invalid move. Try again.\n");
        }
    }
    printf("Congrats! You have solved the puzzle.\n");
    return 0;
}