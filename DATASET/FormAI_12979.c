//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define ROW 6
#define COL 8

// Struct to represent the cell of the grid
struct cell {
    int row;
    int col;
    int f_cost;
    int g_cost;
    int h_cost;
    bool is_obstacle;
    struct cell* parent;
    pthread_mutex_t lock;
};

int start_row = 0;
int start_col = 0;
int end_row = 5;
int end_col = 7;

struct cell grid[ROW][COL];

// Function to initialize the grid
void init_grid() {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            grid[i][j].row = i;
            grid[i][j].col = j;
            grid[i][j].f_cost = -1;
            grid[i][j].g_cost = -1;
            grid[i][j].h_cost = -1;
            grid[i][j].is_obstacle = false;
            grid[i][j].parent = NULL;
            pthread_mutex_init(&grid[i][j].lock, NULL);
        }
    }
}

// Function to set obstacles in the grid
void set_obstacles() {
    grid[2][2].is_obstacle = true;
    grid[2][3].is_obstacle = true;
    grid[3][3].is_obstacle = true;
    grid[4][3].is_obstacle = true;
    grid[4][4].is_obstacle = true;
}

// Function to calculate the Manhattan distance
int manhattan_distance(int row, int col) {
    return abs(row - end_row) + abs(col - end_col);
}

// Function to check if a cell is traversable
bool is_traversable(int row, int col) {
    if (row < 0 || row >= ROW || col < 0 || col >= COL || grid[row][col].is_obstacle) {
        return false;
    }
    return true;
}

// Function to update the f_cost, g_cost and h_cost values of a cell
void update_cell(struct cell *current, struct cell *successor) {
    successor->g_cost = current->g_cost + 1;
    successor->h_cost = manhattan_distance(successor->row, successor->col);
    successor->f_cost = successor->g_cost + successor->h_cost;
    successor->parent = current;
}

// Function to check if a cell is the end cell
bool is_end_cell(int row, int col) {
    if (row == end_row && col == end_col) {
        return true;
    }
    return false;
}

// Function to return the cell with the lowest f_cost in the open list
struct cell* get_lowest_f_cost_cell(struct cell* open_list[]) {
    struct cell* lowest_cost_cell = NULL;
    int min_f_cost = -1;
    int i;
    for (i = 0; i < ROW * COL; i++) {
        if (open_list[i] != NULL) {
            if (lowest_cost_cell == NULL || open_list[i]->f_cost < min_f_cost) {
                lowest_cost_cell = open_list[i];
                min_f_cost = lowest_cost_cell->f_cost;
            }
        }
    }
    return lowest_cost_cell;
}

// Function to add a cell to the open list
void add_to_open_list(struct cell* open_list[], struct cell* cell) {
    int i;
    for (i = 0; i < ROW * COL; i++) {
        if (open_list[i] == NULL) {
            pthread_mutex_lock(&cell->lock);
            open_list[i] = cell;
            pthread_mutex_unlock(&cell->lock);
            break;
        }
    }
}

// Function to remove a cell from the open list
void remove_from_open_list(struct cell* open_list[], struct cell* cell) {
    int i;
    for (i = 0; i < ROW * COL; i++) {
        if (open_list[i] == cell) {
            pthread_mutex_lock(&cell->lock);
            open_list[i] = NULL;
            pthread_mutex_unlock(&cell->lock);
            break;
        }
    }
}

// Function to check if a cell is in the open list
bool cell_in_open_list(struct cell* open_list[], struct cell* cell) {
    int i;
    for (i = 0; i < ROW * COL; i++) {
        if (open_list[i] == cell) {
            return true;
        }
    }
    return false;
}

// Function to free the allocated memory
void free_memory(struct cell* open_list[], struct cell* closed_list[]) {
    int i;
    for (i = 0; i < ROW * COL; i++) {
        if (open_list[i] != NULL) {
            free(open_list[i]);
        }
        if (closed_list[i] != NULL) {
            free(closed_list[i]);
        }
    }
}

// Function to print the path from start to end cell
void print_path(struct cell *current) {
    printf("Path: ");
    while (current != NULL) {
        printf("(%d, %d) ", current->row, current->col);
        current = current->parent;
    }
}

// Function to run the A* Algorithm
void* run_a_star_algorithm() {
    struct cell* open_list[ROW * COL];
    struct cell* closed_list[ROW * COL];
    int i, j, k;
    for (i = 0; i < ROW * COL; i++) {
        open_list[i] = NULL;
        closed_list[i] = NULL;
    }
    add_to_open_list(open_list, &grid[start_row][start_col]);
    while (true) {
        struct cell* current = get_lowest_f_cost_cell(open_list);
        if (current == NULL) {
            printf("No path found!\n");
            break;
        }
        if (is_end_cell(current->row, current->col)) {
            print_path(current);
            break;
        }
        remove_from_open_list(open_list, current);
        closed_list[k++] = current;
        for (i = -1; i <= 1; i++) {
            for (j = -1; j <= 1; j++) {
                if (is_traversable(current->row + i, current->col + j)) {
                    struct cell* successor = &grid[current->row + i][current->col + j];
                    if (cell_in_open_list(open_list, successor)) {
                        if (current->g_cost + 1 < successor->g_cost) {
                            update_cell(current, successor);
                        }
                    } else if (cell_in_open_list(closed_list, successor)) {
                        if (current->g_cost + 1 < successor->g_cost) {
                            update_cell(current, successor);
                            add_to_open_list(open_list, successor);
                        }
                    } else {
                        update_cell(current, successor);
                        add_to_open_list(open_list, successor);
                    }
                }
            }
        }
    }
    free_memory(open_list, closed_list);
}

int main() {
    init_grid();
    set_obstacles();

    pthread_t thread;
    pthread_create(&thread, NULL, run_a_star_algorithm, NULL);
    pthread_join(thread, NULL);

    return 0;
}