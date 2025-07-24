//FormAI DATASET v1.0 Category: Table Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 6
#define COLS 7

// Function prototypes
void display_board(char board[ROWS][COLS]);
int is_valid_move(char board[ROWS][COLS], int col);
int drop_piece(char board[ROWS][COLS], int row, int col, char piece);
int get_player_move(char board[ROWS][COLS], char piece);
int check_win(char board[ROWS][COLS], char piece);
int play_game();

int main() {
    printf("*** WELCOME TO CONNECT FOUR! ***\n\n");

    play_game();

    printf("\nThanks for playing Connect Four!\n");

    return 0;
}

// Displays the current state of the game board
void display_board(char board[ROWS][COLS]) {
    printf("\n\n");

    // Print column numbers
    printf(" ");
    for (int i = 0; i < COLS; i++) {
        printf(" %d", i + 1);
    }
    printf("\n");

    // Print board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf(" %c", board[i][j]);
        }
        printf("\n");
    }
}

// Checks if move is valid (within bounds and not full)
int is_valid_move(char board[ROWS][COLS], int col) {
    return board[0][col] == ' ';
}

// Drops a piece into the board
int drop_piece(char board[ROWS][COLS], int row, int col, char piece) {
    if (board[row][col] != ' ') {
        return -1;
    }

    board[row][col] = piece;
    return 0;
}

// Prompts player for move and drops piece into board
int get_player_move(char board[ROWS][COLS], char piece) {
    int col;

    do {
        printf("Player %c, please enter a column (1-7): ", piece);
        scanf("%d", &col);
        col--;
    } while (col < 0 || col >= COLS || !is_valid_move(board, col));

    // Find the first open cell in the selected column and place a piece
    for (int i = ROWS - 1; i >= 0; i--) {
        if (board[i][col] == ' ') {
            return drop_piece(board, i, col, piece);
        }
    }

    return -1;
}

// Checks if a player has won the game
int check_win(char board[ROWS][COLS], char piece) {
    int row, col;

    // Check vertical
    for (row = 0; row < ROWS - 3; row++) {
        for (col = 0; col < COLS; col++) {
            if (board[row][col] == piece &&
                board[row+1][col] == piece &&
                board[row+2][col] == piece &&
                board[row+3][col] == piece) {
                    return 1;
            }
        }
    }

    // Check horizontal
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS - 3; col++) {
            if (board[row][col] == piece &&
                board[row][col+1] == piece &&
                board[row][col+2] == piece &&
                board[row][col+3] == piece) {
                    return 1;
            }
        }
    }

    // Check diagonal
    for (row = 0; row < ROWS - 3; row++) {
        for (col = 0; col < COLS - 3; col++) {
            if (board[row][col] == piece &&
                board[row+1][col+1] == piece &&
                board[row+2][col+2] == piece &&
                board[row+3][col+3] == piece) {
                    return 1;
            }
        }
    }

    // Check antidiagonal
    for (row = 3; row < ROWS; row++) {
        for (col = 0; col < COLS - 3; col++) {
            if (board[row][col] == piece &&
                board[row-1][col+1] == piece &&
                board[row-2][col+2] == piece &&
                board[row-3][col+3] == piece) {
                    return 1;
            }
        }
    }

    return 0;
}

// Plays a game of Connect Four
int play_game() {
    char board[ROWS][COLS];
    char player_1 = 'X';
    char player_2 = 'O';
    char current_player = ' ';
    int turn = 0;

    // Initialize the game board to all empty spaces
    memset(board, ' ', sizeof(board));

    printf("Press enter to start the game.");
    getchar();

    srand(time(NULL));

    // Randomly choose starting player
    if (rand() % 2 == 0) {
        current_player = player_1;
    } else {
        current_player = player_2;
    }

    while (1) {
        display_board(board);

        if (current_player == player_1) {
            if (get_player_move(board, current_player) < 0) {
                printf("Invalid move! Try again.\n");
                continue;
            }
        } else {
            int col = rand() % COLS;

            while (!is_valid_move(board, col)) {
                col = rand() % COLS;
            }

            printf("Computer chooses column %d.\n", col + 1);

            drop_piece(board, ROWS - 1, col, current_player);
        }

        if (check_win(board, current_player)) {
            display_board(board);
            printf("Player %c wins!\n", current_player);
            return 0;
        }

        turn++;

        // Check for a tie
        if (turn >= ROWS * COLS) {
            display_board(board);
            printf("The game is a tie!\n");
            return 0;
        }

        // Switch players
        if (current_player == player_1) {
            current_player = player_2;
        } else {
            current_player = player_1;
        }
    }
}