//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define CENTER 13

void print_card(int card[ROWS][COLS]);
void generate_numbers(int card[ROWS][COLS]);
int check_card(int card[ROWS][COLS]);

int main()
{
    int card[ROWS][COLS] = {{0}};
    int num_of_draws = 0;
    int num;

    // Generating the bingo card
    generate_numbers(card);

    // Printing the card
    print_card(card);

    // Generating random numbers until a bingo is detected
    while (!check_card(card))
    {
        num = rand() % 75 + 1;
        printf("Number drawn: %d\n", num);
        num_of_draws++;

        // Marking the number on the card if it is present
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (card[i][j] == num)
                {
                    card[i][j] = -1;
                }
            }
        }
    }

    // Printing the number of draws it took to get a bingo
    printf("\n\nBingo! It took %d draws.\n", num_of_draws);

    return 0;
}

void print_card(int card[ROWS][COLS])
{
    printf("BINGO CARD\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (card[i][j] == -1)
            {
                printf("X ");
            }
            else if (card[i][j] == CENTER)
            {
                printf("* ");
            }
            else
            {
                printf("%d ", card[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void generate_numbers(int card[ROWS][COLS])
{
    srand(time(NULL));

    // Generating random numbers for the first column
    for (int i = 0; i < ROWS; i++)
    {
        int num;
        do
        {
            num = rand() % 15 + 1;
        } while (num == card[0][0] || num == card[1][0] || num == card[2][0] || num == card[3][0] || num == card[4][0]);
        card[i][0] = num;
    }

    // Generating random numbers for the second column
    for (int i = 0; i < ROWS; i++)
    {
        int num;
        do
        {
            num = rand() % 15 + 16;
        } while (num == card[0][1] || num == card[1][1] || num == card[2][1] || num == card[3][1] || num == card[4][1]);
        card[i][1] = num;
    }

    // Generating random numbers for the third column
    for (int i = 0; i < ROWS; i++)
    {
        int num;
        do
        {
            num = rand() % 15 + 31;
        } while (num == card[0][2] || num == card[1][2] || num == card[2][2] || num == card[3][2] || num == card[4][2]);
        card[i][2] = num;
    }

    // Generating random numbers for the fourth column
    for (int i = 0; i < ROWS; i++)
    {
        int num;
        do
        {
            num = rand() % 15 + 46;
        } while (num == card[0][3] || num == card[1][3] || num == card[2][3] || num == card[3][3] || num == card[4][3]);
        card[i][3] = num;
    }

    // Generating random numbers for the fifth column
    for (int i = 0; i < ROWS; i++)
    {
        int num;
        do
        {
            num = rand() % 15 + 61;
        } while (num == card[0][4] || num == card[1][4] || num == card[2][4] || num == card[3][4] || num == card[4][4]);
        card[i][4] = num;
    }

    // Marking the center square as *
    card[2][2] = CENTER;
}

int check_card(int card[ROWS][COLS])
{
    int row_sum, col_sum, diag_sum;

    // Checking for complete rows
    for (int i = 0; i < ROWS; i++)
    {
        row_sum = 0;
        for (int j = 0; j < COLS; j++)
        {
            if (card[i][j] == -1)
            {
                row_sum++;
            }
        }
        if (row_sum == COLS)
        {
            return 1;
        }
    }

    // Checking for complete columns
    for (int i = 0; i < COLS; i++)
    {
        col_sum = 0;
        for (int j = 0; j < ROWS; j++)
        {
            if (card[j][i] == -1)
            {
                col_sum++;
            }
        }
        if (col_sum == ROWS)
        {
            return 1;
        }
    }

    // Checking for complete diagonal (top-left to bottom-right)
    diag_sum = 0;
    for (int i = 0; i < ROWS; i++)
    {
        if (card[i][i] == -1)
        {
            diag_sum++;
        }
    }
    if (diag_sum == ROWS)
    {
        return 1;
    }

    // Checking for complete diagonal (bottom-left to top-right)
    diag_sum = 0;
    for (int i = 0; i < ROWS; i++)
    {
        if (card[i][ROWS - 1 - i] == -1)
        {
            diag_sum++;
        }
    }
    if (diag_sum == ROWS)
    {
        return 1;
    }

    // No bingo yet
    return 0;
}