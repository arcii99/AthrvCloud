//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: active
#include<stdio.h>
#include<stdlib.h>
#define ROW 5
#define COL 5

int openList[ROW*COL], closedList[ROW*COL], path[ROW*COL];
int map[ROW][COL] = {{1, 1, 1, 1, 1},
                     {0, 1, 0, 1, 0},
                     {0, 1, 0, 1, 0},
                     {0, 1, 0, 1, 0},
                     {0, 1, 0, 0, 0}};

typedef struct {
    int i;
    int j;
} node;

int isSameNode(node n1, node n2)
{
    if(n1.i == n2.i && n1.j == n2.j)
    return 1;
    else
    return 0;
}

int isDiagonal(node cS, node nS)
{
    if(cS.i-nS.i==1 && cS.j-nS.j==1)
    return 1;
    else if(cS.i-nS.i==1 && nS.j-cS.j==1)
    return 1;
    else if(nS.i-cS.i==1 && cS.j-nS.j==1)
    return 1;
    else if(nS.i-cS.i==1 && nS.j-cS.j==1)
    return 1;
    else
    return 0;
}

int calculateCost(int currI, int currJ, int nextI, int nextJ)
{
    if(currI == nextI || currJ == nextJ)
    return 10; //Horizontal or vertical move
    else
    return 14; //Diagonal move
}

int isInOpenList(int i, int j)
{
    for(int k=0; k<ROW*COL && openList[k]!=-1; k=k+2)
    {
        if(openList[k]==i && openList[k+1]==j)
        return k;
    }
    return -1;
}

int isInClosedList(int i, int j)
{
    for(int k=0; k<ROW*COL && closedList[k]!=-1; k=k+2)
    {
        if(closedList[k]==i && closedList[k+1]==j)
        return k;
    }
    return -1;
}

int getBestNode()
{
    int bestNode = openList[0];
    int bestNodeFValue = openList[2];
    for(int i=2; i<ROW*COL && openList[i]!=-1; i=i+4)
    {
        if(openList[i] < bestNodeFValue)
        {
            bestNode = openList[i-2];
            bestNodeFValue = openList[i];
        }
    }
    return bestNode;
}

void printMap()
{
    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
        {
            if(map[i][j]==1)
            printf("  ");
            else
            printf("X ");
        }
        printf("\n");
    }
    printf("\n");
}

void printPath()
{
    printf("Path from start to end:\n");
    for(int i=0; i<ROW*COL && path[i]!=-1; i=i+2)
    {
        printf("(%d,%d)", path[i], path[i+1]);
        if(i+2 != ROW*COL && path[i+2]!=-1)
        printf(" -> ");
    }
    printf("\n");
}

void AStarPathfinding(node start, node end)
{
    int openListSize = 0, closedListSize = 0;
    int **G = (int **)malloc(ROW * sizeof(int *));
    int **H = (int **)malloc(ROW * sizeof(int *));
    int **F = (int **)malloc(ROW * sizeof(int *));
    for(int i=0; i<ROW; i++)
    {
        G[i] = (int *)malloc(COL * sizeof(int));
        H[i] = (int *)malloc(COL * sizeof(int));
        F[i] = (int *)malloc(COL * sizeof(int));
        for(int j=0; j<COL; j++)
        {
            G[i][j] = -1; //Set all G values to -1 initially
            H[i][j] = abs(end.i-i)+abs(end.j-j); //Calculate Manhattan distance and set as H value
            F[i][j] = -1; //Set all F values to -1 initially
        }
    }
    openList[openListSize++] = start.i;
    openList[openListSize++] = start.j;
    openList[openListSize++] = H[start.i][start.j];
    openList[openListSize++] = H[start.i][start.j];
    G[start.i][start.j] = 0;
    F[start.i][start.j] = H[start.i][start.j];
    while(openListSize > 0)
    {
        int currNode = getBestNode();
        node currentNode = {openList[currNode], openList[currNode+1]};
        if(isSameNode(currentNode, end))
        {
            int i = currNode/2;
            path[i*2] = end.i;
            path[i*2+1] = end.j;
            while(i > 0)
            {
                i--;
                path[i*2] = closedList[i*2];
                path[i*2+1] = closedList[i*2+1];
            }
            return;
        }
        int currIndex = isInOpenList(currentNode.i, currentNode.j);
        closedList[closedListSize++] = currentNode.i;
        closedList[closedListSize++] = currentNode.j;
        openList[currIndex] = -1;
        G[currentNode.i][currentNode.j] = -1;
        F[currentNode.i][currentNode.j] = -1;
        openListSize -= 4;
        for(int i=-1; i<=1; i++)
        {
            for(int j=-1; j<=1; j++)
            {
                if(i==0 && j==0)
                continue;
                if(currentNode.i+i < 0 || currentNode.i+i >= ROW || currentNode.j+j < 0 || currentNode.j+j >= COL)
                continue;
                if(map[currentNode.i+i][currentNode.j+j] == 1)
                continue;
                node neighborNode = {currentNode.i+i, currentNode.j+j};
                int inClosedList = isInClosedList(neighborNode.i, neighborNode.j);
                if(inClosedList != -1)
                {
                    continue;
                }
                int neighborCost = calculateCost(currentNode.i, currentNode.j, neighborNode.i, neighborNode.j);
                int neighborGValue = G[currentNode.i][currentNode.j] + neighborCost;
                int inOpenList = isInOpenList(neighborNode.i, neighborNode.j);
                if(inOpenList == -1)
                {
                    openList[openListSize++] = neighborNode.i;
                    openList[openListSize++] = neighborNode.j;
                    G[neighborNode.i][neighborNode.j] = neighborGValue;
                    F[neighborNode.i][neighborNode.j] = neighborGValue + H[neighborNode.i][neighborNode.j];
                }
                else
                {
                    if(neighborGValue < G[neighborNode.i][neighborNode.j])
                    {
                        G[neighborNode.i][neighborNode.j] = neighborGValue;
                        F[neighborNode.i][neighborNode.j] = neighborGValue + H[neighborNode.i][neighborNode.j];
                    }
                }
            }
        }
        for(int i=0; i<openListSize; i=i+4)
        {
            int FValue = openList[i+2];
            if(FValue == -1)
            continue;
            node openListNode = {openList[i], openList[i+1]};
            int inClosedList = isInClosedList(openListNode.i, openListNode.j);
            if(inClosedList != -1)
            {
                openList[i+2] = closedList[inClosedList+1] + H[openListNode.i][openListNode.j];
                openList[i+3] = closedList[inClosedList+1];
            }
            else
            {
                int GValue = G[openListNode.i][openListNode.j];
                openList[i+2] = GValue + H[openListNode.i][openListNode.j];
                openList[i+3] = GValue;
            }
        }
    }
}

int main()
{
    node start = {0, 0};
    node end = {4, 3};
    for(int i=0; i<ROW*COL; i++)
    {
        openList[i] = -1;
        closedList[i] = -1;
        path[i] = -1;
    }
    printMap();
    AStarPathfinding(start, end);
    printPath();
    return 0;
}