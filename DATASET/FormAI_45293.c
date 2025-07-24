//FormAI DATASET v1.0 Category: Chess AI ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

int piece_values[] = { 0, 1, 3, 3, 5, 9 }; // pawn, rook, knight, bishop, queen, king
int piece_positions[] = // piece-square tables
{
    0,  0,  0,  0,  0,  0,  0,  0,
    5, 10, 10,-20,-20, 10, 10,  5,
   -5,-10,  0,  0,  0,  0,-10, -5,
   -5, -5,-10,-10,-10,-10, -5, -5,
    0,  0,  0,  0,  0,  0,  0,  0,
   -5,-10,-10,-10,-10,-10,-10, -5,
   -5, -5, -5, -5, -5, -5, -5, -5,
    0,  0,  0,  5,  5,  0,  0,  0
};

typedef struct piece_t { int type; int x; int y; } piece_t;

int evaluate_position(int board[BOARD_SIZE][BOARD_SIZE])
{
    int score = 0;
    for (int y = 0; y < BOARD_SIZE; y++)
    {
        for (int x = 0; x < BOARD_SIZE; x++)
        {
            int piece_type = abs(board[y][x]);
            if (piece_type != 0)
            {
                int piece_value = piece_values[piece_type];
                score += piece_value * (board[y][x] / piece_type);
                score += piece_positions[piece_type * BOARD_SIZE + (y * BOARD_SIZE + x)] * (board[y][x] / piece_type);
            }
        }
    }
    return score;
}

int is_valid_move(int board[BOARD_SIZE][BOARD_SIZE], int from_x, int from_y, int to_x, int to_y)
{
    int from_piece = board[from_y][from_x];
    int to_piece = board[to_y][to_x];

    if (from_piece == 0) return 0;
    if ((from_piece < 0 && to_piece < 0) || (from_piece > 0 && to_piece > 0)) return 0;

    switch (abs(from_piece))
    {
        case 1: // pawn
            if (from_x == to_x && abs(to_y - from_y) == 1 && to_piece == 0) return 1;
            if (abs(to_x - from_x) == 1 && abs(to_y - from_y) == 1 && to_piece != 0) return 1;
            if (from_x == to_x && abs(to_y - from_y) == 2 && (to_piece == 0 && from_piece > 0))
            {
                if (from_y == 1 && board[2][from_x] == 0) return 1;
                if (from_y == 6 && board[5][from_x] == 0) return 1;
            }
            break;
        case 2: // rook
            if (from_x == to_x || from_y == to_y)
            {
                if (from_y == to_y) // move horizontally
                {
                    int min_x = (from_x < to_x ? from_x : to_x);
                    int max_x = (from_x < to_x ? to_x : from_x);
                    for (int i = min_x + 1; i < max_x; i++)
                    {
                        if (board[from_y][i] != 0) return 0;
                    }
                }
                else // move vertically
                {
                    int min_y = (from_y < to_y ? from_y : to_y);
                    int max_y = (from_y < to_y ? to_y : from_y);
                    for (int i = min_y + 1; i < max_y; i++)
                    {
                        if (board[i][from_x] != 0) return 0;
                    }
                }
                return 1;
            }
            break;
        case 3: // knight
            if ((abs(to_x - from_x) == 2 && abs(to_y - from_y) == 1) || (abs(to_x - from_x) == 1 && abs(to_y - from_y) == 2))
            {
                return 1;
            }
            break;
        case 4: // bishop
            if (abs(to_x - from_x) == abs(to_y - from_y))
            {
                int min_x = (from_x < to_x ? from_x : to_x);
                int max_x = (from_x < to_x ? to_x : from_x);
                int min_y = (from_y < to_y ? from_y : to_y);
                int max_y = (from_y < to_y ? to_y : from_y);
                for (int i = 1; i < max_x - min_x; i++)
                {
                    if (board[min_y + i][min_x + i] != 0) return 0;
                }
                return 1;
            }
            break;
        case 5: // queen
            if (from_x == to_x || from_y == to_y)
            {
                if (from_y == to_y)
                {
                    int min_x = (from_x < to_x ? from_x : to_x);
                    int max_x = (from_x < to_x ? to_x : from_x);
                    for (int i = min_x + 1; i < max_x; i++)
                    {
                        if (board[from_y][i] != 0) return 0;
                    }
                }
                else
                {
                    int min_y = (from_y < to_y ? from_y : to_y);
                    int max_y = (from_y < to_y ? to_y : from_y);
                    for (int i = min_y + 1; i < max_y; i++)
                    {
                        if (board[i][from_x] != 0) return 0;
                    }
                }
                return 1;
            }
            if (abs(to_x - from_x) == abs(to_y - from_y))
            {
                int min_x = (from_x < to_x ? from_x : to_x);
                int max_x = (from_x < to_x ? to_x : from_x);
                int min_y = (from_y < to_y ? from_y : to_y);
                int max_y = (from_y < to_y ? to_y : from_y);
                for (int i = 1; i < max_x - min_x; i++)
                {
                    if (board[min_y + i][min_x + i] != 0) return 0;
                }
                return 1;
            }
            break;
        case 6: // king
            if (abs(to_x - from_x) <= 1 && abs(to_y - from_y) <= 1)
            {
                return 1;
            }
            if (from_y == to_y && abs(to_x - from_x) == 2)
            {
                int dir = (to_x > from_x ? 1 : -1);
                int rook_x = (dir == 1 ? 7 : 0);
                int is_castle_possible = 1;
                for (int i = from_x + dir; i != to_x; i += dir)
                {
                    if (board[from_y][i] != 0) is_castle_possible = 0;
                }
                if (board[from_y][rook_x] != dir * 2 || board[from_y][from_x] != dir * 6) is_castle_possible = 0;
                if (is_castle_possible) return 2;
            }
            break;
    }
    return 0;
}

