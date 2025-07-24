//FormAI DATASET v1.0 Category: Checkers Game ; Style: realistic
#include <stdio.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE] = {
    {'_', 'b', '_', 'b', '_', 'b', '_', 'b'},
    {'b', '_', 'b', '_', 'b', '_', 'b', '_'},
    {'_', 'b', '_', 'b', '_', 'b', '_', 'b'},
    {'_', '_', '_', '_', '_', '_', '_', '_'},
    {'_', '_', '_', '_', '_', '_', '_', '_'},
    {'w', '_', 'w', '_', 'w', '_', 'w', '_'},
    {'_', 'w', '_', 'w', '_', 'w', '_', 'w'},
    {'w', '_', 'w', '_', 'w', '_', 'w', '_'}
};

void print_board() {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("%d\n", i + 1);
    }
    printf("  a b c d e f g h\n");
}

void move_piece(int row1, int col1, int row2, int col2) {
    board[row2][col2] = board[row1][col1];
    board[row1][col1] = '_';
}

int main() {
    printf("Welcome to my Checkers game!\n\n");
    
    print_board();
    
    move_piece(5, 0, 4, 1);
    
    print_board();
    
    return 0;
}