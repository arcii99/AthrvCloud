//FormAI DATASET v1.0 Category: Memory Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void print_board(char board[ROWS][COLS], int revealed[ROWS][COLS]);
void shuffle_board(char board[ROWS][COLS]);
int check_win(int revealed[ROWS][COLS]);

int main()
{
    char board[ROWS][COLS] = {
        {'A', 'B', 'C', 'D'},
        {'E', 'F', 'G', 'H'},
        {'I', 'J', 'K', 'L'},
        {'M', 'N', 'O', 'P'}
    };
    int revealed[ROWS][COLS] = {0};
    int num_revealed = 0;
    int row1, col1, row2, col2;

    // Seed the random number generator
    srand(time(NULL));

    // Shuffle the board
    shuffle_board(board);

    // Print the board
    print_board(board, revealed);

    // Loop until all tiles are revealed
    while (num_revealed < ROWS * COLS)
    {
        // Get the first tile to reveal
        printf("Enter the row and column of the first tile to reveal (e.g. '1 2'): ");
        scanf("%d %d", &row1, &col1);

        while (revealed[row1][col1])
        {
            printf("That tile is already revealed.\n");
            printf("Enter the row and column of the first tile to reveal (e.g. '1 2'): ");
            scanf("%d %d", &row1, &col1);
        }

        // Reveal the first tile and print the board
        revealed[row1][col1] = 1;
        num_revealed++;
        print_board(board, revealed);

        // Get the second tile to reveal
        printf("Enter the row and column of the second tile to reveal (e.g. '2 3'): ");
        scanf("%d %d", &row2, &col2);

        while (revealed[row2][col2])
        {
            printf("That tile is already revealed.\n");
            printf("Enter the row and column of the second tile to reveal (e.g. '2 3'): ");
            scanf("%d %d", &row2, &col2);
        }

        // Reveal the second tile and print the board
        revealed[row2][col2] = 1;
        num_revealed++;
        print_board(board, revealed);

        // Check if the tiles match
        if (board[row1][col1] != board[row2][col2])
        {
            // If they don't match, hide both tiles and print the board
            revealed[row1][col1] = 0;
            revealed[row2][col2] = 0;
            num_revealed -= 2;
            print_board(board, revealed);
        }

        // Check if the game is won
        if (check_win(revealed))
        {
            printf("Congratulations, you win!\n");
            return 0;
        }
    }

    return 0;
}

void print_board(char board[ROWS][COLS], int revealed[ROWS][COLS])
{
    int row, col;

    printf("Board:\n");

    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLS; col++)
        {
            if (revealed[row][col])
            {
                printf("%c ", board[row][col]);
            }
            else
            {
                printf("* ");
            }
        }

        printf("\n");
    }

    printf("\n");
}

void shuffle_board(char board[ROWS][COLS])
{
    int row, col, rand_row, rand_col;
    char temp;

    // Loop through all tiles
    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLS; col++)
        {
            // Pick a random tile to swap with
            rand_row = rand() % ROWS;
            rand_col = rand() % COLS;

            // Swap the tiles
            temp = board[row][col];
            board[row][col] = board[rand_row][rand_col];
            board[rand_row][rand_col] = temp;
        }
    }
}

int check_win(int revealed[ROWS][COLS])
{
    int row, col;

    // Loop through all tiles
    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLS; col++)
        {
            // If any tile is unrevealed, the game is not won
            if (!revealed[row][col])
            {
                return 0;
            }
        }
    }

    // If all tiles are revealed, the game is won
    return 1;
}