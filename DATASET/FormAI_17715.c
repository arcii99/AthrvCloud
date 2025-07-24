//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

// define the maze dimensions
#define ROWS 5
#define COLS 5

// define the maze structure
typedef struct Maze {
    int grid[ROWS][COLS];
} Maze;

// define the position structure
typedef struct Position {
    int x;
    int y;
} Position;

// define the stack structure
typedef struct Stack {
    Position data[ROWS * COLS];
    int top;
} Stack;

// initialize the stack
void initStack(Stack *stack) {
    stack->top = -1;
}

// check if the stack is empty
int isStackEmpty(Stack *stack) {
    return (stack->top == -1);
}

// push an element onto the stack
void push(Stack *stack, Position pos) {
    stack->top++;
    stack->data[stack->top] = pos;
}

// pop an element from the stack
Position pop(Stack *stack) {
    Position pos = stack->data[stack->top];
    stack->top--;
    return pos;
}

// check if a given position is valid
int isValid(Maze maze, Position pos) {
    return (pos.x >= 0 && pos.x < ROWS && pos.y >= 0 && pos.y < COLS && maze.grid[pos.x][pos.y] == 0);
}

// check if a given position is the destination
int isDestination(Position pos, Position dest) {
    return (pos.x == dest.x && pos.y == dest.y);
}

// find the route in the maze using the depth-first search algorithm
int findRoute(Maze maze, Position start, Position dest) {
    Stack stack;
    Position curr, next;
    int visited[ROWS][COLS] = {0};
    
    initStack(&stack);
    push(&stack, start);
    
    while (!isStackEmpty(&stack)) {
        curr = pop(&stack);
        
        if (isDestination(curr, dest)) {
            printf("Route found!\n");
            return 1;
        }
        
        visited[curr.x][curr.y] = 1;
        
        next.x = curr.x + 1;
        next.y = curr.y;
        if (isValid(maze, next) && !visited[next.x][next.y]) {
            push(&stack, next);
        }
        
        next.x = curr.x - 1;
        next.y = curr.y;
        if (isValid(maze, next) && !visited[next.x][next.y]) {
            push(&stack, next);
        }
        
        next.x = curr.x;
        next.y = curr.y + 1;
        if (isValid(maze, next) && !visited[next.x][next.y]) {
            push(&stack, next);
        }
        
        next.x = curr.x;
        next.y = curr.y - 1;
        if (isValid(maze, next) && !visited[next.x][next.y]) {
            push(&stack, next);
        }
    }
    
    printf("Route not found.\n");
    return 0;   
}

int main() {
    Maze maze = {{ {0, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0},
                   {0, 0, 0, 1, 0},
                   {1, 1, 1, 1, 0},
                   {0, 0, 0, 1, 0} }};
    Position start = {0, 0};
    Position dest = {4, 4};
    
    findRoute(maze, start, dest);
    
    return 0;
}