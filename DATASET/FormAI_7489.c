//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: futuristic
#include <stdio.h>

// Define maze matrix and its size
int maze[10][10] = {
    {1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};
int size = 10;

// Define the structure of each point in the maze
typedef struct {
    int x;
    int y;
} Point;

// Define the stack used for DFS algorithm
typedef struct {
    Point points[100];   // Maximum stack size is 100
    int top;
} Stack;

// Function to push a Point onto the stack
void push(Stack *S, Point P) {
    S->points[++(S->top)] = P;
}

// Function to pop and return a Point from the stack
Point pop(Stack *S) {
    return S->points[(S->top)--];
}

// Function to check if a Point is within the bounds of the maze
int isValid(Point P) {
    if (P.x < 0 || P.x >= size || P.y < 0 || P.y >= size || maze[P.x][P.y] == 0) {
        return 0;
    }
    return 1;
}

// Function to find a route from the starting point to the ending point in the maze
void findRoute(Point start, Point end) {
    Stack S;
    S.top = -1;
    push(&S, start);
    maze[start.x][start.y] = 0;   // Mark the starting point as visited
    
    while (S.top != -1) {
        Point current = pop(&S);
        if (current.x == end.x && current.y == end.y) {   // Found the ending point
            printf("Route found!\n");
            while (S.top != -1) {
                Point P = pop(&S);
                printf("(%d, %d) -> ", P.x, P.y);
            }
            printf("(%d, %d)\n", start.x, start.y);
            return;
        }
        Point next = { current.x, current.y + 1 };
        if (isValid(next)) {
            push(&S, next);
            maze[next.x][next.y] = 0;
        }
        next = (Point) { current.x + 1, current.y };
        if (isValid(next)) {
            push(&S, next);
            maze[next.x][next.y] = 0;
        }
        next = (Point) { current.x, current.y - 1 };
        if (isValid(next)) {
            push(&S, next);
            maze[next.x][next.y] = 0;
        }
        next = (Point) { current.x - 1, current.y };
        if (isValid(next)) {
            push(&S, next);
            maze[next.x][next.y] = 0;
        }
    }
    printf("Unable to find a route!\n");
}

int main() {
    Point start = { 1, 1 };
    Point end = { 8, 8 };
    findRoute(start, end);
    return 0;
}