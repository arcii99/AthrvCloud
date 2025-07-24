//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 10 // Size of the grid

void print_grid(int grid[N][N])
{
    printf("\n");
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(grid[i][j] == 0) // if the site is closed
            {
                printf("%c ", 219); // print a filled square
            }
            else
            {
                printf("  "); // print an empty space
            }
        }
        printf("\n");
    }
    printf("\n");
}

int is_percolated(int grid[N][N])
{
    for(int j=0; j<N; j++)
    {
        if(grid[0][j] == 1) // if the site is open at the top row
        {
            int visited[N][N] = {0};
            visited[0][j] = 1; // mark the site as visited

            // check if the site percolates from the top to the bottom
            for(int i=1; i<N; i++)
            {
                for(int k=-1; k<=1; k++)
                {
                    if(j+k>=0 && j+k<N && grid[i][j+k] == 1 && !visited[i][j+k])
                    {
                        visited[i][j+k] = 1;
                    }
                }
            }

            if(visited[N-1][j] == 1) // if the site is visited at the last row
            {
                return 1; // the percolation has occurred
            }
        }
    }
    return 0; // the percolation has not occurred
}

int main()
{
    srand(time(NULL)); // seed the random number generator

    int grid[N][N] = {0}; // Grid initialization, all the sites are closed
    int open_sites = 0;

    while(!is_percolated(grid)) // while the system has not yet percolated
    {
        int i = rand() % N; // select a random row
        int j = rand() % N; // select a random column

        if(grid[i][j] == 0) // if the site is closed
        {
            grid[i][j] = 1; // open the site
            open_sites++;

            print_grid(grid);

            printf("Open Sites: %d\n", open_sites);

            printf("Press Enter to continue...");
            getchar();
        }
    }

    printf("The system has percolated with %d open sites.\n", open_sites);

    return 0;
}