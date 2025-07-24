//FormAI DATASET v1.0 Category: Checkers Game ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// Function to print the current state of the board
void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    printf("Current board state:\n");
    printf("   0 1 2 3 4 5 6 7\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d  ", i);
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to initialize the board
void initialize_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0 && i < 3) {
                board[i][j] = 'b'; // black player
            } else if ((i + j) % 2 == 0 && i > 4) {
                board[i][j] = 'w'; // white player
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

// Function to move a piece on the board
int move_piece(char board[BOARD_SIZE][BOARD_SIZE], int x1, int y1, int x2, int y2) {
    if (board[x2][y2] != ' ') { // illegal move - target cell is not empty
        return 0;
    }

    if (abs(x2 - x1) == 1 && abs(y2 - y1) == 1 && board[x1][y1] != 'B' && board[x1][y1] != 'W') { // regular move for non-king piece
        board[x2][y2] = board[x1][y1];
        board[x1][y1] = ' ';
        return 1;
    } else if (abs(x2 - x1) == 2 && abs(y2 - y1) == 2 && board[x2 - (x2 - x1)/2][y2 - (y2 - y1)/2] != ' ' && ((board[x1][y1] == 'w' && board[x2 - (x2 - x1)/2][y2 - (y2 - y1)/2] == 'b') || (board[x1][y1] == 'b' && board[x2 - (x2 - x1)/2][y2 - (y2 - y1)/2] == 'w'))) { // capture move
        board[x2][y2] = board[x1][y1];
        board[x1][y1] = ' ';
        board[x2 - (x2 - x1)/2][y2 - (y2 - y1)/2] = ' ';
        return 1;
    } else if (abs(x2 - x1) == 1 && abs(y2 - y1) == 1 && (board[x1][y1] == 'B' || board[x1][y1] == 'W')) { // regular move for king piece
        board[x2][y2] = board[x1][y1];
        board[x1][y1] = ' ';
        return 1;
    } else if (abs(x2 - x1) == 2 && abs(y2 - y1) == 2 && 
                board[x2 - (x2 - x1)/2][y2 - (y2 - y1)/2] != ' ' && 
                ((board[x1][y1] == 'W' && board[x2 - (x2 - x1)/2][y2 - (y2 - y1)/2] == 'B') || 
                (board[x1][y1] == 'B' && board[x2 - (x2 - x1)/2][y2 - (y2 - y1)/2] == 'W'))) { // capture move for king piece
        board[x2][y2] = board[x1][y1];
        board[x1][y1] = ' ';
        board[x2 - (x2 - x1)/2][y2 - (y2 - y1)/2] = ' ';
        return 1;
    }

    return 0; // illegal move
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int player = 1, x1, y1, x2, y2, valid_move;
    initialize_board(board);
    print_board(board);

    while (1) {
        printf("Player %d's turn: \n", player);
        printf("Enter the coordinates of the piece you want to move (x y): ");
        scanf("%d %d", &x1, &y1);
        printf("Enter the coordinates of the cell you want to move to (x y): ");
        scanf("%d %d", &x2, &y2);

        valid_move = move_piece(board, x1, y1, x2, y2);

        if (!valid_move) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        print_board(board);

        if (player == 1) {
            player = 2;
        } else {
            player = 1;
        }
    }

    return 0;
}