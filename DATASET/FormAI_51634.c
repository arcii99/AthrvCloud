//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 15
#define COLS 15

struct Node {
    int f, g, h;
    int row, col;
    int type;
    struct Node* parent;
};

int map[ROWS][COLS] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,0,1,1,1,1,1,1,1,1,1,0,1},
    {1,0,1,0,1,0,0,0,0,0,0,0,1,0,1},
    {1,0,1,0,1,0,1,1,1,1,1,0,1,0,1},
    {1,0,1,0,1,0,1,0,0,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0,1,1,1,0,1,0,1},
    {1,0,1,0,1,0,1,0,0,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0,0,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,1,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,0,0,0,0,1,0,1,0,1},
    {1,0,1,1,1,1,1,1,1,1,1,0,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

struct Node* createNode(int row, int col, int type) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->f = 0;
    node->g = 0;
    node->h = 0;
    node->parent = NULL;
    node->row = row;
    node->col = col;
    node->type = type;
    return node;
}

void printMap(struct Node* start, struct Node* end) {
    printf("\n\t");
    for (int i = 0; i < COLS; i++) {
        printf("%d ", i % 10);
    }
    printf("\n\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d\t", i % 10);
        for (int j = 0; j < COLS; j++) {
            if (start->row == i && start->col == j) {
                printf("S ");
            } else if (end->row == i && end->col == j) {
                printf("E ");
            } else if (map[i][j] == 0) {
                printf(". ");
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
}

int manhattan(int row1, int col1, int row2, int col2) {
    return abs(row1 - row2) + abs(col1 - col2);
}

int diagonal(int row1, int col1, int row2, int col2) {
    int dx = abs(row1 - row2);
    int dy = abs(col1 - col2);
    return 10 * fmin(dx, dy) + 10 * (fmax(dx, dy) - fmin(dx, dy));
}

int heuristic(int row1, int col1, int row2, int col2) {
    return diagonal(row1, col1, row2, col2);
}

void addOpen(struct Node** open, struct Node* node, int* count) {
    for (int i = 0; i < *count; i++) {
        if (open[i]->f > node->f) {
            for (int j = *count; j > i; j--) {
                open[j] = open[j - 1];
            }
            open[i] = node;
            (*count)++;
            return;
        }
    }
    open[*count] = node;
    (*count)++;
}

void addNeighbors(struct Node** open, int* count, struct Node* current, struct Node* end) {
    int row = current->row;
    int col = current->col;
    if (row - 1 >= 0 && map[row - 1][col] == 0) {
        struct Node* node = createNode(row - 1, col, 0);
        node->g = current->g + 10;
        node->h = heuristic(node->row, node->col, end->row, end->col);
        node->f = node->g + node->h;
        node->parent = current;
        addOpen(open, node, count);
    }
    if (row + 1 < ROWS && map[row + 1][col] == 0) {
        struct Node* node = createNode(row + 1, col, 0);
        node->g = current->g + 10;
        node->h = heuristic(node->row, node->col, end->row, end->col);
        node->f = node->g + node->h;
        node->parent = current;
        addOpen(open, node, count);
    }
    if (col - 1 >= 0 && map[row][col - 1] == 0) {
        struct Node* node = createNode(row, col - 1, 0);
        node->g = current->g + 10;
        node->h = heuristic(node->row, node->col, end->row, end->col);
        node->f = node->g + node->h;
        node->parent = current;
        addOpen(open, node, count);
    }
    if (col + 1 < COLS && map[row][col + 1] == 0) {
        struct Node* node = createNode(row, col + 1, 0);
        node->g = current->g + 10;
        node->h = heuristic(node->row, node->col, end->row, end->col);
        node->f = node->g + node->h;
        node->parent = current;
        addOpen(open, node, count);
    }
}

void aStar(struct Node* start, struct Node* end) {
    struct Node* open[ROWS * COLS];
    int openCount = 0;
    struct Node* closed[ROWS * COLS];
    int closedCount = 0;
    addOpen(open, start, &openCount);
    while (openCount > 0) {
        struct Node* current = open[0];
        if (current->row == end->row && current->col == end->col) {
            current = end;
            do {
                map[current->row][current->col] = 2;
                current = current->parent;
            } while(current != NULL);
            printMap(start, end);
            return;
        }
        openCount--;
        for (int i = 0; i < openCount; i++) {
            open[i] = open[i + 1];
        }
        addNeighbors(open, &openCount, current, end);
        closed[closedCount] = current;
        closedCount++;
    }
    printf("No path found!\n");
    printMap(start, end);
}

int main() {
    struct Node* start = createNode(1, 1, 1);
    struct Node* end = createNode(ROWS - 2, COLS - 2, 1);
    aStar(start, end);
    return 0;
}