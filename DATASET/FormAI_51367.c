//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 30

char maze[ROWS][COLS + 1] = {
    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
    "X     X           X         X X",
    "X XXXXX XXXXXXXXX X XXXXX X X X",
    "X       X     X     X   X X X X",
    "X XXXXXXXXXXX X XXXXXXX X X X X",
    "X           X   X       X X   X",
    "XXXXX XXXX X XXX XXXXXXX X XXX",
    "X     X   X X   X X     X   X X",
    "X XXXXX XXX XXXXX XXX XXXXXXX X",
    "X     X     X     X   X     X X",
    "X XXXXXXXXX X XXXXXXX X XXX X X",
    "X X       X X X       X     X X",
    "X X XXXXX X X XXXXXXXXXX XXX X",
    "X X X     X     X       X   X X",
    "X X X XXXXXXXXX X XXXXXXX X X X",
    "X   X       X   X         X X X",
    "XXXXXXXXXX XX XXXXXXXXXXXXX X",
    "X           X   X             X",
    "X XXXXXXXXXXX X XXXXXXXXXXXXX",
    "X                         X X",
};

typedef struct
{
    int row;
    int col;
} point_t;

point_t start = {1, 0};
point_t end = {ROWS - 2, COLS - 1};

void print_maze(void)
{
    for (int i = 0; i < ROWS; i++)
    {
        printf("%s\n", maze[i]);
    }
}

void mark_point(point_t point, char mark)
{
    maze[point.row][point.col] = mark;
}

char get_point(point_t point)
{
    return maze[point.row][point.col];
}

int is_valid(point_t point)
{
    return point.row >= 0 && point.row < ROWS && point.col >= 0 && point.col < COLS && get_point(point) == ' ';
}

void find_path(point_t current, int *path_found)
{
    mark_point(current, '*');

    if (current.row == end.row && current.col == end.col)
    {
        *path_found = 1;
        return;
    }

    point_t next;

    next.row = current.row;
    next.col = current.col + 1;
    if (is_valid(next))
    {
        find_path(next, path_found);
    }

    if (*path_found)
    {
        return;
    }

    next.row = current.row + 1;
    next.col = current.col;
    if (is_valid(next))
    {
        find_path(next, path_found);
    }

    if (*path_found)
    {
        return;
    }

    next.row = current.row;
    next.col = current.col - 1;
    if (is_valid(next))
    {
        find_path(next, path_found);
    }

    if (*path_found)
    {
        return;
    }

    next.row = current.row - 1;
    next.col = current.col;
    if (is_valid(next))
    {
        find_path(next, path_found);
    }

    if (*path_found)
    {
        return;
    }

    mark_point(current, ' ');
}

void reset_maze(void)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (maze[i][j] == '*' || maze[i][j] == 'X')
            {
                continue;
            }

            maze[i][j] = ' ';
        }
    }
}

int main(int argc, char *argv[])
{
    int path_found = 0;
    print_maze();

    find_path(start, &path_found);

    if (path_found)
    {
        printf("Path found!\n");
        print_maze();
    }
    else
    {
        printf("No path found.\n");
    }

    reset_maze();
    return 0;
}