//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define HUMAN_MARKER 'X'
#define COMPUTER_MARKER 'O'
#define EMPTY_SPACE ' '

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    int row, col;
    printf("\n");
    for (row = 0; row < BOARD_SIZE; row++) {
        printf(" %c | %c | %c ", board[row][0], board[row][1], board[row][2]);
        if (row != BOARD_SIZE - 1) {
            printf("\n---|---|---\n");
        }
    }
    printf("\n\n");
}

int get_random_number(int min, int max) {
    srand(time(0));
    return (rand() % (max - min + 1)) + min;
}

int get_computer_move(char board[BOARD_SIZE][BOARD_SIZE]) {
    int row, col;
    while (1) {
        row = get_random_number(0, BOARD_SIZE - 1);
        col = get_random_number(0, BOARD_SIZE - 1);
        if (board[row][col] == EMPTY_SPACE) {
            return row * BOARD_SIZE + col;
        }
    }
}

char check_win(char board[BOARD_SIZE][BOARD_SIZE]) {
    int row, col;
    for (row = 0; row < BOARD_SIZE; row++) {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
            return board[row][0];
        }
    }
    for (col = 0; col < BOARD_SIZE; col++) {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
            return board[0][col];
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    return EMPTY_SPACE;
}

void play_game() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int i, row, col, turn, game_over, move;
    for (row = 0; row < BOARD_SIZE; row++) {
        for (col = 0; col < BOARD_SIZE; col++) {
            board[row][col] = EMPTY_SPACE;
        }
    }
    turn = 0;
    game_over = 0;
    while (!game_over) {
        print_board(board);
        if (turn % 2 == 0) {
            printf("Your turn! Enter row and column numbers (0 to 2): ");
            scanf("%d %d", &row, &col);
            if (board[row][col] == EMPTY_SPACE) {
                board[row][col] = HUMAN_MARKER;
                turn++;
            } else {
                printf("That space is already taken.\n");
            }
        } else {
            printf("Computer's turn.\n");
            move = get_computer_move(board);
            row = move / BOARD_SIZE;
            col = move % BOARD_SIZE;
            board[row][col] = COMPUTER_MARKER;
            turn++;
        }
        char winner = check_win(board);
        if (winner != EMPTY_SPACE) {
            if (winner == HUMAN_MARKER) {
                printf("Congratulations! You win!\n");
            } else {
                printf("Sorry, you lost. Better luck next time!\n");
            }
            game_over = 1;
            print_board(board);
        } else if (turn == BOARD_SIZE * BOARD_SIZE) {
            printf("It's a tie game!\n");
            game_over = 1;
            print_board(board);
        }
    }
}

int main() {
    char play_again = 'y';
    while (play_again == 'y' || play_again == 'Y') {
        play_game();
        printf("Do you want to play again? (y/n) ");
        scanf(" %c", &play_again);
    }
    printf("Thanks for playing!\n");
    return 0;
}