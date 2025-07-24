//FormAI DATASET v1.0 Category: Chess engine ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define BOARD_SIZE 8

struct Board {
    char squares[BOARD_SIZE][BOARD_SIZE]; // ' ' for empty, 'P'/'p' for pawn, 'K'/'k' for king, etc.
};

char get_piece_at(struct Board* board, int x, int y) {
    if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE) {
        return board->squares[x][y];
    }
    return '\0'; // out of bounds
}

bool is_move_possible(struct Board* board, int from_x, int from_y, int to_x, int to_y) {
    char piece = get_piece_at(board, from_x, from_y);
    if (piece == '\0') {
        return false; // invalid move or out of bounds
    }

    // check if piece can move to target square
    switch (piece) {
        case 'P': // pawn
            // ...
            break;
        case 'K': // king
            // ...
            break;
        // ...
    }
    return false; // invalid move
}

void print_board(struct Board* board) {
    for (int y = BOARD_SIZE - 1; y >= 0; y--) {
        printf("%d", y + 1);
        for (int x = 0; x < BOARD_SIZE; x++) {
            printf(" %c", get_piece_at(board, x, y));
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}

// initialize board with standard chess setup
void init_board(struct Board* board) {
    board->squares[0][0] = board->squares[7][0] = 'R';
    board->squares[1][0] = board->squares[6][0] = 'N';
    board->squares[2][0] = board->squares[5][0] = 'B';
    board->squares[3][0] = 'Q';
    board->squares[4][0] = 'K';
    for (int x = 0; x < BOARD_SIZE; x++) {
        board->squares[x][1] = 'P';
        board->squares[x][6] = 'p';
    }
    board->squares[0][7] = board->squares[7][7] = 'r';
    board->squares[1][7] = board->squares[6][7] = 'n';
    board->squares[2][7] = board->squares[5][7] = 'b';
    board->squares[3][7] = 'q';
    board->squares[4][7] = 'k';
    // remaining squares are empty
}

int main() {
    struct Board board;
    init_board(&board);
    print_board(&board);

    // TODO: implement game loop
}