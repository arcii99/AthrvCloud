//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

int maze[ROW][COL] = {
    {0,0,0,0,0,0,0,0,0,0},
    {0,1,1,1,0,1,1,1,1,0},
    {0,0,0,1,0,1,0,0,1,0},
    {0,1,0,1,1,1,0,1,1,0},
    {0,1,0,0,0,1,0,0,0,0},
    {0,1,1,1,1,1,1,1,1,0},
    {0,1,0,0,0,0,0,0,1,0},
    {0,1,1,1,1,1,1,1,1,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
};

int visited[ROW][COL] = {0};

int path[ROW * COL] = {0};
int path_index = 0;

int start_row = 1;
int start_col = 1;
int end_row = 8;
int end_col = 8;

int is_valid_move(int row, int col){
    if(row >= 0 && row < ROW && col >= 0 && col < COL && maze[row][col] == 1 && visited[row][col] == 0){
        return 1;
    }
    return 0;
}

void print_path(){
    for(int i = 0; i < path_index; i++){
        printf("(%d, %d) ", path[i]/10, path[i]%10);
    }
    printf("\n");
}

void find_path(int row, int col){
    path[path_index++] = row*10 + col;
    visited[row][col] = 1;
    if(row == end_row && col == end_col){
        print_path();
    }
    if(is_valid_move(row + 1, col)){
        find_path(row + 1, col);
    }
    if(is_valid_move(row, col + 1)){
        find_path(row, col + 1);
    }
    if(is_valid_move(row - 1, col)){
        find_path(row - 1, col);
    }
    if(is_valid_move(row, col - 1)){
        find_path(row, col - 1);
    }
    // Backtrack if the current path is not leading to the destination
    path_index--;
    visited[row][col] = 0;
}

int main()
{
    printf("Maze Route Finder:\n");
    find_path(start_row, start_col);
    return 0;
}