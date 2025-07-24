//FormAI DATASET v1.0 Category: Checkers Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

// Function to print the board
void print_board(char board[][SIZE]) {
    printf("   a b c d e f g h\n"); // Column labels
    for(int i = 0; i < SIZE; i++) {
        printf("%d  ", i+1); // Row label
        for(int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]); // The cell content
        }
        printf("%d\n", i+1); // Another row label
    }
    printf("   a b c d e f g h\n"); // Column labels
}

// Function to initialize the board
void initialize_board(char board[][SIZE]) {
    // Initialize all cells to empty space
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
    // Initialize the black pieces
    for(int i = 0; i < 3; i++) {
        for(int j = i%2; j < SIZE; j += 2) {
            board[i][j] = 'B';
        }
    }
    // Initialize the white pieces
    for(int i = SIZE-1; i >= SIZE-3; i--) {
        for(int j = i%2; j < SIZE; j += 2) {
            board[i][j] = 'W';
        }
    }
}

// Function to check if a move is valid
int is_valid_move(char board[][SIZE], int x1, int y1, int x2, int y2) {
    // Check if the destination is an empty cell
    if(board[x2][y2] != ' ') {
        return 0;
    }
    // Check if the move is (at most) diagonal and within the board bounds
    if(abs(x2-x1) != abs(y2-y1) || x2 < 0 || x2 >= SIZE || y2 < 0 || y2 >= SIZE) {
        return 0;
    }
    // Check if the move is a jump
    if(abs(x2-x1) == 2) {
        // Calculate the position of the captured piece
        int x_c = (x1+x2)/2;
        int y_c = (y1+y2)/2;
        // Check if the captured piece belongs to the opponent
        if(board[x_c][y_c] == 'B') {
            // Check if the piece is a king
            if(board[x1][y1] == 'W' && x2 == 0) {
                board[x2][y2] = 'K'; // Crown the king
            } else {
                board[x2][y2] = board[x1][y1]; // Move the piece
            }
            board[x1][y1] = ' '; // Remove the piece from its previous position
            board[x_c][y_c] = ' '; // Remove the captured piece
            return 1;
        }
        return 0;
    }
    // Check if the move is a regular move
    if(abs(x2-x1) == 1) {
        // Check if the piece is a king
        if(board[x1][y1] == 'W' && x2 == 0) {
            board[x2][y2] = 'K'; // Crown the king
        } else {
            board[x2][y2] = board[x1][y1]; // Move the piece
        }
        board[x1][y1] = ' '; // Remove the piece from its previous position
        return 1;
    }
    return 0;
}

// Function to change turns
void change_turn(char *turn) {
    if(*turn == 'W') {
        *turn = 'B';
    } else {
        *turn = 'W';
    }
}

int main(void) {
    char board[SIZE][SIZE]; // The game board
    char turn = 'W'; // The player who moves next
    int game_over = 0; // Flag for game over condition
    int x1, y1, x2, y2; // Coordinates of the move
    initialize_board(board); // Initialize the board
    while(!game_over) {
        print_board(board); // Print the board
        printf("%c's turn\n", turn);
        printf("Enter the coordinates of the piece you want to move (row, column): ");
        scanf("%d %d", &x1, &y1);
        printf("Enter the coordinates of the cell you want to move to (row, column): ");
        scanf("%d %d", &x2, &y2);
        // Check if the move is valid and execute it if it is
        if(is_valid_move(board, x1-1, y1-1, x2-1, y2-1)) {
            change_turn(&turn);
        }
        // Check for game over condition
        int white_pieces = 0, black_pieces = 0;
        for(int i = 0; i < SIZE; i++) {
            for(int j = 0; j < SIZE; j++) {
                if(board[i][j] == 'W' || board[i][j] == 'K') {
                    white_pieces++;
                }
                if(board[i][j] == 'B' || board[i][j] == 'K') {
                    black_pieces++;
                }
            }
        }
        if(white_pieces == 0 || black_pieces == 0) {
            game_over = 1;
            printf("Game over! %c wins!\n", (white_pieces == 0) ? 'B' : 'W');
            print_board(board); // Print the final board
        }
    }
    return 0;
}