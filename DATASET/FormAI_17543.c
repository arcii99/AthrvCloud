//FormAI DATASET v1.0 Category: Checkers Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

#define BLACK 'O'
#define WHITE 'X'

#define BLACK_KING 'K'
#define WHITE_KING 'Q'

#define ROWS_TO_CHECK {1, -1}
#define COLS_TO_CHECK {1, -1}

typedef enum {false, true} bool;

typedef struct {
    char color;
    bool is_king;
} Piece;

void init_board(Piece board[][BOARD_SIZE], int board_size) {
    int i, j;
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            board[i][j].color = ' ';
            board[i][j].is_king = false;
        }
    }

    // Initialize black pieces
    for (i = 0; i < 3; i++) {
        for (j = 0; j < board_size; j++) {
            if ((i+j)%2 == 0) {
                board[i][j].color = BLACK;
            }
        }
    }

    // Initialize white pieces
    for (i = 5; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            if ((i+j)%2 == 0) {
                board[i][j].color = WHITE;
            }
        }
    }
}

void print_board(Piece board[][BOARD_SIZE], int board_size) {
    int i, j;
    for (i = 0; i < board_size; i++) {
        printf("%d", board_size - i);
        for (j = 0; j < board_size; j++) {
            printf("|%c", board[i][j].color);
        }
        printf("|\n");
    }

    printf(" ");
    for (i = 0; i < board_size; i++) {
        printf(" %c", 'A' + i);
    }
    printf("\n");
}

bool is_valid_move(int row, int col, int dest_row, int dest_col, Piece board[][BOARD_SIZE]) {
    if (dest_row < 0 || dest_col < 0 || dest_row >= BOARD_SIZE || dest_col >= BOARD_SIZE) {
        return false;
    }

    if (board[dest_row][dest_col].color != ' ') {
        return false;
    }

    Piece curr_piece = board[row][col];

    if (curr_piece.color == BLACK) {
        if (dest_row > row) {
            return false;
        }
        if (!curr_piece.is_king && (abs(dest_row - row) > 1 || abs(dest_col - col) > 1)) {
            return false;
        }
    } else if (curr_piece.color == WHITE) {
        if (dest_row < row) {
            return false;
        }
        if (!curr_piece.is_king && (abs(dest_row - row) > 1 || abs(dest_col - col) > 1)) {
            return false;
        }
    }

    return true;
}

bool is_valid_capture(int row, int col, int dest_row, int dest_col, Piece board[][BOARD_SIZE]) {
    if (dest_row < 0 || dest_col < 0 || dest_row >= BOARD_SIZE || dest_col >= BOARD_SIZE) {
        return false;
    }

    if (board[dest_row][dest_col].color != ' ') {
        return false;
    }

    Piece curr_piece = board[row][col];
    Piece captured_piece = board[(row + dest_row)/2][(col + dest_col)/2];

    if (curr_piece.color == BLACK) {
        if (dest_row > row) {
            return false;
        }
        if (!curr_piece.is_king && (abs(dest_row - row) > 2 || abs(dest_col - col) > 2)) {
            return false;
        }
        if (captured_piece.color != WHITE && captured_piece.color != WHITE_KING) {
            return false;
        }
    } else if (curr_piece.color == WHITE) {
        if (dest_row < row) {
            return false;
        }
        if (!curr_piece.is_king && (abs(dest_row - row) > 2 || abs(dest_col - col) > 2)) {
            return false;
        }
        if (captured_piece.color != BLACK && captured_piece.color != BLACK_KING) {
            return false;
        }
    }

    return true;
}

void make_move(int row, int col, int dest_row, int dest_col, Piece board[][BOARD_SIZE]) {
    Piece curr_piece = board[row][col];
    if (curr_piece.color == BLACK && dest_row == 0) {
        curr_piece.is_king = true;
    } else if (curr_piece.color == WHITE && dest_row == BOARD_SIZE - 1) {
        curr_piece.is_king = true;
    }

    board[row][col].color = ' ';
    board[dest_row][dest_col] = curr_piece;
}

void make_capture(int row, int col, int dest_row, int dest_col, Piece board[][BOARD_SIZE]) {
    make_move(row, col, dest_row, dest_col, board);
    board[(row + dest_row)/2][(col + dest_col)/2].color = ' ';
}

void get_possible_moves(int row, int col, int *possible_moves, Piece board[][BOARD_SIZE]) {
    int i, j;
    int num_moves = 0;
    Piece curr_piece = board[row][col];

    int rows_to_check[] = ROWS_TO_CHECK;
    int cols_to_check[] = COLS_TO_CHECK;
    if (curr_piece.is_king) {
        rows_to_check[0] = 1;
        rows_to_check[1] = -1;
    }

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            int dest_row = row + rows_to_check[i];
            int dest_col = col + cols_to_check[j];
            if (is_valid_move(row, col, dest_row, dest_col, board)) {
                possible_moves[num_moves] = (dest_row * BOARD_SIZE) + dest_col;
                num_moves++;
            } else if (is_valid_capture(row, col, dest_row + rows_to_check[i], dest_col + cols_to_check[j], board)) {
                possible_moves[num_moves] = ((dest_row + rows_to_check[i]) * BOARD_SIZE) + (dest_col + cols_to_check[j]);
                num_moves++;
            }
        }
    }
}

