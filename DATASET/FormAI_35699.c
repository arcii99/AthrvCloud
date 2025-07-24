//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ROW 10
#define COL 10
#define INF INT_MAX

int grid[ROW][COL] =
{
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 1, 0, 1, 0},
    {0, 1, 1, 0, 1, 1, 1, 0, 1, 0},
    {0, 1, 1, 0, 1, 1, 1, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
    {0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
    {0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
    {0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int closed[ROW][COL];
int dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};

typedef struct Node
{
    int row, col;
    int f, g, h;
    struct Node *parent;
} Node;

Node *newNode(int row, int col)
{
    Node *node = (Node*) malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->f = node->g = node->h = 0;
    node->parent = NULL;
    return node;
}

void printPath(Node *node)
{
    if(node == NULL)
    {
        return;
    }
    printPath(node->parent);
    printf("(%d, %d) -> ", node->row, node->col);
}

int heuristic(int row, int col, int goalRow, int goalCol)
{
    return abs(row - goalRow) + abs(col - goalCol);
}

void cleanup()
{
    int i, j;
    for(i = 0; i < ROW; i++)
    {
        for(j = 0; j < COL; j++)
        {
            closed[i][j] = 0;
        }
    }
}

int isInsideGrid(int row, int col)
{
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

void Astar(int startRow, int startCol, int goalRow, int goalCol)
{
    if(!isInsideGrid(startRow, startCol))
    {
        printf("Invalid start position\n");
        return;
    }
    if(!isInsideGrid(goalRow, goalCol))
    {
        printf("Invalid goal position\n");
        return;
    }
    if(grid[startRow][startCol] == 0)
    {
        printf("Start position is blocked\n");
        return;
    }
    if(grid[goalRow][goalCol] == 0)
    {
        printf("Goal position is blocked\n");
        return;
    }
    if(startRow == goalRow && startCol == goalCol)
    {
        printf("You are already there\n");
        return;
    }

    cleanup();

    Node *startNode = newNode(startRow, startCol);
    startNode->f = startNode->g = startNode->h = 0;
    startNode->parent = NULL;

    Node *goalNode = newNode(goalRow, goalCol);
    goalNode->f = goalNode->g = goalNode->h = 0;
    goalNode->parent = NULL;

    Node *openList[ROW * COL];
    int openListCount = 0;

    openList[openListCount++] = startNode;

    int i, j;
    while(openListCount > 0)
    {
        Node *currentNode = openList[0];
        int currentIndex = 0;

        for(i = 1; i < openListCount; i++)
        {
            if(openList[i]->f < currentNode->f)
            {
                currentNode = openList[i];
                currentIndex = i;
            }
        }

        openListCount--;
        openList[currentIndex] = openList[openListCount];

        closed[currentNode->row][currentNode->col] = 1;

        if(currentNode->row == goalNode->row && currentNode->col == goalNode->col)
        {
            printPath(currentNode);
            printf("\n");
            return;
        }

        for(i = 0; i < 8; i++)
        {
            int newRow = currentNode->row + dx[i];
            int newCol = currentNode->col + dy[i];

            if(isInsideGrid(newRow, newCol))
            {
                if(closed[newRow][newCol] == 0 && grid[newRow][newCol] != 0)
                {
                    Node *successorNode = newNode(newRow, newCol);
                    successorNode->parent = currentNode;
                    successorNode->g = currentNode->g + 1;
                    successorNode->h = heuristic(newRow, newCol, goalRow, goalCol);
                    successorNode->f = successorNode->g + successorNode->h;

                    int isInOpenList = 0;
                    for(j = 0; j < openListCount; j++)
                    {
                        if(openList[j]->row == successorNode->row && openList[j]->col == successorNode->col)
                        {
                            isInOpenList = 1;
                            break;
                        }
                    }

                    if(isInOpenList == 0)
                    {
                        openList[openListCount++] = successorNode;
                    }
                }
            }
        }
    }

    printf("No path found!\n");

    return;
}

int main()
{
    Astar(0, 0, 9, 9);

    return 0;
}