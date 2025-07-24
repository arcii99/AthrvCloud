//FormAI DATASET v1.0 Category: Checkers Game ; Style: decentralized
#include <stdio.h>
#include <string.h>

#define BOARD_SIZE 8
#define WHITE_PIECE 'w'
#define BLACK_PIECE 'b'
#define EMPTY_SPACE  ' '

char board[BOARD_SIZE][BOARD_SIZE];

char char_to_piece(char piece_char) {
    if (piece_char == 'w') {
        return WHITE_PIECE;
    } else if (piece_char == 'b') {
        return BLACK_PIECE;
    }
    return EMPTY_SPACE;
}

void init_board() {
    int i;
    int j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY_SPACE;
        }
    }
}

void print_board() {
    int i;
    int j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY_SPACE) {
                printf(" ");
            } else {
                printf("%c", board[i][j]);
            }
        }
        printf("\n");
    }
}

void place_piece(char piece_type, int row, int col) {
    if (row >= BOARD_SIZE || col >= BOARD_SIZE) {
        printf("Invalid coordinates!\n");
        return;
    }
    if (board[row][col] != EMPTY_SPACE) {
        printf("Position already filled!\n");
        return;
    }
    board[row][col] = piece_type;
}

int main() {
    init_board();
    place_piece(BLACK_PIECE, 3, 4);
    place_piece(BLACK_PIECE, 2, 5);
    place_piece(WHITE_PIECE, 5, 2);
    print_board();
    return 0;
}