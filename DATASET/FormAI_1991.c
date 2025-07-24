//FormAI DATASET v1.0 Category: Table Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win(char board[BOARD_SIZE][BOARD_SIZE]) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == 'X') {
                return 1;
            } else if (board[i][0] == 'O') {
                return -1;
            }
        }
    }
    // Check columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if (board[0][i] == 'X') {
                return 1;
            } else if (board[0][i] == 'O') {
                return -1;
            }
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'X') {
            return 1;
        } else if (board[0][0] == 'O') {
            return -1;
        }
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == 'X') {
            return 1;
        } else if (board[0][2] == 'O') {
            return -1;
        }
    }
    // Check draw
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == '-') {
                return 0;
            }
        }
    }
    return 2;
}

void player_turn(char board[BOARD_SIZE][BOARD_SIZE], char player) {
    int row, col;
    printf("Player %c's turn.\n", player);
    do {
        printf("Enter row (1-%d) and column (1-%d) separated by a space: ", BOARD_SIZE, BOARD_SIZE);
        scanf("%d %d", &row, &col);
        row--, col--;
    } while (board[row][col] != '-');
    board[row][col] = player;
}

void computer_turn(char board[BOARD_SIZE][BOARD_SIZE], char computer) {
    int row, col;
    printf("Computer's turn.\n");
    do {
        row = rand() % BOARD_SIZE;
        col = rand() % BOARD_SIZE;
    } while (board[row][col] != '-');
    board[row][col] = computer;
}

void play_game() {
    char board[BOARD_SIZE][BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }
    srand(time(NULL));
    int turn = rand() % 2; // randomly select who goes first (0 = player, 1 = computer)
    char player, computer;
    if (turn == 0) {
        player = 'X';
        computer = 'O';
        printf("Player goes first.\n");
    } else {
        player = 'O';
        computer = 'X';
        printf("Computer goes first.\n");
    }
    int winner;
    print_board(board);
    do {
        if (turn == 0) {
            player_turn(board, player);
            print_board(board);
            winner = check_win(board);
            if (winner) break;
            turn = 1;
        } else {
            computer_turn(board, computer);
            print_board(board);
            winner = check_win(board);
            if (winner) break;
            turn = 0;
        }
    } while (winner == 0);
    if (winner == 1) {
        printf("Player %c wins!\n", player);
    } else if (winner == -1) {
        printf("Computer %c wins!\n", computer);
    } else {
        printf("It's a draw!\n");
    }
}

int main() {
    char play_again;
    do {
        play_game();
        printf("Play again? (y/n) ");
        scanf(" %c", &play_again);
    } while (play_again == 'y');
    return 0;
}