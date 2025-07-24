//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 20
#define COL 30

//Global variable definitions for the maze
int maze[ROW][COL];
int visited[ROW][COL];
int stack[ROW*COL][2];
int top=-1;
int start_row, start_col, end_row, end_col;

//function prototypes
void generate_maze();
void print_maze();
void depth_first_search();
int is_valid_move(int, int);
int is_visited(int, int);
void push(int, int);
void pop();

//generate maze function
void generate_maze(){
    //set all cells as unvisited and all walls present
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            maze[i][j]=15;
            visited[i][j]=0;
        }
    }
    //random starting and ending point
    srand(time(NULL));
    start_row=rand()%ROW;
    start_col=rand()%COL;
    end_row=rand()%ROW;
    end_col=rand()%COL;
    //open start and end points
    maze[start_row][start_col]-=1;
    maze[end_row][end_col]-=2;
    visited[start_row][start_col]=1; visited[end_row][end_col]=0;
    //random starting point put into stack
    push(start_row, start_col);
    //depth first search algorithm
    depth_first_search();
    //print final generated maze
    print_maze();
}

//depth first search algorithm
void depth_first_search(){
    int curr_row, curr_col, new_row, new_col, possible_moves[4], num_of_moves;

    while(top>-1){
        //get current position
        curr_row=stack[top][0];
        curr_col=stack[top][1];
        //find possible moves
        num_of_moves = 0;
        //check north
        if(is_valid_move(curr_row-1, curr_col) && is_visited(curr_row-1, curr_col)){
            possible_moves[num_of_moves++] = 1;
        }
        //check south
        if(is_valid_move(curr_row+1, curr_col) && is_visited(curr_row+1, curr_col)){
            possible_moves[num_of_moves++] = 2;
        }
        //check east
        if(is_valid_move(curr_row, curr_col+1) && is_visited(curr_row, curr_col+1)){
            possible_moves[num_of_moves++] = 3;
        }
        //check west
        if(is_valid_move(curr_row, curr_col-1) && is_visited(curr_row, curr_col-1)){
            possible_moves[num_of_moves++] = 4;
        }
        //if there are no possible moves, pop the stack
        if (num_of_moves == 0){
            pop();
        }
        //otherwise move to a random possible cell
        else{
            int r = rand()%num_of_moves;
            switch (possible_moves[r]){
                case 1:
                    new_row = curr_row - 1;
                    new_col = curr_col;
                    maze[curr_row][curr_col] &= 14;
                    maze[new_row][new_col] &= 13;
                    visited[new_row][new_col] = 1;
                    push(new_row,new_col);
                    break;
                case 2:
                    new_row = curr_row + 1;
                    new_col = curr_col;
                    maze[curr_row][curr_col] &= 13;
                    maze[new_row][new_col] &= 14;
                    visited[new_row][new_col] = 1;
                    push(new_row,new_col);
                    break;
                case 3:
                    new_row = curr_row;
                    new_col = curr_col + 1;
                    maze[curr_row][curr_col] &= 11;
                    maze[new_row][new_col] &= 7;
                    visited[new_row][new_col] = 1;
                    push(new_row,new_col);
                    break;
                case 4:
                    new_row = curr_row;
                    new_col = curr_col - 1;
                    maze[curr_row][curr_col] &= 7;
                    maze[new_row][new_col] &= 11;
                    visited[new_row][new_col] = 1;
                    push(new_row,new_col);
                    break;
            }
        }
    }
}

//push function
void push(int row, int col){
    stack[++top][0]=row;
    stack[top][1]=col;
}

//pop function
void pop(){
    top--;
}

//function to check if move is valid
int is_valid_move(int row, int col){
    if(row<0 || row>=ROW || col<0 || col>=COL){
        return 0;
    }
    else{
        return 1;
    }
}

//function to check if a cell is visited
int is_visited(int row, int col){
    if(visited[row][col]==1){
        return 0;
    }
    else{
        return 1;
    }
}

//function to print maze
void print_maze(){
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            if(maze[i][j]&1){
                printf("+---");
            }
            else{
                printf("+   ");
            }
        }
        printf("+\n");
        for(int j=0;j<COL;j++){
            if(maze[i][j]&8){
                printf("|   ");
            }
            else{
                printf("    ");
            }
        }
        printf("|\n");
    }
    for(int j=0;j<COL;j++){
        printf("+---");
    }
    printf("+\n");
}

//main function
int main(){
    generate_maze();
    return 0;
}