//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// structure that contains x and y coordinates
typedef struct coord {
    int x, y;
} coord;

int heuristic(coord a, coord b) {
    // Euclidean distance for heuristic calculation
    return sqrt(pow(abs(b.x - a.x), 2) + pow(abs(b.y - a.y), 2));
}

// Function for getting the minimum value index
int get_min(int* f, int* in_open, int size) {
    int min = size + 1;
    int min_index = -1;
    for (int i = 0; i < size; i++) {
        if (in_open[i] && f[i] < min) {
            min = f[i];
            min_index = i;
        }
    }
    return min_index;
}

void a_star(int** grid, int rows, int cols, coord start, coord end) {
    int in_open[rows*cols];
    int in_closed[rows*cols];
    int g[rows*cols];
    int f[rows*cols];
    int parent[rows*cols];
    coord neighbors[8] = {{-1, -1}, {-1, 0}, {-1, 1},
                          {0, -1}, {0, 1},
                          {1, -1}, {1, 0}, {1, 1}};
                          
    // Initialize values to 0 or infinity
    for (int i = 0; i < rows*cols; i++) {
        in_open[i] = 0;
        in_closed[i] = 0;
        g[i] = rows*cols + 1;
        f[i] = rows*cols + 1;
    }
    
    // Set starting values
    int start_index = start.x*cols + start.y;
    g[start_index] = 0;
    f[start_index] = heuristic(start, end);
    in_open[start_index] = 1;
    parent[start_index] = -1;
    
    while (1) {
        // Get the cell with minimum f value
        int current_index = get_min(f, in_open, rows*cols);
        if (current_index == -1) {
            printf("No Path Found\n");
            return;
        }
        
        // If the current cell is the goal cell
        if (current_index == end.x*cols + end.y) {
            int path[rows*cols];
            int current = current_index;
            int path_idx = 0;
            while (parent[current] != -1) {
                path[path_idx++] = current;
                current = parent[current];
            }
            path[path_idx++] = start_index;
            printf("Path: ");
            for (int i = path_idx - 1; i >= 0; i--)
                printf("(%d, %d) ", path[i]/cols, path[i]%cols);
            printf("\n");
            return;
        }
        
        // Update lists
        in_open[current_index] = 0;
        in_closed[current_index] = 1;
        
        // Traverse through neighbors
        for (int i = 0; i < 8; i++) {
            int new_x = (current_index/cols) + neighbors[i].x;
            int new_y = (current_index%cols) + neighbors[i].y;
            
            // Check if out of bounds or a wall
            if (new_x < 0 || new_x >= rows || new_y < 0 || new_y >= cols) continue;
            if (grid[new_x][new_y] == 0) continue;
            
            int neighbor_index = new_x*cols + new_y;
            
            // Check if already in closed list
            if (in_closed[neighbor_index]) continue;
            
            // Calculate new g value
            int new_g = g[current_index] + heuristic(neighbors[i], (coord){0,0});
            
            // Check if better path
            if (new_g < g[neighbor_index]) {
                parent[neighbor_index] = current_index;
                g[neighbor_index] = new_g;
                f[neighbor_index] = g[neighbor_index] + heuristic((coord){new_x, new_y}, end);
                if (!in_open[neighbor_index]) {
                    in_open[neighbor_index] = 1;
                }
            }
        }
    }
}

int main() {
    // Define a 2D array as the grid with 1s as passable, 0s as impassable
    int grid[5][5] = {
        {1, 0, 0, 0, 0},
        {1, 1, 0, 1, 0},
        {1, 1, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
    };
    // Define the start and end coordinates on the grid
    coord start = {0, 0};
    coord end = {4, 4};
    // Call the A* pathfinding function
    a_star(grid, 5, 5, start, end);
    return 0;
}