//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>

#define ROW 10
#define COL 10

char maze[ROW][COL] = {      //The maze that we want to solve
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', ' ', '#', ' ', '#', '#', '#', '#'},
    {'#', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', ' ', '#', '#', '#', '#', ' ', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#'},
    {'#', ' ', '#', '#', '#', '#', ' ', '#', ' ', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

int start_row = 1, start_col = 1;   //Starting position of the maze
int end_row = 8, end_col = 8;   //Ending position of the maze

int visited[ROW][COL] = {0};     //Array to keep track of visited cells

void print_maze(char m[ROW][COL]){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            printf("%c ", m[i][j]);
        }
        printf("\n");
    }
}

void find_route(int row, int col){
    visited[row][col] = 1;   //making the cell as visited

    if(row == end_row && col == end_col){    //if we reach the ending position, print the path
        printf("Found a way to the end of the maze! Here is the path: \n");
        print_maze(maze);
        printf("\n");
        return;
    }

    //Checking the cell on the right
    if(visited[row][col+1] == 0 && maze[row][col+1] == ' ' && col+1 < COL){
        maze[row][col+1] = 'P';    //Making the path with 'P'
        find_route(row, col+1);
        maze[row][col+1] = ' ';    //Backtrack and remove 'P'
    }

    //Checking the cell on the bottom
    if(visited[row+1][col] == 0 && maze[row+1][col] == ' ' && row+1 < ROW){
        maze[row+1][col] = 'P';
        find_route(row+1, col);
        maze[row+1][col] = ' ';
    }

    //Checking the cell on the left
    if(visited[row][col-1] == 0 && maze[row][col-1] == ' ' && col-1 >= 0){
        maze[row][col-1] = 'P';
        find_route(row, col-1);
        maze[row][col-1] = ' ';
    }

    //Checking the cell on the top
    if(visited[row-1][col] == 0 && maze[row-1][col] == ' ' && row-1 >= 0){
        maze[row-1][col] = 'P';
        find_route(row-1, col);
        maze[row-1][col] = ' ';
    }
}

int main(){
    printf("Maze before solving: \n");
    print_maze(maze);
    printf("\n");

    maze[start_row][start_col] = 'P';   //Marking starting position with 'P'
    find_route(start_row, start_col);

    return 0;
}