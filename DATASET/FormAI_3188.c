//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

//Structure to hold a point in 2D space
struct Point
{
    int x, y;
};

//Stack implementation to store a series of points
struct Stack
{
    struct Point path[ROW*COL];
    int size;
};

//Function to add a point to the stack
void push(struct Stack* stack, struct Point p)
{
    stack->path[stack->size] = p;
    stack->size++;
}

//Function to remove a point from the stack
struct Point pop(struct Stack* stack)
{
    stack->size--;
    return stack->path[stack->size];
}

//Function to determine if a point is within bounds of the board
bool isValid(int x, int y)
{
    return x >= 0 && x < ROW && y >= 0 && y < COL;
}

//Function to determine if a point is an obstacle
bool isObstacle(int board[][COL], int x, int y)
{
    return board[x][y] == 1;
}

//Function to calculate the heuristic cost of a point
int heuristic(struct Point a, struct Point b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

//Function to implement A* algorithm
bool AStar(int board[][COL], struct Point start, struct Point end)
{
    int g[ROW][COL];
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            g[i][j] = 99999;
        }
    }

    g[start.x][start.y] = 0;

    int f[ROW][COL];
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            f[i][j] = 99999;
        }
    }

    f[start.x][start.y] = heuristic(start, end);

    bool closedList[ROW][COL] = {false};

    struct Stack openList = {0};

    push(&openList, start);

    while (openList.size != 0)
    {
        struct Point p = pop(&openList);

        if (p.x == end.x && p.y == end.y)
        {
            return true;
        }

        closedList[p.x][p.y] = true;

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int x = p.x + dx[i];
            int y = p.y + dy[i];

            int newG = g[p.x][p.y] + 1;

            if (isValid(x, y) && !isObstacle(board, x, y))
            {
                if (closedList[x][y] == false || newG < g[x][y])
                {
                    struct Point newP = {x, y};
                    push(&openList, newP);

                    g[x][y] = newG;
                    f[x][y] = newG + heuristic(newP, end);
                }
            }
        }
    }

    return false;
}

//Driver code
int main()
{
    int board[ROW][COL] =
    {
        {0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0},
    };

    struct Point start = {0, 0};
    struct Point end = {4, 4};

    if (AStar(board, start, end))
    {
        printf("A path exists between start and end point.");
    }
    else
    {
        printf("No path exists between start and end point.");
    }

    return 0;
}