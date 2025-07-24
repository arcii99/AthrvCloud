//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define maze size
#define WIDTH 10
#define HEIGHT 10

// Define directions
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

// Define maze cells
#define WALL '#'
#define OPEN '.'

// Define maze
char maze[HEIGHT][WIDTH] = {
    {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
    {WALL, OPEN, WALL, OPEN, WALL, OPEN, WALL, OPEN, OPEN, WALL},
    {WALL, OPEN, WALL, OPEN, WALL, OPEN, OPEN, WALL, OPEN, WALL},
    {WALL, OPEN, WALL, OPEN, WALL, WALL, OPEN, WALL, OPEN, WALL},
    {WALL, OPEN, WALL, OPEN, OPEN, OPEN, OPEN, WALL, OPEN, WALL},
    {WALL, OPEN, OPEN, OPEN, WALL, WALL, WALL, OPEN, OPEN, WALL},
    {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
    {WALL, OPEN, OPEN, OPEN, WALL, WALL, OPEN, WALL, OPEN, WALL},
    {WALL, OPEN, WALL, WALL, WALL, OPEN, OPEN, WALL, OPEN, WALL},
    {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL}
};

// Define moves
int move_row[] = {-1, 0, 1, 0};
int move_col[] = {0, 1, 0, -1};

// Define start and end points
int start_row = 1, start_col = 1;
int end_row = 8, end_col = 8;

// Define stack structure
typedef struct {
    int row;
    int col;
} Cell;

Cell stack[HEIGHT * WIDTH];
int top = -1;

void push(int row, int col) {
    top++;
    stack[top].row = row;
    stack[top].col = col;
}

Cell pop() {
    Cell cell = stack[top];
    top--;
    return cell;
}

bool is_empty() {
    return top == -1;
}

void print_path() {
    int i;
    for (i = 0; i <= top; i++) {
        printf("(%d, %d) -> ", stack[i].row, stack[i].col);
    }
    printf("DONE\n");
}

bool is_valid_move(int row, int col) {
    if (row < 0 || col < 0 || row >= HEIGHT || col >= WIDTH) {
        return false;
    }
    if (maze[row][col] == WALL) {
        return false;
    }
    return true;
}

void find_path() {
    int row = start_row, col = start_col, direction = 0;
    bool found_path = false;
    
    while (!(row == end_row && col == end_col)) {
        maze[row][col] = WALL;  // mark current cell as visited
        
        // try moving in each direction
        int i;
        for (i = 0; i < 4; i++) {
            int new_row = row + move_row[i];
            int new_col = col + move_col[i];
            if (is_valid_move(new_row, new_col)) {
                push(row, col);
                row = new_row;
                col = new_col;
                direction = i;
                break;
            }
        }
        
        // if no valid move, backtrack
        if (i == 4) {
            maze[row][col] = OPEN;  // mark current cell as unvisited
            if (is_empty()) {
                printf("No path found!\n");
                return;
            }
            Cell cell = pop();
            row = cell.row;
            col = cell.col;
            // determine previous direction
            Cell prev_cell = stack[top];
            int prev_row = prev_cell.row;
            int prev_col = prev_cell.col;
            if (prev_row == row - 1) {
                direction = NORTH;
            } else if (prev_col == col + 1) {
                direction = EAST;
            } else if (prev_row == row + 1) {
                direction = SOUTH;
            } else {
                direction = WEST;
            }
        }
        
        // check if goal has been reached
        if (row == end_row && col == end_col) {
            found_path = true;
            push(row, col);
        }
    }
    
    if (found_path) {
        printf("Path found:\n");
        print_path();
    }
}

int main() {
    find_path();
    return 0;
}