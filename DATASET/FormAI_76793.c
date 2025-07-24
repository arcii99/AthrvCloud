//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define ROWS 8
#define COLS 8

typedef struct {
    int row, col;
} Node;

Node start = {0, 0};
Node end = {ROWS-1, COLS-1};

int map[ROWS][COLS] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 1, 0},
    {0, 1, 1, 0, 1, 1, 1, 0},
    {0, 1, 1, 0, 1, 1, 1, 0},
    {0, 1, 1, 1, 1, 1, 1, 0},
    {0, 1, 1, 1, 1, 1, 1, 0},
    {0, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

int dist[ROWS][COLS];
Node prev[ROWS][COLS];
Node queue[ROWS * COLS];
int head = 0, tail = 0;

Node getNextNode() {
    return queue[head++];
}

void enqueue(Node node) {
    queue[tail++] = node;
}

int isQueueEmpty() {
    return head == tail;
}

int isValid(int row, int col) {
    return row >= 0 && row < ROWS && col >= 0 && col < COLS && map[row][col] == 1;
}

int manhattanDistance(Node a, Node b) {
    return abs(a.row - b.row) + abs(a.col - b.col);
}

void printPath() {
    Node current = end;
    while (current.row != start.row || current.col != start.col) {
        printf("%d,%d\n", current.row, current.col);
        current = prev[current.row][current.col];
    }
    printf("%d,%d\n", current.row, current.col);
}

int main() {
    int i, j;
    
    // Initialize distances to "infinity"
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            dist[i][j] = ROWS * COLS;
        }
    }
    dist[start.row][start.col] = 0;
    
    // Enqueue start node
    enqueue(start);
    
    // Breadth-first search
    while (!isQueueEmpty()) {
        Node current = getNextNode();
        int row = current.row, col = current.col;
        int d = dist[row][col];
        
        // Check if we have found the end node
        if (row == end.row && col == end.col) {
            printf("Path found:\n");
            printPath();
            return 0;
        }
        
        // Check each neighbor
        if (isValid(row-1, col)) { // Up
            int alt = d + 1;
            if (alt < dist[row-1][col]) {
                dist[row-1][col] = alt;
                prev[row-1][col] = current;
                enqueue((Node){row-1, col});
            }
        }
        if (isValid(row+1, col)) { // Down
            int alt = d + 1;
            if (alt < dist[row+1][col]) {
                dist[row+1][col] = alt;
                prev[row+1][col] = current;
                enqueue((Node){row+1, col});
            }
        }
        if (isValid(row, col-1)) { // Left
            int alt = d + 1;
            if (alt < dist[row][col-1]) {
                dist[row][col-1] = alt;
                prev[row][col-1] = current;
                enqueue((Node){row, col-1});
            }
        }
        if (isValid(row, col+1)) { // Right
            int alt = d + 1;
            if (alt < dist[row][col+1]) {
                dist[row][col+1] = alt;
                prev[row][col+1] = current;
                enqueue((Node){row, col+1});
            }
        }
        if (isValid(row-1, col-1)) { // Up-Left
            int alt = d + 1;
            if (alt < dist[row-1][col-1]) {
                dist[row-1][col-1] = alt;
                prev[row-1][col-1] = current;
                enqueue((Node){row-1, col-1});
            }
        }
        if (isValid(row-1, col+1)) { // Up-Right
            int alt = d + 1;
            if (alt < dist[row-1][col+1]) {
                dist[row-1][col+1] = alt;
                prev[row-1][col+1] = current;
                enqueue((Node){row-1, col+1});
            }
        }
        if (isValid(row+1, col-1)) { // Down-Left
            int alt = d + 1;
            if (alt < dist[row+1][col-1]) {
                dist[row+1][col-1] = alt;
                prev[row+1][col-1] = current;
                enqueue((Node){row+1, col-1});
            }
        }
        if (isValid(row+1, col+1)) { // Down-Right
            int alt = d + 1;
            if (alt < dist[row+1][col+1]) {
                dist[row+1][col+1] = alt;
                prev[row+1][col+1] = current;
                enqueue((Node){row+1, col+1});
            }
        }
    }
    
    printf("No path found\n");
    return 0;
}