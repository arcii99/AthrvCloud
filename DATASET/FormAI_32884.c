//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

// Function to check if the number is already present in the array
int checkNumber(int number, int array[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (array[i][j] == number)
                return 0;
        }
    }
    return 1;
}

// Function to print the Bingo Grid
void printArray(int array[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // Initialize the array with -1
    int board[ROWS][COLS] = {{-1, -1, -1, -1, -1},
                             {-1, -1, -1, -1, -1},
                             {-1, -1, -1, -1, -1},
                             {-1, -1, -1, -1, -1},
                             {-1, -1, -1, -1, -1}};

    // Generate random numbers and assign them to the array
    srand(time(0));
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            int number;
            do
            {
                number = rand() % 25 + 1;
            } while (!checkNumber(number, board));

            board[i][j] = number;
        }
    }

    // Print the Bingo Grid
    printf("B\tI\tN\tG\tO\n");
    printArray(board);

    // Generate random numbers until a Bingo is achieved
    int number;
    int count = 0;
    int bingo = 0;
    while (!bingo)
    {
        count++;
        printf("\nEnter a number from 1 to 25:");
        scanf("%d", &number);

        // Check if the number is present in the array
        if (!checkNumber(number, board))
        {
            printf("\nNumber already called! Try again");
            continue;
        }

        // Mark the cell with a 0 if the number is present in the array
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (board[i][j] == number)
                    board[i][j] = 0;
            }
        }

        // Print the Bingo Grid
        printf("\nB\tI\tN\tG\tO\n");
        printArray(board);

        // Check if a Bingo has been achieved
        for (int i = 0; i < ROWS; i++)
        {
            int rowSum = 0;
            int colSum = 0;
            for (int j = 0; j < COLS; j++)
            {
                rowSum += board[i][j];
                colSum += board[j][i];
            }
            if (rowSum == 0 || colSum == 0)
            {
                bingo = 1;
            }
        }

        // Check if a diagonal Bingo has been achieved
        if (board[0][0] == 0 && board[1][1] == 0 && board[2][2] == 0 && board[3][3] == 0 && board[4][4] == 0)
        {
            bingo = 1;
        }
        if (board[0][4] == 0 && board[1][3] == 0 && board[2][2] == 0 && board[3][1] == 0 && board[4][0] == 0)
        {
            bingo = 1;
        }
    }

    // Print the number of calls required to achieve the Bingo
    printf("\nBINGO! You have won in %d calls.\n", count);

    return 0;
}