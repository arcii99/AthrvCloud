//FormAI DATASET v1.0 Category: Checkers Game ; Style: multiplayer
#include <stdio.h>

#define BOARD_SIZE 8

void print_board(char board[][BOARD_SIZE])
{
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    char board[BOARD_SIZE][BOARD_SIZE] = { {'r', ' ', 'r', ' ', 'r', ' ', 'r', ' '},
                                            {' ', 'r', ' ', 'r', ' ', 'r', ' ', 'r'},
                                            {'r', ' ', 'r', ' ', 'r', ' ', 'r', ' '},
                                            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                            {' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b'},
                                            {'b', ' ', 'b', ' ', 'b', ' ', 'b', ' '},
                                            {' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b'} };

    print_board(board);

    return 0;
}