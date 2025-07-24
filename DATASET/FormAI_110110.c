//FormAI DATASET v1.0 Category: Checkers Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// function prototypes
void init_board(char board[BOARD_SIZE][BOARD_SIZE]);
void print_board(char board[BOARD_SIZE][BOARD_SIZE]);
int move_piece(char board[BOARD_SIZE][BOARD_SIZE], int player, int row_from, int col_from, int row_to, int col_to);
int player_has_moves_left(char board[BOARD_SIZE][BOARD_SIZE], int player);
int get_opponent(int player);

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    init_board(board);
    print_board(board);

    int player = 1; // player 1 is the human player, player 2 is the computer
    int game_over = 0;

    while (!game_over) {
        printf("Player %d's turn\n", player);

        // get move from player
        int row_from, col_from, row_to, col_to;
        printf("Enter move (from row, from col, to row, to col): ");
        scanf("%d%d%d%d", &row_from, &col_from, &row_to, &col_to);

        // attempt to move piece, check for errors
        int move_successful = move_piece(board, player, row_from, col_from, row_to, col_to);
        if (!move_successful) {
            printf("Invalid move, try again.\n");
            continue;
        }

        print_board(board);

        // check for win or draw
        if (!player_has_moves_left(board, player)) {
            printf("Player %d has no moves left, game over\n", player);
            game_over = 1;
            continue;
        }

        if (player_has_moves_left(board, get_opponent(player))) {
            // switch to next player
            player = get_opponent(player);
        } else {
            // opponent has no moves left, player wins
            printf("Player %d wins!\n", player);
            game_over = 1;
        }
    }

    return 0;
}

void init_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    // initialize board to starting position
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                if (i < 3) {
                    board[i][j] = 'X'; // player 1's pieces
                } else if (i > 4) {
                    board[i][j] = 'O'; // player 2's pieces
                } else {
                    board[i][j] = ' '; // empty square
                }
            } else {
                board[i][j] = ' '; // empty square
            }
        }
    }
}

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    // print header row of column numbers
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");

    // print rows with board contents
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("%d\n", i); // print row number again at end of row
    }

    // print footer row of column numbers
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

int move_piece(char board[BOARD_SIZE][BOARD_SIZE], int player, int row_from, int col_from, int row_to, int col_to) {
    // check if player is moving their own piece
    if (board[row_from][col_from] == 'X' && player != 1) return 0;
    if (board[row_from][col_from] == 'O' && player != 2) return 0;

    // check if destination square is occupied
    if (board[row_to][col_to] != ' ') return 0;

    // check if piece is only moving one space diagonally
    int row_diff = row_to - row_from;
    int col_diff = col_to - col_from;
    if (abs(row_diff) != 1 || abs(col_diff) != 1) return 0;

    // move piece
    board[row_to][col_to] = board[row_from][col_from];
    board[row_from][col_from] = ' ';

    return 1;
}

int player_has_moves_left(char board[BOARD_SIZE][BOARD_SIZE], int player) {
    // check if any of player's pieces can move
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 'X' && player == 1) {
                // check if piece can move diagonally to the left or right
                if (i < BOARD_SIZE - 1 && j > 0 && board[i+1][j-1] == ' ') return 1;
                if (i < BOARD_SIZE - 1 && j < BOARD_SIZE - 1 && board[i+1][j+1] == ' ') return 1;
            } else if (board[i][j] == 'O' && player == 2) {
                // check if piece can move diagonally to the left or right
                if (i > 0 && j > 0 && board[i-1][j-1] == ' ') return 1;
                if (i > 0 && j < BOARD_SIZE - 1 && board[i-1][j+1] == ' ') return 1;
            }
        }
    }

    return 0;
}

int get_opponent(int player) {
    return player == 1 ? 2 : 1;
}