//FormAI DATASET v1.0 Category: Chess engine ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define BOARD_SIZE 8

// piece color and type constants
enum { WHITE_PAWN, WHITE_KNIGHT, WHITE_BISHOP, WHITE_ROOK, WHITE_QUEEN, WHITE_KING,
       BLACK_PAWN, BLACK_KNIGHT, BLACK_BISHOP, BLACK_ROOK, BLACK_QUEEN, BLACK_KING, EMPTY };

// piece type characters
const char piece_char[] = { 'P', 'N', 'B', 'R', 'Q', 'K', 'p', 'n', 'b', 'r', 'q', 'k', '.' };

// stores the current state of the game board
int board[BOARD_SIZE][BOARD_SIZE] = {
    {BLACK_ROOK,   BLACK_KNIGHT, BLACK_BISHOP, BLACK_QUEEN, BLACK_KING,   BLACK_BISHOP, BLACK_KNIGHT, BLACK_ROOK  },
    {BLACK_PAWN,   BLACK_PAWN,   BLACK_PAWN,   BLACK_PAWN,  BLACK_PAWN,   BLACK_PAWN,   BLACK_PAWN,   BLACK_PAWN  },
    {EMPTY,        EMPTY,        EMPTY,        EMPTY,       EMPTY,        EMPTY,        EMPTY,        EMPTY      },
    {EMPTY,        EMPTY,        EMPTY,        EMPTY,       EMPTY,        EMPTY,        EMPTY,        EMPTY      },
    {EMPTY,        EMPTY,        EMPTY,        EMPTY,       EMPTY,        EMPTY,        EMPTY,        EMPTY      },
    {EMPTY,        EMPTY,        EMPTY,        EMPTY,       EMPTY,        EMPTY,        EMPTY,        EMPTY      },
    {WHITE_PAWN,   WHITE_PAWN,   WHITE_PAWN,   WHITE_PAWN,  WHITE_PAWN,   WHITE_PAWN,   WHITE_PAWN,   WHITE_PAWN  },
    {WHITE_ROOK,   WHITE_KNIGHT, WHITE_BISHOP, WHITE_QUEEN, WHITE_KING,   WHITE_BISHOP, WHITE_KNIGHT, WHITE_ROOK  }
};

// converts a standard chess coordinate (e.g. "a1") to an array index
void coord_to_index(char* coord, int* x, int* y) {
    *x = BOARD_SIZE - (coord[1] - '0');
    *y = coord[0] - 'a';
}

// prints the current state of the board
void print_board() {
    printf("  -----------------\n");
    for (int i = BOARD_SIZE - 1; i >= 0; i--) {
        printf("%d |", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c", piece_char[board[i][j]]);
        }
        printf(" |\n");
    }
    printf("  -----------------\n");
    printf("    a b c d e f g h\n");
}

// moves a piece from one square to another
void make_move(char* from_coord, char* to_coord) {
    int from_x, from_y, to_x, to_y;
    coord_to_index(from_coord, &from_x, &from_y);
    coord_to_index(to_coord, &to_x, &to_y);
    board[to_x][to_y] = board[from_x][from_y];
    board[from_x][from_y] = EMPTY;
}

// determines if a given move is legal and updates the board state if it is
bool move_piece(char* from_coord, char* to_coord) {
    int from_x, from_y, to_x, to_y;
    coord_to_index(from_coord, &from_x, &from_y);
    coord_to_index(to_coord, &to_x, &to_y);

    // check if the move is valid for the piece being moved
    switch (board[from_x][from_y]) {
        case WHITE_PAWN:
            if (to_x == from_x - 1 && to_y == from_y && board[to_x][to_y] == EMPTY) {
                make_move(from_coord, to_coord);
                return true;
            }
            break;
        // add more cases for other piece types here
        default:
            return false;
    }

    return false;
}

// main game loop
int main() {
    char input[10];
    printf("Welcome to the C Chess Engine!\n");
    while (true) {
        print_board();
        printf("Enter your move (e.g. 'a2 a3'): ");
        fgets(input, sizeof(input), stdin);
        if (strlen(input) < 5 || !isalpha(input[0]) || !isdigit(input[1]) || input[2] != ' ' ||
            !isalpha(input[3]) || !isdigit(input[4])) {
            printf("Invalid input. Please enter your move in the format 'a2 a3'.\n");
        } else {
            if (move_piece(input, input + 3)) {
                printf("Move successful.\n");
            } else {
                printf("Invalid move.\n");
            }
        }
    }
    return 0;
}