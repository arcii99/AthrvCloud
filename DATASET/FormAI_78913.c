//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define ROW 10
#define COL 10

char maze[ROW][COL] = {
    "# # # # # # # # # #",
    "# S #   #     #   #",
    "# # # # # # # # # #",
    "#   #     #     # #",
    "# # # # # # # # # #",
    "#   #   #   #     #",
    "# # # # # # # # # #",
    "#     #   #     # #",
    "# # # # # # # # # #",
    "# # # # # # # # # E"
};


void printMaze(){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

void getPosition(int* x, int* y, char c){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            if(maze[i][j] == c){
                *x = i;
                *y = j;
            }
        }
    }
}

bool isValidMove(int row, int col){
    if(row < 0 || col < 0 || row >= ROW || col >= COL || maze[row][col] == '#' || maze[row][col] == '*'){
        return false;
    }
    return true;
}

bool findRoute(int row, int col){
    if(!isValidMove(row, col)){
        return false;
    }

    if(maze[row][col] == 'E'){
        return true;
    }

    maze[row][col] = '*';

    if(findRoute(row+1, col) || findRoute(row-1, col) || findRoute(row, col+1) || findRoute(row, col-1)){
        return true;
    }

    maze[row][col] = ' ';

    return false;
}


int main()
{
    int s_row, s_col, e_row, e_col;
    getPosition(&s_row, &s_col, 'S');
    getPosition(&e_row, &e_col, 'E');

    printf("Maze:\n");
    printMaze();

    if(findRoute(s_row, s_col)){
        printf("\nPath:\n");
        printMaze();
        printf("\nFound the route!\n");
    }else{
        printf("\nNo route found!\n");
    }

    return 0;
}