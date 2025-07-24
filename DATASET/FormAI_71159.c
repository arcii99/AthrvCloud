//FormAI DATASET v1.0 Category: Checkers Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

/* Function to initialize the game board */
void initialize_board() {
    int i, j;
    
    // Setting all board squares to empty
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
    
    // Placing black pieces
    board[0][1] = 'b';
    board[0][3] = 'b';
    board[0][5] = 'b';
    board[0][7] = 'b';
    board[1][0] = 'b';
    board[1][2] = 'b';
    board[1][4] = 'b';
    board[1][6] = 'b';
    board[2][1] = 'b';
    board[2][3] = 'b';
    board[2][5] = 'b';
    board[2][7] = 'b';
    
    // Placing red pieces
    board[5][0] = 'r';
    board[5][2] = 'r';
    board[5][4] = 'r';
    board[5][6] = 'r';
    board[6][1] = 'r';
    board[6][3] = 'r';
    board[6][5] = 'r';
    board[6][7] = 'r';
    board[7][0] = 'r';
    board[7][2] = 'r';
    board[7][4] = 'r';
    board[7][6] = 'r';
}

/* Function to print the game board */
void print_board() {
    int i, j;
    
    printf("   ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d |", i);
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c|", board[i][j]);
        }
        printf(" %d\n", i);
    }
    
    printf("   ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

/* Function to validate a user's move */
bool validate_move(int row, int col, int new_row, int new_col, char player) {
    // Checking if new position is outside the board
    if (new_row < 0 || new_row >= BOARD_SIZE || new_col < 0 || new_col >= BOARD_SIZE) {
        return false;
    }
    
    // Checking if new position is on a white square
    if ((new_row + new_col) % 2 == 0) {
        return false;
    }
    
    // Checking if new position is not empty
    if (board[new_row][new_col] != ' ') {
        return false;
    }
    
    // Checking if player is moving their own piece
    if (player == 'b' && islower(board[row][col])) {
        return false;
    } else if (player == 'r' && isupper(board[row][col])) {
        return false;
    }
    
    // Checking if move is diagonal
    if (abs(new_row - row) != abs(new_col - col)) {
        return false;
    }
    
    // Checking if move is one or two squares away
    if (abs(new_row - row) == 1) {
        // Single square move
        if (player == 'b' && new_row > row) {
            return false;
        } else if (player == 'r' && new_row < row) {
            return false;
        }
    } else if (abs(new_row - row) == 2) {
        // Jump move
        int mid_row = (row + new_row) / 2;
        int mid_col = (col + new_col) / 2;
        if (player == 'b' && new_row > row) {
            // Player is moving down, must jump over red piece
            if (board[mid_row][mid_col] != 'r' && board[mid_row][mid_col] != 'R') {
                return false;
            }
        } else if (player == 'r' && new_row < row) {
            // Player is moving up, must jump over black piece
            if (board[mid_row][mid_col] != 'b' && board[mid_row][mid_col] != 'B') {
                return false;
            }
        }
    } else {
        return false;
    }
    
    // Move is valid
    return true;
}

/* Function to make a move */
void make_move(int row, int col, int new_row, int new_col, char player) {
    // Removing piece from old position
    board[row][col] = ' ';
    
    // Placing piece in new position
    board[new_row][new_col] = player;
    
    // If piece reaches last row, promote to king
    if (new_row == 0 && player == 'r') {
        board[new_row][new_col] = 'R';
    } else if (new_row == BOARD_SIZE - 1 && player == 'b') {
        board[new_row][new_col] = 'B';
    }
    
    // If move was a jump, remove jumped piece
    if (abs(new_row - row) == 2) {
        int mid_row = (row + new_row) / 2;
        int mid_col = (col + new_col) / 2;
        board[mid_row][mid_col] = ' ';
    }
}

/* Function to check if a player has won */
char check_winner() {
    int b_pieces = 0, r_pieces = 0;
    int i, j;
    
    // Counting number of pieces for each player
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 'b' || board[i][j] == 'B') {
                b_pieces++;
            } else if (board[i][j] == 'r' || board[i][j] == 'R') {
                r_pieces++;
            }
        }
    }
    
    if (b_pieces == 0) {
        return 'r';
    } else if (r_pieces == 0) {
        return 'b';
    } else {
        return ' ';
    }
}

/* Function to move a player's piece */
bool move_piece(char player) {
    // Initializing all variables
    int row, col, new_row, new_col;
    char move_input[5];
    
    // Taking user input until valid move is given
    while (true) {
        printf("Player %c's turn. Please enter move: ", player);
        scanf("%s", move_input);
        
        // Validating move input
        if (strlen(move_input) != 4) {
            printf("Invalid move. Please try again.\n");
            continue;
        }
        
        col = move_input[0] - '0';
        row = move_input[1] - '0';
        new_col = move_input[2] - '0';
        new_row = move_input[3] - '0';
        
        if (!validate_move(row, col, new_row, new_col, player)) {
            printf("Invalid move. Please try again.\n");
            continue;
        }
        
        // Making the move
        make_move(row, col, new_row, new_col, player);
        
        // Checking if player has won
        char winner = check_winner();
        if (winner != ' ') {
            printf("Player %c has won the game!\n", winner);
            return true;
        }
        
        // Move successful, break out of loop
        break;
    }
    
    // Move not a winning move, game continues
    return false;
}

/* Main function */
int main() {
    printf("Welcome to the medieval checkers game!\n");
    printf("Black pieces are represented by 'b' and red pieces by 'r'.\n");
    printf("Kings are represented by uppercase letters (B for black and R for red).\n");
    
    initialize_board();
    print_board();
    
    char winner = ' ';
    while (true) {
        if (move_piece('b')) {
            // black player has won
            winner = 'b';
            break;
        }
        
        print_board();
        
        if (move_piece('r')) {
            // red player has won
            winner = 'r';
            break;
        }
        
        print_board();
    }
    
    printf("Congratulations to player %c!\n", winner);
    return 0;
}