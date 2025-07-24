//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 10

// Create a struct to hold cell coordinates
typedef struct cell {
    int x;
    int y;
} cell;

// Function to randomly shuffle an array
void shuffle(int *arr, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Function to generate the maze
void generateMaze(int maze[][MAZE_SIZE]) {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the maze with walls
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            maze[i][j] = 1;
        }
    }

    // Select a random starting point
    int startX = rand() % MAZE_SIZE;
    int startY = rand() % MAZE_SIZE;
    maze[startX][startY] = 0;

    // Initialize stack for backtracking
    cell stack[MAZE_SIZE * MAZE_SIZE];
    int top = 0;

    // Push the starting cell onto the stack
    cell start = {startX, startY};
    stack[top] = start;

    // Loop until the stack is empty
    while (top >= 0) {
        // Pop the top cell from the stack
        cell currentCell = stack[top];
        top--;

        // Generate a random shuffle order of directions
        int directions[] = {1, 2, 3, 4};
        shuffle(directions, 4);

        // Loop through each direction
        for (int i = 0; i < 4; i++) {
            // Initialize variables to track neighbor cell coordinates
            int neighborX = currentCell.x;
            int neighborY = currentCell.y;

            // Move to the neighbor cell according to the direction
            switch (directions[i]) {
                case 1: // Up
                    if (currentCell.x > 0) {
                        neighborX--;
                    }
                    break;
                case 2: // Down
                    if (currentCell.x < MAZE_SIZE - 1) {
                        neighborX++;
                    }
                    break;
                case 3: // Left
                    if (currentCell.y > 0) {
                        neighborY--;
                    }
                    break;
                case 4: // Right
                    if (currentCell.y < MAZE_SIZE - 1) {
                        neighborY++;
                    }
                    break;
            }

            // Check if the neighbor cell is in bounds and unvisited
            if (neighborX >= 0 && neighborX < MAZE_SIZE && neighborY >= 0 && neighborY < MAZE_SIZE && maze[neighborX][neighborY] == 1) {
                // Break down the wall between the current cell and neighbor cell
                if (directions[i] == 1) {
                    maze[currentCell.x][currentCell.y] &= ~1; // Remove north wall
                    maze[neighborX][neighborY] &= ~2; // Remove south wall
                }
                else if (directions[i] == 2) {
                    maze[currentCell.x][currentCell.y] &= ~2; // Remove south wall
                    maze[neighborX][neighborY] &= ~1; // Remove north wall
                }
                else if (directions[i] == 3) {
                    maze[currentCell.x][currentCell.y] &= ~4; // Remove west wall
                    maze[neighborX][neighborY] &= ~8; // Remove east wall
                }
                else if (directions[i] == 4) {
                    maze[currentCell.x][currentCell.y] &= ~8; // Remove east wall
                    maze[neighborX][neighborY] &= ~4; // Remove west wall
                }

                // Mark the neighbor cell as visited and push onto stack
                maze[neighborX][neighborY] = 0;
                cell neighbor = {neighborX, neighborY};
                top++;
                stack[top] = neighbor;
            }
        }
    }
}

// Function to print the maze
void printMaze(int maze[][MAZE_SIZE]) {
    for (int i = 0; i < MAZE_SIZE; i++) {
        // Print top wall of row
        printf("+");
        for (int j = 0; j < MAZE_SIZE; j++) {
            printf("%s", (maze[i][j] & 1) ? "---" : "   ");
            printf("+");
        }
        printf("\n");

        // Print left and right walls of row
        printf("|");
        for (int j = 0; j < MAZE_SIZE; j++) {
            printf(" %s ", (maze[i][j] & 8) ? "|" : " ");
        }
        printf("|");
        printf("\n");
    }

    // Print bottom wall of maze
    printf("+");
    for (int j = 0; j < MAZE_SIZE; j++) {
        printf("---+");
    }
    printf("\n");
}

// Main function to run the program
int main() {
    // Initialize the maze
    int maze[MAZE_SIZE][MAZE_SIZE];
    generateMaze(maze);

    // Print the maze
    printMaze(maze);

    return 0;
}