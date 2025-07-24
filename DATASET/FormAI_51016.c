//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,0,1,0,1},
    {1,0,1,0,0,0,0,1,0,1},
    {1,0,1,0,1,1,1,0,0,1},
    {1,0,1,0,0,0,0,0,1,1},
    {1,0,1,1,0,1,1,0,1,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,1,0,1,1,0,1,0,0,1},
    {1,1,1,1,1,1,1,1,1,1},
};

// Represents a cell in the maze
typedef struct {
    int row;
    int col;
} Cell;

// Stack implementation to store the path
typedef struct {
    Cell items[ROWS * COLS];
    int top;
} Stack;

// Function to initialize an empty stack
void makeEmpty(Stack *stack) {
    stack->top = -1;
}

// Function to push an element onto the stack
void push(Stack *stack, Cell item) {
    stack->items[++stack->top] = item;
}

// Function to pop an element from the stack
Cell pop(Stack *stack) {
    return stack->items[stack->top--];
}

// Function to check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Prints the solution path
void printPath(Stack *stack) {
    printf("Solution path: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("(%d,%d) ", stack->items[i].row, stack->items[i].col);
    }
    printf("\n");
}

// Finds a path through the maze using the right-hand rule
void findPath() {
    // Define the starting position
    Cell start = {1,1};
    Cell current = start;

    // Define the direction to move
    int direction = 0; //0=East, 1=South, 2=West, 3=North

    // Create an empty stack to store the path
    Stack stack;
    makeEmpty(&stack);

    // Push the starting cell onto the stack
    push(&stack, current);

    // Loop until the path is found or there are no more cells to explore
    while (!isEmpty(&stack)) {
        // Pop the current cell off the stack
        current = pop(&stack);

        // If we have found the end of the maze, print the path and exit the function
        if (current.row == 8 && current.col == 8) {
            printPath(&stack);
            return;
        }

        // Check if we can move right
        if (maze[current.row][current.col+1] == 0 && direction != 2) {
            // Move right
            Cell next = {current.row, current.col+1};
            push(&stack, current);
            direction = 0;
            push(&stack, next);
        }
        // Check if we can move down
        else if (maze[current.row+1][current.col] == 0 && direction != 3) {
            // Move down
            Cell next = {current.row+1, current.col};
            push(&stack, current);
            direction = 1;
            push(&stack, next);
        }
        // Check if we can move left
        else if (maze[current.row][current.col-1] == 0 && direction != 0) {
            // Move left
            Cell next = {current.row, current.col-1};
            push(&stack, current);
            direction = 2;
            push(&stack, next);
        }
        // Check if we can move up
        else if (maze[current.row-1][current.col] == 0 && direction != 1) {
            // Move up
            Cell next = {current.row-1, current.col};
            push(&stack, current);
            direction = 3;
            push(&stack, next);
        }
    }

    // If we have reached this point, then no path was found
    printf("There is no path through the maze!\n");
}

int main() {
    findPath();
    return 0;
}