void get_all_possible_moves(char color, int *all_possible_moves, Piece board[][BOARD_SIZE]) {
    int i, j, k, l;
    int num_moves = 0;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].color == color || board[i][j].color == (color == BLACK ? BLACK_KING : WHITE_KING)) {
                int possible_moves[4] = {-1, -1, -1, -1};
                get_possible_moves(i, j, possible_moves, board);
                for (k = 0; k < 4; k++) {
                    if (possible_moves[k] != -1) {
                        all_possible_moves[num_moves] = ((i * BOARD_SIZE) + j) * 100 + possible_moves[k];
                        num_moves++;
                    }
                }
            }
        }
    }
}

bool has_valid_move(char color, Piece board[][BOARD_SIZE]) {
    int all_possible_moves[1000] = {-1};
    get_all_possible_moves(color, all_possible_moves, board);

    int i;
    for (i = 0; i < 1000; i++) {
        if (all_possible_moves[i] == -1) {
            break;
        }

        int src_row = all_possible_moves[i] / (BOARD_SIZE * 100);
        int src_col = (all_possible_moves[i] / 100) % BOARD_SIZE;
        int dest_row = all_possible_moves[i] % BOARD_SIZE;
        int dest_col = (all_possible_moves[i] % 100) % BOARD_SIZE;

        if (is_valid_move(src_row, src_col, dest_row, dest_col, board) || is_valid_capture(src_row, src_col, dest_row, dest_col, board)) {
            return true;
        }
    }

    return false;
}

bool is_game_over(Piece board[][BOARD_SIZE]) {
    return (!has_valid_move(BLACK, board) || !has_valid_move(WHITE, board));
}

int main() {
    Piece board[BOARD_SIZE][BOARD_SIZE];
    init_board(board, BOARD_SIZE);

    char curr_player = BLACK;

    while (!is_game_over(board)) {
        print_board(board, BOARD_SIZE);

        int all_possible_moves[1000] = {-1};
        get_all_possible_moves(curr_player, all_possible_moves, board);

        if (all_possible_moves[0] == -1) {
            printf("%c has no valid moves. Skipping turn.\n", curr_player);
            curr_player = (curr_player == BLACK) ? WHITE : BLACK;
            continue;
        }

        int i;
        for (i = 0; i < 1000; i++) {
            if (all_possible_moves[i] == -1) {
                break;
            }

            int src_row = all_possible_moves[i] / (BOARD_SIZE * 100);
            int src_col = (all_possible_moves[i] / 100) % BOARD_SIZE;
            int dest_row = all_possible_moves[i] % BOARD_SIZE;
            int dest_col = (all_possible_moves[i] % 100) % BOARD_SIZE;

            if (is_valid_move(src_row, src_col, dest_row, dest_col, board) || is_valid_capture(src_row, src_col, dest_row, dest_col, board)) {
                printf("%c's turn. Enter move: %c%d %c%d\n", curr_player, 'A' + src_col, BOARD_SIZE - src_row, 'A' + dest_col, BOARD_SIZE - dest_row);
                char input[6];
                fgets(input, sizeof(input), stdin);
                int input_col = input[0] - 'A';
                int input_src_row = BOARD_SIZE - (input[1] - '0');
                int input_dest_row = BOARD_SIZE - (input[4] - '0');
                int input_dest_col = input[3] - 'A';

                if (input_col == src_col && input_src_row == src_row && input_dest_row == dest_row && input_dest_col == dest_col && (is_valid_move(src_row, src_col, dest_row, dest_col, board) || is_valid_capture(src_row, src_col, dest_row, dest_col, board))) {
                    if (is_valid_capture(src_row, src_col, dest_row, dest_col, board)) {
                        make_capture(src_row, src_col, dest_row, dest_col, board);
                    } else {
                        make_move(src_row, src_col, dest_row, dest_col, board);
                    }
                    curr_player = (curr_player == BLACK) ? WHITE : BLACK;
                    break;
                }
            }
        }
    }

    print_board(board, BOARD_SIZE);

    int black_pieces = 0;
    int white_pieces = 0;

    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].color == BLACK || board[i][j].color == BLACK_KING) {
                black_pieces++;
            } else if (board[i][j].color == WHITE || board[i][j].color == WHITE_KING) {
                white_pieces++;
            }
        }
    }

    printf("Game over! Final score: O %d - %d X\n", black_pieces, white_pieces);

    return 0;
}