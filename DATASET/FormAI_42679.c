//FormAI DATASET v1.0 Category: Memory Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define MAX_MOVES 50

void display_board(int board[ROWS][COLS], int moves);
void shuffle_board(int board[ROWS][COLS]);
int move_tile(int board[ROWS][COLS]);
int check_win(int board[ROWS][COLS]);

int main()
{
    int board[ROWS][COLS] = {0};
    int moves = 0;
    int score = 0;
    int done = 0;

    srand(time(NULL)); // for randomization

    shuffle_board(board); // shuffle the board

    while (!done && moves < MAX_MOVES)
    {
        display_board(board, moves); // display the board
        score += move_tile(board); // move a tile and add to score
        done = check_win(board); // check if the game is won
        moves++; // increment moves
    }

    display_board(board, moves); // display the final board
    printf("Final Score: %d\n", score); // print the final score

    return 0;
}

// displays the game board
void display_board(int board[ROWS][COLS], int moves)
{
    printf("Moves: %d\n", moves);
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// shuffles the game board
void shuffle_board(int board[ROWS][COLS])
{
    int tiles[ROWS*COLS];
    int num_tiles = 0;

    // populate tiles array with numbers 1 to 16
    for (int i = 1; i <= ROWS*COLS; i++)
    {
        tiles[num_tiles] = i;
        num_tiles++;
    }

    // shuffle tiles array using Fisher-Yates shuffle
    for (int i = num_tiles - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = tiles[j];
        tiles[j] = tiles[i];
        tiles[i] = temp;
    }

    // populate board array with shuffled tiles
    int k = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            board[i][j] = tiles[k];
            k++;
        }
    }
}

// moves a tile and returns the score
int move_tile(int board[ROWS][COLS])
{
    int row_src, col_src, row_dest, col_dest;
    int score = 0;

    printf("Enter source row:");
    scanf("%d", &row_src);
    printf("Enter source col:");
    scanf("%d", &col_src);
    printf("Enter destination row:");
    scanf("%d", &row_dest);
    printf("Enter destination col:");
    scanf("%d", &col_dest);

    if (row_src < 0 || row_src >= ROWS || col_src < 0 || col_src >= COLS ||
        row_dest < 0 || row_dest >= ROWS || col_dest < 0 || col_dest >= COLS)
    {
        printf("Invalid move!\n");
    }
    else if (board[row_src][col_src] == 0)
    {
        printf("There is no tile at the source position!\n");
    }
    else if (board[row_dest][col_dest] != 0)
    {
        printf("There is already a tile at the destination position!\n");
    }
    else
    {
        board[row_dest][col_dest] = board[row_src][col_src];
        board[row_src][col_src] = 0;
        score = abs(row_dest - row_src) + abs(col_dest - col_src); // calculate score
    }

    return score;
}

// checks if the game is won and returns 1 if yes, 0 otherwise
int check_win(int board[ROWS][COLS])
{
    int win = 1;
    int count = 1;

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (board[i][j] != count && count != ROWS*COLS)
            {
                win = 0;
                break;
            }
            count++;
        }
    }

    return win;
}