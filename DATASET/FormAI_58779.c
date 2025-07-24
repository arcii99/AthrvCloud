//FormAI DATASET v1.0 Category: Checkers Game ; Style: Claude Shannon
#include <stdio.h>
#include <ctype.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE]; // 2D character array for board

// Function to initialize the board with starting pieces
void initialize_board() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if ((i+j)%2 == 0 && i < 3) // place black pieces
                board[i][j] = 'B';
            else if ((i+j)%2 == 0 && i > 4) // place red pieces
                board[i][j] = 'R';
            else // empty squares
                board[i][j] = ' ';
        }
    }
}

// Function to print the current board
void print_board() {
    int i, j;
    printf("  0 1 2 3 4 5 6 7\n"); // column numbers
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i); // row number
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n"); // proceed to next line
    }
}

// Function to check if move is within board bounds
int is_within_bounds(int row, int col) {
    if (row < 0 || col < 0 || row >= BOARD_SIZE || col >= BOARD_SIZE)
        return 0; // out of bounds
    else
        return 1; // within bounds
}

// Function to check if piece is owned by current player
int is_own_piece(char piece, int player) {
    if (player == 1 && (piece == 'R' || piece == 'K'))
        return 1;
    else if (player == 2 && (piece == 'B' || piece == 'Q'))
        return 1;
    else
        return 0; // not owned by player
}

// Function to check if move is valid
int is_valid_move(int player, int curr_row, int curr_col, int dest_row, int dest_col) {
    if (!is_within_bounds(dest_row, dest_col) || board[dest_row][dest_col] != ' ')
        return 0; // destination out of bounds or not empty
    if (player == 1 && board[curr_row][curr_col] == 'R' && dest_row > curr_row) // red can only move up
        return 0;
    if (player == 2 && board[curr_row][curr_col] == 'B' && dest_row < curr_row) // black can only move down
        return 0;
    if (abs(dest_row-curr_row) == 2 && abs(dest_col-curr_col) == 2) { // check for jump
        int mid_row = (dest_row+curr_row)/2; // calculate position of jumped piece
        int mid_col = (dest_col+curr_col)/2;
        if (board[mid_row][mid_col] == ' ') // no piece to jump over
            return 0;
    }
    return 1; // move is valid
}

// Function to make move
void make_move(int player, int curr_row, int curr_col, int dest_row, int dest_col) {
    board[dest_row][dest_col] = board[curr_row][curr_col]; // place piece in destination square
    board[curr_row][curr_col] = ' '; // empty current square
    if (abs(dest_row-curr_row) == 2 && abs(dest_col-curr_col) == 2) { // check for jump
        int mid_row = (dest_row+curr_row)/2; // calculate position of jumped piece
        int mid_col = (dest_col+curr_col)/2;
        board[mid_row][mid_col] = ' '; // remove jumped piece from board
    }
}

// Function to check if player has won (no opponent pieces remaining)
int has_won(int player) {
    int i, j;
    char opponent_piece;
    if (player == 1)
        opponent_piece = 'B';
    else
        opponent_piece = 'R';
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == opponent_piece)
                return 0; // opponent piece found, game still ongoing
        }
    }
    return 1; // no opponent pieces remaining, player has won
}

// Main function
int main() {
    int curr_player = 1; // red starts first
    initialize_board(); // start with initial pieces
    print_board(); // print board for first time
    while (!has_won(curr_player)) { // game continues until current player wins
        printf("Player %d's turn:\n", curr_player);
        int curr_row, curr_col, dest_row, dest_col;
        do { // loop until valid piece selected
            printf("Enter current piece position (row col): ");
            scanf("%d %d", &curr_row, &curr_col);
        } while (!is_within_bounds(curr_row, curr_col) || !is_own_piece(board[curr_row][curr_col], curr_player));
        do { // loop until valid move selected
            printf("Enter destination position (row col): ");
            scanf("%d %d", &dest_row, &dest_col);
        } while (!is_valid_move(curr_player, curr_row, curr_col, dest_row, dest_col));
        make_move(curr_player, curr_row, curr_col, dest_row, dest_col); // execute valid move
        print_board(); // print updated board
        curr_player = (curr_player % 2) + 1; // switch to other player's turn
    }
    printf("Player %d has won the game!\n", curr_player); // winner declared
    return 0;
}