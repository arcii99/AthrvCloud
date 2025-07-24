//FormAI DATASET v1.0 Category: Chess engine ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// Chess piece constants
#define EMPTY 0
#define PAWN 1
#define KNIGHT 2
#define BISHOP 3
#define ROOK 4
#define QUEEN 5
#define KING 6

// Movement constants
#define UP 1
#define DOWN -1
#define LEFT -1
#define RIGHT 1

// Player constants
#define NO_PLAYER 0
#define PLAYER_WHITE 1
#define PLAYER_BLACK 2

// Function declarations
void initialize_board(int board[][BOARD_SIZE]);
void print_board(int board[][BOARD_SIZE]);
int get_piece(int board[][BOARD_SIZE], int row, int col);
void set_piece(int board[][BOARD_SIZE], int row, int col, int piece, int player);
int get_player(int piece);
void move_piece(int board[][BOARD_SIZE], int from_row, int from_col, int to_row, int to_col);

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);

    // Place players' pieces
    set_piece(board, 0, 0, ROOK, PLAYER_WHITE);
    set_piece(board, 0, 1, KNIGHT, PLAYER_WHITE);
    set_piece(board, 0, 2, BISHOP, PLAYER_WHITE);
    set_piece(board, 0, 3, QUEEN, PLAYER_WHITE);
    set_piece(board, 0, 4, KING, PLAYER_WHITE);
    set_piece(board, 0, 5, BISHOP, PLAYER_WHITE);
    set_piece(board, 0, 6, KNIGHT, PLAYER_WHITE);
    set_piece(board, 0, 7, ROOK, PLAYER_WHITE);
    set_piece(board, 1, 0, PAWN, PLAYER_WHITE);
    set_piece(board, 1, 1, PAWN, PLAYER_WHITE);
    set_piece(board, 1, 2, PAWN, PLAYER_WHITE);
    set_piece(board, 1, 3, PAWN, PLAYER_WHITE);
    set_piece(board, 1, 4, PAWN, PLAYER_WHITE);
    set_piece(board, 1, 5, PAWN, PLAYER_WHITE);
    set_piece(board, 1, 6, PAWN, PLAYER_WHITE);
    set_piece(board, 1, 7, PAWN, PLAYER_WHITE);

    set_piece(board, 7, 0, ROOK, PLAYER_BLACK);
    set_piece(board, 7, 1, KNIGHT, PLAYER_BLACK);
    set_piece(board, 7, 2, BISHOP, PLAYER_BLACK);
    set_piece(board, 7, 3, QUEEN, PLAYER_BLACK);
    set_piece(board, 7, 4, KING, PLAYER_BLACK);
    set_piece(board, 7, 5, BISHOP, PLAYER_BLACK);
    set_piece(board, 7, 6, KNIGHT, PLAYER_BLACK);
    set_piece(board, 7, 7, ROOK, PLAYER_BLACK);
    set_piece(board, 6, 0, PAWN, PLAYER_BLACK);
    set_piece(board, 6, 1, PAWN, PLAYER_BLACK);
    set_piece(board, 6, 2, PAWN, PLAYER_BLACK);
    set_piece(board, 6, 3, PAWN, PLAYER_BLACK);
    set_piece(board, 6, 4, PAWN, PLAYER_BLACK);
    set_piece(board, 6, 5, PAWN, PLAYER_BLACK);
    set_piece(board, 6, 6, PAWN, PLAYER_BLACK);
    set_piece(board, 6, 7, PAWN, PLAYER_BLACK);

    // Print out the board before any moves have been made
    printf("Starting position:\n");
    print_board(board);

    // Move a pawn
    move_piece(board, 1, 4, 2, 4);

    // Print out the board after one move
    printf("After moving a pawn:\n");
    print_board(board);
    
    return 0;
}

