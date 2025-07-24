//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function to create a maze
void createMaze(int **maze, int rows, int cols){
    //Random seed using time
    srand(time(NULL));

    //Fill maze with all walls
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            maze[i][j] = 1;
        }
    }

    //Pick a random starting point
    int startX = rand()%rows;
    int startY = rand()%cols;

    //Create a path from the starting point
    createPath(maze, rows, cols, startX, startY);
}

//Function to create a path in the maze recursively
void createPath(int **maze, int rows, int cols, int x, int y){
    //Directions to check
    int directions[4][2] = {
        {0,-1},
        {0,1},
        {-1,0},
        {1,0}
    };

    //Randomize the directions
    for(int i=0;i<4;i++){
        int temp = directions[i][0];
        int randIndex = rand()%4;
        directions[i][0] = directions[randIndex][0];
        directions[randIndex][0] = temp;

        temp = directions[i][1];
        randIndex = rand()%4;
        directions[i][1] = directions[randIndex][1];
        directions[randIndex][1] = temp;
    }

    //Carve out the path
    for(int i=0;i<4;i++){
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];

        //Check if the new point is valid
        if(newX>=0 && newX<rows && newY>=0 && newY<cols && maze[newX][newY]==1){
            maze[newX][newY] = 0;
            maze[x][y] = 0;
            createPath(maze, rows, cols, newX, newY);
        }
    }
}

//Function to print the maze
void printMaze(int **maze, int rows, int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(maze[i][j]==1){
                printf("█");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}

//Main function
int main(){
    //Initialize the maze
    int rows = 21;
    int cols = 51;
    int **maze = (int**)malloc(rows*sizeof(int*));
    for(int i=0;i<rows;i++){
        maze[i] = (int*)malloc(cols*sizeof(int));
    }

    //Create the maze
    createMaze(maze, rows, cols);

    //Print the maze
    printMaze(maze, rows, cols);

    //Free the memory
    for(int i=0;i<rows;i++){
        free(maze[i]);
    }
    free(maze);

    return 0;
}