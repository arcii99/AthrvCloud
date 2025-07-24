//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40
#define WALL '#'
#define PATH ' '
#define START 'S'
#define END 'E'

char maze[ROWS][COLS];
int visited[ROWS][COLS];

int start_row, start_col;
int end_row, end_col;

void print_maze(){
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int is_valid(int row, int col){
    return (row>=0 && row<ROWS && col>=0 && col<COLS);
}

int is_wall(int row, int col){
    return (maze[row][col] == WALL);
}

int is_path(int row, int col){
    return (maze[row][col] == PATH);
}

int is_end(int row, int col){
    return (maze[row][col] == END);
}

int is_start(int row, int col){
    return (maze[row][col] == START);
}

void generate_maze(){
    int row, col;
    int visited_count = 0;
    
    srand(time(NULL)); // Initializing random seed
    
    // Create outer walls
    for(int i=0; i<ROWS; i++){
        maze[i][0] = WALL;
        maze[i][COLS-1] = WALL;
    }
    for(int j=0; j<COLS; j++){
        maze[0][j] = WALL;
        maze[ROWS-1][j] = WALL;
    }
    
    // Create paths randomly
    for(int i=1; i<ROWS-1; i++){
        for(int j=1; j<COLS-1; j++){
            if(rand()%2){
                maze[i][j] = WALL;
            }
            else{
                maze[i][j] = PATH;
            }
        }
    }
    
    // Create start and end points
    start_row = rand()%(ROWS-2)+1;
    start_col = rand()%(COLS-2)+1;
    maze[start_row][start_col] = START;
    
    do{
        end_row = rand()%(ROWS-2)+1;
        end_col = rand()%(COLS-2)+1;
    }while(end_row == start_row && end_col == start_col);
    maze[end_row][end_col] = END;
    
}

void dfs(int row, int col){
    visited[row][col] = 1;
    
    int direction_row[4] = {0,0,-1,1};
    int direction_col[4] = {-1,1,0,0};
    
    int directions[4] = {0,1,2,3};
    for(int i=0; i<3; i++){
        int j = rand()%(4-i)+i;
        int temp = directions[i];
        directions[i] = directions[j];
        directions[j] = temp;
    }
    
    for(int i=0; i<4; i++){
        int next_row = row + direction_row[directions[i]];
        int next_col = col + direction_col[directions[i]];
        
        if(is_valid(next_row, next_col) && !visited[next_row][next_col] && is_path(next_row, next_col)){
            maze[(row+next_row)/2][(col+next_col)/2] = PATH;
            dfs(next_row, next_col);
        }
    
    }
    
}

void solve_maze(){
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            visited[i][j] = 0;
        }
    }
    
    // Starting from start point
    dfs(start_row, start_col);
}

int main(){
    generate_maze();
    printf("Generated Maze:\n");
    print_maze();
    
    printf("\nSolving Maze...\n");
    solve_maze();
    printf("Solved Maze:\n");
    print_maze();
    return 0;
}