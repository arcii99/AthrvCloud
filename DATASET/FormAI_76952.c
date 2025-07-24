//FormAI DATASET v1.0 Category: Chess engine ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8
#define MAX_DEPTH 3

// Define chess pieces as constants
#define EMPTY 0
#define PAWN 1
#define KNIGHT 2
#define BISHOP 3
#define ROOK 4
#define QUEEN 5
#define KING 6

// Define colors as constants
#define WHITE 0
#define BLACK 1

int board[BOARD_SIZE][BOARD_SIZE];

// Initialize the board
void initialize_board() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (i == 1 || i == 6) {
                board[i][j] = PAWN;
            } else if (i == 0 || i == 7) {
                if (j == 0 || j == 7) {
                    board[i][j] = ROOK;
                } else if (j == 1 || j == 6) {
                    board[i][j] = KNIGHT;
                } else if (j == 2 || j == 5) {
                    board[i][j] = BISHOP;
                } else if (j == 3) {
                    board[i][j] = QUEEN;
                } else if (j == 4) {
                    board[i][j] = KING;
                }
            } else {
                board[i][j] = EMPTY;
            }
        }
    }
}

// Get the value of a piece based on its type and position
int piece_value(int piece, int i, int j) {
    int value = 0;
    switch (piece) {
        case PAWN:
            value = 1;
            break;
        case KNIGHT:
            value = 3;
            break;
        case BISHOP:
            value = 3;
            break;
        case ROOK:
            value = 5;
            break;
        case QUEEN:
            value = 9;
            break;
        case KING:
            value = 100;
            break;
    }
    if (i == 1 || i == 6) {
        value += 1; // Add value for pawns on second rank
    }
    return value;
}

// Evaluate the board based on the value of the pieces
int evaluate_board(int color) {
    int i, j, value = 0;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != EMPTY) {
                if ((board[i][j] == PAWN && color == WHITE) || (board[i][j] != PAWN && i < BOARD_SIZE/2)) {
                    value += piece_value(board[i][j], i, j);
                } else {
                    value -= piece_value(board[i][j], i, j);
                }
            }
        }
    }
    return value;
}

// Check if a move is valid
int is_valid_move(int i1, int j1, int i2, int j2, int color) {
    if (i1 < 0 || i1 >= BOARD_SIZE || j1 < 0 || j1 >= BOARD_SIZE || i2 < 0 || i2 >= BOARD_SIZE || j2 < 0 || j2 >= BOARD_SIZE) {
        return 0;
    }
    if (board[i2][j2] != EMPTY && color == (board[i2][j2] < 7)) {
        return 0;
    }
    switch (board[i1][j1]) {
        case PAWN:
            if (color == WHITE) {
                if (i2 == i1-1 && j2 == j1 && board[i2][j2] == EMPTY) {
                    return 1;
                } else if (i2 == i1-1 && abs(j2-j1) == 1 && board[i2][j2] != EMPTY && color != (board[i2][j2] < 7)) {
                    return 1;
                } else if (i1 == 6 && i2 == 4 && j2 == j1 && board[5][j1] == EMPTY && board[i2][j2] == EMPTY) {
                    return 1;
                }
            } else {
                if (i2 == i1+1 && j2 == j1 && board[i2][j2] == EMPTY) {
                    return 1;
                } else if (i2 == i1+1 && abs(j2-j1) == 1 && board[i2][j2] != EMPTY && color != (board[i2][j2] < 7)) {
                    return 1;
                } else if (i1 == 1 && i2 == 3 && j2 == j1 && board[2][j1] == EMPTY && board[i2][j2] == EMPTY) {
                    return 1;
                }
            }
            break;
        case KNIGHT:
            if ((abs(i2-i1) == 2 && abs(j2-j1) == 1) || (abs(i2-i1) == 1 && abs(j2-j1) == 2)) {
                return 1;
            }
            break;
        case BISHOP:
            if (abs(i2-i1) == abs(j2-j1)) {
                int x, y;
                x = (i2 > i1) ? 1 : -1;
                y = (j2 > j1) ? 1 : -1;
                int it, jt;
                for (it = i1+x, jt = j1+y; it != i2; it += x, jt += y) {
                    if (board[it][jt] != EMPTY) {
                        return 0;
                    }
                }
                if (board[i2][j2] == EMPTY || color != (board[i2][j2] < 7)) {
                    return 1;
                }
            }
            break;
        case ROOK:
            if (i1 == i2 || j1 == j2) {
                int x, y;
                if (i1 == i2) {
                    x = 0;
                    y = (j2 > j1) ? 1 : -1;
                } else {
                    x = (i2 > i1) ? 1 : -1;
                    y = 0;
                }
                int it, jt;
                for (it = i1+x, jt = j1+y; it != i2 || jt != j2; it += x, jt += y) {
                    if (board[it][jt] != EMPTY) {
                        return 0;
                    }
                }
                if (board[i2][j2] == EMPTY || color != (board[i2][j2] < 7)) {
                    return 1;
                }
            }
            break;
        case QUEEN:
            if (abs(i2-i1) == abs(j2-j1)) {
                int x, y;
                x = (i2 > i1) ? 1 : -1;
                y = (j2 > j1) ? 1 : -1;
                int it, jt;
                for (it = i1+x, jt = j1+y; it != i2; it += x, jt += y) {
                    if (board[it][jt] != EMPTY) {
                        return 0;
                    }
                }
            } else if (i1 == i2 || j1 == j2) {
                int x, y;
                if (i1 == i2) {
                    x = 0;
                    y = (j2 > j1) ? 1 : -1;
                } else {
                    x = (i2 > i1) ? 1 : -1;
                    y = 0;
                }
                int it, jt;
                for (it = i1+x, jt = j1+y; it != i2 || jt != j2; it += x, jt += y) {
                    if (board[it][jt] != EMPTY) {
                        return 0;
                    }
                }
            } else {
                return 0;
            }
            if (board[i2][j2] == EMPTY || color != (board[i2][j2] < 7)) {
                return 1;
            }
            break;
        case KING:
            if (abs(i2-i1) <= 1 && abs(j2-j1) <= 1) {
                if (board[i2][j2] == EMPTY || color != (board[i2][j2] < 7)) {
                    return 1;
                }
            }
            if (i1 == 7-color*7 && j1 == 4 && i2 == 7-color*5 && j2 == 4 && board[7-color*6][4] == EMPTY && board[i2][j2] == EMPTY) {
                return 1; // Add castling
            }
            break;
    }
    return 0;
}