int make_move(int board[BOARD_SIZE][BOARD_SIZE], int from_x, int from_y, int to_x, int to_y, int promotion_type)
{
    int from_piece = board[from_y][from_x];
    int to_piece = board[to_y][to_x];

    if (is_valid_move(board, from_x, from_y, to_x, to_y))
    {
        if (to_piece != 0 || from_piece == 1 || from_piece == -1) // capture or pawn move
        {
            board[to_y][to_x] = from_piece;
            board[from_y][from_x] = 0;
        }
        else if (from_piece == 6 || from_piece == -6) // castle move
        {
            board[to_y][to_x] = from_piece;
            board[from_y][from_x] = 0;

            if (to_x == 2) // queenside castle
            {
                board[to_y][3] = (from_piece / 6) * 2;
                board[to_y][0] = 0;
            }
            else if (to_x == 6) // kingside castle
            {
                board[to_y][5] = (from_piece / 6) * 2;
                board[to_y][7] = 0;
            }
        }
        else // move without capture or pawn move
        {
            board[to_y][to_x] = from_piece;
            board[from_y][from_x] = 0;
        }

        // promotion
        if ((promotion_type != 0 && from_piece == 1 && to_y == 0) || (promotion_type != 0 && from_piece == -1 && to_y == BOARD_SIZE - 1))
        {
            board[to_y][to_x] = promotion_type;
        }
        return 1;
    }
    return 0;
}

piece_t* get_next_piece(int board[BOARD_SIZE][BOARD_SIZE], int color, piece_t* current_piece)
{
    int x = current_piece == NULL ? 0 : current_piece->x;
    int y = current_piece == NULL ? 0 : current_piece->y;

    for (; y < BOARD_SIZE; y++)
    {
        for (; x < BOARD_SIZE; x++)
        {
            if (board[y][x] * color > 0)
            {
                piece_t* piece = (piece_t*)malloc(sizeof(piece_t));
                piece->type = abs(board[y][x]);
                piece->x = x;
                piece->y = y;
                return piece;
            }
        }
        x = 0;
    }
    return NULL;
}

