//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

typedef struct {
    int row;
    int col;
} Point;

int heuristic(Point start, Point end) {
    return abs(start.row - end.row) + abs(start.col - end.col);
}

void printPath(Point path[], int length) {
    printf("Path: ");
    for(int i = 0; i < length; i++) {
        printf("(%d,%d) ", path[i].row, path[i].col);
    }
    printf("\n");
}

int main() {
    int startX = 0, startY = 0;
    int endX = 9, endY = 9;

    int maze[ROWS][COLS] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,1,1,0,1,1,1,0,1,0},
        {0,1,1,0,1,0,1,0,1,0},
        {0,1,1,0,1,0,1,0,1,0},
        {0,1,0,0,0,0,1,0,1,0},
        {0,1,1,1,1,1,1,0,1,0},
        {0,1,0,0,0,0,1,0,1,0},
        {0,1,1,1,1,1,1,0,1,0},
        {0,1,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,0,0}
    };

    // Initialize start and end points
    Point start = {startX, startY};
    Point end = {endX, endY};

    // Array for keeping track of path
    Point path[ROWS*COLS];
    int pathLength = 0;

    // Initialize the open and closed lists
    Point openList[ROWS*COLS];
    int openListLength = 0;
    Point closedList[ROWS*COLS];
    int closedListLength = 0;

    // Add the starting point to the open list
    openList[openListLength++] = start;

    // Main loop for finding the shortest path
    while(openListLength > 0) {
        // Find the index of the point with the lowest f value
        int lowestIndex = 0;
        for(int i = 0; i < openListLength; i++) {
            if(heuristic(openList[i], end) + pathLength < heuristic(openList[lowestIndex], end) + pathLength) {
                lowestIndex = i;
            }
        }

        // Add the lowest f value point to the path
        path[pathLength++] = openList[lowestIndex];

        // Check if the end has been reached
        if(openList[lowestIndex].row == end.row && openList[lowestIndex].col == end.col) {
            printPath(path, pathLength);
            return 0;
        }

        // Move the point with the lowest f value from the open list to the closed list
        closedList[closedListLength++] = openList[lowestIndex];
        openList[lowestIndex] = openList[--openListLength];

        // Loop through all the neighboring points
        for(int row = -1; row <= 1; row++) {
            for(int col = -1; col <= 1; col++) {
                // Skip the current point and diagonals
                if((row == 0 && col == 0) || (row != 0 && col != 0)) {
                    continue;
                }

                // Calculate the neighbor's coordinates
                int neighborRow = closedList[closedListLength-1].row + row;
                int neighborCol = closedList[closedListLength-1].col + col;

                // Skip the neighbor if it's out of bounds or if it's a wall or if it's already on a list
                if(neighborRow < 0 || neighborRow >= ROWS || neighborCol < 0 || neighborCol >= COLS ||
                   maze[neighborRow][neighborCol] == 0 ||
                   ((neighborRow == start.row && neighborCol == start.col) || (neighborRow == end.row && neighborCol == end.col))) {
                    continue;
                }

                // Calculate the neighbor's f, g, and h values
                int neighborG = pathLength;
                int neighborH = heuristic((Point){neighborRow, neighborCol}, end);
                int neighborF = neighborG + neighborH;

                // Check if the neighbor is already on the open list
                int existingIndex = -1;
                for(int i = 0; i < openListLength; i++) {
                    if(openList[i].row == neighborRow && openList[i].col == neighborCol) {
                        existingIndex = i;
                        break;
                    }
                }

                // Add the neighbor to the open list or update its values if it's already on the list
                if(existingIndex == -1) {
                    openList[openListLength++] = (Point){neighborRow, neighborCol};
                } else if(neighborF < neighborG + heuristic(openList[existingIndex], end)) {
                    openList[existingIndex] = (Point){neighborRow, neighborCol};
                }
            }
        }
    }

    // If no path was found, print an error message
    printf("No path found.\n");

    return 0;
}