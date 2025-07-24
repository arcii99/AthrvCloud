//FormAI DATASET v1.0 Category: Chess engine ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
} Move;

int board[8][8] = {
        {-5, -3, -4, -10, -50, -4, -3, -5},
        {-1, -1, -1,  -1,  -1, -1, -1, -1},
        { 0,  0,  0,   0,   0,  0,  0,  0},
        { 0,  0,  0,   1,   1,  0,  0,  0},
        { 0,  0,  0,   0,   0,  0,  0,  0},
        { 0,  0,  0,   0,   0,  0,  0,  0},
        { 1,  1,  1,   1,   1,  1,  1,  1},
        { 5,  3,  4,  10,  50,  4,  3,  5}
};

Move moves[100];
int num_moves = 0;

// Find all legal moves for the current player
void find_legal_moves(int player) {
    num_moves = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] * player > 0) {
                // Piece belongs to the current player
                switch (abs(board[i][j])) {
                    case 1: // Pawn
                        if (player == -1) {
                            if (board[i+1][j] == 0) {
                                add_move(i, j, i+1, j);
                            }
                            if (j > 0 && board[i+1][j-1] > 0) {
                                add_move(i, j, i+1, j-1);
                            }
                            if (j < 7 && board[i+1][j+1] > 0) {
                                add_move(i, j, i+1, j+1);
                            }
                        } else {
                            if (board[i-1][j] == 0) {
                                add_move(i, j, i-1, j);
                            }
                            if (j > 0 && board[i-1][j-1] < 0) {
                                add_move(i, j, i-1, j-1);
                            }
                            if (j < 7 && board[i-1][j+1] < 0) {
                                add_move(i, j, i-1, j+1);
                            }
                        }
                        break;
                    case 3: // Knight
                        if (i > 1 && j > 0 && board[i-2][j-1] * player <= 0) {
                            add_move(i, j, i-2, j-1);
                        }
                        if (i > 0 && j > 1 && board[i-1][j-2] * player <= 0) {
                            add_move(i, j, i-1, j-2);
                        }
                        if (i < 6 && j > 0 && board[i+2][j-1] * player <= 0) {
                            add_move(i, j, i+2, j-1);
                        }
                        if (i < 7 && j > 1 && board[i+1][j-2] * player <= 0) {
                            add_move(i, j, i+1, j-2);
                        }
                        if (i < 7 && j < 6 && board[i+1][j+2] * player <= 0) {
                            add_move(i, j, i+1, j+2);
                        }
                        if (i < 6 && j < 7 && board[i+2][j+1] * player <= 0) {
                            add_move(i, j, i+2, j+1);
                        }
                        if (i > 0 && j < 6 && board[i-1][j+2] * player <= 0) {
                            add_move(i, j, i-1, j+2);
                        }
                        if (i > 1 && j < 7 && board[i-2][j+1] * player <= 0) {
                            add_move(i, j, i-2, j+1);
                        }
                        break;
                    case 4: // Bishop
                        for (int k = 1; k < 8; k++) {
                            if (i-k < 0 || j-k < 0 || board[i-k][j-k] * player > 0) {
                                break;
                            } else if (board[i-k][j-k] * player < 0) {
                                add_move(i, j, i-k, j-k);
                                break;
                            } else {
                                add_move(i, j, i-k, j-k);
                            }
                        }
                        for (int k = 1; k < 8; k++) {
                            if (i-k < 0 || j+k > 7 || board[i-k][j+k] * player > 0) {
                                break;
                            } else if (board[i-k][j+k] * player < 0) {
                                add_move(i, j, i-k, j+k);
                                break;
                            } else {
                                add_move(i, j, i-k, j+k);
                            }
                        }
                        for (int k = 1; k < 8; k++) {
                            if (i+k > 7 || j-k < 0 || board[i+k][j-k] * player > 0) {
                                break;
                            } else if (board[i+k][j-k] * player < 0) {
                                add_move(i, j, i+k, j-k);
                                break;
                            } else {
                                add_move(i, j, i+k, j-k);
                            }
                        }
                        for (int k = 1; k < 8; k++) {
                            if (i+k > 7 || j+k > 7 || board[i+k][j+k] * player > 0) {
                                break;
                            } else if (board[i+k][j+k] * player < 0) {
                                add_move(i, j, i+k, j+k);
                                break;
                            } else {
                                add_move(i, j, i+k, j+k);
                            }
                        }
                        break;
                    case 5: // Rook
                        for (int k = 1; k < 8; k++) {
                            if (i-k < 0 || board[i-k][j] * player > 0) {
                                break;
                            } else if (board[i-k][j] * player < 0) {
                                add_move(i, j, i-k, j);
                                break;
                            } else {
                                add_move(i, j, i-k, j);
                            }
                        }
                        for (int k = 1; k < 8; k++) {
                            if (i+k > 7 || board[i+k][j] * player > 0) {
                                break;
                            } else if (board[i+k][j] * player < 0) {
                                add_move(i, j, i+k, j);
                                break;
                            } else {
                                add_move(i, j, i+k, j);
                            }
                        }
                        for (int k = 1; k < 8; k++) {
                            if (j-k < 0 || board[i][j-k] * player > 0) {
                                break;
                            } else if (board[i][j-k] * player < 0) {
                                add_move(i, j, i, j-k);
                                break;
                            } else {
                                add_move(i, j, i, j-k);
                            }
                        }
                        for (int k = 1; k < 8; k++) {
                            if (j+k > 7 || board[i][j+k] * player > 0) {
                                break;
                            } else if (board[i][j+k] * player < 0) {
                                add_move(i, j, i, j+k);
                                break;
                            } else {
                                add_move(i, j, i, j+k);
                            }
                        }
                        break;
                    case 10: // King
                        if (i > 0 && board[i-1][j] * player <= 0) {
                            add_move(i, j, i-1, j);
                        }
                        if (i < 7 && board[i+1][j] * player <= 0) {
                            add_move(i, j, i+1, j);
                        }
                        if (j > 0 && board[i][j-1] * player <= 0) {
                            add_move(i, j, i, j-1);
                        }
                        if (j < 7 && board[i][j+1] * player <= 0) {
                            add_move(i, j, i, j+1);
                        }
                        if (i > 0 && j > 0 && board[i-1][j-1] * player <= 0) {
                            add_move(i, j, i-1, j-1);
                        }
                        if (i > 0 && j < 7 && board[i-1][j+1] * player <= 0) {
                            add_move(i, j, i-1, j+1);
                        }
                        if (i < 7 && j > 0 && board[i+1][j-1] * player <= 0) {
                            add_move(i, j, i+1, j-1);
                        }
                        if (i < 7 && j < 7 && board[i+1][j+1] * player <= 0) {
                            add_move(i, j, i+1, j+1);
                        }
                        break;
                    case 50: // Queen
                        for (int k = 1; k < 8; k++) {
                            if (i-k < 0 || board[i-k][j] * player > 0) {
                                break;
                            } else if (board[i-k][j] * player < 0) {
                                add_move(i, j, i-k, j);
                                break;
                            } else {
                                add_move(i, j, i-k, j);
                            }
                        }
                        for (int k = 1; k < 8; k++) {
                            if (i+k > 7 || board[i+k][j] * player > 0) {
                                break;
                            } else if (board[i+k][j] * player < 0) {
                                add_move(i, j, i+k, j);
                                break;
                            } else {
                                add_move(i, j, i+k, j);
                            }
                        }
                        for (int k = 1; k < 8; k++) {
                            if (j-k < 0 || board[i][j-k] * player > 0) {
                                break;
                            } else if (board[i][j-k] * player < 0) {
                                add_move(i, j, i, j-k);
                                break;
                            } else {
                                add_move(i, j, i, j-k);
                            }
                        }
                        for (int k = 1; k < 8; k++) {
                            if (j+k > 7 || board[i][j+k] * player > 0) {
                                break;
                            } else if (board[i][j+k] * player < 0) {
                                add_move(i, j, i, j+k);
                                break;
                            } else {
                                add_move(i, j, i, j+k);
                            }
                        }
                        for (int k = 1; k < 8; k++) {
                            if (i-k < 0 || j-k < 0 || board[i-k][j-k] * player > 0) {
                                break;
                            } else if (board[i-k][j-k] * player < 0) {
                                add_move(i, j, i-k, j-k);
                                break;
                            } else {
                                add_move(i, j, i-k, j-k);
                            }
                        }
                        for (int k = 1; k < 8; k++) {
                            if (i-k < 0 || j+k > 7 || board[i-k][j+k] * player > 0) {
                                break;
                            } else if (board[i-k][j+k] * player < 0) {
                                add_move(i, j, i-k, j+k);
                                break;
                            } else {
                                add_move(i, j, i-k, j+k);
                            }
                        }
                        for (int k = 1; k < 8; k++) {
                            if (i+k > 7 || j-k < 0 || board[i+k][j-k] * player > 0) {
                                break;
                            } else if (board[i+k][j-k] * player < 0) {
                                add_move(i, j, i+k, j-k);
                                break;
                            } else {
                                add_move(i, j, i+k, j-k);
                            }
                        }
                        for (int k = 1; k < 8; k++) {
                            if (i+k > 7 || j+k > 7 || board[i+k][j+k] * player > 0) {
                                break;
                            } else if (board[i+k][j+k] * player < 0) {
                                add_move(i, j, i+k, j+k);
                                break;
                            } else {
                                add_move(i, j, i+k, j+k);
                            }
                        }
                        break;
                    default:
                        break;
                }
            }
        }
    }
}

// Add a move to the list of legal moves
void add_move(int r1, int c1, int r2, int c2) {
    moves[num_moves].row = r2;
    moves[num_moves].col = c2;
    num_moves++;
}

int main() {
    find_legal_moves(1);
    return 0;
}