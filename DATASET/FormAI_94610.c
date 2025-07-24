//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 10

void initialize_board(char board[ROWS][COLS]);
void print_board(char board[ROWS][COLS]);
int move(char board[ROWS][COLS], int row, int col);
int check_game_over(char board[ROWS][COLS]);
void generate_enemy(char board[ROWS][COLS]);
void move_enemy(char board[ROWS][COLS]);

int main()
{
    char board[ROWS][COLS];
    int row = ROWS - 1, col = COLS / 2 - 1;
    int score = 0, game_over = 0;

    initialize_board(board);
    print_board(board);

    while (!game_over)
    {
        int hit = move(board, row, col);

        if (hit)
        {
            generate_enemy(board);
            score++;
            printf("Score: %d\n", score);
        }

        move_enemy(board);
        game_over = check_game_over(board);
        print_board(board);
    }

    printf("Game over! Final score: %d\n", score);

    return 0;
}

void initialize_board(char board[ROWS][COLS])
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            board[i][j] = '.';
        }
    }

    board[ROWS - 1][COLS / 2 - 1] = 'O';
}

void print_board(char board[ROWS][COLS])
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int move(char board[ROWS][COLS], int row, int col)
{
    int move_row, move_col;
    int hit = 0;

    printf("Move: ");
    scanf("%d %d", &move_row, &move_col);

    board[row][col] = '.';

    row += move_row;
    col += move_col;

    if (row < 0 || row >= ROWS || col < 0 || col >= COLS)
    {
        printf("Invalid move!\n");
        row -= move_row;
        col -= move_col;
    }
    else if (board[row][col] == '*')
    {
        printf("Hit!\n");
        hit = 1;
        board[row][col] = '.';
    }
    else
    {
        board[row][col] = 'O';
    }

    return hit;
}

int check_game_over(char board[ROWS][COLS])
{
    int i;

    for (i = 0; i < COLS; i++)
    {
        if (board[0][i] == '*')
        {
            return 1;
        }
    }

    return 0;
}

void generate_enemy(char board[ROWS][COLS])
{
    int col;
    srand(time(NULL));
    col = rand() % COLS;
    board[0][col] = '*';
}

void move_enemy(char board[ROWS][COLS])
{
    int i, j;

    for (i = ROWS - 2; i >= 0; i--)
    {
        for (j = 0; j < COLS; j++)
        {
            if (board[i][j] == '*')
            {
                board[i][j] = '.';
                board[i + 1][j] = '*';
            }
        }
    }
}