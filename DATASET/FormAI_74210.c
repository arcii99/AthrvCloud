//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: interoperable
#include <stdio.h> 

#define ROW 10 
#define COL 10 
#define INF 100000 

// A structure to hold the cell coordinates 
struct Cell 
{ 
    int row; 
    int col; 
}; 

// Boolean function to check if the cell is inside the grid 
int isValid(int row, int col) 
{ 
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL); 
} 

// Boolean function to check if the cell is not blocked or not visited 
int isUnblocked(int grid[][COL], int row, int col) 
{ 
    return grid[row][col] == 1; 
} 

// Helper function to calculate the minimum of two values 
int min(int a, int b) 
{ 
    return a < b ? a : b; 
} 

// Function to calculate the Manhattan distance between two cells 
int heuristic(int row1, int col1, int row2, int col2) 
{ 
    return abs(row1 - row2) + abs(col1 - col2); 
} 

// Main function that implements A* algorithm to find the shortest path 
void astar(int grid[][COL], struct Cell start, struct Cell end) 
{ 
    // Initialize the closed and open list
    int closed[ROW][COL]; 
    memset(closed, 0, sizeof(closed)); 

    int open[ROW][COL]; 
    memset(open, 0, sizeof(open)); 

    // Initialize the parent array 
    struct Cell parent[ROW][COL]; 
    memset(parent, -1, sizeof(parent)); 

    // Initialize the distances and f-scores of each cell 
    int dist[ROW][COL]; 
    memset(dist, INF, sizeof(dist)); 

    int f[ROW][COL]; 
    memset(f, INF, sizeof(f)); 

    // Set the distance and f-score of the starting cell to 0 
    int start_row = start.row; 
    int start_col = start.col; 
    dist[start_row][start_col] = 0; 
    f[start_row][start_col] = heuristic(start_row, start_col, end.row, end.col); 

    // Add the starting cell to the open list 
    open[start_row][start_col] = 1; 

    // Loop until the open list is empty 
    while (1) 
    { 
        // Find the cell with the lowest f-score 
        int min_f = INF; 
        int current_row = -1; 
        int current_col = -1; 

        for (int row = 0; row < ROW; row++) 
        { 
            for (int col = 0; col < COL; col++) 
            { 
                if (open[row][col] && f[row][col] < min_f) 
                { 
                    min_f = f[row][col]; 
                    current_row = row; 
                    current_col = col; 
                } 
            } 
        } 

        // If the current cell is the goal cell, we have found the shortest path 
        if (current_row == end.row && current_col == end.col) 
        { 
            break; 
        } 

        // Remove the current cell from the open list and add it to the closed list 
        open[current_row][current_col] = 0; 
        closed[current_row][current_col] = 1; 

        // Check the neighboring cells 
        for (int i = -1; i <= 1; i++) 
        { 
            for (int j = -1; j <= 1; j++) 
            { 
                if (i == 0 && j == 0) 
                { 
                    continue; 
                } 

                int neighbor_row = current_row + i; 
                int neighbor_col = current_col + j; 

                // Check if the neighbor cell is inside the grid 
                if (isValid(neighbor_row, neighbor_col)) 
                { 
                    // Check if the neighbor cell is unblocked and not already closed 
                    if (isUnblocked(grid, neighbor_row, neighbor_col) && !closed[neighbor_row][neighbor_col]) 
                    { 
                        // Calculate the tentative distance to the neighbor cell 
                        int tentative_dist = dist[current_row][current_col] + heuristic(current_row, current_col, neighbor_row, neighbor_col); 

                        // If the tentative distance is lower than the current distance, update the parent cell and distances 
                        if (tentative_dist < dist[neighbor_row][neighbor_col]) 
                        { 
                            parent[neighbor_row][neighbor_col].row = current_row; 
                            parent[neighbor_row][neighbor_col].col = current_col; 
                            dist[neighbor_row][neighbor_col] = tentative_dist; 
                            f[neighbor_row][neighbor_col] = tentative_dist + heuristic(neighbor_row, neighbor_col, end.row, end.col); 

                            // Add the neighbor cell to the open list if it is not already there 
                            if (!open[neighbor_row][neighbor_col]) 
                            { 
                                open[neighbor_row][neighbor_col] = 1; 
                            } 
                        } 
                    } 
                } 
            } 
        } 
    } 

    // Print the shortest path 
    int path_dist = dist[end.row][end.col]; 

    if (path_dist == INF) 
    { 
        printf("No path found!\n"); 
        return; 
    } 

    struct Cell path[path_dist]; 
    int path_len = 0; 

    int row = end.row; 
    int col = end.col; 

    while (row != -1 && col != -1) 
    { 
        path[path_len].row = row; 
        path[path_len].col = col; 
        path_len++; 

        int temp_row = row; 
        row = parent[row][col].row; 
        col = parent[temp_row][col].col; 
    } 

    printf("Shortest Path is:\n"); 

    for (int i = path_len - 1; i >= 0; i--) 
    { 
        printf("(%d,%d) ", path[i].row, path[i].col); 
    } 

    printf("\nShortest Path Distance is %d\n", path_dist); 
} 

// Driver function 
int main() 
{ 
    int grid[ROW][COL] =
    { 
        {1, 1, 1, 1, 1, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 1, 1, 1, 1, 1, 1} 
    }; 

    struct Cell start = {0, 0}; 
    struct Cell end = {ROW-1, COL-1}; 

    astar(grid, start, end); 

    return 0; 
}