//FormAI DATASET v1.0 Category: Chess engine ; Style: energetic
#include <stdio.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

void init_board() {
    // Initialize the board to the standard starting position.
    for(int row = 0; row < BOARD_SIZE; row++) {
        for(int col = 0; col < BOARD_SIZE; col++) {
            if(row == 0 || row == 7) {
                if(col == 0 || col == 7) {
                    board[row][col] = 'R';
                } else if(col == 1 || col == 6) {
                    board[row][col] = 'N';
                } else if(col == 2 || col == 5) {
                    board[row][col] = 'B';
                } else if(col == 3) {
                    board[row][col] = 'Q';
                } else { // col == 4
                    board[row][col] = 'K';
                }
            } else if(row == 1 || row == 6) {
                board[row][col] = 'P';
            } else {
                board[row][col] = ' ';
            }
        }
    }
}

void print_board() {
    // Print out the board with labels.
    printf("  a b c d e f g h\n");
    for(int row = 0; row < BOARD_SIZE; row++) {
        printf("%d ", BOARD_SIZE - row);
        for(int col = 0; col < BOARD_SIZE; col++) {
            printf("%c ", board[row][col]);
        }
        printf("%d\n", BOARD_SIZE - row);
    }
    printf("  a b c d e f g h\n");
}

int main() {
    init_board();
    print_board();

    return 0;
}