//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ROWS 10
#define MAX_COLS 10

//Structure for storing the coordinates of cell
typedef struct{
    int row;
    int col;
} Cell;

//Structure fo Maze
typedef struct{
    int maze[MAX_ROWS][MAX_COLS];
    int rows;
    int cols;
} Maze;

//Initializes the maze
void initialize(Maze* m){
    int i,j;
    for(i=0;i < m->rows;i++){
        for(j=0;j < m->cols;j++){
            m->maze[i][j] = rand() %2;
        }
    }
}

//Displays the maze
void display(Maze m){
    int i,j;
    for(i=0;i < m.rows;i++){
        for(j=0;j < m.cols;j++){
            printf("%d ",m.maze[i][j]);
        }
        printf("\n");
    }
}

// Checks if the given cell is valid or not
int is_valid(Cell c,Maze m){
    if(c.row >= 0 && c.row < m.rows && c.col >= 0 && c.col < m.cols && m.maze[c.row][c.col] == 0){
        return 1;
    }
    return 0;
}

//Finds the path from start cell to destination cell
int find_path(Cell start,Cell dest,Maze m){
    if(start.row == dest.row && start.col == dest.col){
        return 1;
    }
    if(!is_valid(start,m)){
        return 0;
    }
    m.maze[start.row][start.col] = 1; //Mark the current cell as visited
    if(find_path((Cell){start.row-1,start.col},dest,m)){ //Search in up direction
        printf("(%d, %d) -> ",start.row,start.col);
        return 1;
    }
    if(find_path((Cell){start.row,start.col+1},dest,m)){ //Search in right direction
        printf("(%d, %d) -> ",start.row,start.col);
        return 1;
    }
    if(find_path((Cell){start.row+1,start.col},dest,m)){ //Search in down direction
        printf("(%d, %d) -> ",start.row,start.col);
        return 1;
    }
    if(find_path((Cell){start.row,start.col-1},dest,m)){ //Search in left direction
        printf("(%d, %d) -> ",start.row,start.col);
        return 1;
    }
    return 0;
}

int main(){
    Maze m;
    m.rows = MAX_ROWS;
    m.cols = MAX_COLS;
    initialize(&m);
    printf("Maze:\n");
    display(m);
    Cell start = {0,0};
    Cell dest = {MAX_ROWS-1,MAX_COLS-1};
    printf("\nPath:\n");
    if(!find_path(start,dest,m)){
        printf("No path found!\n");
    }
    return 0;
}