//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: thoughtful
#include <stdio.h>
#define ROW 8
#define COL 8
#define INF 1000000

int shortestDistance(int grid[ROW][COL], int startX, int startY, int endX, int endY);

int main()
{
    int grid[ROW][COL] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0}
    };

    int startX = 1;
    int startY = 1;
    int endX = 6;
    int endY = 6;

    int shortestPath = shortestDistance(grid, startX, startY, endX, endY);

    printf("The shortest path distance is: %d", shortestPath);

    return 0;
}

int shortestDistance(int grid[ROW][COL], int startX, int startY, int endX, int endY)
{
    int dist[ROW][COL];
    int visited[ROW][COL];

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            visited[i][j] = 0;
            dist[i][j] = INF;
        }
    }

    dist[startX][startY] = 0;

    for (int k = 0; k < ROW * COL; k++)
    {
        int minDist = INF;
        int x;
        int y;

        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                if (visited[i][j] == 0 && dist[i][j] < minDist)
                {
                    minDist = dist[i][j];
                    x = i;
                    y = j;
                }
            }
        }

        visited[x][y] = 1;

        if (x == endX && y == endY)
        {
            return dist[x][y];
        }

        if (x > 0 && visited[x - 1][y] == 0 && grid[x - 1][y] == 0 && dist[x][y] + 1 < dist[x - 1][y])
        {
            dist[x - 1][y] = dist[x][y] + 1;
        }

        if (y > 0 && visited[x][y - 1] == 0 && grid[x][y - 1] == 0 && dist[x][y] + 1 < dist[x][y - 1])
        {
            dist[x][y - 1] = dist[x][y] + 1;
        }

        if (x < ROW - 1 && visited[x + 1][y] == 0 && grid[x + 1][y] == 0 && dist[x][y] + 1 < dist[x + 1][y])
        {
            dist[x + 1][y] = dist[x][y] + 1;
        }

        if (y < COL - 1 && visited[x][y + 1] == 0 && grid[x][y + 1] == 0 && dist[x][y] + 1 < dist[x][y + 1])
        {
            dist[x][y + 1] = dist[x][y] + 1;
        }
    }

    return INF;
}