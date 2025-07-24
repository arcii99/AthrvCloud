//FormAI DATASET v1.0 Category: Chess engine ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BOARD_LENGTH 8
#define MAX_MOVE_LENGTH 6
#define NO_PIECE ' '

typedef enum { P, N, B, R, Q, K } piece_t;
typedef enum { WHITE, BLACK } color_t;

typedef struct {
    piece_t piece;
    color_t color;
} square_t;

typedef struct {
    square_t board[BOARD_LENGTH][BOARD_LENGTH];
    color_t turn;
} game_t;

void init_board(game_t *game) {
    int i, j;
    piece_t pieces[] = { R, N, B, Q, K, B, N, R };
    for (i = 0; i < BOARD_LENGTH; i++) {
        for (j = 0; j < BOARD_LENGTH; j++) {
            if (i == 0 || i == BOARD_LENGTH-1) {
                game->board[i][j].piece = pieces[j];
                game->board[i][j].color = (i == 0) ? BLACK : WHITE;
            } else if (i == 1 || i == BOARD_LENGTH-2) {
                game->board[i][j].piece = P;
                game->board[i][j].color = (i == 1) ? BLACK : WHITE;
            } else {
                game->board[i][j].piece = NO_PIECE;
                game->board[i][j].color = (j % 2 != i % 2) ? BLACK : WHITE;
            }
        }
    }
    game->turn = WHITE;
}

void print_board(game_t game) {
    int i, j;
    printf("  A B C D E F G H\n");
    for (i = 0; i < BOARD_LENGTH; i++) {
        printf("%d ", BOARD_LENGTH - i);
        for (j = 0; j < BOARD_LENGTH; j++) {
            printf("%c ", (game.board[i][j].piece == NO_PIECE) ? '.' : game.board[i][j].piece);
        }
        printf("%d\n", BOARD_LENGTH - i);
    }
    printf("  A B C D E F G H\n");
}

int is_valid_move(char *move) {
    if (strlen(move) != MAX_MOVE_LENGTH) {
        return 0;
    }
    if (!isalpha(move[0]) || !isalpha(move[3])) {
        return 0;
    }
    if (!isdigit(move[1]) || !isdigit(move[4])) {
        return 0;
    }
    if (move[2] != '-') {
        return 0;
    }
    if (move[5] != '\0') {
        return 0;
    }
    return 1;
}

int is_valid_piece(piece_t piece) {
    return (piece == P || piece == N || piece == B || piece == R || piece == Q || piece == K);
}

int is_valid_color(color_t color) {
    return (color == WHITE || color == BLACK);
}

int is_empty_space(square_t square) {
    return (square.piece == NO_PIECE);
}

int is_opponent_color(game_t game, char *move, color_t color) {
    square_t square = game.board[8 - (move[2] - '0')][move[1] - 'a'];
    return (square.color != color && !is_empty_space(square));
}

