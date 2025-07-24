//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

void print_maze(char maze[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            putchar(maze[i][j]);
            putchar(' ');
        }
        putchar('\n');
    }
}

void generate_maze(char maze[ROWS][COLS]) {
    //Initialize the maze matrix with walls and open borders
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(i==0 || i==ROWS-1 || j==0 || j==COLS-1) {
                maze[i][j] = '*';
            } else {
                maze[i][j] = ' ';
            }
        }
    }

    //Choose a random starting point
    int x = rand() % (ROWS-2) + 1;
    int y = rand() % (COLS-2) + 1;

    //Mark the starting point as visited
    maze[x][y] = '@';

    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    //Perform a random walk algorithm
    int num_visited = 1;
    while(num_visited < ROWS * COLS) {
        int nx = x + dx[rand() % 4];
        int ny = y + dy[rand() % 4];
        if(maze[nx][ny] == ' ') {
            maze[nx][ny] = '@';
            num_visited++;
        }
        x = nx;
        y = ny;
    }

    //Print the final maze
    print_maze(maze);
}

int main(void) {
    char maze[ROWS][COLS];
    srand(time(NULL));
    generate_maze(maze);
    return 0;
}