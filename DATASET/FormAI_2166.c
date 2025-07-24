//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The size of maze (must be an odd number)
#define SIZE 21

// The symbol for path and wall
#define PATH ' '
#define WALL '#'

// The direction of movement
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

// The status of cell
#define UNVISITED 0
#define VISITED 1

// The structure of cell
struct cell {
    int x;
    int y;
    int status;
    int wall[4];
};

// The array of maze
struct cell maze[SIZE][SIZE];

// A stack to keep track of path
struct cell stack[SIZE * SIZE];
int top = -1;

// Function prototypes
void generateMaze();
void printMaze();
int dfs(int, int);
int isWall(int, int, int);
int isVisited(int, int, int);
void push(struct cell);
struct cell pop();
int isEmpty();

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate the maze
    generateMaze();

    // Print the maze
    printMaze();

    // Solve the maze
    if (dfs(1, 1)) {
        // The maze has been solved
        printf("\nRoute found!\n");
    } else {
        // The maze cannot be solved
        printf("\nRoute not found!\n");
    }

    return 0;
}

// Function to generate the maze
void generateMaze() {
    int x, y, i, dx, dy;

    // Initialize all cells to be unvisited
    for (x = 0; x < SIZE; x++) {
        for (y = 0; y < SIZE; y++) {
            maze[x][y].x = x;
            maze[x][y].y = y;
            maze[x][y].status = UNVISITED;
            for (i = 0; i < 4; i++) {
                maze[x][y].wall[i] = 1;
            }
        }
    }

    // Choose a random starting cell
    x = rand() % ((SIZE - 1) / 2) * 2 + 1;
    y = rand() % ((SIZE - 1) / 2) * 2 + 1;

    // Mark the starting cell as visited
    maze[x][y].status = VISITED;

    // Generate the maze with the Depth-first search algorithm
    do {
        // Choose a random neighbor of the current cell
        do {
            i = rand() % 4;
            dx = (i == 1) - (i == 3);
            dy = (i == 0) - (i == 2);
        } while (isVisited(x + dx, y + dy, VISITED));

        // Break the wall between the current cell and the neighbor
        maze[x][y].wall[i] = 0;
        maze[x + dx][y + dy].wall[(i + 2) % 4] = 0;

        // Move to the neighbor cell
        x += dx;
        y += dy;

        // Mark the neighbor cell as visited
        maze[x][y].status = VISITED;

        // Push the current cell into the stack
        push(maze[x][y]);
    } while (!isEmpty());
}

// Function to print the maze
void printMaze() {
    int x, y, i;

    // Print the top border
    for (i = 0; i < SIZE + 2; i++) {
        putchar(WALL);
    }
    putchar('\n');

    // Print the cells
    for (y = 0; y < SIZE; y++) {
        putchar(WALL);
        for (x = 0; x < SIZE; x++) {
            if (x == 1 && y == 0) {
                putchar('S');
            } else if (x == SIZE - 2 && y == SIZE - 1) {
                putchar('E');
            } else if (maze[x][y].status == UNVISITED) {
                putchar(WALL);
            } else {
                putchar(PATH);
            }
            if (maze[x][y].wall[EAST]) {
                putchar(WALL);
            } else {
                putchar(PATH);
            }
        }
        putchar('\n');
        if (y < SIZE - 1) {
            for (x = 0; x < SIZE; x++) {
                if (maze[x][y].wall[SOUTH]) {
                    putchar(WALL);
                } else {
                    putchar(PATH);
                }
                putchar(WALL);
            }
            putchar('\n');
        }
    }

    // Print the bottom border
    for (i = 0; i < SIZE + 2; i++) {
        putchar(WALL);
    }
    putchar('\n');
}

// Function to solve the maze with Depth-first search algorithm
int dfs(int x, int y) {
    int i, found = 0;

    push(maze[x][y]);

    while (!isEmpty() && !found) {
        struct cell current = pop();
        x = current.x;
        y = current.y;

        if (x == SIZE - 2 && y == SIZE - 2) {
            found = 1;
        } else {
            maze[x][y].status = VISITED;

            for (i = 0; i < 4; i++) {
                if (!isWall(x, y, i) && !isVisited(x, y, VISITED)) {
                    push(maze[x][y]);
                    x += (i == 1) - (i == 3);
                    y += (i == 0) - (i == 2);
                    push(maze[x][y]);
                }
            }
        }
    }

    return found;
}

// Function to check if a wall exists
int isWall(int x, int y, int d) {
    return maze[x][y].wall[d];
}

// Function to check if a cell has been visited
int isVisited(int x, int y, int s) {
    return maze[x][y].status == s;
}

// Function to push a cell into the stack
void push(struct cell c) {
    stack[++top] = c;
}

// Function to pop a cell from the stack
struct cell pop() {
    return stack[top--];
}

// Function to check if the stack is empty
int isEmpty() {
    return top == -1;
}