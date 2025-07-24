//FormAI DATASET v1.0 Category: Chess engine ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define BOARD_SIZE 8
#define MAX_MOVES 2048

static const int piece_values[] = {0, 100, 320, 330, 500, 900, 20000};
static const int pieces[] = {0, 'p', 'n', 'b', 'r', 'q', 'k'};
static const int black = 0;
static const int white = 1;

// Define board struct
typedef struct {
    int board[BOARD_SIZE][BOARD_SIZE];
    bool can_castle[2][2];
    int en_passant[2];
    int half_moves;
    int full_moves;
    int to_move;
} chess_board;

// Board initialization function
void init_board(chess_board *board) {
    memset(board, 0, sizeof(chess_board));
    for (int i = 0; i < BOARD_SIZE; i++) {
        board->board[1][i] = 'p';
        board->board[6][i] = 'P';
    }
    board->board[0][0] = 'r';
    board->board[0][1] = 'n';
    board->board[0][2] = 'b';
    board->board[0][3] = 'q';
    board->board[0][4] = 'k';
    board->board[0][5] = 'b';
    board->board[0][6] = 'n';
    board->board[0][7] = 'r';
    board->board[7][0] = 'R';
    board->board[7][1] = 'N';
    board->board[7][2] = 'B';
    board->board[7][3] = 'Q';
    board->board[7][4] = 'K';
    board->board[7][5] = 'B';
    board->board[7][6] = 'N';
    board->board[7][7] = 'R';
    board->can_castle[0][0] = true;
    board->can_castle[0][1] = true;
    board->can_castle[1][0] = true;
    board->can_castle[1][1] = true;
    board->en_passant[0] = -1;
    board->en_passant[1] = -1;
    board->half_moves = 0;
    board->full_moves = 1;
    board->to_move = white;
}

// Print board function
void print_board(chess_board *board) {
    printf("  a b c d e f g h \n");
    printf(" +----------------+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf(" %d|", BOARD_SIZE - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            int piece = board->board[i][j];
            if (piece == 0) {
                printf(" ");
            } else {
                printf("%c", piece);
            }
            printf("|");
        }
        printf(" %d\n", BOARD_SIZE - i);
        printf(" +----------------+\n");
    }
    printf("  a b c d e f g h \n");
}

// Parse move function
bool parse_move(chess_board *board, char *move_string) {
    int from_row, from_col, to_row, to_col;
    if (islower(move_string[0])) {
        from_col = move_string[0] - 'a';
        from_row = move_string[1] - '1';
        to_col = move_string[2] - 'a';
        to_row = move_string[3] - '1';
    } else {
        from_col = move_string[1] - 'a';
        from_row = move_string[2] - '1';
        to_col = move_string[3] - 'a';
        to_row = move_string[4] - '1';
    }
    if (from_row < 0 || from_row >= BOARD_SIZE || from_col < 0 || from_col >= BOARD_SIZE || to_row < 0 || to_row >= BOARD_SIZE || to_col < 0 || to_col >= BOARD_SIZE) {
        return false;
    }
    int piece = board->board[from_row][from_col];
    if (piece == 0) {
        return false;
    }
    if ((piece > 0 && board->to_move == black) || (piece < 0 && board->to_move == white)) {
        return false;
    }
    int abs_piece = abs(piece);
    if (abs_piece == 1) { // Pawn move
        if (from_col == to_col && board->board[to_row][to_col] == 0) { // Normal move
            if ((board->to_move == white && to_row == from_row - 1) || (board->to_move == black && to_row == from_row + 1)) {
                board->board[to_row][to_col] = piece;
                board->board[from_row][from_col] = 0;
                board->en_passant[board->to_move] = -1;
                board->half_moves++;
                board->full_moves += board->to_move;
                board->to_move = !board->to_move;
                return true;
            } else if ((board->to_move == white && from_row == 6 && to_row == 4) || (board->to_move == black && from_row == 1 && to_row == 3)) {
                board->board[to_row][to_col] = piece;
                board->board[from_row][from_col] = 0;
                board->en_passant[board->to_move] = to_col;
                board->half_moves = 0;
                board->full_moves += board->to_move;
                board->to_move = !board->to_move;
                return true;
            } else {
                return false;
            }
        } else if (to_col == board->en_passant[!board->to_move] && ((board->to_move == white && to_row == from_row - 1) || (board->to_move == black && to_row == from_row + 1))) { // En passant
            board->board[to_row][to_col] = piece;
            board->board[from_row][from_col] = 0;
            board->board[from_row][to_col] = 0;
            board->en_passant[!board->to_move] = -1;
            board->half_moves = 0;
            board->full_moves += board->to_move;
            board->to_move = !board->to_move;
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

int main() {
    printf("Welcome to my Irregular Chess engine!\n");
    chess_board board;
    init_board(&board);
    print_board(&board);
    char move_string[10];
    int move_count = 0;
    while (true) {
        if (board.to_move == white) {
            printf("White's move: ");
        } else {
            printf("Black's move: ");
        }
        fflush(stdout);
        if (fgets(move_string, 10, stdin) == NULL) {
            break;
        } else if (move_string[0] == 'q') {
            break;
        }
        if (parse_move(&board, move_string)) {
            move_count++;
            print_board(&board);
            printf("Move %d: %s\n", move_count, move_string);
        } else {
            printf("Invalid move: %s\n", move_string);
        }
    }
    printf("Thanks for playing!\n");
    return 0;
}