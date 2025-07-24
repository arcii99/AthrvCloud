//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define NUM_MINES 15

char board[BOARD_SIZE][BOARD_SIZE];
char revealed[BOARD_SIZE][BOARD_SIZE];
int num_mines_unflagged = NUM_MINES;
int num_revealed = 0;

// Function to display the current state of the board
void print_board() {
    printf("   ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d ", i);

        for (int j = 0; j < BOARD_SIZE; j++) {
            if (!revealed[i][j]) {
                printf("%c ", board[i][j] == 'X' ? '_' : 'X');
            } else {
                printf("%c ", board[i][j]);
            }
        }

        printf("\n");
    }
}

// Helper function to check if a given cell is a valid cell on the board
int is_valid_cell(int row, int col) {
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE;
}

// Function to generate the board and randomly place the mines
void generate_board() {
    // Initialize the board with empty cells represented as '.'
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '.';
            revealed[i][j] = 0;
        }
    }

    // Place the mines randomly on the board
    srand(time(NULL));
    int num_mines_placed = 0;
    while (num_mines_placed < NUM_MINES) {
        int row = rand() % BOARD_SIZE;
        int col = rand() % BOARD_SIZE;

        if (board[row][col] == '.') {
            board[row][col] = 'X';
            num_mines_placed++;
        }
    }
}

// Function to reveal the current cell and recursively reveal adjacent cells if no mines are nearby
void reveal_cell(int row, int col) {
    if (!is_valid_cell(row, col) || revealed[row][col]) {
        return;
    }

    revealed[row][col] = 1;
    num_revealed++;

    if (board[row][col] == 'X') {
        printf("Oh no, you've hit a mine! Game over.\n");
        exit(0);
    } else if (board[row][col] != '.') {
        return;
    }

    int num_mines_nearby = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (is_valid_cell(i, j) && board[i][j] == 'X') {
                num_mines_nearby++;
            }
        }
    }

    if (num_mines_nearby == 0) {
        for (int i = row - 1; i <= row + 1; i++) {
            for (int j = col - 1; j <= col + 1; j++) {
                if (!(i == row && j == col)) {
                    reveal_cell(i, j);
                }
            }
        }
    }
}

// Function to flag a cell as containing a mine
void flag_cell(int row, int col) {
    if (revealed[row][col]) {
        printf("This cell has already been revealed!\n");
        return;
    }

    if (board[row][col] == 'X') {
        num_mines_unflagged--;
    }

    board[row][col] = 'F';
}

int main() {
    generate_board();

    printf("Welcome to Minesweeper!\n");
    printf("To reveal a cell, input [x y]\n");
    printf("To flag a cell, input [x y f]\n");

    while (num_mines_unflagged > 0 && num_revealed < BOARD_SIZE * BOARD_SIZE - NUM_MINES) {
        print_board();

        int row, col;
        char action;
        printf("> ");
        scanf("%d %d %c", &row, &col, &action);

        if (action == 'f' || action == 'F') {
            flag_cell(row, col);
        } else {
            reveal_cell(row, col);
        }
    }

    if (num_mines_unflagged > 0) {
        printf("Congratulations, you've won!\n");
    }

    return 0;
}