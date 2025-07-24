//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 20

//function prototypes
void generateMaze(int maze[][COLS]);
void printMaze(int maze[][COLS]);
void recursiveMaze(int row, int col, int maze[][COLS]);

int main() {
    srand(time(NULL)); //seed random generator

    int maze[ROWS][COLS];

    generateMaze(maze);
    printMaze(maze);

    return 0;
}

//Function to generate the maze
void generateMaze(int maze[][COLS]) {
    //Step 1: initialise the maze with all walls
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            maze[row][col] = 1;
        }
    }

    //Step 2: choose a random start position on the top row
    int startCol = rand() % COLS;
    maze[0][startCol] = 0;

    //Step 3: recursively create the maze
    recursiveMaze(0, startCol, maze);
}

//Recursive function to create the maze
void recursiveMaze(int row, int col, int maze[][COLS]) {
    //create an array of directions
    int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    //randomly shuffle the directions
    for (int i = 0; i < 4; i++) {
        int r = rand() % 4;
        int c = rand() % 4;

        int temp1 = directions[i][0];
        int temp2 = directions[i][1];

        directions[i][0] = directions[r][0];
        directions[i][1] = directions[r][1];

        directions[r][0] = temp1;
        directions[r][1] = temp2;
    }

    //try all directions
    for (int i = 0; i < 4; i++) {
        int newRow = row + directions[i][0] * 2;
        int newCol = col + directions[i][1] * 2;

        //check if the new position is within the maze and not visited
        if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS && maze[newRow][newCol] == 1) {
            //break the walls
            maze[row + directions[i][0]][col + directions[i][1]] = 0;
            maze[newRow][newCol] = 0;

            //recursively call the function
            recursiveMaze(newRow, newCol, maze);
        }
    }
}

//Function to print the maze
void printMaze(int maze[][COLS]) {
    printf("\nMAZE:\n");

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (maze[row][col] == 1) { //print wall
                printf(" #");
            } else { //print path
                printf("  ");
            }
        }
        printf("\n");
    }
}