int get_num_moves(int board[BOARD_SIZE][BOARD_SIZE], int color)
{
    int num_moves = 0;
    piece_t* current_piece = NULL;
    while ((current_piece = get_next_piece(board, color, current_piece)) != NULL)
    {
        int from_x = current_piece->x;
        int from_y = current_piece->y;

        for (int to_y = 0; to_y < BOARD_SIZE; to_y++)
        {
            for (int to_x = 0; to_x < BOARD_SIZE; to_x++)
            {
                if (make_move(board, from_x, from_y, to_x, to_y, 5))
                {
                    num_moves++;
                }
            }
        }

        free(current_piece);
    }
    return num_moves;
}

int minimax(int board[BOARD_SIZE][BOARD_SIZE], int depth, int alpha, int beta, int is_max_player)
{
    if (depth == 0) return evaluate_position(board); // leaf node

    int num_moves = get_num_moves(board, is_max_player ? 1 : -1);
    if (num_moves == 0) return evaluate_position(board); // leaf node

    piece_t* current_piece = NULL;
    while ((current_piece = get_next_piece(board, is_max_player ? 1 : -1, current_piece)) != NULL)
    {
        int from_x = current_piece->x;
        int from_y = current_piece->y;

        for (int to_y = 0; to_y < BOARD_SIZE; to_y++)
        {
            for (int to_x = 0; to_x < BOARD_SIZE; to_x++)
            {
                int move_status = make_move(board, from_x, from_y, to_x, to_y, 5);
                if (move_status != 0)
                {
                    int score = minimax(board, depth - 1, alpha, beta, !is_max_player);

                    make_move(board, to_x, to_y, from_x, from_y, 5);

                    if (is_max_player && score > alpha) alpha = score;
                    if (!is_max_player && score < beta) beta = score;
                    if (alpha >= beta) break;
                }
            }
        }

        free(current_piece);

        if (alpha >= beta) break;
    }
    return is_max_player ? alpha : beta;
}

void get_best_move(int board[BOARD_SIZE][BOARD_SIZE], int* from_x, int* from_y, int* to_x, int* to_y)
{
    int alpha = -10000;
    int beta = 10000;
    int is_max_player = 1;
    int best_score = -10000;

    piece_t* current_piece = NULL;
    while ((current_piece = get_next_piece(board, is_max_player ? 1 : -1, current_piece)) != NULL)
    {
        int from_x_ = current_piece->x;
        int from_y_ = current_piece->y;

        for (int to_y_ = 0; to_y_ < BOARD_SIZE; to_y_++)
        {
            for (int to_x_ = 0; to_x_ < BOARD_SIZE; to_x_++)
            {
                int move_status = make_move(board, from_x_, from_y_, to_x_, to_y_, 5);
                if (move_status != 0)
                {
                    int score = minimax(board, 2, alpha, beta, !is_max_player);

                    make_move(board, to_x_, to_y_, from_x_, from_y_, 5);

                    if (score > best_score)
                    {
                        best_score = score;
                        *from_x = from_x_;
                        *from_y = from_y_;
                        *to_x = to_x_;
                        *to_y = to_y_;
                    }
                }
            }
        }

        free(current_piece);
    }
}

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] =
    {
        -2, -3, -4, -6, -5, -4, -3, -2,
        -1, -1, -1, -1, -1, -1, -1, -1,
         0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  1,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,
         1,  1,  1,  1,  1,  1,  1,  1,
         2,  3,  4,  6,  5,  4,  3,  2,
    };

    int from_x, from_y, to_x, to_y;
    get_best_move(board, &from_x, &from_y, &to_x, &to_y);
    printf("Best move found: %c%d to %c%d\n", from_x + 'a', BOARD_SIZE - from_y, to_x + 'a', BOARD_SIZE - to_y);
    return 0;
}