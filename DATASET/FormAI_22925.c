//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// Define directions
enum directions {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

// Maze cell struct
typedef struct cell {
    int x;
    int y;
    int walls[4]; // [up, down, left, right]: 1 if wall exists, 0 if not
    bool visited;
} Cell;

// Initialize maze
void init_maze(Cell maze[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j].x = i;
            maze[i][j].y = j;
            maze[i][j].visited = false;
            maze[i][j].walls[UP] = 1;
            maze[i][j].walls[DOWN] = 1;
            maze[i][j].walls[LEFT] = 1;
            maze[i][j].walls[RIGHT] = 1;
        }
    }
}

// Check if cell is in bounds
bool in_bounds(int x, int y) {
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS);
}

// Check if cell has unvisited neighbors
bool has_unvisited_neighbors(Cell maze[][COLS], Cell curr) {
    int x = curr.x;
    int y = curr.y;
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < 4; i++) {
        int new_x = x + dirs[i][0];
        int new_y = y + dirs[i][1];
        if (in_bounds(new_x, new_y) && !maze[new_x][new_y].visited) {
            return true;
        }
    }
    return false;
}

// Remove wall between two adjacent cells
void remove_wall(Cell *cell1, Cell *cell2) {
    int x_diff = cell1->x - cell2->x;
    int y_diff = cell1->y - cell2->y;
    if (x_diff == 1) { // Left cell is adjacent to the right cell
        cell1->walls[LEFT] = 0;
        cell2->walls[RIGHT] = 0;
    } else if (x_diff == -1) { // Right cell is adjacent to the left cell
        cell1->walls[RIGHT] = 0;
        cell2->walls[LEFT] = 0;
    } else if (y_diff == 1) { // Up cell is adjacent to the down cell
        cell1->walls[UP] = 0;
        cell2->walls[DOWN] = 0;
    } else if (y_diff == -1) { // Down cell is adjacent to the up cell
        cell1->walls[DOWN] = 0;
        cell2->walls[UP] = 0;
    }
}

// Generate maze using depth first search algorithm
void generate_maze(Cell maze[][COLS]) {
    Cell *curr = &maze[0][0]; // Start at top-left corner
    curr->visited = true;
    int stack_x[ROWS * COLS];
    int stack_y[ROWS * COLS];
    int stack_len = 0;
    while (curr != &maze[ROWS-1][COLS-1]) { // Continue until end has been reached
        if (has_unvisited_neighbors(maze, *curr)) {
            int x = curr->x;
            int y = curr->y;
            stack_x[stack_len] = x;
            stack_y[stack_len] = y;
            stack_len++;
            int neighbors[4][2] = {{x-1, y}, {x+1, y}, {x, y-1}, {x, y+1}};
            while (true) {
                int rand_dir = rand() % 4; // Choose random direction
                int new_x = neighbors[rand_dir][0];
                int new_y = neighbors[rand_dir][1];
                if (in_bounds(new_x, new_y) && !maze[new_x][new_y].visited) {
                    remove_wall(curr, &maze[new_x][new_y]);
                    curr = &maze[new_x][new_y];
                    curr->visited = true;
                    break;
                }
            }
        } else if (stack_len > 0) { // Backtrack if there are no unvisited neighbors
            stack_len--;
            curr = &maze[stack_x[stack_len]][stack_y[stack_len]];
        }
    }
}

// Print maze
void print_maze(Cell maze[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("+");
            if (maze[i][j].walls[UP]) {
                printf("---");
            } else {
                printf("   ");
            }
        }
        printf("+\n");
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j].walls[LEFT]) {
                printf("|");
            } else {
                printf(" ");
            }
            printf("   ");
            if (j == COLS - 1) {
                printf("|");
            }
        }
        printf("\n");
    }
    for (int j = 0; j < COLS; j++) {
        printf("+---");
    }
    printf("+\n");
}

int main() {
    srand(time(NULL));
    Cell maze[ROWS][COLS];
    init_maze(maze);
    generate_maze(maze);
    print_maze(maze);
    return 0;
}