// Get a list of valid moves
int get_valid_moves(int color, int moves[][4]) {
    int i, j, k = 0;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != EMPTY && color == (board[i][j] < 7)) {
                int ii, jj;
                for (ii = 0; ii < BOARD_SIZE; ii++) {
                    for (jj = 0; jj < BOARD_SIZE; jj++) {
                        if (is_valid_move(i, j, ii, jj, color)) {
                            moves[k][0] = i;
                            moves[k][1] = j;
                            moves[k][2] = ii;
                            moves[k][3] = jj;
                            k++;
                        }
                    }
                }
            }
        }
    }
    return k;
}

// Make a move on the board
void make_move(int i1, int j1, int i2, int j2, int color) {
    board[i2][j2] = board[i1][j1];
    board[i1][j1] = EMPTY;
    if (board[i2][j2] == PAWN && (i2 == 0 || i2 == BOARD_SIZE-1)) {
        board[i2][j2] = QUEEN; // Promote pawn to queen
    }
    if (board[i2][j2] == KING && abs(j2-j1) == 2) {
        board[i2][(j1+j2)/2] = board[i2][(j1 > j2) ? 0 : BOARD_SIZE-1]; // Move rook for castling
        board[i2][(j1 > j2) ? 0 : BOARD_SIZE-1] = EMPTY;
    }
}

// Undo a move on the board
void undo_move(int i1, int j1, int i2, int j2, int color, int capture) {
    board[i1][j1] = board[i2][j2];
    board[i2][j2] = capture;
    if (board[i1][j1] == KING && abs(j2-j1) == 2) {
        board[i1][(j1+j2)/2] = board[i1][(j1 > j2) ? 0 : BOARD_SIZE-1];
        board[i1][(j1 > j2) ? 0 : BOARD_SIZE-1] = EMPTY;
    }
}

// Negamax function
int negamax(int color, int depth, int alpha, int beta) {
    if (depth == 0) {
        return evaluate_board(color);
    }
    int moves[BOARD_SIZE*BOARD_SIZE][4];
    int num_moves = get_valid_moves(color, moves);
    if (num_moves == 0) {
        return evaluate_board(color) * ((color == WHITE) ? 1 : -1) * ((depth % 2 == 0) ? 1 : -1);
    }
    int i, j, value, best_value = -1000000;
    for (i = 0; i < num_moves; i++) {
        int i1 = moves[i][0], j1 = moves[i][1], i2 = moves[i][2], j2 = moves[i][3];
        int capture = board[i2][j2];
        make_move(i1, j1, i2, j2, color);
        value = -negamax(1-color, depth-1, -beta, -alpha);
        undo_move(i1, j1, i2, j2, color, capture);
        if (value > best_value) {
            best_value = value;
        }
        if (value > alpha) {
            alpha = value;
        }
        if (alpha >= beta) {
            return best_value;
        }
    }
    return best_value;
}

// Get the best move for a given color
void get_best_move(int color, int move[]) {
    int moves[BOARD_SIZE*BOARD_SIZE][4];
    int num_moves = get_valid_moves(color, moves);
    if (num_moves == 0) {
        move[0] = move[1] = move[2] = move[3] = -1;
        return;
    }
    int i, j, value, best_value = -1000000;
    for (i = 0; i < num_moves; i++) {
        int i1 = moves[i][0], j1 = moves[i][1], i2 = moves[i][2], j2 = moves[i][3];
        int capture = board[i2][j2];
        make_move(i1, j1, i2, j2, color);
        value = -negamax(1-color, MAX_DEPTH-1, -1000000, 1000000);
        undo_move(i1, j1, i2, j2, color, capture);
        if (value > best_value) {
            best_value = value;
            move[0] = i1;
            move[1] = j1;
            move[2] = i2;
            move[3] = j2;
        }
    }
}

int main() {
    srand(time(NULL));
    initialize_board();
    int move[4];
    while (1) {
        int color = (evaluate_board(WHITE) > evaluate_board(BLACK)) ? WHITE : BLACK;
        if (color == WHITE) {
            get_best_move(color, move);
        } else {
            printf("Enter move for black (i1 j1 i2 j2): ");
            scanf("%d %d %d %d", &move[0], &move[1], &move[2], &move[3]);
        }
        make_move(move[0], move[1], move[2], move[3], color);
        int i, j;
        for (i = 0; i < BOARD_SIZE; i++) {
            for (j = 0; j < BOARD_SIZE; j++) {
                printf("%c ", (board[i][j] == EMPTY) ? '_' : "PNBRQKpnbrqk"[board[i][j]]);
            }
            printf("\n");
        }
        if (evaluate_board(WHITE) > 1000) { // Check for checkmate
            printf("White wins!\n");
            break;
        }
        if (evaluate_board(BLACK) < -1000) {
            printf("Black wins!\n");
            break;
        }
    }
    return 0;
}