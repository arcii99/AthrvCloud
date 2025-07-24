//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maze constants
#define ROWS 6
#define COLS 7
#define WALL '#'
#define PATH ' '
#define START 'S'
#define END 'E'

// Define the maze array
char maze[ROWS][COLS] = {
    {'#','#','#','#','#','#','#'},
    {'#','S',' ','#','#','#','#'},
    {'#',' ','#',' ','#','#','#'},
    {'#',' ','#',' ',' ','#','#'},
    {'#',' ',' ','#',' ','#','E'},
    {'#','#','#','#','#','#','#'}
};

// Define the direction constants
enum Direction { UP, DOWN, LEFT, RIGHT };

// Define the Node structure
struct Node {
    int row;
    int col;
    struct Node* parent;
};

// Define the Stack structure
struct Stack {
    struct Node* data;
    struct Stack* next;
};

// Initialize the Maze Route Finder program
void init() {
    printf("Welcome to the Maze Route Finder program!\n");
    printf("The maze is shown below:\n");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

// Allocate memory for a new node
struct Node* newNode(int row, int col, struct Node* parent) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->row = row;
    node->col = col;
    node->parent = parent;
    return node;
}

// Push a node onto the stack
void push(struct Node* node, struct Stack** stack) {
    struct Stack* newStack = (struct Stack*)malloc(sizeof(struct Stack));
    newStack->data = node;
    newStack->next = *stack;
    *stack = newStack;
}

// Pop a node from the stack
struct Node* pop(struct Stack** stack) {
    if (*stack == NULL) {
        return NULL;
    }

    struct Stack* top = *stack;
    struct Node* data = top->data;
    *stack = top->next;
    free(top);
    return data;
}

// Check if a coordinate is within the bounds of the maze
bool isWithinBounds(int row, int col) {
    if (row >= ROWS || col >= COLS || row < 0 || col < 0) {
        return false;
    }

    return true;
}

// Check if a coordinate is on a valid path
bool isPath(int row, int col) {
    if (isWithinBounds(row, col) && maze[row][col] == PATH) {
        return true;
    }

    return false;
}

// Check if a coordinate is the end goal
bool isGoal(int row, int col) {
    if (isWithinBounds(row, col) && maze[row][col] == END) {
        return true;
    }

    return false;
}

// Get the next coordinate in a specific direction
void getNextCoordinate(int* row, int* col, enum Direction direction) {
    switch(direction) {
        case UP: (*row)--; break;
        case DOWN: (*row)++; break;
        case LEFT: (*col)--; break;
        case RIGHT: (*col)++; break;
    }
}

// Find the path through the maze
void findPath() {
    struct Stack* stack = NULL;
    push(newNode(1, 1, NULL), &stack);

    while (stack != NULL) {
        struct Node* current = pop(&stack);
        int row = current->row;
        int col = current->col;

        if (isGoal(row, col)) {
            struct Node* node = current;
            while (node != NULL) {
                maze[node->row][node->col] = '*';
                node = node->parent;
            }
            break;
        }

        maze[row][col] = WALL;

        for (enum Direction dir = UP; dir <= RIGHT; dir++) {
            int nextRow = row;
            int nextCol = col;
            getNextCoordinate(&nextRow, &nextCol, dir);

            if (isPath(nextRow, nextCol)) {
                push(newNode(nextRow, nextCol, current), &stack);
            }
        }
    }
}

// Print the final solution of the maze
void printSolution() {
    printf("\nThe solution to the maze is shown below:\n");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    init();
    findPath();
    printSolution();
    return 0;
}