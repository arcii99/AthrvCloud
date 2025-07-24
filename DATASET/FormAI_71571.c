//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 10
#define P 0.6 // Probability of a site being open

bool grid[SIZE][SIZE];
bool open[SIZE][SIZE]; // Keeps track of which sites are open
int id[SIZE*SIZE]; // Each site's unique id
int sz[SIZE*SIZE]; // Size of each component
int opened = 0; // Number of opened sites
int components = 0; // Number of components
int max_component = 0; // Size of largest component

int root(int i)
{
    while (i != id[i])
    {
        id[i] = id[id[i]];
        i = id[i];
    }
    return i;
}

void union_find(int a, int b)
{
    int i = root(a);
    int j = root(b);
    if (i == j) return;
    if (sz[i] < sz[j])
    {
        id[i] = j;
        sz[j] += sz[i];
        if (sz[j] > max_component) max_component = sz[j];
        components--;
    }
    else
    {
        id[j] = i;
        sz[i] += sz[j];
        if (sz[i] > max_component) max_component = sz[i];
        components--;
    }
}

void init()
{
    for (int i = 0; i < SIZE*SIZE; i++)
    {
        id[i] = i;
        sz[i] = 1;
    }
    components = SIZE*SIZE;
}

void print_grid()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (grid[i][j])
            {
                if (open[i][j])
                {
                    printf(" O ");
                }
                else
                {
                    printf(" X ");
                }
            }
            else
            {
                printf("   ");
            }
        }
        printf("\n");
    }
}

void simulate()
{
    srand(time(NULL));
    while (max_component < SIZE*SIZE)
    {
        int i = rand() % SIZE;
        int j = rand() % SIZE;
        if (!grid[i][j])
        {
            grid[i][j] = true;
            if (i > 0 && grid[i-1][j]) union_find(i*SIZE+j, (i-1)*SIZE+j);
            if (i < SIZE-1 && grid[i+1][j]) union_find(i*SIZE+j, (i+1)*SIZE+j);
            if (j > 0 && grid[i][j-1]) union_find(i*SIZE+j, i*SIZE+j-1);
            if (j < SIZE-1 && grid[i][j+1]) union_find(i*SIZE+j, i*SIZE+j+1);
            opened++;
            open[i][j] = true;
            if ((float)opened / (SIZE*SIZE) >= P) break;
        }
    }
}

int main()
{
    init();
    simulate();
    print_grid();
    printf("Number of opened sites: %d\n", opened);
    printf("Number of components: %d\n", components);
    printf("Size of largest component: %d\n", max_component);
    return 0;
}