//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

int maze[ROWS][COLS];
int visited[ROWS][COLS];

void generate_maze(int row, int col);
void print_maze();

int main()
{
    srand(time(NULL));
    generate_maze(0, 0);
    print_maze();
    return 0;
}

void generate_maze(int row, int col)
{
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int shuffle[4] = {0, 1, 2, 3};
    int temp;
    int next_row, next_col;

    visited[row][col] = 1;
    for (int i = 0; i < 4; i++) {
        int r = rand() % 4;
        temp = shuffle[r];
        shuffle[r] = shuffle[i];
        shuffle[i] = temp;
    }
    for (int i = 0; i < 4; i++) {
        next_row = row + dir[shuffle[i]][0];
        next_col = col + dir[shuffle[i]][1];
        if (next_row < 0 || next_row >= ROWS || next_col < 0 || next_col >= COLS)
            continue;
        if (visited[next_row][next_col])
            continue;
        if (maze[next_row][next_col])
            continue;
        if (shuffle[i] == 0)
            maze[row][col] |= 1 << 0;
        if (shuffle[i] == 1)
            maze[row][col] |= 1 << 1;
        if (shuffle[i] == 2)
            maze[row][col] |= 1 << 2;
        if (shuffle[i] == 3)
            maze[row][col] |= 1 << 3;
        if (shuffle[i] == 0)
            maze[next_row][next_col] |= 1 << 2;
        if (shuffle[i] == 1)
            maze[next_row][next_col] |= 1 << 3;
        if (shuffle[i] == 2)
            maze[next_row][next_col] |= 1 << 0;
        if (shuffle[i] == 3)
            maze[next_row][next_col] |= 1 << 1;
        generate_maze(next_row, next_col);
    }
}

void print_maze()
{
    printf(" ");
    for (int i = 0; i < COLS * 2 - 1; i++)
        printf("_");
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        printf("|");
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] & 1 << 0)
                printf(" ");
            else
                printf("_");
            if (maze[i][j] & 1 << 1)
                printf("|");
            else
                printf(" ");
        }
        printf("\n");
    }
}