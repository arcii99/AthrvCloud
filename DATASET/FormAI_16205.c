//FormAI DATASET v1.0 Category: Checkers Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// global variables
int board[BOARD_SIZE][BOARD_SIZE] = {0};
int player = 1;
int pieces_remaining[3] = {12, 12, 0};

// function prototypes
void initialize_board();
void print_board();
int move_piece(int row, int col, int new_row, int new_col);
int num_opponent_pieces_remaining();
int is_game_over();

// main function
int main() {
    initialize_board();
    printf("Welcome to C Checkers Game!\n");
    printf("Player 1 starts the game.\n");

    int row, col, new_row, new_col;
    int valid_move = 0;
    while (!is_game_over()) {
        // keep asking for move until a valid move is made
        while (!valid_move) {
            printf("Player %d's turn.\n", player);
            printf("Enter the row and column of the piece to move (e.g. 3 4): ");
            scanf("%d %d", &row, &col);
            printf("Enter the row and column where the piece will go (e.g. 4 5): ");
            scanf("%d %d", &new_row, &new_col);

            // validate move
            valid_move = move_piece(row, col, new_row, new_col);
            if (!valid_move) {
                printf("Invalid move! Please try again.\n");
            }
        }

        // print board and reset valid_move
        print_board();
        valid_move = 0;

        // switch player
        player = player == 1 ? 2 : 1;
    }

    // print winner
    printf("Game over! Player %d wins!\n", player);

    return 0;
}

// initialize the board with pieces
void initialize_board() {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if ((row + col) % 2 == 1) {
                if (row < 3) {
                    board[row][col] = 1;
                } else if (row > 4) {
                    board[row][col] = 2;
                }
            }
        }
    }
}

// print the current game board
void print_board() {
    printf("\n  ");
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf("%d ", col + 1);
    }
    printf("\n");

    for (int row = 0; row < BOARD_SIZE; row++) {
        printf("%c ", 'A' + row);
        for (int col = 0; col < BOARD_SIZE; col++) {
            switch (board[row][col]) {
                case 0:
                    printf(". ");
                    break;
                case 1:
                    printf("x ");
                    break;
                case 2:
                    printf("o ");
                    break;
                case 3:
                    printf("X ");
                    break;
                case 4:
                    printf("O ");
                    break;
            }
        }
        printf("\n");
    }

    printf("\nPlayer 1: %d pieces remaining\n", pieces_remaining[1]);
    printf("Player 2: %d pieces remaining\n\n", pieces_remaining[2]);
}

// move a piece from (row, col) to (new_row, new_col)
// returns 1 if move is valid, 0 otherwise
int move_piece(int row, int col, int new_row, int new_col) {
    // check if the piece exists
    if (board[row][col] == 0 || board[row][col] == 3 || board[row][col] == 4) {
        return 0;
    }

    // check if the destination is out of bounds or occupied
    if (new_row < 0 || new_row >= BOARD_SIZE || new_col < 0 || new_col >= BOARD_SIZE || board[new_row][new_col] != 0) {
        return 0;
    }

    // check if the move is valid for the player's color
    int dy = new_row - row;
    int dx = new_col - col;
    if (player == 1) {
        if (board[row][col] == 1) {
            if (dy != 1 || abs(dx) != 1) {
                return 0;
            }
        } else {
            if ((dy != 1 && dy != -1) || (dx != 1 && dx != -1)) {
                return 0;
            }
        }
    } else {
        if (board[row][col] == 2) {
            if (dy != -1 || abs(dx) != 1) {
                return 0;
            }
        } else {
            if ((dy != 1 && dy != -1) || (dx != 1 && dx != -1)) {
                return 0;
            }
        }
    }

    // perform the move
    board[new_row][new_col] = board[row][col];
    board[row][col] = 0;

    // check for a jump move
    if (abs(dy) == 2 && abs(dx) == 2) {
        int jumped_row = row + dy / 2;
        int jumped_col = col + dx / 2;
        if (board[jumped_row][jumped_col] != (player == 1 ? 2 : 1)) {
            return 0;
        }

        // remove the opponent's piece
        board[jumped_row][jumped_col] = 0;
        pieces_remaining[player == 1 ? 2 : 1]--;
    }

    // check if the piece needs to be kinged
    if ((player == 1 && new_row == BOARD_SIZE - 1) || (player == 2 && new_row == 0)) {
        if (board[new_row][new_col] == 1) {
            board[new_row][new_col] = 3;
        } else if (board[new_row][new_col] == 2) {
            board[new_row][new_col] = 4;
        }
    }

    // decrement the player's pieces_remaining count
    pieces_remaining[player]--;

    return 1;
}

// count the number of opponent's pieces remaining
int num_opponent_pieces_remaining() {
    if (player == 1) {
        return pieces_remaining[2];
    } else {
        return pieces_remaining[1];
    }
}

// check if the game is over
int is_game_over() {
    if (pieces_remaining[1] == 0 || pieces_remaining[2] == 0) {
        return 1;
    }

    // check if any piece can move
    int can_move = 0;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] != 0 && board[row][col] != 3 && board[row][col] != 4) {
                for (int drow = -2; drow <= 2; drow++) {
                    for (int dcol = -2; dcol <= 2; dcol++) {
                        if (drow != 0 && dcol != 0 && abs(drow) == abs(dcol)) {
                            int new_row = row + drow;
                            int new_col = col + dcol;
                            if (new_row >= 0 && new_row < BOARD_SIZE && new_col >= 0 && new_col < BOARD_SIZE && board[new_row][new_col] == 0) {
                                can_move = 1;
                                break;
                            }
                        }
                    }
                    if (can_move) {
                        break;
                    }
                }
            }
            if (can_move) {
                break;
            }
        }
        if (can_move) {
            break;
        }
    }

    return !can_move;
}