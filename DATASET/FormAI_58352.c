//FormAI DATASET v1.0 Category: Checkers Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BLACK 1
#define WHITE 2
#define SIZE 8

// Function to display board
void display_board(char board[SIZE][SIZE]) {
    printf("    1   2   3   4   5   6   7   8\n");
    printf("  +---+---+---+---+---+---+---+---+\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%c ", 'A' + i);
        for (int j = 0; j < SIZE; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
        printf("  +---+---+---+---+---+---+---+---+\n");
    }
}

// Function to check if move is valid
int is_valid_move(char board[SIZE][SIZE], int player, int cur_row, int cur_col, int new_row, int new_col) {
    int row_diff = new_row - cur_row;
    int col_diff = new_col - cur_col;
    int abs_row_diff = abs(row_diff);
    int abs_col_diff = abs(col_diff);

    // Check if piece exists
    if (board[cur_row][cur_col] == ' ') {
        return 0;
    }

    // Check if new position is empty
    if (board[new_row][new_col] != ' ') {
        return 0;
    }

    // Check if move is diagonal
    if (abs_row_diff != abs_col_diff) {
        return 0;
    }

    // Check if move direction is correct
    if (player == BLACK && row_diff < 0) {
        return 0;
    }
    else if (player == WHITE && row_diff > 0) {
        return 0;
    }

    // Check if move is within one row
    if (abs_row_diff > 2) {
        return 0;
    }

    // Check if move is in the correct direction
    if (abs_row_diff == 1 && abs_col_diff == 1) {
        // Normal move
        return 1;
    }
    else if (abs_row_diff == 2 && abs_col_diff == 2) {
        // Check for jump
        int jumped_row = cur_row + row_diff / 2;
        int jumped_col = cur_col + col_diff / 2;
        if (board[jumped_row][jumped_col] == ' ') {
            return 0;
        }
        else if (player == BLACK && board[jumped_row][jumped_col] != 'W') {
            return 0;
        }
        else if (player == WHITE && board[jumped_row][jumped_col] != 'B') {
            return 0;
        }
        else {
            return 2;
        }
    }
    else {
        return 0;
    }
}

// Function to check if move is capturing move
int is_capturing_move(char board[SIZE][SIZE], int player) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == (player == BLACK ? 'b' : 'w')) {
                if (is_valid_move(board, player, i, j, i+2, j+2) || is_valid_move(board, player, i, j, i-2, j+2) 
                    ||is_valid_move(board, player, i, j, i+2, j-2) || is_valid_move(board, player, i, j, i-2, j-2)) {
                    return 1;
                }
            }
            else if (board[i][j] == (player == BLACK ? 'B' : 'W')) {
                if (is_valid_move(board, player, i, j, i+2, j+2) || is_valid_move(board, player, i, j, i-2, j+2) 
                    ||is_valid_move(board, player, i, j, i+2, j-2) || is_valid_move(board, player, i, j, i-2, j-2)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

// Function to make move
void make_move(char board[SIZE][SIZE], int player, int cur_row, int cur_col, int new_row, int new_col, int capture) {
    board[new_row][new_col] = board[cur_row][cur_col];
    board[cur_row][cur_col] = ' ';

    // Check for capturing move
    if (capture) {
        int jumped_row = cur_row + (new_row - cur_row) / 2;
        int jumped_col = cur_col + (new_col - cur_col) / 2;
        board[jumped_row][jumped_col] = ' ';
    }

    // Make piece a king if it reaches last row
    if (new_row == 0 && player == BLACK) {
        board[new_row][new_col] = 'B';
    }
    else if (new_row == SIZE-1 && player == WHITE) {
        board[new_row][new_col] = 'W';
    }
}

// Function to get user input
int get_input(int *cur_row, int *cur_col, int *new_row, int *new_col) {
    int valid_input = 0;
    char cur_pos[3], new_pos[3];
    while (!valid_input) {
        printf("\nEnter current position: ");
        scanf("%2s", cur_pos);
        getchar();
        printf("Enter new position: ");
        scanf("%2s", new_pos);
        getchar();

        // Check if input is valid
        if (isalpha(cur_pos[0]) && isdigit(cur_pos[1]) && isalpha(new_pos[0]) && isdigit(new_pos[1])) {
            *cur_row = toupper(cur_pos[0]) - 'A';
            *cur_col = cur_pos[1] - '1';
            *new_row = toupper(new_pos[0]) - 'A';
            *new_col = new_pos[1] - '1';
            valid_input = 1;
        }
        else {
            printf("Invalid input!\n");
        }
    }
    return 1;
}

int main() {
    char board[SIZE][SIZE] = {
        {' ', 'w', ' ', 'w', ' ', 'w', ' ', 'w'},
        {'w', ' ', 'w', ' ', 'w', ' ', 'w', ' '},
        {' ', 'w', ' ', 'w', ' ', 'w', ' ', 'w'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'b', ' ', 'b', ' ', 'b', ' ', 'b', ' '},
        {' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b'},
        {'b', ' ', 'b', ' ', 'b', ' ', 'b', ' '}
    };
    int player = BLACK;
    int game_over = 0;

    printf("Welcome to Retro Checkers!\n");
    display_board(board);

    while (!game_over) {
        // Get user input
        int valid_input = 0;
        int cur_row, cur_col, new_row, new_col;
        while (!valid_input) {
            printf("\n%s's turn.\n", player == BLACK ? "Black" : "White");
            get_input(&cur_row, &cur_col, &new_row, &new_col);
            // Check if move is valid
            int capture = is_valid_move(board, player, cur_row, cur_col, new_row, new_col);
            if (capture) {
                make_move(board, player, cur_row, cur_col, new_row, new_col, capture == 2 ? 1 : 0);
                if (!is_capturing_move(board, player)) {
                    valid_input = 1;
                }
                // Check if player wins
                if (!is_capturing_move(board, player == BLACK ? WHITE : BLACK)) {
                    printf("\n%s has won the game!\n", player == BLACK ? "Black" : "White");
                    game_over = 1;
                }
            }
            else {
                printf("Invalid move!\n");
            }
        }
        display_board(board);

        // Switch player
        player = player == BLACK ? WHITE : BLACK;
    }

    return 0;
}