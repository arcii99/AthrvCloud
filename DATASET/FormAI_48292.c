//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define ROW 10
#define COL 10

// function to check if a cell is valid or not
int isValid(int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

// queue structure to store nodes during BFS
struct Queue {

    int row;
    int col;
};

// function to create a node for the enqueued element
struct Queue* createNode(int row, int col) {
    struct Queue* node = (struct Queue*)malloc(sizeof(struct Queue));
    node->row = row;
    node->col = col;

    return node;
}

// function to perform Breadth First Search
void BFS(int matrix[ROW][COL], int trace[ROW][COL], int row_source, int col_source, int row_dest, int col_dest) {

    // directions in which movement is allowed
    int ROWS[] = {-1, 0, 0, 1};
    int COLS[] = {0, -1, 1, 0};

    // create a queue for BFS
    struct Queue** queue = (struct Queue**)malloc(sizeof(struct Queue*));
    int front = 0, rear = 0;

    // mark the source as visited and enqueue it
    trace[row_source][col_source] = 1;
    queue[rear] = createNode(row_source, col_source);
    rear++;

    // stop the loop when the queue becomes empty or destination is reached
    while (front < rear) {

        // dequeue a vertex and print it
        int curr_row = queue[front]->row;
        int curr_col = queue[front]->col;
        printf("Visited cell: [%d,%d]\n", curr_row, curr_col);

        // destination found
        if (curr_row == row_dest && curr_col == col_dest) {
            printf("Destination found at cell: [%d,%d]\n", row_dest, col_dest);
            return;
        }

        // enqueue adjacent cells
        for (int i = 0; i < 4; i++) {

            int adj_row = curr_row + ROWS[i];
            int adj_col = curr_col + COLS[i];

            // if adjacent cell is valid, unvisited and allowed move
            if (isValid(adj_row, adj_col) && matrix[adj_row][adj_col] && !trace[adj_row][adj_col]) {

                trace[adj_row][adj_col] = trace[curr_row][curr_col] + 1;
                queue[rear] = createNode(adj_row, adj_col);
                rear++;
            }
        }
        front++;
    }

    printf("Destination not found.\n");
}

int main() {

    int matrix[ROW][COL] = {
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 0, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1, 0, 1, 0, 0, 1},
        {1, 1, 1, 0, 1, 0, 1, 0, 0, 1},
        {1, 1, 0, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}
    };

    int trace[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            trace[i][j] = 0;
        }
    }

    // starting and ending coordinates
    int row_source = 0, col_source = 0;
    int row_dest = 9, col_dest = 9;

    printf("Starting cell: [%d,%d]\n", row_source, col_source);
    printf("Destination cell: [%d,%d]\n", row_dest, col_dest);

    // perform BFS
    BFS(matrix, trace, row_source, col_source, row_dest, col_dest);

    return 0;
}