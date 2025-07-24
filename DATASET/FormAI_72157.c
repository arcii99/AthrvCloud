//FormAI DATASET v1.0 Category: Checkers Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

char board[8][8] = {{'r',' ','r',' ','r',' ','r',' '},
                    {' ','r',' ','r',' ','r',' ','r'},
                    {'r',' ','r',' ','r',' ','r',' '},
                    {' ',' ',' ',' ',' ',' ',' ',' '},
                    {' ',' ',' ',' ',' ',' ',' ',' '},
                    {' ','b',' ','b',' ','b',' ','b'},
                    {'b',' ','b',' ','b',' ','b',' '},
                    {' ','b',' ','b',' ','b',' ','b'}};

void display_board() {
    int row, col;
    for (row = 0; row < 8; row++) {
        for (col = 0; col < 8; col++) {
            printf("%c", board[row][col]);
            printf(" ");
        }
        printf("\n");
    }
}

int main() {
    int row, col;
    int player = 1;
    int selected_row, selected_col, target_row, target_col;
    while (1) {
        display_board();
        printf("Player %d, enter the row and col of the piece you want to move: ", player);
        scanf("%d %d", &selected_row, &selected_col);
        printf("Enter the row and col of the square you want to move to: ");
        scanf("%d %d", &target_row, &target_col);
        if (board[selected_row][selected_col] == ' ') {
            printf("No piece selected. Try again.\n");
            continue;
        }
        if (player == 1) {
            if (board[selected_row][selected_col] != 'r' && board[selected_row][selected_col] != 'R') {
                printf("You can only move your own pieces. Try again.\n");
                continue;
            }
        } else {
            if (board[selected_row][selected_col] != 'b' && board[selected_row][selected_col] != 'B') {
                printf("You can only move your own pieces. Try again.\n");
                continue;
            }
        }
        if (target_row < 0 || target_row > 7 || target_col < 0 || target_col > 7) {
            printf("Invalid move. Try again.\n");
            continue;
        }
        if (board[target_row][target_col] != ' ') {
            printf("The target square is not empty. Try again.\n");
            continue;
        }
        if (selected_row == target_row) {
            printf("You cannot move to the same square. Try again.\n");
            continue;
        }
        if ((player == 1 && target_row > selected_row) || (player == 2 && target_row < selected_row)) {
            printf("You can only move forward. Try again.\n");
            continue;
        }
        if (abs(selected_row - target_row) != abs(selected_col - target_col)) {
            printf("Invalid move. Try again.\n");
            continue;
        }
        if (board[selected_row][selected_col] == 'r' || board[selected_row][selected_col] == 'b') {
            // normal move
            if (abs(selected_row - target_row) != 1) {
                printf("Invalid move. Try again.\n");
                continue;
            }
            board[target_row][target_col] = board[selected_row][selected_col];
            board[selected_row][selected_col] = ' ';
        } else {
            // jump move
            if (abs(selected_row - target_row) != 2) {
                printf("Invalid move. Try again.\n");
                continue;
            }
            int jumped_row = (selected_row + target_row) / 2;
            int jumped_col = (selected_col + target_col) / 2;
            if (board[jumped_row][jumped_col] == ' ') {
                printf("Invalid move. You can only jump over other pieces. Try again.\n");
                continue;
            } else if ((player == 1 && board[jumped_row][jumped_col] != 'b' && board[jumped_row][jumped_col] != 'B') ||
                       (player == 2 && board[jumped_row][jumped_col] != 'r' && board[jumped_row][jumped_col] != 'R')) {
                printf("Invalid move. You can only jump over your opponent's pieces. Try again.\n");
                continue;
            } else {
                board[target_row][target_col] = board[selected_row][selected_col];
                board[selected_row][selected_col] = ' ';
                board[jumped_row][jumped_col] = ' ';
            }
        }
        if (player == 1) { player = 2; } else { player = 1; }
    }
    return 0;
}