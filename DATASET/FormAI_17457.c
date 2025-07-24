//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 15
#define COL 15

char maze[ROW][COL] = {' '};

void print_maze() {
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

void generate_maze() {
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            if(i==0 || i==ROW-1 || j==0 || j==COL-1) {
                maze[i][j] = '#';
            }
            else {
                maze[i][j] = '.';
            }
        }
    }

    srand(time(NULL));
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            if(maze[i][j] == '.') {
                int r = rand()%10;
                if(r < 3) {
                    maze[i][j] = '#';
                }
            }
        }
    }

    maze[1][1] = '.';
    maze[ROW-2][COL-2] = '.';
}

int solve(int row, int col) {
    if(maze[row][col] == '#') {
        return 0;
    }

    if(row == ROW-2 && col == COL-2) {
        maze[row][col] = '*';
        return 1;
    }

    maze[row][col] = '*';

    if(solve(row+1, col) == 1) {
        return 1;
    }

    if(solve(row, col+1) == 1) {
        return 1;
    }

    if(solve(row-1, col) == 1) {
        return 1;
    }

    if(solve(row, col-1) == 1) {
        return 1;
    }

    maze[row][col] = '.';
    return 0;
}

int main() {
    generate_maze();
    printf("Maze before solving:\n");
    print_maze();

    if(solve(1,1) == 1) {
        printf("\nMaze after solving:\n");
        print_maze();
    }
    else {
        printf("\nNo solution found!\n");
    }

    return 0;
}