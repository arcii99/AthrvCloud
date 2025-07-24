//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ROW 10
#define COL 10

typedef struct node {
    int x; // Node's x-coordinate
    int y; // Node's y-coordinate
    int f; // f(n) value (estimated total cost)
    int g; // g(n) value (cost from start node to current node)
    int h; // h(n) value (heuristic cost from current node to end node)
    int parent_x; // x-coordinate of parent node in path
    int parent_y; // y-coordinate of parent node in path
} node;

// Declare a map and a priority queue
int map[ROW][COL];
node* openList[ROW * COL];
int openListSize = 0;

// Declare functions used by the A* algorithm
bool isGoal(node* current, int end_x, int end_y);
int heuristic(int current_x, int current_y, int end_x, int end_y);
node* getNode(int x, int y, int g, int end_x, int end_y, node* parent);
void addToOpenList(node* current, int end_x, int end_y);
void removeFromOpenList();
bool isInOpenList(int x, int y);
int getIndexOfInOpenList(int x, int y);
void updateOpenList(node* current, int end_x, int end_y);
void printPath(int start_x, int start_y, int end_x, int end_y);

int main() {
    // Initialize the map
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            map[i][j] = 1; // Wall
        }
    }
    for(int i = 1; i < ROW - 1; i++) {
        for(int j = 1; j < COL - 1; j++) {
            map[i][j] = 0; // Path
        }
    }

    // Set start and end positions
    int start_x = 1;
    int start_y = 1;
    int end_x = ROW - 2;
    int end_y = COL - 2;

    // Initialize the start node
    node* start = getNode(start_x, start_y, 0, end_x, end_y, NULL);

    addToOpenList(start, end_x, end_y);

    // Run the A* algorithm
    while(openListSize > 0) {
        node* current = openList[0];
        if(isGoal(current, end_x, end_y)) {
            printf("Path found!\n");
            printPath(start_x, start_y, end_x, end_y);
            return 0;
        }
        removeFromOpenList();
        // Check North, South, East, West, Northeast, Northwest, Southeast and Southwest nodes
        int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
        int dy[8] = {1, -1, 0, 0, 1, 1, -1, -1};
        for(int i = 0; i < 8; i++) {
            int x = current->x + dx[i];
            int y = current->y + dy[i];
            if(x >= 0 && x < ROW && y >= 0 && y < COL && map[x][y] == 0) {
                // Calculate new cost from start node to current node
                int new_g = current->g + sqrt(pow(x - current->x, 2) + pow(y - current->y, 2));
                if(isInOpenList(x, y)) {
                    int index = getIndexOfInOpenList(x, y);
                    if(new_g < openList[index]->g) {
                        updateOpenList(current, end_x, end_y);
                    }
                } else {
                    node* child = getNode(x, y, new_g, end_x, end_y, current);
                    addToOpenList(child, end_x, end_y);
                }
            }
        }
    }

    printf("Path not found\n");
    return 0;
}

bool isGoal(node* current, int end_x, int end_y) {
    return current->x == end_x && current->y == end_y;
}

int heuristic(int current_x, int current_y, int end_x, int end_y) {
    return sqrt(pow(current_x - end_x, 2) + pow(current_y - end_y, 2));
}

node* getNode(int x, int y, int g, int end_x, int end_y, node* parent) {
    node* n = (node*) malloc(sizeof(node));
    n->x = x;
    n->y = y;
    n->g = g;
    n->h = heuristic(x, y, end_x, end_y);
    n->f = n->g + n->h;
    n->parent_x = parent != NULL ? parent->x : -1;
    n->parent_y = parent != NULL ? parent->y : -1;
    return n;
}

void addToOpenList(node* current, int end_x, int end_y) {
    openList[openListSize++] = current;
    int currentIndex = openListSize - 1;
    while(currentIndex > 0) {
        int parentIndex = (currentIndex - 1) / 2;
        if(openList[currentIndex]->f < openList[parentIndex]->f) {
            node* temp = openList[currentIndex];
            openList[currentIndex] = openList[parentIndex];
            openList[parentIndex] = temp;
            currentIndex = parentIndex;
        } else {
            break;
        }
    }
}

void removeFromOpenList() {
    int currentIndex = 0;
    int leftChildIndex = 1;
    int rightChildIndex = 2;
    // Move the last node to the root position and heapify the array
    openList[0] = openList[--openListSize];
    while(leftChildIndex < openListSize) {
        int smallerChildIndex = rightChildIndex < openListSize && openList[rightChildIndex]->f < openList[leftChildIndex]->f ? rightChildIndex : leftChildIndex;
        if(openList[currentIndex]->f > openList[smallerChildIndex]->f) {
            node* temp = openList[currentIndex];
            openList[currentIndex] = openList[smallerChildIndex];
            openList[smallerChildIndex] = temp;
            currentIndex = smallerChildIndex;
            leftChildIndex = currentIndex * 2 + 1;
            rightChildIndex = currentIndex * 2 + 2;
        } else {
            break;
        }
    }
}

bool isInOpenList(int x, int y) {
    for(int i = 0; i < openListSize; i++) {
        if(openList[i]->x == x && openList[i]->y == y) {
            return true;
        }
    }
    return false;
}

int getIndexOfInOpenList(int x, int y) {
    for(int i = 0; i < openListSize; i++) {
        if(openList[i]->x == x && openList[i]->y == y) {
            return i;
        }
    }
    return -1;
}

void updateOpenList(node* current, int end_x, int end_y) {
    int index = getIndexOfInOpenList(current->x, current->y);
    openList[index]->parent_x = current->parent_x;
    openList[index]->parent_y = current->parent_y;
    openList[index]->g = current->g;
    openList[index]->f = current->f;
    int currentIndex = index;
    while(currentIndex > 0) {
        int parentIndex = (currentIndex - 1) / 2;
        if(openList[currentIndex]->f < openList[parentIndex]->f) {
            node* temp = openList[currentIndex];
            openList[currentIndex] = openList[parentIndex];
            openList[parentIndex] = temp;
            currentIndex = parentIndex;
        } else {
            break;
        }
    }
}

void printPath(int start_x, int start_y, int end_x, int end_y) {
    int x = end_x;
    int y = end_y;
    while(!(x == start_x && y == start_y)) {
        printf("(%d, %d) -> ", x, y);
        int index = getIndexOfInOpenList(x, y);
        x = openList[index]->parent_x;
        y = openList[index]->parent_y;
    }
    printf("(%d, %d)\n", x, y);
}