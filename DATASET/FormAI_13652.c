//FormAI DATASET v1.0 Category: Checkers Game ; Style: visionary
#include<stdio.h>

#define BOARD_SIZE 8 // Size of the board
#define WHITE 'W' // White player
#define BLACK 'B' // Black player
#define EMPTY '-' // Empty space

char board[BOARD_SIZE][BOARD_SIZE]; // The game board
int player_turn; // Current player turn

// Function to print the board
void print_board() {
    printf("  ");
    for(int i=0; i<BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for(int row=0; row<BOARD_SIZE; row++) {
        printf("%d ", row);
        for(int col=0; col<BOARD_SIZE; col++) {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
}

// Function to initialize the game board
void initialize_board() {
    // Fill the board with empty spots
    for(int row=0; row<BOARD_SIZE; row++) {
        for(int col=0; col<BOARD_SIZE; col++) {
            board[row][col] = EMPTY;
        }
    }

    // Place the black pieces
    for(int row=0; row<3; row++) {
        for(int col=0; col<BOARD_SIZE; col++) {
            if((row + col) % 2 == 0) {
                board[row][col] = BLACK;
            }
        }
    }

    // Place the white pieces
    for(int row=5; row<BOARD_SIZE; row++) {
        for(int col=0; col<BOARD_SIZE; col++) {
            if((row + col) % 2 == 0) {
                board[row][col] = WHITE;
            }
        }
    }
}

// Function to check if a move is valid
int is_valid_move(int row, int col, int dest_row, int dest_col) {
    // The destination spot must be empty
    if(board[dest_row][dest_col] != EMPTY) {
        return 0;
    }

    // White player moves upwards
    if(board[row][col] == WHITE && dest_row < row) {
        return 0;
    }

    // Black player moves downwards
    if(board[row][col] == BLACK && dest_row > row) {
        return 0;
    }

    // Check if the move is diagonal
    if(abs(dest_row - row) != abs(dest_col - col)) {
        return 0;
    }

    // Check if the move is within the board bounds
    if(dest_row < 0 || dest_row >= BOARD_SIZE || dest_col < 0 || dest_col >= BOARD_SIZE) {
        return 0;
    }

    // Check if a piece is being taken
    if(abs(dest_row - row) == 2 && abs(dest_col - col) == 2) {
        int mid_row = (row + dest_row) / 2;
        int mid_col = (col + dest_col) / 2;
        if(board[mid_row][mid_col] == EMPTY || board[mid_row][mid_col] == player_turn) {
            return 0;
        }
    }

    return 1;
}

// Function to perform a move
void perform_move(int row, int col, int dest_row, int dest_col) {
    board[dest_row][dest_col] = board[row][col];
    board[row][col] = EMPTY;

    // If a piece has been taken, remove it from the board
    if(abs(dest_row - row) == 2 && abs(dest_col - col) == 2) {
        int mid_row = (row + dest_row) / 2;
        int mid_col = (col + dest_col) / 2;
        board[mid_row][mid_col] = EMPTY;
    }
}

// Function to check if the game has ended
int is_game_over() {
    int white_count = 0, black_count = 0;

    for(int row=0; row<BOARD_SIZE; row++) {
        for(int col=0; col<BOARD_SIZE; col++) {
            if(board[row][col] == WHITE) {
                white_count++;
            } else if(board[row][col] == BLACK) {
                black_count++;
            }
        }
    }

    if(white_count == 0 || black_count == 0) {
        return 1;
    }

    return 0;
}

// Function to switch the player turn
void switch_turn() {
    if(player_turn == WHITE) {
        player_turn = BLACK;
    } else {
        player_turn = WHITE;
    }
}

// Main function
int main() {
    initialize_board();
    player_turn = BLACK;

    while(!is_game_over()) {
        printf("\n\n%s player's turn\n", player_turn == WHITE ? "White" : "Black");
        print_board();

        int row, col, dest_row, dest_col;
        int valid_move = 0;

        do {
            printf("\nEnter piece position (row, column): ");
            scanf("%d%d", &row, &col);
            printf("Enter destination position (row, column): ");
            scanf("%d%d", &dest_row, &dest_col);

            if(is_valid_move(row, col, dest_row, dest_col)) {
                valid_move = 1;
                perform_move(row, col, dest_row, dest_col);
            } else {
                printf("\nInvalid move! Try again.\n");
            }
        } while(!valid_move);

        switch_turn();
    }

    printf("\n\nGame over!\n");
    print_board();

    return 0;
}