//FormAI DATASET v1.0 Category: Chess AI ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define BOARD_SIZE 8

#define PAWN 'P'
#define KNIGHT 'N'
#define BISHOP 'B'
#define ROOK 'R'
#define QUEEN 'Q'
#define KING 'K'

#define WHITE 'w'
#define BLACK 'b'

#define MAX_DEPTH 3

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

typedef struct {
    char piece;
    char color;
} square;

square board[BOARD_SIZE][BOARD_SIZE];

int evaluate_board(square board[BOARD_SIZE][BOARD_SIZE]) {
    int value = 0;
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            square s = board[r][c];
            switch (s.piece) {
                case PAWN:
                    value += (s.color == WHITE ? 1 : -1);
                    break;
                case KNIGHT:
                    value += (s.color == WHITE ? 3 : -3);
                    break;
                case BISHOP:
                    value += (s.color == WHITE ? 3 : -3);
                    break;
                case ROOK:
                    value += (s.color == WHITE ? 5 : -5);
                    break;
                case QUEEN:
                    value += (s.color == WHITE ? 9 : -9);
                    break;
                case KING:
                    value += (s.color == WHITE ? 100 : -100);
                    break;
            }
        }
    }
    return value;
}

int alpha_beta(square board[BOARD_SIZE][BOARD_SIZE], int depth, int alpha, int beta, char player) {
    if (depth == 0) {
        return evaluate_board(board);
    }

    int max_value = INT_MIN;
    int min_value = INT_MAX;

    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            square s = board[r][c];
            if (s.piece != 0 && s.color == player) {
                for (int i = r-1; i <= r+1; i++) {
                    for (int j = c-1; j <= c+1; j++) {
                        if (i >= 0 && i < BOARD_SIZE && j >= 0 && j < BOARD_SIZE) {
                            square temp = board[i][j];
                            if (temp.color != player) {  // make sure move is valid
                                square temp2 = board[r][c];  // move piece
                                board[i][j] = board[r][c];
                                board[r][c].piece = 0;
                                int value = -alpha_beta(board, depth-1, -beta, -alpha, (player == WHITE ? BLACK : WHITE));
                                board[r][c] = temp2;  // undo move
                                board[i][j] = temp;
                                if (value > max_value) {
                                    max_value = value;
                                    alpha = max(alpha, value);
                                }
                                if (value < min_value) {
                                    min_value = value;
                                    beta = min(beta, value);
                                }
                                if (alpha >= beta) {
                                    return player == WHITE ? max_value : min_value;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return player == WHITE ? max_value : min_value;
}

void make_move(square board[BOARD_SIZE][BOARD_SIZE], int depth, char player) {
    int max_value = INT_MIN;
    int move_row, move_col, move_to_row, move_to_col;
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            square s = board[r][c];
            if (s.piece != 0 && s.color == player) {
                for (int i = r-1; i <= r+1; i++) {
                    for (int j = c-1; j <= c+1; j++) {
                        if (i >= 0 && i < BOARD_SIZE && j >= 0 && j < BOARD_SIZE) {
                            square temp = board[i][j];
                            if (temp.color != player) {  // make sure move is valid
                                square temp2 = board[r][c];  // move piece
                                board[i][j] = board[r][c];
                                board[r][c].piece = 0;
                                int value = -alpha_beta(board, depth-1, INT_MIN, INT_MAX, (player == WHITE ? BLACK : WHITE));
                                board[r][c] = temp2;  // undo move
                                board[i][j] = temp;
                                if (value > max_value) {
                                    max_value = value;
                                    move_row = r;
                                    move_col = c;
                                    move_to_row = i;
                                    move_to_col = j;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("The AI chooses to move from (%d, %d) to (%d, %d)\n", move_row, move_col, move_to_row, move_to_col);
    square temp = board[move_to_row][move_to_col];
    board[move_to_row][move_to_col] = board[move_row][move_col];
    board[move_row][move_col].piece = 0;
}

int main()
{
    // initialize board
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[1][i] = (square){PAWN, WHITE};
        board[6][i] = (square){PAWN, BLACK};
    }
    board[0][0] = (square){ROOK, WHITE};
    board[0][7] = (square){ROOK, WHITE};
    board[7][0] = (square){ROOK, BLACK};
    board[7][7] = (square){ROOK, BLACK};
    board[0][1] = (square){KNIGHT, WHITE};
    board[0][6] = (square){KNIGHT, WHITE};
    board[7][1] = (square){KNIGHT, BLACK};
    board[7][6] = (square){KNIGHT, BLACK};
    board[0][2] = (square){BISHOP, WHITE};
    board[0][5] = (square){BISHOP, WHITE};
    board[7][2] = (square){BISHOP, BLACK};
    board[7][5] = (square){BISHOP, BLACK};
    board[0][3] = (square){QUEEN, WHITE};
    board[7][3] = (square){QUEEN, BLACK};
    board[0][4] = (square){KING, WHITE};
    board[7][4] = (square){KING, BLACK};

    // print starting position
    printf("Starting position:\n");
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            printf("%c%c ", board[r][c].color, board[r][c].piece);
        }
        printf("\n");
    }
    printf("\n");

    // play game
    char current_player = WHITE;
    while (1) {
        if (current_player == WHITE) {
            make_move(board, MAX_DEPTH, current_player);
        }
        else {
            // player's move
            // implementation not provided
        }

        // print board state
        printf("Board state:\n");
        for (int r = 0; r < BOARD_SIZE; r++) {
            for (int c = 0; c < BOARD_SIZE; c++) {
                printf("%c%c ", board[r][c].color, board[r][c].piece);
            }
            printf("\n");
        }
        printf("\n");

        // check for win condition
        // implementation not provided

        // switch players
        current_player = (current_player == WHITE ? BLACK : WHITE);
    }

    return 0;
}