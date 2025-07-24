//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAZE_ROWS 5
#define MAZE_COLS 5

// Maze represented as a 2D array of integers
int maze[MAZE_ROWS][MAZE_COLS] = 
{
    {0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0},
    {1, 1, 0, 0, 0},
    {0, 1, 1, 0, 1},
    {0, 0, 0, 0, 0}
};

// Struct to represent a coordinate in the maze
typedef struct
{
    int x;
    int y;
} coord;

// Stack struct for backtracking
typedef struct
{
    int top;
    coord items[MAZE_ROWS * MAZE_COLS];
} stack;

// Initialize stack
stack s;
void init_stack() 
{
    s.top = -1;
}

// Check if stack is empty
int is_empty() 
{
    return s.top == -1;
}

// Push item onto stack
void push(coord c) 
{
    s.top++;
    s.items[s.top] = c;
}

// Pop item from stack
coord pop() 
{
    coord c = s.items[s.top];
    s.top--;
    return c;
}

// Get neighboring coordinates
coord *get_neighbors(coord c) 
{
    static coord neighbors[4];
    neighbors[0] = (coord) {c.x + 1, c.y};
    neighbors[1] = (coord) {c.x - 1, c.y};
    neighbors[2] = (coord) {c.x, c.y + 1};
    neighbors[3] = (coord) {c.x, c.y - 1};
    return neighbors;
}

// Check if coordinate is within bounds of maze
int within_bounds(coord c) 
{
    return c.x >= 0 && c.x < MAZE_ROWS && c.y >= 0 && c.y < MAZE_COLS;
}

// Check if coordinate is a valid move (not a wall and not already visited)
int valid_move(coord *c) 
{
    return within_bounds(*c) && !maze[c->x][c->y];
}

// Find the exit of the maze using depth-first search
void find_exit(coord start, coord end) 
{
    init_stack();
    push(start);
    while (!is_empty()) 
    {
        coord cur = pop();
        if (cur.x == end.x && cur.y == end.y) 
        {
            printf("Path found!\n");
            break;
        }
        maze[cur.x][cur.y] = 2; // Mark as visited
        // Push valid neighboring coordinates onto stack
        coord *neighbors = get_neighbors(cur);
        for (int i = 0; i < 4; i++) 
        {
            if (valid_move(&neighbors[i])) 
            {
                push(neighbors[i]);
            }
        }
    }
    if (is_empty()) 
    {
        printf("No path found\n");
    }
}

int main() 
{
    coord start = (coord) {0, 0};
    coord end = (coord) {4, 4};
    find_exit(start, end);
    return 0;
}