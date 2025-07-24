//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maze dimension and wall character
#define WIDTH 10
#define HEIGHT 10
#define WALL '#'

// Define the cell structure
struct cell {
    int x, y;
    int top, bottom, left, right;
    int visited;
};

// Initialize the maze
void initialize(struct cell maze[WIDTH][HEIGHT])
{
    for (int x = 0; x < WIDTH; ++x) {
        for (int y = 0; y < HEIGHT; ++y) {
            maze[x][y].x = x;
            maze[x][y].y = y;
            maze[x][y].top = 1;
            maze[x][y].bottom = 1;
            maze[x][y].left = 1;
            maze[x][y].right = 1;
            maze[x][y].visited = 0;
        }
    }
}

// Check if a neighbor cell is valid
int is_valid(int x, int y)
{
    return (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT);
}

// Get a random neighbor cell
struct cell * get_neighbor(struct cell maze[WIDTH][HEIGHT], struct cell * cell)
{
    struct cell * neighbors[4] = {
        &maze[cell->x][cell->y-1],
        &maze[cell->x][cell->y+1],
        &maze[cell->x-1][cell->y],
        &maze[cell->x+1][cell->y]
    };
    int count = 0;
    for (int i = 0; i < 4; ++i) {
        if (is_valid(neighbors[i]->x, neighbors[i]->y) && !neighbors[i]->visited) {
            ++count;
        }
    }
    if (count == 0) {
        return NULL;
    }
    int index = rand() % count;
    for (int i = 0; i < 4; ++i) {
        if (is_valid(neighbors[i]->x, neighbors[i]->y) && !neighbors[i]->visited) {
            if (index == 0) {
                return neighbors[i];
            }
            --index;
        }
    }
    return NULL;
}

// Remove a wall
void remove_wall(struct cell * curr, struct cell * next)
{
    if (curr->x == next->x && curr->y > next->y) {
        curr->top = 0;
        next->bottom = 0;
    }
    else if (curr->x == next->x && curr->y < next->y) {
        curr->bottom = 0;
        next->top = 0;
    }
    else if (curr->y == next->y && curr->x > next->x) {
        curr->left = 0;
        next->right = 0;
    }
    else if (curr->y == next->y && curr->x < next->x) {
        curr->right = 0;
        next->left = 0;
    }
}

// Generate the maze
void generate(struct cell maze[WIDTH][HEIGHT], struct cell * curr)
{
    curr->visited = 1;
    struct cell * next = get_neighbor(maze, curr);
    while (next != NULL) {
        remove_wall(curr, next);
        generate(maze, next);
        next = get_neighbor(maze, curr);
    }   
}

// Print the maze
void print(struct cell maze[WIDTH][HEIGHT])
{
    printf("+");
    for (int x = 0; x < WIDTH; ++x) {
        printf("-+");
    }
    printf("\n");
    for (int y = 0; y < HEIGHT; ++y) {
        printf("|");
        for (int x = 0; x < WIDTH; ++x) {
            printf(" ");
            if (maze[x][y].bottom) {
                printf("%c", WALL);
            }
            else {
                printf(" ");
            }
            printf(" ");
            if (maze[x][y].right) {
                printf("%c", WALL);
            }
            else {
                printf(" ");
            }
            printf("|");
        }
        printf("\n+");
        for (int x = 0; x < WIDTH; ++x) {
            if (maze[x][y].top) {
                printf("%c", WALL);
            }
            else {
                printf(" ");
            }
            printf("-+");
        }
        printf("\n");
    }
}

int main()
{
    srand(time(NULL));
    struct cell maze[WIDTH][HEIGHT];
    initialize(maze);
    generate(maze, &maze[rand() % WIDTH][rand() % HEIGHT]);
    print(maze);
    return 0;
}