//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>

// Function to print the maze
void printMaze(char maze[][10]){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            printf("%c ",maze[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the move is valid
int isMoveValid(char maze[][10], int x, int y){
    if(x < 0 || x >= 10 || y < 0 || y >= 10 || maze[x][y] == '#' || maze[x][y] == '@'){
        return 0;
    }
    return 1;
}

// Function to solve the maze using backtracking
int solveMaze(char maze[][10], int x, int y, char route[]){
    if(x == 9 && y == 9){
        route[99] = '\0';
        return 1;
    }
    
    if(isMoveValid(maze, x+1, y)){
        maze[x][y] = '@';
        route[x*10+y] = 'D';
        if(solveMaze(maze, x+1, y, route)){
            return 1;
        }
        maze[x][y] = '.';
        route[x*10+y] = '\0';
    }
    
    if(isMoveValid(maze, x-1, y)){
        maze[x][y] = '@';
        route[x*10+y] = 'U';
        if(solveMaze(maze, x-1, y, route)){
            return 1;
        }
        maze[x][y] = '.';
        route[x*10+y] = '\0';
    }
    
    if(isMoveValid(maze, x, y+1)){
        maze[x][y] = '@';
        route[x*10+y] = 'R';
        if(solveMaze(maze, x, y+1, route)){
            return 1;
        }
        maze[x][y] = '.';
        route[x*10+y] = '\0';
    }
    
    if(isMoveValid(maze, x, y-1)){
        maze[x][y] = '@';
        route[x*10+y] = 'L';
        if(solveMaze(maze, x, y-1, route)){
            return 1;
        }
        maze[x][y] = '.';
        route[x*10+y] = '\0';
    }
    
    return 0;
}


int main(){
    char maze[10][10] = {{'.','.','.','#','.','#','#','#','#','#'},
                        {'#','#','.','#','.','#','.','.','.','#'},
                        {'.','.','.','#','.','.','.','#','.','#'},
                        {'.','#','.','.','#','#','.','#','.','.'},
                        {'.','#','#','.','.','#','.','#','.','#'},
                        {'.','.','.','.','#','.','.','#','.','.'},
                        {'#','#','.','#','#','.','#','#','.','#'},
                        {'.','.','.','.','.','.','.','.','.','#'},
                        {'.','#','#','#','#','#','.','#','.','.'},
                        {'.','.','.','#','.','.','#','.','.','.'}};
    char route[100];
    if(solveMaze(maze, 0, 0, route)){
        printf("Congratulations! You found a route through the maze\n");
        printf("Route: %s\n",route);
        printf("\nHere's the maze with the route beside you:\n");
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                printf("%c ",maze[i][j]);
            }
            printf("\t\t");
            for(int j=0;j<10;j++){
                if(route[i*10+j] == '\0'){
                    printf("  ");
                }
                else {
                    printf("%c ",route[i*10+j]);
                }
            }
            printf("\n");
        }
    }
    else {
        printf("Sorry! There is no route through the maze\n");
    }
    return 0;
}