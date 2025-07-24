//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the Bingo board
void printBoard(int board[][5], int size)
{
    printf("\nB\tI\tN\tG\tO\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (board[i][j] == -1)
                printf("X\t");
            else
                printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if Bingo has been achieved
int checkBingo(int board[][5], int size)
{
    int row, col, diag1 = 0, diag2 = 0;
    // Check each row for Bingo
    for (row = 0; row < size; row++)
    {
        int cnt = 0;
        for (col = 0; col < size; col++)
        {
            if (board[row][col] == -1)
                cnt++;
        }
        if (cnt == size)
            return 1;
    }
    // Check each column for Bingo
    for (col = 0; col < size; col++)
    {
        int cnt = 0;
        for (row = 0; row < size; row++)
        {
            if (board[row][col] == -1)
                cnt++;
        }
        if (cnt == size)
            return 1;
    }
    // Check the first diagonal for Bingo
    for (row = 0; row < size; row++)
    {
        if (board[row][row] == -1)
            diag1++;
    }
    if (diag1 == size)
        return 1;
    // Check the second diagonal for Bingo
    for (row = 0; row < size; row++)
    {
        if (board[row][size - 1 - row] == -1)
            diag2++;
    }
    if (diag2 == size)
        return 1;
    // Return 0 if Bingo is not achieved
    return 0;
}

int main()
{
    int board[5][5], num, size = 5;
    srand(time(NULL)); // Initialize random number generator
    // Initialize the board with unique random numbers
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int flag, val;
            do
            {
                flag = 0;
                val = rand() % 15 + j * 15 + 1;
                for (int k = 0; k < j; k++)
                    if (board[i][k] == val)
                        flag = 1;
            } while (flag);
            board[i][j] = val;
        }
    }
    // Print the Bingo board
    printBoard(board, size);
    // Play the game
    while (1)
    {
        printf("Enter the number called (0 to quit): ");
        scanf("%d", &num);
        if (num == 0)
            break;
        // Mark the number on the board
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (board[i][j] == num)
                    board[i][j] = -1;
            }
        }
        // Print the updated Bingo board
        printBoard(board, size);
        // Check if Bingo has been achieved
        if (checkBingo(board, size))
        {
            printf("Bingo!!\n");
            break;
        }
    }
    return 0;
}