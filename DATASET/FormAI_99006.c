//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 10 // Size of the lattice
#define p 0.5 // Occupation probability

typedef struct {
    int x;
    int y;
} Site;

int parent(int x, int y);
void merge(int x1, int y1, int x2, int y2);
bool percolates();

static int l[N];
static int r[N];
static int grid[N][N];

int main() {
    // Initializing the lattice and array
    // of disjoint sets.
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        l[i] = i;
        r[i] = i;
        for (int j = 0; j < N; j++) {
            grid[i][j] = (rand() / (double)RAND_MAX) < p ? 1 : 0;
        }
    }
    
    // Initializing the two sets for top and bottom rows.
    int topLeft = parent(0,0);
    int topRight = parent(0,N-1);
    int bottomLeft = parent(N-1,0);
    int bottomRight = parent(N-1,N-1);

    // Unionizing the sites if they are open.
    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < N-1; j++) {
            if (grid[i][j]) {
                if (grid[i][j+1])
                    merge(i, j, i, j+1);
                if (grid[i+1][j])
                    merge(i, j, i+1, j);
            }
        }
    }
  
    // Checking if the top and bottom rows have
    // some open path between them.
    if (parent(0,0) == parent(N-1,0) || parent(0,N-1) == parent(N-1,N-1))
        printf("Percolated!\n");
    else
        printf("Did not percolate.\n");
}

int parent(int x, int y) {
    int index = x*N+y;
    while (index != l[index*N+y])
        index = l[index*N+y];
    return index;
}

void merge(int x1, int y1, int x2, int y2) {
    int index1 = parent(x1, y1);
    int index2 = parent(x2, y2);
    if (index1 == index2)
        return;
    if (r[index1] > r[index2]) {
        l[index2] = index1;
        r[index1] += r[index2];
    }
    else {
        l[index1] = index2;
        r[index2] += r[index1];
    }
}

bool percolates() {
    return parent(0,0) == parent(N-1,0) || parent(0,N-1) == parent(N-1,N-1);
}