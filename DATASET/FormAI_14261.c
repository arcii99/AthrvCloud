//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define ROW 6
#define COL 6

// structure to store coordinates of a node
typedef struct node {
    int x;
    int y;
} Node;

// structure to represent a cell in the grid
typedef struct cell {
    bool isWall;
    int f; // f = g + h
    int g; // cost of path from start node to current node
    int h; // heuristic cost
    Node parent;
} Cell;

// declare the grid of cells
Cell grid[ROW][COL];

// declare variables for start and end node coordinates
Node start, end;

// function to calculate the Manhattan distance between two nodes
int getManhattanDistance(Node a, Node b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

// function to explore neighbors of a cell
void exploreNeighbors(Node current) {
    int x = current.x;
    int y = current.y;
    int newG;

    // check top neighbor
    if (y > 0 && !grid[x][y - 1].isWall) {
        newG = grid[x][y].g + 1;
        if (newG < grid[x][y - 1].g) {
            grid[x][y - 1].g = newG;
            grid[x][y - 1].parent = current;
            grid[x][y - 1].h = getManhattanDistance((Node) {x, y - 1}, end);
            grid[x][y - 1].f = grid[x][y - 1].g + grid[x][y - 1].h;
        }
    }

    // check right neighbor
    if (x < ROW - 1 && !grid[x + 1][y].isWall) {
        newG = grid[x][y].g + 1;
        if (newG < grid[x + 1][y].g) {
            grid[x + 1][y].g = newG;
            grid[x + 1][y].parent = current;
            grid[x + 1][y].h = getManhattanDistance((Node) {x + 1, y}, end);
            grid[x + 1][y].f = grid[x + 1][y].g + grid[x + 1][y].h;
        }
    }

    // check bottom neighbor
    if (y < COL - 1 && !grid[x][y + 1].isWall) {
        newG = grid[x][y].g + 1;
        if (newG < grid[x][y + 1].g) {
            grid[x][y + 1].g = newG;
            grid[x][y + 1].parent = current;
            grid[x][y + 1].h = getManhattanDistance((Node) {x, y + 1}, end);
            grid[x][y + 1].f = grid[x][y + 1].g + grid[x][y + 1].h;
        }
    }

    // check left neighbor
    if (x > 0 && !grid[x - 1][y].isWall) {
        newG = grid[x][y].g + 1;
        if (newG < grid[x - 1][y].g) {
            grid[x - 1][y].g = newG;
            grid[x - 1][y].parent = current;
            grid[x - 1][y].h = getManhattanDistance((Node) {x - 1, y}, end);
            grid[x - 1][y].f = grid[x - 1][y].g + grid[x - 1][y].h;
        }
    }
}

// function to find the cell with the lowest f value in the open list
Node getNodeWithLowestFValue() {
    int minF = INT_MAX;
    Node minNode;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (grid[i][j].f < minF && grid[i][j].f > 0) {
                minF = grid[i][j].f;
                minNode = (Node) {i, j};
            }
        }
    }
    return minNode;
}

// function to print the path from start to end
void printPath() {
    Node current = end;
    while ((current.x != start.x) || (current.y != start.y)) {
        printf("(%d,%d) -> ", current.x, current.y);
        current = grid[current.x][current.y].parent;
    }
    printf("(%d,%d)\n", start.x, start.y);
}

// function to check if the end node has been reached
bool isEndReached() {
    return grid[end.x][end.y].parent.x != -1;
}

// main function
int main() {
    // initialize the grid
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            grid[i][j] = (Cell) {
                .isWall = false,
                .f = INT_MAX,
                .g = INT_MAX,
                .h = INT_MAX,
                .parent = (Node) {-1, -1}
            };
        }
    }

    // mark the walls in the grid
    grid[1][2].isWall = true;
    grid[2][2].isWall = true;
    grid[3][2].isWall = true;
    grid[4][2].isWall = true;

    // set the start and end node coordinates
    start = (Node) {0, 0};
    end = (Node) {5, 5};

    // initialize the start node
    grid[start.x][start.y].f = 0;
    grid[start.x][start.y].g = 0;
    grid[start.x][start.y].h = getManhattanDistance(start, end);

    // A* algorithm loop
    while (!isEndReached()) {
        // get the node with the lowest f value
        Node current = getNodeWithLowestFValue();

        // explore its neighbors
        exploreNeighbors(current);

        // set its f value to 0 so it won't be explored again
        grid[current.x][current.y].f = 0;
    }

    // print the path from start to end
    printPath();

    return 0;
}