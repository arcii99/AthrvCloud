//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 21
#define COLS 41

typedef struct {
    int x, y;
} Point;

typedef enum { 
    WALL, PATH 
} Cell;

void generateMaze(Cell maze[ROWS][COLS], Point start, Point end) {
    srand(time(NULL));
    
    // Initialize maze with walls
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            maze[i][j] = WALL;
        }
    }
    
    // Generate maze starting from start point
    Point curr = start;
    Point prev = curr;
    maze[curr.y][curr.x] = PATH;
    
    while(curr.x != end.x || curr.y != end.y) {
        // Generate random direction
        int dir = rand() % 4;
        
        switch(dir) {
            case 0: // Up
                if(curr.y > 0 && maze[curr.y-1][curr.x] == WALL) {
                    curr.y--;
                    maze[curr.y][curr.x] = PATH;
                    maze[(curr.y+prev.y)/2][(curr.x+prev.x)/2] = PATH;
                    prev = curr;
                }
                break;
            case 1: // Right
                if(curr.x < COLS-1 && maze[curr.y][curr.x+1] == WALL) {
                    curr.x++;
                    maze[curr.y][curr.x] = PATH;
                    maze[(curr.y+prev.y)/2][(curr.x+prev.x)/2] = PATH;
                    prev = curr;
                }
                break;
            case 2: // Down
                if(curr.y < ROWS-1 && maze[curr.y+1][curr.x] == WALL) {
                    curr.y++;
                    maze[curr.y][curr.x] = PATH;
                    maze[(curr.y+prev.y)/2][(curr.x+prev.x)/2] = PATH;
                    prev = curr;
                }
                break;
            case 3: // Left
                if(curr.x > 0 && maze[curr.y][curr.x-1] == WALL) {
                    curr.x--;
                    maze[curr.y][curr.x] = PATH;
                    maze[(curr.y+prev.y)/2][(curr.x+prev.x)/2] = PATH;
                    prev = curr;
                }
                break;
        }
    }
}

int main() {
    Cell maze[ROWS][COLS];
    Point start = {0, 0};
    Point end = {COLS-1, ROWS-1};
    
    generateMaze(maze, start, end);
    
    // Print maze
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j] == WALL ? '#' : ' ');
        }
        printf("\n");
    }
    
    return 0;
}