//FormAI DATASET v1.0 Category: Checkers Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// In this version of checkers, we represent the game board using a 2D array
int board[BOARD_SIZE][BOARD_SIZE] = {
    {-1, 0,-1, 0,-1, 0,-1, 0},
    { 0,-1, 0,-1, 0,-1, 0,-1},
    {-1, 0,-1, 0,-1, 0,-1, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 1, 0, 1, 0, 1, 0, 1},
    { 1, 0, 1, 0, 1, 0, 1, 0},
    { 0, 1, 0, 1, 0, 1, 0, 1}
};

// Function to print the current state of the board
void print_board() {

    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == -1) {
                printf("X ");
            } else if (board[i][j] == 1) {
                printf("O ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

// Function to check if a move is valid
int is_valid_move(int player, int x, int y, int new_x, int new_y) {

    // Check if the move is out of bounds
    if (new_x < 0 || new_x >= BOARD_SIZE || new_y < 0 || new_y >= BOARD_SIZE) {
        return 0;
    }

    // Check if the destination is already occupied
    if (board[new_x][new_y] != 0) {
        return 0;
    }

    // Check if the player is moving in the right direction
    if (player == 1 && new_x > x) {
        return 0;
    } else if (player == -1 && new_x < x) {
        return 0;
    }

    // Check if the move is a jump
    if (abs(new_x - x) == 2 && abs(new_y - y) == 2) {

        // Check if there is an opposing piece in the way
        if (board[(new_x + x) / 2][(new_y + y) / 2] == -player) {
            return 1;
        } else {
            return 0;
        }
    }

    // Check if the move is a regular move
    if (abs(new_x - x) == 1 && abs(new_y - y) == 1) {
        return 1;
    }

    // Otherwise, the move is not valid
    return 0;
}

// Function to perform a move
int perform_move(int player, int x, int y, int new_x, int new_y) {

    // Check if the move is valid
    if (!is_valid_move(player, x, y, new_x, new_y)) {
        return 0;
    }

    // Move the piece
    board[new_x][new_y] = board[x][y];
    board[x][y] = 0;

    // Check if the move was a jump
    if (abs(new_x - x) == 2 && abs(new_y - y) == 2) {
        board[(new_x + x) / 2][(new_y + y) / 2] = 0;
    }

    // Check if the piece should be kinged
    if (new_x == 0 && player == -1) {
        board[new_x][new_y] = -2;
    } else if (new_x == BOARD_SIZE - 1 && player == 1) {
        board[new_x][new_y] = 2;
    }

    return 1;
}

// Function to check if a player has won
int has_won(int player) {

    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == player || board[i][j] == player * 2) {
                // Check if the player has any moves left
                if ((player == 1 && (is_valid_move(player, i, j, i+1, j+1) || is_valid_move(player, i, j, i+1, j-1) || is_valid_move(player, i, j, i+2, j+2) || is_valid_move(player, i, j, i+2, j-2)))
                || (player == -1 && (is_valid_move(player, i, j, i-1, j+1) || is_valid_move(player, i, j, i-1, j-1) || is_valid_move(player, i, j, i-2, j+2) || is_valid_move(player, i, j, i-2, j-2)))) {
                    return 0;
                }
            }
        }
    }

    // If the player has no moves left, they have lost
    return 1;
}

int main() {

    int turn = 1; // 1 for player 1 (O), -1 for player 2 (X)
    int winner = 0;
    int x, y, new_x, new_y;

    while (!winner) {

        // Print the current board
        printf("Current board:\n");
        print_board();

        // Get the player's move
        printf("Player %d's turn\n", turn);
        printf("Enter the coordinates of the piece you want to move (row column): ");
        scanf("%d %d", &x, &y);
        printf("Enter the coordinates of the square you want to move to (row column): ");
        scanf("%d %d", &new_x, &new_y);

        // Perform the move
        if (!perform_move(turn, x, y, new_x, new_y)) {
            printf("Invalid move, try again\n");
            continue;
        }

        // Check if the game has been won
        if (has_won(turn)) {
            winner = turn;
            continue;
        }

        // Switch turns
        turn *= -1;
    }

    // Print the winner
    if (winner == 1) {
        printf("Player O wins!\n");
    } else {
        printf("Player X wins!\n");
    }

    return 0;
}