//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 10
#define NUM_MINES 15

bool game_over = false;
char board[BOARD_SIZE][BOARD_SIZE];
int num_mines_left = NUM_MINES;

// Initialize the board with all cells covered and no mines
void init_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

// Shuffle the board to randomly place mines
void shuffle_board() {
    srand(time(NULL));
    int num_mines_placed = 0;
    while (num_mines_placed < NUM_MINES) {
        int row = rand() % BOARD_SIZE;
        int col = rand() % BOARD_SIZE;
        if (board[row][col] != '*') {
            board[row][col] = '*';
            num_mines_placed++;
        }
    }
}

// Print the game board
void print_board() {
    printf("\n   ");
    for (int i = 1; i <= BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\nMines left: %d\n", num_mines_left);
}

// Calculate the number of mines in the neighboring cells
int count_adjacent_mines(int row, int col) {
    int count = 0;
    if (row > 0) {
        if (col > 0 && board[row - 1][col - 1] == '*') count++;
        if (board[row - 1][col] == '*') count++;
        if (col < BOARD_SIZE - 1 && board[row - 1][col + 1] == '*') count++;
    }
    if (col > 0 && board[row][col - 1] == '*') count++;
    if (col < BOARD_SIZE - 1 && board[row][col + 1] == '*') count++;
    if (row < BOARD_SIZE - 1) {
        if (col > 0 && board[row + 1][col - 1] == '*') count++;
        if (board[row + 1][col] == '*') count++;
        if (col < BOARD_SIZE - 1 && board[row + 1][col + 1] == '*') count++;
    }
    return count;
}

// Reveal the cell at the given position
void reveal_cell(int row, int col) {
    if (board[row][col] == '*') {
        game_over = true;
        printf("Game over! You hit a mine.\n");
    } else if (board[row][col] == '-') {
        int adjacent_mines = count_adjacent_mines(row, col);
        board[row][col] = (adjacent_mines > 0) ? ('0' + adjacent_mines) : ' ';
        if (adjacent_mines == 0) {
            if (row > 0 && board[row - 1][col] == '-') reveal_cell(row - 1, col);
            if (row < BOARD_SIZE - 1 && board[row + 1][col] == '-') reveal_cell(row + 1, col);
            if (col > 0 && board[row][col - 1] == '-') reveal_cell(row, col - 1);
            if (col < BOARD_SIZE - 1 && board[row][col + 1] == '-') reveal_cell(row, col + 1);
            if (row > 0 && col > 0 && board[row - 1][col - 1] == '-') reveal_cell(row - 1, col - 1);
            if (row > 0 && col < BOARD_SIZE - 1 && board[row - 1][col + 1] == '-') reveal_cell(row - 1, col + 1);
            if (row < BOARD_SIZE - 1 && col > 0 && board[row + 1][col - 1] == '-') reveal_cell(row + 1, col - 1);
            if (row < BOARD_SIZE - 1 && col < BOARD_SIZE - 1 && board[row + 1][col + 1] == '-') reveal_cell(row + 1, col + 1);
        }
    }
}

// Mark a cell as a mine or remove the mine mark if it's already marked
void mark_cell(int row, int col) {
    if (board[row][col] == '-') {
        board[row][col] = '!';
        num_mines_left--;
    } else if (board[row][col] == '!') {
        board[row][col] = '-';
        num_mines_left++;
    }
}

// Check if all cells without a mine have been revealed
bool all_clear() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == '-' && board[i][j] != '*') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    printf("-- Minesweeper Terminal Game --\n");
    init_board();
    shuffle_board();
    print_board();
    while (!game_over) {
        printf("Enter the row and column of the cell you want to reveal or mark as a mine (e.g. 1 2 m): ");
        int row, col;
        char action[2];
        scanf("%d %d %s", &row, &col, action);
        if (row < 1 || row > BOARD_SIZE || col < 1 || col > BOARD_SIZE) {
            printf("Invalid row or column number. Please try again.\n");
        } else if (strcmp(action, "m") == 0) {
            mark_cell(row - 1, col - 1);
        } else if (strcmp(action, "r") == 0) {
            if (board[row - 1][col - 1] != '-') {
                printf("This cell has already been revealed. Please try again.\n");
            } else {
                reveal_cell(row - 1, col - 1);
                print_board();
                if (all_clear()) {
                    printf("Congratualations! You have won the game!\n");
                    game_over = true;
                }
            }
        } else {
            printf("Invalid action. Please enter 'm' to mark a cell as a mine or 'r' to reveal a cell.\n");
        }
    }
    return 0;
}