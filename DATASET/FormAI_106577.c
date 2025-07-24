//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // Grid size
#define MAX_STACK_SIZE N*N // Max size for stack array

int grid[N][N]; // 2D array to represent grid
int visited[N][N]; // 2D array to keep track of visited nodes
int top = -1; // Stack pointer initialized to -1

struct node { // Struct to hold row and col values
    int row;
    int col;
} stack[MAX_STACK_SIZE]; // Stack array

void push(int row, int col) { // Function to push values on stack
    struct node temp;
    temp.row = row;
    temp.col = col;
    if (top == MAX_STACK_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = temp;
}

int peek() { // Function to return top element from stack
    if (top == -1) {
        return -1;
    }
    return top;
}

struct node pop() { // Function to pop element from stack
    if (top == -1) {
        printf("Stack underflow\n");
        struct node temp;
        temp.row = -1;
        temp.col = -1;
        return temp;
    }
    struct node temp = stack[top--];
    return temp;
}

void initialize() { // Function to initialize grid
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            grid[i][j] = rand() % 2; // Assign random value to each node (0 or 1)
            visited[i][j] = 0; // Mark all nodes as unvisited
        }
    }
}

void printGrid() { // Function to print current state of grid
    int i, j;
    printf("\n\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

void DFS(int row, int col) { // Recursive DFS function to traverse the grid
    visited[row][col] = 1;  // Mark current node as visited
    if (grid[row][col] == 0) {
        return; // Stop if current node is blocked
    }
    push(row, col); // Add current node to stack
    while (peek() != -1) { // Continue as long as stack is not empty
        struct node temp = pop(); // Pop top element
        row = temp.row;
        col = temp.col;
        if (row > 0 && visited[row-1][col] == 0) { // Check top element
            visited[row-1][col] = 1; // Mark as visited
            if (grid[row-1][col] != 0) { // Add to stack if not blocked
                push(row-1, col);
            }
        }
        if (row < N-1 && visited[row+1][col] == 0) { // Check bottom element
            visited[row+1][col] = 1; // Mark as visited
            if (grid[row+1][col] != 0) { // Add to stack if not blocked
                push(row+1, col);
            }
        }
        if (col > 0 && visited[row][col-1] == 0) { // Check left element
            visited[row][col-1] = 1; // Mark as visited
            if (grid[row][col-1] != 0) { // Add to stack if not blocked
                push(row, col-1);
            }
        }
        if (col < N-1 && visited[row][col+1] == 0) { // Check right element
            visited[row][col+1] = 1; // Mark as visited
            if (grid[row][col+1] != 0) { // Add to stack if not blocked
                push(row, col+1);
            }
        }
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    initialize(); // Initialize grid
    printGrid(); // Print initial state of grid
    int i, j;
    for (i = 0; i < N; i++) {
        if (grid[i][0] == 1) { // Check if top element is open
            DFS(i, 0); // Traverse grid starting at top element
        }
    }
    for (i = 0; i < N; i++) {
        if (visited[i][N-1] == 1) { // Check if path was found to bottom element
            printf("\n\nPercolation achieved!\n");
            printGrid(); // Print final state of grid
            return 0;
        }
    }
    printf("\n\nPercolation not achieved :(\n");
    printGrid(); // Print final state of grid
    return 0;
}