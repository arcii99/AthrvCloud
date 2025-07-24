//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// size of the grid
#define N 10

// starting and ending points of the percolation
#define START 0
#define END (N * N - 1)

// function to get the index in 1D array from (i,j) pair
int get_index(int i, int j)
{
    return (i * N + j);
}

// function to print the grid
void print_grid(int grid[N][N])
{
    printf("\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// union-find data structure implementation
int parent[N * N], rank[N * N];
void make_set(int x) {
    parent[x] = x;
    rank[x] = 1;
}
int find_set(int x) {
    if (x != parent[x]) {
        parent[x] = find_set(parent[x]);
    }
    return parent[x];
}
void union_sets(int x, int y) {
    int root_x = find_set(x);
    int root_y = find_set(y);
    if (root_x != root_y) {
        if (rank[root_x] < rank[root_y]) {
            parent[root_x] = root_y;
        } else {
            parent[root_y] = root_x;
            if (rank[root_x] == rank[root_y]) {
                rank[root_x]++;
            }
        }
    }
}

// function to check if the percolation has occurred
int percolates(int grid[N][N])
{
    // initializing parent arrays for the union-find data structure
    for (int i = 0; i < N * N; i++)
    {
        make_set(i);
    }

    // connecting all the open cells in the first row with the virtual top cell
    for (int j = 0; j < N; j++)
    {
        if (grid[0][j])
        {
            union_sets(START, get_index(0, j));
        }
    }

    // connecting all the open cells in the last row with the virtual bottom cell
    for (int j = 0; j < N; j++)
    {
        if (grid[N - 1][j])
        {
            union_sets(END, get_index(N - 1, j));
        }
    }

    // connecting open cells with their neighboring open cells in the grid
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j])
            {
                // connecting with right cell
                if (j < N - 1 && grid[i][j + 1])
                {
                    union_sets(get_index(i, j), get_index(i, j + 1));
                }

                // connecting with bottom cell
                if (i < N - 1 && grid[i + 1][j])
                {
                    union_sets(get_index(i, j), get_index(i + 1, j));
                }
            }
        }
    }

    // if the virtual top cell and virtual bottom cell are in the same set, then percolation has occurred
    if (find_set(START) == find_set(END))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// function to simulate percolation and return the probability of percolation
float simulate_percolation()
{
    int grid[N][N] = {0}; // initializing all cells as closed
    int open_count = 0; // number of open cells
    float p = 0.0; // probability of each cell being open

    srand(time(NULL)); // seeding random number generator

    while (!percolates(grid)) // simulating until percolation occurs
    {
        // generating random i,j pairs for opening cells
        int i = rand() % N;
        int j = rand() % N;

        // if the cell is already open, continue to next iteration
        if (grid[i][j])
        {
            continue;
        }

        // opening the cell
        grid[i][j] = 1;
        open_count++;

        // calculating the new probability of each cell being open
        p = (float) open_count / (N * N);
    }

    return p;
}

int main()
{
    float p = simulate_percolation();
    printf("Probability of percolation: %f\n", p);

    return 0;
}