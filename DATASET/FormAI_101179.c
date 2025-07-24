//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for board size and other values
#define ROWS 6
#define COLS 9
#define MINE_PROBABILITY 20
#define MAX_MOVES (ROWS * COLS)

// Define the possible states of each cell on the board
enum CellState { UNREVEALED, REVEALED, FLAGGED };

// Define the possible contents of each cell on the board
enum CellContents { EMPTY, MINE };

// Define a struct to represent a cell on the board with its state and contents
struct Cell {
    enum CellState state;
    enum CellContents contents;
};

// Define a struct to represent the game board
struct Board {
    struct Cell cells[ROWS][COLS];
    int revealed_count;
};

// Print the board to the console, including cell states and contents
void print_board(struct Board *board) {
    printf("    ");
    for (int c = 0; c < COLS; c++) {
        printf("%-2d ", c);
    }
    printf("\n");
    printf("   ");
    for (int c = 0; c < COLS; c++) {
        printf("---");
    }
    printf("\n");
    for (int r = 0; r < ROWS; r++) {
        printf("%-2d| ", r);
        for (int c = 0; c < COLS; c++) {
            switch (board->cells[r][c].state) {
                case UNREVEALED:
                    printf(".  ");
                    break;
                case REVEALED:
                    switch (board->cells[r][c].contents) {
                        case EMPTY:
                            printf("   ");
                            break;
                        case MINE:
                            printf("*  ");
                            break;
                    }
                    break;
                case FLAGGED:
                    printf("f  ");
                    break;
            }
        }
        printf("\n");
    }
}

// Generate a random integer between min and max (inclusive)
int rand_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Fill the board with random cell contents and set all cell states to UNREVEALED
void initialize_board(struct Board *board) {
    srand(time(NULL));
    board->revealed_count = 0;
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            board->cells[r][c].contents = (rand_int(1, 100) <= MINE_PROBABILITY) ? MINE : EMPTY;
            board->cells[r][c].state = UNREVEALED;
        }
    }
}

// Get the number of neighboring cells that contain mines
int count_neighbors(struct Board *board, int row, int col) {
    int count = 0;
    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            int r = row + dr;
            int c = col + dc;
            if (r >= 0 && r < ROWS && c >= 0 && c < COLS && board->cells[r][c].contents == MINE) {
                count++;
            }
        }
    }
    return count;
}

// Reveal a cell on the board and return true if the game is over (either won or lost)
int reveal_cell(struct Board *board, int row, int col) {
    if (board->cells[row][col].state == REVEALED || board->cells[row][col].state == FLAGGED) {
        return 0;
    }
    board->cells[row][col].state = REVEALED;
    if (board->cells[row][col].contents == MINE) {
        return 1;
    }
    board->revealed_count++;
    if (board->revealed_count == MAX_MOVES - MINE_PROBABILITY) {
        return 2;
    }
    if (count_neighbors(board, row, col) == 0) {
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                int r = row + dr;
                int c = col + dc;
                if (r >= 0 && r < ROWS && c >= 0 && c < COLS) {
                    reveal_cell(board, r, c);
                }
            }
        }
    }
    return 0;
}

// Set a cell on the board to flagged state (if not already revealed) or unflagged state (if already flagged)
void toggle_flag(struct Board *board, int row, int col) {
    if (board->cells[row][col].state == UNREVEALED) {
        board->cells[row][col].state = FLAGGED;
    } else if (board->cells[row][col].state == FLAGGED) {
        board->cells[row][col].state = UNREVEALED;
    }
}

int main() {
    struct Board board;
    initialize_board(&board);
    print_board(&board);
    while (1) {
        printf("\nEnter row and column (or 'f' to toggle flag): ");
        char input[10];
        fgets(input, 10, stdin);
        int row, col;
        if (sscanf(input, "%d %d", &row, &col) == 2) {
            if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
                printf("Invalid row or column.\n");
            } else {
                int result = reveal_cell(&board, row, col);
                print_board(&board);
                if (result == 1) {
                    printf("Game over: you hit a mine!\n");
                    break;
                } else if (result == 2) {
                    printf("Congratulations, you win!\n");
                    break;
                }
            }
        } else if (input[0] == 'f' && sscanf(input + 1, "%d %d", &row, &col) == 2) {
            if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
                printf("Invalid row or column.\n");
            } else {
                toggle_flag(&board, row, col);
                print_board(&board);
            }
        } else {
            printf("Invalid input.\n");
        }
    }
    return 0;
}