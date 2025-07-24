//FormAI DATASET v1.0 Category: Chess AI ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8

// Constants for the value of each piece
#define PAWN_VALUE 1
#define KNIGHT_VALUE 3
#define BISHOP_VALUE 3
#define ROOK_VALUE 5
#define QUEEN_VALUE 9
#define KING_VALUE 0

// Constants for the color of each piece
#define BLACK 1
#define WHITE 0

// Struct for each piece
typedef struct {
    int value;
    int color; // 0 for white, 1 for black
} Piece;

// Struct for each square on the board
typedef struct {
    Piece *piece; // NULL if square is empty
    int x; // x and y coordinates
    int y;
} Square;

// Struct for the entire board
typedef struct {
    Square *squares[BOARD_SIZE][BOARD_SIZE];
} Board;

// Initialize the board and pieces
void init_board(Board *board) {
    // Initialize and place pawns
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->squares[i][j] = malloc(sizeof(Square));
            if (i == 1) {
                board->squares[i][j]->piece = malloc(sizeof(Piece));
                board->squares[i][j]->piece->value = PAWN_VALUE;
                board->squares[i][j]->piece->color = BLACK;
            } else if (i == BOARD_SIZE - 2) {
                board->squares[i][j]->piece = malloc(sizeof(Piece));
                board->squares[i][j]->piece->value = PAWN_VALUE;
                board->squares[i][j]->piece->color = WHITE;
            } else {
                board->squares[i][j]->piece = NULL;
            }
            board->squares[i][j]->x = i;
            board->squares[i][j]->y = j;
        }
    }
    // Initialize and place knights
    board->squares[0][1]->piece = malloc(sizeof(Piece));
    board->squares[0][1]->piece->value = KNIGHT_VALUE;
    board->squares[0][1]->piece->color = BLACK;
    board->squares[0][6]->piece = malloc(sizeof(Piece));
    board->squares[0][6]->piece->value = KNIGHT_VALUE;
    board->squares[0][6]->piece->color = BLACK;
    board->squares[BOARD_SIZE - 1][1]->piece = malloc(sizeof(Piece));
    board->squares[BOARD_SIZE - 1][1]->piece->value = KNIGHT_VALUE;
    board->squares[BOARD_SIZE - 1][1]->piece->color = WHITE;
    board->squares[BOARD_SIZE - 1][6]->piece = malloc(sizeof(Piece));
    board->squares[BOARD_SIZE - 1][6]->piece->value = KNIGHT_VALUE;
    board->squares[BOARD_SIZE - 1][6]->piece->color = WHITE;
    // Initialize and place bishops
    board->squares[0][2]->piece = malloc(sizeof(Piece));
    board->squares[0][2]->piece->value = BISHOP_VALUE;
    board->squares[0][2]->piece->color = BLACK;
    board->squares[0][5]->piece = malloc(sizeof(Piece));
    board->squares[0][5]->piece->value = BISHOP_VALUE;
    board->squares[0][5]->piece->color = BLACK;
    board->squares[BOARD_SIZE - 1][2]->piece = malloc(sizeof(Piece));
    board->squares[BOARD_SIZE - 1][2]->piece->value = BISHOP_VALUE;
    board->squares[BOARD_SIZE - 1][2]->piece->color = WHITE;
    board->squares[BOARD_SIZE - 1][5]->piece = malloc(sizeof(Piece));
    board->squares[BOARD_SIZE - 1][5]->piece->value = BISHOP_VALUE;
    board->squares[BOARD_SIZE - 1][5]->piece->color = WHITE;
    // Initialize and place rooks
    board->squares[0][0]->piece = malloc(sizeof(Piece));
    board->squares[0][0]->piece->value = ROOK_VALUE;
    board->squares[0][0]->piece->color = BLACK;
    board->squares[0][7]->piece = malloc(sizeof(Piece));
    board->squares[0][7]->piece->value = ROOK_VALUE;
    board->squares[0][7]->piece->color = BLACK;
    board->squares[BOARD_SIZE - 1][0]->piece = malloc(sizeof(Piece));
    board->squares[BOARD_SIZE - 1][0]->piece->value = ROOK_VALUE;
    board->squares[BOARD_SIZE - 1][0]->piece->color = WHITE;
    board->squares[BOARD_SIZE - 1][7]->piece = malloc(sizeof(Piece));
    board->squares[BOARD_SIZE - 1][7]->piece->value = ROOK_VALUE;
    board->squares[BOARD_SIZE - 1][7]->piece->color = WHITE;
    // Initialize and place queens
    board->squares[0][3]->piece = malloc(sizeof(Piece));
    board->squares[0][3]->piece->value = QUEEN_VALUE;
    board->squares[0][3]->piece->color = BLACK;
    board->squares[BOARD_SIZE - 1][3]->piece = malloc(sizeof(Piece));
    board->squares[BOARD_SIZE - 1][3]->piece->value = QUEEN_VALUE;
    board->squares[BOARD_SIZE - 1][3]->piece->color = WHITE;
    // Initialize and place kings
    board->squares[0][4]->piece = malloc(sizeof(Piece));
    board->squares[0][4]->piece->value = KING_VALUE;
    board->squares[0][4]->piece->color = BLACK;
    board->squares[BOARD_SIZE - 1][4]->piece = malloc(sizeof(Piece));
    board->squares[BOARD_SIZE - 1][4]->piece->value = KING_VALUE;
    board->squares[BOARD_SIZE - 1][4]->piece->color = WHITE;
}

// Print the board and pieces
void print_board(Board *board) {
    printf("   0  1  2  3  4  5  6  7\n");
    printf("  ------------------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d |", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->squares[i][j]->piece == NULL) {
                printf(" . ");
            } else {
                if (board->squares[i][j]->piece->color == WHITE) {
                    printf("W");
                } else {
                    printf("B");
                }
                printf("%d", board->squares[i][j]->piece->value);
                printf(" ");
            }
            printf("|");
        }
        printf("\n");
        printf("  ------------------------\n");
    }
}

int main() {
    srand(time(NULL));
    Board board;
    init_board(&board);
    print_board(&board);
    return 0;
}