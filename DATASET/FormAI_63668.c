//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: unmistakable
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>

#define ROW 10
#define COL 10

// Node structure
struct node 
{
    int x, y, f, g, h;
};

// A* search algorithm function
void aStarSearch(int grid[ROW][COL], struct node start, struct node end) 
{
    if (start.x < 0 || start.x >= ROW || start.y < 0 || start.y >= COL) 
    {
        printf("Invalid start node\n");
        return;
    }

    if (end.x < 0 || end.x >= ROW || end.y < 0 || end.y >= COL) 
    {
        printf("Invalid end node\n");
        return;
    }

    bool closedList[ROW][COL];

    for (int i = 0; i < ROW; i++) 
    {
        for (int j = 0; j < COL; j++) 
        {
            closedList[i][j] = false;
        }
    }

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    struct node openList[ROW * COL];
    int count = 0;

    start.f = 0;
    start.g = 0;
    start.h = 0;
    openList[count++] = start;

    while (count > 0) 
    {
        int minF = INT_MAX;
        int current;
        for (int i = 0; i < count; i++) 
        {
            if (openList[i].f < minF) 
            {
                minF = openList[i].f;
                current = i;
            }
        }

        struct node currentNode = openList[current];

        if (currentNode.x == end.x && currentNode.y == end.y) 
        {
            printf("\nPath Found\n");
            return;
        }

        for (int i = 0; i < 4; i++) 
        {
            int newX = currentNode.x + dx[i];
            int newY = currentNode.y + dy[i];

            if (newX < 0 || newX >= ROW || newY < 0 || newY >= COL || closedList[newX][newY] || grid[newX][newY] == 1) 
            {
                continue;
            }

            int tentativeG = currentNode.g + 1;

            bool newNode = true;
            for (int j = 0; j < count; j++) 
            {
                if (openList[j].x == newX && openList[j].y == newY) 
                {
                    newNode = false;
                    if (tentativeG < openList[j].g) 
                    {
                        openList[j].g = tentativeG;
                        openList[j].f = openList[j].g + openList[j].h;
                    }
                    break;
                }
            }

            if (newNode) 
            {
                struct node neighborNode;

                neighborNode.x = newX;
                neighborNode.y = newY;
                neighborNode.g = tentativeG;
                neighborNode.h = abs(end.x - newX) + abs(end.y - newY);
                neighborNode.f = neighborNode.g + neighborNode.h;

                openList[count++] = neighborNode;
            }
        }

        closedList[currentNode.x][currentNode.y] = true;

        for (int i = current; i < count - 1; i++) 
        {
            openList[i] = openList[i + 1];
        }

        count--;
    }

    printf("\nPath not found\n");

}

int main() 
{
    int grid[ROW][COL] = {
            {0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
            {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    struct node start = {0, 0, 0, 0, 0};
    struct node end = {9, 9, 0, 0, 0};

    aStarSearch(grid, start, end);

    return 0;
}