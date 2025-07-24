//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: immersive
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROWS 5
#define COLUMNS 5

void print_board(int board[][COLUMNS], int markers[][COLUMNS]);
int check_bingo(int markers[][COLUMNS]);
void generate_numbers(int numbers[]);

int main()
{
    srand(time(NULL));

    int board[ROWS][COLUMNS] = {0};
    int markers[ROWS][COLUMNS] = {0};
    int numbers[75] = {0};
    int call_count = 0;

    printf("Welcome to Bingo Simulator!\n");

    // generate the numbers for calling
    generate_numbers(numbers);

    // fill the board with random numbers
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLUMNS; col++)
        {
            int num = rand() % 75 + 1;
            board[row][col] = num;
        }
    }

    // print initial board
    print_board(board, markers);

    // start calling numbers
    while (1)
    {
        int number = numbers[call_count];
        printf("Calling number: %d\n", number);
        
        // mark the number on the board
        for (int row = 0; row < ROWS; row++)
        {
            for (int col = 0; col < COLUMNS; col++)
            {
                if (board[row][col] == number)
                {
                    markers[row][col] = 1;
                    break;
                }
            }
        }

        // print updated board
        print_board(board, markers);

        // check for bingo
        if (check_bingo(markers))
        {
            printf("BINGO!\n");
            break;
        }

        // wait for user input
        getchar();

        // clear the screen
        system("clear");

        // increment call count
        call_count++;
    }

    return 0;
}

void print_board(int board[][COLUMNS], int markers[][COLUMNS])
{
    printf("\n");
    printf("Current board:\n");

    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLUMNS; col++)
        {
            if (markers[row][col] == 1)
            {
                printf("[%2d] ", board[row][col]);
            }
            else
            {
                printf(" -  ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int check_bingo(int markers[][COLUMNS])
{
    // check rows
    for (int row = 0; row < ROWS; row++)
    {
        int count = 0;
        for (int col = 0; col < COLUMNS; col++)
        {
            if (markers[row][col] == 1)
            {
                count++;
            }
        }
        if (count == COLUMNS)
        {
            return 1;
        }
    }

    // check columns
    for (int col = 0; col < COLUMNS; col++)
    {
        int count = 0;
        for (int row = 0; row < ROWS; row++)
        {
            if (markers[row][col] == 1)
            {
                count++;
            }
        }
        if (count == ROWS)
        {
            return 1;
        }
    }

    // check diagonal
    int count = 0;
    for (int i = 0; i < ROWS; i++)
    {
        if (markers[i][i] == 1)
        {
            count++;
        }
    }
    if (count == ROWS)
    {
        return 1;
    }

    // check other diagonal
    count = 0;
    for (int i = 0; i < ROWS; i++)
    {
        if (markers[i][COLUMNS-1-i] == 1)
        {
            count++;
        }
    }
    if (count == ROWS)
    {
        return 1;
    }

    return 0;
}

void generate_numbers(int numbers[])
{
    printf("Generating numbers...\n");

    for (int i = 0; i < 75; i++)
    {
        numbers[i] = i+1;
    }

    // shuffle the numbers
    for (int i = 0; i < 75; i++)
    {
        int temp = numbers[i];
        int random_index = rand() % 75;
        numbers[i] = numbers[random_index];
        numbers[random_index] = temp;
    }
}