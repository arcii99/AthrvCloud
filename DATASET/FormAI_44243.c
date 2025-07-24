//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

typedef struct {
    int x, y;
} Point;

typedef struct {
    char map[ROWS][COLS];
    Point start, end;
} GameMap;

typedef struct {
    int x, y, f, g, h;
    struct Node* parent;
} Node;

Node* createNode(int x, int y, int f, int g, int h, Node* parent) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->f = f;
    node->g = g;
    node->h = h;
    node->parent = parent;
    return node;
}

void destroyNode(Node* node) {
    free(node);
}

int getHValue(Point p1, Point p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

void insertHeap(Node** heap, int* heapSize, Node* node) {
    int i = (*heapSize)++;
    while (i > 0 && heap[(i - 1) / 2]->f >= node->f) {
        heap[i] = heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap[i] = node;
}

Node* deleteHeap(Node** heap, int* heapSize) {
    Node* minNode = heap[0];
    Node* lastNode = heap[--(*heapSize)];
    int i = 0;
    while (i * 2 + 1 < *heapSize) {
        int child = i * 2 + 1;
        if (child + 1 < *heapSize && heap[child + 1]->f < heap[child]->f) {
            child++;
        }
        if (heap[child]->f >= lastNode->f) {
            break;
        }
        heap[i] = heap[child];
        i = child;
    }
    heap[i] = lastNode;
    return minNode;
}

bool isValidPoint(GameMap* gameMap, Point p) {
    return p.x >= 0 && p.x < ROWS && p.y >= 0 && p.y < COLS && gameMap->map[p.x][p.y] != '#';
}

bool isEndPoint(Point p, Point end) {
    return p.x == end.x && p.y == end.y;
}

bool isVisited(bool** closed, Point p) {
    return closed[p.x][p.y];
}

void printMap(GameMap* gameMap) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", gameMap->map[i][j]);
        }
        printf("\n");
    }
}

void printPath(Node* node) {
    if (node->parent == NULL) {
        return;
    }
    printPath(node->parent);
    printf("(%d,%d) ", node->x, node->y);
}

Node* aStar(GameMap* gameMap) {
    bool** closed = (bool**) calloc(ROWS, sizeof(bool*));
    for (int i = 0; i < ROWS; i++) {
        closed[i] = (bool*) calloc(COLS, sizeof(bool));
    }
    Node* heap[ROWS * COLS];
    int heapSize = 0;
    insertHeap(heap, &heapSize, createNode(gameMap->start.x, gameMap->start.y, 0, 0, getHValue(gameMap->start, gameMap->end), NULL));
    while (heapSize > 0) {
        Node* currNode = deleteHeap(heap, &heapSize);
        Point currPoint = { currNode->x, currNode->y };
        if (isEndPoint(currPoint, gameMap->end)) {
            return currNode;
        }
        closed[currPoint.x][currPoint.y] = true;
        Point nextPoints[] = {
            { currPoint.x - 1, currPoint.y },
            { currPoint.x + 1, currPoint.y },
            { currPoint.x, currPoint.y - 1 },
            { currPoint.x, currPoint.y + 1 }
        };
        for (int i = 0; i < 4; i++) {
            if (isValidPoint(gameMap, nextPoints[i]) && !isVisited(closed, nextPoints[i])) {
                int g = currNode->g + 1;
                int h = getHValue(nextPoints[i], gameMap->end);
                int f = g + h;
                insertHeap(heap, &heapSize, createNode(nextPoints[i].x, nextPoints[i].y, f, g, h, currNode));
            }
        }
    }
    return NULL;
}

int main() {
    GameMap gameMap = {
        { // map
            { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
            { '#', '.', '.', '.', '#', '.', '.', '.', '.', '#' },
            { '#', '.', '#', '.', '#', '.', '#', '#', '.', '#' },
            { '#', '.', '#', '.', '.', '.', '.', '.', '.', '#' },
            { '#', '.', '#', '.', '#', '#', '#', '.', '.', '#' },
            { '#', '.', '.', '.', '.', '.', '.', '.', '#', '#' },
            { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
            { '#', '.', '.', '.', '.', '#', '.', '.', '.', '#' },
            { '#', '.', '#', '#', '#', '#', '.', '#', '.', '#' },
            { '#', '.', '.', '.', '.', '.', '.', '.', '.', '#' }
        },
        { 1, 1 }, // start
        { 8, 8 } // end
    };
    printMap(&gameMap);
    Node* endNode = aStar(&gameMap);
    if (endNode != NULL) {
        printf("Path: ");
        printPath(endNode);
        printf("\n");
    } else {
        printf("No path found.\n");
    }
    return 0;
}