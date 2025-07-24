//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: romantic
#include <stdio.h>
#include <math.h>

#define ROW 5 // number of rows in grid
#define COL 5 // number of columns in grid
#define START_X 0 // starting x-coordinate of the path
#define START_Y 0 // starting y-coordinate of the path
#define END_X 4 // ending x-coordinate of the path
#define END_Y 4 // ending y-coordinate of the path

// define node struct of grid
struct Node {
    int x, y;
    int f, g, h;
    struct Node *parent;
};

// function to calculate distance between two nodes
int distance(struct Node a, struct Node b) {
    int dist = abs(a.x - b.x) + abs(a.y - b.y);
    return dist;
}

// function to check if a node is a valid position in the grid
int isValid(int x, int y) {
    if (x < 0 || y < 0 || x >= ROW || y >= COL) {
        return 0;
    }
    return 1;
}

// function to check if a node is blocked or not
int isBlocked(int grid[][COL], int x, int y) {
    if (grid[x][y] == 1) { // 1 represents a blocked node
        return 1;
    }
    return 0;
}

// function to trace the path from start node to end node
void tracePath(struct Node *end, int grid[][COL]) {
    printf("Path: ");
    struct Node *temp = end;
    while (temp != NULL) {
        printf("(%d,%d) ", temp->x, temp->y);
        grid[temp->x][temp->y] = 2; // mark the path with 2 in the grid
        temp = temp->parent;
    }
    printf("\n");
}

// function to implement A* algorithm
void aStar(int grid[][COL], struct Node start, struct Node end) {
    // initialize open and closed list
    int openList[ROW * COL][2], closedList[ROW * COL][2]; // maximum size of open and closed list is ROW*COL
    int openCount = 0, closedCount = 0;
    openList[openCount][0] = start.x; // insert start node to open list
    openList[openCount][1] = start.y;
    openCount++;
    // initialize f,g,h values for start node
    start.f = 0; 
    start.g = 0;
    start.h = distance(start, end);
    start.parent = NULL;
    // loop until path is found or open list is empty
    while (openCount > 0) {
        // get the node with the lowest f value from open list
        int minf = 1000000, current;
        for (int i = 0; i < openCount; i++) {
            int x = openList[i][0];
            int y = openList[i][1];
            if (grid[x][y] == minf && i < current) {
                current = i;
            }
            else if (grid[x][y] < minf) {
                minf = grid[x][y];
                current = i;
            }
        }
        int x = openList[current][0];
        int y = openList[current][1];
        // remove the current node from open list and add to closed list
        openCount--;
        openList[current][0] = openList[openCount][0];
        openList[current][1] = openList[openCount][1];
        closedList[closedCount][0] = x;
        closedList[closedCount][1] = y;
        closedCount++;
        // check if the current node is the end node
        if (x == end.x && y == end.y) {
            tracePath(&start, grid);
            return;
        }
        // expand the current node's neighbors
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if ((i == 0 && j == 0) || !isValid(x+i, y+j) || isBlocked(grid, x+i, y+j)) {
                    continue;
                }
                // calculate f,g,h values for the neighbor node
                struct Node *neighbor = malloc(sizeof(struct Node));
                neighbor->x = x+i;
                neighbor->y = y+j;
                neighbor->g = distance(start, *neighbor);
                neighbor->h = distance(*neighbor, end);
                neighbor->f = neighbor->g + neighbor->h;
                neighbor->parent = malloc(sizeof(struct Node));
                neighbor->parent->x = x;
                neighbor->parent->y = y;
                // check if neighbor node is already in closed list
                int inClosedList = 0;
                for (int k = 0; k < closedCount; k++) {
                    if (closedList[k][0] == neighbor->x && closedList[k][1] == neighbor->y) {
                        inClosedList = 1;
                        break;
                    }
                }
                if (inClosedList) {
                    continue;
                }
                // check if neighbor node is already in open list
                int inOpenList = 0;
                for (int k = 0; k < openCount; k++) {
                    if (openList[k][0] == neighbor->x && openList[k][1] == neighbor->y) {
                        inOpenList = 1;
                        if (neighbor->f < grid[neighbor->x][neighbor->y]) {
                            grid[neighbor->x][neighbor->y] = neighbor->f;
                            neighbor->parent = malloc(sizeof(struct Node));
                            neighbor->parent->x = x;
                            neighbor->parent->y = y;
                        }
                        break;
                    }
                }
                if (!inOpenList) {
                    grid[neighbor->x][neighbor->y] = neighbor->f;
                    openList[openCount][0] = neighbor->x;
                    openList[openCount][1] = neighbor->y;
                    openCount++;
                }
            }
        }
    }
    printf("Path not found!\n");
}

int main() {
    int grid[ROW][COL] = {
        { 0, 1, 0, 0, 0 },
        { 0, 1, 0, 0, 0 },
        { 0, 1, 0, 1, 0 },
        { 0, 0, 0, 1, 0 },
        { 1, 1, 0, 1, 0 }
    };
    struct Node start = { START_X, START_Y };
    struct Node end = { END_X, END_Y };
    aStar(grid, start, end);
    // print the grid with path marked with 2
    printf("\nGrid with path marked:\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    return 0;
}