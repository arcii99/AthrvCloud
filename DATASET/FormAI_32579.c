//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20 // Width of maze
#define HEIGHT 10 // Height of maze

typedef struct MazeNode {
    int x, y;
    int visited;
} MazeNode;

int maze[HEIGHT][WIDTH]; // 2D array for maze
MazeNode stack[WIDTH * HEIGHT]; // Stack for tracking nodes during generation
int top = -1; // Top of stack
MazeNode current; // Current node being visited

// Get neighbor nodes of given node
MazeNode* getNeighbors(MazeNode node, MazeNode nodes[4]) {
    int i = 0;

    if (node.x > 0) {
        nodes[i].x = node.x - 1;
        nodes[i].y = node.y;
        nodes[i].visited = maze[nodes[i].y][nodes[i].x];
        i++;
    }

    if (node.x < WIDTH - 1) {
        nodes[i].x = node.x + 1;
        nodes[i].y = node.y;
        nodes[i].visited = maze[nodes[i].y][nodes[i].x];
        i++;
    }

    if (node.y > 0) {
        nodes[i].x = node.x;
        nodes[i].y = node.y - 1;
        nodes[i].visited = maze[nodes[i].y][nodes[i].x];
        i++;
    }

    if (node.y < HEIGHT - 1) {
        nodes[i].x = node.x;
        nodes[i].y = node.y + 1;
        nodes[i].visited = maze[nodes[i].y][nodes[i].x];
        i++;
    }

    return nodes;
}

// Add node to stack
void push(MazeNode node) {
    top++;
    stack[top] = node;
}

// Remove top node from stack
MazeNode pop() {
    MazeNode node = stack[top];
    top--;
    return node;
}

// Generate maze using depth-first search algorithm
void generateMaze() {
    srand(time(NULL)); // Seed random number generator

    // Set all nodes to unvisited
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            maze[y][x] = 0;
        }
    }

    // Choose random starting node and mark as visited
    int startX = rand() % WIDTH;
    int startY = rand() % HEIGHT;
    maze[startY][startX] = 1;
    current.x = startX;
    current.y = startY;
    current.visited = 1;

    // Loop until all nodes have been visited
    while (current.visited) {
        // Get neighbor nodes that have not been visited
        MazeNode nodes[4];
        MazeNode* neighbors = getNeighbors(current, nodes);
        int numNeighbors = 0;
        for (int i = 0; i < 4; i++) {
            if (!neighbors[i].visited) {
                numNeighbors++;
            }
        }

        if (numNeighbors > 0) {
            // Choose random unvisited neighbor and mark as visited
            int randIndex = rand() % numNeighbors;
            int i = 0;
            while (randIndex >= 0) {
                if (!neighbors[i].visited) {
                    randIndex--;
                }
                if (randIndex >= 0) {
                    i++;
                }
            }
            MazeNode next = neighbors[i];
            maze[next.y][next.x] = 1;

            // Remove wall between current node and chosen neighbor
            if (current.x > next.x) {
                maze[current.y][current.x-1] = 1;
            } else if (current.x < next.x) {
                maze[current.y][current.x+1] = 1;
            } else if (current.y > next.y) {
                maze[current.y-1][current.x] = 1;
            } else if (current.y < next.y) {
                maze[current.y+1][current.x] = 1;
            }

            // Add current node to stack and move to new node
            push(current);
            current = next;
            current.visited = 1;
        } else {
            // Move back to previous node if no unvisited neighbors
            current = pop();
        }
    }
}

// Print maze to console
void printMaze() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (maze[y][x]) {
                printf("  ");
            } else {
                printf("\u2588\u2588");
            }
        }
        printf("\n");
    }
}

int main(void) {
    generateMaze(); // Generate maze
    printMaze(); // Print maze to console
    return 0;
}