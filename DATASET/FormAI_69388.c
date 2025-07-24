//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: brave
#include <stdio.h>

#define ROWS 10
#define COLS 10

// Custom data type for the node of the graph
typedef struct Node {
    int row;
    int col;
    int f; // f = g + h
    int g; // actual cost from start node to current node
    int h; // heuristic cost from current node to target node
    struct Node* parent; // pointer to the parent node
} Node;

// Custom data type for the priority queue
typedef struct PriorityQueue {
    Node* arr[ROWS*COLS];
    int size;
} PriorityQueue;

// Forward declaration of helper functions
int calcManhattanDistance(int row1, int col1, int row2, int col2);
void initGrid(int grid[ROWS][COLS]);
void printGrid(int grid[ROWS][COLS]);
void printPath(Node* endNode);
void addNodeToPriorityQueue(PriorityQueue* pq, Node* node);
Node* getNodeWithLowestFValue(PriorityQueue* pq);
Node* getNode(int row, int col, int g, int h, Node* parent);
void aStar(int grid[ROWS][COLS], int startRow, int startCol, int targetRow, int targetCol);

// Main function
int main() {
    int grid[ROWS][COLS] = {
        {0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,0,0}
    };
    printf("The initial grid is:\n");
    printGrid(grid);
    aStar(grid, 0, 0, 9, 9);
    return 0;
}

// Calculate Manhattan distance between (row1, col1) and (row2, col2)
int calcManhattanDistance(int row1, int col1, int row2, int col2) {
    return abs(row1 - row2) + abs(col1 - col2);
}

// Initialize the grid with values
void initGrid(int grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = 0;
        }
    }
}

// Print the grid
void printGrid(int grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Print path from the start node to the end node
void printPath(Node* endNode) {
    if (endNode == NULL) {
        printf("No path found\n");
        return;
    }

    int path[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            path[i][j] = 0;
        }
    }

    Node* currNode = endNode;
    while (currNode != NULL) {
        path[currNode->row][currNode->col] = 1;
        currNode = currNode->parent;
    }

    printf("The path is:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", path[i][j]);
        }
        printf("\n");
    }
}

// Add node to the priority queue
void addNodeToPriorityQueue(PriorityQueue* pq, Node* node) {
    pq->arr[pq->size++] = node;
    int i = pq->size - 1;
    while (i > 0 && pq->arr[(i-1)/2]->f > pq->arr[i]->f) {
        Node* temp = pq->arr[(i-1)/2];
        pq->arr[(i-1)/2] = pq->arr[i];
        pq->arr[i] = temp;
        i = (i-1)/2;
    }
}

// Get the node with the lowest f value from the priority queue
Node* getNodeWithLowestFValue(PriorityQueue* pq) {
    if (pq->size == 0) return NULL;
    Node* minNode = pq->arr[0];
    pq->arr[0] = pq->arr[pq->size-1];
    pq->size--;
    int i = 0;
    while (2*i+1 < pq->size) {
        Node* firstChild = pq->arr[2*i+1];
        Node* secondChild = (2*i+2 < pq->size) ? pq->arr[2*i+2] : NULL;
        if (secondChild != NULL && firstChild->f > secondChild->f) {
            firstChild = secondChild;
            i = 2*i+2;
        } else {
            i = 2*i+1;
        }
        if (pq->arr[i]->f < pq->arr[(i-1)/2]->f) {
            Node* temp = pq->arr[(i-1)/2];
            pq->arr[(i-1)/2] = pq->arr[i];
            pq->arr[i] = temp;
        } else {
            break;
        }
    }
    return minNode;
}

// Get a new node with the given parameters
Node* getNode(int row, int col, int g, int h, Node* parent) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->g = g;
    node->h = h;
    node->f = g + h;
    node->parent = parent;
    return node;
}

// A* algorithm function
void aStar(int grid[ROWS][COLS], int startRow, int startCol, int targetRow, int targetCol) {
    Node* startNode = getNode(startRow, startCol, 0, calcManhattanDistance(startRow, startCol, targetRow, targetCol), NULL);
    Node* endNode = NULL;
    PriorityQueue* pq = (PriorityQueue*) malloc(sizeof(PriorityQueue));
    pq->size = 0;
    addNodeToPriorityQueue(pq, startNode);
    int visited[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            visited[i][j] = 0;
        }
    }
    visited[startRow][startCol] = 1;

    while (pq->size > 0) {
        Node* currNode = getNodeWithLowestFValue(pq);
        int row = currNode->row;
        int col = currNode->col;

        if (row == targetRow && col == targetCol) {
            endNode = currNode;
            break;
        }

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int newRow = row + i;
                int newCol = col + j;
                if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS && (i != 0 || j != 0) && grid[newRow][newCol] == 0 && visited[newRow][newCol] == 0) {
                    visited[newRow][newCol] = 1;
                    Node* newNode = getNode(newRow, newCol, currNode->g+1, calcManhattanDistance(newRow, newCol, targetRow, targetCol), currNode);
                    addNodeToPriorityQueue(pq, newNode);
                }
            }
        }
    }

    printPath(endNode);

    // Free memory
    while (pq->size > 0) {
        free(pq->arr[--pq->size]);
    }
    free(pq);
}