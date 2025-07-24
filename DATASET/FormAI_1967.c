//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ROW 10
#define COL 10

int absdiff(int a, int b) {
    return abs(a - b);
}

struct node {
    int x, y, f, g, h;
    bool visited;
    int obstacles;
    struct node *parent;
};

void printPath(struct node *curr) {
    if(curr->parent == NULL) return;
    printPath(curr->parent);
    printf("-> (%d,%d) ", curr->x, curr->y);
}

int main() {
    int startX = 0, startY = 0;
    int goalX = 9, goalY = 9;
    int obstacles = 30;
    struct node map[ROW][COL];
    struct node *openList[ROW*COL], *closedList[ROW*COL];
    int openListSize = 0, closedListSize = 0;

    // Initialize map with random obstacles
    srand(time(NULL));
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            map[i][j].x = i;
            map[i][j].y = j;
            map[i][j].visited = false;
            map[i][j].obstacles = 0;
            if(rand() % 100 < obstacles) {
                map[i][j].obstacles = rand() % 9 + 1;
            }
        }
    }

    // Initialize start node's values
    map[startX][startY].g = 0;
    map[startX][startY].h = absdiff(startX, goalX) + absdiff(startY, goalY);
    map[startX][startY].f = map[startX][startY].g + map[startX][startY].h;
    map[startX][startY].visited = true;
    openList[openListSize++] = &map[startX][startY];

    while(openListSize > 0) {
        // Find node with low f value
        int currentIndex = 0;
        for(int i=0; i<openListSize; i++) {
            if(openList[i]->f < openList[currentIndex]->f) currentIndex = i;
        }
        struct node *current = openList[currentIndex];

        // End the search if we have reached the goal
        if(current->x == goalX && current->y == goalY) {
            printf("Path: ");
            printPath(current);
            printf("\n");
            return 0;
        }

        // Move current node to the closed list
        current->visited = false;
        closedList[closedListSize++] = current;

        // Check neighbors of current node
        const int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for(int i=0; i<4; i++) {
            int neighborX = current->x + directions[i][0];
            int neighborY = current->y + directions[i][1];
            if(neighborX < 0 || neighborY < 0 || neighborX >= ROW || neighborY >= COL) continue;
            struct node *neighbor = &map[neighborX][neighborY];

            // Skip if neighbor is an obstacle or already in the closed list
            if(neighbor->obstacles == 0 || neighbor->visited) continue;

            // Calculate new tentative g and f values for neighbor
            int tentativeG = current->g + neighbor->obstacles;
            int tentativeH = absdiff(neighborX, goalX) + absdiff(neighborY, goalY);
            int tentativeF = tentativeG + tentativeH;

            // Add neighbor to the open list if it has not been visited or has lower f value
            if(!neighbor->visited || tentativeF < neighbor->f) {
                neighbor->visited = true;
                neighbor->g = tentativeG;
                neighbor->h = tentativeH;
                neighbor->f = tentativeF;
                neighbor->parent = current;
                openList[openListSize++] = neighbor;
            }
        }
    }
    printf("No path found!\n");
    return 0;
}