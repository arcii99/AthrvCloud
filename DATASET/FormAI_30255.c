//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: brave
#include <stdio.h>
#define MAX_ROWS 10
#define MAX_COLS 10

//function to print the maze
void print_maze(int maze[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int maze[MAX_ROWS][MAX_COLS] = {
        {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 1, 1, 0},
        {0, 1, 1, 1, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 0, 1, 1, 1, 1, 1, 0},
        {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 1, 1, 0, 1, 0},
        {0, 1, 1, 1, 1, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 1, 1, 1, 0, 1, 0},
        {0, 1, 1, 1, 1, 0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    
    int start_row = 0;
    int start_col = 0;
    int end_row = 9;
    int end_col = 9;
    
    printf("Maze:\n");
    print_maze(maze, MAX_ROWS, MAX_COLS);
    
    //initialize the visited array
    int visited[MAX_ROWS][MAX_COLS] = {{0}};
    visited[start_row][start_col] = 1;
    
    //initialize the queue
    int queue_x[MAX_ROWS*MAX_COLS];
    int queue_y[MAX_ROWS*MAX_COLS];
    int queue_front = 0;
    int queue_rear = 0;
    queue_x[queue_rear] = start_row;
    queue_y[queue_rear] = start_col;
    queue_rear++;
    
    while (queue_front < queue_rear) {
        //dequeue
        int current_row = queue_x[queue_front];
        int current_col = queue_y[queue_front];
        queue_front++;
        
        //check if we have reached the end
        if (current_row == end_row && current_col == end_col) {
            printf("\nPath found!\n");
            maze[current_row][current_col] = 2;
            print_maze(maze, MAX_ROWS, MAX_COLS);
            return 0;
        }
        
        //enqueue neighbors
        if (current_row-1 >= 0 && maze[current_row-1][current_col] == 1 && visited[current_row-1][current_col] == 0) {
            queue_x[queue_rear] = current_row-1;
            queue_y[queue_rear] = current_col;
            queue_rear++;
            visited[current_row-1][current_col] = 1;
            maze[current_row-1][current_col] = 2;
        }
        if (current_row+1 < MAX_ROWS && maze[current_row+1][current_col] == 1 && visited[current_row+1][current_col] == 0) {
            queue_x[queue_rear] = current_row+1;
            queue_y[queue_rear] = current_col;
            queue_rear++;
            visited[current_row+1][current_col] = 1;
            maze[current_row+1][current_col] = 2;
        }
        if (current_col-1 >= 0 && maze[current_row][current_col-1] == 1 && visited[current_row][current_col-1] == 0) {
            queue_x[queue_rear] = current_row;
            queue_y[queue_rear] = current_col-1;
            queue_rear++;
            visited[current_row][current_col-1] = 1;
            maze[current_row][current_col-1] = 2;
        }
        if (current_col+1 < MAX_COLS && maze[current_row][current_col+1] == 1 && visited[current_row][current_col+1] == 0) {
            queue_x[queue_rear] = current_row;
            queue_y[queue_rear] = current_col+1;
            queue_rear++;
            visited[current_row][current_col+1] = 1;
            maze[current_row][current_col+1] = 2;
        }
    }
    
    printf("\nNo path found.\n");
    print_maze(maze, MAX_ROWS, MAX_COLS);
    return 0;
}