//FormAI DATASET v1.0 Category: Checkers Game ; Style: Alan Touring
#include <stdio.h>
#define BOARD_SIZE 8

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE] = {{'_', 'w', '_', 'w', '_', 'w', '_', 'w'},
                                          {'w', '_', 'w', '_', 'w', '_', 'w', '_'},
                                          {'_', 'w', '_', 'w', '_', 'w', '_', 'w'},
                                          {'_', '_', '_', '_', '_', '_', '_', '_'},
                                          {'_', '_', '_', '_', '_', '_', '_', '_'},
                                          {'b', '_', 'b', '_', 'b', '_', 'b', '_'},
                                          {'_', 'b', '_', 'b', '_', 'b', '_', 'b'},
                                          {'b', '_', 'b', '_', 'b', '_', 'b', '_'}};

    print_board(board);
    return 0;
}