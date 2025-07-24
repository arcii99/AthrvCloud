//FormAI DATASET v1.0 Category: Memory Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 5

void print_board(char board[][COLS]);
void initialize_board(char board[][COLS]);
void shuffle_board(char board[][COLS]);
int check_win(char board[][COLS]);

int main()
{
    char board[ROWS][COLS];
    int row1, row2, col1, col2, num_pairs = 0;
    char temp;

    srand(time(0)); // initialize random seed
    
    initialize_board(board);
    shuffle_board(board);

    while (num_pairs < 10) // loop until all pairs are matched
    {
        print_board(board);

        printf("Enter the row and column of the first card:\n");
        scanf("%d %d", &row1, &col1);

        printf("Enter the row and column of the second card:\n");
        scanf("%d %d", &row2, &col2);

        // swap the values on the board
        temp = board[row1][col1];
        board[row1][col1] = board[row2][col2];
        board[row2][col2] = temp;

        if (check_win(board))
        {
            printf("You matched all the pairs! Congratulations!\n");
            return 0;
        }

        num_pairs++;
    }

    printf("Game over. You did not match all the pairs.\n");

    return 0;
}

/**
 * Prints the game board.
 */
void print_board(char board[][COLS])
{
    int i, j;

    printf("\n");

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%c ", board[i][j]);
        }

        printf("\n");
    }

    printf("\n");
}

/**
 * Initializes the game board with pairs of letters.
 */
void initialize_board(char board[][COLS])
{
    int i, j, k = 65; // use ASCII values for letters A to Z

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            board[i][j] = k++;

            if (k == 91) // wrap around to A after Z
            {
                k = 65;
            }
        }
    }
}

/**
 * Shuffles the game board by swapping random pairs of tiles.
 */
void shuffle_board(char board[][COLS])
{
    int i, j, k;

    for (k = 0; k < 100; k++) // shuffle 100 times
    {
        i = rand() % ROWS;
        j = rand() % COLS;

        // pick a random tile and its neighbor and swap values
        if (i < ROWS - 1)
        {
            board[i][j] ^= board[i+1][j];
            board[i+1][j] ^= board[i][j];
            board[i][j] ^= board[i+1][j];
        }

        if (j < COLS - 1)
        {
            board[i][j] ^= board[i][j+1];
            board[i][j+1] ^= board[i][j];
            board[i][j] ^= board[i][j+1];
        }
    }
}

/**
 * Returns 1 if all tiles on the board match each other, otherwise 0.
 */
int check_win(char board[][COLS])
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (board[i][j] != board[0][0])
            {
                return 0;
            }
        }
    }

    return 1;
}