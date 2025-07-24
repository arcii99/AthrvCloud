//FormAI DATASET v1.0 Category: Chess engine ; Style: automated
#include <stdio.h>

#define BOARD_DIM 8
#define NUM_PIECES 6

enum Pieces { EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING };
enum Colors { WHITE, BLACK };
enum Results { NONE, DRAW, WHITE_WIN, BLACK_WIN };

const char * const piece_names[NUM_PIECES] = {
    "", "Pawn", "Knight", "Bishop", "Rook", "Queen", "King"
};
const char * const color_names[NUM_PIECES] = { "White", "Black" };

typedef struct {
    int row;
    int col;
} Position;

typedef struct {
    int type;
    int color;
    Position pos;
} Piece;

typedef struct {
    Piece * board[BOARD_DIM][BOARD_DIM];
    int turn;
    int result;
} Game;

int initialize_game(Game * game);
void print_board(const Game * game);
int is_valid_move(const Game * game, Position start, Position end);
int move(Game * game, Position start, Position end);
int checkmate(const Game * game);
int stalemate(const Game * game);

int main(void)
{
    Game game;
    initialize_game(&game);
    print_board(&game);
    
    int playing = 1;
    do {
        int row1, col1, row2, col2;
        printf("%s's move: ", color_names[game.turn]);
        scanf("%d%d%d%d", &row1, &col1, &row2, &col2);
        Position start = { row1, col1 };
        Position end = { row2, col2 };
        if (is_valid_move(&game, start, end)) {
            move(&game, start, end);
            if (checkmate(&game)) {
                int result = game.turn == WHITE ? BLACK_WIN : WHITE_WIN;
                printf("%s wins!\n", color_names[result]);
                playing = 0;
            }
            else if (stalemate(&game)) {
                puts("Stalemate!");
                playing = 0;
            }
            else {
                print_board(&game);
            }
        }
        else {
            puts("Invalid move!");
        }
    } while (playing);
    
    return 0;
}

