//FormAI DATASET v1.0 Category: Checkers Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

// Defining the board and players
char board[SIZE][SIZE];
int player; // 1 for player 1 and 2 for player 2

// Function to initialize the board
void init_board() {
    // Filling the board with empty spaces
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    // Placing the players' pieces
    for(int i=0; i<3; i++) {
        for(int j=0; j<SIZE; j++) {
            if((i+j)%2 == 0) {
                board[i][j] = '1';
            }
        }
    }

    for(int i=SIZE-1; i>SIZE-4; i--) {
        for(int j=0; j<SIZE; j++) {
            if((i+j)%2 == 0) {
                board[i][j] = '2';
            }
        }
    }

    // Initializing the player to player 1
    player = 1;
}

// Function to print the board
void print_board() {
    printf("    ");
    for(int i=0; i<SIZE; i++) {
        printf("%d   ", i+1);
    }
    printf("\n");

    for(int i=0; i<SIZE; i++) {
        printf("  +---+---+---+---+---+---+---+---+\n");
        printf("%d ", i+1);
        for(int j=0; j<SIZE; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("  +---+---+---+---+---+---+---+---+\n");
}

// Function to check if a move is valid
int is_valid_move(int from_row, int from_col, int to_row, int to_col) {
    // Check if the 'to' position is not already occupied
    if(board[to_row][to_col] != ' ') {
        return 0;
    }

    // Check if the 'from' and 'to' positions are diagonal
    if(abs(from_row-to_row) != abs(from_col-to_col)) {
        return 0;
    }

    // Check if the piece being moved is of the current player
    if(board[from_row][from_col] == '1' && player == 2) {
        return 0;
    }
    else if(board[from_row][from_col] == '2' && player == 1) {
        return 0;
    }

    // Check if the move is a capture move
    if(abs(from_row-to_row) == 2) {
        int capture_row = (from_row+to_row)/2;
        int capture_col = (from_col+to_col)/2;

        if(board[capture_row][capture_col] == '1' && player == 2) {
            return 1;
        }
        else if(board[capture_row][capture_col] == '2' && player == 1) {
            return 1;
        }
        else {
            return 0;
        }
    }

    // Check if the move is a regular move
    if(abs(from_row-to_row) == 1) {
        return 1;
    }
    else {
        return 0;
    }
}

// Function to make a move
void make_move(int from_row, int from_col, int to_row, int to_col) {
    // Move the piece to the 'to' position
    board[to_row][to_col] = board[from_row][from_col];
    board[from_row][from_col] = ' ';

    // If it is a capture move, remove the captured piece
    if(abs(from_row-to_row) == 2) {
        int capture_row = (from_row+to_row)/2;
        int capture_col = (from_col+to_col)/2;
        board[capture_row][capture_col] = ' ';
    }
}

// Function to check if there are any available moves for the current player
int has_available_moves() {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            if(board[i][j] == '1' && player == 1) {
                if((i>0 && j>0 && is_valid_move(i,j,i-1,j-1)) ||
                   (i>0 && j<SIZE-1 && is_valid_move(i,j,i-1,j+1)) ||
                   (i<SIZE-2 && j>0 && is_valid_move(i,j,i+1,j-1)) ||
                   (i<SIZE-2 && j<SIZE-1 && is_valid_move(i,j,i+1,j+1))) {
                    return 1;
                }
            }
            else if(board[i][j] == '2' && player == 2) {
                if((i>1 && j>0 && is_valid_move(i,j,i-1,j-1)) ||
                   (i>1 && j<SIZE-1 && is_valid_move(i,j,i-1,j+1)) ||
                   (i<SIZE-1 && j>0 && is_valid_move(i,j,i+1,j-1)) ||
                   (i<SIZE-1 && j<SIZE-1 && is_valid_move(i,j,i+1,j+1))) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

// Function to switch players
void switch_players() {
    if(player == 1) {
        player = 2;
    }
    else {
        player = 1;
    }
}

// Function to play the game
void play_game() {
    int from_row, from_col, to_row, to_col;

    while(1) {
        // Print the board
        print_board();

        // Check if the current player has any available moves
        if(!has_available_moves()) {
            printf("Player %d does not have any available moves. Player %d wins!\n", player, player==1?2:1);
            return;
        }

        // Get the move from the current player
        printf("Player %d, enter the row and column of the piece to move (e.g. 3 4): ", player);
        scanf("%d %d", &from_row, &from_col);

        printf("Player %d, enter the row and column of the position to move to (e.g. 3 4): ", player);
        scanf("%d %d", &to_row, &to_col);

        // Check if the move is valid
        if(!is_valid_move(from_row-1, from_col-1, to_row-1, to_col-1)) {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Make the move
        make_move(from_row-1, from_col-1, to_row-1, to_col-1);

        // Check if the current player has won
        if(player == 1) {
            if(to_row-1 == 0) {
                printf("Player %d wins!\n", player);
                return;
            }
        }
        else {
            if(to_row-1 == SIZE-1) {
                printf("Player %d wins!\n", player);
                return;
            }
        }

        // Switch to the other player
        switch_players();
    }
}

// Main function
int main() {
    printf("Welcome to C Checkers!\n\n");
    printf("Instructions:\n");
    printf("1. Player 1's pieces are represented by the number 1.\n");
    printf("2. Player 2's pieces are represented by the number 2.\n");
    printf("3. To make a move, enter the row and column of the piece to move, then the row and column of the position to move to.\n");
    printf("4. The first player to get one of their pieces to the opposite end of the board wins.\n\n");

    init_board();
    play_game();

    return 0;
}