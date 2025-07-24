//FormAI DATASET v1.0 Category: Game of Life ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

// dimensions of the grid
#define ROWS 25
#define COLS 50

// number of generations to run the simulation
#define GENERATIONS 50

// representation of a cell in the grid
typedef struct {
    int state; // 0 = dead, 1 = alive
    int next_state;
} Cell;

// representation of the grid
typedef struct {
    Cell cells[ROWS][COLS];
    int generation;
} Grid;

// function that initializes the grid with random values
void initialize_grid(Grid *grid) {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int state = rand() % 2;
            grid->cells[i][j].state = state;
            grid->cells[i][j].next_state = state;
        }
    }
}

// function that prints the grid to the console
void print_grid(Grid *grid) {
    printf("Generation: %d\n", grid->generation);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            char symbol = grid->cells[i][j].state == 1 ? '*' : '-';
            putchar(symbol);
        }
        putchar('\n');
    }
}

// function that counts the number of alive neighbors of a cell
int count_neighbors(Grid *grid, int row, int col) {
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i == row && j == col) continue; // skip current cell
            
            int r = (i + ROWS) % ROWS; // handle edge cases
            int c = (j + COLS) % COLS;
            
            count += grid->cells[r][c].state;
        }
    }
    return count;
}

// function that updates the state of a cell according to the rules of the Game of Life
void update_cell(Grid *grid, int row, int col) {
    Cell *cell = &grid->cells[row][col];
    int neighbors = count_neighbors(grid, row, col);
    
    if (cell->state == 1 && (neighbors < 2 || neighbors > 3)) {
        cell->next_state = 0; // cell dies of loneliness or overcrowding
    } else if (cell->state == 0 && neighbors == 3) {
        cell->next_state = 1; // cell is born
    } else {
        cell->next_state = cell->state; // cell stays the same
    }
}

// function that updates all cells in the grid
void update_grid(Grid *grid) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            update_cell(grid, i, j);
        }
    }
    
    // copy next_state to state
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid->cells[i][j].state = grid->cells[i][j].next_state;
        }
    }
    
    grid->generation++;
}

// function that runs the simulation for a given number of generations
void run_simulation(Grid *grid, int num_generations) {
    for (int i = 0; i < num_generations; i++) {
        update_grid(grid);
    }
}

// threaded function that updates the grid every second
void* update_thread(void *arg) {
    Grid *grid = (Grid*) arg;
    while (1) {
        usleep(1000000); // sleep for 1 second
        update_grid(grid);
    }
}

int main() {
    Grid grid;
    initialize_grid(&grid);
    pthread_t thread;
    pthread_create(&thread, NULL, update_thread, (void*) &grid);
    while (1) {
        print_grid(&grid);
        usleep(100000); // sleep for 0.1 seconds
    }
    return 0;
}