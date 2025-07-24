//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 //maze size
#define WALL 1
#define PATH 0
#define START_PATH 2
#define END_PATH 3

//Recursive function to generate maze
void generateMaze(int maze[SIZE][SIZE], int x, int y) {
    maze[x][y] = PATH; //mark current location as path

    //generate random directions to move
    int directions[4] = {0, 1, 2, 3};
    for(int i = 0; i < 4; i++) {
        int randIndex = rand() % 4;
        int temp = directions[i];
        directions[i] = directions[randIndex];
        directions[randIndex] = temp;
    }

    //recursively move in each direction
    for(int i = 0; i < 4; i++) {
        int direction = directions[i];
        int newX = x, newY = y;
        switch(direction) {
            case 0: //move up
                newY--;
                break;
            case 1: //move down
                newY++;
                break;
            case 2: //move left
                newX--;
                break;
            case 3: //move right
                newX++;
                break;
        }

        //check if new location is within bounds and is a wall
        if(newX >= 0 && newX < SIZE && newY >= 0 && newY < SIZE && maze[newX][newY] == WALL) {
            //mark wall as path
            maze[(newX+x)/2][(newY+y)/2] = PATH;
            //recursively move into new location
            generateMaze(maze, newX, newY);
        }
    }
}

int main() {
    srand(time(NULL)); //seed random number generator

    int maze[SIZE][SIZE] = {0}; //initialize maze with all walls

    //mark starting and ending points
    maze[0][0] = START_PATH;
    maze[SIZE-1][SIZE-1] = END_PATH;

    //generate maze
    generateMaze(maze, 0, 0);

    //print maze
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            switch(maze[i][j]) {
                case WALL:
                    printf("#");
                    break;
                case PATH:
                    printf(" ");
                    break;
                case START_PATH:
                    printf("S");
                    break;
                case END_PATH:
                    printf("E");
                    break;
            }
        }
        printf("\n");
    }

    return 0;
}