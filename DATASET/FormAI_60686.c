//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the size of the map
#define ROW_SIZE 5
#define COL_SIZE 8

// Define the map
int map[ROW_SIZE][COL_SIZE] = {
    {0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
};

// Define the start and end points
int start_row = 0;
int start_col = 0;
int end_row = ROW_SIZE-1;
int end_col = COL_SIZE-1;

// Define the queue
int queue[ROW_SIZE*COL_SIZE][2];
int queue_front = -1;
int queue_rear = -1;

// Define the visited array
bool visited[ROW_SIZE][COL_SIZE];

// Define the path array
int path[ROW_SIZE*COL_SIZE][2];
int path_index = -1;

// Function to add element to the queue
void enqueue(int row, int col) {
    if (queue_front == -1) {
        queue_front = 0;
    }
    queue_rear++;
    queue[queue_rear][0] = row;
    queue[queue_rear][1] = col;
}

// Function to remove element from the queue
bool dequeue(int *row, int *col) {
    if (queue_front == -1 || queue_front > queue_rear) {
        return false;
    }
    *row = queue[queue_front][0];
    *col = queue[queue_front][1];
    queue_front++;
    return true;
}

// Function to check if a cell is valid
bool is_valid(int row, int col) {
    if (row < 0 || row >= ROW_SIZE) {
        return false;
    }
    if (col < 0 || col >= COL_SIZE) {
        return false;
    }
    if (map[row][col] == 1) {
        return false;
    }
    if (visited[row][col] == true) {
        return false;
    }
    return true;
}

// Function to perform the breadth first search
void bfs() {
    // Add the starting point to the queue
    enqueue(start_row, start_col);
    
    while (dequeue(&start_row, &start_col)) {
        // Check if this point is the end point
        if (start_row == end_row && start_col == end_col) {
            // Trace back the path and print it out
            path_index++;
            int row = end_row;
            int col = end_col;
            while (row != -1 && col != -1) {
                path[path_index][0] = row;
                path[path_index][1] = col;
                
                int temp_row = row;
                row = map[row][col]/COL_SIZE;
                col = map[temp_row][col]%COL_SIZE;
            }
            printf("Shortest path found:\n");
            for (int i = path_index; i >= 0; i--) {
                printf("(%d, %d) ", path[i][0], path[i][1]);
            }
            printf("\n");
            return;
        }
        
        // Mark this cell as visited
        visited[start_row][start_col] = true;
        
        // Check the neighbours
        if (is_valid(start_row-1, start_col)) {
            map[start_row-1][start_col] = start_row*COL_SIZE + start_col;
            enqueue(start_row-1, start_col);
        }
        if (is_valid(start_row+1, start_col)) {
            map[start_row+1][start_col] = start_row*COL_SIZE + start_col;
            enqueue(start_row+1, start_col);
        }
        if (is_valid(start_row, start_col-1)) {
            map[start_row][start_col-1] = start_row*COL_SIZE + start_col;
            enqueue(start_row, start_col-1);
        }
        if (is_valid(start_row, start_col+1)) {
            map[start_row][start_col+1] = start_row*COL_SIZE + start_col;
            enqueue(start_row, start_col+1);
        }
    }
}

int main() {
    bfs();
    return 0;
}