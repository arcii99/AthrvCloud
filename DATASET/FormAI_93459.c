//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

// Definition of Node struct
typedef struct {
    int x, y;
    int f, g, h;
} Node;

// Definition of the A* Pathfinding Algorithm function
int AStar(Node start, Node end, int map[][COLS]) {
    Node openList[ROWS * COLS], closedList[ROWS * COLS];
    int openSize = 0, closedSize = 0;

    Node current = start;
    openList[openSize++] = start;

    while (openSize > 0) {
        int lowest = 0;

        // Find the Node with the lowest f value
        for (int i = 0; i < openSize; i++) {
            if (openList[i].f < openList[lowest].f) {
                lowest = i;
            }
        }

        current = openList[lowest];

        // If the current Node is the destination, return its g value
        if (current.x == end.x && current.y == end.y) {
            return current.g;
        }

        // Remove the current Node from the open list and add it to the closed list
        openSize--;
        closedList[closedSize++] = current;

        // Iterate through all the adjacent Nodes of the current Node
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                // Ignore the Node if it is the current Node or outside of the map boundaries
                if ((i == 0 && j == 0) || current.x + i < 0 || current.x + i >= ROWS || current.y + j < 0 || current.y + j >= COLS) {
                    continue;
                }

                int g = current.g + map[current.x + i][current.y + j];
                int h = abs(end.x - (current.x + i)) + abs(end.y - (current.y + j));
                int f = g + h;

                // Ignore the Node if it is on the closed list
                int skip = 0;
                for (int k = 0; k < closedSize; k++) {
                    if (closedList[k].x == current.x + i && closedList[k].y == current.y + j) {
                        skip = 1;
                        break;
                    }
                }
                if (skip) {
                    continue;
                }

                // If the Node is not on the open list, add it with its f value
                skip = 0;
                for (int k = 0; k < openSize; k++) {
                    if (openList[k].x == current.x + i && openList[k].y == current.y + j) {
                        if (f < openList[k].f) {
                            openList[k].f = f;
                            openList[k].g = g;
                            openList[k].h = h;
                        }
                        skip = 1;
                        break;
                    }
                }
                if (!skip) {
                    openList[openSize].x = current.x + i;
                    openList[openSize].y = current.y + j;
                    openList[openSize].f = f;
                    openList[openSize].g = g;
                    openList[openSize].h = h;
                    openSize++;
                }
            }
        }
    }

    // If there is no path, return -1
    return -1;
}

int main() {
    int map[ROWS][COLS] = {
        {3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
        {3, 1, 1, 1, 1, 1, 1, 1, 1, 3},
        {3, 1, 1, 1, 1, 1, 1, 1, 1, 3},
        {3, 1, 1, 1, 1, 1, 1, 1, 1, 3},
        {3, 1, 1, 1, 1, 1, 1, 1, 1, 3},
        {3, 1, 1, 1, 1, 1, 1, 1, 1, 3},
        {3, 1, 1, 1, 1, 1, 1, 1, 1, 3},
        {3, 1, 1, 1, 1, 1, 1, 1, 1, 3},
        {3, 1, 1, 1, 1, 1, 1, 1, 1, 3},
        {3, 3, 3, 3, 3, 3, 3, 3, 3, 3}
    };

    Node start = {1, 1, 0, 0, 0};
    Node end = {8, 8, 0, 0, 0};

    int result = AStar(start, end, map);

    printf("Shortest path distance: %d\n", result);

    return 0;
}