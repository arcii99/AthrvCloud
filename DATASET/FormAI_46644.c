//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

// Define maze as a 2D array
char maze[ROWS][COLS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', '#'},
    {'#', ' ', '#', '#', ' ', '#', '#', ' ', '#', '#'},
    {'#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', ' ', '#', '#', '#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

// Define a Point struct to store coordinates
typedef struct {
    int x, y;
} Point;

// Define a Stack struct to store Points
typedef struct {
    int size;
    Point data[ROWS*COLS];
} Stack;

// Push a Point onto the Stack
void push(Stack *s, Point p) {
    s->data[s->size++] = p;
}

// Pop a Point off of the Stack
Point pop(Stack *s) {
    return s->data[--s->size];
}

// Check if a Point is inside the maze boundary and not a wall
int is_valid(Point p) {
    return (p.x >= 0 && p.x < ROWS && p.y >= 0 && p.y < COLS && maze[p.x][p.y] != '#');
}

// Find a path through the maze from start to end using depth-first search
void find_path(Point start, Point end) {
    // Create a visited array to mark which Points have been visited
    int visited[ROWS][COLS] = {0};
    // Create a Stack to store Points to be visited
    Stack s = {0};
    // Push the start Point onto the Stack
    push(&s, start);
    // While the Stack is not empty, pop the top Point and check its neighbors
    while (s.size > 0) {
        // Pop the top Point off the Stack
        Point current = pop(&s);
        // Mark the Point as visited
        visited[current.x][current.y] = 1;
        // If the current Point is the end Point, we have found a path
        if (current.x == end.x && current.y == end.y) {
            // Print the path by iterating through the Stack
            printf("Path: ");
            int i;
            for (i = 0; i < s.size; i++) {
                printf("(%d,%d) -> ", s.data[i].x, s.data[i].y);
            }
            printf("(%d,%d)\n", end.x, end.y);
            return;
        }
        // Check the neighbors of the current Point
        Point neighbors[4] = {{current.x-1, current.y}, {current.x+1, current.y},
                              {current.x, current.y-1}, {current.x, current.y+1}};
        int i;
        for (i = 0; i < 4; i++) {
            // If the neighbor is valid and has not been visited, push it onto the Stack
            if (is_valid(neighbors[i]) && !visited[neighbors[i].x][neighbors[i].y]) {
                push(&s, neighbors[i]);
            }
        }
    }
    // If we reach this point, there is no path from start to end
    printf("No path found\n");
}

int main() {
    Point start = {1, 1};
    Point end = {8, 8};
    find_path(start, end);
    return 0;
}