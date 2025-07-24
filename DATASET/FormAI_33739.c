//FormAI DATASET v1.0 Category: Game ; Style: relaxed
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4 // Size of the square board
#define EMPTY_SPACE '-' // Empty space character used on the board

char board[BOARD_SIZE][BOARD_SIZE];

// Initializes the board with empty spaces
void init_board() {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY_SPACE;
        }
    }
}

// Prints the board to the console
void print_board() {
    printf("  ");
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i+1);
    }
    printf("\n");
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i+1);
        for(int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Generates a random position on the board
void generate_random_position(int* row, int* col) {
    srand(time(NULL)); // Seed the random number generator with current time
    do {
        *row = rand() % BOARD_SIZE;
        *col = rand() % BOARD_SIZE;
    } while(board[*row][*col] != EMPTY_SPACE);
}

// Places a piece on the board
void place_piece(char piece) {
    int row, col;
    generate_random_position(&row, &col);
    board[row][col] = piece;
}

// Ends the game
void end_game() {
    printf("Good game! Thanks for playing.\n");
    exit(0); // Exits the program
}

// Checks if the board is full
bool is_board_full() {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == EMPTY_SPACE) {
                return false;
            }
        }
    }
    return true;
}

// Checks if either player has won
bool is_winner(char piece) {
    for(int i = 0; i < BOARD_SIZE; i++) {
        // Check for horizontal win
        if(board[i][0] == piece && board[i][1] == piece && board[i][2] == piece && board[i][3] == piece) {
            return true;
        }
        // Check for vertical win
        if(board[0][i] == piece && board[1][i] == piece && board[2][i] == piece && board[3][i] == piece) {
            return true;
        }
    }
    // Check for diagonal win
    if(board[0][0] == piece && board[1][1] == piece && board[2][2] == piece && board[3][3] == piece) {
        return true;
    }
    if(board[0][3] == piece && board[1][2] == piece && board[2][1] == piece && board[3][0] == piece) {
        return true;
    }
    return false;
}

// Starts the game
void start_game() {
    char current_piece = 'X'; // Starting piece
    while(!is_board_full()) { // Keep playing until board is full
        place_piece(current_piece);
        print_board(); // Print the board after each move
        if(is_winner(current_piece)) { // Check if current player has won
            printf("Congratulations! Player %c won!\n", current_piece);
            end_game(); // End game if winner found
        }
        current_piece = (current_piece == 'X') ? 'O' : 'X'; // Switch player
    }
    printf("It's a tie! Nobody wins.\n");
    end_game(); // End game if board is full
}

int main() {
    init_board(); // Initialize the board
    start_game(); // Start the game
    return 0;
}