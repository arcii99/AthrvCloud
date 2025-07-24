//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10 // Size of grid
#define P 0.5 // Probability of site being open

bool grid[N][N]; // Grid array
bool connected[N][N]; // Array to track if cells are connected

// Union find data structure
int parent[N*N];
int size[N*N];

// Initialize grid with open/closed sites
void initialize_grid()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            double r = ((double) rand() / (RAND_MAX)); // Random number between 0 and 1
            
            if(r < P)
            {
                grid[i][j] = true; // Open site
            }
            else
            {
                grid[i][j] = false; // Closed site
            }
            
            connected[i][j] = false; // Initialize cells as not connected
        }
    }
}

// Initialize Union Find data structure
void initialize_uf()
{
    for(int i=0; i<N*N; i++)
    {
        parent[i] = i;
        size[i] = 1; // Initialize all sizes to 1
    }
}

// Find root element of element i in Union Find data structure
int find(int i)
{
    while(i != parent[i])
    {
        parent[i] = parent[parent[i]]; // Path compression
        i = parent[i];
    }
    
    return i;
}

// Union operation in Union Find data structure
void union_find(int p, int q)
{
    int root_p = find(p);
    int root_q = find(q);
    
    if(root_p == root_q)
    {
        return;
    }
    
    if(size[root_p] < size[root_q])
    {
        parent[root_p] = root_q;
        size[root_q] += size[root_p];
    }
    else
    {
        parent[root_q] = root_p;
        size[root_p] += size[root_q];
    }
}

// Connect open cells to top row of grid
void connect_top_row()
{
    for(int j=0; j<N; j++)
    {
        if(grid[0][j])
        {
            int index = j;
            
            if(index > 0 && grid[0][index-1])
            {
                union_find(index, index-1); // Connect to left cell
            }
            
            if(index < N-1 && grid[0][index+1])
            {
                union_find(index, index+1); // Connect to right cell
            }
            
            union_find(index, N); // Connect to virtual top cell
        }
    }
}

// Connect remaining cells to adjacent open cells
void connect_remaining_cells()
{
    for(int i=1; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(grid[i][j])
            {
                int index = i*N + j;
                
                if(j > 0 && grid[i][j-1])
                {
                    union_find(index, index-1); // Connect to left cell
                }
                
                if(j < N-1 && grid[i][j+1])
                {
                    union_find(index, index+1); // Connect to right cell
                }
                
                if(i > 0 && grid[i-1][j])
                {
                    union_find(index, index-N); // Connect to cell above
                }
                
                if(i < N-1 && grid[i+1][j])
                {
                    union_find(index, index+N); // Connect to cell below
                }
            }
        }
    }
}

// Check if cells are connected to top row
void check_connected_cells()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(grid[i][j])
            {
                int index = i*N + j;
                int root = find(index);
                
                if(root == N)
                {
                    connected[i][j] = true; // Set cell as connected
                }
            }
        }
    }
}

// Print grid and connected cells
void print_results()
{
    printf("Grid:\n");
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(grid[i][j])
            {
                printf("O ");
            }
            else
            {
                printf("+ ");
            }
        }
        printf("\n");
    }
    
    printf("Connected cells:\n");
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(connected[i][j])
            {
                printf("O ");
            }
            else
            {
                printf("+ ");
            }
        }
        printf("\n");
    }
}

int main()
{
    srand(42); // Set random seed for reproducibility
    
    initialize_grid(); // Initialize grid
    initialize_uf(); // Initialize Union Find data structure
    connect_top_row(); // Connect top row of grid
    connect_remaining_cells(); // Connect remaining cells
    check_connected_cells(); // Check if cells are connected to top row
    print_results(); // Print results
    
    return 0;
}