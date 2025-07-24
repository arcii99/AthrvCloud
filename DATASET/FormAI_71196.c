//FormAI DATASET v1.0 Category: Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 9

char board[BOARD_SIZE]; // The game board

// Check if the game is over
int is_game_over() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i] == '-') {
            return 0;
        }
    }
    return 1;
}

// Display the game board
void display_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%c ", board[i]);
        if ((i + 1) % 3 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

// Check if the player has won
int check_winner(char player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i += 3) {
        if (board[i] == player && board[i+1] == player && board[i+2] == player) {
            return 1;
        }
    }
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[i] == player && board[i+3] == player && board[i+6] == player) {
            return 1;
        }
    }
    // Check diagonals
    if (board[0] == player && board[4] == player && board[8] == player) {
        return 1;
    }
    if (board[2] == player && board[4] == player && board[6] == player) {
        return 1;
    }
    // No winner
    return 0;
}

// Get a random valid move
int get_random_move() {
    int rand_num = rand() % BOARD_SIZE;
    while (board[rand_num] != '-') {
        rand_num = rand() % BOARD_SIZE;
    }
    return rand_num;
}

int main() {
    // Initialize the game board
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = '-';
    }

    // Start the game
    printf("Welcome to Tic Tac Toe!\n");
    display_board();
    srand(time(NULL)); // Seed the random number generator

    while (!is_game_over()) {
        // Player's turn
        int player_move = -1;
        while (player_move == -1) {
            printf("Enter a valid move (0-8): ");
            int move;
            scanf("%d", &move);
            if (move >= 0 && move < BOARD_SIZE && board[move] == '-') {
                player_move = move;
            } else {
                printf("Invalid move!\n");
            }
        }
        board[player_move] = 'X';
        display_board();
        if (check_winner('X')) {
            printf("Congratulations, you win!\n");
            break;
        }
        if (is_game_over()) {
            printf("Game over! It's a tie!\n");
            break;
        }

        // Computer's turn
        int computer_move = get_random_move();
        board[computer_move] = 'O';
        printf("Computer played at %d\n", computer_move);
        display_board();
        if (check_winner('O')) {
            printf("Sorry, you lose!\n");
            break;
        }
    }

    return 0;
}