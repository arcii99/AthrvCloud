//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 15
#define COL 30

void generateMaze(char maze[ROW][COL]) {
    int i, j, k, start, end;
    char stage[ROW][COL]; // copy of the maze
    srand(time(NULL)); // set the seed for random number generation
    
    // set all cells as walls
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            maze[i][j] = '#';
            stage[i][j] = '#';
        }
    }
    
    // mark all odd numbered cells as passages
    for (i = 1; i < ROW; i += 2) {
        for (j = 1; j < COL; j += 2) {
            maze[i][j] = ' ';
            stage[i][j] = ' ';
        }
    }
    
    // set the start and end points randomly
    start = rand() % ROW;
    end = rand() % ROW;
    maze[start][0] = 'S';
    stage[start][0] = 'S';
    maze[end][COL-1] = 'E';
    stage[end][COL-1] = 'E';
    
    // randomly create passages
    for (k = 0; k < ROW * COL; k++) {
        i = (rand() % (ROW-2)) + 1;
        j = (rand() % (COL-2)) + 1;
        
        if ((i % 2 == 1 && maze[i][j-1] == '#' && maze[i][j+1] == ' ') ||
            (i % 2 == 1 && maze[i][j+1] == '#' && maze[i][j-1] == ' ')) {
            maze[i][j] = ' ';
            stage[i][j] = ' ';
        }
        else if ((j % 2 == 1 && maze[i-1][j] == '#' && maze[i+1][j] == ' ') ||
                 (j % 2 == 1 && maze[i+1][j] == '#' && maze[i-1][j] == ' ')) {
            maze[i][j] = ' ';
            stage[i][j] = ' ';
        }
        else {
            maze[i][j] = '#';
            stage[i][j] = '#';
        }
    }
    
    // print the maze
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char maze[ROW][COL];
    generateMaze(maze);
    return 0;
}