//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: statistical
#include<stdio.h>
#include<stdlib.h>

#define ROW 10
#define COL 10

int matrix[ROW][COL] = { { 1, 1, 0, 1, 1, 1, 0, 1, 0, 1 },
                        { 0, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
                        { 0, 0, 1, 1, 1, 1, 1, 0, 1, 0 },
                        { 1, 0, 1, 0, 1, 1, 1, 1, 1, 1 },
                        { 0, 0, 0, 1, 0, 1, 0, 0, 1, 0 },
                        { 1, 0, 1, 1, 0, 1, 1, 0, 1, 1 },
                        { 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
                        { 1, 1, 1, 1, 0, 1, 0, 1, 1, 1 },
                        { 0, 0, 0, 0, 1, 1, 0, 0, 1, 0 },
                        { 1, 1, 0, 1, 1, 0, 1, 1, 1, 1 } };

int visited[ROW][COL] = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };

int goal_row = 4, goal_col = 9, start_row = 0, start_col = 0;

int is_valid(int x, int y)
{
    return (x >= 0 && x < ROW) && (y >= 0 && y < COL);
}

int is_safe(int x, int y)
{
    return matrix[x][y] && !visited[x][y];
}

void print_path(int path[ROW][COL])
{
    printf("Shortest Path is: ");
    int x = goal_row, y = goal_col;
    while (path[x][y] != -1)
    {
        int temp_x = x;
        int temp_y = y;
        printf("(%d,%d) ", x, y);
        x = path[x][y] / COL;
        y = path[temp_x][temp_y] % COL;
    }
    printf("(%d,%d)\n", x, y);
}

void BFS()
{
    int row[] = {-1, 0, 0, 1};
    int col[] = {0, -1, 1, 0};
    int path[ROW][COL];
    int queue[ROW*COL];
    int front = -1, rear = -1, queue_size = 0;
    queue[++rear] = start_row * COL + start_col;
    visited[start_row][start_col] = 1;
    path[start_row][start_col] = -1;
    while (front != rear)
    {
        int current = queue[++front];
        queue_size++;
        int x = current / COL;
        int y = current % COL;
        if (x == goal_row && y == goal_col)
        {
            print_path(path);
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int next_x = x + row[i];
            int next_y = y + col[i];
            if (is_valid(next_x, next_y) && is_safe(next_x, next_y))
            {
                queue[++rear] = next_x * COL + next_y;
                path[next_x][next_y] = current;
                visited[next_x][next_y] = 1;
            }
        }
    }
    if (queue_size == ROW * COL) printf("No path found.\n");
}

int main()
{
    BFS();
    return 0;
}