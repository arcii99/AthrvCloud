//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3]; // Global variable representing current game board.

void clear_board() {
    int row, col;
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            board[row][col] = ' ';
        }
    }
}

void print_board() {
    printf("\n   1   2   3\n");
    printf("1  %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("  ---+---+---\n");
    printf("2  %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("  ---+---+---\n");
    printf("3  %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

int is_game_over() {
    int row, col;
    // Check for horizontal and vertical wins.
    for (row = 0; row < 3; row++) {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2] && board[row][0] != ' ') {
            return 1;  // Player has won.
        }
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col] && board[0][col] != ' ') {
            return 1;  // Player has won.
        }
    }
    // Check for diagonal wins.
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return 1;  // Player has won.
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return 1;  // Player has won.
    }
    // Check if board is full (draw).
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            if (board[row][col] == ' ') {
                return 0;  // Game is not over yet.
            }
        }
    }
    return 2;  // Game is a draw.
}

void player_move() {
    int row, col;
    printf("\nEnter row and column for your move: ");
    scanf("%d %d", &row, &col);
    if (board[row-1][col-1] == ' ') {
        board[row-1][col-1] = 'X';
    } else {
        printf("\nInvalid move. Try again.");
        player_move();
    }
}

void computer_move() {
    int row, col;
    srand(time(NULL));  // Initialize random seed.
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != ' ');
    board[row][col] = 'O';
    printf("\nComputer played at row %d, column %d", row+1, col+1);
}

void play_game() {
    clear_board();
    print_board();
    while (is_game_over() == 0) {
        player_move();
        print_board();
        if (is_game_over() == 0) {
            printf("\nComputer is thinking...");
            computer_move();
            print_board();
        }
    }
    if (is_game_over() == 1) {
        printf("\nCongratulations! You won!");
    } else {
        printf("\nGame over. It's a draw.");
    }
}

int main() {
    char play_again = 'Y';
    while (play_again == 'Y' || play_again == 'y') {
        play_game();
        printf("\nDo you want to play again? (Y/N)");
        scanf(" %c", &play_again);
    }
    return 0;
}