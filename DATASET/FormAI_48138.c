//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAZE_SIZE 10

int maze[MAZE_SIZE][MAZE_SIZE] = 
{
    {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
    {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
    {1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
    {0, 0, 1, 0, 1, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 1, 1, 0, 1, 0},
    {1, 0, 1, 1, 1, 1, 0, 1, 0, 0},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
    {1, 1, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

// Node structure to store coordinates
typedef struct Node
{
    int x, y;
} Node;

// Stack data structure for storing path
typedef struct Stack
{
    Node data[MAZE_SIZE * MAZE_SIZE];
    int size;
} Stack;

// Initialize stack
void init_stack(Stack* s)
{
    s->size = 0;
}

// Push element onto stack
void push(Stack* s, Node n)
{
    s->data[s->size++] = n;
}

// Pop element off stack
Node pop(Stack* s)
{
    return s->data[--s->size];
}

// Get top element of stack
Node top(Stack* s)
{
    return s->data[s->size - 1];
}

// Check if stack is empty
bool is_empty(Stack* s)
{
    return s->size == 0;
}

// Find a path through the maze
bool find_path(int x, int y, Stack* path)
{
    // Check if current position is outside bounds of the maze
    if (x < 0 || x >= MAZE_SIZE || y < 0 || y >= MAZE_SIZE)
    {
        return false;
    }

    // Check if current position is the end of the maze
    if (maze[x][y] == 0)
    {
        return true;
    }

    // Check if current position has already been visited
    if (maze[x][y] == 2)
    {
        return false;
    }

    // Mark current position as visited
    maze[x][y] = 2;

    // Try moving in all four directions
    if (find_path(x + 1, y, path) || 
        find_path(x - 1, y, path) ||
        find_path(x, y + 1, path) || 
        find_path(x, y - 1, path))
    {
        // Push current position onto the stack
        push(path, (Node){x, y});
        return true;
    }

    // If no path is found, unmark current position and return false
    maze[x][y] = 1;
    return false;
}

// Print the maze
void print_maze()
{
    for (int i = 0; i < MAZE_SIZE; i++)
    {
        for (int j = 0; j < MAZE_SIZE; j++)
        {
            if (maze[i][j] == 0)
            {
                printf("F ");
            }
            else
            {
                printf("%d ", maze[i][j]);
            }
        }
        printf("\n");
    }
}

int main()
{
    printf("Welcome to the Maze Route Finder!\n");
    printf("Here is the maze:\n\n");
    print_maze();

    // Get starting position from user
    int x, y;
    printf("\nEnter starting coordinates (x y): ");
    scanf("%d %d", &x, &y);

    // Find the path through the maze
    Stack path;
    init_stack(&path);
    if (find_path(x, y, &path))
    {
        // Print the path in reverse order
        printf("\nPath found!\n");
        while (!is_empty(&path))
        {
            Node n = pop(&path);
            printf("(%d,%d) ", n.x, n.y);
        }
        printf("\n");
    }
    else
    {
        printf("\nNo path found!\n");
    }

    printf("\nThank you for using the Maze Route Finder!\n");
    return 0;
}