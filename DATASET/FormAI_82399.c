//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

char grid[ROW][COL] = {
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
    {'*', '.', '.', '.', '*', '.', '.', '.', '.', '*'},
    {'*', '.', '*', '.', '*', '.', '*', '*', '.', '*'},
    {'*', '.', '.', '.', '.', '.', '.', '.', '.', '*'},
    {'*', '*', '*', '*', '*', '.', '*', '*', '*', '*'},
    {'*', '.', '.', '.', '.', '.', '.', '.', '.', '*'},
    {'*', '.', '*', '*', '*', '*', '*', '*', '.', '*'},
    {'*', '.', '.', '.', '.', '.', '.', '.', '.', '*'},
    {'*', '.', '*', '*', '*', '.', '*', '*', '.', '*'},
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}
};

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int f;
    int g;
    int h;
    bool visited;
    Point parent;
} Node;

Node nodes[ROW][COL];

Point start = {1, 1};
Point end = {8, 8};

void findPath()
{
    bool found = false;
    Point current = start;

    while (!found)
    {
        // Find the lowest f cost node in the open list
        int minCost = 1000000;
        Point next = current;
        for (int i = current.x - 1; i <= current.x + 1; i++)
        {
            for (int j = current.y - 1; j <= current.y + 1; j++)
            {
                if (i >= 0 && i < ROW && j >= 0 && j < COL)
                {
                    if (nodes[i][j].g != 0)
                    {
                        int cost = nodes[i][j].g + nodes[i][j].h;
                        if (cost < minCost && !nodes[i][j].visited)
                        {
                            minCost = cost;
                            next = (Point){i, j};
                        }
                    }
                }
            }
        }

        current = next;
        nodes[current.x][current.y].visited = true;

        // If we've reached the end, break out of the loop
        if (current.x == end.x && current.y == end.y)
        {
            found = true;
            break;
        }

        // Update neighbors
        for (int i = current.x - 1; i <= current.x + 1; i++)
        {
            for (int j = current.y - 1; j <= current.y + 1; j++)
            {
                if (i >= 0 && i < ROW && j >= 0 && j < COL)
                {
                    if (j == current.y || i == current.x)
                    {
                        int cost = (i == current.x) ? 10 : 14;
                        int newG = nodes[current.x][current.y].g + cost;
                        if (newG < nodes[i][j].g && !nodes[i][j].visited && grid[i][j] != '*')
                        {
                            nodes[i][j].g = newG;
                            nodes[i][j].h = abs(i - end.x) + abs(j - end.y);
                            nodes[i][j].f = nodes[i][j].g + nodes[i][j].h;
                            nodes[i][j].parent = current;
                        }
                    }
                }
            }
        }
    }

    // Print the path
    Point currentPoint = end;
    while (currentPoint.x != start.x || currentPoint.y != start.y)
    {
        printf("(%d, %d) -> ", currentPoint.x, currentPoint.y);
        currentPoint = nodes[currentPoint.x][currentPoint.y].parent;
    }
    printf("(%d, %d)\n", start.x, start.y);
}

int main()
{
    // Initialize nodes and calculate h values
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            nodes[i][j].f = 0;
            nodes[i][j].g = 1000000; // Set g to a large number to start
            nodes[i][j].h = abs(i - end.x) + abs(j - end.y);
            nodes[i][j].visited = false;
            nodes[i][j].parent = (Point){-1, -1};
        }
    }

    nodes[start.x][start.y].g = 0;

    findPath();

    return 0;
}