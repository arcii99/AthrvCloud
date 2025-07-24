//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: interoperable
//A* pathfinding algorithm in C

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ROW 5
#define COL 5

//structure for each cell in the grid
struct cell
{
    int row, col;
};

//function to check if cell is valid or not
int isValid(int row, int col)
{
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

//function to check if cell is blocked or not
int isBlocked(int grid[][COL], int row, int col)
{
    return (grid[row][col] == 0);
}

//function to check if destination cell is reached
int isDestination(int row, int col, struct cell dest)
{
    return (row == dest.row && col == dest.col);
}

//function to calculate heuristic cost (Manhattan distance)
int calculateHeuristic(int row, int col, struct cell dest)
{
    return abs(row-dest.row) + abs(col-dest.col);
}

//A* pathfinding algorithm
void aStar(int grid[][COL], struct cell src, struct cell dest)
{
    if (!isValid(src.row, src.col))
    {
        printf("Source cell is invalid\n");
        return;
    }
    
    if (!isValid(dest.row, dest.col))
    {
        printf("Destination cell is invalid\n");
        return;
    }
    
    if (isBlocked(grid, src.row, src.col) || isBlocked(grid, dest.row, dest.col))
    {
        printf("Source or destination cell is blocked\n");
        return;
    }
    
    if (isDestination(src.row, src.col, dest))
    {
        printf("Source is already at the destination\n");
        return;
    }
    
    int visited[ROW][COL] = {0}; //matrix to keep track of visited cells
    visited[src.row][src.col] = 1;
    
    int parent[ROW][COL] = {-1}; //matrix to keep track of parent cells
    
    int cost[ROW][COL]; //matrix to store final cost of each cell
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            cost[i][j] = INT_MAX;
    cost[src.row][src.col] = 0;
    
    struct cell queue[ROW*COL]; //queue to store cells in priority order
    int front = 0, rear = 0;
    queue[rear++] = src;
    
    while (front != rear)
    {
        //dequeue cell with minimum cost
        struct cell curr = queue[front++];
        
        //stop search if destination cell is reached
        if (isDestination(curr.row, curr.col, dest))
            break;
        
        //check neighbors of current cell
        int row = curr.row;
        int col = curr.col;
        int cost_current = cost[row][col];
        int heuristic;
        
        //left cell
        if (isValid(row, col-1) && !isBlocked(grid, row, col-1))
        {
            heuristic = calculateHeuristic(row, col-1, dest);
            if (!visited[row][col-1] || cost_current+1+heuristic < cost[row][col-1])
            {
                visited[row][col-1] = 1;
                cost[row][col-1] = cost_current + 1;
                parent[row][col-1] = row*COL + col;
                queue[rear++] = (struct cell){row, col-1};
            }
        }
        
        //right cell
        if (isValid(row, col+1) && !isBlocked(grid, row, col+1))
        {
            heuristic = calculateHeuristic(row, col+1, dest);
            if (!visited[row][col+1] || cost_current+1+heuristic < cost[row][col+1])
            {
                visited[row][col+1] = 1;
                cost[row][col+1] = cost_current + 1;
                parent[row][col+1] = row*COL + col;
                queue[rear++] = (struct cell){row, col+1};
            }
        }
        
        //up cell
        if (isValid(row-1, col) && !isBlocked(grid, row-1, col))
        {
            heuristic = calculateHeuristic(row-1, col, dest);
            if (!visited[row-1][col] || cost_current+1+heuristic < cost[row-1][col])
            {
                visited[row-1][col] = 1;
                cost[row-1][col] = cost_current + 1;
                parent[row-1][col] = row*COL + col;
                queue[rear++] = (struct cell){row-1, col};
            }
        }
        
        //down cell
        if (isValid(row+1, col) && !isBlocked(grid, row+1, col))
        {
            heuristic = calculateHeuristic(row+1, col, dest);
            if (!visited[row+1][col] || cost_current+1+heuristic < cost[row+1][col])
            {
                visited[row+1][col] = 1;
                cost[row+1][col] = cost_current + 1;
                parent[row+1][col] = row*COL + col;
                queue[rear++] = (struct cell){row+1, col};
            }
        }
    }
    
    if (parent[dest.row][dest.col] == -1)
    {
        printf("Destination cell cannot be reached\n");
        return;
    }
    
    //backtrack from destination to source to get path
    int path[ROW*COL], len = 0;
    for (int row = dest.row, col = dest.col; row != src.row || col != src.col; )
    {
        int cur = row*COL + col;
        path[len++] = cur;
        int prev = parent[row][col];
        row = prev/COL;
        col = prev%COL;
    }
    path[len++] = src.row*COL + src.col;

    printf("Path is:");
    for (int i = len-1; i >= 0; i--)
        printf(" (%d,%d)", path[i]/COL, path[i]%COL);
    printf("\n");
}

//main function
int main()
{
    int grid[][COL] = 
    {
        {1, 1, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1}
    };
    
    struct cell src = {0, 0};
    struct cell dest = {4, 4};
    
    aStar(grid, src, dest);
    
    return 0;
}