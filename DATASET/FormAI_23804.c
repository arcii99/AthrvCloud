//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: recursive
#include <stdio.h>
#include <stdbool.h>

char board[3][3]; // Tic Tac Toe game board
int moves = 0; // number of moves taken

// recursive function to make a move on the board
bool make_move(char player, int row, int col) {
    if (board[row][col] == ' ') { // check if spot is empty
        board[row][col] = player; // make move
        moves++; // increment move count
        return true;
    }
    return false; // invalid move
}

// recursive function to check if any player has won
bool check_win(char player) {
    // check rows
    for (int row = 0; row < 3; row++) {
        if (board[row][0] == player && board[row][1] == player && board[row][2] == player) {
            return true; // player won
        }
    }
    // check columns
    for (int col = 0; col < 3; col++) {
        if (board[0][col] == player && board[1][col] == player && board[2][col] == player) {
            return true; // player won
        }
    }
    // check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; // player won
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; // player won
    }
    return false; // no winner yet
}

// recursive function to print the game board
void print_board() {
    printf("\n-------------\n");
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            printf("| %c ", board[row][col]);
        }
        printf("|\n-------------\n");
    }
}

// recursive function for AI to make a move
void ai_make_move(char ai_player) {
    // loop through all possible moves
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row][col] == ' ') { // check if empty spot
                make_move(ai_player, row, col); // make move
                if (check_win(ai_player)) { // if this move wins the game
                    return;
                }
                ai_make_move(ai_player == 'X' ? 'O' : 'X'); // switch player and continue
                board[row][col] = ' '; // undo move
            }
        }
    }
}

// recursive main function for the game
void play_game() {
    print_board(); // print initial board
    char human_player = 'X';
    char ai_player = 'O';
    while (moves < 9) { // continue game until all spots are filled
        int row, col;
        if (human_player == 'X') {
            printf("Enter row (1-3): ");
            scanf("%d", &row);
            printf("Enter column (1-3): ");
            scanf("%d", &col);
            row--;
            col--;
            if (make_move(human_player, row, col)) {
                if (check_win(human_player)) {
                    printf("Human wins!\n");
                    return;
                }
                human_player = 'O'; // switch to AI player
                ai_make_move(ai_player); // AI makes a move
                if (check_win(ai_player)) {
                    printf("AI wins!\n");
                    return;
                }
                human_player = 'X'; // switch back to human player
            } else {
                printf("Invalid move, try again.\n");
            }
        }
    }
    printf("Draw!\n"); // no one won
}

int main() {
    // initialize board with empty spaces
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            board[row][col] = ' ';
        }
    }
    play_game(); // start game
    return 0;
}