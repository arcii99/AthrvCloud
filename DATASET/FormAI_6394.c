//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 7
#define COL 10

int cost[ROW][COL]; // stores the cost of each cell
bool closedList[ROW][COL]; // stores if a cell is in the closed list
int start[2] = {2,0}; // start node
int goal[2] = {5,9}; // goal node

// struct for each node
typedef struct Node
{
    int row;
    int col;
    int fcost;
    int gcost;
    int hcost;
    struct Node* parent;
} Node;

Node* createNode(int row, int col, int f, int g, int h, Node* parent)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->fcost = f;
    node->gcost = g;
    node->hcost = h;
    node->parent = parent;
    return node;
}

// calculates the euclidean distance heuristic between two points
int euclidean(int row1, int col1, int row2, int col2)
{
    int dx = abs(row1 - row2);
    int dy = abs(col1 - col2);
    return (int)(sqrt(dx*dx + dy*dy) * 10);
}

// checks if a node is valid (within the bounds and not an obstacle)
bool isValid(int row, int col)
{
    if (row < 0 || row >= ROW || col < 0 || col >= COL)
        return false;
    if (cost[row][col] == -1 || closedList[row][col])
        return false;
    return true;
}

// gets the valid neighbors of a node
void getNeighbors(Node* curr, Node* neighbors[])
{
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0)
                continue;
            int row = curr->row + i;
            int col = curr->col + j;
            if (isValid(row, col))
            {
                int g = curr->gcost + cost[row][col];
                int h = euclidean(row, col, goal[0], goal[1]);
                int f = g + h;
                neighbors[i + 1 + (j + 1)*3] = createNode(row, col, f, g, h, curr);
            }
            else
            {
                neighbors[i + 1 + (j + 1)*3] = NULL;
            }
        }
    }
}

// prints the path from start to goal
void printPath(Node* curr)
{
    if (curr == NULL)
        return;
    printPath(curr->parent);
    printf("[%d,%d] ", curr->row, curr->col);
}

// finds the path from start to goal using A*
void findPath()
{
    Node* startNode = createNode(start[0], start[1], 0, 0, 0, NULL);
    startNode->fcost = euclidean(start[0], start[1], goal[0], goal[1]);
    Node* openList[ROW*COL];
    int openCount = 0;
    openList[0] = startNode;
    openCount++;
    Node* curr = NULL;
    while (openCount > 0)
    {
        // find node with lowest fcost in openList
        int minF = openList[0]->fcost;
        int idx = 0;
        for (int i = 1; i < openCount; i++)
        {
            if (openList[i]->fcost < minF)
            {
                idx = i;
                minF = openList[i]->fcost;
            }
        }
        curr = openList[idx];

        // if goal is found, print path and return
        if (curr->row == goal[0] && curr->col == goal[1])
        {
            printPath(curr);
            return;
        }

        // remove curr from openList and add to closedList
        for (int i = idx; i < openCount - 1; i++)
        {
            openList[i] = openList[i+1];
        }
        openCount--;
        closedList[curr->row][curr->col] = true;

        // get valid neighbors of curr
        Node* neighbors[9];
        getNeighbors(curr, neighbors);

        // add neighbors to openList
        for (int i = 0; i < 9; i++)
        {
            if (neighbors[i] != NULL)
            {
                int row = neighbors[i]->row;
                int col = neighbors[i]->col;
                if (closedList[row][col])
                    continue;
                bool inOpenList = false;
                int j;
                for (j = 0; j < openCount; j++)
                {
                    if (openList[j]->row == row && openList[j]->col == col)
                    {
                        inOpenList = true;
                        break;
                    }
                }
                if (!inOpenList)
                {
                    openList[openCount] = neighbors[i];
                    openCount++;
                }
                else
                {
                    int g = curr->gcost + cost[row][col];
                    if (g < openList[j]->gcost)
                    {
                        openList[j]->gcost = g;
                        openList[j]->fcost = g + openList[j]->hcost;
                        openList[j]->parent = curr;
                    }
                }
            }
        }
    }
}

int main()
{
    // initialize the cost matrix
    int obstacles[ROW*COL] = {12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
                              12, -1, -1, 12, 12, -1, -1, 12, -1, 12,
                              12, -1, -1, -1, -1, -1, -1, 12, -1, 12,
                              12, -1, 12, 12, -1, -1, -1, -1, -1, 12,
                              12, -1, -1, 12, -1, 12, -1, 12, 12, 12,
                              12, 12, -1, -1, -1, -1, -1, -1, -1, 12,
                              12, 12, 12, 12, 12, 12, 12, 12, 12, 12};
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            cost[i][j] = obstacles[i*COL + j];
            closedList[i][j] = false;
        }
    }

    // find the path from start to goal
    findPath();
    return 0;
}