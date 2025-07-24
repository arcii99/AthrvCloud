//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: distributed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ROW 10
#define COL 10

struct node
{
    int x, y; // x-coordinate and y-coordinate of the node 
    int f, g, h; // f, g and h costs of the node
    struct node* parent; // parent node for the path
};

// Node for storing each individual process information
struct process
{
    int pid;
    int socket;
    int arrived;
    int completed;
    struct node* start;
    struct node* goal;
};

struct node* createNode(int x, int y)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->x = x;
    newNode->y = y;

    newNode->f = newNode->g = newNode->h = 0;
    newNode->parent = NULL;

    return newNode;
}

void printPath(struct node* node)
{
    if (node == NULL)
        return;

    printPath(node->parent);
    printf("(%d,%d) ", node->x, node->y);
}

// function to return the heuristic value for each node
int heuristic(struct node* node, struct node* goal)
{
    return abs(node->x - goal->x) + abs(node->y - goal->y);
}

int isvalid(int row, int col)
{
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

int isUnBlocked(int grid[][COL], int row, int col)
{
    if (grid[row][col] == 0)
        return 1;
    else
        return 0;
}

int isEqual(struct node* a, struct node* b)
{
    if (a->x == b->x && a->y == b->y)
        return 1;
    else
        return 0;
}

void aStarSearch(int grid[][COL], struct node* start, struct node* goal)
{
    if (isUnBlocked(grid, start->x, start->y) == 0 || isUnBlocked(grid, goal->x, goal->y) == 0)
    {
        printf("Blocked or Invalid Cells!\n");
        return;
    }

    if (isEqual(start, goal) == 1)
    {
        printf("Goal Reached!\n");
        return;
    }

    int closedList[ROW][COL];
    memset(closedList, 0, sizeof(closedList));

    struct node* a[ROW * COL];
    int numProcesses = 0;

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            a[numProcesses] = createNode(i,j);
            numProcesses++;
        }
    }

    int row[] = { 1, 0, -1, 0, -1, -1, 1, 1 };
    int col[] = { 0, 1, 0, -1, -1, 1, -1, 1 };

    // start node initialization
    int ix = start->x;
    int iy = start->y;

    int index = -1;
    int minFVal = ROW * COL;

    for (int i = 0; i < numProcesses; i++)
    {
        if (a[i]->x == start->x && a[i]->y == start->y)
        {
            index = i;
            break;
        }
    }

    a[index]->f = 0;
    a[index]->g = 0;
    a[index]->h = 0;
    a[index]->parent = NULL;

    // open list
    int openList[numProcesses];
    memset(openList, 0, sizeof(openList));

    int openCount = 0;
    openList[openCount] = index;
    openCount++;

    while (openCount > 0)
    {
        int currentNode = -1;
        int currentFVal = ROW * COL;

        for (int i = 0; i < openCount; i++)
        {
            if (a[openList[i]]->f < currentFVal)
            {
                currentFVal = a[openList[i]]->f;
                currentNode = openList[i];
            }
        }

        // terminate when the goal node is reached
        if (isEqual(a[currentNode], goal) == 1)
        {
            closedList[a[currentNode]->x][a[currentNode]->y] = 1;
            printf("Path Found!\n");
            printf("Path:");
            printPath(a[currentNode]);
            printf("\n");
            return;
        }

        openList[currentNode] = -1;

        for (int i = 0; i < 8; i++)
        {
            int newRow = a[currentNode]->x + row[i];
            int newCol = a[currentNode]->y + col[i];

            if (isvalid(newRow, newCol) == 1)
            {
                if (isEqual(a[currentNode], createNode(newRow, newCol)) == 1)
                    continue;

                if (isUnBlocked(grid, newRow, newCol) == 0)
                    continue;

                int newNodeIndex = -1;

                for (int j = 0; j < numProcesses; j++)
                {
                    if (a[j]->x == newRow && a[j]->y == newCol)
                        newNodeIndex = j;
                }

                if (newNodeIndex == -1)
                {
                    printf("Error finding the index of the child node!\n");
                    return;
                }

                if (closedList[newRow][newCol] == 0)
                {
                    int gNew = a[currentNode]->g + 1;
                    int hNew = heuristic(a[newNodeIndex], goal);
                    int fNew = gNew + hNew;

                    if (a[newNodeIndex]->f == ROW * COL || a[newNodeIndex]->f > fNew)
                    {
                        a[newNodeIndex]->f = fNew;
                        a[newNodeIndex]->g = gNew;
                        a[newNodeIndex]->h = hNew;
                        a[newNodeIndex]->parent = a[currentNode];

                        if (openList[newNodeIndex] == -1)
                        {
                            openList[newNodeIndex] = 1;
                            openCount++;
                        }
                    }
                }
            }
        }
        closedList[a[currentNode]->x][a[currentNode]->y] = 1;

    }

    if (openCount == 0)
    {
        printf("Path Not Found!\n");
        return;
    }

    return;
}

int main()
{

    int grid[ROW][COL] =
    {
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
        { 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }
    };

    struct node* start = createNode(0, 0);
    struct node* goal = createNode(9, 9);

    aStarSearch(grid, start, goal);

    return 0;
}