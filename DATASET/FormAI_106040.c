//FormAI DATASET v1.0 Category: Table Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Function to display game board
 * @param board: The game board
 * @param size: The size of the board
 */
void display_board(char **board, int size) {
    printf("   ");
    for (int i = 0; i < size; i++) {
        printf("%c ", 'A' + i);
    }
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < size; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

/**
 * Function to check if a player has won the game
 * @param board: The game board
 * @param size: The size of the board
 * @param player: The current player (X or O)
 * @return: 1 if the player has won, 0 otherwise
 */
int check_win(char **board, int size, char player) {
    // Check for horizontal win
    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (board[i][j] == player) {
                count++;
            } else {
                count = 0;
            }
            if (count == 3) {
                return 1;
            }
        }
    }

    // Check for vertical win
    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (board[j][i] == player) {
                count++;
            } else {
                count = 0;
            }
            if (count == 3) {
                return 1;
            }
        }
    }

    // Check for diagonal win (top-left to bottom-right)
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (board[i][i] == player) {
            count++;
        } else {
            count = 0;
        }
        if (count == 3) {
            return 1;
        }
    }

    // Check for diagonal win (bottom-left to top-right)
    count = 0;
    for (int i = 0; i < size; i++) {
        if (board[size - 1 - i][i] == player) {
            count++;
        } else {
            count = 0;
        }
        if (count == 3) {
            return 1;
        }
    }

    // No win condition found
    return 0;
}

/**
 * Main function to play the Tic Tac Toe game
 */
int main() {
    int size = 3;
    char **board = malloc(size * sizeof(char *));
    for (int i = 0; i < size; i++) {
        board[i] = malloc(size * sizeof(char));
        for (int j = 0; j < size; j++) {
            board[i][j] = '-';
        }
    }

    printf("Welcome to the Tic Tac Toe game!\n");
    printf("Player 1 (X) starts the game.\n");
    printf("Enter the row and column for your move, separated by a space (e.g. 1 A): \n");

    char current_player = 'X';
    int moves_left = size * size;

    while (moves_left > 0) {
        display_board(board, size);
        printf("Player %c's turn: ", current_player);

        int row, col;
        scanf("%d %c", &row, &col);
        getchar(); // Clear input buffer

        // Convert column from character to integer
        col = col - 'A';

        if (row < 1 || row > size || col < 0 || col >= size || board[row - 1][col] != '-') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        board[row - 1][col] = current_player;
        moves_left--;

        if (check_win(board, size, current_player)) {
            display_board(board, size);
            printf("Congratulations, Player %c wins!\n", current_player);
            break;
        }

        if (moves_left == 0) {
            display_board(board, size);
            printf("Game over. It's a tie!\n");
            break;
        }

        // Swap players
        current_player = (current_player == 'X') ? 'O' : 'X';
    }

    // Free memory
    for (int i = 0; i < size; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}