//FormAI DATASET v1.0 Category: Checkers Game ; Style: lively
#include <stdio.h>

// global variables for board size and pieces
#define BOARD_SIZE 8
#define PLAYER_ONE 'x'
#define PLAYER_TWO 'o'

// function to initialize board
void initialize_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                if (i < 3) {
                    board[i][j] = PLAYER_ONE;
                } else if (i > 4) {
                    board[i][j] = PLAYER_TWO;
                } else {
                    board[i][j] = ' ';
                }
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

// function to print the board
void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf(" %d ", i);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("|%c|", board[i][j]);
        }
        printf("\n");
    }
}

// function to check if a move is valid
int is_valid_move(char board[BOARD_SIZE][BOARD_SIZE], int row, int col, int new_row, int new_col, char player) {
    // check if new position is within board boundaries
    if (new_row >= BOARD_SIZE || new_col >= BOARD_SIZE || new_row < 0 || new_col < 0) {
        return 0;
    }

    // check if new position is empty
    if (board[new_row][new_col] != ' ') {
        return 0;
    }

    // check if player is moving their own piece
    if (player == PLAYER_ONE && board[row][col] != PLAYER_ONE && board[row][col] != 'X') {
        return 0;
    } else if (player == PLAYER_TWO && board[row][col] != PLAYER_TWO && board[row][col] != 'O') {
        return 0;
    }

    // check if move direction is valid
    if (player == PLAYER_ONE) {
        if (new_row > row || abs(new_col - col) != 1) {
            return 0;
        }
    } else {
        if (new_row < row || abs(new_col - col) != 1) {
            return 0;
        }
    }

    return 1;
}

// function to check if there are any valid moves left for a player
int valid_moves_left(char board[BOARD_SIZE][BOARD_SIZE], char player) {
    int count = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (player == PLAYER_ONE && (board[i][j] == PLAYER_ONE || board[i][j] == 'X')) {
                if (is_valid_move(board, i, j, i+1, j-1, player) || is_valid_move(board, i, j, i+1, j+1, player)) {
                    count++;
                }
            } else if (player == PLAYER_TWO && (board[i][j] == PLAYER_TWO || board[i][j] == 'O')) {
                if (is_valid_move(board, i, j, i-1, j-1, player) || is_valid_move(board, i, j, i-1, j+1, player)) {
                    count++;
                }
            }
        }
    }

    if (count > 0) {
        return 1;
    } else {
        return 0;
    }
}

// function to make a move
void make_move(char board[BOARD_SIZE][BOARD_SIZE], int row, int col, int new_row, int new_col, char player) {
    board[new_row][new_col] = board[row][col];

    if (player == PLAYER_ONE && new_row == BOARD_SIZE - 1) {
        board[new_row][new_col] = 'X';
    } else if (player == PLAYER_TWO && new_row == 0) {
        board[new_row][new_col] = 'O';
    }

    board[row][col] = ' ';

    if (abs(new_row - row) == 2 && abs(new_col - col) == 2) {
        board[(new_row+row)/2][(new_col+col)/2] = ' ';
    }
}

// function to check if there is a winner
char get_winner(char board[BOARD_SIZE][BOARD_SIZE]) {
    int player_one_count = 0;
    int player_two_count = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == PLAYER_ONE || board[i][j] == 'X') {
                player_one_count++;
            } else if (board[i][j] == PLAYER_TWO || board[i][j] == 'O') {
                player_two_count++;
            }
        }
    }

    if (player_one_count == 0) {
        return PLAYER_TWO;
    } else if (player_two_count == 0) {
        return PLAYER_ONE;
    } else {
        return ' ';
    }
}

// main function
int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int row, col, new_row, new_col;
    char player = PLAYER_ONE;
    char winner = ' ';

    initialize_board(board);

    printf("Welcome to Checkers!\n");
    printf("Player %c goes first.\n", player);

    while (winner == ' ') {
        print_board(board);

        int valid_move = 0;
        while (!valid_move) {
            printf("Player %c, enter the row and column of the piece you want to move: ", player);
            scanf("%d %d", &row, &col);
            printf("Enter the row and column of the position you want to move to: ");
            scanf("%d %d", &new_row, &new_col);

            if (is_valid_move(board, row, col, new_row, new_col, player)) {
                make_move(board, row, col, new_row, new_col, player);
                valid_move = 1;
            } else {
                printf("Invalid move, please try again.\n");
            }
        }

        if (player == PLAYER_ONE) {
            player = PLAYER_TWO;
        } else {
            player = PLAYER_ONE;
        }

        if (!valid_moves_left(board, player)) {
            winner = get_winner(board);
        }
    }

    print_board(board);
    printf("Player %c wins!\n", winner);

    return 0;
}