int initialize_game(Game * game)
{
    game->turn = WHITE;
    game->result = NONE;
    int row, col;
    // initialize white pieces
    for (col = 0; col < BOARD_DIM; ++col) {
        game->board[1][col] = (Piece *) malloc (sizeof(Piece));
        game->board[1][col]->type = PAWN;
        game->board[1][col]->color = WHITE;
        game->board[1][col]->pos.row = 1;
        game->board[1][col]->pos.col = col;
    }
    game->board[0][0] = (Piece *) malloc (sizeof(Piece));
    game->board[0][0]->type = ROOK;
    game->board[0][0]->color = WHITE;
    game->board[0][0]->pos.row = 0;
    game->board[0][0]->pos.col = 0;
    game->board[0][BOARD_DIM - 1] = (Piece *) malloc (sizeof(Piece));
    game->board[0][BOARD_DIM - 1]->type = ROOK;
    game->board[0][BOARD_DIM - 1]->color = WHITE;
    game->board[0][BOARD_DIM - 1]->pos.row = 0;
    game->board[0][BOARD_DIM - 1]->pos.col = BOARD_DIM - 1;
    game->board[0][1] = (Piece *) malloc (sizeof(Piece));
    game->board[0][1]->type = KNIGHT;
    game->board[0][1]->color = WHITE;
    game->board[0][1]->pos.row = 0;
    game->board[0][1]->pos.col = 1;
    game->board[0][BOARD_DIM - 2] = (Piece *) malloc (sizeof(Piece));
    game->board[0][BOARD_DIM - 2]->type = KNIGHT;
    game->board[0][BOARD_DIM - 2]->color = WHITE;
    game->board[0][BOARD_DIM - 2]->pos.row = 0;
    game->board[0][BOARD_DIM - 2]->pos.col = BOARD_DIM - 2;
    game->board[0][2] = (Piece *) malloc (sizeof(Piece));
    game->board[0][2]->type = BISHOP;
    game->board[0][2]->color = WHITE;
    game->board[0][2]->pos.row = 0;
    game->board[0][2]->pos.col = 2;
    game->board[0][BOARD_DIM - 3] = (Piece *) malloc (sizeof(Piece));
    game->board[0][BOARD_DIM - 3]->type = BISHOP;
    game->board[0][BOARD_DIM - 3]->color = WHITE;
    game->board[0][BOARD_DIM - 3]->pos.row = 0;
    game->board[0][BOARD_DIM - 3]->pos.col = BOARD_DIM - 3;
    game->board[0][3] = (Piece *) malloc (sizeof(Piece));
    game->board[0][3]->type = QUEEN;
    game->board[0][3]->color = WHITE;
    game->board[0][3]->pos.row = 0;
    game->board[0][3]->pos.col = 3;
    game->board[0][4] = (Piece *) malloc (sizeof(Piece));
    game->board[0][4]->type = KING;
    game->board[0][4]->color = WHITE;
    game->board[0][4]->pos.row = 0;
    game->board[0][4]->pos.col = 4;
    // initialize black pieces
    for (col = 0; col < BOARD_DIM; ++col) {
        game->board[BOARD_DIM - 2][col] = (Piece *) malloc (sizeof(Piece));
        game->board[BOARD_DIM - 2][col]->type = PAWN;
        game->board[BOARD_DIM - 2][col]->color = BLACK;
        game->board[BOARD_DIM - 2][col]->pos.row = BOARD_DIM - 2;
        game->board[BOARD_DIM - 2][col]->pos.col = col;
    }
    game->board[BOARD_DIM - 1][0] = (Piece *) malloc (sizeof(Piece));
    game->board[BOARD_DIM - 1][0]->type = ROOK;
    game->board[BOARD_DIM - 1][0]->color = BLACK;
    game->board[BOARD_DIM - 1][0]->pos.row = BOARD_DIM - 1;
    game->board[BOARD_DIM - 1][0]->pos.col = 0;
    game->board[BOARD_DIM - 1][BOARD_DIM - 1] = (Piece *) malloc (sizeof(Piece));
    game->board[BOARD_DIM - 1][BOARD_DIM - 1]->type = ROOK;
    game->board[BOARD_DIM - 1][BOARD_DIM - 1]->color = BLACK;
    game->board[BOARD_DIM - 1][BOARD_DIM - 1]->pos.row = BOARD_DIM - 1;
    game->board[BOARD_DIM - 1][BOARD_DIM - 1]->pos.col = BOARD_DIM - 1;
    game->board[BOARD_DIM - 1][1] = (Piece *) malloc (sizeof(Piece));
    game->board[BOARD_DIM - 1][1]->type = KNIGHT;
    game->board[BOARD_DIM - 1][1]->color = BLACK;
    game->board[BOARD_DIM - 1][1]->pos.row = BOARD_DIM - 1;
    game->board[BOARD_DIM - 1][1]->pos.col = 1;
    game->board[BOARD_DIM - 1][BOARD_DIM - 2] = (Piece *) malloc (sizeof(Piece));
    game->board[BOARD_DIM - 1][BOARD_DIM - 2]->type = KNIGHT;
    game->board[BOARD_DIM - 1][BOARD_DIM - 2]->color = BLACK;
    game->board[BOARD_DIM - 1][BOARD_DIM - 2]->pos.row = BOARD_DIM - 1;
    game->board[BOARD_DIM - 1][BOARD_DIM - 2]->pos.col = BOARD_DIM - 2;
    game->board[BOARD_DIM - 1][2] = (Piece *) malloc (sizeof(Piece));
    game->board[BOARD_DIM - 1][2]->type = BISHOP;
    game->board[BOARD_DIM - 1][2]->color = BLACK;
    game->board[BOARD_DIM - 1][2]->pos.row = BOARD_DIM - 1;
    game->board[BOARD_DIM - 1][2]->pos.col = 2;
    game->board[BOARD_DIM - 1][BOARD_DIM - 3] = (Piece *) malloc (sizeof(Piece));
    game->board[BOARD_DIM - 1][BOARD_DIM - 3]->type = BISHOP;
    game->board[BOARD_DIM - 1][BOARD_DIM - 3]->color = BLACK;
    game->board[BOARD_DIM - 1][BOARD_DIM - 3]->pos.row = BOARD_DIM - 1;
    game->board[BOARD_DIM - 1][BOARD_DIM - 3]->pos.col = BOARD_DIM - 3;
    game->board[BOARD_DIM - 1][3] = (Piece *) malloc (sizeof(Piece));
    game->board[BOARD_DIM - 1][3]->type = QUEEN;
    game->board[BOARD_DIM - 1][3]->color = BLACK;
    game->board[BOARD_DIM - 1][3]->pos.row = BOARD_DIM - 1;
    game->board[BOARD_DIM - 1][3]->pos.col = 3;
    game->board[BOARD_DIM - 1][4] = (Piece *) malloc (sizeof(Piece));
    game->board[BOARD_DIM - 1][4]->type = KING;
    game->board[BOARD_DIM - 1][4]->color = BLACK;
    game->board[BOARD_DIM - 1][4]->pos.row = BOARD_DIM - 1;
    game->board[BOARD_DIM - 1][4]->pos.col = 4;
    // initialize empty squares
    for (row = 2; row < BOARD_DIM - 2; ++row) {
        for (col = 0; col < BOARD_DIM; ++col) {
            game->board[row][col] = NULL;
        }
    }
    return 0;
}

