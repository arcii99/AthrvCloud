//FormAI DATASET v1.0 Category: Checkers Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

void reset_board(char board[][SIZE]) {
    int x, y;
    for (y = 0; y < SIZE; y++) {
        for (x = 0; x < SIZE; x++) {
            if (y < 3 && (x + y) % 2 == 1) {
                board[x][y] = 'W';
            } else if (y > 4 && (x + y) % 2 == 1) {
                board[x][y] = 'B';
            } else {
                board[x][y] = '.';
            }
        }
    }
}

void print_board(char board[][SIZE]) {
    int x, y;
    printf("  A B C D E F G H\n");
    for (y = 0; y < SIZE; y++) {
        printf("%d ", y + 1);
        for (x = 0; x < SIZE; x++) {
            printf("%c ", board[x][y]);
        }
        printf("%d", y + 1);
        printf("\n");
    }
    printf("  A B C D E F G H\n");
}

int main() {
    char board[SIZE][SIZE];
    reset_board(board);
    print_board(board);
    return 0;
}