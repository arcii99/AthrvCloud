//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define ROW 10
#define COL 10
#define INF INT_MAX

typedef struct {
    int row, col, g, h, f;
} node;

// Initialize the nodes with their positions and costs
node nodes[ROW][COL] = {
    //row 0
    { { 0, 0, INF, INF, INF }, { 0, 1, INF, INF, INF }, { 0, 2, INF, INF, INF }, { 0, 3, INF, INF, INF }, { 0, 4, INF, INF, INF }, { 0, 5, INF, INF, INF }, { 0, 6, INF, INF, INF }, { 0, 7, INF, INF, INF }, { 0, 8, INF, INF, INF }, { 0, 9, INF, INF, INF } },
    //row 1
    { { 1, 0, INF, INF, INF }, { 1, 1, INF, INF, INF }, { 1, 2, INF, INF, INF }, { 1, 3, INF, INF, INF }, { 1, 4, INF, INF, INF }, { 1, 5, INF, INF, INF }, { 1, 6, INF, INF, INF }, { 1, 7, INF, INF, INF }, { 1, 8, INF, INF, INF }, { 1, 9, INF, INF, INF } },
    //row 2
    { { 2, 0, INF, INF, INF }, { 2, 1, INF, INF, INF }, { 2, 2, INF, INF, INF }, { 2, 3, INF, INF, INF }, { 2, 4, INF, INF, INF }, { 2, 5, INF, INF, INF }, { 2, 6, INF, INF, INF }, { 2, 7, INF, INF, INF }, { 2, 8, INF, INF, INF }, { 2, 9, INF, INF, INF } },
    //row 3
    { { 3, 0, INF, INF, INF }, { 3, 1, INF, INF, INF }, { 3, 2, INF, INF, INF }, { 3, 3, INF, INF, INF }, { 3, 4, INF, INF, INF }, { 3, 5, INF, INF, INF }, { 3, 6, INF, INF, INF }, { 3, 7, INF, INF, INF }, { 3, 8, INF, INF, INF }, { 3, 9, INF, INF, INF } },
    //row 4
    { { 4, 0, INF, INF, INF }, { 4, 1, INF, INF, INF }, { 4, 2, INF, INF, INF }, { 4, 3, INF, INF, INF }, { 4, 4, INF, INF, INF }, { 4, 5, INF, INF, INF }, { 4, 6, INF, INF, INF }, { 4, 7, INF, INF, INF }, { 4, 8, INF, INF, INF }, { 4, 9, INF, INF, INF } },
    //row 5
    { { 5, 0, INF, INF, INF }, { 5, 1, INF, INF, INF }, { 5, 2, INF, INF, INF }, { 5, 3, INF, INF, INF }, { 5, 4, INF, INF, INF }, { 5, 5, INF, INF, INF }, { 5, 6, INF, INF, INF }, { 5, 7, INF, INF, INF }, { 5, 8, INF, INF, INF }, { 5, 9, INF, INF, INF } },
    //row 6
    { { 6, 0, INF, INF, INF }, { 6, 1, INF, INF, INF }, { 6, 2, INF, INF, INF }, { 6, 3, INF, INF, INF }, { 6, 4, INF, INF, INF }, { 6, 5, INF, INF, INF }, { 6, 6, INF, INF, INF }, { 6, 7, INF, INF, INF }, { 6, 8, INF, INF, INF }, { 6, 9, INF, INF, INF } },
    //row 7
    { { 7, 0, INF, INF, INF }, { 7, 1, INF, INF, INF }, { 7, 2, INF, INF, INF }, { 7, 3, INF, INF, INF }, { 7, 4, INF, INF, INF }, { 7, 5, INF, INF, INF }, { 7, 6, INF, INF, INF }, { 7, 7, INF, INF, INF }, { 7, 8, INF, INF, INF }, { 7, 9, INF, INF, INF } },
    //row 8
    { { 8, 0, INF, INF, INF }, { 8, 1, INF, INF, INF }, { 8, 2, INF, INF, INF }, { 8, 3, INF, INF, INF }, { 8, 4, INF, INF, INF }, { 8, 5, INF, INF, INF }, { 8, 6, INF, INF, INF }, { 8, 7, INF, INF, INF }, { 8, 8, INF, INF, INF }, { 8, 9, INF, INF, INF } },
    //row 9
    { { 9, 0, INF, INF, INF }, { 9, 1, INF, INF, INF }, { 9, 2, INF, INF, INF }, { 9, 3, INF, INF, INF }, { 9, 4, INF, INF, INF }, { 9, 5, INF, INF, INF }, { 9, 6, INF, INF, INF }, { 9, 7, INF, INF, INF }, { 9, 8, INF, INF, INF }, { 9, 9, INF, INF, INF } },
};

