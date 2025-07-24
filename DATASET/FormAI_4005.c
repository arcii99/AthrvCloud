//FormAI DATASET v1.0 Category: Chess engine ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef enum {Pawn, Knight, Bishop, Rook, Queen, King} piece_type;
typedef enum {Pawn_W, Knight_W, Bishop_W, Rook_W, Queen_W, King_W, Pawn_B, Knight_B, Bishop_B, Rook_B, Queen_B, King_B, Empty} piece;

typedef struct {
    piece position[BOARD_SIZE][BOARD_SIZE];
} board;

typedef struct {
    piece_type type;
    int x_pos;
    int y_pos;
    int team; // white = 0, black = 1
} piece_attributes;

void initialize_board(board gameboard);
void print_board(board gameboard);
void move_piece(board gameboard, int x_start, int y_start, int x_end, int y_end);

int main() {
    board gameboard;
    initialize_board(gameboard);
    print_board(gameboard);
    move_piece(gameboard, 1, 0, 3, 0);
    print_board(gameboard);
    return 0;
}

void initialize_board(board gameboard) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i == 1) {
                gameboard.position[i][j] == Pawn_W;
            }
            else if (i == BOARD_SIZE - 2) {
                gameboard.position[i][j] == Pawn_B;
            }
            else if (i == 0) {
                if (j == 0 || j == BOARD_SIZE - 1) {
                    gameboard.position[i][j] == Rook_W;
                }
                else if (j == 1 || j == BOARD_SIZE - 2) {
                    gameboard.position[i][j] == Knight_W;
                }
                else if (j == 2 || j == BOARD_SIZE - 3) {
                    gameboard.position[i][j] == Bishop_W;
                }
                else if (j == 3) {
                    gameboard.position[i][j] == Queen_W;
                }
                else {
                    gameboard.position[i][j] == King_W;
                }
            }
            else if (i == BOARD_SIZE - 1) {
                if (j == 0 || j == BOARD_SIZE - 1) {
                    gameboard.position[i][j] == Rook_B;
                }
                else if (j == 1 || j == BOARD_SIZE - 2) {
                    gameboard.position[i][j] == Knight_B;
                }
                else if (j == 2 || j == BOARD_SIZE - 3) {
                    gameboard.position[i][j] == Bishop_B;
                }
                else if (j == 3) {
                    gameboard.position[i][j] == Queen_B;
                }
                else {
                    gameboard.position[i][j] == King_B;
                }
            }
            else {
                gameboard.position[i][j] == Empty;
            }
        }
    }
}

void print_board(board gameboard) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", gameboard.position[i][j]);
        }
        printf("\n");
    }
}

void move_piece(board gameboard, int x_start, int y_start, int x_end, int y_end) {
    gameboard.position[x_end][y_end] = gameboard.position[x_start][y_start];
    gameboard.position[x_start][y_start] = Empty;
}