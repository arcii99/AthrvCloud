//FormAI DATASET v1.0 Category: Checkers Game ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#define ROWS 8
#define COLUMNS 8

// create the checkerboard
char board[ROWS][COLUMNS] = {
    {' ', 'o', ' ', 'o', ' ', 'o', ' ', 'o'},
    {'o', ' ', 'o', ' ', 'o', ' ', 'o', ' '},
    {' ', 'o', ' ', 'o', ' ', 'o', ' ', 'o'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'x', ' ', 'x', ' ', 'x', ' ', 'x', ' '},
    {' ', 'x', ' ', 'x', ' ', 'x', ' ', 'x'},
    {'x', ' ', 'x', ' ', 'x', ' ', 'x', ' '}
};

// define the piece type
typedef enum {
    NO_PIECE,
    WHITE_PAWN,
    WHITE_KING,
    BLACK_PAWN,
    BLACK_KING
} piece_type;

// define the piece struct
typedef struct {
    piece_type type;
    int x;
    int y;
} piece;

// create the pieces
piece white_pieces[12];
piece black_pieces[12];

// initialize the pieces on the checkerboard
void init_pieces() {
    int w_count = 0;
    int b_count = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            // add white pieces
            if (i < 3 && (i + j) % 2 == 0) {
                white_pieces[w_count].type = WHITE_PAWN;
                white_pieces[w_count].x = j;
                white_pieces[w_count].y = i;
                w_count++;
            }
            // add black pieces
            else if (i > 4 && (i + j) % 2 == 0) {
                black_pieces[b_count].type = BLACK_PAWN;
                black_pieces[b_count].x = j;
                black_pieces[b_count].y = i;
                b_count++;
            }
        }
    }
}

// print out a single piece
void print_piece(piece p) {
    switch (p.type) {
        case WHITE_PAWN:
            printf("o");
            break;
        case WHITE_KING:
            printf("O");
            break;
        case BLACK_PAWN:
            printf("x");
            break;
        case BLACK_KING:
            printf("X");
            break;
        default:
            printf(" ");
            break;  
    }
}

// print out the checkerboard
void print_board() {
    printf("  A B C D E F G H\n");
    printf("  - - - - - - - -\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d|", i+1);
        for (int j = 0; j < COLUMNS; j++) {
            int found = 0;
            // check for a white piece
            for (int k = 0; k < 12; k++) {
                if (white_pieces[k].x == j && white_pieces[k].y == i) {
                    print_piece(white_pieces[k]);
                    found = 1;
                    break;
                }
            }
            // check for a black piece
            if (!found) {
                for (int k = 0; k < 12; k++) {
                    if (black_pieces[k].x == j && black_pieces[k].y == i) {
                        print_piece(black_pieces[k]);
                        found = 1;
                        break;
                    }
                }
            }
            // if no pieces were found, print a space
            if (!found) {
                printf(" ");
            }
            printf("|");
        }
        printf("%d\n", i+1);
        printf("  - - - - - - - -\n");
    }
    printf("  A B C D E F G H\n");
}

int main() {
    // initialize the pieces on the checkerboard
    init_pieces();

    // print out the starting checkerboard
    printf("Welcome to Checkers!\n");
    printf("Starting Position:\n");
    print_board();

    return 0;
}