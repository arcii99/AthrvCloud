//FormAI DATASET v1.0 Category: Memory Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4 // Size of the game board (4 x 4)
#define MAX_MOVES (BOARD_SIZE * BOARD_SIZE) / 2 // Number of moves in the game

void init_board(int board[][BOARD_SIZE]);
void print_board(int board[][BOARD_SIZE], int revealed[][BOARD_SIZE]);
int make_move(int board[][BOARD_SIZE], int revealed[][BOARD_SIZE], int row, int col);
int check_win(int revealed[][BOARD_SIZE]);

int main() {
    int board[BOARD_SIZE][BOARD_SIZE]; // The game board
    int revealed[BOARD_SIZE][BOARD_SIZE] = {0}; // Keeps track of which tiles have been revealed
    int num_moves = 0; // Counter for number of moves made
    int row, col; // Stores user's selected row and column
    srand(time(NULL)); // Seed the random number generator
    init_board(board); // Initialize the game board with random numbers

    printf("Welcome to the Memory Game!\n");
    printf("You have %d moves to match all pairs.\n", MAX_MOVES);

    while (1) {
        // Print the current state of the board
        print_board(board, revealed);

        // Prompt the user to select a tile
        printf("Enter a row and column to reveal (e.g. 1 2): ");
        scanf("%d %d", &row, &col);

        // Check if the selected move is valid
        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || revealed[row][col]) {
            printf("Invalid move!\n");
            continue; // Continue loop for another iteration
        }

        // Make the move and increment the move counter
        if (make_move(board, revealed, row, col)) {
            printf("You found a pair!\n");
        } else {
            printf("Sorry, not a match.\n");
        }
        num_moves++;

        // Check if the game has been won
        if (check_win(revealed)) {
            printf("Congratulations, you won in %d moves!\n", num_moves);
            break;
        }

        // Check if the maximum number of moves has been exceeded
        if (num_moves >= MAX_MOVES) {
            printf("Sorry, you lost. Better luck next time!\n");
            break;
        }
    }

    return 0;
}

/**
 * Initializes the game board with random numbers.
 */
void init_board(int board[][BOARD_SIZE]) {
    int num_pairs = (BOARD_SIZE * BOARD_SIZE) / 2;
    int pairs[num_pairs]; // Stores each number pair
    int pairs_idx = 0; // Index into the pairs array
    int row, col;

    // Initialize the pairs array with unique numbers (0 to num_pairs - 1)
    for (int i = 0; i < num_pairs; i++) {
        pairs[i] = i;
    }

    // Shuffle the pairs array using the Fisher-Yates algorithm
    for (int i = num_pairs - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = pairs[i];
        pairs[i] = pairs[j];
        pairs[j] = temp;
    }

    // Place the pairs onto the game board at random positions
    for (int i = 0; i < num_pairs; i++) {
        int value = pairs[i];

        // Place the pair in two random positions on the board
        for (int j = 0; j < 2; j++) {
            do {
                row = rand() % BOARD_SIZE;
                col = rand() % BOARD_SIZE;
            } while (board[row][col] != 0);
            board[row][col] = value;
        }
    }
}

/**
 * Prints the game board with revealed tiles.
 */
void print_board(int board[][BOARD_SIZE], int revealed[][BOARD_SIZE]) {
    printf("\n");
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (revealed[row][col]) {
                printf("%d ", board[row][col]);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * Reveals the tile at the given row and column. Returns 1 if a match is found, 0 otherwise.
 */
int make_move(int board[][BOARD_SIZE], int revealed[][BOARD_SIZE], int row, int col) {
    int value = board[row][col];
    revealed[row][col] = 1;

    // Check if there is another revealed tile with the same value
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            if (revealed[r][c] && board[r][c] == value && (r != row || c != col)) {
                revealed[r][c] = 1;
                return 1; // Match found, return true
            }
        }
    }

    return 0; // Match not found, return false
}

/**
 * Checks if the game has been won.
 */
int check_win(int revealed[][BOARD_SIZE]) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (!revealed[row][col]) {
                return 0; // Some tiles are still hidden, return false
            }
        }
    }
    return 1; // All tiles are revealed, return true
}