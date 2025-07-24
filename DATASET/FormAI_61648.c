//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS] = { // Creating the Maze
    {1,1,1,1,1,1,1,1,1,1}, // "1" represents walls
    {1,0,1,0,0,0,0,0,0,1}, // "0" represents empty cells
    {1,0,1,1,1,1,0,1,0,1},
    {1,0,1,0,0,0,0,1,0,1},
    {1,0,1,0,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,1,0,1,1,1,1,1,0,1},
    {1,1,1,1,1,1,1,1,1,1}
};

int visited[ROWS][COLS] = { // Matrix to keep track of visited cells
    {0,0,0,0,0,0,0,0,0,0}, // "0" means cell is not visited
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
};

// A node structure to keep track of coordinates (row, col) of a cell in a maze
struct Node {
    int row;
    int col;
    struct Node* next; // Pointer to next node
};

// A function to check if a cell is valid in a maze
int isValidCell(int row, int col) {
    return (row >= 0) && (row < ROWS) && (col >= 0) && (col < COLS) && (maze[row][col] == 0) && (visited[row][col] == 0);
}

// A function to push a new node into the linked list
void push(struct Node** head, int row, int col) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); // Create new node
    new_node->row = row; // Assign row value to new node
    new_node->col = col; // Assign col value to new node
    new_node->next = (*head); // Add new node to the beginning of linked list
    (*head) = new_node; // Update head to point to new node
}

// A function to pop the last node from the linked list
void pop(struct Node** head) {
    (*head) = (*head)->next; // Update head to point to next node
}

// A function to print the maze
void printMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d", maze[i][j]);
        }
        printf("\n");
    }
}

// A function to print the path found by the algorithm
void printPath(struct Node* head) {
    printf("Path:\n");
    while (head != NULL) {
        printf("(%d,%d) ", head->row, head->col);
        head = head->next;
    }
    printf("\n");
}

// A recursive function to find the path from start (row_start, col_start) to goal (row_goal, col_goal)
int findPathUtil(int row_start, int col_start, int row_goal, int col_goal, struct Node** path) {
    if (!isValidCell(row_start, col_start)) { // If start cell is not valid, return 0
        return 0;
    }
    if (row_start == row_goal && col_start == col_goal) { // If start cell is equal to goal cell, return 1
        push(path, row_start, col_start); // Add goal cell to the path
        return 1;
    }

    visited[row_start][col_start] = 1; // Mark start cell as visited

    if (findPathUtil(row_start+1, col_start, row_goal, col_goal, path) == 1) { // Check cell below (South)
        push(path, row_start, col_start); // Add current cell to path
        return 1;
    }
    if (findPathUtil(row_start-1, col_start, row_goal, col_goal, path) == 1) { // Check cell above (North)
        push(path, row_start, col_start); // Add current cell to path
        return 1;
    }
    if (findPathUtil(row_start, col_start+1, row_goal, col_goal, path) == 1) { // Check cell to the right (East)
        push(path, row_start, col_start); // Add current cell to path
        return 1;
    }
    if (findPathUtil(row_start, col_start-1, row_goal, col_goal, path) == 1) { // Check cell to the left (West)
        push(path, row_start, col_start); // Add current cell to path
        return 1;
    }

    return 0; // If no path exists, return 0
}

// A function to find the path from start (row_start, col_start) to goal (row_goal, col_goal)
void findPath(int row_start, int col_start, int row_goal, int col_goal) {
    struct Node* path = NULL; // Create an empty linked list to store path
    if (findPathUtil(row_start, col_start, row_goal, col_goal, &path) == 0) { // If no path exists, print error message
        printf("Path not found!\n");
        return;
    }
    printPath(path); // Print the path found by the algorithm
}

// main function (driver code)
int main() {
    printf("Maze:\n");
    printMaze(); // Print initial maze
    printf("\n");

    printf("Finding path from (1,1) to (8,8):\n");
    findPath(1, 1, 8, 8); // Find and print path from (1,1) to (8,8)
    printf("\n");

    printf("Finding path from (1,2) to (9,5):\n");
    findPath(1, 2, 9, 5); // Find and print path from (1,2) to (9,5)
    printf("\n");

    printf("Finding path from (0,0) to (9,9):\n");
    findPath(0, 0, 9, 9); // Find and print path from (0,0) to (9,9)
    printf("\n");

    return 0;
}