//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int grid[SIZE][SIZE];

// Define a struct for cells
typedef struct cell {
    int x;
    int y;
    int f;
    int g;
    int h;
    struct cell* parent;
} cell;

// Open and closed list for A*
cell *open_list = NULL, *closed_list = NULL;

// Helper function to add a cell to the open list
void add_to_open(cell* c) {
    c->parent = closed_list;
    c->g = c->parent->g + 1;
    c->h = abs(c->x - SIZE/2) + abs(c->y - SIZE/2);
    c->f = c->g + c->h;
    open_list = c;
}

// Helper function to add a cell to the closed list
void add_to_closed(cell* c) {
    closed_list = c;
}

// Helper function to see if a cell is in the open list
int in_open_list(cell* c) {
    return c == open_list;
}

// Helper function to see if a cell is in the closed list
int in_closed_list(cell* c) {
    return c == closed_list;
}

// Helper function to get the manhattan distance between two cells
int manhattan(cell* a, cell* b) {
    return abs(a->x - b->x) + abs(a->y - b->y);
}

// A* pathfinding algorithm
cell* astar() {
    // Start and end cells
    cell* start = (cell*)malloc(sizeof(cell));
    cell* end = (cell*)malloc(sizeof(cell));
    start->x = 0;
    start->y = 0;
    end->x = SIZE-1;
    end->y = SIZE-1;
    start->g = 0;
    start->h = manhattan(start, end);
    start->f = start->g + start->h;
    start->parent = NULL;
    
    // Add starting cell to the closed list
    add_to_closed(start);
    
    // Loop until path is found or no more options in open list
    while (open_list != NULL) {
        // Get cell with lowest f score from open list
        cell* current = open_list;
        cell* tmp = open_list->parent;
        while (tmp != NULL) {
            current = tmp;
            tmp = tmp->parent;
        }
        
        // Remove current from open list
        open_list = NULL;
        
        // If current is the end cell, the path has been found
        if (current->x == end->x && current->y == end->y) {
            return current;
        }
        
        // Generate neighbors of current
        cell* neighbors[4];
        int count = 0;
        if (current->x > 0) {
            neighbors[count] = (cell*)malloc(sizeof(cell));
            neighbors[count]->x = current->x - 1;
            neighbors[count]->y = current->y;
            count++;
        }
        if (current->x < SIZE-1) {
            neighbors[count] = (cell*)malloc(sizeof(cell));
            neighbors[count]->x = current->x + 1;
            neighbors[count]->y = current->y;
            count++;
        }
        if (current->y > 0) {
            neighbors[count] = (cell*)malloc(sizeof(cell));
            neighbors[count]->x = current->x;
            neighbors[count]->y = current->y - 1;
            count++;
        }
        if (current->y < SIZE-1) {
            neighbors[count] = (cell*)malloc(sizeof(cell));
            neighbors[count]->x = current->x;
            neighbors[count]->y = current->y + 1;
            count++;
        }
        
        // Add each neighbor to the open list
        for (int i = 0; i < count; i++) {
            if (!in_open_list(neighbors[i]) && !in_closed_list(neighbors[i])) {
                add_to_open(neighbors[i]);
            }
        }
        
        // Add current to the closed list
        add_to_closed(current);
    }
    
    // No path found
    return NULL;
}

// Helper function to print the grid
void print_grid() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Fill the grid with random 0's and 1's
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    
    // Print the grid
    printf("Initial grid:\n");
    print_grid();
    
    // Find a path using A*
    cell* path = astar();
    
    // If a path is found, mark it on the grid and print it
    if (path != NULL) {
        printf("Path found!\n");
        while (path != NULL) {
            grid[path->x][path->y] = 2;
            path = path->parent;
        }
        print_grid();
    } else {
        printf("No path found!\n");
    }
    
    return 0;
}