//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3]; // the tic tac toe board
char player = 'X'; // the current player
char computer = 'O'; // the computer player

// function to print the board
void print_board() {

    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf(" --------- \n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf(" --------- \n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");

}

// function to check if a move is valid
int is_valid_move(int row, int col) {

    if (row < 0 || col < 0 || row > 2 || col > 2) return 0; // outside the board
    if (board[row][col] != '-') return 0; // already occupied
    return 1;

}

// function to check if the game is over
int game_over(char player) {

    // check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }

    // check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    // check if board is full
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '-') return 0;
        }
    }

    return 2; // tie game

}

// function to get the computer's move
void computer_move() {

    int row, col;

    // try to win
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (is_valid_move(i, j)) {
                board[i][j] = computer;
                if (game_over(computer) == 1) return;
                board[i][j] = '-';
            }
        }
    }

    // try to block
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (is_valid_move(i, j)) {
                board[i][j] = player;
                if (game_over(player) == 1) {
                    board[i][j] = computer;
                    return;
                }
                board[i][j] = '-';
            }
        }
    }

    // try to take a corner
    if (is_valid_move(0, 0)) { row = 0; col = 0; }
    else if (is_valid_move(0, 2)) { row = 0; col = 2; }
    else if (is_valid_move(2, 0)) { row = 2; col = 0; }
    else if (is_valid_move(2, 2)) { row = 2; col = 2; }

    // try to take the center
    else if (is_valid_move(1, 1)) { row = 1; col = 1; }

    // take any available edge
    else {
        do {
            row = rand() % 3;
            col = rand() % 3;
        } while (!is_valid_move(row, col));
    }

    board[row][col] = computer;

}

int main() {

    srand(time(NULL)); // seed the random number generator

    // initialize the board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }

    // main game loop
    while (1) {

        // player's turn
        int row, col;
        printf("Player %c's turn.\n", player);
        do {
            printf("Enter row (0-2): ");
            scanf("%d", &row);
            printf("Enter column (0-2): ");
            scanf("%d", &col);
        } while (!is_valid_move(row, col));
        board[row][col] = player;

        // print the board
        print_board();

        // check for winner
        int winner = game_over(player);
        if (winner) {
            if (winner == 1) printf("Player %c wins!\n", player);
            else printf("It's a tie!\n");
            break;
        }

        // computer's turn
        computer_move();
        printf("Computer plays:\n");
        print_board();

        // check for winner
        winner = game_over(computer);
        if (winner) {
            if (winner == 1) printf("Computer wins!\n");
            else printf("It's a tie!\n");
            break;
        }

    }

    return 0;

}