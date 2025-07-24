//FormAI DATASET v1.0 Category: Checkers Game ; Style: decentralized
#include <stdio.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

// initializes the board with starting positions of the pieces
void init_board() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                if (i < 3)
                    board[i][j] = 'r';
                else if (i > 4)
                    board[i][j] = 'b';
                else
                    board[i][j] = ' ';
            }
            else {
                board[i][j] = ' ';
            }
        }
    }
}

// prints the current state of the board
void print_board() {
    int i, j;
    printf("   0 1 2 3 4 5 6 7\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("|%c", board[i][j]);
        }
        printf("|\n");
    }
}

// checks if there are any valid moves for player 'player'
int valid_moves(char player) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == player) {
                if (i < BOARD_SIZE - 1 && (j > 0 && board[i + 1][j - 1] == ' '))
                    return 1;
                if (i < BOARD_SIZE - 1 && (j < BOARD_SIZE - 1 && board[i + 1][j + 1] == ' '))
                    return 1;
                if (i > 0 && (j > 0 && board[i - 1][j - 1] == ' ') && board[i][j] == 'b')
                    return 1;
                if (i > 0 && (j < BOARD_SIZE - 1 && board[i - 1][j + 1] == ' ') && board[i][j] == 'b')
                    return 1;
            }
        }
    }
    return 0;
}

// makes the move if it is valid
void make_move(int r1, int c1, int r2, int c2) {
    if (board[r2][c2] == ' ')
        board[r2][c2] = board[r1][c1];
    else
        printf("Invalid move!");
    board[r1][c1] = ' ';
}

int main() {
    int game_over = 0;
    char player = 'r';
    init_board();
    while (!game_over) {
        print_board();
        if (!valid_moves(player)) {
            printf("Player %c has no valid moves!\n", player);
            if (player == 'r')
                player = 'b';
            else
                player = 'r';
            if (!valid_moves(player)) {
                printf("Game over!\n");
                game_over = 1;
                break;
            }
        }

        int r1, c1, r2, c2;
        printf("Player %c, enter move (row of piece, column of piece, row of destination, column of destination): ", player);
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        if (r1 < 0 || r2 < 0 || c1 < 0 || c2 < 0 || r1 >= BOARD_SIZE || r2 >= BOARD_SIZE || c1 >= BOARD_SIZE || c2 >= BOARD_SIZE) {
            printf("Invalid move!\n");
            continue;
        }
        if (board[r1][c1] != player) {
            printf("Invalid move!\n");
            continue;
        }
        if (player == 'r' && r2 < r1) {
            printf("Invalid move!\n");
            continue;
        }
        if (player == 'b' && r2 > r1) {
            printf("Invalid move!\n");
            continue;
        }
        int dr = r2 - r1;
        int dc = c2 - c1;
        if (board[r1][c1] == 'r' && (dr != 1 || (dc != 1 && dc != -1))) {
            printf("Invalid move!\n");
            continue;
        }
        if (board[r1][c1] == 'b' && (dr != -1 || (dc != 1 && dc != -1))) {
            printf("Invalid move!\n");
            continue;
        }
        make_move(r1, c1, r2, c2);
        if (player == 'r')
            player = 'b';
        else
            player = 'r';
    }
    return 0;
}