//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

// Function prototypes
void print_card(int card[ROWS][COLS]);
void generate_numbers(int numbers[75]);
int is_bingo(int card[ROWS][COLS], int marked[ROWS][COLS]);

int main()
{
    // Declaration and initialization of variables
    int card[ROWS][COLS];
    int marked[ROWS][COLS] = {0};
    int numbers[75];
    int num, row, col;
    int bingo = 0;

    // Generating random numbers
    generate_numbers(numbers);

    // Generating Bingo card
    srand(time(NULL)); // Setting random seed
    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLS; col++)
        {
            // Assigning random number to card
            num = rand() % 75 + 1;
            card[row][col] = num;
            printf("%2d ", num);
        }
        printf("\n");
    }

    // Game loop
    while (!bingo)
    {
        printf("\nEnter number (0 to exit): ");
        scanf("%d", &num);

        if (num == 0)
        {
            // Exiting game
            printf("\nThanks for playing!\n");
            return 0;
        }

        // Marking number on card
        for (row = 0; row < ROWS; row++)
        {
            for (col = 0; col < COLS; col++)
            {
                if (card[row][col] == num)
                {
                    marked[row][col] = 1;
                    break;
                }
            }
        }

        // Printing updated card
        printf("\nUpdated Bingo card:\n");
        print_card(card);

        // Checking if Bingo achieved
        bingo = is_bingo(card, marked);
        if (bingo)
        {
            printf("\nBINGO!! Congratulations, you have won!\n");
        }
    }

    return 0;
}

void print_card(int card[ROWS][COLS])
{
    int row, col;
    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLS; col++)
        {
            if (card[row][col] == 0)
            {
                printf("   ");
            }
            else
            {
                printf("%2d ", card[row][col]);
            }
        }
        printf("\n");
    }
}

void generate_numbers(int numbers[75])
{
    int i;
    for (i = 0; i < 75; i++)
    {
        numbers[i] = i+1;
    }

    // Shuffling numbers
    srand(time(NULL)); // Setting random seed
    for (i = 0; i < 75; i++)
    {
        int j = rand() % 75;
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }
}

int is_bingo(int card[ROWS][COLS], int marked[ROWS][COLS])
{
    int row, col;
    int bingo = 0;

    // Checking rows for Bingo
    for (row = 0; row < ROWS; row++)
    {
        int row_check = 1;
        for (col = 0; col < COLS; col++)
        {
            if (marked[row][col] == 0)
            {
                row_check = 0;
                break;
            }
        }

        if (row_check)
        {
            bingo = 1;
            break;
        }
    }

    // Checking columns for Bingo
    for (col = 0; col < COLS; col++)
    {
        int col_check = 1;
        for (row = 0; row < ROWS; row++)
        {
            if (marked[row][col] == 0)
            {
                col_check = 0;
                break;
            }
        }

        if (col_check)
        {
            bingo = 1;
            break;
        }
    }

    // Checking diagonal 1 for Bingo
    int diag1_check = 1;
    for (row = 0; row < ROWS; row++)
    {
        if (marked[row][row] == 0)
        {
            diag1_check = 0;
            break;
        }
    }

    if (diag1_check)
    {
        bingo = 1;
    }

    // Checking diagonal 2 for Bingo
    int diag2_check = 1;
    for (row = 0; row < ROWS; row++)
    {
        if (marked[row][COLS-row-1] == 0)
        {
            diag2_check = 0;
            break;
        }
    }

    if (diag2_check)
    {
        bingo = 1;
    }

    return bingo;
}