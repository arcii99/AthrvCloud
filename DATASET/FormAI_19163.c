//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10  // Number of rows in the grid
#define COL 10  // Number of columns in the grid

struct Grid {
    int vertex;  // Vertex number
    int x;  // X coordinate of vertex
    int y;  // Y coordinate of vertex
    int is_open;  // Flag to check if the vertex is open or not
};

struct Grid grid[ROW][COL];
int open_count = 0;  // Count of open vertices


// Function to initialize the grid
void initialize() {
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            grid[i][j].vertex = i*COL + j;
            grid[i][j].x = i;
            grid[i][j].y = j;
            grid[i][j].is_open = 0;
        }
    }
}

// Function to randomly open vertices
void open_random() {
    srand(time(NULL));
    while(open_count < ROW*COL) {
        int x = rand() % ROW;
        int y = rand() % COL;
        if(grid[x][y].is_open == 0) {
            grid[x][y].is_open = 1;
            open_count++;
        }
    }
}

// Function to check if a vertex is connected to the top row
int is_connected(int vertex) {
    int x = vertex / COL;
    int y = vertex % COL;
    if(grid[x][y].is_open == 0)
        return 0;
    if(x == 0)
        return 1;
    if(x != 0 && grid[x-1][y].is_open == 1)
        return is_connected(grid[x-1][y].vertex);
    if(y != 0 && grid[x][y-1].is_open == 1)
        return is_connected(grid[x][y-1].vertex);
    if(y != COL-1 && grid[x][y+1].is_open == 1)
        return is_connected(grid[x][y+1].vertex);
    return 0;
}

// Function to run the percolation simulation
int run_simulation() {
    while(open_count < ROW*COL) {
        int x = rand() % ROW;
        int y = rand() % COL;
        if(grid[x][y].is_open == 0) {
            grid[x][y].is_open = 1;
            open_count++;
            if(is_connected(grid[x][y].vertex))
                return 1;
        }
    }
    return 0;
}

// Function to print the grid
void print_grid() {
    printf(" ");
    for(int i=0; i<COL; i++)
        printf("__");
    printf("\n");
    for(int i=0; i<ROW; i++) {
        printf("|");
        for(int j=0; j<COL; j++) {
            if(grid[i][j].is_open == 1)
                printf("  ");
            else
                printf("__");
            if(j == COL-1)
                printf("|");
            else if(grid[i][j].is_open == 1 && grid[i][j+1].is_open == 1)
                printf(" ");
            else
                printf("|");
        }
        printf("\n");
    }
    printf(" ");
    for(int i=0; i<COL; i++)
        printf("--");
    printf("\n");
}

// Main function
int main() {
    initialize();
    open_random();
    print_grid();
    if(run_simulation())
        printf("The grid percolates.\n");
    else
        printf("The grid does not percolate.\n");
    return 0;
}