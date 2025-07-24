//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 1, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

Node* createNode(int x, int y) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;
    return newNode;
}

void push(Node** headRef, int x, int y) {
    Node* newNode = createNode(x, y);
    newNode->next = (*headRef);
    (*headRef) = newNode;
}

void pop(Node** headRef) {
    if (*headRef == NULL) {
        return;
    }

    Node* temp = *headRef;
    (*headRef) = (*headRef)->next;
    free(temp);
}

bool isEmpty(Node** headRef) {
    return (*headRef) == NULL;
}

void printPath(Node* path) {
    while (path != NULL) {
        printf("(%d, %d) ", path->x, path->y);
        path = path->next;
    }
    printf("\n");
}

bool findPath(int x, int y, Node** path, bool visited[ROWS][COLS]) {
    if (x == ROWS - 1 && y == COLS - 1) {
        push(path, x, y);
        return true;
    }

    if (maze[x][y] == 0 && visited[x][y] == false) {
        visited[x][y] = true;
        push(path, x, y);

        if (x > 0 && findPath(x - 1, y, path, visited)) {
            return true;
        }
        if (x < ROWS - 1 && findPath(x + 1, y, path, visited)) {
            return true;
        }
        if (y > 0 && findPath(x, y - 1, path, visited)) {
            return true;
        }
        if (y < COLS - 1 && findPath(x, y + 1, path, visited)) {
            return true;
        }

        pop(path);
    }
    return false;
}

int main() {
    bool visited[ROWS][COLS] = {false};
    Node* path = NULL;

    if (findPath(0, 0, &path, visited)) {
        printf("Path found: ");
        printPath(path);
    } else {
        printf("No path found.\n");
    }

    return 0;
}