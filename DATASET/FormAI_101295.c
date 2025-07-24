//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

typedef struct Node {
    int row, col, f, g, h;
    struct Node* parent;
    bool visited;
    bool isWall;
} Node;

Node nodes[ROWS][COLS];

int heuristic(Node a, Node b) {
    return abs(a.row - b.row) + abs(a.col - b.col);
}

void initNodes() {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            nodes[row][col].row = row;
            nodes[row][col].col = col;
            nodes[row][col].visited = false;
            nodes[row][col].isWall = false;
            nodes[row][col].parent = NULL;
        }
    }
    // set walls
    nodes[3][4].isWall = true;
    nodes[4][4].isWall = true;
    nodes[5][4].isWall = true;
}

void printPath(Node* node) {
    if (node == NULL) {
        printf("Cannot find path.\n");
        return;
    }
    printf("Path found.\n");
    while (node != NULL) {
        printf("R%d C%d\n", node->row, node->col);
        node = node->parent;
    }
}

int main() {
    initNodes();
    Node* start = &nodes[0][0];
    Node* end = &nodes[7][9];
    start->visited = true;
    start->g = 0;
    start->h = heuristic(*start, *end);
    start->f = start->g + start->h;
    Node* openList[ROWS * COLS];
    int openListIndex = 0;
    openList[openListIndex++] = start;
    while (openListIndex > 0) {
        Node* current = openList[0];
        // remove current from openList
        for (int i = 0; i < openListIndex - 1; i++) {
            openList[i] = openList[i + 1];
        }
        openListIndex--;
        if (current == end) {
            printPath(current);
            return 0;
        }
        // check neighbors
        for (int row = -1; row <= 1; row++) {
            for (int col = -1; col <= 1; col++) {
                if ((row != 0 || col != 0) && current->row + row >= 0 && current->row + row < ROWS && current->col + col >= 0 && current->col + col < COLS && !nodes[current->row + row][current->col + col].isWall) {
                    Node* neighbor = &nodes[current->row + row][current->col + col];
                    if (!neighbor->visited) {
                        neighbor->visited = true;
                        neighbor->parent = current;
                        neighbor->g = current->g + 1; // cost is always 1
                        neighbor->h = heuristic(*neighbor, *end);
                        neighbor->f = neighbor->g + neighbor->h;
                        openList[openListIndex++] = neighbor;
                    }
                }
            }
        }
    }
    printPath(NULL);
    return 0;
}