void print_board(const Game * game)
{
    int row, col;
    for (row = 0; row < BOARD_DIM; ++row) {
        for (col = 0; col < BOARD_DIM; ++col) {
            if (game->board[row][col] != NULL) {
                printf("%s %s ", color_names[game->board[row][col]->color],
                    piece_names[game->board[row][col]->type]);
            }
            else {
                printf("_______ ");
            }
        }
        putchar('\n');
    }
}

int is_valid_move(const Game * game, Position start, Position end)
{
    // empty square
    if (game->board[start.row][start.col] == NULL) {
        return 0;
    }
    // move onto own piece
    if (game->board[end.row][end.col] != NULL &&
        game->board[end.row][end.col]->color == game->board[start.row][start.col]->color) {
        return 0;
    }
    // check each piece type
    switch (game->board[start.row][start.col]->type) {
        case PAWN:
            // move forward one or two spaces
            if (end.col == start.col &&
                ((game->board[start.row][start.col]->color == WHITE &&
                end.row - start.row == -1) ||
                (game->board[start.row][start.col]->color == BLACK &&
                end.row - start.row == 1))) {
                if (game->board[end.row][end.col] == NULL) {
                    return 1;
                }
            }
            // capture
            if (end.col == start.col + 1 || end.col == start.col - 1) {
                if (game->board[end.row][end.col] != NULL &&
                    game->board[end.row][end.col]->color != game->board[start.row][start.col]->color) {
                    return 1;
                }
            }
            break;
        case KNIGHT:
            // L-shaped moves
            if ((abs(end.row - start.row) == 2 && abs(end.col - start.col) == 1) ||
                (abs(end.row - start.row) == 1 && abs(end.col - start.col) == 2)) {
                if (game->board[end.row][end.col] == NULL ||
                    game->board[end.row][end.col]->color != game->board[start.row][start.col]->color) {
                    return 1;
                }
            }
            break;
        case BISHOP:
            // diagonal moves
            if (abs(end.row - start.row) == abs(end.col - start.col)) {
                int i;
                int d_row = (end.row > start.row ? 1 : -1);
                int d_col = (end.col > start.col ? 1 : -1);
                for (i = 1; i < abs(end.row - start.row); ++i) {
                    if (game->board[start.row + i * d_row][start.col + i * d_col] != NULL) {
                        return 0;
                    }
                }
                if (game->board[end.row][end.col] == NULL ||
                    game->board[end.row][end.col]->color != game->board[start.row][start.col]->color) {
                    return 1;
                }
            }
            break;
        case ROOK:
            // horizontal or vertical moves
            if (end.row == start.row || end.col == start.col) {
                int i;
                int d_row = (end.row > start.row ? 1 : (end.row == start.row ? 0 : -1));
                int d_col = (end.col > start.col ? 1 : (end.col == start.col ? 0 : -1));
                for (i = 1; i < abs(end.row - start.row) + abs(end.col - start.col); ++i) {
                    if (game->board[start.row + i * d_row][start.col + i * d_col] != NULL) {
                        return 0;
                    }
                }
                if (game->board[end.row][end.col] == NULL ||
                    game->board[end.row][end.col]->color != game->board[start.row][start.col]->color) {
                    return 1;
                }
            }
            break;
        case QUEEN:
            // diagonal, horizontal, or vertical moves
            if (end.row == start.row || end.col == start.col ||
                abs(end.row - start.row) == abs(end.col - start.col)) {
                int i;
                int d_row = (end.row > start.row ? 1 : (end.row == start.row ? 0 : -1));
                int d_col = (end.col > start.col ? 1 : (end.col == start.col ? 0 : -1));
                for (i = 1; i < abs(end.row - start.row) + abs(end.col - start.col); ++i) {
                    if (game->board[start.row + i * d_row][start.col + i * d_col] != NULL) {
                        return 0;
                    }
                }
                if (game->board[end.row][end.col] == NULL ||
                    game->board[end.row][end.col]->color != game->board[start.row][start.col]->color) {
                    return 1;
                }
            }
            break;
        case KING:
            // one space in any direction
            if (abs(end.row - start.row) <= 1 && abs(end.col - start.col) <= 1) {
                if (game->board[end.row][end.col] == NULL ||
                    game->board[end.row][end.col]->color != game->board[start.row][start.col]->color) {
                    return 1;
                }
            }
            break;
    }
    return 0;
}

int move(Game * game, Position start, Position end)
{
    Piece * piece = game->board[start.row][start.col];
    game->board[start.row][start.col] = NULL;
    piece->pos.row = end.row;
    piece->pos.col = end.col;
    game->board[end.row][end.col] = piece;
    game->turn = game->turn == WHITE ? BLACK : WHITE;
    return 0;
}

int checkmate(const Game * game)
{
    // TODO: implement
    return 0;
}

int stalemate(const Game * game)
{
    // TODO: implement
    return 0;
}