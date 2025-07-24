//FormAI DATASET v1.0 Category: Chess engine ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * A Chess Engine Program
 * By: [Your Name]
 */

// Define Board Tile Size
#define BOARD_SIZE 8

// Piece Color Constants
#define WHITE 0
#define BLACK 1

// Piece Type Constants
#define PAWN 1
#define ROOK 2
#define KNIGHT 3
#define BISHOP 4
#define QUEEN 5
#define KING 6

// Piece Struct
struct Piece {
    int type;
    int color;
    char symbol;
};

// Board Struct
struct Board {
    struct Piece tiles[BOARD_SIZE][BOARD_SIZE];
};

// Initialize Chess Board
void InitBoard(struct Board* board) {
    // Setup Pawns
    for (int file = 0; file < BOARD_SIZE; file++) {
        board->tiles[1][file].type = PAWN;
        board->tiles[1][file].color = BLACK;
        board->tiles[1][file].symbol = 'P';

        board->tiles[6][file].type = PAWN;
        board->tiles[6][file].color = WHITE;
        board->tiles[6][file].symbol = 'p';
    }

    // Setup Rooks
    board->tiles[0][0].type = ROOK;
    board->tiles[0][0].color = BLACK;
    board->tiles[0][0].symbol = 'R';

    board->tiles[0][7].type = ROOK;
    board->tiles[0][7].color = BLACK;
    board->tiles[0][7].symbol = 'R';

    board->tiles[7][0].type = ROOK;
    board->tiles[7][0].color = WHITE;
    board->tiles[7][0].symbol = 'r';

    board->tiles[7][7].type = ROOK;
    board->tiles[7][7].color = WHITE;
    board->tiles[7][7].symbol = 'r';

    // Setup Knights
    board->tiles[0][1].type = KNIGHT;
    board->tiles[0][1].color = BLACK;
    board->tiles[0][1].symbol = 'N';

    board->tiles[0][6].type = KNIGHT;
    board->tiles[0][6].color = BLACK;
    board->tiles[0][6].symbol = 'N';

    board->tiles[7][1].type = KNIGHT;
    board->tiles[7][1].color = WHITE;
    board->tiles[7][1].symbol = 'n';

    board->tiles[7][6].type = KNIGHT;
    board->tiles[7][6].color = WHITE;
    board->tiles[7][6].symbol = 'n';

    // Setup Bishops
    board->tiles[0][2].type = BISHOP;
    board->tiles[0][2].color = BLACK;
    board->tiles[0][2].symbol = 'B';

    board->tiles[0][5].type = BISHOP;
    board->tiles[0][5].color = BLACK;
    board->tiles[0][5].symbol = 'B';

    board->tiles[7][2].type = BISHOP;
    board->tiles[7][2].color = WHITE;
    board->tiles[7][2].symbol = 'b';

    board->tiles[7][5].type = BISHOP;
    board->tiles[7][5].color = WHITE;
    board->tiles[7][5].symbol = 'b';

    // Setup Queens
    board->tiles[0][3].type = QUEEN;
    board->tiles[0][3].color = BLACK;
    board->tiles[0][3].symbol = 'Q';

    board->tiles[7][3].type = QUEEN;
    board->tiles[7][3].color = WHITE;
    board->tiles[7][3].symbol = 'q';

    // Setup Kings
    board->tiles[0][4].type = KING;
    board->tiles[0][4].color = BLACK;
    board->tiles[0][4].symbol = 'K';

    board->tiles[7][4].type = KING;
    board->tiles[7][4].color = WHITE;
    board->tiles[7][4].symbol = 'k';
}

// Print Chess Board
void PrintBoard(struct Board* board) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        printf(" +---+---+---+---+---+---+---+---+\n");
        printf(" |");
        for (int file = 0; file < BOARD_SIZE; file++) {
            printf(" %c |", board->tiles[row][file].symbol);
        }
        printf(" %d\n", BOARD_SIZE - row);
    }
    printf(" +---+---+---+---+---+---+---+---+\n");
    printf("   a   b   c   d   e   f   g   h\n");
}

// Get User Input
char* GetUserInput() {
    char* input = malloc(sizeof(char) * 5);
    printf("Enter Move (e.g. e2e4): ");
    scanf("%s", input);
    return input;
}

// Parse User Input
void ParseUserInput(char* input, int* from_row, int* from_file, int* to_row, int* to_file) {
    *from_file = (int)input[0] - (int)'a';
    *from_row = BOARD_SIZE - ((int)input[1] - (int)'0');

    *to_file = (int)input[2] - (int)'a';
    *to_row = BOARD_SIZE - ((int)input[3] - (int)'0');
}

// Validate User Input
int ValidateUserInput(struct Board* board, int from_row, int from_file, int to_row, int to_file) {

    // Check From Tile has Piece
    if (board->tiles[from_row][from_file].type == 0) {
        return 0;
    }

    // Check To Tile is Empty or Opponent Piece
    if (board->tiles[to_row][to_file].type != 0 && board->tiles[to_row][to_file].color == board->tiles[from_row][from_file].color) {
        return 0;
    }

    return 1;
}

// Move Piece
void MovePiece(struct Board* board, int from_row, int from_file, int to_row, int to_file) {
    // Copy Piece to New Tile
    board->tiles[to_row][to_file].type = board->tiles[from_row][from_file].type;
    board->tiles[to_row][to_file].color = board->tiles[from_row][from_file].color;
    board->tiles[to_row][to_file].symbol = board->tiles[from_row][from_file].symbol;

    // Clear Old Tile
    board->tiles[from_row][from_file].type = 0;
    board->tiles[from_row][from_file].color = 0;
    board->tiles[from_row][from_file].symbol = ' ';
}

int main() {
    struct Board board;
    int from_row, from_file, to_row, to_file;

    InitBoard(&board);
    PrintBoard(&board);

    while (1) {
        char* input = GetUserInput();
        ParseUserInput(input, &from_row, &from_file, &to_row, &to_file);

        if (ValidateUserInput(&board, from_row, from_file, to_row, to_file)) {
            MovePiece(&board, from_row, from_file, to_row, to_file);
            PrintBoard(&board);
        } else {
            printf("Invalid Move! Try Again.\n");
        }
        
        free(input);
    }

    return 0;
}