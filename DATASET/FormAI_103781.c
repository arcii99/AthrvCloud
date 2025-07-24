//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int start_x = 2, start_y = 2;
int end_x = 7, end_y = 8;

int visited[ROWS][COLS] = {0};
int path[ROWS][COLS] = {0};

typedef struct {
    int x;
    int y;
}Coord;

Coord queue[ROWS * COLS];
int head = 0, tail = 0;

void print_maze(int maze[][COLS])
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

void print_visited(int visited[][COLS])
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%d ", visited[i][j]);
        }
        printf("\n");
    }
}

void print_path(int path[][COLS])
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%d ", path[i][j]);
        }
        printf("\n");
    }
}

void enqueue(Coord coord)
{
    queue[tail++] = coord;
}

Coord dequeue()
{
    return queue[head++];
}

int is_empty()
{
    return (head == tail);
}

int is_valid(int x, int y)
{
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS)
    {
        return 0;
    }
    if (maze[x][y] == 0 && visited[x][y] == 0)
    {
        return 1;
    }
    return 0;
}

void mark_path(Coord coord)
{
    path[coord.x][coord.y] = 1;
}

void bfs()
{
    Coord current, next;

    current.x = start_x;
    current.y = start_y;
    visited[current.x][current.y] = 1;
    enqueue(current);

    while (!is_empty())
    {
        current = dequeue();

        if (current.x == end_x && current.y == end_y)
        {
            mark_path(current);
            break;
        }

        next.x = current.x - 1;
        next.y = current.y;
        if (is_valid(next.x, next.y))
        {
            visited[next.x][next.y] = 1;
            mark_path(current);
            enqueue(next);
        }

        next.x = current.x;
        next.y = current.y - 1;
        if (is_valid(next.x, next.y))
        {
            visited[next.x][next.y] = 1;
            mark_path(current);
            enqueue(next);
        }

        next.x = current.x + 1;
        next.y = current.y;
        if (is_valid(next.x, next.y))
        {
            visited[next.x][next.y] = 1;
            mark_path(current);
            enqueue(next);
        }

        next.x = current.x;
        next.y = current.y + 1;
        if (is_valid(next.x, next.y))
        {
            visited[next.x][next.y] = 1;
            mark_path(current);
            enqueue(next);
        }
    }
}

int main()
{
    bfs();
    printf("Maze:\n");
    print_maze(maze);
    printf("Visited:\n");
    print_visited(visited);
    printf("Path:\n");
    print_path(path);

    return 0;
}