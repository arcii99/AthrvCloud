//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 10
#define MAX_MOVES 20

void print_board(int board[ROW][COL], int row, int col);
void instructions();
int make_move(int board[ROW][COL], int moves[2][MAX_MOVES], int *num_moves, int row, int col);
void update_board(int board[ROW][COL], int row, int col, int x, int y);

int main()
{
    int board[ROW][COL] = { 0 };  // initialize all elements to 0
    int moves[2][MAX_MOVES] = { 0 };  // initialize all elements to 0
    int num_moves = 0;
    int row = ROW;
    int col = COL;
    int game_over = 0;

    srand(time(NULL));

    instructions();
    print_board(board, row, col);

    while (!game_over && num_moves < MAX_MOVES)
    {
        game_over = make_move(board, moves, &num_moves, row, col);
        print_board(board, row, col);
    }

    printf("\nGame over!\n");

    return 0;
}

void instructions()
{
    printf("Welcome to the Terminal Game!\n");
    printf("The game board is a %d x %d grid.\n", ROW, COL);
    printf("You have to move through the board without being caught by the enemy.\n");
    printf("You have a maximum of %d moves.\n", MAX_MOVES);
}

void print_board(int board[ROW][COL], int row, int col)
{
    printf("\n");

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (board[i][j] == 0)
                printf(". ");
            else if (board[i][j] == -1)
                printf("X ");
            else if (board[i][j] == 1)
                printf("P ");
            else if (board[i][j] == 2)
                printf("M ");
        }

        printf("\n");
    }

    printf("\n");
}

int make_move(int board[ROW][COL], int moves[2][MAX_MOVES], int *num_moves, int row, int col)
{
    int x, y;
    int i, j;
    int dx, dy;

    printf("Enter your move (x,y): ");
    scanf(" %d,%d", &x, &y);

    if (x < 0 || x >= row || y < 0 || y >= col)
    {
        printf("Invalid move.\n");
        return 0;
    }

    // update board
    update_board(board, row, col, x, y);

    // add move to array
    moves[0][*num_moves] = x;
    moves[1][*num_moves] = y;
    *num_moves += 1;

    // check if player has won
    if (x == 0 || x == row - 1 || y == 0 || y == col - 1)
    {
        printf("\nCongratulations! You have won the game in %d moves.\n", *num_moves);
        return 1;
    }

    // generate enemy move
    i = rand() % row;
    j = rand() % col;

    if (i == x && j == y)
    {
        printf("\nYou have been caught by the enemy! Game over!\n");
        board[x][y] = -1;
        return 1;
    }

    dx = (i < x) ? -1 : 1;
    dy = (j < y) ? -1 : 1;

    if (board[i][j] != -1)
    {
        board[i][j] = 2;
    }
    else
    {
        board[i + dx][j] = 2;
        board[i][j + dy] = 2;
    }

    printf("\nEnemy moves to (%d,%d)\n", i, j);

    return 0;
}

void update_board(int board[ROW][COL], int row, int col, int x, int y)
{
    int dx, dy;

    // clear current position
    board[x][y] = 0;

    // move player to new position
    printf("\nPlayer moves to (%d,%d)\n", x, y);
    board[x][y] = 1;

    // move enemy
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (board[i][j] == 2)
            {
                dx = (i < x) ? -1 : 1;
                dy = (j < y) ? -1 : 1;

                if (board[i + dx][j] != -1)
                {
                    board[i + dx][j] = 2;
                    board[i][j] = 0;
                }
                else if (board[i][j + dy] != -1)
                {
                    board[i][j + dy] = 2;
                    board[i][j] = 0;
                }
            }
        }
    }
}