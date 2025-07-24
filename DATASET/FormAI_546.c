//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// Function to print the maze
void print_maze(int maze[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (maze[i][j] == 0) {
                printf("# ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int maze[SIZE][SIZE]; // The maze, represented as a 2D array
    int stack[SIZE * SIZE]; // Stack for the DFS algorithm
    int visited[SIZE * SIZE]; // Array to keep track of visited nodes
    int curr_node, next_node, stack_top = -1;

    // Initialize the maze to be all walls
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            maze[i][j] = 0;
        }
    }

    // Pick a random starting node
    curr_node = rand() % (SIZE * SIZE);

    // Mark the starting node as visited and push it onto the stack
    visited[curr_node] = 1;
    stack[++stack_top] = curr_node;

    // DFS algorithm to carve out the maze
    while (stack_top >= 0) {
        curr_node = stack[stack_top--];

        // Check if the current node has any unvisited neighbors
        int neighbors[4];
        int num_neighbors = 0;
        int row = curr_node / SIZE;
        int col = curr_node % SIZE;

        if (row > 0 && !visited[curr_node - SIZE]) {
            neighbors[num_neighbors++] = curr_node - SIZE;
        }
        if (col < SIZE - 1 && !visited[curr_node + 1]) {
            neighbors[num_neighbors++] = curr_node + 1;
        }
        if (row < SIZE - 1 && !visited[curr_node + SIZE]) {
            neighbors[num_neighbors++] = curr_node + SIZE;
        }
        if (col > 0 && !visited[curr_node - 1]) {
            neighbors[num_neighbors++] = curr_node - 1;
        }

        // If there are unvisited neighbors, pick one at random and carve
        // a path through to it
        if (num_neighbors > 0) {
            next_node = neighbors[rand() % num_neighbors];

            int next_row = next_node / SIZE;
            int next_col = next_node % SIZE;

            if (next_node == curr_node - SIZE) { // Move up
                maze[row][col] |= 1 << 0;
                maze[next_row][next_col] |= 1 << 2;
            } else if (next_node == curr_node + 1) { // Move right
                maze[row][col] |= 1 << 1;
                maze[next_row][next_col] |= 1 << 3;
            } else if (next_node == curr_node + SIZE) { // Move down
                maze[row][col] |= 1 << 2;
                maze[next_row][next_col] |= 1 << 0;
            } else { // Move left
                maze[row][col] |= 1 << 3;
                maze[next_row][next_col] |= 1 << 1;
            }

            visited[next_node] = 1;
            stack[++stack_top] = curr_node;
            stack[++stack_top] = next_node;
        }
    }

    // Print the final maze
    print_maze(maze);

    return 0;
}