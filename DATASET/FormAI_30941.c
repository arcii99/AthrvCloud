//FormAI DATASET v1.0 Category: Table Game ; Style: peaceful
/*
 * Author: Chatbot
 * Date: 10/10/2021
 * Description: This program allows users to play the Peaceful Game, a simple strategic game
 *              played on a 4x4 board.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

// The board is represented by a 2D array of integers
int board[BOARD_SIZE][BOARD_SIZE];

// This function initializes the board with random values between 0 and 9
void initialize_board() {
    srand(time(NULL));  // Set the random seed based on the current time

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = rand() % 10;  // Generate a random number between 0 and 9
        }
    }
}

// This function prints the current state of the board
void print_board() {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// This function checks if the player has won the game by checking if all the values in the board
// are equal
int check_win() {
    int target = board[0][0];
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != target) {
                return 0;  // The player has not won yet
            }
        }
    }
    return 1;  // The player has won the game
}

// This is the main function that runs the game loop
int main() {
    int player_turn = 1;  // Start with player 1
    int row, col;

    initialize_board();

    printf("Welcome to the Peaceful Game!\n");
    printf("The goal of this game is to make all the values on the board equal.\n");
    printf("Each turn, you may select a square on the board and add its value to all the squares\n");
    printf("in its row and column. Then, it will become your opponent's turn.\n");
    printf("Good luck!\n\n");

    print_board();

    while (!check_win()) {
        if (player_turn == 1) {
            printf("Player 1's turn\n");
        } else {
            printf("Player 2's turn\n");
        }

        printf("Select a square (row, column): ");
        scanf("%d %d", &row, &col);

        // Add the selected square's value to its row and column
        for (int i = 0; i < BOARD_SIZE; i++) {
            board[row][i] += board[row][col];
            board[i][col] += board[row][col];
        }

        player_turn = (player_turn == 1) ? 2 : 1;  // Switch to the other player's turn
        print_board();
    }

    if (player_turn == 1) {
        printf("Congratulations! Player 2 has won the game!\n");
    } else {
        printf("Congratulations! Player 1 has won the game!\n");
    }

    return 0;
}