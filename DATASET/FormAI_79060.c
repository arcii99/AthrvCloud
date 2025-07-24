//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a struct to hold coordinates of each cell in maze
typedef struct {
    int x;
    int y;
} Cell;

// Declare global constants for maze size
const int MAZE_WIDTH = 20;
const int MAZE_HEIGHT = 20;

// Declare global variables for visited and unvisited cells
int visited[20][20] = {0};
int unvisited = MAZE_WIDTH * MAZE_HEIGHT - 1;

// Define a function to generate a random integer within a range
int rand_range(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Define a function to check if a cell is within the maze boundaries
int in_maze(Cell c) {
    return (c.x >= 0 && c.x < MAZE_WIDTH && c.y >= 0 && c.y < MAZE_HEIGHT);
}

// Define a function to get the neighbor cells of a given cell
int get_neighbors(Cell c, Cell neighbors[4]) {
    int count = 0;
    Cell left = {c.x - 1, c.y};
    Cell right = {c.x + 1, c.y};
    Cell up = {c.x, c.y - 1};
    Cell down = {c.x, c.y + 1};
    if (in_maze(left)) {
        neighbors[count] = left;
        count++;
    }
    if (in_maze(right)) {
        neighbors[count] = right;
        count++;
    }
    if (in_maze(up)) {
        neighbors[count] = up;
        count++;
    }
    if (in_maze(down)) {
        neighbors[count] = down;
        count++;
    }
    return count;
}

// Define a function to remove a neighbor from an array of neighbors
void remove_neighbor(Cell neighbors[4], int index, int length) {
    for (int i=index; i<length-1; i++) {
        neighbors[i] = neighbors[i+1];
    }
}

// Define main function
int main() {
    srand(time(0)); // Seed random number generator with system time
    Cell current = {0, 0}; // Initialize current cell to top-left corner
    visited[0][0] = 1; // Mark starting cell as visited
    unvisited--; // Decrement count of unvisited cells
    while (unvisited > 0) { // Loop until all cells have been visited
        Cell neighbors[4];
        int num_neighbors = get_neighbors(current, neighbors); // Get neighbor cells
        if (num_neighbors > 0) { // If there are unvisited neighbors
            int rand_index = rand_range(0, num_neighbors-1); // Choose a random neighbor
            Cell next = neighbors[rand_index];
            remove_neighbor(neighbors, rand_index, num_neighbors); // Remove chosen neighbor from array
            for (int i=0; i<num_neighbors-1; i++) { // Mark all other neighbors as blocked
                Cell blocked = neighbors[i];
                visited[blocked.x][blocked.y] = -1;
                unvisited--;
            }
            if (visited[next.x][next.y] == 0) { // If chosen neighbor is unvisited
                visited[next.x][next.y] = 1; // Mark as visited
                unvisited--; // Decrement count of unvisited cells
                if (next.x < current.x) { // Check direction of movement
                    printf("Move left\n"); // Output movement direction for futuristic feel
                } else if (next.x > current.x) {
                    printf("Move right\n");
                } else if (next.y < current.y) {
                    printf("Move up\n");
                } else {
                    printf("Move down\n");
                }
                current = next; // Move to chosen neighbor
            }
        } else { // If all neighbors are visited or blocked
            visited[current.x][current.y] = -1; // Mark current cell as blocked
            unvisited--;
            Cell backtrack = {0, 0};
            int num_backtrack = get_neighbors(current, neighbors); // Get neighbor cells
            for (int i=0; i<num_backtrack; i++) { // Check all neighbors for visited cells
                Cell neighbor = neighbors[i];
                if (visited[neighbor.x][neighbor.y] == 1) {
                    backtrack = neighbor; // Choose first visited neighbor as backtrack cell
                    break;
                }
            }
            if (backtrack.x < current.x) { // Check direction of movement
                printf("Backtrack left\n"); // Output movement direction for futuristic feel
            } else if (backtrack.x > current.x) {
                printf("Backtrack right\n");
            } else if (backtrack.y < current.y) {
                printf("Backtrack up\n");
            } else {
                printf("Backtrack down\n");
            }
            current = backtrack; // Move to backtrack cell
        }
    }
    printf("You have reached the center of the maze. Congratulations!\n"); // Output message for reaching the end
    return 0;
}