//FormAI DATASET v1.0 Category: Checkers Game ; Style: systematic
#include <stdio.h>

// Constants
#define BOARD_SIZE 8
#define PLAYER_ONE 1
#define PLAYER_TWO 2

// Variables
int board[BOARD_SIZE][BOARD_SIZE];
int player_turn = PLAYER_ONE;

// Function Prototypes
void initialize_board();
void print_board();
void switch_turn();
int move_piece(int row_start, int col_start, int row_end, int col_end);
int is_valid_move(int row_start, int col_start, int row_end, int col_end);
int is_jump_move(int row_start, int col_start, int row_end, int col_end);

int main() {
    // Initialize Board
    initialize_board();
    // Play Game
    while (1) {
        // Print Board
        print_board();
        // Get Player Input
        int start_row, start_col, end_row, end_col;
        printf("Player %d's turn\n", player_turn);
        printf("Enter Starting Row: ");
        scanf("%d", &start_row);
        printf("Enter Starting Column: ");
        scanf("%d", &start_col);
        printf("Enter Ending Row: ");
        scanf("%d", &end_row);
        printf("Enter Ending Column: ");
        scanf("%d", &end_col);
        // Move Piece
        int move_status = move_piece(start_row, start_col, end_row, end_col);
        if (move_status == 0) {
            printf("Invalid Move\n");
        } else if (move_status == 2) {
            printf("Jump Move Made\n");
        } else {
            switch_turn();
        }
    }
    return 0;
}

void initialize_board() {
    int i, j;
    // Initialize All Board Spaces to 0
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
    // Player One Pieces
    board[0][1] = PLAYER_ONE;
    board[0][3] = PLAYER_ONE;
    board[0][5] = PLAYER_ONE;
    board[0][7] = PLAYER_ONE;
    board[1][0] = PLAYER_ONE;
    board[1][2] = PLAYER_ONE;
    board[1][4] = PLAYER_ONE;
    board[1][6] = PLAYER_ONE;
    board[2][1] = PLAYER_ONE;
    board[2][3] = PLAYER_ONE;
    board[2][5] = PLAYER_ONE;
    board[2][7] = PLAYER_ONE;
    // Player Two Pieces
    board[5][0] = PLAYER_TWO;
    board[5][2] = PLAYER_TWO;
    board[5][4] = PLAYER_TWO;
    board[5][6] = PLAYER_TWO;
    board[6][1] = PLAYER_TWO;
    board[6][3] = PLAYER_TWO;
    board[6][5] = PLAYER_TWO;
    board[6][7] = PLAYER_TWO;
    board[7][0] = PLAYER_TWO;
    board[7][2] = PLAYER_TWO;
    board[7][4] = PLAYER_TWO;
    board[7][6] = PLAYER_TWO;
}

void print_board() {
    int i, j;
    printf("\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("| ");
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%d | ", board[i][j]);
        }
        printf("\n");
    }
}

void switch_turn() {
    if (player_turn == PLAYER_ONE) {
        player_turn = PLAYER_TWO;
    } else {
        player_turn = PLAYER_ONE;
    }
}

int move_piece(int row_start, int col_start, int row_end, int col_end) {
    // Check if Move is Valid
    if (is_valid_move(row_start, col_start, row_end, col_end)) {
        // Move Piece
        board[row_end][col_end] = board[row_start][col_start];
        board[row_start][col_start] = 0;
        // Check if Jump Move
        if (is_jump_move(row_start, col_start, row_end, col_end)) {
            // Remove Jumped Piece
            int row_jump = (row_start + row_end) / 2;
            int col_jump = (col_start + col_end) / 2;
            board[row_jump][col_jump] = 0;
            return 2;
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

int is_valid_move(int row_start, int col_start, int row_end, int col_end) {
    // Check if End Space is Empty
    if (board[row_end][col_end] != 0) {
        return 0;
    }
    // Check if Valid Distance
    if (abs(row_end - row_start) != 1 && abs(row_end - row_start) != 2) {
        return 0;
    }
    // Check if Valid Direction
    if (board[row_start][col_start] == PLAYER_ONE) {
        if (row_end < row_start) {
            return 0;
        }
    } else {
        if (row_end > row_start) {
            return 0;
        }
    }
    // Check if Jump Move Available
    if (abs(row_end - row_start) == 2 && abs(col_end - col_start) == 2) {
        int row_jump = (row_start + row_end) / 2;
        int col_jump = (col_start + col_end) / 2;
        if (board[row_jump][col_jump] != player_turn && board[row_jump][col_jump] != 0) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 1;
    }
}

int is_jump_move(int row_start, int col_start, int row_end, int col_end) {
    if (abs(row_end - row_start) == 2 && abs(col_end - col_start) == 2) {
        return 1;
    } else {
        return 0;
    }
}