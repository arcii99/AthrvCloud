//FormAI DATASET v1.0 Category: Checkers Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

void initialize_board() {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if ((i+j)%2 == 0) {
                if (i < 3)
                    board[i][j] = 'R';
                else if (i > 4)
                    board[i][j] = 'B';
                else
                    board[i][j] = ' ';
            }
            else
                board[i][j] = ' ';
        }
    }
}

void print_board() {
    int i, j;
    printf("\n\n   ");
    for (i = 0; i < BOARD_SIZE; i++)
        printf("%d ", i+1);
    printf("\n\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i+1);
        for (j = 0; j < BOARD_SIZE; j++) {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
}

void move_piece(int xi, int yi, int xf, int yf, char player) {
    int x_diff = xf - xi;
    int y_diff = yf - yi;
    if (player == 'R') {
        if ((board[xi][yi] == 'R') || (board[xi][yi] == 'K')) {
            if ((x_diff == 1) && ((y_diff == 1) || (y_diff == -1))) {
                board[xf][yf] = 'R';
                board[xi][yi] = ' ';
            }
            else if ((x_diff == 2) && ((y_diff == 2) || (y_diff == -2))) {
                int x_mid, y_mid;
                x_mid = (xi + xf) / 2;
                y_mid = (yi + yf) / 2;
                if (board[x_mid][y_mid] == 'B') {
                    board[xf][yf] = 'R';
                    board[xi][yi] = ' ';
                    board[x_mid][y_mid] = ' ';
                }
            }
        }
    }
    else if (player == 'B') {
        if ((board[xi][yi] == 'B') || (board[xi][yi] == 'K')) {
            if ((x_diff == -1) && ((y_diff == 1) || (y_diff == -1))) {
                board[xf][yf] = 'B';
                board[xi][yi] = ' ';
            }
            else if ((x_diff == -2) && ((y_diff == 2) || (y_diff == -2))) {
                int x_mid, y_mid;
                x_mid = (xi + xf) / 2;
                y_mid = (yi + yf) / 2;
                if (board[x_mid][y_mid] == 'R') {
                    board[xf][yf] = 'B';
                    board[xi][yi] = ' ';
                    board[x_mid][y_mid] = ' ';
                }
            }
        }
    }
}

void king_me(int xi, int yi, char player) {
    if (player == 'R') {
        if (xi == 0)
            board[xi][yi] = 'K';
    }
    else if (player == 'B') {
        if (xi == BOARD_SIZE - 1)
            board[xi][yi] = 'K';
    }
}

int main() {
    int xi, yi, xf, yf;
    char player = 'R';
    initialize_board();
    print_board();

    while (1) {
        printf("\nIt is player %c's turn.\n", player);
        printf("Enter the x and y coordinates of the piece you want to move: ");
        scanf("%d %d", &xi, &yi);
        printf("Enter the x and y coordinates of the destination: ");
        scanf("%d %d", &xf, &yf);

        move_piece(xi-1, yi-1, xf-1, yf-1, player);
        king_me(xf-1, yf-1, player);
        print_board();

        if (player == 'R')
            player = 'B';
        else if (player == 'B')
            player = 'R';
    }

    return 0;
}