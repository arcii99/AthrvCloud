//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20     // grid size
#define P 0.6    // probability of a site being open

int uf_parent[N*N];  // array for Union-Find algorithm
int uf_size[N*N]; 

int find(int p)  // Union-Find: find the root of p
{
    while (p != uf_parent[p]) {
        uf_parent[p] = uf_parent[uf_parent[p]];
        p = uf_parent[p];
    }
    return p;
}

void union_sites(int p, int q)  // Union-Find: join p and q (weighted-quick-union-with-path-compression)
{
    int root_p = find(p);
    int root_q = find(q);
    if (root_p == root_q) return;
    if (uf_size[root_p] < uf_size[root_q]) {
        uf_parent[root_p] = root_q;
        uf_size[root_q] += uf_size[root_p];
    } else {
        uf_parent[root_q] = root_p;
        uf_size[root_p] += uf_size[root_q];
    }
}

int percolates()  // check if the system percolates
{
    for (int j = 0; j < N; j++) {
        if (find(j) == find(N*(N-1) + j)) {
            return 1;
        }
    }
    return 0;
}

void print_grid(char grid[N*N])  // print the current status of the grid
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c", grid[i*N + j]);
        }
        printf("\n");
    }
    printf("\n");
}

void percolation_simulator()   // the main function of the program
{
    char grid[N*N];           // the grid with closed sites and open sites ('X' and 'O', respectively)
    for (int i = 0; i < N*N; i++) {
        uf_parent[i] = i;     // initializing Union-Find
        uf_size[i] = 1;
        grid[i] = 'X';        // all sites are closed at the beginning
    }
    srand(time(NULL));       // initializing the random number generator with a different seed each time
    for (int i = 0; i < N*N; i++) {    // randomly opening sites with probability P
        if ((double) rand()/RAND_MAX < P) {
            grid[i] = 'O';
            if (i >= N) {    // connecting to the open neighbors
                if (grid[i-N] == 'O') union_sites(i, i-N);
            }
            if (i % N != 0) {
                if (grid[i-1] == 'O') union_sites(i, i-1);
            }
            if (i % N != N-1) {
                if (grid[i+1] == 'O') union_sites(i, i+1);
            }
            if (i < N*(N-1)) {
                if (grid[i+N] == 'O') union_sites(i, i+N);
            }
        }
        print_grid(grid);   // printing the grid at each step
        if (percolates()) { // if the system percolates, stop the simulation
            printf("The system percolates!\n");
            return;
        }
    }
    printf("The system does not percolate.\n"); // if the system never percolates, this message is printed
}

int main()
{
    percolation_simulator();
    return 0;
}