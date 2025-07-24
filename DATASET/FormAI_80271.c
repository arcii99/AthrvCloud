//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: light-weight
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SIZE 20

void generateMaze(int maze[][SIZE], int x, int y);
void printMaze(int maze[][SIZE]);

int main(void) {
    int maze[SIZE][SIZE] = {0};
    srand(time(NULL));
    generateMaze(maze, SIZE/2, SIZE/2);
    printMaze(maze);
    return 0;
}

void generateMaze(int maze[][SIZE], int x, int y) {
    maze[x][y] = 1;
    int directions[4] = {1, 2, 3, 4};
    int temp, randIndex;
    // Shuffle directions
    for(int i = 0; i < 4; i++) {
        randIndex = rand() % 4;
        temp = directions[i];
        directions[i] = directions[randIndex];
        directions[randIndex] = temp;
    }
    // Move in each direction
    for(int i = 0; i < 4; i++) {
        switch(directions[i]) {
            case 1: // Move up
                if(x > 1 && maze[x-2][y] == 0) {
                    maze[x-1][y] = 1;
                    generateMaze(maze, x-2, y);
                }
                break;
            case 2: // Move right
                if(y < SIZE-2 && maze[x][y+2] == 0) {
                    maze[x][y+1] = 1;
                    generateMaze(maze, x, y+2);
                }
                break;
            case 3: // Move down
                if(x < SIZE-2 && maze[x+2][y] == 0) {
                    maze[x+1][y] = 1;
                    generateMaze(maze, x+2, y);
                }
                break;
            case 4: // Move left
                if(y > 1 && maze[x][y-2] == 0) {
                    maze[x][y-1] = 1;
                    generateMaze(maze, x, y-2);
                }
                break;
        }
    }
}

void printMaze(int maze[][SIZE]) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(maze[i][j] == 1) printf("  ");
            else printf("##");
        }
        printf("\n");
    }
}