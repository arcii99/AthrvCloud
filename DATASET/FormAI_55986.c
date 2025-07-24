//FormAI DATASET v1.0 Category: Recursive ; Style: medieval
#include <stdio.h>

void knights_tour(int chess[][8], int row, int col, int move);

void print_board(int board[][8])
{
    int i, j;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(int x, int y, int chess[][8])
{
    if (x >= 0 && y >= 0 && x <= 7 && y <= 7 && chess[x][y] == -1)
        return 1;
    return 0;
}

int knights_move(int x, int y, int chess[][8], int moves[][2])
{
    int i, next_x, next_y;
    for (i = 0; i < 8; i++)
    {
        next_x = x + moves[i][0];
        next_y = y + moves[i][1];
        if (is_valid_move(next_x, next_y, chess))
        {
            return i;
        }
    }
    return -1;
}

void knights_tour(int chess[][8], int row, int col, int move)
{
    int moves[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1},
                       {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
    int i, x, y;

    if (move == 64)
    {
        printf("Knights tour complete!\n");
        print_board(chess);
        return;
    }

    for (i = 0; i < 8; i++)
    {
        x = row + moves[i][0];
        y = col + moves[i][1];
        if (is_valid_move(x, y, chess))
        {
            chess[x][y] = move;
            if (knights_move(x, y, chess, moves) == -1)
            {
                knights_tour(chess, x, y, move + 1);
            }
            chess[x][y] = -1;
        }
    }
}

int main()
{
    int chess_board[8][8];
    int i, j;

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            chess_board[i][j] = -1;
        }
    }

    chess_board[0][0] = 0;

    printf("Starting knights tour...\n");
    knights_tour(chess_board, 0, 0, 1);

    return 0;
}