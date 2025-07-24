//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: funny
#include<stdio.h>

//declaring the size of the maze
#define ROWS 5
#define COLS 7

//function to initialize maze
void initializeMaze(char maze[][COLS]){
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            maze[i][j] = '.';
        }
    }
}

//function to print maze
void printMaze(char maze[][COLS]){
    printf("\n");
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

//function to check if the given position is valid or not 
int isValid(int x, int y){
    if(x >= ROWS || y >= COLS || x < 0 || y < 0){
        return 0;
    }
    return 1;
}

//function to check if the position is available to move 
int isAvailable(char maze[][COLS], int x, int y){
    if(maze[x][y] == '.'){
        return 1;
    }
    return 0;
}

//function to find the route in the maze
int findRoute(char maze[][COLS], int x, int y, char route[], int index){
    if(!isValid(x, y)){ //if not a valid position
        return 0;
    }
    if(maze[x][y] == 'X'){ //if destination reached
        route[index] = 'X';
        return 1;
    }
    if(!isAvailable(maze, x, y)){ //if not an available position to move
        return 0;
    }

    maze[x][y] = 'O'; //marking the position as visited
    route[index] = 'O';

    if(findRoute(maze, x, y+1, route, index+1)){ //move right
        return 1;
    }

    if(findRoute(maze, x+1, y, route, index+1)){ //move down
        return 1;
    }

    if(findRoute(maze, x, y-1, route, index+1)){ //move left        
        return 1;       
    }

    if(findRoute(maze, x-1, y, route, index+1)){ //move up
        return 1;       
    }

    maze[x][y] = '.'; //if no path found from current position then mark as unvisited
    index--;
    route[index] = '.';

    return 0;
}

int main(){

    char maze[ROWS][COLS];

    //creating the sample maze
    initializeMaze(maze);
    maze[1][0] = '|';
    maze[1][1] = 'X';
    maze[1][2] = '|';
    maze[2][2] = '|';
    maze[3][1] = '|';
    maze[3][2] = '_';
    maze[3][3] = '_';
    maze[3][4] = '_';
    maze[3][5] = '_';
    maze[2][5] = '|';
    maze[1][5] = '|';

    printf("Welcome to the Amazing Maze Route Finder!\n");
    printf("Your goal is to find the route from the start to the finish marked by 'X'\n");
    printf("You can move only up, down, left or right in the maze\n");
    printf("The walls are marked by '|'(vertical) and '_'(horizontal) characters\n");
    printf("The available path to move is marked by '.' character\n\n");

    printMaze(maze);

    printf("\nPress any key to find the solution of the maze.. \n");
    getchar();

    char route[100] = {'I'}; //initializing the route
    findRoute(maze, 1, 0, route, 1); //starting from (1,0) as it is marked by '|' character

    printMaze(maze);
    printf("\n");
    for(int i=1;i<49;i++){
        if(route[i] == 'X'){
            printf("You Won!!! Congratulations\n");
            break;
        }else if(route[i] == 'O'){
            printf("Move %d : %c\n", i, route[i]);
        }else{
            printf("No more moves available!! Sorry\n");
            break;
        }

    }

    return 0;
}