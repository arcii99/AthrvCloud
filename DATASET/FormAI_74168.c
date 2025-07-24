//FormAI DATASET v1.0 Category: Checkers Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// The game board
char board[BOARD_SIZE][BOARD_SIZE];

// Initialize the game board with starting pieces
void init_board() {
    int i, j;
    // Set the initial pieces for the first 3 rows
    for(i = 0; i < 3; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            if(i%2 == 0 && j%2 == 1) board[i][j] = 'o';
            else if(i%2 == 1 && j%2 == 0) board[i][j] = 'o';
            else board[i][j] = ' ';
        }
    }
    // Set the initial pieces for the last 3 rows
    for(i = 5; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            if(i%2 == 0 && j%2 == 1) board[i][j] = 'x';
            else if(i%2 == 1 && j%2 == 0) board[i][j] = 'x';
            else board[i][j] = ' ';
        }
    }
}

// Print the game board to the console
void print_board() {
    int i, j;
    printf("\n");
    for(i = 0; i < BOARD_SIZE; i++) {
        printf("  %c ", i+65);
    }
    printf("\n");
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("| %d\n", i+1);
        printf(" ");
        for(j = 0; j < BOARD_SIZE; j++) {
            printf("----");
        }
        printf("\n");
    }
    printf("\n");
}

// Handle the player's move
void player_move() {
    int from_row, from_col, to_row, to_col;
    // Get the piece the player wants to move
    printf("\nEnter the position of the piece you want to move (e.g. A1): ");
    scanf("%d%d", &from_row, &from_col);
    // Convert the letters to numbers for the array
    from_row -= 1;
    from_col -= 1;
    // Make sure the player is moving their own piece
    if(board[from_row][from_col] != 'o') {
        printf("\nYou can only move your own pieces!\n");
        player_move();
        return;
    }
    // Get the position the player wants to move to
    printf("\nEnter the position you want to move to (e.g. B2): ");
    scanf("%d%d", &to_row, &to_col);
    // Convert the letters to numbers for the array
    to_row -= 1;
    to_col -= 1;
    // Make sure the move is valid
    if(to_row == from_row+1 && (to_col == from_col-1 || to_col == from_col+1)) {
        // Move the piece and check for a king piece
        board[to_row][to_col] = 'o';
        if(to_row == BOARD_SIZE-1) board[to_row][to_col] = 'O';
        board[from_row][from_col] = ' ';
    } else if(to_row == from_row+2 && (to_col == from_col-2 || to_col == from_col+2)) {
        // Make sure the player is jumping over an opponent's piece
        int opp_row = (to_row + from_row) / 2;
        int opp_col = (to_col + from_col) / 2;
        if(board[opp_row][opp_col] != 'x' && board[opp_row][opp_col] != 'X') {
            printf("\nYou can only jump over your opponent's pieces!\n");
            player_move();
            return;
        }
        // Move the piece and capture the opponent's piece
        board[to_row][to_col] = 'o';
        if(to_row == BOARD_SIZE-1) board[to_row][to_col] = 'O';
        board[opp_row][opp_col] = ' ';
        board[from_row][from_col] = ' ';
    } else {
        printf("\nInvalid move!\n");
        player_move();
        return;
    }
}

// Handle the computer's move
void computer_move() {
    int i, j, from_row, from_col, to_row, to_col;
    // Find a random piece to move
    while(1) {
        from_row = rand() % BOARD_SIZE;
        from_col = rand() % BOARD_SIZE;
        if(board[from_row][from_col] == 'x' || board[from_row][from_col] == 'X') break;
    }
    // Find a random valid move for that piece
    while(1) {
        int direction = rand() % 4;
        if(direction == 0) { // Move diagonally to the left
            to_row = from_row + 1;
            to_col = from_col - 1;
        } else if(direction == 1) { // Move diagonally to the right
            to_row = from_row + 1;
            to_col = from_col + 1;
        } else if(direction == 2) { // Jump diagonally to the left
            to_row = from_row + 2;
            to_col = from_col - 2;
        } else { // Jump diagonally to the right
            to_row = from_row + 2;
            to_col = from_col + 2;
        }
        // Make sure the move is within the bounds of the board
        if(to_row < 0 || to_row >= BOARD_SIZE || to_col < 0 || to_col >= BOARD_SIZE) continue;
        // Make sure the move is not on top of another piece
        if(board[to_row][to_col] != ' ') continue;
        // Make sure the move is valid
        if(to_row == from_row+1 && (to_col == from_col-1 || to_col == from_col+1)) {
            // Move the piece and check for a king piece
            board[to_row][to_col] = 'x';
            if(to_row == 0) board[to_row][to_col] = 'X';
            board[from_row][from_col] = ' ';
            break;
        } else if(to_row == from_row+2 && (to_col == from_col-2 || to_col == from_col+2)) {
            // Make sure the computer is jumping over an opponent's piece
            int opp_row = (to_row + from_row) / 2;
            int opp_col = (to_col + from_col) / 2;
            if(board[opp_row][opp_col] != 'o' && board[opp_row][opp_col] != 'O') continue;
            // Move the piece and capture the opponent's piece
            board[to_row][to_col] = 'x';
            if(to_row == 0) board[to_row][to_col] = 'X';
            board[opp_row][opp_col] = ' ';
            board[from_row][from_col] = ' ';
            break;
        }
    }
    printf("\nThe computer made a move.\n");
}

int main() {
    int i, j;
    // Initialize the game board
    init_board();
    printf("Welcome to Shape Shifting Checkers!\n");
    printf("---------------------------------\n");
    printf("You are the player 'o' and the computer is 'x'.\n");
    printf("The game board is %d x %d and looks like this:\n", BOARD_SIZE, BOARD_SIZE);
    print_board();
    // Main game loop
    while(1) {
        // Player's turn
        printf("Your turn!\n");
        player_move();
        print_board();
        // Check for the player winning
        int player_wins = 1;
        for(i = 0; i < BOARD_SIZE; i++) {
            for(j = 0; j < BOARD_SIZE; j++) {
                if(board[i][j] == 'x' || board[i][j] == 'X') player_wins = 0;
            }
        }
        if(player_wins) {
            printf("Congratulations! You win!\n");
            break;
        }
        // Computer's turn
        printf("Computer's turn!\n");
        computer_move();
        print_board();
        // Check for the computer winning
        int computer_wins = 1;
        for(i = 0; i < BOARD_SIZE; i++) {
            for(j = 0; j < BOARD_SIZE; j++) {
                if(board[i][j] == 'o' || board[i][j] == 'O') computer_wins = 0;
            }
        }
        if(computer_wins) {
            printf("Sorry, the computer wins!\n");
            break;
        }
    }
    return 0;
}