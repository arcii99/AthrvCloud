//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: excited
#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("Welcome to the C Pathfinding Algorithms Example Program!");
    printf("Let's code a maze solver using A* algorithm and visualize it.");

    int startX, startY, endX, endY;
    char maze[10][10] = {
        {'#','#','#','#','#','#','#','#','#','#'},
        {'#','S','#',' ',' ',' ','#',' ',' ','#'},
        {'#',' ',' ',' ','#',' ','#',' ','#','#'},
        {'#',' ','#',' ','#',' ','#',' ','#','#'},
        {'#',' ','#',' ','#',' ','#',' ',' ','#'},
        {'#',' ','#',' ','#',' ',' ',' ','#','#'},
        {'#',' ','#',' ','#',' ','#',' ','#','#'},
        {'#',' ','#',' ','#',' ','#',' ','#','#'},
        {'#',' ',' ',' ',' ',' ','#',' ','F','#'},
        {'#','#','#','#','#','#','#','#','#','#'}
    };

    startX = 1;
    startY = 1;
    endX = 8;
    endY = 8;

    int openNodes[100][2], closedNodes[100][2];
    int g[10][10], h[10][10], f[10][10], parentX[10][10], parentY[10][10];

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            g[i][j] = 0;
            h[i][j] = abs(endX-i)+abs(endY-j);
            f[i][j] = g[i][j]+h[i][j];

            parentX[i][j] = -1;
            parentY[i][j] = -1;
        }
    }

    int openCount = 1;
    int closedCount = 0;

    openNodes[0][0] = startX;
    openNodes[0][1] = startY;

    int currentX = startX;
    int currentY = startY;

    while(1)
    {
        if(currentX == endX && currentY == endY) // goal reached!
            break;

        // get the node with the lowest f value from openNodes
        int minF = 100000;
        int minIndex = -1;
        for(int i=0;i<openCount;i++)
        {
            if(f[openNodes[i][0]][openNodes[i][1]]<minF)
            {
                minF = f[openNodes[i][0]][openNodes[i][1]];
                minIndex = i;
            }
        }

        // remove the node with the lowest f value from openNodes and add it to closedNodes
        closedNodes[closedCount][0] = openNodes[minIndex][0];
        closedNodes[closedCount][1] = openNodes[minIndex][1];
        closedCount++;

        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                if(i==0 && j==0) // current node
                    continue;

                int neighborX = currentX+i;
                int neighborY = currentY+j;

                // not valid coordinates
                if(neighborX<0 || neighborX>=10 || neighborY<0 || neighborY>=10)
                    continue;

                // obstacle
                if(maze[neighborX][neighborY]=='#')
                    continue;

                // already in closed nodes
                int flag = 0;
                for(int k=0;k<closedCount;k++)
                {
                    if(closedNodes[k][0]==neighborX && closedNodes[k][1]==neighborY)
                        flag = 1;
                }
                if(flag==1)
                    continue;

                // update the g value for the neighbor
                int tentG = g[currentX][currentY]+1;

                flag = 0;
                for(int k=0;k<openCount;k++)
                {
                    if(openNodes[k][0]==neighborX && openNodes[k][1]==neighborY)
                    {
                        flag = 1;
                        if(g[neighborX][neighborY]>tentG)
                        {
                            g[neighborX][neighborY] = tentG;
                            f[neighborX][neighborY] = g[neighborX][neighborY]+h[neighborX][neighborY];
                            parentX[neighborX][neighborY] = currentX;
                            parentY[neighborX][neighborY] = currentY;

                        }
                    }
                }

                if(flag==0)
                {
                    openNodes[openCount][0] = neighborX;
                    openNodes[openCount][1] = neighborY;
                    openCount++;

                    g[neighborX][neighborY] = tentG;
                    f[neighborX][neighborY] = g[neighborX][neighborY]+h[neighborX][neighborY];
                    parentX[neighborX][neighborY] = currentX;
                    parentY[neighborX][neighborY] = currentY;
                }
            }
        }

        if(openCount==0) // no solution found
            break;

        currentX = openNodes[minIndex][0];
        currentY = openNodes[minIndex][1];

        // remove the current node from openNodes
        for(int i=minIndex;i<openCount-1;i++)
        {
            openNodes[i][0] = openNodes[i+1][0];
            openNodes[i][1] = openNodes[i+1][1];
        }
        openCount--;
    }

    if(currentX==endX && currentY==endY) // goal reached!
    {
        printf("\nThe maze is solved!\n");

        // print the solved maze
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(maze[i][j]=='#')
                    printf("%c",maze[i][j]);
                else if(i==startX && j==startY)
                    printf("S");
                else if(i==endX && j==endY)
                    printf("F");
                else
                {
                    int flag = 0;
                    for(int k=0;k<closedCount;k++)
                    {
                        if(closedNodes[k][0]==i && closedNodes[k][1]==j)
                        {
                            printf("*");
                            flag = 1;
                        }
                    }

                    if(flag==0)
                        printf(" ");
                }
            }
            printf("\n");
        }

        // backtrace from end node to start node using parent arrays
        currentX = endX;
        currentY = endY;

        int pathX[100], pathY[100];
        int pathLength = 0;

        while(1)
        {
            pathX[pathLength] = currentX;
            pathY[pathLength] = currentY;
            pathLength++;

            if(currentX == startX && currentY == startY)
                break;

            int temp = currentX;
            currentX = parentX[currentX][currentY];
            currentY = parentY[temp][currentY];
        }

        // print the path
        printf("\nThe path from S to F is:\n");
        for(int i=pathLength-1;i>=0;i--)
        {
            printf("(%d,%d)",pathX[i],pathY[i]);
            if(i!=0)
                printf(" -> ");
        }
    }
    else // no solution found
        printf("\nOops! No solution found.");

    return 0;
}