//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

typedef struct Node {
    int x, y, f, g, h;
    struct Node* parent;
} Node;

Node* createNode(int x, int y, int f, int g, int h, Node* parent) {
    Node* n = (Node*) malloc(sizeof(Node));
    n->x = x;
    n->y = y;
    n->f = f;
    n->g = g;
    n->h = h;
    n->parent = parent;
    return n;
}

Node* getNodeWithLowestF(Node* openList[]) {
    int lowestF = -1;
    Node* lowestFNode;
    for (int i = 0; i < ROW * COL; i++) {
        if (openList[i] == NULL) continue;
        if (lowestF == -1 || openList[i]->f < lowestF) {
            lowestF = openList[i]->f;
            lowestFNode = openList[i];
        }
    }
    return lowestFNode;
}

int isNodeValid(int x, int y, int grid[][COL], Node* closedList[]) {
    if (x < 0 || x >= ROW || y < 0 || y >= COL) return 0;
    if (grid[x][y] == 1) return 0;
    for (int i = 0; i < ROW * COL; i++) {
        if (closedList[i] == NULL) break;
        if (closedList[i]->x == x && closedList[i]->y == y) return 0;
    }
    return 1;
}

int calculateH(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

void printPath(Node* lastNode) {
    if (lastNode == NULL) return;
    printPath(lastNode->parent);
    printf("(%d, %d) ", lastNode->x, lastNode->y);
}

void AStar(int startX, int startY, int endX, int endY, int grid[][COL]) {
    Node* openList[ROW * COL];
    Node* closedList[ROW * COL];
    for (int i = 0; i < ROW * COL; i++) {
        openList[i] = NULL;
        closedList[i] = NULL;
    }
    Node* startNode = createNode(startX, startY, 0, 0, 0, NULL);
    Node* endNode = createNode(endX, endY, 0, 0, 0, NULL);
    openList[0] = startNode;
    int count = 1;
    while (count > 0) {
        Node* currentNode = getNodeWithLowestF(openList);
        if (currentNode == NULL) break;
        openList[currentNode->x * ROW + currentNode->y] = NULL;
        closedList[(currentNode->x * ROW) + currentNode->y] = currentNode;
        if (currentNode->x == endX && currentNode->y == endY) {
            printPath(currentNode);
            return;
        }
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) continue;
                if (isNodeValid(currentNode->x + i, currentNode->y + j, grid, closedList)) {
                    int g = currentNode->g + 1;
                    int h = calculateH(currentNode->x + i, currentNode->y + j, endX, endY);
                    int f = g + h;
                    Node* newNode = createNode(currentNode->x + i, currentNode->y + j, f, g, h, currentNode);
                    openList[newNode->x * ROW + newNode->y] = newNode;
                    count++;
                }
            }
        }
    }
    printf("No path found!\n");
}

int main() {
    int grid[ROW][COL] = {
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 1, 0, 0, 1, 1, 0 },
        { 0, 1, 0, 0, 1, 0, 0, 1, 1, 0 },
        { 0, 1, 0, 0, 1, 0, 0, 1, 1, 0 },
        { 0, 0, 1, 1, 1, 1, 1, 1, 1, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    };
    AStar(3, 3, 6, 7, grid);
    return 0;
}