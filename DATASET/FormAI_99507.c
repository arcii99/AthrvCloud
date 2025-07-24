//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROW 10
#define COL 10

typedef struct
{
    int row;
    int col;
}Node;

typedef struct
{
    Node parent;
    double gCost;
    double fCost;
    int visited;
    int obstacle;
}Cell;

Cell grid[ROW][COL];

int goalRow, goalCol;
int startRow, startCol;

Node getNextCell(int row, int col)
{
    Node nextCell = {row, col};
    return nextCell;
}

void updateCell(int row, int col, Node parent, double gCost, double fCost, int visited, int obstacle)
{
    grid[row][col].parent = parent;
    grid[row][col].gCost = gCost;
    grid[row][col].fCost = fCost;
    grid[row][col].visited = visited;
    grid[row][col].obstacle = obstacle;
}

double calcDist(Node nodeA, Node nodeB)
{
    double dist = sqrt(pow(nodeA.row - nodeB.row, 2) + pow(nodeA.col - nodeB.col, 2));
    return dist;
}

double heuristic(Node nodeA, Node nodeB)
{
    double h = calcDist(nodeA, nodeB);
    return h;
}

void aStar()
{
    Node curr = getNextCell(startRow, startCol);
    grid[curr.row][curr.col].visited = 1;

    double gCost = 0;
    double hCost = heuristic(curr, getNextCell(goalRow, goalCol));
    double fCost = gCost + hCost;

    updateCell(curr.row, curr.col, curr, gCost, fCost, 1, grid[curr.row][curr.col].obstacle);

    int found = 0;

    while (!found)
    {
        double minCost = INFINITY;
        Node next;

        for (int row = 0; row < ROW; row++)
        {
            for (int col = 0; col < COL; col++)
            {
                if (grid[row][col].visited == 0 && grid[row][col].obstacle == 0)
                {
                    if (grid[row][col].fCost < minCost)
                    {
                        minCost = grid[row][col].fCost;
                        next = getNextCell(row, col);
                    }
                }
            }
        }

        curr = next;
        grid[curr.row][curr.col].visited = 1;

        if (curr.row == goalRow && curr.col == goalCol)
        {
            found = 1;
        }
        else
        {
            for (int dx = -1; dx <= 1; dx++)
            {
                for (int dy = -1; dy <= 1; dy++)
                {
                    double addCost = 1.0;

                    if (dx != 0 && dy != 0)
                    {
                        addCost = 1.4;
                    }

                    int newRow = curr.row + dx;
                    int newCol = curr.col + dy;

                    if (newRow >= 0 && newRow < ROW && newCol >= 0 && newCol < COL)
                    {
                        if (grid[newRow][newCol].visited == 0 && grid[newRow][newCol].obstacle == 0)
                        {
                            double gCost = grid[curr.row][curr.col].gCost + addCost;
                            double hCost = heuristic(getNextCell(newRow, newCol), getNextCell(goalRow, goalCol));
                            double fCost = gCost + hCost;

                            if (grid[newRow][newCol].fCost > fCost)
                            {
                                updateCell(newRow, newCol, curr, gCost, fCost, 1, grid[newRow][newCol].obstacle);
                            }
                        }
                    }
                }
            }
        }
    }
}

void printPath()
{
    Node curr = getNextCell(goalRow, goalCol);

    while (curr.row != startRow || curr.col != startCol)
    {
        printf("(%d,%d) -> ", curr.row, curr.col);
        curr = grid[curr.row][curr.col].parent;
    }

    printf("(%d,%d)\n", curr.row, curr.col);
}

int main()
{
    //initialize grid
    for (int row = 0; row < ROW; row++)
    {
        for (int col = 0; col < COL; col++)
        {
            updateCell(row, col, getNextCell(-1, -1), INFINITY, INFINITY, 0, 0);
        }
    }

    //set start and end points
    startRow = 1;
    startCol = 1;
    goalRow = 8;
    goalCol = 8;

    //set obstacles
    grid[3][5].obstacle = 1;
    grid[4][5].obstacle = 1;
    grid[5][5].obstacle = 1;
    grid[6][5].obstacle = 1;

    aStar();
    printPath();

    return 0;
}