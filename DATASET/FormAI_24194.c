//FormAI DATASET v1.0 Category: Checkers Game ; Style: grateful
#include <stdio.h>

// Function to print the game board with pieces
void print_board(char board[][8]) {
    printf("\n       A  B  C  D  E  F  G  H");
    printf("\n      -----------------------");

    for (int i = 0; i < 8; i++) {
        printf("\n   %d |", i + 1);
        for (int j = 0; j < 8; j++) {
            printf(" %c |", board[i][j]);
        }
        printf(" %d", i + 1);
        printf("\n      -----------------------");
    }
    printf("\n       A  B  C  D  E  F  G  H\n");
}

// Function to move the piece from source to destination
void move_piece(char board[][8], int src_row, int src_col, int dst_row, int dst_col) {
    board[dst_row][dst_col] = board[src_row][src_col];
    board[src_row][src_col] = ' ';
}

// Function to check if the move can be made by the selected player
int is_move_valid(char board[][8], char player, int src_row, int src_col, int dst_row, int dst_col) {
    // check if source and destination coordinates are within board limits
    if (src_row < 0 || src_row > 7 || src_col < 0 || src_col > 7 || dst_row < 0 || dst_row > 7 || dst_col < 0 || dst_col > 7) {
        return 0;
    }

    // check if source contains player piece
    if (board[src_row][src_col] != player) {
        return 0;
    }

    // check if destination is an empty cell
    if (board[dst_row][dst_col] != ' ') {
        return 0;
    }

    // check if the move is diagonal
    if (abs(dst_row - src_row) != abs(dst_col - src_col)) {
        return 0;
    }

    // check if the move distance is one or two cells
    if (abs(dst_row - src_row) == 1 && abs(dst_col - src_col) == 1) {
        return 1; // valid single move
    } else if (abs(dst_row - src_row) == 2 && abs(dst_col - src_col) == 2) {
        // check if the move is a capture move
        int mid_row = (src_row + dst_row) / 2;
        int mid_col = (src_col + dst_col) / 2;
        if (board[mid_row][mid_col] == (player == 'x' ? 'o' : 'x')) {
            return 2; // valid capture move
        }
    }

    return 0; // invalid move
}

int main() {
    char board[8][8] = {
        {' ', 'x', ' ', 'x', ' ', 'x', ' ', 'x'},
        {'x', ' ', 'x', ' ', 'x', ' ', 'x', ' '},
        {' ', 'x', ' ', 'x', ' ', 'x', ' ', 'x'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'o', ' ', 'o', ' ', 'o', ' ', 'o', ' '},
        {' ', 'o', ' ', 'o', ' ', 'o', ' ', 'o'},
        {'o', ' ', 'o', ' ', 'o', ' ', 'o', ' '}
    };
    char player = 'x';

    printf("Welcome to Checkers Game!\n");

    while (1) {
        printf("\nPlayer %c's turn:\n", player);
        print_board(board);

        int src_row, src_col, dst_row, dst_col;
        printf("Enter piece coordinates (row col): ");
        scanf("%d %d", &src_row, &src_col);

        printf("Enter destination coordinates (row col): ");
        scanf("%d %d", &dst_row, &dst_col);

        // check if the move is valid and execute the move
        int move_result = is_move_valid(board, player, src_row-1, src_col-1, dst_row-1, dst_col-1);
        if (move_result == 0) {
            printf("Invalid move, try again.\n");
            continue;
        } else if (move_result == 2) {
            // capture move
            int mid_row = (src_row + dst_row) / 2;
            int mid_col = (src_col + dst_col) / 2;
            move_piece(board, src_row-1, src_col-1, dst_row-1, dst_col-1);
            move_piece(board, mid_row-1, mid_col-1, -1, -1);
            printf("Capture move made!\n");
        } else {
            // single cell move
            move_piece(board, src_row-1, src_col-1, dst_row-1, dst_col-1);
        }

        // check if the current player won the game
        int player_row_start = (player == 'x' ? 0 : 5);
        int num_pieces = 0;
        for (int i = player_row_start; i < player_row_start + 3; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == player) {
                    num_pieces++;
                }
            }
        }
        if (num_pieces == 0) {
            printf("\nPlayer %c has won the game!\n", player);
            break;
        }

        // switch to the next player
        player = (player == 'x' ? 'o' : 'x');
    }

    return 0;
}