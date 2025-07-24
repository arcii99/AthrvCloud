//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: configurable
#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int graph[MAX_ROWS][MAX_COLS];
int visited[MAX_ROWS][MAX_COLS];

int queue[MAX_ROWS * MAX_COLS]; // BFS queue
int front = 0, rear = -1;

void bfs(int start_row, int start_col, int end_row, int end_col)
{
    queue[++rear] = start_row * MAX_COLS + start_col; // add starting cell
    visited[start_row][start_col] = 1;

    int row, col, cell;

    while (front <= rear) // while queue is not empty
    {
        cell = queue[front++];
        row = cell / MAX_COLS;
        col = cell % MAX_COLS;

        if (row == end_row && col == end_col) // destination reached
        {
            printf("Path found from (%d,%d) to (%d,%d)\n", start_row, start_col, end_row, end_col);
            return;
        }

        // check right cell
        if (col + 1 < MAX_COLS && visited[row][col + 1] == 0 && graph[row][col + 1] == 1)
        {
            queue[++rear] = row * MAX_COLS + col + 1;
            visited[row][col + 1] = 1;
        }

        // check down cell
        if (row + 1 < MAX_ROWS && visited[row + 1][col] == 0 && graph[row + 1][col] == 1)
        {
            queue[++rear] = (row + 1) * MAX_COLS + col;
            visited[row + 1][col] = 1;
        }

        // check left cell
        if (col - 1 >= 0 && visited[row][col - 1] == 0 && graph[row][col - 1] == 1)
        {
            queue[++rear] = row * MAX_COLS + col - 1;
            visited[row][col - 1] = 1;
        }

        // check up cell
        if (row - 1 >= 0 && visited[row - 1][col] == 0 && graph[row - 1][col] == 1)
        {
            queue[++rear] = (row - 1) * MAX_COLS + col;
            visited[row - 1][col] = 1;
        }
    }

    printf("No path found from (%d,%d) to (%d,%d)\n", start_row, start_col, end_row, end_col);
}

int main()
{
    // initialization
    for (int i = 0; i < MAX_ROWS; i++)
    {
        for (int j = 0; j < MAX_COLS; j++)
        {
            graph[i][j] = 0;
            visited[i][j] = 0;
        }
    }

    // set some cells as nodes
    graph[1][1] = 1;
    graph[1][7] = 1;
    graph[2][4] = 1;
    graph[3][0] = 1;
    graph[3][1] = 1;
    graph[5][5] = 1;
    graph[6][3] = 1;
    graph[7][8] = 1;
    graph[8][6] = 1;
    graph[9][3] = 1;

    bfs(1, 1, 7, 8);
    bfs(5, 5, 9, 3);

    return 0;
}