//FormAI DATASET v1.0 Category: Checkers Game ; Style: Donald Knuth
#include <stdio.h>

#define BOARD_SIZE 8
#define EMPTY ' '
#define PLAYER_1 'X'
#define PLAYER_2 'O'

char board[BOARD_SIZE][BOARD_SIZE];

void init_board() {
    // initialize the board with empty spaces
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void print_board() {
    // print the current state of the board
    printf("     0   1   2   3   4   5   6   7\n");
    printf("   +---+---+---+---+---+---+---+---+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf(" %d |", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n");
        printf("   +---+---+---+---+---+---+---+---+\n");
    }
}

int is_valid_move(int row, int col) {
    // check if the move is valid for the current player
    char player = (board[row][col] == PLAYER_1) ? PLAYER_1 : PLAYER_2;
    if (player == PLAYER_1) {
        if (row < BOARD_SIZE - 1 && col > 0) {
            // check for jumps
            if (board[row+1][col-1] == PLAYER_2 && board[row+2][col-2] == EMPTY) {
                return 1;
            }
        }
        if (row < BOARD_SIZE - 1 && col < BOARD_SIZE - 1) {
            // check for jumps
            if (board[row+1][col+1] == PLAYER_2 && board[row+2][col+2] == EMPTY) {
                return 1;
            }
        }
        if (row < BOARD_SIZE - 1) {
            // check for regular move
            if (board[row+1][col] == EMPTY) {
                return 1;
            }
        }
        if (row == BOARD_SIZE - 2 && col > 0) {
            // check for regular move to become king
            if (board[row+1][col-1] == PLAYER_2 && board[row+2][col-2] == EMPTY) {
                return 1;
            }
        }
        if (row == BOARD_SIZE - 2 && col < BOARD_SIZE - 1) {
            // check for regular move to become king
            if (board[row+1][col+1] == PLAYER_2 && board[row+2][col+2] == EMPTY) {
                return 1;
            }
        }
    } else {
        if (row > 0 && col > 0) {
            // check for jumps
            if (board[row-1][col-1] == PLAYER_1 && board[row-2][col-2] == EMPTY) {
                return 1;
            }
        }
        if (row > 0 && col < BOARD_SIZE - 1) {
            // check for jumps
            if (board[row-1][col+1] == PLAYER_1 && board[row-2][col+2] == EMPTY) {
                return 1;
            }
        }
        if (row > 0) {
            // check for regular move
            if (board[row-1][col] == EMPTY) {
                return 1;
            }
        }
        if (row == 1 && col > 0) {
            // check for regular move to become king
            if (board[row-1][col-1] == PLAYER_1 && board[row-2][col-2] == EMPTY) {
                return 1;
            }
        }
        if (row == 1 && col < BOARD_SIZE - 1) {
            // check for regular move to become king
            if (board[row-1][col+1] == PLAYER_1 && board[row-2][col+2] == EMPTY) {
                return 1;
            }
        }
    }
    return 0;
}

void make_move(int row, int col) {
    // make the move on the board
    char player = (board[row][col] == PLAYER_1) ? PLAYER_1 : PLAYER_2;
    board[row][col] = EMPTY;
    if (player == PLAYER_1) {
        if (row < BOARD_SIZE - 1 && col > 0) {
            // remove opponent and move
            if (board[row+1][col-1] == PLAYER_2 && board[row+2][col-2] == EMPTY) {
                board[row+1][col-1] = EMPTY;
                board[row+2][col-2] = PLAYER_1;
                return;
            }
        }
        if (row < BOARD_SIZE - 1 && col < BOARD_SIZE - 1) {
            // remove opponent and move
            if (board[row+1][col+1] == PLAYER_2 && board[row+2][col+2] == EMPTY) {
                board[row+1][col+1] = EMPTY;
                board[row+2][col+2] = PLAYER_1;
                return;
            }
        }
        if (row < BOARD_SIZE - 1) {
            // regular move
            board[row+1][col] = PLAYER_1;
            if (row + 1 == BOARD_SIZE - 1) {
                // check for promotion to king
                board[row+1][col] = 'K';
            }
            return;
        }
    } else {
        if (row > 0 && col > 0) {
            // remove opponent and move
            if (board[row-1][col-1] == PLAYER_1 && board[row-2][col-2] == EMPTY) {
                board[row-1][col-1] = EMPTY;
                board[row-2][col-2] = PLAYER_2;
                return;
            }
        }
        if (row > 0 && col < BOARD_SIZE - 1) {
            // remove opponent and move
            if (board[row-1][col+1] == PLAYER_1 && board[row-2][col+2] == EMPTY) {
                board[row-1][col+1] = EMPTY;
                board[row-2][col+2] = PLAYER_2;
                return;
            }
        }
        if (row > 0) {
            // regular move
            board[row-1][col] = PLAYER_2;
            if (row - 1 == 0) {
                // check for promotion to king
                board[row-1][col] = 'K';
            }
            return;
        }
    }
}

int main() {
    init_board();
    int player = 1;
    while (1) {
        print_board();
        printf("Player %d's turn\n", player);
        int row, col;
        printf("Enter row: ");
        scanf("%d", &row);
        printf("Enter col: ");
        scanf("%d", &col);
        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] == EMPTY || !is_valid_move(row, col)) {
            printf("Invalid move\n");
            continue;
        }
        make_move(row, col);
        if (player == 1) {
            player = 2;
        } else {
            player = 1;
        }
        int p1_count = 0, p2_count = 0;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == PLAYER_1 || board[i][j] == 'K') {
                    p1_count++;
                } else if (board[i][j] == PLAYER_2 || board[i][j] == 'Q') {
                    p2_count++;
                }
            }
        }
        if (p1_count == 0) {
            printf("Player 2 wins!\n");
            break;
        }
        if (p2_count == 0) {
            printf("Player 1 wins!\n");
            break;
        }
    }
    return 0;
}