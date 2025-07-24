//FormAI DATASET v1.0 Category: Chess engine ; Style: relaxed
#include <stdio.h>

// Define piece values
#define PAWN_VALUE 1
#define KNIGHT_VALUE 3
#define BISHOP_VALUE 3
#define ROOK_VALUE 5
#define QUEEN_VALUE 9
#define KING_VALUE 500

// Define board dimensions
#define ROWS 8
#define COLUMNS 8

// Define piece characters
#define EMPTY '-'
#define PAWN 'P'
#define KNIGHT 'N'
#define BISHOP 'B'
#define ROOK 'R'
#define QUEEN 'Q'
#define KING 'K'


// Define board
char board[ROWS][COLUMNS] = {
    {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK},
    {PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN},
    {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK},
};

// Define piece values array
int values[6] = {PAWN_VALUE, KNIGHT_VALUE, BISHOP_VALUE, ROOK_VALUE, QUEEN_VALUE, KING_VALUE};

// Define function to print board
void print_board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
}

// Define function to get value of piece
int get_value(char piece) {
    switch (piece) {
        case PAWN:
            return PAWN_VALUE;
        case KNIGHT:
            return KNIGHT_VALUE;
        case BISHOP:
            return BISHOP_VALUE;
        case ROOK:
            return ROOK_VALUE;
        case QUEEN:
            return QUEEN_VALUE;
        case KING:
            return KING_VALUE;
        default:
            return 0;
    }
}

// Define function to get total value of pieces for a player
int get_total_value(char side) {
    int total_value = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            char piece = board[i][j];
            if (piece != EMPTY) {
                if (side == 'w' && isupper(piece)) {
                    total_value += get_value(piece);
                } else if (side == 'b' && islower(piece)) {
                    total_value += get_value(piece);
                }
            }
        }
    }
    return total_value;
}

int main() {
    printf("Initial board:\n");
    print_board();
    
    printf("\nTotal value of pieces for white: %d\n", get_total_value('w'));
    printf("Total value of pieces for black: %d\n", get_total_value('b'));
    
    return 0;
}