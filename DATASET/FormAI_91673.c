//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ROWS 10
#define COLS 10
#define MAX_STACK_SIZE 100

/* A Stack data structure that will be used to store the maze coordinates */
typedef struct {
    int row;
    int col;
} coordinates;

coordinates stack[MAX_STACK_SIZE];
int top = -1;

void push(int row, int col) {
    if (top == MAX_STACK_SIZE - 1) {
        printf("Stack overflow! Could not push onto stack.");
        return;
    }
    top++;
    stack[top].row = row;
    stack[top].col = col;
}

coordinates pop() {
    if (top == -1) {
        printf("Stack underflow! Could not pop from stack.");
        coordinates error = {-1, -1};
        return error;
    }
    coordinates popped = stack[top];
    top--;
    return popped;
}

coordinates get_top() {
    if (top == -1) {
        printf("Stack is empty.");
        coordinates error = {-1, -1};
        return error;
    }
    return stack[top];
}

bool is_empty() {
    if (top == -1) {
        return true;
    }
    return false;
}

/* A function to print the Maze */
void print_maze(char maze[ROWS][COLS]) {
    printf("\nCurrent Maze Status:\n\n");
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            printf("%c", maze[row][col]);
        }
        printf("\n");
    }
}

bool is_valid_move(char maze[ROWS][COLS], int row, int col) {
    /* Check if we are inside the bounds of the maze */
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        /* Check if we are hitting a wall or previously visited coordinate
           If either of the conditions are true then return false */
        if (maze[row][col] == '#' || maze[row][col] == '*' || maze[row][col] == '+') {
            return false;
        }
        return true;
    }
    return false;
}

void path_found(coordinates current, coordinates start, char maze[ROWS][COLS]) {
    printf("Path Found!\n\n");
    /* Mark the final destination on the maze */
    maze[current.row][current.col] = '+';
    /* Traverse back to the starting point and mark the path */
    while (!(current.row == start.row && current.col == start.col)) {
        current = pop();
        maze[current.row][current.col] = '+';
    }
    print_maze(maze);
}

void dfs_maze_solver(coordinates start, coordinates end, char maze[ROWS][COLS]) {
    /* Push the starting coordinate onto the stack */
    push(start.row, start.col);
    
    while(!is_empty()) {
        /* Retrieve the top of the stack */
        coordinates current = get_top();
        
        /* Check if we have reached our destination */
        if (current.row == end.row && current.col == end.col) {
            path_found(current, start, maze);
            break;
        }
        
        /* Identify the valid moves */
        int row_moves[] = {-1, 1, 0, 0}; // Up, Down, Left, Right
        int col_moves[] = {0, 0, -1, 1};
    
        bool valid_move_found = false;
        for (int i = 0; i < 4; i++) {
            int new_row = current.row + row_moves[i];
            int new_col = current.col + col_moves[i];
            
            if (is_valid_move(maze, new_row, new_col)) {
                valid_move_found = true;
                push(new_row, new_col);
                maze[new_row][new_col] = '*';
                break;
            }
        }
        
        if (!valid_move_found) {
            /* If we did not find any valid move, pop the current node and move back one step */
            coordinates popped = pop();
            maze[popped.row][popped.col] = 'X';
        }
        
        print_maze(maze);
    }
}

int main() {
    /* Initialize maze */
    char maze[ROWS][COLS] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '.', '#', '#', '#', '.', '#', '#', '.', '#'},
        {'#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
        {'#', '.', '.', '.', '#', '#', '.', '#', '.', '#'},
        {'#', '#', '#', '.', '.', '#', '.', '#', '.', '#'},
        {'#', '.', '.', '#', '.', '.', '.', '#', '.', '#'},
        {'#', '#', '.', '#', '.', '#', '.', '.', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '#', '.', '*', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    };
    
    /* Identify starting & ending points */
    coordinates start = {1, 1};
    coordinates end = {8, 8};
    
    printf("Starting Maze:\n\n");
    print_maze(maze);
    
    /* Call the DFS Algorithm */
    dfs_maze_solver(start, end, maze);
    
    return 0;
}