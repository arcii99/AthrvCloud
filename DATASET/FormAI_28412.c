//FormAI DATASET v1.0 Category: Chess AI ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8

int pawn_table[BOARD_SIZE][BOARD_SIZE] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {50, 50, 50, 50, 50, 50, 50, 50},
    {10, 10, 20, 30, 30, 20, 10, 10},
    {5, 5, 10, 25, 25, 10, 5, 5},
    {0, 0, 0, 20, 20, 0, 0, 0},
    {5, -5, -10, 0, 0, -10, -5, 5},
    {5, 10, 10, -20, -20, 10, 10, 5},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

int knight_table[BOARD_SIZE][BOARD_SIZE] = {
    {-50, -40, -30, -30, -30, -30, -40, -50},
    {-40, -20, 0, 0, 0, 0, -20, -40},
    {-30, 0, 10, 15, 15, 10, 0, -30},
    {-30, 5, 15, 20, 20, 15, 5, -30},
    {-30, 0, 15, 20, 20, 15, 0, -30},
    {-30, 5, 10, 15, 15, 10, 5, -30},
    {-40, -20, 0, 5, 5, 0, -20, -40},
    {-50, -40, -30, -30, -30, -30, -40, -50}
};

int bishop_table[BOARD_SIZE][BOARD_SIZE] = {
    {-20, -10, -10, -10, -10, -10, -10, -20},
    {-10, 0, 0, 0, 0, 0, 0, -10},
    {-10, 0, 5, 10, 10, 5, 0, -10},
    {-10, 5, 5, 10, 10, 5, 5, -10},
    {-10, 0, 10, 10, 10, 10, 0, -10},
    {-10, 10, 10, 10, 10, 10, 10, -10},
    {-10, 5, 0, 0, 0, 0, 5, -10},
    {-20, -10, -10, -10, -10, -10, -10, -20}
};

int rook_table[BOARD_SIZE][BOARD_SIZE] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {5, 10, 10, 10, 10, 10, 10, 5},
    {-5, 0, 0, 0, 0, 0, 0, -5},
    {-5, 0, 0, 0, 0, 0, 0, -5},
    {-5, 0, 0, 0, 0, 0, 0, -5},
    {-5, 0, 0, 0, 0, 0, 0, -5},
    {-5, 0, 0, 0, 0, 0, 0, -5},
    {0, 0, 0, 5, 5, 0, 0, 0}
};

int queen_table[BOARD_SIZE][BOARD_SIZE] = {
    {-20, -10, -10, -5, -5, -10, -10, -20},
    {-10, 0, 0, 0, 0, 0, 0, -10},
    {-10, 0, 5, 5, 5, 5, 0, -10},
    {-5, 0, 5, 5, 5, 5, 0, -5},
    {0, 0, 5, 5, 5, 5, 0, -5},
    {-10, 5, 5, 5, 5, 5, 0, -10},
    {-10, 0, 5, 0, 0, 0, 0, -10},
    {-20, -10, -10, -5, -5, -10, -10, -20}
};

int king_table[BOARD_SIZE][BOARD_SIZE] = {
    {-30, -40, -40, -50, -50, -40, -40, -30},
    {-30, -40, -40, -50, -50, -40, -40, -30},
    {-30, -40, -40, -50, -50, -40, -40, -30},
    {-30, -40, -40, -50, -50, -40, -40, -30},
    {-20, -30, -30, -40, -40, -30, -30, -20},
    {-10, -20, -20, -20, -20, -20, -20, -10},
    {20, 20, 0, 0, 0, 0, 20, 20},
    {20, 30, 10, 0, 0, 10, 30, 20},
};

typedef struct {
    int x;
    int y;
} 
Position;

typedef struct {
    char color;
    char type;
    Position position;
} 
Piece;

Position get_position(int x, int y) {
    Position position;
    position.x = x;
    position.y = y;
    return position;
}

Piece get_piece(char color, char type, int x, int y) {
    Piece piece;
    piece.color = color;
    piece.type = type;
    piece.position = get_position(x, y);
    return piece;
}

void initialize_board(Piece board[BOARD_SIZE][BOARD_SIZE]) {
    // Black Pieces
    board[0][0] = get_piece('b', 'r', 0, 0);
    board[0][1] = get_piece('b', 'k', 0, 1);
    board[0][2] = get_piece('b', 'b', 0, 2);
    board[0][3] = get_piece('b', 'q', 0, 3);
    board[0][4] = get_piece('b', 'n', 0, 4);
    board[0][5] = get_piece('b', 'b', 0, 5);
    board[0][6] = get_piece('b', 'k', 0, 6);
    board[0][7] = get_piece('b', 'r', 0, 7);
    board[1][0] = get_piece('b', 'p', 1, 0);
    board[1][1] = get_piece('b', 'p', 1, 1);
    board[1][2] = get_piece('b', 'p', 1, 2);
    board[1][3] = get_piece('b', 'p', 1, 3);
    board[1][4] = get_piece('b', 'p', 1, 4);
    board[1][5] = get_piece('b', 'p', 1, 5);
    board[1][6] = get_piece('b', 'p', 1, 6);
    board[1][7] = get_piece('b', 'p', 1, 7);

    // White Pieces
    board[7][0] = get_piece('w', 'r', 7, 0);
    board[7][1] = get_piece('w', 'k', 7, 1);
    board[7][2] = get_piece('w', 'b', 7, 2);
    board[7][3] = get_piece('w', 'q', 7, 3);
    board[7][4] = get_piece('w', 'n', 7, 4);
    board[7][5] = get_piece('w', 'b', 7, 5);
    board[7][6] = get_piece('w', 'k', 7, 6);
    board[7][7] = get_piece('w', 'r', 7, 7);
    board[6][0] = get_piece('w', 'p', 6, 0);
    board[6][1] = get_piece('w', 'p', 6, 1);
    board[6][2] = get_piece('w', 'p', 6, 2);
    board[6][3] = get_piece('w', 'p', 6, 3);
    board[6][4] = get_piece('w', 'p', 6, 4);
    board[6][5] = get_piece('w', 'p', 6, 5);
    board[6][6] = get_piece('w', 'p', 6, 6);
    board[6][7] = get_piece('w', 'p', 6, 7);
}

int evaluate_position(Piece board[BOARD_SIZE][BOARD_SIZE]) {
    int score = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            Piece piece = board[i][j];
            int value = 0;

            switch (piece.type) {
                case 'p':
                    value = 100 + pawn_table[i][j];
                    break;
                case 'n':
                    value = 320 + knight_table[i][j];
                    break;
                case 'b':
                    value = 330 + bishop_table[i][j];
                    break;
                case 'r':
                    value = 500 + rook_table[i][j];
                    break;
                case 'q':
                    value = 900 + queen_table[i][j];
                    break;
                case 'k':
                    value = 20000 + king_table[i][j];
                    break;
            }

            if (piece.color == 'w') {
                score += value;
            } else {
                score -= value;
            }
        }
    }
    return score;
}

void print_board(Piece board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            Piece piece = board[i][j];
            if (piece.type == 0) {
                printf("-- ");
            } else {
                printf("%c%c ", piece.color, piece.type);
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    Piece board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);

    print_board(board);

    int score = evaluate_position(board);
    printf("Initial score: %d\n", score);

    return 0;
}