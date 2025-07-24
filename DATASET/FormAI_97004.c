//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 20
#define COL 30

void populate_grid(char grid[ROW][COL]) {
    srand(time(0));
    for(int i=0;i<ROW;i++) {
        for(int j=0;j<COL;j++) {
            if(i%2==0 && j%2==0) {
                grid[i][j] = '+';
            } else {
                int r = rand()%10 + 1;
                if(r<=6) {
                    grid[i][j] = ' ';
                } else {
                    grid[i][j] = '#';
                }
            }
        }
    }
}

void print_grid(char grid[ROW][COL]) {
    for(int i=0;i<ROW;i++) {
        for(int j=0;j<COL;j++) {
            printf("%c",grid[i][j]);
        }
        printf("\n");
    }
}

void dfs(int i, int j, char grid[ROW][COL]) {
    grid[i][j] = '*';
    int neighbors[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    srand(time(0));
    for(int k=0;k<4;k++) {
        int r = rand()%4;
        int x = i + neighbors[r][0]*2;
        int y = j + neighbors[r][1]*2;

        if(x>=0&&x<ROW&&y>=0&&y<COL&&grid[x][y]==' ') {
            grid[x][y] = '*';
            dfs(x,y,grid);
        }
    }
}

void generate_maze(char grid[ROW][COL]) {
    dfs(1,1,grid);
}

int main() {
    char grid[ROW][COL];
    populate_grid(grid);
    printf("Before maze generation:\n");
    print_grid(grid);
    generate_maze(grid);
    printf("\nAfter maze generation:\n");
    print_grid(grid);
    return 0;
}