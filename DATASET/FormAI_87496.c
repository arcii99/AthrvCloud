//FormAI DATASET v1.0 Category: Checkers Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE]; // global 2D array that represents the board
char player1 = 'X'; // player 1's checker symbol
char player2 = 'O'; // player 2's checker symbol

void init_board() {
    // initialize the board with empty spaces and the checkers in their starting positions
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(i <= 2 && (i+j) % 2 == 0) { // player 1's checkers
                board[i][j] = player1;
            } else if(i >= 5 && (i+j) % 2 == 0) { // player 2's checkers
                board[i][j] = player2;
            } else { // empty space
                board[i][j] = ' ';
            }
        }
    }
}

void print_board() {
    // print out the current state of the board
    printf("    a   b   c   d   e   f   g   h\n");
    printf("  +---+---+---+---+---+---+---+---+\n");
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("%d |", i+1);
        for(int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c |", board[i][j]);
        }
        printf(" %d\n", i+1);
        printf("  +---+---+---+---+---+---+---+---+\n");
    }
    printf("    a   b   c   d   e   f   g   h\n");
}

int is_valid_move(int row, int col, int new_row, int new_col, char player) {
    // check if the move is valid and return 1 if it is, 0 otherwise
    if(new_row < 0 || new_row >= BOARD_SIZE || new_col < 0 || new_col >= BOARD_SIZE) { // out of bounds
        return 0;
    }
    if(board[new_row][new_col] != ' ') { // destination tile is not empty
        return 0;
    }
    if(player == player1) { // player 1's checker
        if(new_row <= row) { // can only move forwards
            return 0;
        }
        if(new_row - row == 1 && abs(new_col - col) == 1) { // basic move (one tile diagonally)
            return 1;
        }
        if(new_row - row == 2 && abs(new_col - col) == 2 && board[row+1][(col+new_col)/2] == player2) { // jump move (two tiles diagonally)
            return 1;
        }
    } else if(player == player2) { // player 2's checker
        if(new_row >= row) { // can only move forwards
            return 0;
        }
        if(row - new_row == 1 && abs(new_col - col) == 1) { // basic move (one tile diagonally)
            return 1;
        }
        if(row - new_row == 2 && abs(new_col - col) == 2 && board[row-1][(col+new_col)/2] == player1) { // jump move (two tiles diagonally)
            return 1;
        }
    }
    return 0; // move is not valid
}

int can_capture(int row, int col, char player) {
    // check if the checker at the given position can make a jump move
    if(player == player1) { // player 1's checker
        if(is_valid_move(row, col, row+2, col+2, player) || is_valid_move(row, col, row+2, col-2, player)) {
            return 1;
        }
    } else if(player == player2) { // player 2's checker
        if(is_valid_move(row, col, row-2, col+2, player) || is_valid_move(row, col, row-2, col-2, player)) {
            return 1;
        }
    }
    return 0; // unable to make a jump move
}

int get_winner() {
    // check if one of the players has won (i.e. all of the other player's checkers have been captured)
    int player1_count = 0;
    int player2_count = 0;
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == player1) {
                player1_count++;
            } else if(board[i][j] == player2) {
                player2_count++;
            }
        }
    }
    if(player1_count == 0) {
        return 2; // player 2 wins
    } else if(player2_count == 0) {
        return 1; // player 1 wins
    }
    return 0; // game not over yet
}

void play_game() {
    // main game loop
    int row, col, new_row, new_col, is_valid, can_jump, winner;
    char player = player1;
    while(1) {
        print_board();
        printf("%c's turn\n", player);
        printf("Enter the coordinates of the checker you want to move (e.g. \"3 4\"): ");
        scanf("%d %d", &row, &col);
        if(board[row-1][col-1] != player) { // selected checker does not belong to the current player
            printf("Invalid checker selected\n");
            continue;
        }
        can_jump = can_capture(row-1, col-1, player);
        printf("Possible moves:\n");
        if(can_jump) { // must make a jump move if possible
            if(is_valid_move(row-1, col-1, row+2, col+2, player)) {
                printf("- Jump to (%d,%d)\n", row+2, col+2);
            }
            if(is_valid_move(row-1, col-1, row+2, col-2, player)) {
                printf("- Jump to (%d,%d)\n", row+2, col-2);
            }
            printf("Enter the coordinates of the destination tile to make a jump move: ");
        } else { // can make a basic move or pass
            if(is_valid_move(row-1, col-1, row+1, col+1, player)) {
                printf("- Move to (%d,%d)\n", row+1, col+1);
            }
            if(is_valid_move(row-1, col-1, row+1, col-1, player)) {
                printf("- Move to (%d,%d)\n", row+1, col-1);
            }
            printf("Enter the coordinates of the destination tile to make a basic move, or enter 0 0 to pass: ");
        }
        scanf("%d %d", &new_row, &new_col);
        if(new_row == 0 && new_col == 0) { // pass
            printf("%c has passed their turn\n", player);
            player = player == player1 ? player2 : player1;
            continue;
        }
        is_valid = is_valid_move(row-1, col-1, new_row-1, new_col-1, player);
        if(!is_valid) { // invalid move
            printf("Invalid move\n");
            continue;
        }
        can_jump = can_capture(new_row-1, new_col-1, player);
        board[new_row-1][new_col-1] = player; // move checker to new position
        board[row-1][col-1] = ' '; // remove checker from old position
        if(can_jump) { // check if another jump move is possible
            row = new_row;
            col = new_col;
            continue;
        }
        winner = get_winner();
        if(winner) { // game over
            print_board();
            printf("Congratulations to %c for winning!\n", winner == 1 ? player1 : player2);
            break;
        }
        player = player == player1 ? player2 : player1; // switch players
    }
}

int main() {
    init_board();
    play_game();
    return 0;
}