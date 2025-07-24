//FormAI DATASET v1.0 Category: Chess engine ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define BOARD_SIZE 8

// Define chess pieces enum
enum Pieces {
    EMPTY,
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN, 
    KING
};

// Define chess board struct
struct Board {
    enum Pieces pieces[BOARD_SIZE][BOARD_SIZE];
};

// Initialize a new chess board
void init_board(struct Board *board) {
    for (int x = 0; x < BOARD_SIZE; x++) {
        for (int y = 0; y < BOARD_SIZE; y++) {
            if (y == 1) {
                board->pieces[x][y] = PAWN;
            } else if (y == 0 || y == 7) {
                if (x == 0 || x == 7) {
                    board->pieces[x][y] = ROOK;
                } else if (x == 1 || x == 6) {
                    board->pieces[x][y] = KNIGHT;
                } else if (x == 2 || x == 5) {
                    board->pieces[x][y] = BISHOP;
                } else if (x == 3) {
                    board->pieces[x][y] = QUEEN;
                } else if (x == 4) {
                    board->pieces[x][y] = KING;
                }
            } else {
                board->pieces[x][y] = EMPTY;
            }
        }
    }
}

// Print the chess board
void print_board(struct Board *board) {
    for (int y = BOARD_SIZE - 1; y >= 0; y--) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            switch (board->pieces[x][y]) {
                case EMPTY:
                    printf(". ");
                    break;
                case PAWN:
                    printf("p ");
                    break;
                case KNIGHT:
                    printf("n ");
                    break;
                case BISHOP:
                    printf("b ");
                    break;
                case ROOK:
                    printf("r ");
                    break;
                case QUEEN:
                    printf("q ");
                    break;
                case KING:
                    printf("k ");
                    break;
                default:
                    break;
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Check if the given coordinates are within the board boundaries
bool is_within_board(int x, int y) {
    return x >= 0 && y >= 0 && x < BOARD_SIZE && y < BOARD_SIZE;
}

// Check if the given move is valid
bool is_valid_move(struct Board *board, int from_x, int from_y, int to_x, int to_y) {
    if (!is_within_board(from_x, from_y) || !is_within_board(to_x, to_y)) {
        return false;
    }

    enum Pieces piece = board->pieces[from_x][from_y];
    enum Pieces target_piece = board->pieces[to_x][to_y];

    // Check if the target position is empty or contains an enemy piece
    if (target_piece != EMPTY && (target_piece & 0x10) == (piece & 0x10)) {
        return false;
    }

    switch (piece) {
        case EMPTY:
            return false;
        case PAWN:
            if ((from_y == 1 || from_y == 6) && abs(from_y - to_y) == 2) {
                if (from_x != to_x || board->pieces[to_x][to_y] != EMPTY) {
                    return false;
                }
            } else if (from_x == to_x) {
                if (board->pieces[to_x][to_y] != EMPTY) {
                    return false;
                }
            } else if (abs(from_x - to_x) == 1 && abs(from_y - to_y) == 1) {
                if (board->pieces[to_x][to_y] == EMPTY) {
                    return false;
                }
            } else {
                return false;
            }
            break;
        case KNIGHT:
            if (!((abs(from_x - to_x) == 1 && abs(from_y - to_y) == 2) || (abs(from_x - to_x) == 2 && abs(from_y - to_y) == 1))) {
                return false;
            }
            break;
        case BISHOP:
            if (abs(from_x - to_x) != abs(from_y - to_y)) {
                return false;
            }
            for (int i = 1; i < abs(from_x - to_x); i++) {
                if (board->pieces[from_x + i * (to_x - from_x) / abs(from_x - to_x)][from_y + i * (to_y - from_y) / abs(from_y - to_y)] != EMPTY) {
                    return false;
                }
            }
            break;
        case ROOK:
            if (from_x != to_x && from_y != to_y) {
                return false;
            }
            if (from_x == to_x) {
                for (int i = 1; i < abs(from_y - to_y); i++) {
                    if (board->pieces[from_x][from_y + i * (to_y - from_y) / abs(from_y - to_y)] != EMPTY) {
                        return false;
                    }
                }
            } else {
                for (int i = 1; i < abs(from_x - to_x); i++) {
                    if (board->pieces[from_x + i * (to_x - from_x) / abs(from_x - to_x)][from_y] != EMPTY) {
                        return false;
                    }
                }
            }
            break;
        case QUEEN:
            if (abs(from_x - to_x) == abs(from_y - to_y)) {
                for (int i = 1; i < abs(from_x - to_x); i++) {
                    if (board->pieces[from_x + i * (to_x - from_x) / abs(from_x - to_x)][from_y + i * (to_y - from_y) / abs(from_y - to_y)] != EMPTY) {
                        return false;
                    }
                }
            } else if (from_x != to_x && from_y != to_y) {
                return false;
            } else {
                if (from_x == to_x) {
                    for (int i = 1; i < abs(from_y - to_y); i++) {
                        if (board->pieces[from_x][from_y + i * (to_y - from_y) / abs(from_y - to_y)] != EMPTY) {
                            return false;
                        }
                    }
                } else {
                    for (int i = 1; i < abs(from_x - to_x); i++) {
                        if (board->pieces[from_x + i * (to_x - from_x) / abs(from_x - to_x)][from_y] != EMPTY) {
                            return false;
                        }
                    }
                }
            }
            break;
        case KING:
            if (abs(from_x - to_x) > 1 || abs(from_y - to_y) > 1) {
                return false;
            }
            break;
        default:
            return false;
    }

    return true;
}

int main() {
    struct Board board;
    init_board(&board);

    print_board(&board);

    return 0;
}