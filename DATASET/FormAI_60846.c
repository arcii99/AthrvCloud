//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define MAZE_SIZE 10

int maze[MAZE_SIZE][MAZE_SIZE];
int visited[MAZE_SIZE][MAZE_SIZE];
int cur_x, cur_y, dest_x, dest_y;

void print_maze() {
    printf("\n");
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            if (i == cur_x && j == cur_y)
                printf("C");
            else if (i == dest_x && j == dest_y)
                printf("D");
            else if (maze[i][j])
                printf("#");
            else
                printf(".");
        }
        printf("\n");
    }
}

void fold_maze(int x1, int y1, int x2, int y2) {
    int temp = maze[x1][y1];
    maze[x1][y1] = maze[x2][y2];
    maze[x2][y2] = temp;
}

void check_folds() {
    int l_x = cur_x - 1, r_x = cur_x + 1, u_y = cur_y - 1, d_y = cur_y + 1;

    if (l_x >= 0 && l_x < MAZE_SIZE && maze[l_x][cur_y] && !visited[l_x][cur_y]) {
        visited[l_x][cur_y] = 1;
        cur_x = l_x;
        fold_maze(cur_x, cur_y, l_x, cur_y);
        print_maze();
        check_folds();
        fold_maze(l_x, cur_y, cur_x, cur_y);
        cur_x = l_x;
    }

    if (r_x >= 0 && r_x < MAZE_SIZE && maze[r_x][cur_y] && !visited[r_x][cur_y]) {
        visited[r_x][cur_y] = 1;
        cur_x = r_x;
        fold_maze(cur_x, cur_y, r_x, cur_y);
        print_maze();
        check_folds();
        fold_maze(r_x, cur_y, cur_x, cur_y);
        cur_x = r_x;
    }

    if (u_y >= 0 && u_y < MAZE_SIZE && maze[cur_x][u_y] && !visited[cur_x][u_y]) {
        visited[cur_x][u_y] = 1;
        cur_y = u_y;
        fold_maze(cur_x, cur_y, cur_x, u_y);
        print_maze();
        check_folds();
        fold_maze(cur_x, u_y, cur_x, cur_y);
        cur_y = u_y;
    }

    if (d_y >= 0 && d_y < MAZE_SIZE && maze[cur_x][d_y] && !visited[cur_x][d_y]) {
        visited[cur_x][d_y] = 1;
        cur_y = d_y;
        fold_maze(cur_x, cur_y, cur_x, d_y);
        print_maze();
        check_folds();
        fold_maze(cur_x, d_y, cur_x, cur_y);
        cur_y = d_y;
    }
}

int main() {
    // initialize maze
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            if (i == 0 || j == 0 || i == MAZE_SIZE - 1 || j == MAZE_SIZE - 1)
                maze[i][j] = 1;
            else
                maze[i][j] = 0;
        }
    }

    // set start and end points
    cur_x = 1;
    cur_y = 1;
    visited[cur_x][cur_y] = 1;

    dest_x = MAZE_SIZE - 2;
    dest_y = MAZE_SIZE - 2;

    print_maze();
    check_folds();
}