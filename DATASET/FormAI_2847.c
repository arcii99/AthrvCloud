//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 10

char maze[MAZE_SIZE][MAZE_SIZE];

void initializeMaze() {
    int i, j;
    for (i = 0; i < MAZE_SIZE; i++) {
        for (j = 0; j < MAZE_SIZE; j++) {
            // initialize the border walls
            if (i == 0 || j == 0 || i == MAZE_SIZE - 1 || j == MAZE_SIZE - 1) {
                maze[i][j] = '#';
            } else {
                maze[i][j] = ' ';
            }
        }
    }
}

void printMaze() {
    int i, j;
    for (i = 0; i < MAZE_SIZE; i++) {
        for (j = 0; j < MAZE_SIZE; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n"); // print new line after each row
    }
}

void generateMaze(int row, int col) {
    maze[row][col] = ' '; // clear the current cell
    int directions[4] = {1, 2, 3, 4}; // up, right, down, left
    int temp, index, i;
    // shuffle the directions array randomly
    for (i = 0; i < 4; i++) {
        index = rand() % 4;
        temp = directions[i];
        directions[i] = directions[index];
        directions[index] = temp;
    }
    // try to carve out each direction
    for (i = 0; i < 4; i++) {
        switch (directions[i]) {
            case 1: // up
                if (maze[row - 2][col] == '#') { // check if there is a wall
                    maze[row - 1][col] = ' '; // clear the wall
                    generateMaze(row - 2, col); // move to the next cell
                }
                break;
            case 2: // right
                if (maze[row][col + 2] == '#') { // check if there is a wall
                    maze[row][col + 1] = ' '; // clear the wall
                    generateMaze(row, col + 2); // move to the next cell
                }
                break;
            case 3: // down
                if (maze[row + 2][col] == '#') { // check if there is a wall
                    maze[row + 1][col] = ' '; // clear the wall
                    generateMaze(row + 2, col); // move to the next cell
                }
                break;
            case 4: // left
                if (maze[row][col - 2] == '#') { // check if there is a wall
                    maze[row][col - 1] = ' '; // clear the wall
                    generateMaze(row, col - 2); // move to the next cell
                }
                break;
        }
    }
}

int main() {
    srand(time(NULL));
    initializeMaze();
    generateMaze(2, 2); // start generating from the center of the maze
    printMaze();
    return 0;
}