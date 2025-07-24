//FormAI DATASET v1.0 Category: Checkers Game ; Style: modular
#include <stdio.h>

// Constants to represent the black and white pieces
#define BLACK 'b'
#define WHITE 'w'
#define EMPTY '-'

// Board size
#define BOARD_SIZE 8

// Structure to hold the position of a piece
typedef struct {
    int row;
    int col;
} Position;

// Function to print the board
void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("   ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a move is valid
int is_valid_move(char board[BOARD_SIZE][BOARD_SIZE], Position current_pos, Position new_pos) {
    // Check if the new position is within the board
    if (new_pos.row < 0 || new_pos.row >= BOARD_SIZE || new_pos.col < 0 || new_pos.col >= BOARD_SIZE) {
        return 0;
    }
    // Check if the current position is not empty
    if (board[current_pos.row][current_pos.col] == EMPTY) {
        return 0;
    }
    // Check if the new position is empty
    if (board[new_pos.row][new_pos.col] != EMPTY) {
        return 0;
    }
    // Check if the move is diagonal
    if (abs(new_pos.row - current_pos.row) != abs(new_pos.col - current_pos.col)) {
        return 0;
    }
    // Check if the move is one or two steps
    if (abs(new_pos.row - current_pos.row) > 2 || abs(new_pos.col - current_pos.col) > 2) {
        return 0;
    }
    // Check if the move is capturing a piece
    if (abs(new_pos.row - current_pos.row) == 2) {
        int mid_row = (new_pos.row + current_pos.row) / 2;
        int mid_col = (new_pos.col + current_pos.col) / 2;
        if (board[mid_row][mid_col] == EMPTY || board[mid_row][mid_col] == board[current_pos.row][current_pos.col]) {
            return 0;
        }
    }
    // Check if black pieces are moving in the correct direction
    if (board[current_pos.row][current_pos.col] == BLACK && new_pos.row <= current_pos.row) {
        return 0;
    }
    // Check if white pieces are moving in the correct direction
    if (board[current_pos.row][current_pos.col] == WHITE && new_pos.row >= current_pos.row) {
        return 0;
    }
    return 1;
}

// Function to move a piece
void move_piece(char board[BOARD_SIZE][BOARD_SIZE], Position current_pos, Position new_pos) {
    // Move the piece
    board[new_pos.row][new_pos.col] = board[current_pos.row][current_pos.col];
    board[current_pos.row][current_pos.col] = EMPTY;
    // Check if the move captured a piece
    if (abs(new_pos.row - current_pos.row) == 2) {
        int mid_row = (new_pos.row + current_pos.row) / 2;
        int mid_col = (new_pos.col + current_pos.col) / 2;
        board[mid_row][mid_col] = EMPTY;
    }
}

// Function to check if a player has won
int has_won(char board[BOARD_SIZE][BOARD_SIZE], char player) {
    int num_pieces = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == player) {
                num_pieces++;
            }
        }
    }
    return num_pieces == 0;
}

int main() {
    // Initialize the board
    char board[BOARD_SIZE][BOARD_SIZE] = {
        { EMPTY, WHITE, EMPTY, WHITE, EMPTY, WHITE, EMPTY, WHITE },
        { WHITE, EMPTY, WHITE, EMPTY, WHITE, EMPTY, WHITE, EMPTY },
        { EMPTY, WHITE, EMPTY, WHITE, EMPTY, WHITE, EMPTY, WHITE },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY },
        { EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK },
        { BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY }
    };
    print_board(board);
    // Initialize the player
    char player = BLACK;
    while (1) {
        printf("%c player's turn\n", player);
        // Get the current position of the piece to move
        int current_row, current_col;
        printf("Current row: ");
        scanf("%d", &current_row);
        printf("Current column: ");
        scanf("%d", &current_col);
        Position current_pos = { current_row - 1, current_col - 1 };
        // Get the new position of the piece
        int new_row, new_col;
        printf("New row: ");
        scanf("%d", &new_row);
        printf("New column: ");
        scanf("%d", &new_col);
        Position new_pos = { new_row - 1, new_col - 1 };
        // Check if the move is valid
        if (!is_valid_move(board, current_pos, new_pos)) {
            printf("Invalid move\n");
            continue;
        }
        // Move the piece
        move_piece(board, current_pos, new_pos);
        // Check if the player has won
        if (has_won(board, player)) {
            printf("%c player has won!\n", player);
            break;
        }
        // Switch the player
        if (player == BLACK) {
            player = WHITE;
        } else {
            player = BLACK;
        }
        print_board(board);
    }
    return 0;
}