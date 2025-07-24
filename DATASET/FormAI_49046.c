//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 20

int maze[ROW][COL];

void printMaze(){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            if(maze[i][j] == 0) printf("+");
            else printf(" ");
        }
        printf("\n");
    }
}

void generateMaze(){
    //Initializes the maze with walls
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            maze[i][j] = 0;
        }
    }

    //Random Seed
    srand(time(NULL));
    
    //Generate Path
    int i=1; //Starting from second row
    while(i<ROW){
        int j= rand() % COL; //Random column
        if(maze[i][j] == 0){ //If spot is a wall
            maze[i][j] = 1; //Make it a path
            int randNum = rand() % 5; //Random move generator 0->left 1->right 2->up 3->down
            if(randNum == 0 && j>1){ //Go left
                if(maze[i][j-1] == 0 && maze[i-1][j-1] == 0 && maze[i+1][j-1] == 0){
                    maze[i][j-1] = 1;
                    j--;
                }
            }
            else if(randNum == 1 && j<COL-2){ //Go right
                if(maze[i][j+1] == 0 && maze[i-1][j+1] == 0 && maze[i+1][j+1] == 0){
                    maze[i][j+1] = 1;
                    j++;
                }
            }
            else if(randNum == 2 && i>1){ //Go up
                if(maze[i-1][j] == 0 && maze[i-1][j+1] == 0 && maze[i-1][j-1] == 0){
                    maze[i-1][j] = 1;
                    i--;
                }
            }
            else if(randNum == 3 && i<ROW-2){ //Go down
                if(maze[i+1][j] == 0 && maze[i+1][j+1] == 0 && maze[i+1][j-1] == 0){
                    maze[i+1][j] = 1;
                    i++;
                }
            }
        }
        if(i >= ROW-1){ //End of maze
            for(int j=0; j<COL; j++){
                if(maze[i][j] == 1) maze[i][j] = 2; //Change path to exit
            }
        }
    }
}

int main(){
    generateMaze();
    printMaze();
    return 0;
}