//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

void generateMaze(int maze[MAZE_WIDTH][MAZE_HEIGHT], int xpos, int ypos);
void initializeMaze(int maze[MAZE_WIDTH][MAZE_HEIGHT]);

int main(void) {
    int maze[MAZE_WIDTH][MAZE_HEIGHT];
    initializeMaze(maze);
    generateMaze(maze, 0, 0);
    for(int y = 0; y < MAZE_HEIGHT; y++) {
        for(int x = 0; x < MAZE_WIDTH; x++) {
            printf("%c ", maze[x][y] ? '#' : '.');
        }
        printf("\n");
    }
    return 0;
}

void initializeMaze(int maze[MAZE_WIDTH][MAZE_HEIGHT]) {
    srand(time(NULL));
    for(int y = 0; y < MAZE_HEIGHT; y++) {
        for(int x = 0; x < MAZE_WIDTH; x++) {
            if(x == 0 || y == 0 || x == MAZE_WIDTH - 1 || y == MAZE_HEIGHT - 1) {
                maze[x][y] = 1;
            } else {
                maze[x][y] = rand() % 2;
            }
        }
    }
}

void generateMaze(int maze[MAZE_WIDTH][MAZE_HEIGHT], int xpos, int ypos) {
    maze[xpos][ypos] = 1;
    int directions[4] = {0, 1, 2, 3};
    for(int i = 0; i < 4; i++) {
        int temp = directions[i];
        int randomIndex = rand() % 4;
        directions[i] = directions[randomIndex];
        directions[randomIndex] = temp;
    }
    for(int i = 0; i < 4; i++) {
        switch(directions[i]) {
            case 0:
                if(xpos - 2 <= 0) {
                    continue;
                }
                if(maze[xpos - 2][ypos] == 0) {
                    maze[xpos - 1][ypos] = 1;
                    generateMaze(maze, xpos - 2, ypos);
                }
                break;
            case 1:
                if(ypos - 2 <= 0) {
                    continue;
                }
                if(maze[xpos][ypos - 2] == 0) {
                    maze[xpos][ypos - 1] = 1;
                    generateMaze(maze, xpos, ypos - 2);
                }
                break;
            case 2:
                if(xpos + 2 >= MAZE_WIDTH - 1) {
                    continue;
                }
                if(maze[xpos + 2][ypos] == 0) {
                    maze[xpos + 1][ypos] = 1;
                    generateMaze(maze, xpos + 2, ypos);
                }
                break;
            case 3:
                if(ypos + 2 >= MAZE_HEIGHT - 1) {
                    continue;
                }
                if(maze[xpos][ypos + 2] == 0) {
                    maze[xpos][ypos + 1] = 1;
                    generateMaze(maze, xpos, ypos + 2);
                }
                break;
        }
    }
}