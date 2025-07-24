//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: puzzling
#include <stdio.h>

// Function to check if a position is valid
int isValidPosition(int x, int y, int N, int M, char maze[N][M], int visited[N][M])
{
    if (x < 0 || y < 0 || x >= N || y >= M || maze[x][y] == '#' || visited[x][y])
        return 0;
    return 1;
}

// Function to find the minimum path from start to destination using DFS
void findPath(int x, int y, int N, int M, char maze[N][M], int visited[N][M], int dest_x, int dest_y, int *min_dist, int dist)
{
    // Check if we have reached the destination
    if (x == dest_x && y == dest_y) 
    {
        if (*min_dist > dist)
            *min_dist = dist;
        return;
    }

    // Mark the current cell as visited
    visited[x][y] = 1;

    // Traverse all possible directions
    if (isValidPosition(x + 1, y, N, M, maze, visited))
        findPath(x + 1, y, N, M, maze, visited, dest_x, dest_y, min_dist, dist + 1);

    if (isValidPosition(x, y + 1, N, M, maze, visited))
        findPath(x, y + 1, N, M, maze, visited, dest_x, dest_y, min_dist, dist + 1);

    if (isValidPosition(x - 1, y, N, M, maze, visited))
        findPath(x - 1, y, N, M, maze, visited, dest_x, dest_y, min_dist, dist + 1);

    if (isValidPosition(x, y - 1, N, M, maze, visited))
        findPath(x, y - 1, N, M, maze, visited, dest_x, dest_y, min_dist, dist + 1);

    // Unmark the current cell as visited
    visited[x][y] = 0;
}

int main()
{
    // The maze, # represents walls and . represents open paths
    char maze[6][6] = {
        {'#', '.', '#', '#', '.', '#'},
        {'.', '.', '#', '.', '.', '#'},
        {'#', '.', '.', '.', '.', '#'},
        {'#', '#', '#', '.', '.', '#'},
        {'#', '.', '.', '.', '.', '.'},
        {'#', '#', '#', '#', '#', '#'}
    };

    int N = 6, M = 6;
    int start_x = 0, start_y = 1;
    int dest_x = 5, dest_y = 4;
    int visited[N][M];
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            visited[i][j] = 0;
        }
    }

    // Find the minimum path using DFS
    int min_dist = N * M;
    findPath(start_x, start_y, N, M, maze, visited, dest_x, dest_y, &min_dist, 0);

    // Print the minimum path
    if (min_dist == N * M)
        printf("No path found!");
    else
        printf("The minimum path length is: %d", min_dist);

    return 0;
}