//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25 //Number of rows in the maze
#define COLS 50 //Number of columns in the maze

typedef struct cell{
    int x; //X coordinate of the cell
    int y; //Y coordinate of the cell
    int visited; //Whether the cell has been visited or not
    int walls[4]; //Whether the cell has walls or not (left, right, top, bottom)
}cell;

void printMaze(cell maze[ROWS][COLS]){
    printf(" ");
    for(int i = 0; i < COLS; i++){
        printf("_"); //Prints the top border of the maze
    }
    printf("\n");
    for(int i = 0; i < ROWS; i++){
        printf("|"); //Prints left border of the maze
        for(int j = 0; j < COLS; j++){
            if(maze[i][j].walls[1]){ //Checks if the cell has a right wall
                printf("_"); //Prints bottom wall of the cell
            }
            else{
                printf(" "); //Prints space if there is no right wall
            }
            if(maze[i][j].walls[3]){ //Checks if the cell has a bottom wall
                printf("|"); //Prints right wall of the cell
            }
            else{
                printf(" "); //Prints a space if there is no bottom wall
            }
        }
        printf("\n");
    }
}

void generateMaze(cell maze[ROWS][COLS], int x, int y){

    maze[x][y].visited = 1; //Marks the current cell as visited
    int directions[4] = {0, 1, 2, 3}; //Array containing the possible directions to move
    for(int i = 0; i < 4; i++){
        int randIndex = rand() % 4; //Random index to choose a direction from the direction array
        int temp = directions[i]; //Temporary variable to store the current direction
        directions[i] = directions[randIndex]; //Swaps the current direction with a random direction from the direction array
        directions[randIndex] = temp;
    }
    for(int i = 0; i < 4; i++){
        int direction = directions[i]; //Assigns the current direction to a variable
        if(direction == 0){ //Checks if the direction is left
            if(y > 0 && !maze[x][y-1].visited){ //Checks if it is not on left edge of the maze and the cell on left has not been visited
                maze[x][y].walls[0] = 0; //Removes the left wall of the current cell
                maze[x][y-1].walls[1] = 0; //Removes the right wall of the adjacent cell
                generateMaze(maze, x, y-1); //Recursively calls the function for the adjacent cell
            }
        }
        else if(direction == 1){ //Checks if the direction is right
            if(y < COLS-1 && !maze[x][y+1].visited){ //Checks if it is not on right edge of the maze and the cell on right has not been visited
                maze[x][y].walls[1] = 0; //Removes the right wall of the current cell
                maze[x][y+1].walls[0] = 0; //Removes the left wall of the adjacent cell
                generateMaze(maze, x, y+1); //Recursively calls the function for the adjacent cell
            }
        }
        else if(direction == 2){ //Checks if the direction is up
            if(x > 0 && !maze[x-1][y].visited){ //Checks if it is not on top edge of the maze and the cell on top has not been visited
                maze[x][y].walls[2] = 0; //Removes the top wall of the current cell
                maze[x-1][y].walls[3] = 0; //Removes the bottom wall of the adjacent cell
                generateMaze(maze, x-1, y); //Recursively calls the function for the adjacent cell
            }
        }
        else if(direction == 3){ //Checks if the direction is down
            if(x < ROWS-1 && !maze[x+1][y].visited){ //Checks if it is not on bottom edge of the maze and the cell on bottom has not been visited
                maze[x][y].walls[3] = 0; //Removes the bottom wall of the current cell
                maze[x+1][y].walls[2] = 0; //Removes the top wall of the adjacent cell
                generateMaze(maze, x+1, y); //Recursively calls the function for the adjacent cell
            }
        }
    }
}

int main(){

    srand(time(NULL)); //Seeds the random number generator

    cell maze[ROWS][COLS];

    //Initialize the maze
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            maze[i][j].x = i;
            maze[i][j].y = j;
            maze[i][j].visited = 0;
            maze[i][j].walls[0] = 1;
            maze[i][j].walls[1] = 1;
            maze[i][j].walls[2] = 1;
            maze[i][j].walls[3] = 1;
        }
    }

    generateMaze(maze, 0, 0);

    printMaze(maze);

    return 0;
}