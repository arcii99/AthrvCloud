//FormAI DATASET v1.0 Category: Chess engine ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the chess board size
#define BOARD_SIZE 8

// Define the chess pieces
#define EMPTY 0
#define PAWN 1
#define KNIGHT 2
#define BISHOP 3
#define ROOK 4
#define QUEEN 5
#define KING 6

// Define the chess colors
#define WHITE 0
#define BLACK 1

// Define the chess board
int board[BOARD_SIZE][BOARD_SIZE];

// Define a structure for a chess piece
typedef struct {
    int type;
    int color;
    int x;
    int y;
} ChessPiece;

// Print the chess board
void print_board() {
    printf("\n  A B C D E F G H\n");
    printf("  ----------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                printf(" |");
            } else {
                printf("%c|", board[i][j]);
            }
        }
        printf("%d\n", i + 1);
    }
    printf("  ----------------\n");
    printf("  A B C D E F G H\n\n");
}

// Initialize the chess board
void initialize_board() {
    // Initialize the pawns
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[1][i] = PAWN;
        board[6][i] = PAWN;
    }
    
    // Initialize the other pieces
    board[0][0] = ROOK;
    board[0][1] = KNIGHT;
    board[0][2] = BISHOP;
    board[0][3] = QUEEN;
    board[0][4] = KING;
    board[0][5] = BISHOP;
    board[0][6] = KNIGHT;
    board[0][7] = ROOK;
    
    board[7][0] = ROOK;
    board[7][1] = KNIGHT;
    board[7][2] = BISHOP;
    board[7][3] = QUEEN;
    board[7][4] = KING;
    board[7][5] = BISHOP;
    board[7][6] = KNIGHT;
    board[7][7] = ROOK;
}

// Move a chess piece
void move_piece(ChessPiece* piece, int x, int y) {
    board[piece->x][piece->y] = EMPTY;
    piece->x = x;
    piece->y = y;
    board[piece->x][piece->y] = piece->type + (piece->color == WHITE ? 'A' : 'a');
}

// Check if a move is valid
int is_valid_move(ChessPiece* piece, int x, int y) {
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
        return 0;
    }
    if (board[x][y] != EMPTY && board[x][y] / 10 == piece->color) {
        return 0;
    }
    switch (piece->type) {
        case PAWN:
            if (piece->color == WHITE) {
                if (x == piece->x - 1) {
                    if (y == piece->y - 1 || y == piece->y + 1) {
                        return board[x][y] != EMPTY || (x == 0 && y == 0) || (x == 0 && y == BOARD_SIZE - 1);
                    }
                } else if (x == piece->x - 2 && piece->x == 6 && y == piece->y) {
                    return board[piece->x - 1][y] == EMPTY && board[piece->x - 2][y] == EMPTY;
                }
            } else {
                if (x == piece->x + 1) {
                    if (y == piece->y - 1 || y == piece->y + 1) {
                        return board[x][y] != EMPTY || (x == BOARD_SIZE - 1 && y == 0) || (x == BOARD_SIZE - 1 && y == BOARD_SIZE - 1);
                    }
                } else if (x == piece->x + 2 && piece->x == 1 && y == piece->y) {
                    return board[piece->x + 1][y] == EMPTY && board[piece->x + 2][y] == EMPTY;
                }
            }
            return 0;
        case KNIGHT:
            return (x == piece->x + 2 && y == piece->y + 1) ||
                   (x == piece->x + 2 && y == piece->y - 1) ||
                   (x == piece->x - 2 && y == piece->y + 1) ||
                   (x == piece->x - 2 && y == piece->y - 1) ||
                   (x == piece->x + 1 && y == piece->y + 2) ||
                   (x == piece->x + 1 && y == piece->y - 2) ||
                   (x == piece->x - 1 && y == piece->y + 2) ||
                   (x == piece->x - 1 && y == piece->y - 2);
        case BISHOP:
            if (abs(x - piece->x) != abs(y - piece->y)) {
                return 0;
            }
            if (x > piece->x && y > piece->y) {
                for (int i = piece->x + 1, j = piece->y + 1; i < x; i++, j++) {
                    if (board[i][j] != EMPTY) {
                        return 0;
                    }
                }
            } else if (x > piece->x && y < piece->y) {
                for (int i = piece->x + 1, j = piece->y - 1; i < x; i++, j--) {
                    if (board[i][j] != EMPTY) {
                        return 0;
                    }
                }
            } else if (x < piece->x && y > piece->y) {
                for (int i = piece->x - 1, j = piece->y + 1; i > x; i--, j++) {
                    if (board[i][j] != EMPTY) {
                        return 0;
                    }
                }
            } else {
                for (int i = piece->x - 1, j = piece->y - 1; i > x; i--, j--) {
                    if (board[i][j] != EMPTY) {
                        return 0;
                    }
                }
            }
            return 1;
        case ROOK:
            if (x != piece->x && y != piece->y) {
                return 0;
            }
            if (x > piece->x) {
                for (int i = piece->x + 1; i < x; i++) {
                    if (board[i][piece->y] != EMPTY) {
                        return 0;
                    }
                }
            } else if (x < piece->x) {
                for (int i = piece->x - 1; i > x; i--) {
                    if (board[i][piece->y] != EMPTY) {
                        return 0;
                    }
                }
            } else if (y > piece->y) {
                for (int i = piece->y + 1; i < y; i++) {
                    if (board[piece->x][i] != EMPTY) {
                        return 0;
                    }
                }
            } else {
                for (int i = piece->y - 1; i > y; i--) {
                    if (board[piece->x][i] != EMPTY) {
                        return 0;
                    }
                }
            }
            return 1;
        case QUEEN:
            return is_valid_move(piece, x, y) && (is_valid_move(piece, x, piece->y) || is_valid_move(piece, piece->x, y));
        case KING:
            return abs(x - piece->x) <= 1 && abs(y - piece->y) <= 1;
        default:
            return 0;
    }
}

int main() {
    // Initialize the chess board
    initialize_board();
    
    // Print the starting position
    print_board();
    
    // Move some pieces
    ChessPiece white_king = {KING, WHITE, 0, 4};
    ChessPiece black_knight = {KNIGHT, BLACK, 7, 6};
    move_piece(&white_king, 1, 4);
    move_piece(&black_knight, 5, 5);
    
    // Print the new position
    print_board();
    
    // Check if a move is valid
    ChessPiece white_pawn = {PAWN, WHITE, 1, 0};
    printf("Is moving white pawn to square 2,0 valid? %s\n", is_valid_move(&white_pawn, 2, 0) ? "yes" : "no");
    printf("Is moving white pawn to square 3,0 valid? %s\n", is_valid_move(&white_pawn, 3, 0) ? "yes" : "no");
    
    return 0;
}