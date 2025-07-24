//FormAI DATASET v1.0 Category: Chess engine ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEPTH 4
#define EVAL_INF 99999

int negamax(int board[8][8], int depth, int color, int alpha, int beta);

int eval(int board[8][8])
{
    int score = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == 1)
            {
                score += 1;
            }
            else if (board[i][j] == 2)
            {
                score -= 1;
            }
        }
    }
    return score;
}

int is_move_valid(int board[8][8], int x1, int y1, int x2, int y2)
{
    if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0 || x1 >= 8 || y1 >= 8 || x2 >= 8 || y2 >= 8)
        return 0;

    if (board[x1][y1] < 1 || board[x1][y1] > 2)
        return 0;

    if (board[x2][y2] != 0)
        return 0;

    int dx = abs(x1 - x2);
    int dy = abs(y1 - y2);

    if (dx == 0 || dy == 0 || dx == dy)
    {
        int xinc = (x2 > x1) ? 1 : ((x2 == x1) ? 0 : -1);
        int yinc = (y2 > y1) ? 1 : ((y2 == y1) ? 0 : -1);
        int x = x1 + xinc, y = y1 + yinc;
        while (x != x2 || y != y2)
        {
            if (board[x][y] != 0)
                return 0;
            x += xinc;
            y += yinc;
        }
        return 1;
    }
    return 0;
}

void move(int board[8][8], int x1, int y1, int x2, int y2)
{
    int t = board[x2][y2];
    board[x2][y2] = board[x1][y1];
    board[x1][y1] = 0;
}

int negamax(int board[8][8], int depth, int color, int alpha, int beta)
{
    if (depth == 0)
    {
        return eval(board) * color;
    }

    int max_eval = -EVAL_INF;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == color)
            {
                for (int m = 0; m < 8; m++)
                {
                    for (int n = 0; n < 8; n++)
                    {
                        if (is_move_valid(board, i, j, m, n))
                        {
                            int tboard[8][8];
                            memcpy(tboard, board, sizeof(int) * 64);
                            move(tboard, i, j, m, n);
                            int eval = -negamax(tboard, depth - 1, -color, -beta, -alpha);
                            if (eval > max_eval)
                            {
                                max_eval = eval;
                                if (eval > alpha)
                                    alpha = eval;
                                if (alpha >= beta)
                                    goto AB_cut;
                            }
                        }
                    }
                }
            }
        }
    }
AB_cut:
    return max_eval;
}

int main()
{
    int board[8][8] = {
        {2, 2, 2, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2, 2, 2},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1},
    };
    int max_eval = -EVAL_INF, mx1, my1, mx2, my2;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == 1)
            {
                for (int m = 0; m < 8; m++)
                {
                    for (int n = 0; n < 8; n++)
                    {
                        if (is_move_valid(board, i, j, m, n))
                        {
                            int tboard[8][8];
                            memcpy(tboard, board, sizeof(int) * 64);
                            move(tboard, i, j, m, n);
                            int eval = -negamax(tboard, DEPTH - 1, -1, -EVAL_INF, EVAL_INF);
                            if (eval > max_eval)
                            {
                                max_eval = eval;
                                mx1 = i;
                                my1 = j;
                                mx2 = m;
                                my2 = n;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("Best move: (%d,%d)->(%d,%d), eval=%d\n", mx1, my1, mx2, my2, max_eval);
    return 0;
}