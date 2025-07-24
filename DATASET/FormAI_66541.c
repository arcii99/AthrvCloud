//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW_SIZE 5
#define COL_SIZE 5

void print_card(int card[ROW_SIZE][COL_SIZE], int marked[ROW_SIZE][COL_SIZE]);
void generate_numbers(int card[ROW_SIZE][COL_SIZE]);
int check_bingo(int card[ROW_SIZE][COL_SIZE], int marked[ROW_SIZE][COL_SIZE]);

int main()
{
    int i, j, count = 0;
    int card[ROW_SIZE][COL_SIZE], marked[ROW_SIZE][COL_SIZE] = {0};
    srand(time(NULL));

    generate_numbers(card); // generate the bingo card

    // print the card
    printf("Welcome to Bingo Simulator!\n");
    printf("---------------------------\n");
    printf("Your card is:\n");
    print_card(card, marked);

    // start the game
    while (1)
    {
        int number = rand() % 75 + 1; // generate a random number
        printf("\n\nThe next number is: %d\n", number);

        // mark the number on the card if it is present
        for (i = 0; i < ROW_SIZE; i++)
        {
            for (j = 0; j < COL_SIZE; j++)
            {
                if (card[i][j] == number)
                {
                    marked[i][j] = 1;
                    count++;
                }
            }
        }

        // print the updated card
        print_card(card, marked);

        // check for bingo
        if (check_bingo(card, marked))
        {
            printf("\n\nBingo! You have won!\n");
            break;
        }

        printf("\n\nPress enter for the next number...\n");
        getchar();
    }

    return 0;
}

void print_card(int card[ROW_SIZE][COL_SIZE], int marked[ROW_SIZE][COL_SIZE])
{
    int i, j;

    printf("\n");

    for (i = 0; i < ROW_SIZE; i++)
    {
        for (j = 0; j < COL_SIZE; j++)
        {
            if (marked[i][j])
            {
                printf("%-3s", "X"); // print a 'X' for marked numbers
            }
            else
            {
                printf("%-3d", card[i][j]); // print the number
            }
        }

        printf("\n");
    }
}

void generate_numbers(int card[ROW_SIZE][COL_SIZE])
{
    int i, j, count = 0;

    for (i = 0; i < ROW_SIZE; i++)
    {
        for (j = 0; j < COL_SIZE; j++)
        {
            while (1)
            {
                int number = rand() % 15 + (15 * j) + 1; // generate a number based on the column
                if (number < (15 * (j + 1) + 1) && !card[i][j]) // check if the number is within the column and not already present
                {
                    card[i][j] = number;
                    break;
                }
            }
            count++;
        }
    }
}

int check_bingo(int card[ROW_SIZE][COL_SIZE], int marked[ROW_SIZE][COL_SIZE])
{
    int i, j, row_sum, col_sum;

    // check rows for bingo
    for (i = 0; i < ROW_SIZE; i++)
    {
        row_sum = 0;
        for (j = 0; j < COL_SIZE; j++)
        {
            row_sum += marked[i][j];
        }
        if (row_sum == COL_SIZE)
        {
            return 1;
        }
    }

    // check columns for bingo
    for (j = 0; j < COL_SIZE; j++)
    {
        col_sum = 0;
        for (i = 0; i < ROW_SIZE; i++)
        {
            col_sum += marked[i][j];
        }
        if (col_sum == ROW_SIZE)
        {
            return 1;
        }
    }

    // check diagonals
    if (marked[0][0] && marked[1][1] && marked[2][2] && marked[3][3] && marked[4][4])
    {
        return 1;
    }
    if (marked[0][4] && marked[1][3] && marked[2][2] && marked[3][1] && marked[4][0])
    {
        return 1;
    }

    return 0;
}