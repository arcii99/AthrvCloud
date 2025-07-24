//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 15
#define COL 25

//Function to print the maze
void printMaze(char maze[][COL]){
    int i, j;
    for(i=0; i<ROW; i++){
        for(j=0; j<COL; j++){
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

//Function to generate the maze
void generateMaze(char maze[][COL]){

    //Setting all cells to "wall"
    int i, j;
    for(i=0; i<ROW; i++){
        for(j=0; j<COL; j++){
            maze[i][j] = '#';
        }
    }

    //Setting random starting point
    srand(time(NULL));
    int x = rand()%ROW;
    int y = rand()%COL;
    maze[x][y] = ' ';

    //Array to keep track of visited cells
    int visited[ROW][COL];
    for(i=0; i<ROW; i++){
        for(j=0; j<COL; j++){
            visited[i][j] = 0;
        }
    }

    //Stack to keep track of visited cells
    int stackRow[ROW*COL];
    int stackCol[ROW*COL];
    int top = -1;
    stackRow[++top] = x;
    stackCol[top] = y;
    visited[x][y] = 1;

    //Creating the maze
    int neighborx, neighbory, temp;
    while(top != -1){
        x = stackRow[top];
        y = stackCol[top];
        top--;

        //Checking for unvisited neighbors
        int neighborCount = 0;
        int neighbors[4];
        if(x>0 && visited[x-1][y]==0){ //top neighbor
            neighbors[neighborCount++] = 0;
        }
        if(y>0 && visited[x][y-1]==0){ //left neighbor
            neighbors[neighborCount++] = 1;
        }
        if(x<ROW-1 && visited[x+1][y]==0){ //bottom neighbor
            neighbors[neighborCount++] = 2;
        }
        if(y<COL-1 && visited[x][y+1]==0){ //right neighbor
            neighbors[neighborCount++] = 3;
        }

        //Choosing a random unvisited neighbor
        if(neighborCount > 0){
            temp = rand()%neighborCount;
            if(neighbors[temp] == 0){ //top neighbor
                neighborx = x-1;
                neighbory = y;
            }
            else if(neighbors[temp] == 1){ //left neighbor
                neighborx = x;
                neighbory = y-1;
            }
            else if(neighbors[temp] == 2){ //bottom neighbor
                neighborx = x+1;
                neighbory = y;
            }
            else{ //right neighbor
                neighborx = x;
                neighbory = y+1;
            }

            //Making a path to the neighbor
            maze[neighborx][neighbory] = ' ';
            visited[neighborx][neighbory] = 1;

            //Adding the neighbor to the stack
            stackRow[++top] = neighborx;
            stackCol[top] = neighbory;
        }
    }
}

int main(){
    char maze[ROW][COL];
    generateMaze(maze);
    printMaze(maze);
    return 0;
}