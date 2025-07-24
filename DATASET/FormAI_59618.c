//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

int grid[ROWS][COLS];
int visited[ROWS][COLS];

typedef struct
{
    int row;
    int col;
} Node;

Node queue[ROWS * COLS];
int front = 0, rear = -1, queueSize = 0;

void enqueue(int row, int col)
{
    queue[++rear] = (Node) {row, col};
    queueSize++;
}

Node dequeue()
{
    Node nextNode = queue[front++];
    queueSize--;
    return nextNode;
}

int isValidCell(int row, int col)
{
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS)
    {
        return 0;
    }
    if (visited[row][col] == 1 || grid[row][col] == 1)
    {
        return 0;
    }
    return 1;
}

void visitCell(int row, int col)
{
    visited[row][col] = 1;
    printf("Visited cell (%d, %d)\n", row, col);
}

void bfs(int startRow, int startCol, int endRow, int endCol)
{
    visitCell(startRow, startCol);
    enqueue(startRow, startCol);

    int rows[] = {-1, 0, 1, 0};
    int cols[] = {0, 1, 0, -1};

    while (queueSize > 0)
    {
        Node curNode = dequeue();
        int curRow = curNode.row;
        int curCol = curNode.col;
        if (curRow == endRow && curCol == endCol)
        {
            printf("Found path from (%d,%d) to (%d,%d)\n", startRow, startCol, endRow, endCol);
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int newRow = curRow + rows[i];
            int newCol = curCol + cols[i];
            if (isValidCell(newRow, newCol))
            {
                visitCell(newRow, newCol);
                enqueue(newRow, newCol);
            }
        }
    }
    printf("Could not find path from (%d,%d) to (%d,%d)\n", startRow, startCol, endRow, endCol);
}

int main()
{
    // initialize grid with walls
    grid[0][3] = 1;
    grid[1][3] = 1;
    grid[2][3] = 1;
    grid[3][3] = 1;
    grid[4][3] = 1;
    grid[4][2] = 1;
    grid[4][1] = 1;
    grid[4][0] = 1;

    bfs(0, 0, 9, 9);

    return 0;
}