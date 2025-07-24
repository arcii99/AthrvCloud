//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 20
#define WIDTH 20

//1 -> Wall
//0 -> Path
int maze[HEIGHT][WIDTH];

void makeMaze(int x, int y);

int main() {
    //Seed the random number generator
    srand(time(NULL));
    
    //Initialize the maze with all walls
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            maze[i][j] = 1;
        }
    }
    
    //Generate the maze recursively starting at (0,0)
    makeMaze(0, 0);
    
    //Print out the completed maze
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            printf("%c ", maze[i][j] == 1 ? '#' : '.');
        }
        printf("\n");
    }
    
    return 0;
}

void makeMaze(int x, int y) {
    //Mark the current cell as a path
    maze[y][x] = 0;
    
    //Create an array of all possible directions to move
    int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    
    //Shuffle the array randomly
    for(int i = 0; i < 4; i++) {
        int randomIndex = rand() % 4;
        int tempX = directions[i][0];
        int tempY = directions[i][1];
        directions[i][0] = directions[randomIndex][0];
        directions[i][1] = directions[randomIndex][1];
        directions[randomIndex][0] = tempX;
        directions[randomIndex][1] = tempY;
    }
    
    //Recurse on each possible direction
    for(int i = 0; i < 4; i++) {
        int nextX = x + directions[i][0];
        int nextY = y + directions[i][1];
        if(nextX >= 0 && nextX < WIDTH && nextY >= 0 && nextY < HEIGHT && maze[nextY][nextX] == 1) {
            int wallX = x + directions[i][0] / 2;
            int wallY = y + directions[i][1] / 2;
            maze[wallY][wallX] = 0;
            makeMaze(nextX, nextY);
        }
    }
}