// Print the grid
void printGrid(node grid[ROW][COL]) {
    printf("   ");
    for (int i = 0; i < COL; i++) {
        if (i < 10) {
            printf(" %d ", i);
        } else {
            printf("%d ", i);
        }
    }
    printf("\n");

    for (int i = 0; i < ROW; i++) {
        if (i < 10) {
            printf(" %d", i);
        } else {
            printf("%d", i);
        }
        for (int j = 0; j < COL; j++) {
            if (grid[i][j].g == INF) {
                printf("| * ");
            } else {
                printf("| %d ", grid[i][j].g);
            }
        }
        printf("|\n");
    }
    printf("\n");
}

// Check if a node is valid
bool isValid(node n) {
    return (n.row >= 0 && n.row < ROW && n.col >= 0 && n.col < COL);
}

// Check if a node is not blocked (i.e., has a cost of INF)
bool isUnblocked(node n) {
    return (nodes[n.row][n.col].g != INF);
}

// Check if a node is the destination
bool isDestination(node n, node dest) {
    return (n.row == dest.row && n.col == dest.col);
}

// Calculate the Euclidean distance between two nodes
int calculateDistance(node a, node b) {
    int dist = (a.row - b.row) * (a.row - b.row) + (a.col - b.col) * (a.col - b.col);
    return dist;
}

// Implement A* Algorithm
void AStar(node nodes[ROW][COL], node src, node dest) {
    bool closedList[ROW][COL];
    memset(closedList, false, sizeof(closedList));
    int row, col;
    for (row = 0; row < ROW; row++) {
        for (col = 0; col < COL; col++) {
            nodes[row][col].f = INF;
            nodes[row][col].h = INF;
            nodes[row][col].g = INF;
        }
    }

    nodes[src.row][src.col].f = 0;
    nodes[src.row][src.col].h = calculateDistance(src, dest);
    nodes[src.row][src.col].g = 0;

    node openList[ROW*COL];
    int index;
    for (row = 0; row < ROW; row++) {
        for (col = 0; col < COL; col++) {
            openList[index].f = INF;
            openList[index].g = INF;
            openList[index].h = INF;
            openList[index].row = row;
            openList[index].col = col;
        }
    }

    int openListCount = 0;
    openList[openListCount++] = nodes[src.row][src.col];

    while (openListCount != 0) {
        node current = openList[0];
        int currentIdx = 0;
        for (index = 0; index < openListCount; index++) {
            if (openList[index].f < current.f) {
                current = openList[index];
                currentIdx = index;
            }
        }

        openList[currentIdx] = openList[openListCount - 1];
        openListCount--;

        int i, j;
        for (i = -1; i <= 1; i++) {
            for (j = -1; j <= 1; j++) {
                node neighbor = { current.row + i, current.col + j, INF, INF, INF };
                if (isValid(neighbor) && isUnblocked(neighbor) && !isDestination(neighbor, dest)) {
                    int tentativeGScore = current.g + nodes[neighbor.row][neighbor.col].g;
                    if (tentativeGScore < nodes[neighbor.row][neighbor.col].g) {
                        nodes[neighbor.row][neighbor.col].g = tentativeGScore;
                        nodes[neighbor.row][neighbor.col].h = calculateDistance(neighbor, dest);
                        nodes[neighbor.row][neighbor.col].f = nodes[neighbor.row][neighbor.col].g + nodes[neighbor.row][neighbor.col].h;

                        int i;
                        for (i = 0; i < openListCount; i++) {
                            if (openList[i].row == neighbor.row && openList[i].col == neighbor.col) {
                                break;
                            }
                        }
                        if (i >= openListCount) {
                            openList[openListCount++] = nodes[neighbor.row][neighbor.col];
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    node start = {0, 0, INF, INF, INF}; // Starting node
    node end = {9, 9, INF, INF, INF}; // Ending node

    AStar(nodes, start, end);

    printf("The cost of the shortest path from start to end is: %d\n", nodes[end.row][end.col].g);

    printGrid(nodes);

    return 0;
}