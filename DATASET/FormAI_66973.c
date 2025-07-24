//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ROW 7
#define COL 11

bool is_valid(int row, int col){
    return (row >= 0 && row < ROW && col >= 0 && col < COL);    
}

bool is_open(char maze[][COL], int row, int col){
    return (maze[row][col] != '#' && maze[row][col] != 'X');    
}

void print_maze(char maze[][COL]){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

void find_path(char maze[][COL], int start_row, int start_col, int end_row, int end_col){
    int row_offset[] = {-1, 0, 1, 0};
    int col_offset[] = {0, 1, 0, -1};
    
    int queue[ROW*COL][2]; // (row, col) coordinates
    int front = 0;
    int rear = 0;
    
    queue[rear][0] = start_row;
    queue[rear][1] = start_col;
    rear++;
    
    while(front != rear){
        int curr_row = queue[front][0];
        int curr_col = queue[front][1];
        front++;
        
        for(int i=0; i<4; i++){
            int next_row = curr_row + row_offset[i];
            int next_col = curr_col + col_offset[i];
            
            if(is_valid(next_row, next_col) && is_open(maze, next_row, next_col)){
                queue[rear][0] = next_row;
                queue[rear][1] = next_col;
                rear++;
                maze[next_row][next_col] = 'X'; // mark as visited
                if(next_row == end_row && next_col == end_col){
                    printf("Path found!\n");
                    maze[start_row][start_col] = 'S'; // mark start
                    maze[end_row][end_col] = 'E'; // mark end
                    print_maze(maze);
                    return;
                }
            }
        }
    }
    printf("Cannot find path in the maze\n");
}

int main(){
    char maze[ROW][COL] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '#'},
        {'#', '.', '#', '.', '#', '.', '#', '#', '#', '.', '#'},
        {'#', '.', '#', '.', '.', '.', '.', '.', '#', '.', '#'},
        {'#', '.', '#', '#', '#', '.', '#', '#', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    };
    
    printf("Original Maze:\n");
    print_maze(maze);
    
    int start_row = 1;
    int start_col = 1;
    int end_row = 4;
    int end_col = 9;
    
    find_path(maze, start_row, start_col, end_row, end_col);

    return 0;
}