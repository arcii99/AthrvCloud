//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: innovative
#include <stdio.h>
#include <string.h>
#define ROW 10
#define COL 10

int maze_arr[ROW][COL] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,0,1,0,1,0,1,1,0,1},
    {1,0,1,0,1,0,0,0,0,1},
    {1,0,1,0,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,0,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,1,0,1,1,1,1,1,0,1},
    {1,1,1,1,1,1,1,1,1,1},
};

int path[ROW][COL];

void print_path(int m, int n) {
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            printf("%d ", path[i][j]);
        }
        printf("\n");
    }
}

int solve_maze(int x, int y, int m, int n) {
    if(x==m-1 && y==n-1) {
        path[x][y] = 1;
        return 1;
    }
    if(x>=0 && y>=0 && x<m && y<n && path[x][y]==0 && maze_arr[x][y]==1) {
        path[x][y] = 1;

        if(solve_maze(x+1, y, m, n)) { // move down
            return 1;
        }

        if(solve_maze(x, y+1, m, n)) { // move right
            return 1;
        }

        if(solve_maze(x-1, y, m, n)) { // move up
            return 1;
        }

        if(solve_maze(x, y-1, m, n)) { // move left
            return 1;
        }

        path[x][y] = 0;
        return 0;
    }
    return 0;
}

int main() {
    memset(path, 0, sizeof(path));
    if(solve_maze(0,0,ROW,COL)) {
        printf("The path to solve the maze is:\n");
        print_path(ROW,COL);
    } else {
        printf("The maze cannot be solved!\n");
    }
    return 0;
}