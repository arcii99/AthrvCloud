//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 11
#define COL 11

void printMaze(int maze[][COL]){
    // This function will print the maze
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            if(maze[i][j] == 1) printf("\u2588\u2588"); // print the walls of the maze
            else printf("  "); // print the empty space
        }
        printf("\n");
    }
}

void generateMaze(int maze[][COL], int row, int col){
    // This function will generate the maze
    srand(time(NULL));
    int random, walls = 0;
    int check[row][col]; // check the visited cells
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            maze[i][j] = 1; // initializing all cells with walls
            check[i][j] = 0;
        }
    }

    int start = rand() % row;
    check[start][0] = 1; // start from the randomly selected first cell
    maze[start][0] = 0; // remove the wall
    int curr_row = start, curr_col = 0;
    while(curr_col < col-1){
        random = rand() % 3 - 1; // select a random direction
        if(curr_row + random >= 0 && curr_row + random < row){
            if(!check[curr_row + random][curr_col]){ // if the cell is not visited
                check[curr_row + random][curr_col] = 1; // mark the cell as visited
                maze[curr_row + random][curr_col] = 0; // remove the wall
                curr_row += random;
                walls++;
            }
        }

        random = rand() % 3 - 1; // select a random direction
        if(curr_col + random >= 0 && curr_col + random < col){
            if(!check[curr_row][curr_col + random]){ // if the cell is not visited
                check[curr_row][curr_col + random] = 1; // mark the cell as visited
                maze[curr_row][curr_col + random] = 0; // remove the wall
                curr_col += random;
                walls++;
            }
        }
    }

    printMaze(maze);
}

int main(){
    int maze[ROW][COL];
    printf("Welcome to C Procedurally Generated Maze\n");
    generateMaze(maze, ROW, COL);
    return 0;
}