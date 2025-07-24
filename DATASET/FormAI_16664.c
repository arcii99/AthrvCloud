//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS]; //The maze

void generateMaze(int, int); //Function to generate the maze
void printMaze(); //Function to print the maze

int main() {
    srand(time(NULL)); //Seed the random number generator

    generateMaze(0, 0); //Start generating the maze from the top left corner

    printMaze();

    return 0;
}

void generateMaze(int row, int col) {
    maze[row][col] = 1; //Mark the current cell as visited

    //Generate a random order in which to check the neighboring cells
    int neighbors[4] = {0, 1, 2, 3};
    for (int i = 3; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = neighbors[i];
        neighbors[i] = neighbors[j];
        neighbors[j] = temp;
    }

    //Check each neighboring cell
    for (int i = 0; i < 4; i++) {
        int nextRow, nextCol;
        switch (neighbors[i]) {
            case 0: //Check cell to the left
                nextRow = row;
                nextCol = col - 1;
                break;
            case 1: //Check cell above
                nextRow = row - 1;
                nextCol = col;
                break;
            case 2: //Check cell to the right
                nextRow = row;
                nextCol = col + 1;
                break;
            case 3: //Check cell below
                nextRow = row + 1;
                nextCol = col;
                break;
        }

        //If the neighboring cell is within the maze boundaries and hasn't been visited yet
        if (nextRow >= 0 && nextRow < ROWS && nextCol >= 0 && nextCol < COLS && maze[nextRow][nextCol] == 0) {
            //Clear the wall between the current cell and the neighboring cell
            if (neighbors[i] == 0) { //Left
                maze[row][col] &= ~1;
                maze[nextRow][nextCol] &= ~4;
            } else if (neighbors[i] == 1) { //Up
                maze[row][col] &= ~2;
                maze[nextRow][nextCol] &= ~8;
            } else if (neighbors[i] == 2) { //Right
                maze[row][col] &= ~4;
                maze[nextRow][nextCol] &= ~1;
            } else if (neighbors[i] == 3) { //Down
                maze[row][col] &= ~8;
                maze[nextRow][nextCol] &= ~2;
            }

            generateMaze(nextRow, nextCol); //Recursively generate the neighboring cell
        }
    }
}

void printMaze() {
    printf(" ");
    for (int i = 0; i < COLS; i++) {
        printf("__");
    }
    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        printf("|");
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] & 2) { //Top wall
                printf(" ");
            } else {
                printf("_");
            }

            if (maze[i][j] & 4) { //Right wall
                printf("|");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}