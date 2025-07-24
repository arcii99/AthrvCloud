//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define RANGE_MIN 1
#define RANGE_MAX 75

void print_card(int card[][SIZE]);
void mark_card(int card[][SIZE], int number);
int check_bingo(int card[][SIZE]);

int main()
{
    srand(time(NULL));
    int card[SIZE][SIZE] = {0};
    int number, bingo = 0;
    printf("Welcome to Bingo Simulator!\n");
    printf("Your card:\n");
    print_card(card);
    printf("Let's Start!\n");

    while (bingo == 0)
    {
        number = rand() % (RANGE_MAX - RANGE_MIN + 1) + RANGE_MIN;
        printf("\nNumber called: %d\n", number);
        mark_card(card, number);
        print_card(card);
        bingo = check_bingo(card);
        if (bingo != 0)
            printf("Bingo! You won in %d turns.\n", bingo);
    }

    return 0;
}

void print_card(int card[][SIZE])
{
    printf("+----+----+----+----+----+\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("|");
        for (int j = 0; j < SIZE; j++)
        {
            printf("%2d", card[i][j]);
            if (j == SIZE - 1)
                printf("|");
            else
                printf(" ");
        }
        printf("\n");
        printf("+----+----+----+----+----+\n");
    }
}

void mark_card(int card[][SIZE], int number)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (card[i][j] == number)
            {
                card[i][j] = -1;
                return;
            }
        }
    }
}

int check_bingo(int card[][SIZE])
{
    int i, j, count, bingo = 0;

    // Check Rows
    for (i = 0; i < SIZE; i++)
    {
        count = 0;
        for (j = 0; j < SIZE; j++)
        {
            if (card[i][j] == -1)
                count++;
        }
        if (count == 5)
        {
            bingo = i + 1;
            return bingo;
        }
    }

    // Check Columns
    for (i = 0; i < SIZE; i++)
    {
        count = 0;
        for (j = 0; j < SIZE; j++)
        {
            if (card[j][i] == -1)
                count++;
        }
        if (count == 5)
        {
            bingo = i + 6;
            return bingo;
        }
    }

    // Check Diagonals
    count = 0;
    for (i = 0; i < SIZE; i++)
    {
        if (card[i][i] == -1)
            count++;
    }
    if (count == 5)
    {
        bingo = 11;
        return bingo;
    }

    count = 0;
    for (i = 0; i < SIZE; i++)
    {
        if (card[i][SIZE - 1 - i] == -1)
            count++;
    }
    if (count == 5)
    {
        bingo = 12;
        return bingo;
    }

    return bingo;
}