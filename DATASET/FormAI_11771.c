//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ROW 5
#define COL 5

/* A structure to hold the coordinates of the current cell */
struct cell
{
    int row, col;
};

/* A structure to hold a cell's details */
struct details
{
    int f, g, h;
    struct cell parent;
};

/* Function to find the shortest path using A* Algorithm */
void findPath(int grid[][COL], struct cell start, struct cell end);

/* Function to check if a cell is blocked or not */
bool isBlocked(int grid[][COL], int row, int col);

/* Function to check if a cell is within the grid */
bool isWithinGrid(int row, int col);

/* Function to calculate the heuristic value of a cell */
int heuristicValue(struct cell current, struct cell end);

/* Function to print the path */
void printPath(struct cell path[], int steps);

/* Function to display the grid */
void displayGrid(int grid[][COL]);

int main()
{
    /* The 2D array representing the grid */
    int grid[ROW][COL] = {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
    };

    /* The starting cell */
    struct cell start = {0, 0};

    /* The ending cell */
    struct cell end = {ROW - 1, COL - 1};

    /* Display the initial grid */
    printf("Initial Grid:\n");
    displayGrid(grid);

    /* Find the shortest path using A* Algorithm */
    findPath(grid, start, end);

    return 0;
}

/* Function to find the shortest path using A* Algorithm */
void findPath(int grid[][COL], struct cell start, struct cell end)
{
    /* Array to store the closed cells */
    bool closedList[ROW][COL];

    /* Array to hold the details of each cell */
    struct details cellDetails[ROW][COL];

    int i, j;

    /* Initialise the closed list and cell details */
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            closedList[i][j] = false;
            cellDetails[i][j].f = cellDetails[i][j].g = cellDetails[i][j].h = 0;
            cellDetails[i][j].parent.row = -1;
            cellDetails[i][j].parent.col = -1;
        }
    }

    /* Initialise the starting cell's details */
    i = start.row;
    j = start.col;
    cellDetails[i][j].f = cellDetails[i][j].g = cellDetails[i][j].h = 0;
    cellDetails[i][j].parent.row = i;
    cellDetails[i][j].parent.col = j;

    /* Create a list to hold the open cells */
    struct cell openList[ROW * COL];
    int openListSize = 1;
    openList[0] = start;

    /* Loop until the end cell is found or there are no more open cells */
    bool found = false;
    while (openListSize > 0)
    {
        /* Find the cell with the lowest f value in the open list */
        int index = 0;
        for (i = 0; i < openListSize; i++)
        {
            if (cellDetails[openList[i].row][openList[i].col].f < cellDetails[openList[index].row][openList[index].col].f)
            {
                index = i;
            }
        }

        /* Get the cell with the lowest f value */
        struct cell current = openList[index];

        /* Remove the current cell from the open list */
        openList[index] = openList[openListSize - 1];
        openListSize--;

        /* Add the current cell to the closed list */
        closedList[current.row][current.col] = true;

        /* Check if we have reached the end cell */
        if (current.row == end.row && current.col == end.col)
        {
            found = true;
            break;
        }

        /* Get the neighbours of the current cell */
        struct cell neighbours[4];
        int numNeighbours = 0;

        int row = current.row - 1;
        int col = current.col;
        if (isWithinGrid(row, col) && !isBlocked(grid, row, col))
        {
            neighbours[numNeighbours++] = (struct cell){row, col};
        }

        row = current.row + 1;
        col = current.col;
        if (isWithinGrid(row, col) && !isBlocked(grid, row, col))
        {
            neighbours[numNeighbours++] = (struct cell){row, col};
        }

        row = current.row;
        col = current.col - 1;
        if (isWithinGrid(row, col) && !isBlocked(grid, row, col))
        {
            neighbours[numNeighbours++] = (struct cell){row, col};
        }

        row = current.row;
        col = current.col + 1;
        if (isWithinGrid(row, col) && !isBlocked(grid, row, col))
        {
            neighbours[numNeighbours++] = (struct cell){row, col};
        }

        /* Loop through each neighbour */
        for (i = 0; i < numNeighbours; i++)
        {
            /* Get the details of the neighbour */
            struct cell neighbour = neighbours[i];
            int neighbourG = cellDetails[current.row][current.col].g + 1;
            int neighbourH = heuristicValue(neighbour, end);
            int neighbourF = neighbourG + neighbourH;

            /* Check if the neighbour is already in the closed list */
            if (closedList[neighbour.row][neighbour.col])
            {
                continue;
            }

            /* Check if the neighbour is already in the open list */
            bool inOpenList = false;
            int neighbourIndex = -1;
            for (j = 0; j < openListSize; j++)
            {
                if (openList[j].row == neighbour.row && openList[j].col == neighbour.col)
                {
                    inOpenList = true;
                    neighbourIndex = j;
                    break;
                }
            }

            /* If the neighbour is not in the open list, add it */
            if (!inOpenList)
            {
                openList[openListSize++] = neighbour;
            }
            /* If the neighbour is in the open list, check if this path is better than the previous path */
            else if (neighbourG >= cellDetails[neighbour.row][neighbour.col].g)
            {
                continue;
            }

            /* Update the neighbour's details */
            cellDetails[neighbour.row][neighbour.col].g = neighbourG;
            cellDetails[neighbour.row][neighbour.col].h = neighbourH;
            cellDetails[neighbour.row][neighbour.col].f = neighbourF;
            cellDetails[neighbour.row][neighbour.col].parent = current;
        }
    }

    /* Print the path if one was found */
    if (found)
    {
        int steps = 0;
        struct cell path[ROW * COL];

        /* Get the cells on the path */
        struct cell current = end;
        while (current.row != start.row || current.col != start.col)
        {
            path[steps++] = current;
            current = cellDetails[current.row][current.col].parent;
        }
        path[steps++] = current;

        /* Print the path */
        printf("Path Found:\n");
        printPath(path, steps);
    }
    else
    {
        printf("No Path Found\n");
    }
}

/* Function to check if a cell is blocked or not */
bool isBlocked(int grid[][COL], int row, int col)
{
    return grid[row][col] == 1;
}

/* Function to check if a cell is within the grid */
bool isWithinGrid(int row, int col)
{
    return row >= 0 && row < ROW && col >= 0 && col < COL;
}

/* Function to calculate the heuristic value of a cell */
int heuristicValue(struct cell current, struct cell end)
{
    int dx = abs(current.row - end.row);
    int dy = abs(current.col - end.col);
    return dx + dy;
}

/* Function to print the path */
void printPath(struct cell path[], int steps)
{
    int i;
    for (i = steps - 1; i >= 0; i--)
    {
        printf("(%d, %d) -> ", path[i].row, path[i].col);
    }
    printf("\n");
}

/* Function to display the grid */
void displayGrid(int grid[][COL])
{
    int i, j;
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}