//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 4

// define color codes for terminal printing
#define RESET   "\x1B[0m"
#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE    "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN    "\x1B[36m"

// initialize the board with random numbers
void initialize_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    srand(time(NULL));

    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            board[r][c] = rand() % 10;
        }
    }
}

// print the board to the terminal
void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n");
    for (int r = 0; r < BOARD_SIZE; r++) {
        printf(" ");
        for (int c = 0; c < BOARD_SIZE; c++) {
            printf("[%d]", board[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}

// check if the player has won the game
int check_win(int board[BOARD_SIZE][BOARD_SIZE]) {
    int count = 0;
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            if (board[r][c] == 0) {
                count++;
            }
        }
    }
    if (count >= 16) {
        return 1;
    }
    return 0;
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);

    printf(BLUE "\nWelcome to the Cryptic Terminal Game!\n" RESET);
    printf(YELLOW "You win the game by clearing the board of all numbers!\n" RESET);
    printf(GREEN "Enter the coordinates of the number you want to remove in the format 'row,column'.\n" RESET);
    printf(RED "Let's begin!\n" RESET);

    while (!check_win(board)) {
        print_board(board);

        char input[10];
        printf("Enter your move: ");
        fgets(input, 10, stdin);

        int row = input[0] - '0';
        int col = input[2] - '0';

        if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE) {
            board[row][col] = 0;
        } else {
            printf("Invalid move!\n");
        }
    }

    printf(BLUE "Congratulations! You win!\n" RESET);

    return 0;
}