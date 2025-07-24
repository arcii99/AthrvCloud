//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Alan Touring
#include <stdio.h>
#define ROW 10
#define COL 10

// maze representation
char maze[ROW][COL] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', '#'},
    {'#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', '#'},
    {'#', ' ', '#', ' ', '#', ' ', '#', ' ', ' ', '#'},
    {'#', ' ', '#', ' ', '#', ' ', '#', '#', ' ', '#'},
    {'#', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', '#', '#', ' ', ' '},
    {'#', '#', '#', ' ', '#', ' ', ' ', '#', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

// possible movements
int row_mov[] = {-1, 0, 1, 0};
int col_mov[] = {0, 1, 0, -1};

// function to print the maze
void printMaze() {
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++)
            printf("%c", maze[i][j]);
        printf("\n");
    }
}

// recursive function to solve the maze
int findPath(int row, int col) {
    // if destination is reached, return success
    if (maze[row][col] == 'X') {
        return 1;
    }
    // mark current cell as visited
    maze[row][col] = '.';
    // explore all possible movements from current cell
    for (int i = 0; i < 4; i++) {
        int next_row = row + row_mov[i];
        int next_col = col + col_mov[i];
        // check if next cell is a valid position
        if (maze[next_row][next_col] == ' ' || maze[next_row][next_col] == 'X') {
            // recursively call the function with the new position
            if (findPath(next_row, next_col) == 1) {
                return 1;
            }
        }
    }
    // no path is found, mark the cell as unvisited and return failure
    maze[row][col] = ' ';
    return 0;
}

int main() {
    // start from (1,1)
    if(findPath(1, 1) == 1)
        printf("Found the path!\n");
    else
        printf("No path found!\n");
    printMaze();
    return 0;
}