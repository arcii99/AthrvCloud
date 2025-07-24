//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isWall(int x, int y) {
    if ((x == 3 && y >= 5 && y <= 7) || (x == 4 && y == 5) || (x == 4 && y == 7))
        return true;
    else
        return false;
}

int main() {
    int startX = 0, startY = 0; // Starting position
    int goalX = 9, goalY = 9; // Goal position
    int maze[10][10] = {0}; // 10x10 maze
    int path[100][2] = {0}; // Store the path here
    int pathLength = 0; // Number of steps in the path

    // Set walls in the maze
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            if (isWall(x, y))
                maze[x][y] = 1;
        }
    }

    // Display maze
    printf("Maze:\n");
    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            if (maze[x][y] == 0)
                printf(". ");
            else
                printf("# ");
        }
        printf("\n");
    }

    int currentX = startX, currentY = startY; // Start at the starting position

    // Loop until we reach the goal
    while (currentX != goalX || currentY != goalY) {
        // Set the current position to a visited node
        maze[currentX][currentY] = 2;

        // Check neighbors
        bool canMove = false;
        if (currentX > 0 && maze[currentX-1][currentY] == 0) { // Move left
            currentX--;
            canMove = true;
        }
        else if (currentX < 9 && maze[currentX+1][currentY] == 0) { // Move right
            currentX++;
            canMove = true;
        }
        else if (currentY > 0 && maze[currentX][currentY-1] == 0) { // Move up
            currentY--;
            canMove = true;
        }
        else if (currentY < 9 && maze[currentX][currentY+1] == 0) { // Move down
            currentY++;
            canMove = true;
        }

        if (!canMove) { // backtracking
            pathLength--;
            if (pathLength < 0) {
                printf("Cannot find a path!\n");
                return 0;
            }
            currentX = path[pathLength][0];
            currentY = path[pathLength][1];
        }
        else { // Moving forward
            path[pathLength][0] = currentX;
            path[pathLength][1] = currentY;
            pathLength++;
        }
    }

    // Display the path
    printf("Path:\n");
    for (int i = 0; i < pathLength; i++) {
        printf("(%d,%d)\n", path[i][0], path[i][1]);
    }

    return 0;
}