//FormAI DATASET v1.0 Category: Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BOARD_SIZE 3
#define X_SYMBOL 'X'
#define O_SYMBOL 'O'
#define EMPTY_SYMBOL '-'

typedef struct Board {
    char cells[BOARD_SIZE][BOARD_SIZE];
} Board;

// Initialize a new board with empty cells
Board init_board() {
    Board board;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board.cells[i][j] = EMPTY_SYMBOL;
        }
    }
    return board;
}

// Print the board
void print_board(Board board) {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("\t");
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board.cells[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Check if the board is full
int is_board_full(Board board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board.cells[i][j] == EMPTY_SYMBOL) {
                return 0;
            }
        }
    }
    return 1;
}

// Check if one player has won
char check_winner(Board board) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board.cells[i][0] == board.cells[i][1] && board.cells[i][1] == board.cells[i][2]) {
            return board.cells[i][0];
        }
    }

    // Check columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board.cells[0][i] == board.cells[1][i] && board.cells[1][i] == board.cells[2][i]) {
            return board.cells[0][i];
        }
    }

    // Check diagonals
    if (board.cells[0][0] == board.cells[1][1] && board.cells[1][1] == board.cells[2][2]) {
        return board.cells[0][0];
    }
    if (board.cells[0][2] == board.cells[1][1] && board.cells[1][1] == board.cells[2][0]) {
        return board.cells[0][2];
    }

    // No winner
    return EMPTY_SYMBOL;
}

// Get user input for row and column
int get_input(int *row, int *col) {
    char input[10];
    printf("Enter row and column (e.g. 1 2): ");
    fgets(input, sizeof(input), stdin);

    if (isspace(input[0])) {
        *row = input[1] - '0';
    } else {
        *row = input[0] - '0';
    }

    if (isspace(input[2])) {
        *col = input[3] - '0';
    } else {
        *col = input[2] - '0';
    }

    return 1;
}

// Play the game
void play_game() {
    Board board = init_board();
    int player = 1;
    char symbol;
    int row, col;

    while(1) {
        // Print the board
        print_board(board);

        // Get user input
        get_input(&row, &col);

        // Check if input is valid
        if (row < 1 || row > 3 || col < 1 || col > 3) {
            printf("Invalid input\n");
            continue;
        }

        // Check if cell is already occupied
        if (board.cells[row-1][col-1] != EMPTY_SYMBOL) {
            printf("Cell is already occupied\n");
            continue;
        }

        // Set symbol for current player
        if (player == 1) {
            symbol = X_SYMBOL;
            player = 2;
        } else {
            symbol = O_SYMBOL;
            player = 1;
        }

        // Set cell value and check for winner
        board.cells[row-1][col-1] = symbol;
        char winner = check_winner(board);
        if (winner != EMPTY_SYMBOL) {
            // Print the final board
            print_board(board);

            // Print the winner
            if (winner == X_SYMBOL) {
                printf("Player 1 (X) wins!\n");
            } else {
                printf("Player 2 (O) wins!\n");
            }
            break;
        }

        // Check if board is full
        if (is_board_full(board)) {
            // Print the final board
            print_board(board);

            // Print draw message
            printf("Draw!\n");
            break;
        }
    }
}

int main() {
    play_game();
    return 0;
}