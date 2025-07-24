//FormAI DATASET v1.0 Category: Game ; Style: scientific
/* 
This program is a simulation of the behavior of a group of cells
It models the generation, mutation and spreading of cells in an environment.
The cells will divide and their genetic code will mutate randomly over time,
with random chance of death and reproduction. The environment is modeled as a 2D grid
 where cells can move and interact with each other.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // Size of the grid
#define INITIAL_CELLS 5 // Number of initial cells
#define MAX_GENERATIONS 500 // Number of generations to run the simulation
#define MUTATION_RATE 0.01 // Mutation rate (percent chance a cell's genetic code will mutate)
#define DEATH_RATE 0.05 // Death rate (percent chance a cell will die in each generation)
#define REPRODUCTION_RATE 0.1 // Reproduction rate (percent chance a cell will reproduce in each generation)

struct Cell {
    int x; // X position on the grid
    int y; // Y position on the grid
    int generation; // Generation number
    char id[10]; // Unique identifier
    int dna[10]; // Genetic code
};

struct Cell grid[SIZE][SIZE]; // 2D grid to store cells

int find_empty_pos(int* x, int* y);
int create_initial_cells();
void print_grid();
void clear_grid();
void move_cells();
int reproduce(int x, int y);
void mutate(int index);

int main() {
    srand(time(NULL));
    int i;
    int total_cells = 0;
    if ((total_cells = create_initial_cells()) == -1) {
        printf("Error creating initial cells");
        return -1;
    }
    printf("Initial cells created: %d\n", total_cells);
    print_grid();
    for (i = 0; i < MAX_GENERATIONS; i++) {
        printf("Generation %d:\n", i+1);
        move_cells();
        int new_cells = 0;
        int j, k;
        for (j = 0; j < SIZE; j++) {
            for (k = 0; k < SIZE; k++) {
                if (grid[j][k].id[0] != '\0') {
                    if ((double)rand()/(double)RAND_MAX < REPRODUCTION_RATE) {
                        int res = reproduce(j, k);
                        if (res == -1) {
                            printf("Error creating new cell\n");
                        } else if (res == 1) {
                            new_cells++;
                        }
                    }
                    double death_chance = (double)rand()/(double)RAND_MAX;
                    if (death_chance < DEATH_RATE) {
                        grid[j][k].id[0] = '\0';
                    }
                    double mutate_chance = (double)rand()/(double)RAND_MAX;
                    if (mutate_chance < MUTATION_RATE) {
                        mutate(j*SIZE + k);
                    }
                }
            }
        }
        printf("Total cells: %d\n", total_cells + new_cells);
        print_grid();
        total_cells += new_cells;
    }
    printf("Simulation completed.\n");
    return 0;
}

// Finds an empty position on the grid and returns it's x and y position
int find_empty_pos(int* x, int* y) {
    int j, k;
    for (j = 0; j < SIZE; j++) {
        for (k = 0; k < SIZE; k++) {
            if (grid[j][k].id[0] == '\0') {
                *x = j;
                *y = k;
                return 1;
            }
        }
    }
    return -1;
}

// Creates the initial cells and places them randomly on the grid
int create_initial_cells() {
    int i;
    int current_cells = 0;
    for (i = 0; i < INITIAL_CELLS; i++) {
        int x, y;
        if (find_empty_pos(&x, &y) == -1) {
            return -1;
        }
        struct Cell cell;
        cell.x = x;
        cell.y = y;
        cell.generation = 0;
        sprintf(cell.id, "Cell%d", current_cells);
        int j;
        for (j = 0; j < 10; j++) {
            cell.dna[j] = rand() % 256;
        }
        grid[x][y] = cell;
        current_cells++;
    }
    return current_cells;
}

// Prints the current generation's grid
void print_grid() {
    int j, k;
    for (j = 0; j < SIZE; j++) {
        for (k = 0; k < SIZE; k++) {
            if (grid[j][k].id[0] == '\0') {
                printf(". ");
            } else {
                printf("%c ", grid[j][k].id[4]);
            }
        }
        printf("\n");
    }
}

// Clears the grid (erases all cells)
void clear_grid() {
    int j, k;
    for (j = 0; j < SIZE; j++) {
        for (k = 0; k < SIZE; k++) {
            grid[j][k].id[0] = '\0';
        }
    }
}

// Moves all the cells randomly on the grid, updating their positions
void move_cells() {
    int j, k;
    for (j = 0; j < SIZE; j++) {
        for (k = 0; k < SIZE; k++) {
            if (grid[j][k].id[0] != '\0') {
                int direction = rand() % 4;
                int new_x = grid[j][k].x;
                int new_y = grid[j][k].y;
                switch (direction) {
                    case 0:
                        new_x--;
                        break;
                    case 1:
                        new_x++;
                        break;
                    case 2:
                        new_y--;
                        break;
                    case 3:
                        new_y++;
                        break;
                }
                if (new_x >= 0 && new_x < SIZE && new_y >= 0 && new_y < SIZE && grid[new_x][new_y].id[0] == '\0') {
                    grid[new_x][new_y] = grid[j][k];
                    grid[new_x][new_y].x = new_x;
                    grid[new_x][new_y].y = new_y;
                    grid[j][k].id[0] = '\0';
                }
            }
        }
    }
}

// Creates a new cell at position (x, y) if the position next to it is empty
int reproduce(int x, int y) {
    int new_x = x, new_y = y;
    int res = find_empty_pos(&new_x, &new_y);
    if (res == -1) {
        return -1;
    } else if (res == 0) {
        return 0;
    }
    struct Cell new_cell;
    new_cell.x = new_x;
    new_cell.y = new_y;
    new_cell.generation = grid[x][y].generation + 1;
    sprintf(new_cell.id, "Cell%d", new_cell.generation);
    int j;
    double mutation_chance = (double)rand()/(double)RAND_MAX;
    if (mutation_chance < MUTATION_RATE) {
        for (j = 0; j < 10; j++) {
            new_cell.dna[j] = grid[x][y].dna[j] + (rand() % 10) - 5;
            if (new_cell.dna[j] < 0) {
                new_cell.dna[j] = 0;
            } else if (new_cell.dna[j] > 255) {
                new_cell.dna[j] = 255;
            }
        }
    } else {
        for (j = 0; j < 10; j++) {
            new_cell.dna[j] = grid[x][y].dna[j];
        }
    }
    grid[new_x][new_y] = new_cell;
    return 1;
}

// Mutates the cell with the given index (in row-major order)
void mutate(int index) {
    int row = index / SIZE;
    int col = index % SIZE;
    int j = rand() % 10;
    grid[row][col].dna[j] = rand() % 256;
}