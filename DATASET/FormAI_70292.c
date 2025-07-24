//FormAI DATASET v1.0 Category: Table Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void print_board(char board[][COLS])
{
    printf("   A B C D E F G H I J\n");

    for (int i = 0; i < ROWS; i++)
    {
        printf("%d  ", i);

        for (int j = 0; j < COLS; j++)
        {
            printf("%c ", board[i][j]);
        }

        printf("\n");
    }
}

char random_ship_type()
{
    int r = rand() % 3;

    if (r == 0)
    {
        return 'c';  
    }
    else if (r == 1)
    {
        return 's';
    }
    else
    {
        return 'b';
    }
}

void place_ships(char board[][COLS])
{
    // Place 5 ships
    for (int i = 0; i < 5; i++)
    {
        char type = random_ship_type();

        int row = rand() % ROWS;
        int col = rand() % COLS;

        while (board[row][col] != '-')
        {
            // Ship already exists at this location, try a new one
            row = rand() % ROWS;
            col = rand() % COLS;
        }

        board[row][col] = type;
    }
}

void fire(char board[][COLS], int *hits, int *misses)
{
    char col_letter;
    int col_number;

    printf("\nEnter the column letter (A-J): ");
    scanf(" %c", &col_letter);
    col_letter = toupper(col_letter);

    printf("Enter the row number (0-9): ");
    scanf("%d", &col_number);

    // Convert the board coordinates to array indices
    int col = col_letter - 'A';
    int row = col_number;

    if (board[row][col] == 'c' || board[row][col] == 's' || board[row][col] == 'b')
    {
        printf("Hit!\n\n");

        board[row][col] = 'h'; // Mark hit on board

        *hits += 1;
    }
    else
    {
        printf("Miss!\n\n");

        board[row][col] = 'm'; // Mark miss on board

        *misses += 1;
    }
}

int main()
{
    char board[ROWS][COLS];

    // Initialize board with empty spaces
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            board[i][j] = '-';
        }
    }

    srand(time(NULL)); // Seed the random number generator

    place_ships(board);

    int hits = 0;
    int misses = 0;

    printf("Welcome to the C Table Game!\n\n");

    while (hits < 5)
    {
        printf("Hits: %d, Misses: %d\n\n", hits, misses);
        print_board(board);
        fire(board, &hits, &misses);
    }

    printf("You sunk all the ships! Game over.\n");

    return 0;
}