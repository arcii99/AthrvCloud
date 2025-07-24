//FormAI DATASET v1.0 Category: Chess engine ; Style: immersive
#include <stdio.h>

// Chess board data structure
typedef struct {
    char board[8][8];
    // 'w' for white, 'b' for black
    // 'p' for pawn, 'r' for rook, 'n' for knight, 'b' for bishop, 'q' for queen, 'k' for king
} Board;

// Function prototypes
void init_board(Board *board);
void print_board(Board *board);

int main() {
    // Initialize the board
    Board board;
    init_board(&board);

    // Print the board
    print_board(&board);

    return 0;
}

void init_board(Board *board) {
    // Set up white pieces
    board->board[0][0] = 'r';
    board->board[0][1] = 'n';
    board->board[0][2] = 'b';
    board->board[0][3] = 'q';
    board->board[0][4] = 'k';
    board->board[0][5] = 'b';
    board->board[0][6] = 'n';
    board->board[0][7] = 'r';
    for (int i = 0; i < 8; i++) {
        board->board[1][i] = 'p';
    }

    // Set up black pieces
    board->board[7][0] = 'R';
    board->board[7][1] = 'N';
    board->board[7][2] = 'B';
    board->board[7][3] = 'Q';
    board->board[7][4] = 'K';
    board->board[7][5] = 'B';
    board->board[7][6] = 'N';
    board->board[7][7] = 'R';
    for (int i = 0; i < 8; i++) {
        board->board[6][i] = 'P';
    }

    // Set up empty squares
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            board->board[i][j] = '-';
        }
    }
}

void print_board(Board *board) {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < 8; j++) {
            printf("%c ", board->board[i][j]);
        }
        printf("%d\n", 8 - i);
    }
    printf("  a b c d e f g h\n");
}