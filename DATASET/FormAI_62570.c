//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIDE 10 // Size of the maze
#define CELL_SIZE 5 // Size of each cell in the maze
#define WALL 'X' // Character used to represent a wall
#define SPACE ' ' // Character used to represent a space


/**
 * Struct that represents a cell in the maze
 */
typedef struct Cell {
    int id;
    int visited;
    int walls[4]; // 0: top wall, 1: right wall, 2: bottom wall, 3: left wall
    struct Cell* neighbors[4]; // 0: top neighbor, 1: right neighbor, 2: bottom neighbor, 3: left neighbor
} Cell;

/**
 * Function that initializes a new maze with all walls set
 *
 * @param cells The cells array
 */
void initializeMaze(Cell cells[SIDE][SIDE]) {
    int i, j;

    for (i = 0; i < SIDE; i++) {
        for (j = 0; j < SIDE; j++) {
            cells[i][j].id = i * SIDE + j;
            cells[i][j].visited = 0;

            if (i == 0) { // If top row, set top wall
                cells[i][j].walls[0] = 1;
            } else {
                cells[i][j].walls[0] = 0;
            }

            if (j == SIDE - 1) { // If right column, set right wall
                cells[i][j].walls[1] = 1;
            } else {
                cells[i][j].walls[1] = 0;
            }

            if (i == SIDE - 1) { // If bottom row, set bottom wall
                cells[i][j].walls[2] = 1;
            } else {
                cells[i][j].walls[2] = 0;
            }

            if (j == 0) { // If left column, set left wall
                cells[i][j].walls[3] = 1;
            } else {
                cells[i][j].walls[3] = 0;
            }
        }
    }
}

/**
 * Function that prints the maze to the console
 *
 * @param cells The cells array
 */
void printMaze(Cell cells[SIDE][SIDE]) {
    int i, j, k;

    for (i = 0; i < SIDE; i++) {
        for (k = 0; k < CELL_SIZE; k++) { // Print the top wall of each cell in the row
            for (j = 0; j < SIDE; j++) {
                if (cells[i][j].walls[0] == 1) {
                    printf("%c", WALL);
                } else {
                    printf("%c", SPACE);
                }

                int l;
                for (l = 0; l < CELL_SIZE - 1; l++) { // Print space to make cells square
                    printf("%c", SPACE);
                }
            }

            printf("%c\n", SPACE);
        }

        for (k = 0; k < CELL_SIZE; k++) { // Print the middle of each cell in the row
            for (j = 0; j < SIDE; j++) {
                if (cells[i][j].visited == 1) { // Print cell id if visited
                    printf("%d", cells[i][j].id);
                } else {
                    printf("%c", SPACE);
                }

                int l;
                for (l = 0; l < CELL_SIZE - 1; l++) { // Print space to make cells square
                    printf("%c", SPACE);
                }
            }

            printf("%c\n", SPACE);
        }

        for (k = 0; k < CELL_SIZE; k++) { // Print the bottom wall of each cell in the row
            for (j = 0; j < SIDE; j++) {
                if (cells[i][j].walls[2] == 1) {
                    printf("%c", WALL);
                } else {
                    printf("%c", SPACE);
                }

                int l;
                for (l = 0; l < CELL_SIZE - 1; l++) { // Print space to make cells square
                    printf("%c", SPACE);
                }
            }

            printf("%c\n", SPACE);
        }

        for (j = 0; j < SIDE; j++) { // Print the right wall of the last cell in the row
            if (cells[i][j].walls[1] == 1) {
                printf("%c", WALL);
            } else {
                printf("%c", SPACE);
            }

            int l;
            for (l = 0; l < CELL_SIZE - 1; l++) { // Print space to make cells square
                printf("%c", SPACE);
            }
        }

        printf("%c\n", SPACE);
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator with current time

    Cell cells[SIDE][SIDE];

    initializeMaze(cells); // Initialize the maze with all walls set

    // Set starting cell to (0, 0)
    Cell* currentCell = &cells[0][0];
    currentCell->visited = 1;

    // Loop until all cells have been visited
    while (1) {
        // Select a random unvisited neighbor of the current cell
        int neighborIndex;
        Cell* neighbor;

        do {
            neighborIndex = rand() % 4;
            neighbor = currentCell->neighbors[neighborIndex];
        } while (neighbor == NULL || neighbor->visited == 1);

        // Remove the wall between the current cell and the selected neighbor
        switch (neighborIndex) {
            case 0: // Top neighbor
                currentCell->walls[0] = 0;
                neighbor->walls[2] = 0;
                break;
            case 1: // Right neighbor
                currentCell->walls[1] = 0;
                neighbor->walls[3] = 0;
                break;
            case 2: // Bottom neighbor
                currentCell->walls[2] = 0;
                neighbor->walls[0] = 0;
                break;
            case 3: // Left neighbor
                currentCell->walls[3] = 0;
                neighbor->walls[1] = 0;
                break;
        }

        neighbor->visited = 1; // Mark the selected neighbor as visited

        currentCell = neighbor; // Set the current cell to the selected neighbor

        // If all cells have been visited, break out of the loop
        int i, j;
        int finished = 1;
        for (i = 0; i < SIDE; i++) {
            for (j = 0; j < SIDE; j++) {
                if (cells[i][j].visited == 0) {
                    finished = 0;
                    break;
                }
            }

            if (finished == 0) {
                break;
            }
        }

        if (finished == 1) {
            break;
        }
    }

    printMaze(cells); // Print the finalized maze

    return 0;
}