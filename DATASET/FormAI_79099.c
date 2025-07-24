//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 10

//Program to generate a procedurally generated maze in surrealist style

void printMaze(char c[][COL]){
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            printf("%c", c[i][j]);
        }
        printf("\n");
    }
}

void generateMaze(int visited[][COL], char maze[][COL], int startX, int startY){

    srand(time(NULL));
    int direction;

    if(startX < 0 || startY < 0 || startX >= ROW || startY >= COL || visited[startX][startY]) return;

    visited[startX][startY] = 1;

    // random direction to move
    while(1){
        direction = rand() % 4;
        if(direction == 0 && startX > 0){
            if(!visited[startX-1][startY]){
                maze[startX-1][startY] = '|';
                generateMaze(visited, maze, startX-2, startY);
            }
        }else if(direction == 1 && startY < COL-1){
            if(!visited[startX][startY+1]){
                maze[startX][startY+1] = '-';
                generateMaze(visited, maze, startX, startY+2);
            }
        }else if(direction == 2 && startX < ROW-1){
            if(!visited[startX+1][startY]){
                maze[startX+1][startY] = '|';
                generateMaze(visited, maze, startX+2, startY);
            }
        }else if(direction == 3 && startY > 0){
            if(!visited[startX][startY-1]){
                maze[startX][startY-1] = '-';
                generateMaze(visited, maze, startX, startY-2);
            }
        }

        if(visited[startX-1][startY] && visited[startX+1][startY] && visited[startX][startY-1] && visited[startX][startY+1]){
            break;
        }
    }
}

int main(){

    int visited[ROW][COL] = {0};
    char maze[ROW][COL];

    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            maze[i][j] = ' ';
        }
    }

    //first cell
    int startX = 1;
    int startY = 1;

    //start generator
    generateMaze(visited, maze, startX, startY);

    //place start and end points
    maze[1][0] = 'S';
    maze[ROW-2][COL-1] = 'E';

    printMaze(maze);

    return 0;
}