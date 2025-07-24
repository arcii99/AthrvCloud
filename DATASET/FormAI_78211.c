//FormAI DATASET v1.0 Category: Memory Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void print_board(int board[][COLS], int rows)
{
    printf("   1  2  3  4\n");
    printf("  +-----------+\n");
    for (int i = 0; i < rows; i++)
    {
        printf("%d ", i + 1);
        for (int j = 0; j < COLS; j++)
        {
            if (board[i][j] == -1)
            {
                printf("|  ");
            }
            else
            {
                printf("|%2d", board[i][j]);
            }
        }
        printf("|\n");
        printf("  +-----------+\n");
    }
}

int main()
{
    int board[ROWS][COLS] = {{0}};
    int numbers[ROWS * COLS / 2];
    int count = 0;

    srand(time(NULL));

    // Generate random numbers to put in the board
    for (int i = 1; i <= ROWS * COLS / 2; i++)
    {
        numbers[count] = i;
        numbers[count + 1] = i;
        count += 2;
    }
  
    // Shuffle the numbers
    for (int i = 0; i < ROWS * COLS; i++)
    {
        int a = rand() % (ROWS * COLS);
        int b = rand() % (ROWS * COLS);

        int temp = numbers[a];
        numbers[a] = numbers[b];
        numbers[b] = temp;
    }

    // Fill the board with the shuffled numbers
    count = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            board[i][j] = numbers[count];
            count++;
        }
    }

    int row1, col1, row2, col2;
    int tries = 0;

    // Loop until all cards are matched
    while (1)
    {
        print_board(board, ROWS);

        printf("Enter first card:\n");
        printf("Row: ");
        scanf("%d", &row1);
        printf("Col: ");
        scanf("%d", &col1);

        while (board[row1 - 1][col1 - 1] == -1)
        {
            printf("Card already matched. Please choose another card\n");
            printf("Row: ");
            scanf("%d", &row1);
            printf("Col: ");
            scanf("%d", &col1);
        }

        printf("Enter second card:\n");
        printf("Row: ");
        scanf("%d", &row2);
        printf("Col: ");
        scanf("%d", &col2);

        while (board[row2 - 1][col2 - 1] == -1)
        {
            printf("Card already matched. Please choose another card\n");
            printf("Row: ");
            scanf("%d", &row2);
            printf("Col: ");
            scanf("%d", &col2);
        }

        if (board[row1 - 1][col1 - 1] != board[row2 - 1][col2 - 1])
        {
            board[row1 - 1][col1 - 1] = -1;
            board[row2 - 1][col2 - 1] = -1;
            printf("\nCards do not match. Try again!\n");
        }
        else
        {
            printf("\nCards matched!\n");
        }

        tries++;

        // Check if game is over 
        int matched = 0;
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (board[i][j] != -1)
                {
                    matched = 1;
                    break;
                }
            }
        }

        if (matched == 0)
        {
            printf("\nCongratulations! You won in %d tries\n", tries);
            break;
        }
    }

    return 0;
}