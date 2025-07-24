//FormAI DATASET v1.0 Category: Game of Life ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

int board[ROWS][COLS];
int temp_board[ROWS][COLS];

void initialize_board() {
    srand(time(NULL)); // Seed the random number generator with current time
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2; // Fill the board with either 0 or 1 randomly
        }
    }
}

void print_board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j] ? 'X' : '.'); // Print 'X' for live cell and '.' for dead cell
        }
        printf("\n");
    }
}

int get_alive_neighbors(int row, int col) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) { // Skip current cell
                continue;
            }
            int r = row + i;
            int c = col + j;
            // Handle edge cases by wrapping around the board
            if (r < 0) r = ROWS - 1;
            if (r >= ROWS) r = 0;
            if (c < 0) c = COLS - 1;
            if (c >= COLS) c = 0;
            
            count += board[r][c];
        }
    }
    return count;
}

void update_board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int alive_neighbors = get_alive_neighbors(i, j);
            if (board[i][j] == 1 && (alive_neighbors < 2 || alive_neighbors > 3)) { // Any live cell with fewer than two or more than three live neighbours dies
                temp_board[i][j] = 0;
            }
            else if (board[i][j] == 0 && alive_neighbors == 3) { // Any dead cell with exactly three live neighbours becomes a live cell
                temp_board[i][j] = 1;
            }
            else { // Any live cell with two or three live neighbours lives, and any dead cell with less than three live neighbours remains dead
                temp_board[i][j] = board[i][j];
            }
        }
    }
    // Copy the new board to the original board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = temp_board[i][j];
        }
    }
}

int main() {
    initialize_board();
    print_board();
    while (1) { // Infinite loop
        update_board();
        system("cls"); // Clear the console before printing the updated board
        print_board();
    }
    return 0;
}