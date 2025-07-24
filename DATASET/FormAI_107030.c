//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

// Define constants
#define WIDTH 20
#define HEIGHT 20
#define WALL 1
#define PATH 0

// Define struct to hold cell information
typedef struct cell {
    int x;
    int y;
    bool visited;
    bool left_wall;
    bool right_wall;
    bool top_wall;
    bool bottom_wall;
} Cell;

// Declare global variables
Cell grid[WIDTH][HEIGHT];
int current_x = 0;
int current_y = 0;
bool finished = false;

// Define function to check if a cell is within the grid boundaries
bool is_valid_cell(int x, int y) {
    if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT) {
        return false;
    }
    return true;
}

// Define function to get random direction to move in
int get_random_direction() {
    int directions[] = {0, 1, 2, 3}; // 0 = left, 1 = right, 2 = up, 3 = down
    int num_directions = 4;
    while (num_directions > 0) {
        int random_index = rand() % num_directions;
        int direction = directions[random_index];
        directions[random_index] = directions[num_directions - 1];
        num_directions--;
        if (direction == 0 && is_valid_cell(current_x - 1, current_y) && !grid[current_x - 1][current_y].visited) {
            return direction;
        } else if (direction == 1 && is_valid_cell(current_x + 1, current_y) && !grid[current_x + 1][current_y].visited) {
            return direction;
        } else if (direction == 2 && is_valid_cell(current_x, current_y - 1) && !grid[current_x][current_y - 1].visited) {
            return direction;
        } else if (direction == 3 && is_valid_cell(current_x, current_y + 1) && !grid[current_x][current_y + 1].visited) {
            return direction;
        }
    }
    return -1;
}

// Define function to move to a new cell
void move_to_cell(int direction) {
    if (direction == 0) { // move left
        grid[current_x][current_y].left_wall = false;
        current_x--;
        grid[current_x][current_y].right_wall = false;
    } else if (direction == 1) { // move right
        grid[current_x][current_y].right_wall = false;
        current_x++;
        grid[current_x][current_y].left_wall = false;
    } else if (direction == 2) { // move up
        grid[current_x][current_y].top_wall = false;
        current_y--;
        grid[current_x][current_y].bottom_wall = false;
    } else if (direction == 3) { // move down
        grid[current_x][current_y].bottom_wall = false;
        current_y++;
        grid[current_x][current_y].top_wall = false;
    }
    grid[current_x][current_y].visited = true;
}

// Define function to check if maze is complete (all cells visited)
bool is_maze_complete() {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (!grid[i][j].visited) {
                return false;
            }
        }
    }
    return true;
}

// Define function to print the maze
void print_maze() {
    printf(" ");
    for (int i = 0; i < WIDTH; i++) {
        printf("__");
    }
    printf("\n");
    for (int j = 0; j < HEIGHT; j++) {
        printf("|");
        for (int i = 0; i < WIDTH; i++) {
            if (grid[i][j].bottom_wall) {
                printf("_");
            } else {
                printf(" ");
            }
            if (grid[i][j].right_wall) {
                printf("|");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Define function to generate the maze asynchronously
void *generate_maze_async(void *arg) {
    while (!finished) {
        int direction = get_random_direction();
        if (direction != -1) {
            move_to_cell(direction);
        } else {
            current_x = 0;
            current_y = 0;
            grid[0][0].visited = true;
        }
        if (is_maze_complete()) {
            finished = true;
        }
        usleep(50000); // Sleep for 50 milliseconds to slow down the generation for visualization purposes
    }
    return NULL;
}

// Main function
int main() {
    srand(time(NULL)); // Seed random number generator 
    // Initialize grid with all walls present and all cells unvisited
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            grid[i][j].x = i;
            grid[i][j].y = j;
            grid[i][j].visited = false;
            grid[i][j].left_wall = true;
            grid[i][j].right_wall = true;
            grid[i][j].top_wall = true;
            grid[i][j].bottom_wall = true;
        }
    }
    grid[0][0].visited = true; // Set starting cell as visited
    pthread_t thread;
    pthread_create(&thread, NULL, generate_maze_async, NULL); // Create thread to generate maze asynchronously
    print_maze();
    pthread_join(thread, NULL); // Wait for thread to finish before exiting
    return 0;
}