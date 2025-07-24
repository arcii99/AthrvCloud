//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 20
#define WALL_PROB 0.3

char maze[ROWS][COLS];

void printMaze() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));  // seed random number generator
    
    // initialize maze with walls
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(rand() / (float)RAND_MAX < WALL_PROB) {
                maze[i][j] = '#';
            } else {
                maze[i][j] = '.';
            }
        }
    }
    
    // add entrance and exit
    maze[0][0] = '.';
    maze[ROWS-1][COLS-1] = '.';
    
    // print original maze
    printMaze();
    
    // find path through maze
    int x = 0;
    int y = 0;
    while(!(x == COLS-1 && y == ROWS-1)) {
        if(x < COLS-1 && maze[y][x+1] == '.') {
            maze[y][x] = '-';
            x++;
        } else if(y < ROWS-1 && maze[y+1][x] == '.') {
            maze[y][x] = '|';
            y++;
        } else if(x > 0 && maze[y][x-1] == '.') {
            maze[y][x] = '-';
            x--;
        } else if(y > 0 && maze[y-1][x] == '.') {
            maze[y][x] = '|';
            y--;
        } else {
            printf("\nMaze is unsolvable!\n");
            return 1;
        }
    }
    maze[y][x] = '-';  // mark exit
    
    // print solved maze
    printf("\n");
    printMaze();
    
    return 0;
}