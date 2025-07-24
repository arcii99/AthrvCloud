//FormAI DATASET v1.0 Category: Table Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 6
#define COLUMNS 7

int board[ROWS][COLUMNS];
int turn = 1;

// Function to print the game board
void print_board() {
    printf("\n");

    for(int i = 0; i < ROWS; i++) {

        for(int j = 0; j < COLUMNS; j++) {

            printf("| ");

            if(board[i][j] == 0) {
                printf(" ");
            }

            else if(board[i][j] == 1) {
                printf("X");
            }

            else if(board[i][j] == 2) {
                printf("O");
            }

            printf(" ");
        }
        printf("|\n");
    }

    printf("-----------------------------\n");
    printf("| 1 2 3 4 5 6 7 |\n\n");
}

// Function to check if the game is over
int game_over() {
    // Check for a horizontal win
    for(int i = 0; i < ROWS; i++) {

        for(int j = 0; j < COLUMNS - 3; j++) {

            if(board[i][j] == turn && board[i][j+1] == turn && board[i][j+2] == turn && board[i][j+3] == turn) {
                return 1;
            }
        }
    }

    // Check for a vertical win
    for(int i = 0; i < ROWS - 3; i++) {

        for(int j = 0; j < COLUMNS; j++) {

            if(board[i][j] == turn && board[i+1][j] == turn && board[i+2][j] == turn && board[i+3][j] == turn) {
                return 1;
            }
        }
    }

    // Check for a diagonal win (top-left to bottom-right)
    for(int i = 0; i < ROWS - 3; i++) {

        for(int j = 0; j < COLUMNS - 3; j++) {

            if(board[i][j] == turn && board[i+1][j+1] == turn && board[i+2][j+2] == turn && board[i+3][j+3] == turn) {
                return 1;
            }
        }
    }

    // Check for a diagonal win (bottom-left to top-right)
    for(int i = 3; i < ROWS; i++) {

        for(int j = 0; j < COLUMNS - 3; j++) {

            if(board[i][j] == turn && board[i-1][j+1] == turn && board[i-2][j+2] == turn && board[i-3][j+3] == turn) {
                return 1;
            }
        }
    }

    // Check for a tie
    for(int i = 0; i < ROWS; i++) {

        for(int j = 0; j < COLUMNS; j++) {

            if(board[i][j] == 0) {
                return 0;
            }
        }
    }

    return 2;
}

// Function to get user input
int get_input() {
    int input;

    printf("Player %d's turn: ", turn);
    scanf("%d", &input);

    return input;
}

// Function to place a piece on the board
void place_piece(int col) {
    for(int i = ROWS - 1; i >= 0; i--) {

        if(board[i][col-1] == 0) {
            board[i][col-1] = turn;
            break;
        }
    }
}

// Main function
int main() {
    int game_status = 0;
    int input;

    // Initialize the board
    for(int i = 0; i < ROWS; i++) {

        for(int j = 0; j < COLUMNS; j++) {

            board[i][j] = 0;
        }
    }

    while(game_status == 0) {
        print_board();
        input = get_input();
        place_piece(input);

        game_status = game_over();

        if(game_status == 1) {
            printf("Player %d wins!\n", turn);
            print_board();
            break;
        }

        else if(game_status == 2) {
            printf("It's a tie!\n");
            print_board();
            break;
        }

        else {
            if(turn == 1) {
                turn = 2;
            }
            else {
                turn = 1;
            }
        }
    }

    return 0;
}