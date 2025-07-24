//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

int maze[HEIGHT][WIDTH];

void generateMaze(int x, int y){
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    int randNum, newX, newY;
    
    maze[y][x]=0;
    while(1){
        randNum = rand()%4;
        newX = x + dir[randNum][0];
        newY = y + dir[randNum][1];
        
        if((newX>=0 && newX<WIDTH) && (newY>=0 && newY<HEIGHT) && maze[newY][newX]==1){
            maze[newY][newX]=0;
            if(randNum==0) generateMaze(newX, newY+1);
            else if(randNum==1) generateMaze(newX+1, newY);
            else if(randNum==2) generateMaze(newX, newY-1);
            else if(randNum==3) generateMaze(newX-1, newY);
        }
        
        if(maze[newY][newX]==0 && (rand()%10)<8) break;
    }
}

void printMaze(){
    for(int y=0; y<HEIGHT; y++){
        for(int x=0; x<WIDTH; x++){
            if(maze[y][x]==1) printf("X ");
            else printf("  ");
        }
        printf("\n");
    }
}

int main(){
    srand(time(NULL));
    for(int y=0; y<HEIGHT; y++){
        for(int x=0; x<WIDTH; x++){
            maze[y][x]=1;
        }
    }
    
    generateMaze(0,0);
    printMaze();
    
    return 0;
}