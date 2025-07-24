//FormAI DATASET v1.0 Category: Table Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 6
#define COLUMNS 7

const char PLAYER1_SYMBOL = 'X';
const char PLAYER2_SYMBOL = 'O';
const char EMPTY_SYMBOL = ' ';

const char BOARD_TOP_LEFT_CORNER = '+';
const char BOARD_TOP_RIGHT_CORNER = '+';
const char BOARD_BOTTOM_LEFT_CORNER = '+';
const char BOARD_BOTTOM_RIGHT_CORNER = '+';
const char BOARD_HORIZONTAL_BORDER = '-';
const char BOARD_VERTICAL_BORDER = '|';

// Function prototypes
void print_board(char board[ROWS][COLUMNS]);
void initialize_board(char board[ROWS][COLUMNS]);
void get_move(char player_symbol, char board[ROWS][COLUMNS]);
int check_win(char symbol, char board[ROWS][COLUMNS]);
int check_horizontal_win(char symbol, char board[ROWS][COLUMNS]);
int check_vertical_win(char symbol, char board[ROWS][COLUMNS]);
int check_diagonal_win(char symbol, char board[ROWS][COLUMNS]);
int check_tie(char board[ROWS][COLUMNS]);

int main() {
    char board[ROWS][COLUMNS];
    char current_player = PLAYER1_SYMBOL;
    int player_won = 0;

    // Seed the random number generator with current time
    srand(time(NULL));

    // Initialize the board
    initialize_board(board);

    // Print the empty board
    print_board(board);

    // Game loop
    while (!player_won) {
        // Get the current player's move
        get_move(current_player, board);

        // Print the updated board
        print_board(board);

        // Check if current player won
        player_won = check_win(current_player, board);

        if (player_won) {
            printf("Player %c wins!\n", current_player);
            break; // Exit the loop if current player won
        }

        // Check for a tie game
        if (check_tie(board)) {
            printf("Tie game!\n");
            break; // Exit the loop if tie game
        }

        // Switch to other player's turn
        if (current_player == PLAYER1_SYMBOL) {
            current_player = PLAYER2_SYMBOL;
        } else {
            current_player = PLAYER1_SYMBOL;
        }
    }

    return 0;
}

// Function definitions

// Print the current state of the board
void print_board(char board[ROWS][COLUMNS]) {
    // Print the top border
    printf("%c", BOARD_TOP_LEFT_CORNER);
    for (int col = 0; col < COLUMNS; col++) {
        printf("%c%c%c", BOARD_HORIZONTAL_BORDER, BOARD_HORIZONTAL_BORDER, BOARD_HORIZONTAL_BORDER);
        if (col != COLUMNS - 1) {
            printf("%c", BOARD_HORIZONTAL_BORDER);
        } else {
            printf("%c", BOARD_TOP_RIGHT_CORNER);
        }
    }
    printf("\n");

    // Print the board contents
    for (int row = 0; row < ROWS; row++) {
        printf("%c", BOARD_VERTICAL_BORDER);
        for (int col = 0; col < COLUMNS; col++) {
            printf(" %c %c", board[row][col], BOARD_VERTICAL_BORDER);
        }
        printf("\n");

        // Print a horizontal border except for last row
        if (row != ROWS - 1) {
            printf("%c", BOARD_VERTICAL_BORDER);
            for (int col = 0; col < COLUMNS; col++) {
                printf("%c%c%c%c", BOARD_HORIZONTAL_BORDER, BOARD_HORIZONTAL_BORDER, BOARD_HORIZONTAL_BORDER, BOARD_VERTICAL_BORDER);
            }
            printf("\n");
        }
    }

    // Print the bottom border
    printf("%c", BOARD_BOTTOM_LEFT_CORNER);
    for (int col = 0; col < COLUMNS; col++) {
        printf("%c%c%c", BOARD_HORIZONTAL_BORDER, BOARD_HORIZONTAL_BORDER, BOARD_HORIZONTAL_BORDER);
        if (col != COLUMNS - 1) {
            printf("%c", BOARD_HORIZONTAL_BORDER);
        } else {
            printf("%c", BOARD_BOTTOM_RIGHT_CORNER);
        }
    }
    printf("\n");
}

// Initialize the board with empty spaces
void initialize_board(char board[ROWS][COLUMNS]) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLUMNS; col++) {
            board[row][col] = EMPTY_SYMBOL;
        }
    }
}

// Get the current player's move
void get_move(char player_symbol, char board[ROWS][COLUMNS]) {
    int col = -1;
    while (col < 0 || col >= COLUMNS) {
        printf("Player %c's turn. Enter a column number (0-6) to make your move: ", player_symbol);
        scanf("%d", &col);
    }

    // Check if the selected column is full
    int row = 0;
    while (board[row][col] != EMPTY_SYMBOL) {
        row++;
        if (row >= ROWS) {
            // Column is full, prompt for another column
            col = -1;
            while (col < 0 || col >= COLUMNS) {
                printf("Column is full. Select another column: ");
                scanf("%d", &col);
            }
            row = 0; // Reset row count
        }
    }

    board[row][col] = player_symbol; // Update board
}

// Check if the specified player has won the game
int check_win(char symbol, char board[ROWS][COLUMNS]) {
    return (check_horizontal_win(symbol, board) || check_vertical_win(symbol, board) || check_diagonal_win(symbol, board));
}

// Check if specified player has a horizontal win
int check_horizontal_win(char symbol, char board[ROWS][COLUMNS]) {
    for (int row = 0; row < ROWS; row++) {
        int consecutive_symbols = 0;
        for (int col = 0; col < COLUMNS; col++) {
            if (board[row][col] == symbol) {
                consecutive_symbols++;
                if (consecutive_symbols >= 4) {
                    return 1;
                }
            } else {
                consecutive_symbols = 0;
            }
        }
    }

    return 0;
}

// Check if specified player has a vertical win
int check_vertical_win(char symbol, char board[ROWS][COLUMNS]) {
    for (int col = 0; col < COLUMNS; col++) {
        int consecutive_symbols = 0;
        for (int row = 0; row < ROWS; row++) {
            if (board[row][col] == symbol) {
                consecutive_symbols++;
                if (consecutive_symbols >= 4) {
                    return 1;
                }
            } else {
                consecutive_symbols = 0;
            }
        }
    }

    return 0;
}

// Check if specified player has a diagonal win
int check_diagonal_win(char symbol, char board[ROWS][COLUMNS]) {
    // Check for diagonal win from upper left to lower right
    for (int row = 0; row < ROWS - 3; row++) {
        for (int col = 0; col < COLUMNS - 3; col++) {
            if (board[row][col] == symbol && board[row + 1][col + 1] == symbol &&
                board[row + 2][col + 2] == symbol && board[row + 3][col + 3] == symbol) {
                return 1;
            }
        }
    }

    // Check for diagonal win from lower left to upper right
    for (int row = ROWS - 1; row >= 3; row--) {
        for (int col = 0; col < COLUMNS - 3; col++) {
            if (board[row][col] == symbol && board[row - 1][col + 1] == symbol &&
                board[row - 2][col + 2] == symbol && board[row - 3][col + 3] == symbol) {
                return 1;
            }
        }
    }

    return 0;
}

// Check for a tie game
int check_tie(char board[ROWS][COLUMNS]) {
    for (int col = 0; col < COLUMNS; col++) {
        if (board[0][col] == EMPTY_SYMBOL) {
            return 0; // At least one column is not full, game is not tied
        }
    }

    return 1; // All columns are full, game is tied
}