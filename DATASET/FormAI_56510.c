//FormAI DATASET v1.0 Category: Game of Life ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the board
#define ROWS 20
#define COLS 40

// Define the maximum number of generations
#define MAX_GEN 100

// Define the colors used to display the grid
#define ALIVE_COLOR "\033[42m"
#define DEAD_COLOR "\033[47m"

// Define the structure of the cells
typedef struct Cell {
    int state;
    int neighbors;
} Cell;

// Create the board of cells
Cell board[ROWS][COLS];

// Count the neighbors of a cell
int count_neighbors(int x, int y) {
    int neighbors = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int row = (x + i + ROWS) % ROWS;
            int col = (y + j + COLS) % COLS;
            neighbors += board[row][col].state;
        }
    }
    neighbors -= board[x][y].state;
    return neighbors;
}

// Update the state of the board
void update_board() {
    for (int x = 0; x < ROWS; x++) {
        for (int y = 0; y < COLS; y++) {
            int neighbors = count_neighbors(x, y);
            board[x][y].neighbors = neighbors;
        }
    }
    for (int x = 0; x < ROWS; x++) {
        for (int y = 0; y < COLS; y++) {
            if (board[x][y].state == 0 && board[x][y].neighbors == 3) {
                board[x][y].state = 1;
            } else if (board[x][y].state == 1 && (board[x][y].neighbors < 2 || board[x][y].neighbors > 3)) {
                board[x][y].state = 0;
            }
        }
    }
}

// Clear the screen
void clear_screen() {
    printf("\033[H\033[J");
}

// Print the board
void print_board() {
    for (int x = 0; x < ROWS; x++) {
        for (int y = 0; y < COLS; y++) {
            if (board[x][y].state == 1) {
                printf(ALIVE_COLOR);
            } else {
                printf(DEAD_COLOR);
            }
            printf(" ");
        }
        printf("\n");
    }
}

// Initialize the board with random values
void initialize_board() {
    srand(time(NULL));
    for (int x = 0; x < ROWS; x++) {
        for (int y = 0; y < COLS; y++) {
            int random = rand() % 2;
            board[x][y].state = random;
        }
    }
}

// Main function
int main() {
    initialize_board();
    int generation = 0;
    while (generation < MAX_GEN) {
        clear_screen();
        printf("Generation: %d\n", generation);
        print_board();
        update_board();
        generation++;
    }
    clear_screen();
    printf("Finished after %d generations.\n", MAX_GEN);
    return 0;
}