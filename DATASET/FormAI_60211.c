//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: multi-threaded
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define ROW_SIZE 10
#define COLUMN_SIZE 10

int visited[ROW_SIZE][COLUMN_SIZE];  // Keeps track of visited cells 
int distance[ROW_SIZE][COLUMN_SIZE]; // Stores the distance from source to each cell
int maze[ROW_SIZE][COLUMN_SIZE] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
    {0, 1, 0, 1, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {0, 1, 1, 1, 1, 0, 1, 1, 0, 1},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {0, 1, 0, 1, 1, 0, 1, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
}; // A sample maze

// The struct represents the cell and its properties
struct cell {
    int row;
    int col;
    int dist;
};

int isValid(int row, int col) {
    // Returns true if the given cell is valid and not visited
    return (row >= 0) && (row < ROW_SIZE) && (col >= 0) && (col < COLUMN_SIZE) && !visited[row][col] && maze[row][col] == 0;
}

void* BFS(void* arg) {
    // The BFS algorithm
    struct cell* node = (struct cell*)arg;
    int i = node->row;
    int j = node->col;
    int dist = node->dist;
    int row[4] = {-1, 0, 1, 0};
    int col[4] = {0, 1, 0, -1};
    int k;

    // Mark the starting cell as visited and set the distance to zero
    visited[i][j] = 1;
    distance[i][j] = 0;

    // Create a queue and enqueue the starting cell
    struct cell* queue = (struct cell*)malloc(sizeof(struct cell));
    int head = 0;
    int tail = 0;
    queue[tail] = *node;
    tail++;

    // Loop until the queue is empty or we find the destination cell
    while (head < tail) {
        struct cell curr = queue[head];
        head++;

        // If we have reached the destination cell, break
        if (curr.row == ROW_SIZE-1 && curr.col == COLUMN_SIZE-1) {
            break;
        }

        // Check all four adjacent cells and enqueue them if they are valid
        for (k = 0; k < 4; k++) {
            int r = curr.row + row[k];
            int c = curr.col + col[k];
            if (isValid(r, c)) {
                visited[r][c] = 1;
                distance[r][c] = curr.dist + 1;
                struct cell next = {r, c, curr.dist + 1};
                queue = (struct cell*)realloc(queue, sizeof(struct cell) * (tail+1));
                queue[tail] = next;
                tail++;
            }
        }
    }

    free(queue);
}

int main() {
    pthread_t threads[2];
    int i, j;

    // Initialize visited and distance arrays
    for (i = 0; i < ROW_SIZE; i++) {
        for (j = 0; j < COLUMN_SIZE; j++) {
            visited[i][j] = 0;
            distance[i][j] = -1;
        }
    }

    // Create two threads, one for BFS from top-left and one for BFS from bottom-right
    struct cell start1 = {0, 0, 0};
    struct cell start2 = {ROW_SIZE-1, COLUMN_SIZE-1, 0};
    pthread_create(&threads[0], NULL, BFS, &start1);
    pthread_create(&threads[1], NULL, BFS, &start2);

    // Wait for both threads to finish
    for (i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the distance array
    for (i = 0; i < ROW_SIZE; i++) {
        for (j = 0; j < COLUMN_SIZE; j++) {
            printf("%2d ", distance[i][j]);
        }
        printf("\n");
    }

    return 0;
}