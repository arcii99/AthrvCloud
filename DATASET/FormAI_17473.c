//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: shocked
#include<stdio.h>
#define ROW 6
#define COL 10

int BFS(int maze[ROW][COL], int start[], int dest[]);

int main() 
{
    int maze[ROW][COL] = {
                            {0, 0, 1, 1, 1, 0, 0, 0, 1, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                            {1, 1, 1, 0, 0, 0, 0, 0, 1, 0}
                         };
    int start[2] = {0, 0}; 
    int dest[2] = {5, 9};
    int dist = BFS(maze, start, dest);
    printf("Shortest Path: %d\n", dist);
    return 0;
}

int BFS(int maze[ROW][COL], int start[], int dest[])
{
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1,-1, 0, 0};
    int queue[ROW*COL][2];
    int visited[ROW][COL]={0};
    queue[0][0] = start[0];
    queue[0][1] = start[1];
    visited[start[0]][start[1]] = 1;
    int front = -1, rear = 0;
    int dist = 0;
    while(front != rear)
    {
        front++;
        int x = queue[front][0];
        int y = queue[front][1];
        if(x == dest[0] && y == dest[1])
            return dist;

        for(int i=0;i<4;++i)
        {
            int row = x + dx[i];
            int col = y + dy[i];

            if(row < 0 || col < 0 || row >=ROW || col >=COL || maze[row][col] == 1 || visited[row][col])
                continue;

            visited[row][col] = 1;
            rear++;
            queue[rear][0] = row;
            queue[rear][1] = col;
        }
        dist++;
    }
    return -1;
}