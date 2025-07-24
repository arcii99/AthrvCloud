//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ROW 5
#define COL 5

int main()
{
    char maze[ROW][COL] = {
        {'#', '#', '#', '#', '#'},
        {'#', '.', '.', '.', '#'},
        {'#', '.', '#', '.', '#'},
        {'#', '.', '.', '.', '#'},
        {'#', '#', '#', '#', '#'}
    };

    bool visited[ROW][COL];
    memset(visited, false, sizeof(visited));

    int queueX[ROW*COL];
    int queueY[ROW*COL];
    int front = 0, rear = 0;

    int startX = 1, startY = 1;
    int endX = 3, endY = 3;

    visited[startX][startY] = true;
    queueX[rear] = startX;
    queueY[rear] = startY;
    rear++;

    int x, y;
    while (front != rear)
    {
        x = queueX[front];
        y = queueY[front];
        front++;

        if (x == endX && y == endY)
        {
            // Found the end
            printf("Path Found!\n");
            return 0;
        }

        // Move up
        if (maze[x-1][y] != '#' && visited[x-1][y] == false)
        {
            visited[x-1][y] = true;
            queueX[rear] = x-1;
            queueY[rear] = y;
            rear++;
        }

        // Move down
        if (maze[x+1][y] != '#' && visited[x+1][y] == false)
        {
            visited[x+1][y] = true;
            queueX[rear] = x+1;
            queueY[rear] = y;
            rear++;
        }

        // Move left
        if (maze[x][y-1] != '#' && visited[x][y-1] == false)
        {
            visited[x][y-1] = true;
            queueX[rear] = x;
            queueY[rear] = y-1;
            rear++;
        }

        // Move right
        if (maze[x][y+1] != '#' && visited[x][y+1] == false)
        {
            visited[x][y+1] = true;
            queueX[rear] = x;
            queueY[rear] = y+1;
            rear++;
        }
    }

    printf("No Path Found!\n");

    return 0;
}