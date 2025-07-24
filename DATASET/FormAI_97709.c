//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10  // Size of the grid
#define OBSTACLE 1  // Obstacle in the grid
#define FREE 0  // Free path in the grid

struct node {
    int x, y;  // Coordinates of the node
    int f, g, h;  // Used in A* algorithm for pathfinding 
};

int grid[SIZE][SIZE];  // The grid in which the pathfinding takes place
struct node start, end;  // Start and end points for the pathfinding

// Calculates the distance between two nodes
int distance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// Returns the node with the lowest F score from the open set of nodes
struct node getLowestF(struct node openSet[]) {
    struct node lowestF = openSet[0];
    for (int i = 1; i < SIZE*SIZE; i++) {
        if (openSet[i].f < lowestF.f)
            lowestF = openSet[i];
    }
    return lowestF;
}

// Returns an array of nodes representing the path from the start to end nodes
struct node* getPath(struct node cameFrom[]) {
    struct node* path = (struct node*) malloc(sizeof(struct node) * SIZE*SIZE);
    struct node currentNode = end;
    int pathLength = 0;
    while (currentNode.x != start.x || currentNode.y != start.y) {
        path[pathLength++] = currentNode;
        currentNode = cameFrom[currentNode.x*SIZE + currentNode.y];
    }
    path[pathLength++] = start;
    return path;
}

// A* pathfinding algorithm
struct node* aStar() {
    struct node* path = NULL;
    int closedSet[SIZE*SIZE] = {0};
    struct node openSet[SIZE*SIZE] = {{0, 0, 0, 0, 0}};  
    int openSetIndex = 0;
    int gScore[SIZE*SIZE] = {0};
    for (int i = 0; i < SIZE*SIZE; i++)
        gScore[i] = SIZE*SIZE;
    gScore[start.x*SIZE + start.y] = 0;
    start.f = distance(start.x, start.y, end.x, end.y);
    openSet[openSetIndex++] = start;

    struct node cameFrom[SIZE*SIZE] = {{0, 0, 0, 0, 0}};

    while (openSetIndex > 0) {
        struct node current = getLowestF(openSet);
        if (current.x == end.x && current.y == end.y) {
            path = getPath(cameFrom);
            return path;
        }
        openSet[current.x*SIZE + current.y].f = SIZE*SIZE;
        closedSet[current.x*SIZE + current.y] = 1;

        // Check neighbours of current node
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0)
                    continue;
                int neighbourX = current.x + dx;
                int neighbourY = current.y + dy;
                if (neighbourX < 0 || neighbourX >= SIZE || neighbourY < 0 || neighbourY >= SIZE)
                    continue;
                if (grid[neighbourX][neighbourY] == OBSTACLE)
                    continue;
                if (closedSet[neighbourX*SIZE + neighbourY] == 1)
                    continue;

                int tentativeGScore = gScore[current.x*SIZE + current.y] + 1;
                if (tentativeGScore < gScore[neighbourX*SIZE + neighbourY]) {
                    cameFrom[neighbourX*SIZE + neighbourY] = current;
                    gScore[neighbourX*SIZE + neighbourY] = tentativeGScore;
                    grid[neighbourX][neighbourY] = FREE;
                    struct node neighbourNode = {neighbourX, neighbourY, 0, 0, 0};
                    neighbourNode.h = distance(neighbourX, neighbourY, end.x, end.y);
                    neighbourNode.f = gScore[neighbourX*SIZE + neighbourY] + neighbourNode.h;
                    openSet[openSetIndex++] = neighbourNode;
                }
            }
        }
    }
    return path;
}

int main() {
    // Initialise the grid
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = FREE;
        }
    }
    // Add obstacles to the grid
    grid[4][2] = OBSTACLE;
    grid[4][3] = OBSTACLE;
    grid[4][4] = OBSTACLE;
    grid[4][5] = OBSTACLE;
    grid[4][6] = OBSTACLE;
    grid[4][7] = OBSTACLE;
    grid[4][8] = OBSTACLE;

    // Set start and end points
    start.x = 3;
    start.y = 0;
    end.x = 3;
    end.y = 9;

    // Run the A* algorithm to find the path
    struct node* path = aStar();

    // Print the path
    printf("The path from (%d,%d) to (%d,%d) is:\n", start.x, start.y, end.x, end.y);
    for (int i = 0; i < SIZE*SIZE; i++) {
        if (path[i].x != 0 || path[i].y != 0)
            printf("(%d,%d) ", path[i].x, path[i].y);
    }
    return 0;
}