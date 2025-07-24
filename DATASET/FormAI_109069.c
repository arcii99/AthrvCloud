//FormAI DATASET v1.0 Category: Checkers Game ; Style: enthusiastic
#include <stdio.h>
#include <stdbool.h>

int main() {
    // Welcome message
    printf("Welcome to the C Checkers game!\n");

    // Define the board with an 8x8 array
    char board[8][8] = {
        {'R', ' ', 'R', ' ', 'R', ' ', 'R', ' '},
        {' ', 'R', ' ', 'R', ' ', 'R', ' ', 'R'},
        {'R', ' ', 'R', ' ', 'R', ' ', 'R', ' '},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {' ', 'B', ' ', 'B', ' ', 'B', ' ', 'B'},
        {'B', ' ', 'B', ' ', 'B', ' ', 'B', ' '},
        {' ', 'B', ' ', 'B', ' ', 'B', ' ', 'B'}
    };

    // Define variables for the game
    bool game_over = false;
    bool is_red_turn = true;
    char turn_color = 'R';

    // Start the game loop
    while (!game_over) {
        // Print the current state of the board
        printf("\nCurrent board:\n");
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }

        // Ask for user input and move the corresponding piece
        bool valid_move = false;
        while (!valid_move) {
            printf("\nIt is %s's turn to move.\n", is_red_turn ? "red" : "black");
            printf("Enter the coordinates of the piece to move (row, column): ");
            int from_row, from_col;
            scanf("%d %d", &from_row, &from_col);

            printf("Enter the coordinates of the destination (row, column): ");
            int to_row, to_col;
            scanf("%d %d", &to_row, &to_col);

            // Check if the move is valid
            if (from_row < 0 || from_row > 7 || from_col < 0 || from_col > 7 || 
                to_row < 0 || to_row > 7 || to_col < 0 || to_col > 7 ||
                board[from_row][from_col] == ' ' ||
                (board[from_row][from_col] == 'R' && !is_red_turn) ||
                (board[from_row][from_col] == 'B' && is_red_turn) ||
                board[to_row][to_col] != ' ') {
                printf("\nInvalid move, try again.\n");
            } else {
                // Move the piece
                board[to_row][to_col] = board[from_row][from_col];
                board[from_row][from_col] = ' ';

                // Check if a piece was captured and remove it
                int capture_row = (from_row + to_row) / 2;
                int capture_col = (from_col + to_col) / 2;
                if (board[capture_row][capture_col] == (is_red_turn ? 'B' : 'R')) {
                    board[capture_row][capture_col] = ' ';
                }

                // Set the flag to indicate a valid move was made
                valid_move = true;

                // Switch turns
                is_red_turn = !is_red_turn;
                turn_color = is_red_turn ? 'R' : 'B';
            }
        }

        // Check if the game is over
        bool red_exists = false;
        bool black_exists = false;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    red_exists = true;
                }
                if (board[i][j] == 'B') {
                    black_exists = true;
                }
                if (red_exists && black_exists) {
                    break;
                }
            }
        }
        if (!red_exists || !black_exists) {
            printf("\nGame over! %s has won.\n", red_exists ? "Red" : "Black");
            game_over = true;
        }
    }

    // Print the final state of the board
    printf("\nFinal board:\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}