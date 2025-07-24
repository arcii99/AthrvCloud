//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: expert-level
#include <stdio.h>

#define ROW 10
#define COL 10

void mazeTraversal(char arr[][COL], int x, int y)
{
    if (x < 0 || x >= ROW || y < 0 || y >= COL || arr[x][y] == '#' || arr[x][y] == '.')
    {
        return;
    }
    if (arr[x][y] == 'G')
    {
        printf("\nMaze Solved!\n");
        return;
    }
    arr[x][y] = '.';
    mazeTraversal(arr, x - 1, y);
    mazeTraversal(arr, x + 1, y);
    mazeTraversal(arr, x, y + 1);
    mazeTraversal(arr, x, y - 1);
    arr[x][y] = ' ';
}

int main()
{
    char maze[ROW][COL] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', '#', ' ', '#', ' ', '#', '#', ' ', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', '#', '#', '#', '#', ' ', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', '#', '#', '#', ' ', '#', '#', ' ', '#'},
        {'#', '#', '#', 'G', '#', '#', '#', '#', '#', '#'}
    };

    printf("\nMaze Before Traversal:\n");
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }

    int startX = 1;
    int startY = 1;

    mazeTraversal(maze, startX, startY);

    printf("\nMaze After Traversal:\n");
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}