int is_valid_rook_move(game_t game, char *move) {
    int move_row = 8 - (move[5] - '0');
    int move_col = move[4] - 'a';
    int i, start, end;

    if (move[4] == move[1]) {
        start = (move_row > 8) ? 8 : move_row;
        end = (move_row < 1) ? 1 : move_row;
        for (i = start; i < end; i++) {
            if (!is_empty_space(game.board[i][move_col])) {
                return 0;
            }
        }
        return 1;
    } else if (move[5] == move[2]) {
        start = (move_col > 8) ? 8 : move_col;
        end = (move_col < 1) ? 1 : move_col;
        for (i = start; i < end; i++) {
            if (!is_empty_space(game.board[move_row][i])) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

int is_valid_knight_move(char *move) {
    int row_diff = abs(8 - (move[2] - '0') - (8 - (move[5] - '0')));
    int col_diff = abs(move[1] - move[4]);
    return ((row_diff == 2 && col_diff == 1) || (row_diff == 1 && col_diff == 2));
}

int is_valid_bishop_move(game_t game, char *move) {
    int move_row = 8 - (move[5] - '0');
    int move_col = move[4] - 'a';
    int row_diff = abs(8 - (move[2] - '0') - move_row);
    int col_diff = abs(move[1] - move_col);
    int i, j;

    if (row_diff != col_diff) {
        return 0;
    }
    i = (move_row > 8) ? 8 : move_row + 1;
    j = (move_col > 8) ? 8 : move_col + 1;
    while (i < 8 && j < 8) { // check up-right diagonal
        if (!is_empty_space(game.board[i][j])) {
            return 0;
        }
        i++;
        j++;
    }
    i = (move_row < 1) ? 1 : move_row - 1;
    j = (move_col > 8) ? 8 : move_col + 1;
    while (i >= 0 && j < 8) { // check down-right diagonal
        if (!is_empty_space(game.board[i][j])) {
            return 0;
        }
        i--;
        j++;
    }
    i = (move_row > 8) ? 8 : move_row + 1;
    j = (move_col < 1) ? 1 : move_col - 1;
    while (i < 8 && j >= 0) { // check up-left diagonal
        if (!is_empty_space(game.board[i][j])) {
            return 0;
        }
        i++;
        j--;
    }
    i = (move_row < 1) ? 1 : move_row - 1;
    j = (move_col < 1) ? 1 : move_col - 1;
    while (i >= 0 && j >= 0) { // check down-left diagonal
        if (!is_empty_space(game.board[i][j])) {
            return 0;
        }
        i--;
        j--;
    }
    return 1;
}

int is_valid_queen_move(game_t game, char *move) {
    return (is_valid_rook_move(game, move) || is_valid_bishop_move(game, move));
}

int is_valid_king_move(char *move) {
    int row_diff = abs(8 - (move[2] - '0') - (8 - (move[5] - '0')));
    int col_diff = abs(move[1] - move[4]);
    return (row_diff < 2 && col_diff < 2);
}

int is_valid_move_piece(game_t game, square_t square, char *move) {
    if (square.color != game.turn) {
        return 0;
    }
    switch (square.piece) {
        case P:
            if (abs(move[5] - move[2]) == 2) {
                return 1; // check for pawn's initial two-step move
            } else if (move[1] == move[4]) {
                return (is_empty_space(game.board[8 - (move[5] - '0')][move[4] - 'a'])); // check for pawn's forward move
            } else {
                return (is_opponent_color(game, move, game.turn)); // check for pawn's capture move
            }
            break;
        case N:
            return (is_valid_knight_move(move)); // check for knight's move
            break;
        case B:
            return (is_valid_bishop_move(game, move)); // check for bishop's move
            break;
        case R:
            return (is_valid_rook_move(game, move)); // check for rook's move
            break;
        case Q:
            return (is_valid_queen_move(game, move)); // check for queen's move
            break;
        case K:
            return (is_valid_king_move(move)); // check for king's move
            break;
        default:
            return 0;
            break;
    }
}

void move_piece(game_t *game, char *move) {
    int from_row = 8 - (move[2] - '0');
    int from_col = move[1] - 'a';
    int to_row = 8 - (move[5] - '0');
    int to_col = move[4] - 'a';
    // update board
    game->board[to_row][to_col] = game->board[from_row][from_col];
    game->board[from_row][from_col].piece = NO_PIECE;
    // switch turn
    game->turn = (game->turn == WHITE) ? BLACK : WHITE;
}

void play_game() {
    game_t game;
    char move[MAX_MOVE_LENGTH];
    int valid;
    // initialize board
    init_board(&game);
    // loop until game is over
    while (1) {
        // print board
        print_board(game);
        // get input
        printf("%s's turn: ", (game.turn == WHITE) ? "White" : "Black");
        scanf("%s", move);
        // check valid move
        valid = is_valid_move(move) && is_valid_piece(game.board[8 - (move[2] - '0')][move[1] - 'a'].piece) && is_valid_color(game.board[8 - (move[2] - '0')][move[1] - 'a'].color) && is_valid_move_piece(game, game.board[8 - (move[2] - '0')][move[1] - 'a'], move);
        if (!valid) {
            printf("Invalid move.\n");
            continue;
        }
        // move piece
        move_piece(&game, move);
    }
}

int main() {
    play_game();
    return 0;
}