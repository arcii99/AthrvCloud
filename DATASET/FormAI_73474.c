//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

char maze[MAX_SIZE][MAX_SIZE];

void print_maze()
{
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int solve(int x, int y)
{
    if (maze[x][y] == 'G') {
        return 1;
    }

    if (maze[x][y] == '+' || maze[x][y] == '-') {
        return 0;
    }

    maze[x][y] = '+';

    if (x > 0 && solve(x - 1, y)) {
        maze[x][y] = '-';
        return 1;
    }
    if (y > 0 && solve(x, y - 1)) {
        maze[x][y] = '-';
        return 1;
    }
    if (x < MAX_SIZE - 1 && solve(x + 1, y)) {
        maze[x][y] = '-';
        return 1;
    }
    if (y < MAX_SIZE - 1 && solve(x, y + 1)) {
        maze[x][y] = '-';
        return 1;
    }

    maze[x][y] = '-';

    return 0;
}

int main()
{
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            maze[i][j] = '-';
        }
    }

    maze[0][0] = 'S';
    maze[4][4] = 'G';

    maze[2][0] = '+';
    maze[2][1] = '+';
    maze[2][2] = '+';
    maze[3][2] = '+';

    print_maze();

    if (solve(0, 0)) {
        printf("\nFound a path!\n\n");

        print_maze();
    } else {
        printf("\nNo path found.\n");
    }

    return 0;
}