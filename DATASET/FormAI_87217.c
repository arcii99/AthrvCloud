//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: standalone
#include <stdio.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

int grid[ROW][COL] = {
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0}
};

int startX = 0;
int startY = 0;
int endX = 4;
int endY = 4;

typedef struct Node {
    int x;
    int y;
    int g;
    int h;
    int f;
    struct Node* parent;
} Node;

Node* createNode(int x, int y, int g, int h, Node* parent) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->g = g;
    node->h = h;
    node->f = g + h;
    node->parent = parent;
    return node;
}

bool isCellValid(int row, int col) {
    if (row >= 0 && row < ROW && col >= 0 && col < COL)
        return (grid[row][col] == 0);
    return false;
}

bool isNodeInList(Node* node, Node** list, int listSize) {
    for (int i = 0; i < listSize; i++)
        if (node->x == list[i]->x && node->y == list[i]->y)
            return true;
    return false;
}

bool isNodeInOpenList(Node* node, Node** openList, int openListSize) {
    for (int i = 0; i < openListSize; i++)
        if (node->x == openList[i]->x && node->y == openList[i]->y)
            return true;
    return false;
}

int calcH(Node* node) {
    return abs(node->x - endX) + abs(node->y - endY);
}

Node** findPath() {
    Node* startNode = createNode(startX, startY, 0, calcH(createNode(startX, startY, 0, 0, NULL)), NULL);
    Node* openList[ROW * COL];
    Node* closedList[ROW * COL];
    int openListSize = 0;
    int closedListSize = 0;

    openList[openListSize++] = startNode;

    while (openListSize > 0) {
        Node* currNode = openList[0];
        int currIndex = 0;

        for (int i = 1; i < openListSize; i++) {
            if (openList[i]->f < currNode->f) {
                currNode = openList[i];
                currIndex = i;
            }
        }

        openListSize--;
        for (int i = currIndex; i < openListSize; i++)
            openList[i] = openList[i + 1];

        closedList[closedListSize++] = currNode;

        if (currNode->x == endX && currNode->y == endY) {
            Node** path = (Node**)malloc(sizeof(Node*) * (closedListSize + 1));
            int pathSize = 0;
            Node* curr = currNode;
            while (curr != NULL) {
                path[pathSize++] = curr;
                curr = curr->parent;
            }
            path[pathSize] = NULL;
            return path;
        }

        struct {
            int x;
            int y;
        } dirs[] = { 
            {-1, 0}, {1, 0}, {0, -1}, {0, 1},
            {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
        };

        int numDirs = sizeof(dirs) / sizeof(dirs[0]);

        for (int i = 0; i < numDirs; i++) {
            int nextX = currNode->x + dirs[i].x;
            int nextY = currNode->y + dirs[i].y;

            if (!isCellValid(nextX, nextY))
                continue;

            Node* child = createNode(nextX, nextY, currNode->g + 1, calcH(createNode(nextX, nextY, 0, 0, NULL)), currNode);

            if (isNodeInList(child, closedList, closedListSize)) {
                free(child);
                continue;
            }

            if (!isNodeInOpenList(child, openList, openListSize)) {
                openList[openListSize++] = child;
            } else {
                free(child);
            }
        }
    }

    return NULL;
}

void printGrid() {
    printf("Grid:\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (grid[i][j] == 1)
                printf("|X|");
            else
                printf("| |");
        }
        printf("\n");
    }
}

void printPath(Node** path) {
    printf("Path:\n");
    int i = 0;
    while (path[i] != NULL) {
        printf("(%d, %d) ", path[i]->x, path[i]->y);
        i++;
    }
    printf("\n");
}

int main() {
    printGrid();
    Node** path = findPath();
    if (path == NULL) {
        printf("No path found.\n");
        return 1;
    }
    printPath(path);
    return 0;
}