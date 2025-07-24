//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ROW 6
#define COL 6

struct Point {
    int x, y;
};

struct Node {
    struct Point pos;
    int f, g, h;
    struct Node *parent;
};

// Heuristic function to estimate the distance from Point A to Point B
int heuristic(struct Point a, struct Point b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

// Function to check if the given point is valid or not
int isValid(int x, int y)
{
    // return true if x and y are within the boundaries of the grid
    return (x >= 0) && (x < ROW) && (y >= 0) && (y < COL);
}

// Function to check if the given point is blocked or not
int isBlocked(int grid[][COL], int x, int y) {
    // return true if the cell is not accessible (blocker)
    return (grid[x][y] == 1);   
}

// Function to trace the path from start to end
void tracePath(struct Node *dest) {
    if(dest == NULL) {
        return;
    }

    tracePath(dest->parent);
    printf("(%d, %d)\n", dest->pos.x, dest->pos.y);
}

// Function to A* Search Algorithm to find the shortest path from start to end
void astar(int grid[][COL], struct Point start, struct Point end) {
    struct Node openList[ROW * COL];
    struct Node closeList[ROW * COL];

    int openListCount = 0;
    int closeListCount = 0;

    // Create a starting node and add it to the open list
    struct Node startNode = {
        .pos = start,
        .f = 0,
        .g = 0,
        .h = 0,
        .parent = NULL,
    };
    openList[openListCount++] = startNode;

    while(openListCount > 0) {
        // Find the node with lowest F cost in the open list
        int lowest = 0;
        for(int i=0; i<openListCount; i++) {
            if(openList[i].f < openList[lowest].f) {
                lowest = i;
            }
        }

        struct Node current = openList[lowest];

        // Remove the current node from the open list and add it to the close list
        openListCount--;
        for(int i=lowest; i<openListCount; i++) {
            openList[i] = openList[i+1];
        }
        closeList[closeListCount++] = current;

        // If the current node is the goal node, trace and return the path
        if(current.pos.x == end.x && current.pos.y == end.y) {
            printf("The shortest path is:\n");
            tracePath(&current);
            return;
        }

        // Generate the children of the current node
        struct Point dirs[8] = {
            {-1,-1}, {-1,0}, {-1,1},
            {0,-1}, /*{0,0},*/ {0,1},
            {1,-1}, {1,0}, {1,1}
        };
        for(int i=0; i<8; i++) {
            struct Point newPos = {
                .x = current.pos.x + dirs[i].x,
                .y = current.pos.y + dirs[i].y,
            };

            // Check if the new position is valid
            if(!isValid(newPos.x, newPos.y)) {
                continue;
            }

            // Check if the new position is blocked
            if(isBlocked(grid, newPos.x, newPos.y)) {
                continue;
            }

            // Calculate costs
            int gCost = current.g + 1;
            int hCost = heuristic(newPos, end);
            int fCost = gCost + hCost;

            // Check if the new position is already in the close list with a lower F cost
            int inCloseList = 0;
            for(int i=0; i<closeListCount; i++) {
                if(closeList[i].pos.x == newPos.x && closeList[i].pos.y == newPos.y) {
                    if(closeList[i].f <= fCost) {
                        inCloseList = 1;
                        break;
                    }
                }
            }
            if(inCloseList) {
                continue;
            }

            // Check if the new position is already in the open list with a lower F cost
            int nodeIndex = -1;
            for(int i=0; i<openListCount; i++) {
                if(openList[i].pos.x == newPos.x && openList[i].pos.y == newPos.y) {
                    nodeIndex = i;
                    break;
                }
            }

            // If the new position is not in the open list, add it to the open list
            if(nodeIndex == -1) {
                struct Node newNode = {
                    .pos = newPos,
                    .f = fCost,
                    .g = gCost,
                    .h = hCost,
                    .parent = &closeList[closeListCount-1],
                };
                openList[openListCount++] = newNode;
            }
            // If the new position is already in the open list, update its F cost if it's lower
            else {
                if(fCost < openList[nodeIndex].f) {
                    openList[nodeIndex].f = fCost;
                    openList[nodeIndex].g = gCost;
                    openList[nodeIndex].h = hCost;
                    openList[nodeIndex].parent = &closeList[closeListCount-1];
                }
            }
        }
    }

    printf("No path found.\n");
}

int main()
{
    int grid[ROW][COL] = {
        {0, 0, 0, 1, 0, 1},
        {1, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 0},
    };
    struct Point start = {0, 0};
    struct Point end = {5, 5};

    astar(grid, start, end);

    return 0;
}