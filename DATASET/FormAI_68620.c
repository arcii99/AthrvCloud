//FormAI DATASET v1.0 Category: Table Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define the size of the table
#define ROWS 10
#define COLS 10

// define the values of the bubbles
#define BUBBLES_MAX 5

// function prototypes
void initialize_table(int table[ROWS][COLS]);
void populate_bubbles(int table[ROWS][COLS]);
void display_table(int table[ROWS][COLS]);
void break_bubbles(int table[ROWS][COLS], int bubble_value, int row, int col);
int get_user_input(int* row, int* col);

int main()
{
    int table[ROWS][COLS] = {0};
    int bubble_value = 0;
    int row = 0;
    int col = 0;
    int score = 0;
    int moves = 0;
    int is_game_over = 0;

    printf("Welcome to the Bubble Breaker game!\n");

    // initialize the table and populate with random bubbles
    initialize_table(table);
    populate_bubbles(table);
    display_table(table);

    // game loop
    while (!is_game_over)
    {
        printf("Enter the row and column numbers of the bubble you want to select (e.g. 1 2): ");
        if (get_user_input(&row, &col) == 0)
        {
            printf("Invalid input! Try again.\n");
            continue;
        }

        if (table[row][col] == 0)
        {
            printf("No bubble at the selected position! Try again.\n");
            continue;
        }

        // break the selected bubble and its adjacent bubbles of the same value
        bubble_value = table[row][col];
        break_bubbles(table, bubble_value, row, col);

        // shift the remaining bubbles down and to the left
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (table[i][j] == 0)
                {
                    // shift the bubble down
                    for (int k = i+1; k < ROWS; k++)
                    {
                        if (table[k][j] != 0)
                        {
                            table[i][j] = table[k][j];
                            table[k][j] = 0;
                            break;
                        }
                    }
                }

                if (table[i][j] == 0)
                {
                    // shift the bubble to the left
                    for (int k = j+1; k < COLS; k++)
                    {
                        if (table[i][k] != 0)
                        {
                            table[i][j] = table[i][k];
                            table[i][k] = 0;
                            break;
                        }
                    }
                }
            }
        }

        moves++;
        score += bubble_value;

        printf("\n");
        display_table(table);

        // check if the game is over
        is_game_over = 1;
        for (int i = 0; i < ROWS && is_game_over; i++)
        {
            for (int j = 0; j < COLS && is_game_over; j++)
            {
                if (table[i][j] != 0)
                {
                    // check if there are adjacent bubbles of the same value
                    if ((i < ROWS-1 && table[i][j] == table[i+1][j]) || 
                        (j < COLS-1 && table[i][j] == table[i][j+1]))
                    {
                        is_game_over = 0;
                        break;
                    }
                }
            }
        }
    }

    printf("Game over! You scored %d points in %d moves.\n", score, moves);

    return 0;
}

void initialize_table(int table[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            table[i][j] = 0;
        }
    }
}

void populate_bubbles(int table[ROWS][COLS])
{
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            table[i][j] = rand() % BUBBLES_MAX + 1;
        }
    }
}

void display_table(int table[ROWS][COLS])
{
    printf("   ");
    for (int j = 0; j < COLS; j++)
    {
        printf("%2d ", j);
    }
    printf("\n");

    printf("   ");
    for (int j = 0; j < COLS; j++)
    {
        printf("---");
    }
    printf("\n");

    for (int i = 0; i < ROWS; i++)
    {
        printf("%2d|", i);
        for (int j = 0; j < COLS; j++)
        {
            printf("%2d|", table[i][j]);
        }
        printf("\n");

        printf("   ");
        for (int j = 0; j < COLS; j++)
        {
            printf("---");
        }
        printf("\n");
    }
}

void break_bubbles(int table[ROWS][COLS], int bubble_value, int row, int col)
{
    if (table[row][col] == 0)
    {
        return;
    }

    table[row][col] = 0;

    if (row > 0 && table[row-1][col] == bubble_value)
    {
        break_bubbles(table, bubble_value, row-1, col);
    }

    if (row < ROWS-1 && table[row+1][col] == bubble_value)
    {
        break_bubbles(table, bubble_value, row+1, col);
    }

    if (col > 0 && table[row][col-1] == bubble_value)
    {
        break_bubbles(table, bubble_value, row, col-1);
    }

    if (col < COLS-1 && table[row][col+1] == bubble_value)
    {
        break_bubbles(table, bubble_value, row, col+1);
    }
}

int get_user_input(int* row, int* col)
{
    char buffer[256];
    char* endptr = NULL;

    if (fgets(buffer, 256, stdin) == NULL)
    {
        return 0;
    }

    *row = strtol(buffer, &endptr, 10);
    if (endptr == buffer || *endptr != ' ')
    {
        return 0;
    }

    buffer[strlen(buffer)-1] = '\0';
    *col = strtol(endptr+1, &endptr, 10);
    if (endptr == buffer+strlen(buffer)-1 || *endptr != '\0')
    {
        return 0;
    }

    return 1;
}