//FormAI DATASET v1.0 Category: Checkers Game ; Style: light-weight
#include <stdio.h>
#include <stdbool.h>

// Constants for board and pieces
#define EMPTY '-'
#define RED 'r'
#define BLACK 'b'
#define KINGRED 'R'
#define KINGBLACK 'B'

// Function to print the board
void print_board(char board[8][8]) {
    printf("\n   A B C D E F G H\n");
    for (int i = 0; i < 8; i++) {
        printf("%d  ", i+1);
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("%d", i+1);
        printf("\n");
    }
    printf("   A B C D E F G H\n\n");
}

// Function to initialize the board
void initialize_board(char board[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0)) {
                if (i < 3)
                    board[i][j] = BLACK;
                else if (i > 4)
                    board[i][j] = RED;
                else
                    board[i][j] = EMPTY;
            }
            else {
                board[i][j] = EMPTY;
            }
        }
    }
}

// Function to check if a move is valid
bool is_valid_move(char board[8][8], int from_row, int from_col, int to_row, int to_col, char player) {
    if (from_row > 7 || from_row < 0 || from_col > 7 || from_col < 0 || to_row > 7 || to_row < 0 || to_col > 7 || to_col < 0)
        return false;
    if (board[from_row][from_col] != player && board[from_row][from_col] != toupper(player))
        return false;
    if (player == RED && board[to_row][to_col] == RED)
        return false;
    if (player == BLACK && board[to_row][to_col] == BLACK)
        return false;

    // Check if the move is diagonal and within range
    int row_diff = to_row - from_row;
    int col_diff = to_col - from_col;
    int abs_row_diff = row_diff >= 0 ? row_diff : -row_diff;
    int abs_col_diff = col_diff >= 0 ? col_diff : -col_diff;
    if (abs_row_diff != abs_col_diff)
        return false;
    if (abs_row_diff > 2)
        return false;
    
    // Check if move is one step only
    if (abs_row_diff == 1) {
        if (board[to_row][to_col] != EMPTY)
            return false;
    }
    else {
        // Check if there is a piece to capture
        int mid_row = (to_row + from_row) / 2;
        int mid_col = (to_col + from_col) / 2;
        if (board[mid_row][mid_col] == EMPTY)
            return false;
        // Check if the capturing is valid
        if (tolower(board[mid_row][mid_col]) == tolower(player))
            return false;
    }

    return true;
}

// Function to check if there are any moves available for a player
bool has_valid_moves(char board[8][8], char player) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == player || board[i][j] == toupper(player)) {
                if (is_valid_move(board, i, j, i+1, j+1, player) || is_valid_move(board, i, j, i+1, j-1, player) ||
                        is_valid_move(board, i, j, i-1, j+1, player) || is_valid_move(board, i, j, i-1, j-1, player))
                    return true;
            }
        }
    }
    return false;
}

// Function to perform a move on the board
void perform_move(char board[8][8], int from_row, int from_col, int to_row, int to_col, char player) {
    board[to_row][to_col] = board[from_row][from_col];
    board[from_row][from_col] = EMPTY;
    if (player == BLACK && to_row == 0)
        board[to_row][to_col] = KINGBLACK;
    else if (player == RED && to_row == 7)
        board[to_row][to_col] = KINGRED;
    else if (board[to_row][to_col] == BLACK && to_row == 7)
        board[to_row][to_col] = KINGBLACK;
    else if (board[to_row][to_col] == RED && to_row == 0)
        board[to_row][to_col] = KINGRED;
    else if (board[from_row][from_col] != board[to_row][to_col] && player == BLACK)
        board[(from_row+to_row)/2][(from_col+to_col)/2] = EMPTY;
    else if (board[from_row][from_col] != board[to_row][to_col] && player == RED)
        board[(from_row+to_row)/2][(from_col+to_col)/2] = EMPTY;
}

int main() {
    char board[8][8];
    char player = RED;
    int from_row, from_col, to_row, to_col;

    initialize_board(board);

    while (true) {
        // Print the board
        print_board(board);

        // Get input from user
        printf("Player %c's turn\n", player);
        printf("\nEnter the coordinates of the piece you want to move: ");
        scanf("%d %d", &from_row, &from_col);
        printf("Enter the coordinates of the square you want to move to: ");
        scanf("%d %d", &to_row, &to_col);

        // Check if move is valid
        if (!is_valid_move(board, from_row-1, from_col-1, to_row-1, to_col-1, player)) {
            printf("\nInvalid move, try again.\n");
        }
        else {
            // Perform the move
            perform_move(board, from_row-1, from_col-1, to_row-1, to_col-1, player);

            // Check for win condition
            if (!has_valid_moves(board, player)) {
                printf("\nPlayer %c wins!\n", player == RED ? BLACK : RED);
                break;
            }

            // Switch player
            if (player == RED)
                player = BLACK;
            else
                player = RED;
        }
    }

    return 0;
}