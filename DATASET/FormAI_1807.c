//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: active
#include <stdio.h>
#define ROW 15
#define COL 15

int GRID[ROW][COL]; // initialize 2D array as the grid

struct Node {
    int row, col;
    struct Node *parent; // pointer to the parent node
    int f, g, h; // f, g, h values for the node
};

struct List {
    struct Node *node;
    struct List *next;
};

struct Node *createNode(int row, int col) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->row = row;
    newNode->col = col;
    newNode->parent = NULL;
    newNode->f = 0;
    newNode->g = 0;
    newNode->h = 0;
    return newNode;
}

void printPath(struct Node *node) {
    if (node->parent != NULL) {
        printPath(node->parent);
    }
    printf("(%d,%d) ", node->row, node->col);
}

int manhattanDistance(int x1, int y1, int x2, int y2) {
    int dx = abs(x1 - x2);
    int dy = abs(y1 - y2);
    return dx + dy;
}

void addToList(struct Node *node, struct List **list) {
    struct List *newList = (struct List*)malloc(sizeof(struct List));
    newList->node = node;
    newList->next = *list;
    *list = newList;
}

int isInList(struct Node *node, struct List *list) {
    while (list != NULL) {
        if (list->node->row == node->row && list->node->col == node->col) {
            return 1;
        }
        list = list->next;
    }
    return 0;
}

void removeNode(struct Node *node, struct List **list) {
    struct List *current = *list;
    struct List *previous = NULL;
    while (current != NULL) {
        if (current->node->row == node->row && current->node->col == node->col) {
            if (previous != NULL) {
                previous->next = current->next;
            } else {
                *list = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void freeList(struct List **list) {
    struct List *current = *list;
    struct List *next = NULL;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *list = NULL;
}

struct Node* findBestNode(struct List *list) {
    struct List *current = list;
    struct Node *best = list->node;
    while (current != NULL) {
        if (current->node->f < best->f) {
             best = current->node;
        }
        current = current->next;
    }
    return best;
}

int astar(int startX, int startY, int endX, int endY) {
    if (GRID[startX][startY] == 1 || GRID[endX][endY] == 1) {
        return -1; // starting or ending point is blocked
    }
    if (startX == endX && startY == endY) {
        return 0; // already at the destination
    }

    struct List *openList = NULL;
    struct List *closedList = NULL;

    struct Node *startNode = createNode(startX, startY);
    startNode->h = manhattanDistance(startX, startY, endX, endY);
    startNode->f = startNode->h;
    addToList(startNode, &openList);

    while (openList != NULL) {
        struct Node *current = findBestNode(openList);
        removeNode(current, &openList);
        addToList(current, &closedList);

        int r = current->row;
        int c = current->col;

        int neighbors[][2] = {{r-1, c}, {r, c-1}, {r+1, c}, {r, c+1}}; // top, left, bottom, right

        for (int i = 0; i < 4; i++) { // loop through the neighbors
            int row = neighbors[i][0];
            int col = neighbors[i][1];

            if (row == endX && col == endY) { // found the end node
                struct Node *endNode = createNode(row, col);
                endNode->parent = current;
                endNode->g = current->g + 1;
                endNode->h = manhattanDistance(row, col, endX, endY);
                endNode->f = endNode->g + endNode->h;
                printPath(endNode);
                freeList(&openList);
                freeList(&closedList);
                return endNode->f;
            }

            if (row < 0 || row >= ROW || col < 0 || col >= COL || GRID[row][col] == 1) {
                continue; // can't traverse to this neighbor
            }

            struct Node *neighborNode = createNode(row, col);
            int tentativeGScore = current->g + 1;

            if (isInList(neighborNode, closedList) && tentativeGScore >= neighborNode->g) {
                continue; // this node is already in the closedList
            }

            if (!isInList(neighborNode, openList) || tentativeGScore < neighborNode->g) {
                neighborNode->g = tentativeGScore;
                neighborNode->h = manhattanDistance(row, col, endX, endY);
                neighborNode->f = neighborNode->g + neighborNode->h;
                neighborNode->parent = current;
                if (!isInList(neighborNode, openList)) {
                    addToList(neighborNode, &openList);
                }
            }
        }
    }
    freeList(&closedList);
    return -1; // path not found
}

int main() {
    int startRow = 2;
    int startCol = 2;
    int endRow = 10;
    int endCol = 12;

    for (int r = 0; r < ROW; r++) {
        for (int c = 0; c < COL; c++) {
            GRID[r][c] = 0; // initialize grid to all empty spaces
        }
    }

    // add some blocked nodes
    GRID[3][6] = 1;
    GRID[4][6] = 1;
    GRID[5][6] = 1;
    GRID[6][6] = 1;
    GRID[7][6] = 1;
    GRID[8][6] = 1;
    GRID[9][6] = 1;

    astar(startRow, startCol, endRow, endCol);

    return 0;
}