void initialize_board(int board[][BOARD_SIZE]) {
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void print_board(int board[][BOARD_SIZE]) {
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", BOARD_SIZE-i);
        for(j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == EMPTY) {
                printf(". ");
            } else {
                switch(board[i][j]) {
                    case PAWN:
                        printf("P ");
                        break;
                    case KNIGHT:
                        printf("N ");
                        break;
                    case BISHOP:
                        printf("B ");
                        break;
                    case ROOK:
                        printf("R ");
                        break;
                    case QUEEN:
                        printf("Q ");
                        break;
                    case KING:
                        printf("K ");
                        break;
                    default:
                        printf("ERROR ");
                        break;
                }
            }
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}

int get_piece(int board[][BOARD_SIZE], int row, int col) {
    if(row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        return -1;
    }
    return board[row][col];
}

void set_piece(int board[][BOARD_SIZE], int row, int col, int piece, int player) {
    board[row][col] = piece + (player - 1) * 6;
}

int get_player(int piece) {
    if(piece == EMPTY) {
        return NO_PLAYER;
    } else {
        return (piece - 1) / 6 + 1;
    }
}

void move_piece(int board[][BOARD_SIZE], int from_row, int from_col, int to_row, int to_col) {
    int piece = get_piece(board, from_row, from_col);
    int player = get_player(piece);
    if(piece == EMPTY || player == NO_PLAYER) {
        printf("Invalid move. There is no piece in (%d,%d).\n", from_row, from_col);
    } else {
        int delta_row = to_row - from_row;
        int delta_col = to_col - from_col;
        int target_piece = get_piece(board, to_row, to_col);
        if(target_piece != EMPTY && get_player(target_piece) == player) {
            printf("Invalid move. A piece already occupies (%d,%d).\n", to_row, to_col);
        } else {
            int valid_move = 0;
            switch(piece) {
                case PAWN:
                    if(delta_col == 0) {
                        if(player == PLAYER_WHITE) {
                            if(delta_row == UP || (from_row == 1 && delta_row == UP+UP)) {
                                valid_move = 1;
                            }
                        } else { // player == PLAYER_BLACK
                            if(delta_row == DOWN || (from_row == BOARD_SIZE-2 && delta_row == DOWN+DOWN)) {
                                valid_move = 1;
                            }
                        }
                    } else if(abs(delta_col) == 1 && abs(delta_row) == 1) {
                        if(target_piece == EMPTY || get_player(target_piece) == player) {
                            printf("Invalid move. A pawn can only move diagonally to take an opponent's piece.\n");
                        } else {
                            valid_move = 1;
                        }
                    } else {
                        printf("Invalid move. A pawn cannot move %d squares vertically or %d squares horizontally.\n", abs(delta_row), abs(delta_col));
                    }
                    break;
                case KNIGHT:
                    if((abs(delta_row) == 2 && abs(delta_col) == 1) || (abs(delta_row) == 1 && abs(delta_col) == 2)) {
                        valid_move = 1;
                    } else {
                        printf("Invalid move. A knight moves in an L-shape, two squares vertically and one square horizontally, or two squares horizontally and one square vertically.\n");
                    }
                    break;
                case BISHOP:
                    if(abs(delta_row) == abs(delta_col)) {
                        int step_row = delta_row > 0 ? UP : DOWN;
                        int step_col = delta_col > 0 ? RIGHT : LEFT;
                        int row = from_row + step_row;
                        int col = from_col + step_col;
                        while(row != to_row && col != to_col) {
                            if(get_piece(board, row, col) != EMPTY) {
                                printf("Invalid move. A bishop cannot jump over other pieces.\n");
                                break;
                            }
                            row += step_row;
                            col += step_col;
                        }
                        valid_move = 1;
                    } else {
                        printf("Invalid move. A bishop moves diagonally along unobstructed lines.\n");
                    }
                    break;
                case ROOK:
                    if(delta_row == 0 || delta_col == 0) {
                        int step_row = delta_row == 0 ? 0 : (delta_row > 0 ? UP : DOWN);
                        int step_col = delta_col == 0 ? 0 : (delta_col > 0 ? RIGHT : LEFT);
                        int row = from_row + step_row;
                        int col = from_col + step_col;
                        while(row != to_row || col != to_col) {
                            if(get_piece(board, row, col) != EMPTY) {
                                printf("Invalid move. A rook cannot jump over other pieces.\n");
                                break;
                            }
                            row += step_row;
                            col += step_col;
                        }
                        valid_move = 1;
                    } else {
                        printf("Invalid move. A rook moves diagonally along unobstructed lines.\n");
                    }
                    break;
                case QUEEN:
                    if(abs(delta_row) == abs(delta_col)) { // bishop-like
                        int step_row = delta_row > 0 ? UP : DOWN;
                        int step_col = delta_col > 0 ? RIGHT : LEFT;
                        int row = from_row + step_row;
                        int col = from_col + step_col;
                        while(row != to_row && col != to_col) {
                            if(get_piece(board, row, col) != EMPTY) {
                                printf("Invalid move. A queen cannot jump over other pieces.\n");
                                break;
                            }
                            row += step_row;
                            col += step_col;
                        }
                        valid_move = 1;
                    } else if(delta_row == 0 || delta_col == 0) { // rook-like
                        int step_row = delta_row == 0 ? 0 : (delta_row > 0 ? UP : DOWN);
                        int step_col = delta_col == 0 ? 0 : (delta_col > 0 ? RIGHT : LEFT);
                        int row = from_row + step_row;
                        int col = from_col + step_col;
                        while(row != to_row || col != to_col) {
                            if(get_piece(board, row, col) != EMPTY) {
                                printf("Invalid move. A queen cannot jump over other pieces.\n");
                                break;
                            }
                            row += step_row;
                            col += step_col;
                        }
                        valid_move = 1;
                    } else {
                        printf("Invalid move. A queen moves diagonally or orthogonally along unobstructed lines.\n");
                    }
                    break;
                case KING:
                    if(abs(delta_row) <= 1 && abs(delta_col) <= 1) {
                        valid_move = 1;
                    } else {
                        printf("Invalid move. A king can only move one square in any direction.\n");
                    }
                    break;
                default:
                    printf("Invalid move. Unknown piece type.\n");
                    break;
            }
            if(valid_move) {
                board[from_row][from_col] = EMPTY;
                board[to_row][to_col] = piece;
            }
        }
    }
}