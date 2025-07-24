//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {FALSE, TRUE} boolean;

// Define dimensions of the game board
#define ROWS 6
#define COLS 6

// Define player characters
#define PLAYER_ONE 'O'
#define PLAYER_TWO 'X'

// Define game board characters
#define EMPTY ' '
#define WALL '#'

// Define maximum number of turns
#define MAX_TURNS (ROWS * COLS)

// Define function to display the game board
void display_board(char board[ROWS][COLS], int player_one_col, int player_one_row, int player_two_col, int player_two_row) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if ((col == player_one_col) && (row == player_one_row)) {
                printf("%c", PLAYER_ONE);
            } else if ((col == player_two_col) && (row == player_two_row)) {
                printf("%c", PLAYER_TWO);
            } else {
                printf("%c", board[row][col]);
            }
        }
        printf("\n");
    }
}

// Define function to check if a move is valid
boolean is_valid_move(char board[ROWS][COLS], int col, int row) {
    if ((col >= COLS) || (col < 0) || (row >= ROWS) || (row < 0)) {
        return FALSE;
    }
    if (board[row][col] != EMPTY) {
        return FALSE;
    }
    return TRUE;
}

// Define function to get player move from user
void get_player_move(char board[ROWS][COLS], int *col, int *row, char player_char) {
    while (TRUE) {
        printf("Player %c, enter your move (col row): ", player_char);
        if (scanf("%d %d", col, row) != 2) {
            printf("Invalid input! Try again.\n");
            // Flush the input buffer
            while (getchar() != '\n') {
                ;
            }
            continue;
        }
        if (!is_valid_move(board, *col, *row)) {
            printf("Invalid move! Try again.\n");
            continue;
        }
        break;
    }
}

// Define function to check if there is a winner
boolean is_winner(char board[ROWS][COLS], int col, int row) {
    char player_char = board[row][col];
    int count;
    
    // Check row
    count = 0;
    for (int c = 0; c < COLS; c++) {
        if (board[row][c] == player_char) {
            count++;
        } else {
            break;
        }
    }
    if (count == 4) {
        return TRUE;
    }
    
    // Check column
    count = 0;
    for (int r = 0; r < ROWS; r++) {
        if (board[r][col] == player_char) {
            count++;
        } else {
            break;
        }
    }
    if (count == 4) {
        return TRUE;
    }
    
    // Check diagonal (top-left to bottom-right)
    count = 0;
    int c = col;
    for (int r = row; r < ROWS; r++) {
        if ((c >= COLS) || (board[r][c] != player_char)) {
            break;
        }
        count++;
        c++;
    }
    c = col - 1;
    for (int r = row - 1; r >= 0; r--) {
        if ((c < 0) || (board[r][c] != player_char)) {
            break;
        }
        count++;
        c--;
    }
    if (count >= 4) {
        return TRUE;
    }
    
    // Check diagonal (bottom-left to top-right)
    count = 0;
    c = col;
    for (int r = row; r >= 0; r--) {
        if ((c >= COLS) || (board[r][c] != player_char)) {
            break;
        }
        count++;
        c++;
    }
    c = col - 1;
    for (int r = row + 1; r < ROWS; r++) {
        if ((c < 0) || (board[r][c] != player_char)) {
            break;
        }
        count++;
        c--;
    }
    if (count >= 4) {
        return TRUE;
    }
    
    // No winner yet
    return FALSE;
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    // Initialize the game board
    char board[ROWS][COLS];
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if ((row == 0) || (row == ROWS - 1) || (col == 0) || (col == COLS - 1)) {
                board[row][col] = WALL;
            } else {
                board[row][col] = EMPTY;
            }
        }
    }
    
    // Initialize player positions
    int player_one_col = COLS / 2;
    int player_one_row = ROWS - 2;
    int player_two_col = COLS / 2;
    int player_two_row = 1;
    
    // Set up the game loop
    boolean game_over = FALSE;
    boolean player_one_turn = TRUE;
    int turn_count = 0;
    
    // Display the initial game board
    display_board(board, player_one_col, player_one_row, player_two_col, player_two_row);
    
    // Start the game loop
    while (!game_over) {
        // Increment the turn count
        turn_count++;
        
        // Check if no more turns left
        if (turn_count > MAX_TURNS) {
            printf("No more turns left! Game over.\n");
            game_over = TRUE;
            break;
        }
        
        // Get the current player's move
        int col;
        int row;
        char player_char;
        if (player_one_turn) {
            player_char = PLAYER_ONE;
            get_player_move(board, &col, &row, player_char);
            player_one_col = col;
            player_one_row = row;
        } else {
            player_char = PLAYER_TWO;
            printf("It's the computer's turn.\n");
            // Add some randomness to the computer's move
            int rand_col = rand() % COLS;
            int rand_row = rand() % ROWS;
            while (!is_valid_move(board, rand_col, rand_row)) {
                rand_col = rand() % COLS;
                rand_row = rand() % ROWS;
            }
            col = rand_col;
            row = rand_row;
            player_two_col = col;
            player_two_row = row;
        }
        
        // Update the game board
        board[row][col] = player_char;
        
        // Check if there is a winner
        if (is_winner(board, col, row)) {
            printf("Player %c wins!!\n", player_char);
            game_over = TRUE;
        }
        
        // Display the updated game board
        display_board(board, player_one_col, player_one_row, player_two_col, player_two_row);
        
        // Switch to the other player's turn
        player_one_turn = !player_one_turn;
    }
    
    return 0;
}