//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 10 // size of grid
#define P 0.6 // probability of a site being open

bool isOpen[N][N]; // matrix to store whether site is open
bool isFull[N][N]; // matrix to store whether site is full
bool isVisited[N][N]; // matrix to store whether site has been visited

// function to initialize grid
void initializeGrid()
{
    // initialize grid with random state
    srand(time(NULL));
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            // generate random number between 0 and 1
            float randNum = (float)rand() / RAND_MAX;
            
            // if randNum is less than or equal to P, set site to open
            if(randNum <= P) isOpen[i][j] = true;
        }
    }
}

// function to check if site is open
bool isOpenSite(int row, int col)
{
    if (row < 0 || row >= N || col < 0 || col >= N) return false;
    return isOpen[row][col];
}

// function to check if site is full
bool isFullSite(int row, int col)
{
    if (row < 0 || row >= N || col < 0 || col >= N) return false;
    if (!isOpen[row][col] || isVisited[row][col] || isFull[row][col]) return false;
    if (row == 0) return true;
    
    isVisited[row][col] = true;
    
    // recursive calls to neighboring sites
    bool isFullTop = isFullSite(row-1, col);
    bool isFullLeft = isFullSite(row, col-1);
    bool isFullRight = isFullSite(row, col+1);
    bool isFullBottom = isFullSite(row+1, col);
    
    // if any neighboring site is full, set current site to full
    if (isFullTop || isFullLeft || isFullRight || isFullBottom)
    {
        isFull[row][col] = true;
        return true;
    }
    
    return false;
}

int main()
{
    initializeGrid();
    
    // print grid before percolation
    printf("Before percolation:\n");
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(isOpen[i][j]) printf("1 ");
            else printf("0 ");
        }
        printf("\n");
    }
    
    // check if grid percolates
    for(int j=0; j<N; j++)
    {
        isFullSite(N-1, j);
    }
    bool percolates = false;
    for(int j=0; j<N; j++)
    {
        if(isFull[0][j])
        {
            percolates = true;
            break;
        }
    }
    
    // print grid after percolation
    printf("\nAfter percolation:\n");
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(percolates && isFull[i][j]) printf("2 ");
            else if(isOpen[i][j]) printf("1 ");
            else printf("0 ");
        }
        printf("\n");
    }
    
    // print whether grid percolates
    if(percolates) printf("\nThe grid percolates.\n");
    else printf("\nThe grid does not percolate.\n");
    
    return 0;
}