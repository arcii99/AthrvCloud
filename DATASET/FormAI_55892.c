//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: mathematical
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define ROW 8
#define COL 8

// the grid for the algorithm
int grid[ROW][COL] = {
    {0 ,  0,  0, -1,  0, -1,  0,  0},
    {0 , -1,  0,  0, -1,  0,  0,  0},
    {0 , -1,  0, -1,  0, -1,  0, -1},
    {0 , -1,  0,  0,  0, -1,  0,  0},
    {0 ,  0,  0, -1,  0,  0,  0, -1},
    {0 , -1,  0,  0,  0, -1,  0, -1},
    {0 ,  0, -1,  0,  0,  0, -1, -1},
    {0 , -1,  0,  0, -1, -1,  0, -1}
};

// 'S' and 'E' represent starting and ending points
int sx = 0, sy = 0;
int ex = 7, ey = 7;

int closedNodes[ROW][COL]; // cells checked by the algorithm
int openNodes[ROW][COL];   // cells to be checked by the algorithm
int dirX[8] = { 1,  0, -1,  0, -1,  1, -1,  1 };
int dirY[8] = { 0,  1,  0, -1, -1,  1,  1, -1 };

// calculate the Manhattan distance from current cell to the end cell
int heuristic(int x, int y)
{
    return abs(ex - x) + abs(ey - y);
}

// the A* pathfinding algorithm
void aStar()
{
    bool found = false;
    
    // initialize the two arrays
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            closedNodes[i][j] = 0;
            openNodes[i][j] = 0;
        }
    }
    
    // initialize the starting node
    int px = sx, py = sy;
    int f = 0, g = 0, h = 0;
    openNodes[px][py] = f = g + heuristic(px, py);
    
    while(true)
    {
        // find the cell with the lowest f value
        int nf = -1, nx = -1, ny = -1;
        for(int x = 0; x < ROW; x++)
        {
            for(int y = 0; y < COL; y++)
            {
                if(openNodes[x][y] > 0)
                {
                    if(nf == -1 || openNodes[x][y] < nf)
                    {
                        nf = openNodes[x][y];
                        nx = x;
                        ny = y;
                    }
                }
            }
        }
        
        // if there is no cell with a lower f value, then there is no path
        if(nx == -1 || ny == -1)
            break;
        
        // if we've reached the end node, we've found the path
        if(nx == ex && ny == ey)
        {
            found = true;
            break;
        }
        
        // move the current node from openNodes to closedNodes
        openNodes[nx][ny] = 0;
        closedNodes[nx][ny] = 1;
        
        // generate the children of the current node
        for(int i = 0; i < 8; i++)
        {
            int cx = nx + dirX[i];
            int cy = ny + dirY[i];
            
            // check if the child node is out of bounds or already closed
            if(cx < 0 || cy < 0 || cx >= ROW || cy >= COL || closedNodes[cx][cy])
                continue;
            
            // get the g, h, and f values for the child node
            g = abs(dirX[i]) == abs(dirY[i]) ? 14 : 10; // diagonal movement costs 14, horizontal/vertical costs 10
            h = heuristic(cx, cy);
            f = g + h;
            
            // if the child has not been added to openNodes yet, add it
            if(!openNodes[cx][cy] || f < openNodes[cx][cy])
                openNodes[cx][cy] = f;
        }
    }
    
    if(found)
        printf("Path found!\n");
    else
        printf("No path found.\n");
}

int main()
{
    aStar(); 
    return 0;
}