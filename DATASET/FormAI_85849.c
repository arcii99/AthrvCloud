//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size of the map
#define MAX_ROWS 10
#define MAX_COLS 10

// Define the starting and ending positions
#define START_ROW 1
#define START_COL 1
#define END_ROW 8
#define END_COL 8

// Define the map
char map[MAX_ROWS][MAX_COLS] = {
    {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
    {'O', 'S', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
    {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
    {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
    {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
    {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
    {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
    {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
    {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
    {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
};

// Define the direction of movement
int direction_start = 0;
int direction_end = 0;
int directions[4] = {1, 3, 7, 9}; // Diagonal movement is allowed

// Define the queue for BFS
struct Queue {
    int row, col, dist;
} queue[MAX_ROWS * MAX_COLS];
int front = -1, rear = -1;

// Initialize the queue
void init_queue() {
    front = rear = -1;
}

// Check if the queue is empty
bool is_queue_empty() {
    return front == -1;
}

// Enqueue an element in the queue
void enqueue(int row, int col, int dist) {
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear].row = row;
    queue[rear].col = col;
    queue[rear].dist = dist;
}

// Dequeue an element from the queue
struct Queue dequeue() {
    struct Queue item = queue[front];
    front++;
    if (front > rear) {
        front = rear = -1;
    }
    return item;
}

// Check if the given position is valid
bool is_valid(int row, int col) {
    if (row >= 0 && row < MAX_ROWS && col >= 0 && col < MAX_COLS) {
        return true;
    }
    return false;
}

// Check if the given position is open
bool is_open(int row, int col) {
    if (map[row][col] == 'O') {
        return true;
    }
    return false;
}

// Check if the given position is the end position
bool is_end(int row, int col) {
    if (row == END_ROW && col == END_COL) {
        return true;
    }
    return false;
}

// Perform BFS to find the shortest path
bool bfs() {
    init_queue();
    enqueue(START_ROW, START_COL, 0);
    while (!is_queue_empty()) {
        struct Queue current = dequeue();
        int row = current.row;
        int col = current.col;
        int dist = current.dist;
        if (is_end(row, col)) {
            return true;
        }
        for (int i = 0; i < 4; i++) { // Loop through all possible directions
            if (direction_end == 0 || direction_end == directions[i]) {
                int new_row = row + ((directions[i] / 3) - 1);
                int new_col = col + ((directions[i] % 3) - 1);
                if (is_valid(new_row, new_col) && is_open(new_row, new_col)) {
                    map[new_row][new_col] = 'X'; // Mark the position as visited
                    enqueue(new_row, new_col, dist + 1);
                }
            }
        }
    }
    return false;
}

// Print the map
void print_map() {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Map before BFS:\n");
    print_map();
    printf("\n");
    if (bfs()) {
        printf("Shortest path from start to end is %d steps:\n", queue[rear].dist);
        struct Queue current = queue[rear];
        while (current.row != START_ROW || current.col != START_COL) {
            for (int i = 0; i < 4; i++) {
                if (direction_start == 0 || direction_start == directions[i]) {
                    int new_row = current.row + ((directions[i] / 3) - 1);
                    int new_col = current.col + ((directions[i] % 3) - 1);
                    if (is_valid(new_row, new_col) && 
                        queue[rear-1].dist == current.dist - 1 &&
                        is_open(new_row, new_col)) {
                            direction_start = (directions[i] + 5) % 10; // Set the reverse direction
                            current.row = new_row;
                            current.col = new_col;
                            map[new_row][new_col] = '+';
                            break;
                    }
                }
            }
        }
        map[START_ROW][START_COL] = 'S';
        print_map();
    } else {
        printf("No path found from start to end.\n");
    }
    return 0;
}