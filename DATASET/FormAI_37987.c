//FormAI DATASET v1.0 Category: Table Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the game board
void print_board(char board[][3]) {
    printf("\n\nTIC TAC TOE\n\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("\t%c", board[i][j]);
        }
        printf("\n");
    }
}

// Function to generate random number between 0-2
int get_random_number() {
    srand(time(NULL));
    int num = rand() % 3;
    return num;
}

// Function to check if the game is over
int is_game_over(char board[][3]) {
    // Check rows for a win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check columns for a win
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }

    // Check diagonals for a win
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    // Check for a draw
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != '_') {
                count++;
            }
        }
    }

    if (count == 9) {
        return 2;
    }

    return 0;
}

int main() {
    char player_1 = 'X';
    char player_2 = 'O';
    int player_1_turn = 1;
    char board[3][3] = {
        {'_', '_', '_'},
        {'_', '_', '_'},
        {'_', '_', '_'}
    };

    printf("\n\nTIC TAC TOE\n\n");

    while (1) {
        int game_over = is_game_over(board);

        if (game_over == 1) {
            if (player_1_turn) {
                printf("\n\nPlayer 2 wins!\n\n");
            } else {
                printf("\n\nPlayer 1 wins!\n\n");
            }
            break;
        } else if (game_over == 2) {
            printf("\n\nGame is a draw.\n\n");
            break;
        }

        // Print the current state of the board
        print_board(board);

        // Get the input from the player
        int row, col;

        if (player_1_turn) {
            printf("\n\nPlayer 1 turn.\n\n");
            printf("Enter row (0-2): ");
            scanf("%d", &row);
            printf("Enter column (0-2): ");
            scanf("%d", &col);

            if (board[row][col] != '_') {
                printf("\n\nInvalid move. Try again.\n\n");
                continue;
            }

            board[row][col] = player_1;
        } else {
            printf("\n\nPlayer 2 turn.\n\n");
            row = get_random_number();
            col = get_random_number();

            if (board[row][col] != '_') {
                continue;
            }

            board[row][col] = player_2;
        }

        player_1_turn = !player_1_turn;
    }

    // Print the final state of the board
    print_board(board);

    return 0;
}