//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_maze(int maze[10][10]){
    int i,j;
    // Initialize maze to all walls
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            maze[i][j]=1;
        }
    }
    // Set random start and end positions
    int startX, startY, endX, endY;
    startX = rand()%10;
    startY = rand()%10;
    endX = rand()%10;
    endY = rand()%10;
    // Ensure start and end positions are not the same
    while(startX==endX && startY==endY){
        endX = rand()%10;
        endY = rand()%10;
    }
    maze[startX][startY]=0;
    maze[endX][endY]=0;
    // Generate maze paths using a recursive function
    gen_path(maze,startX,startY,endX,endY);
}

void gen_path(int maze[10][10], int x, int y, int endX, int endY){
    maze[x][y]=0;
    // Initialize array with possible directions
    int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
    int i;
    // Shuffle array to randomize directions
    for(i=0;i<4;i++){
        int randIndex = rand()%4;
        int tempX = dir[i][0];
        int tempY = dir[i][1];
        dir[i][0] = dir[randIndex][0];
        dir[i][1] = dir[randIndex][1];
        dir[randIndex][0] = tempX;
        dir[randIndex][1] = tempY;
    }
    // Loop through possible directions
    for(i=0;i<4;i++){
        int checkX = x+dir[i][0];
        int checkY = y+dir[i][1];
        // If new position is within bounds and a wall, break it down and continue
        if(checkX>=0 && checkX<10 && checkY>=0 && checkY<10 && maze[checkX][checkY]==1){
            int midX = (x+checkX)/2;
            int midY = (y+checkY)/2;
            maze[midX][midY]=0;
            gen_path(maze,checkX,checkY,endX,endY);
        }
        // Check if end position has been reached
        if(x==endX && y==endY){
            return;
        }
    }
}

int main(){
    int maze[10][10];
    // Seed random number generator
    srand(time(0));
    // Generate maze
    generate_maze(maze);
    // Print maze
    int i,j;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            printf("%s", maze[i][j]?"#":" ");
        }
        printf("\n");
    }
    return 0;
}