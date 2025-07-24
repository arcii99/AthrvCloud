//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#define ROW 10
#define COL 10

// Function to print the grid
void printGrid(int arr[][COL], int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}

// Function to check if a given cell (row, col) is valid or not
int isValid(int row, int col)
{
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

// Function to check if a given cell is unblocked
int isUnblocked(int arr[][COL], int row, int col)
{
    return arr[row][col] == 1;
}

// Function to check if destination cell (row, col) is reached
int isDestination(int row, int col, int destRow, int destCol)
{
    return (row == destRow) && (col == destCol);
}

// A structure to hold the cell details
struct cell
{
    int row, col;
    int f, g, h;
};

// Function to calculate the heuristic value of a given cell (row, col)
int calculateHeuristic(int row, int col, int destRow, int destCol)
{
    return abs(row - destRow) + abs(col - destCol);
}

// Function to get the neighbor cells of a given cell
void getNeighbors(int arr[][COL], struct cell current, struct cell neighbors[])
{
    int row = current.row;
    int col = current.col;
    int cost = 1;

    int rowNeighbor[] = {-1, 0, 1, 0};
    int colNeighbor[] = {0, 1, 0, -1};

    for(int i = 0; i < 4; i++)
    {
        int neighborRow = row + rowNeighbor[i];
        int neighborCol = col + colNeighbor[i];

        if(isValid(neighborRow, neighborCol) && isUnblocked(arr, neighborRow, neighborCol))
        {
            neighbors[i].row = neighborRow;
            neighbors[i].col = neighborCol;
            neighbors[i].g = current.g + cost;
            neighbors[i].h = calculateHeuristic(neighborRow, neighborCol, row, col);
            neighbors[i].f = neighbors[i].g + neighbors[i].h;
        }
    }
}

// A function to find the shortest path from (srcRow, srcCol) to (destRow, destCol)
void findShortestPath(int arr[][COL], int srcRow, int srcCol, int destRow, int destCol)
{
    if(!isValid(srcRow, srcCol))
    {
        printf("Invalid Source\n");
        return;
    }

    if(!isValid(destRow, destCol))
    {
        printf("Invalid Destination\n");
        return;
    }

    if(!isUnblocked(arr, srcRow, srcCol) || !isUnblocked(arr, destRow, destCol))
    {
        printf("Source or Destination is blocked\n");
        return;
    }

    if(isDestination(srcRow, srcCol, destRow, destCol))
    {
        printf("You are already at the destination\n");
        return;
    }

    // Create a set of open cells
    int openList[ROW][COL];

    // Initialize all cells as not visited, i.e. -1
    memset(openList, -1, sizeof(openList));

    // Mark the start cell as visited and add it to open list
    openList[srcRow][srcCol] = 0;

    // Create a set of struct cell to hold cell details
    struct cell details[ROW * COL];

    // Initialize the start cell details
    details[0].row = srcRow;
    details[0].col = srcCol;
    details[0].f = 0;
    details[0].g = 0;
    details[0].h = 0;

    int noOfDetails = 1;

    while(noOfDetails != 0)
    {
        // Select the cell with the lowest f value
        int currentIdx = 0;
        int currentF = details[0].f;

        for(int i = 1; i < noOfDetails; i++)
        {
            if(details[i].f < currentF)
            {
                currentIdx = i;
                currentF = details[i].f;
            }
        }

        struct cell current = details[currentIdx];

        // Remove the current cell from details array
        for(int i = currentIdx; i < noOfDetails - 1; i++)
            details[i] = details[i+1];

        noOfDetails--;

        // Add the current cell to the closed list
        openList[current.row][current.col] = 0;

        if(isDestination(current.row, current.col, destRow, destCol))
        {
            printf("You have reached the destination\n");
            return;
        }

        // Get the neighbor cells of the current cell
        struct cell neighbors[4];
        getNeighbors(arr, current, neighbors);

        // Add the neighbor cells to the open list
        for(int i = 0; i < 4; i++)
        {
            if(!isValid(neighbors[i].row, neighbors[i].col))
                continue;

            if(openList[neighbors[i].row][neighbors[i].col] == 0)
                continue;

            if(openList[neighbors[i].row][neighbors[i].col] != -1)
            {
                int idx = openList[neighbors[i].row][neighbors[i].col];
                if(details[idx].g > neighbors[i].g)
                    details[idx].g = neighbors[i].g;
            }
            else
            {
                int idx = noOfDetails;
                noOfDetails++;

                details[idx] = neighbors[i];
                openList[neighbors[i].row][neighbors[i].col] = idx;
            }
        }
    }

    printf("No Path Found\n");
}

int main()
{
    int arr[ROW][COL] = {
        {1, 1, 1, 1, 1, 0, 0, 0, 0, 1},
        {0, 1, 1, 1, 1, 1, 1, 0, 0, 1},
        {0, 0, 1, 0, 1, 1, 1, 0, 0, 1},
        {0, 0, 1, 1, 1, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {0, 1, 1, 1, 1, 1, 1, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
    };

    findShortestPath(arr, 0, 0, 7, 6);

    return 0;
}